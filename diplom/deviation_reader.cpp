#include "deviation_reader.h"

double CalculateAngle(double a, double b, double c){
    return acos((pow(c, 2) - pow(b, 2) - pow(a, 2)) / (2 * a * b));
}

double CalculateAngle(const CartesianCoordinate& cord1, const CartesianCoordinate& cord2){
    return acos(cord1 * cord2 / (cord1.CalculateRadius() * cord2.CalculateRadius()));
}

void Deviation::Add(double freq, const CartesianCoordinate& coord){
    freq_to_deviations_[freq].Add(coord);
    Atom atom = {coord.GetType(), coord.GetNumber()};
    atom_to_deviations_[atom].push_back(coord);
    freq_to_id_[freq] = atom_to_deviations_.size() - 1;
}

map<double, vector<pair<double, Bond>>> Deviation::CalculateBestType1(const CartesianAtomsCoordinates& coordinates) {
    map<double, vector<pair<double, Bond>>> result_t1;
    for(const auto& [freq, diviations] : freq_to_deviations_){
        //type1
        vector<pair<double, Bond>> delta_rs;
        for(const auto& coord : diviations){
            Atom atom = {coord.GetType(), coord.GetNumber()};
            for(int i = 1; i <= diviations.Size(); i++){
                Atom atom_i = {diviations.GetCoordinate(i).GetType(), diviations.GetCoordinate(i).GetNumber()};
                double delta_r = coord.CalculateDestination(diviations.GetCoordinate(i));
                delta_rs.push_back({delta_r, {atom, atom_i}});
            }
        }
        sort(delta_rs.begin(), delta_rs.end(),
             [](pair<double, Bond> lhs, pair<double, Bond> rhs){ return lhs.first > rhs.first;});
        unique(delta_rs.begin(), delta_rs.end(),
               [](pair<double, Bond> lhs, pair<double, Bond> rhs){
                   return lhs.second.first == rhs.second.second && rhs.second.first == lhs.second.second;});
        delta_rs.resize(10);
        result_t1[freq] = delta_rs;
    }
    return result_t1;
}

    map<double, map<double, vector<Atom>>> Deviation::CalculateBestType2(const CartesianAtomsCoordinates& coordinates){
        map<double, map<double, vector<Atom>>> result_t2;
        for(const auto& [freq, diviations] : freq_to_deviations_){
            //type2
            map<double, vector<Atom>> delta_as;
            for(const auto& delta_coord1 : diviations){
                Atom atom_1 = {delta_coord1.GetType(), delta_coord1.GetNumber()};
                CartesianCoordinate coord1 = coordinates.GetCoordinate(atom_1.number);
                for(int i = 1; i <= diviations.Size(); i++){
                    Atom atom_2 = {diviations.GetCoordinate(i).GetType(), diviations.GetCoordinate(i).GetNumber()};
                    if(atom_1 != atom_2){
                        for(int j = 1; j <= diviations.Size(); j++){
                            Atom atom_3 = {diviations.GetCoordinate(j).GetType(), diviations.GetCoordinate(j).GetNumber()};
                            if(atom_3 != atom_1 && atom_3 != atom_2){
                                CartesianCoordinate delta_coord2 = diviations.GetCoordinate(i);
                                CartesianCoordinate delta_coord3 = diviations.GetCoordinate(j);
                                CartesianCoordinate coord2 = coordinates.GetCoordinate(atom_2.number);
                                CartesianCoordinate coord3 = coordinates.GetCoordinate(atom_3.number);
                                double a = CalculateDistance(coord1, coord2);
                                double b = CalculateDistance(coord2, coord3);
                                double c = CalculateDistance(coord1, coord3);
                                double alpha = CalculateAngle(a, b, c);
                                double a_2 = CalculateDistance(coord1, delta_coord1, coord2, delta_coord2);
                                double b_2 = CalculateDistance(coord2, delta_coord2, coord3, delta_coord3);
                                double c_2 = CalculateDistance(coord1, delta_coord1, coord3, delta_coord3);
                                double alpha_2 = CalculateAngle(a_2, b_2, c_2);
                                double delta_alpha = abs(alpha_2 - alpha);
                                delta_as[delta_alpha] = {atom_1, atom_2, atom_3};
                            }
                        }
                    }
                }
            }
            map<double, vector<Atom>> best_t2;
            for (int p = 0; p < 10; p++){
                best_t2.insert(*prev(delta_as.end(), p + 1));
            }
            result_t2[freq] = best_t2;

        }
        return result_t2;
    }

map<double, map<double, vector<Atom>>> Deviation::CalculateBestType3(const CartesianAtomsCoordinates& coordinates){
    map<double, map<double, vector<Atom>>> result_t3;
    for(const auto& [freq, diviations] : freq_to_deviations_){
        map<double, vector<Atom>> delta_as;
        for(int i = 1; i <= diviations.Size(); i++){
            Atom atom_1 = {diviations.GetCoordinate(i).GetType(), diviations.GetCoordinate(i).GetNumber()};
            CartesianCoordinate coord1 = coordinates.GetCoordinate(atom_1.number);
            CartesianCoordinate delta_coord1 = diviations.GetCoordinate(i);
            for(int j = 1; j <= diviations.Size(); j++){
                Atom atom_2 = {diviations.GetCoordinate(j).GetType(), diviations.GetCoordinate(j).GetNumber()};
                if(atom_2 != atom_1){
                    CartesianCoordinate coord2 = coordinates.GetCoordinate(atom_2.number);
                    CartesianCoordinate delta_coord2 = diviations.GetCoordinate(j);
                    for(int k = 1; k <= diviations.Size(); k++){
                        Atom atom_3 = {diviations.GetCoordinate(k).GetType(), diviations.GetCoordinate(k).GetNumber()};
                        if(atom_3 != atom_2 && atom_3 != atom_1){
                            CartesianCoordinate coord3 = coordinates.GetCoordinate(atom_3.number);
                            CartesianCoordinate delta_coord3 = diviations.GetCoordinate(k);
                            for(int l = 1; l <= diviations.Size(); l++){
                                Atom atom_4 = {diviations.GetCoordinate(l).GetType(), diviations.GetCoordinate(l).GetNumber()};
                                if(atom_4 != atom_3 && atom_4 != atom_2 && atom_4 != atom_1){
                                    CartesianCoordinate coord4 = coordinates.GetCoordinate(atom_4.number);
                                    CartesianCoordinate delta_coord4 = diviations.GetCoordinate(l);
                                    CartesianCoordinate vec_1 = coord2 - coord1;
                                    CartesianCoordinate vec_2 = coord4 - coord3;
                                    double alpha = CalculateAngle(vec_1, vec_2);

                                    CartesianCoordinate vec_1_2 = coord2 + delta_coord2 - coord1 - delta_coord1;
                                    CartesianCoordinate vec_2_2 = coord4 + delta_coord4 - coord3 - delta_coord3;
                                    double alpha_2 = CalculateAngle(vec_1_2, vec_2_2);
                                    double delta_alpha = abs(alpha_2 - alpha);

                                    delta_as[delta_alpha] = {atom_1, atom_2, atom_3, atom_4};
                                }
                            }
                        }

                    }
                }

            }
        }
        map<double, vector<Atom>> best_t3;
        for (int p = 0; p < 10; p++){
            best_t3.insert(*prev(delta_as.end(), p + 1));
        }
        result_t3[freq] = best_t3;
    }
    return result_t3;
}


Deviation DeviationReader(const string& file_name) {
    Deviation dv;
    ifstream input(file_name);
    string tmp;
    getline(input, tmp, '\n');
    string_view first_line(tmp);
    int atom_number = GetFromString<int>(first_line);
    getline(input, tmp, '\n');
    string format = tmp;
    while (!input.eof()) {
            if(format == "firefly"){


                getline(input, tmp);
                getline(input, tmp);
                stringstream s_line;
                string part;
                s_line << tmp;
                getline(s_line, part, ';');
                vector<double> freq;
                for (int i = 0; i < 5; i++) {
                    getline(s_line, part, ';');
                    string_view freq_view(part);
                    double freq_i = GetFromString<double>(freq_view);
                    freq.push_back(freq_i);
                }
                getline(input, tmp, '\n');
                getline(input, tmp, '\n');
                vector<CartesianCoordinate> coords_i;
                for(int j = 0; j < atom_number; j++){
                    getline(input, tmp);
                    stringstream line_x_cord(tmp);
                    getline(line_x_cord, part, ';');
                    string_view number_view(part);
                    int number = GetFromString<int>(number_view);
                    getline(line_x_cord, part, ';');
                    string_view type_view(part);
                    AtomType type = GetFromString<AtomType>(type_view);
                    getline(line_x_cord, part, ';');
                    vector<double> x_i;
                    for(int ix = 0; ix < 5; ix++){
                        getline(line_x_cord, part, ';');
                        string_view x_view(part);
                        double x = GetFromString<double>(x_view);
                        x_i.push_back(x);
                    }

                    getline(input, tmp);
                    stringstream line_y_cord(tmp);
                    getline(line_y_cord, part, ';');
                    vector<double> y_i;
                    for(int iy = 0; iy < 5; iy++){
                        getline(line_y_cord, part, ';');
                        string_view y_view(part);
                        double y = GetFromString<double>(y_view);
                        y_i.push_back(y);
                    }
                    getline(input, tmp);
                    stringstream line_z_cord(tmp);
                    getline(line_z_cord, part, ';');
                    vector<double> z_i;
                    for(int iz = 0; iz < 5; iz++){
                        getline(line_z_cord, part, ';');
                        string_view z_view(part);
                        double z = GetFromString<double>(z_view);
                        z_i.push_back(z);
                    }

                    for(int ia = 0; ia < 5; ia++){
                        CartesianCoordinate coord_i(type, number, x_i[ia], y_i[ia], z_i[ia]);
                        dv.Add(freq[ia], coord_i);
                    }
                }
                for (int l = 0; l < 11; l++){
                    getline(input, tmp);
                }
            } else if(format == "gaussian"){
                getline(input, tmp);
                getline(input, tmp);
                getline(input, tmp);
                stringstream s_line;
                string part;
                s_line << tmp;
                getline(s_line, part, ';');
                vector<double> freq;
                for (int i = 0; i < 3; i++) {
                    getline(s_line, part, ';');
                    string_view freq_view(part);
                    double freq_i = GetFromString<double>(freq_view);
                    freq.push_back(freq_i);
                }
                for (int i = 0; i < 4; i++){
                    getline(input, tmp, '\n');
                }

                for(int j = 0; j < atom_number; j++){
                    vector<double> x_i;
                    vector<double> y_i;
                    vector<double> z_i;
                    getline(input, tmp);
                    stringstream line(tmp);
                    getline(line, part, ';');
                    string_view number_view(part);
                    int number = GetFromString<int>(number_view);
                    getline(line, part, ';');
                    string_view type_view(part);
                    AtomType type = GetFromString<AtomType>(type_view);
                    for (int i = 0; i < 3; i++){
                        //get X
                        getline(line, part, ';');
                        string_view x_view(part);
                        double x = GetFromString<double>(x_view);
                        x_i.push_back(x);
                        //get y
                        getline(line, part, ';');
                        string_view y_view(part);
                        double y = GetFromString<double>(y_view);
                        y_i.push_back(y);
                        //get z
                        getline(line, part, ';');
                        string_view z_view(part);
                        double z = GetFromString<double>(z_view);
                        z_i.push_back(z);
                    }
                    for(int ia = 0; ia < 3; ia++){
                        CartesianCoordinate coord_i(type, number, x_i[ia], y_i[ia], z_i[ia]);
                        dv.Add(freq[ia], coord_i);
                    }
                }
            }
        }
        return dv;
    }

vector<double> Deviation::GetFreq() const{
    vector<double> result;
    for(const auto& item : freq_to_id_){
        result.push_back(item.first);
    }
    return result;
}
