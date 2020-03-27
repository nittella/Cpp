#include "cartesian_atomic_coordinates.h"

CartesianCoordinate CartesianAtomsCoordinates::GetCoordinate(int atom_number) const{
    return coordinates_[atom_number - 1];
}

CartesianAtomsCoordinates::CartesianAtomsCoordinates(){}

CartesianAtomsCoordinates::CartesianAtomsCoordinates(const vector<CartesianCoordinate>& coordinates){
    coordinates_.reserve(coordinates.size());
    for(const auto& item : coordinates){
        coordinates_.push_back(item);
    }
}

size_t CartesianAtomsCoordinates::Size() const{
    return coordinates_.size();
};

CartesianAtomsCoordinates ReadCoordinates(const string& file_name){
    ifstream input(file_name);
    vector<CartesianCoordinate> result;
    string tmp;
    while(!input.eof()){
        getline(input, tmp, '\n');
        string_view view(tmp);
        int number = GetFromString<int>(view);
        double x = GetFromString<double>(view);
        double y = GetFromString<double>(view);
        double z = GetFromString<double>(view);
        AtomType type = GetFromString<AtomType>(view);
        result.push_back(CartesianCoordinate(type, number, x, y, z));
    }
    return CartesianAtomsCoordinates{result};
};
void CartesianAtomsCoordinates::Add(CartesianCoordinate cord){
    coordinates_.push_back(cord);
};

vector<CartesianCoordinate>::iterator CartesianAtomsCoordinates::begin(){
    return coordinates_.begin();
};

vector<CartesianCoordinate>::iterator CartesianAtomsCoordinates::end(){
    return coordinates_.end();
};

vector<CartesianCoordinate>::const_iterator CartesianAtomsCoordinates::begin() const{
    return coordinates_.begin();
};

vector<CartesianCoordinate>::const_iterator CartesianAtomsCoordinates::end() const{
    return coordinates_.end();
};

map<Atom, vector<pair<double, Atom>>> CartesianAtomsCoordinates::CalculateDestinations() const{
    map<Atom, vector<pair<double, Atom>>> result;
    for(const auto& coordinate1 : coordinates_){
        Atom atom1 = {coordinate1.GetType(), coordinate1.GetNumber()};
        vector<pair<double, Atom>> tmp;
        for (const auto& coordinate2 : coordinates_){
            if (coordinate1 != coordinate2){
                Atom atom2 = {coordinate2.GetType(), coordinate2.GetNumber()};
                double destination = coordinate1.CalculateDestination(coordinate2);
                tmp.push_back({destination, {atom2}});
            }
        }
        sort(tmp.begin(), tmp.end(),
                [](pair<double, Atom> p1, pair<double, Atom> p2){ return p1.first < p2.first;}
                );
        result.insert({atom1, tmp});
    }
    return result;
}