#include "converter.h"
#include "calculate_distance.h"
#include "distance_predicator.h"

using Bond = pair<Atom, Atom>;

double GetBondsDistance(pair<Atom, Atom> bond1, pair<Atom, Atom> bond2,
        const CartesianAtomsCoordinates& c_cords){
    double x_1 = c_cords.GetCoordinate(bond1.first.number).GetX();
    double y_1 = c_cords.GetCoordinate(bond1.first.number).GetY();
    double z_1 = c_cords.GetCoordinate(bond1.first.number).GetZ();

    double x_2 = c_cords.GetCoordinate(bond1.second.number).GetX();
    double y_2 = c_cords.GetCoordinate(bond1.second.number).GetY();
    double z_2 = c_cords.GetCoordinate(bond1.second.number).GetZ();

    double x_3 = c_cords.GetCoordinate(bond2.first.number).GetX();
    double y_3 = c_cords.GetCoordinate(bond2.first.number).GetY();
    double z_3 = c_cords.GetCoordinate(bond2.first.number).GetZ();

    double x_4 = c_cords.GetCoordinate(bond2.second.number).GetX();
    double y_4 = c_cords.GetCoordinate(bond2.second.number).GetY();
    double z_4 = c_cords.GetCoordinate(bond2.second.number).GetZ();

    double distance = sqrt(
            pow((x_1 + x_2 - x_3 - x_4) / 2, 2)
            + pow((y_1 + y_2 - y_3 - y_4) / 2, 2)
            + pow((z_1 + z_2 - z_3 - z_4) / 2, 2));
    return distance;
}

InternalAtomsCoordinates ConvertToInternal(
        const CartesianAtomsCoordinates& c_cords){
    int count = 1;
    string name;
    DistancesManager dm1(c_cords);
    InternalAtomsCoordinates result;
    map<Atom, bool> not_determined;
    vector<Atom> stack;
    for(const Atom& atom : dm1){
        not_determined.insert({atom, true});
        stack.push_back(atom);
    }
    vector<Bond> bonds;
    map<Atom, set<Atom>> bonds_by_atom;
    //type1
    while (!stack.empty()){
        Atom atom = stack.back();
        stack.pop_back();
        for(int i = 0; i < dm1.Size() - 1; i++){
            Atom atom_i = dm1.GetAtom(atom, i);
            if(DistancePredicator(dm1.GetDistance(atom, atom_i))){
                if(not_determined[atom_i]){
                    stack.push_back(atom_i);
                    InternalCoordinate i_cord(count++, InternalCoordinateTypeName::Type1,
                                              vector<Atom>{atom, atom_i}, name);
                    result.Add(i_cord);
                    not_determined[atom_i] = false;
                    not_determined[atom] = false;
                    bonds_by_atom[atom].insert(atom_i);
                    bonds_by_atom[atom_i].insert(atom);
                    bonds.push_back({atom, atom_i});
                }
            } else {
                break;
            }
        }
    }

    for(auto [atom, atoms] : bonds_by_atom){
        if(atoms.size() > 1){
            Atom atom_end = *prev(atoms.end());
            for (auto atom_i : atoms){
                if(atom_i != atom_end){
                    InternalCoordinate i_cord(count++, InternalCoordinateTypeName::Type2,
                                              vector<Atom>{atom, atom_i, atom_end}, name);
                    result.Add(i_cord);
                }
            }
        }
    }

    map<Bond, vector<pair<double, Bond>>> bond_to_distance;
    for (auto bond : bonds){
        for(auto bond_i : bonds){
            if(bond != bond_i){
                double distance = GetBondsDistance(bond, bond_i, c_cords);
                bond_to_distance[bond].push_back({distance, bond_i});
            }
        }
        sort(bond_to_distance[bond].begin(),bond_to_distance[bond].end(),
                [](const pair<double, Bond> p1, const pair<double, Bond> p2){
            return p1.first < p2.first;
        });
    }

    for(auto [bond, v] : bond_to_distance){
        Atom atom1 = bond.first;
        Atom atom2 = bond.second;
        for (int i = 0; i < v.size(); i++){
            Atom atom3 = v[i].second.first;
            Atom atom4 = v[i].second.second;
            if(set<Atom>{atom1, atom2, atom3, atom4}.size() == 4){
                if(CalculateDistance(c_cords.GetCoordinate(atom2.number), c_cords.GetCoordinate(atom3.number))
                > CalculateDistance(c_cords.GetCoordinate(atom1.number), c_cords.GetCoordinate(atom4.number))){
                    Atom tmp = atom1;
                    atom1 = atom2;
                    atom2 = tmp;
                    tmp = atom3;
                    atom3 = atom4;
                    atom4 = tmp;
                }
                InternalCoordinate i_cord(
                        count++,
                        InternalCoordinateTypeName::Type4,
                        vector<Atom>{atom4, atom3, atom2, atom1},
                        name);
                result.Add(i_cord);

//                bond_to_distance[bond].erase(
//                        remove(
//                                bond_to_distance[bond].begin(),
//                                bond_to_distance[bond].end(),
//                                make_pair(v[i].first, bond)
//                        ),
//                        bond_to_distance[v[i].second].end()
//                );
                Bond tmp = bond;
                bond_to_distance[v[i].second].erase(
                        remove_if(
                                bond_to_distance[v[i].second].begin(),
                                bond_to_distance[v[i].second].end(),
                                [tmp](pair<double, Bond> p){
                                    return (p.second.first == tmp.second
                                    && p.second.second == tmp.first)
                                    || (p.second.second == tmp.second
                                        && p.second.first == tmp.first);}
                        ),
                        bond_to_distance[v[i].second].end()
                );
                break;
            }
        }
    }


    return  result;
}