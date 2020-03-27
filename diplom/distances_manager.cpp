#include "distances_manager.h"

double MaxBoundLength(){
    return 1.6;
}

DistancesManager::DistancesManager(const CartesianAtomsCoordinates& c_cords) {


    for (const auto &coordinate1 : c_cords) {
        Atom atom1 = {coordinate1.GetType(), coordinate1.GetNumber()};

        vector<pair<double, Atom>> tmp_v;
        map<Atom, double> tmp_m;
        for (const auto &coordinate2 : c_cords) {
            if (coordinate1 != coordinate2) {
                Atom atom2 = {coordinate2.GetType(), coordinate2.GetNumber()};
                double distance = coordinate1.CalculateDestination(coordinate2);
                tmp_v.push_back({distance, {atom2}});
                tmp_m[atom2] = distance;
            }
        }
        sort(tmp_v.begin(), tmp_v.end(),
             [](pair<double, Atom> p1, pair<double, Atom> p2) { return p1.first < p2.first; }
        );


        atoms_.insert(atom1);
        distances_.insert({atom1, tmp_v});
        atoms_to_distances_.insert({atom1, tmp_m});

        //mass center
//        double total_mass = 0;
//        double mass_x = 0;
//        double mass_y = 0;
//        double mass_z = 0;
//        for (const auto &coordinate : c_cords) {
//            Atom atom = {coordinate.GetType(), coordinate.GetNumber()};
//            if(CheckFrameInternalCarbonUnderFG(atom) || CheckFrameInternalCarbon(atom)
//            || CheckFrameExternalCarbon(atom)){
//                total_mass += 12;
//                mass_x += 12 * coordinate.GetX();
//                mass_y += 12 * coordinate.GetY();
//                mass_z += 12 * coordinate.GetZ();
//            } else if(CheckFrameExternalHydrogen(atom)){
//                total_mass += 1;
//                mass_x += 1 * coordinate.GetX();
//                mass_y += 1 * coordinate.GetY();
//                mass_z += 1 * coordinate.GetZ();
//            }
//        }
//        CartesianCoordinate mass_center_coord(
//                AtomType::NoType,
//                0,
//                1/total_mass * mass_x,
//                1/total_mass * mass_y,
//                1/total_mass * mass_z);
//        //diameter to mass center
//        for (const auto &coordinate : c_cords) {
//            Atom atom = {coordinate1.GetType(), coordinate1.GetNumber()};
//            double distance = mass_center_coord.CalculateDestination(coordinate);
//            to_mass_center_.push_back({distance, atom});
//            sort(to_mass_center_.begin(), to_mass_center_.end(),
//                 [](pair<double, Atom> p1, pair<double, Atom> p2) { return p1.first < p2.first; }
//            );
//        }
    }
}

size_t DistancesManager::Size() const{
    return atoms_.size();
}


Atom DistancesManager::GetAtom(const Atom& main_atom, int number) const {
    return distances_.at(main_atom)[number].second;
}


Atom DistancesManager::GetFirstAtom() const{
    return *atoms_.begin();
};

double DistancesManager::GetDistance(const Atom& atom1, const Atom& atom2) const{
    return atoms_to_distances_.at(atom1).at(atom2);
}

void DistancesManager::RemoveDistance(const Atom& atom1, const Atom& atom2){
    distances_[atom2].erase(
            remove(
                    distances_[atom2].begin(),
                    distances_[atom2].end(),
                    make_pair(GetDistance(atom2, atom1), atom1)
            ),
            distances_[atom2].end()
    );
}

//Atom DistancesManager::GetAtomFromMassCenter(int number) const{
//    return to_mass_center_[number].second;
//}

set<Atom>::iterator DistancesManager::begin(){
    return atoms_.begin();
}

set<Atom>::iterator DistancesManager::end(){
    return atoms_.end();
}

set<Atom>::const_iterator DistancesManager::begin() const{
    return atoms_.begin();
}

set<Atom>::const_iterator DistancesManager::end() const{
    return atoms_.end();
}

bool DistancesManager::CheckEpoxide(const Atom& atom) const{
    const auto& item = distances_.at(atom);
    bool result = (atom.type == AtomType::O
                   && item[0].first < MaxBoundLength()
                   && item[0].second.type == AtomType::C
                   && item[1].first < MaxBoundLength()
                   && item[1].second.type == AtomType::C);
    return result;
};

bool DistancesManager::CheckFrameInternalCarbon(const Atom& atom) const{
    const auto& item = distances_.at(atom);
    bool result = (atom.type == AtomType::C
                   && item[0].first < MaxBoundLength()
                   && item[0].second.type == AtomType::C
                   && item[1].first < MaxBoundLength()
                   && item[1].second.type == AtomType::C
                   && item[2].first < MaxBoundLength()
                   && item[2].second.type == AtomType::C
    );
    return result;
};

bool DistancesManager::CheckFrameExternalCarbon(const Atom& atom) const{
    const auto& item = distances_.at(atom);
    bool result= (atom.type == AtomType::C
                  && item[0].first < MaxBoundLength()
                  && item[0].second.type == AtomType::H
    );
    return result;
};

bool DistancesManager::CheckFrameExternalHydrogen(const Atom& atom) const{
    const auto& item = distances_.at(atom);
    bool result = (atom.type == AtomType::H
                   && item[0].first < MaxBoundLength()
                   && item[0].second.type == AtomType::C
    );
    return result;
}

bool DistancesManager::CheckFrameInternalCarbonUnderFG(const Atom& atom) const{
    const auto& item = distances_.at(atom);

    Atom atom1 = GetAtom(atom, 0);
    Atom atom2 = GetAtom(atom, 1);
    Atom atom3 = GetAtom(atom, 2);
    Atom atom4 = GetAtom(atom, 3);
    set<AtomType> group = {
            atom1.type,
            atom2.type,
            atom3.type,
            atom4.type
    };
    return atom.type == AtomType ::C
           && group == set<AtomType >{AtomType::C, AtomType::O}
           && GetDistance(atom, atom1) <= MaxBoundLength()
           && GetDistance(atom, atom2) <= MaxBoundLength()
           && GetDistance(atom, atom3) <= MaxBoundLength();
}

bool DistancesManager::CheckFrameInternalCarbonUnderEpox(const Atom& atom) const{
    return CheckFrameInternalCarbonUnderFG(atom) && GetAtom(atom, 4).type != AtomType::H;
}

bool DistancesManager::CheckFrameInternalCarbonUnderHydro(const Atom& atom) const{
    return CheckFrameInternalCarbonUnderFG(atom) && GetAtom(atom, 4).type == AtomType::H;
}

bool DistancesManager::CheckHydroxydeOxygen(const Atom& atom) const{
    const auto& item = distances_.at(atom);
    bool result = (atom.type == AtomType::O
                   && item[0].first < MaxBoundLength()
                   && item[0].second.type == AtomType::H
                   && item[1].first < MaxBoundLength()
                   && item[1].second.type == AtomType::C);
    return result;
}




bool DistancesManager::CheckHydroxydeHydrogen(const Atom& atom) const{
    return true;
};