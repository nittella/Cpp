#include "internal_atomic_coordinates.h"

void InternalAtomsCoordinates::Add(const InternalCoordinate& i_cord){
    coordinates_.push_back(i_cord);
}

size_t InternalAtomsCoordinates::Size () const{
    return coordinates_.size();
}

void InternalAtomsCoordinates::Sort(){
    sort(coordinates_.begin(), coordinates_.end(),
            [](const InternalCoordinate& lhs, const InternalCoordinate& rhs){ return lhs.GetType() < rhs.GetType();});
};

const InternalCoordinate& InternalAtomsCoordinates::operator[] (int number) const {
    return coordinates_[number - 1];
}

InternalCoordinate& InternalAtomsCoordinates::operator[] (int number) {
    return coordinates_[number - 1];
}

auto InternalAtomsCoordinates::begin(){
    return coordinates_.begin();
}

auto InternalAtomsCoordinates::end(){
    return coordinates_.end();
}

const auto InternalAtomsCoordinates::begin() const {
    return coordinates_.begin();
}

const auto InternalAtomsCoordinates::end() const {
    return coordinates_.end();
}

ostream& operator<< (ostream& os, InternalAtomsCoordinates coords){
    coords.Sort();
    //column parameters
    int no_width = 4;
    int name_width = 20;
    int type_width = 6;
    int count = 1;

    os << setw(no_width) << "//No"
       << setw(name_width) << "Name"
       << setw(type_width) << "Type"
       << "  " << "Atoms" << "\n";
    for (const auto& coordinate : coords){
        os << setw(no_width) << count++
           << setw(name_width) << coordinate.GetName()
           << setw(type_width) << coordinate.GetTypeName()
           << " " << coordinate.GetTypeAtoms()
           << '\n';
    }

    return os;

}