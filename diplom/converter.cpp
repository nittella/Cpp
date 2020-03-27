#include "converter.h"

using namespace std;

InternalAtomsCoordinates ConvertToInternal(
        const CartesianAtomsCoordinates& c_cords){
//    map<Atom, vector<pair<double, Atom>>> distances = c_cords.CalculateDestinations();
    DistancesManager dm(c_cords);
    int count = 1;
    InternalAtomsCoordinates result;
    bool count_type3 = true;
    int count_r = 0;
    int max_count_r = 6;
    int count_a = 0;
    int max_count_a = 0;
    int count_th = 0;
    int max_count_th = 1;
    string name;
    //type5 for
//    vector<vector<Atom>> external_planes = {
//            {{AtomType::C, 1},{AtomType::H, 63},{AtomType::C, 17}},
//            {{AtomType::C, 27},{AtomType::H, 60},{AtomType::C, 47}},
//            {{AtomType::C, 48},{AtomType::H, 57},{AtomType::C, 52}},
//            {{AtomType::C, 53},{AtomType::H, 54},{AtomType::C, 37}},
//            {{AtomType::C, 26},{AtomType::H, 69},{AtomType::C, 7}},
//            {{AtomType::C, 6},{AtomType::H, 66},{AtomType::C, 2}}
//    };
//
////    set<vector<Atom>> external_planes = {
////            {{AtomType::C, 1},{AtomType::H, 63},{AtomType::C, 17}},
////            {{AtomType::C, 48},{AtomType::H, 59},{AtomType::H, 58}},
////            {{AtomType::C, 48},{AtomType::H, 57},{AtomType::C, 52}},
////            {{AtomType::C, 37},{AtomType::H, 71},{AtomType::H, 70}},
////            {{AtomType::C, 26},{AtomType::H, 69},{AtomType::C, 7}},
////            {{AtomType::C, 1},{AtomType::H, 65},{AtomType::H, 64}}
////    };
//    vector<Atom> center_atoms = {
//            Atom{AtomType::C, 21},Atom{AtomType::C, 31},Atom{AtomType::C, 33}
//    };
//    for (auto& counter : vector<pair<int, int>>{{0, 1}, {2, 3}, {4, 5}, {0, 2}, {1, 3}, {2, 4}}){
//        vector<Atom> plane1 = external_planes[counter.first];
//        vector<Atom> plane2 = external_planes[counter.second];
//        Atom atom_c1 = plane1[0];
//        Atom atom_c2 = plane1[1];
//        Atom atom_c3 = plane1[2];
//        Atom atom_ex1 = plane2[0];
//        Atom atom_ex2 = plane2[1];
//        Atom atom_ex3 = plane2[2];
//        InternalCoordinate i_cord7(
//                count++,
//                InternalCoordinateTypeName::Type5,
//                vector<Atom>{atom_c2, atom_c3, atom_c1, atom_ex1, atom_ex2, atom_ex3},
//                name
//        );
//        result.Add(i_cord7);
//
//    }


    for(const auto& atom : dm) {
        name = "";
        //функ. группы по 3N - 2 + k(число связей с каркасом) координат на каждую
        if(dm.CheckEpoxide(atom)){
            name = "epox";
            //type1 for epoxide
            Atom atom_1 = dm.GetAtom(atom, 0);
            Atom atom_2 = dm.GetAtom(atom, 1);
            InternalCoordinate i_cord1(
                    count++,
                    InternalCoordinateTypeName::Type1,
                    vector<Atom>{atom_1, atom},
                    name
            );
            result.Add(i_cord1);
            //type3 for epoxide
            Atom atom_1_1 = dm.GetAtom(atom_1, 1);
            Atom atom_1_2 = dm.GetAtom(atom_1, 2);
            InternalCoordinate i_cord2(
                    count++,
                    InternalCoordinateTypeName::Type3,
                    vector<Atom>{ atom_1_1, atom, atom_1,  atom_1_2},
                    name
            );
            result.Add(i_cord2);

            Atom atom_2_1 = dm.GetAtom(atom_2, 1);
            Atom atom_2_2 = dm.GetAtom(atom_2, 2);
            InternalCoordinate i_cord3(
                    count++,
                    InternalCoordinateTypeName::Type3,
                    vector<Atom>{atom_2_1, atom, atom_2,  atom_2_2},
                    name
            );
            result.Add(i_cord3);
        }
        if (dm.CheckHydroxydeOxygen(atom)){
            name = "hydro";
            Atom atom_h = dm.GetAtom(atom, 0);
            Atom atom_c = dm.GetAtom(atom, 1);
            //type1 O-H
            InternalCoordinate i_cord1(
                    count++,
                    InternalCoordinateTypeName::Type1,
                    vector<Atom>{atom, atom_h},
                    name
            );
            result.Add(i_cord1);
            //type1 C-O
            InternalCoordinate i_cord2(
                    count++,
                    InternalCoordinateTypeName::Type1,
                    vector<Atom>{atom, atom_c},
                    name
            );
            result.Add(i_cord2);

            //type2 HOC
            InternalCoordinate i_cord3(
                    count++,
                    InternalCoordinateTypeName::Type2,
                    vector<Atom>{atom, atom_h, atom_c},
                    name
            );
            result.Add(i_cord3);
            //type2 OCC
            Atom atom_c_1 = dm.GetAtom(atom_c, 1);
            InternalCoordinate i_cord4(
                    count++,
                    InternalCoordinateTypeName::Type2,
                    vector<Atom>{atom_c, atom, atom_c_1},
                    name
            );
            result.Add(i_cord4);

            //type3 for OCCC
            Atom atom_c_2 = dm.GetAtom(atom_c, 2);
            InternalCoordinate i_cord5(
                    count++,
                    InternalCoordinateTypeName::Type3,
                    vector<Atom>{atom_c, atom, atom_c_2, atom_c_1},
                    name
            );
            result.Add(i_cord5);

            //type4 for HOCCC
            InternalCoordinate i_cord6(
                    count++,
                    InternalCoordinateTypeName::Type3,
                    vector<Atom>{atom_h, atom, atom_c, atom_c_1},
                    name
            );
            result.Add(i_cord6);
        }



        //type3 каркас для внутренних атомов
        name = "frame";
        if(dm.CheckFrameInternalCarbon(atom)
        || dm.CheckFrameInternalCarbonUnderFG(atom)
        || dm.CheckFrameExternalCarbon(atom)){
            Atom atom_1, atom_2, atom_3;
            atom_1 = dm.GetAtom(atom, 0);
            atom_2 = dm.GetAtom(atom, 1);
            atom_3 = dm.GetAtom(atom, 2);
//            if(atom == Atom{AtomType::C, 21}
//               || atom == Atom{AtomType::C, 31}
//               || atom == Atom{AtomType::C, 33}) {
                InternalCoordinate i_cord(
                        count++,
                        InternalCoordinateTypeName::Type3,
                        vector<Atom>{atom, atom_1, atom_2, atom_3},
                        name
                );
                result.Add(i_cord);
//            }
        }
        // type3 для внешних атомов углерода: определяем тераэдр через 1 атом
//        if(dm.CheckFrameExternalCarbon(atom)){
//            if(count_type3){
//                Atom atom_1, atom_2, atom_3;
//                atom_1 = dm.GetAtom(atom, 0);
//                atom_2 = dm.GetAtom(atom, 1);
//                atom_3 = dm.GetAtom(atom, 2);
//                InternalCoordinate i_cord(
//                        count++,
//                        InternalCoordinateTypeName::Type3,
//                        vector<Atom>{atom, atom_1, atom_2, atom_3},
//                        name
//                );
//                result.Add(i_cord);
//                count_type3 = false;
//            } else {
//                count_type3 = true;
//            }
//        }
        //type2 каркас углы при H
        if(dm.CheckFrameExternalHydrogen(atom)){
            Atom atom_1 = dm.GetAtom(atom, 0);
            Atom atom_1_1 = dm.GetAtom(atom_1, 1);
            InternalCoordinate i_cord1(
                    count++,
                    InternalCoordinateTypeName::Type2,
                    vector<Atom>{atom_1, atom, atom_1_1},
                    name
            );
            result.Add(i_cord1);
        }
        //type2 каркас углы при C
        if (dm.CheckFrameInternalCarbon(atom)
            || dm.CheckFrameInternalCarbonUnderFG(atom)
            || dm.CheckFrameExternalCarbon(atom)) {
                Atom atom_1, atom_2;
                if(dm.CheckFrameInternalCarbon(atom)){
                    atom_1 = dm.GetAtom(atom, 0);
                    atom_2 = dm.GetAtom(atom, 1);
                } else{
                    atom_1 = dm.GetAtom(atom, 1);
                    atom_2 = dm.GetAtom(atom, 2);
                }
            if(count_a < max_count_a
               && !dm.CheckFrameInternalCarbonUnderFG(atom)) {
                count_a++;
            }
            else {
                InternalCoordinate i_cord1(
                        count++,
                        InternalCoordinateTypeName::Type2,
                        vector<Atom>{atom_1, atom, atom_2},
                        name
                );
                result.Add(i_cord1);
            }
        }
    }
    //type1 каркас
    for(auto& atom : dm){
        for(int i = 0; i < dm.Size() - 1; i++){
            string name = "frame";
            Atom atom_i = dm.GetAtom(atom, i);
            //не работает почить
            if(dm.CheckFrameInternalCarbonUnderEpox(atom)
                            && dm.CheckFrameInternalCarbonUnderEpox(atom_i)){
                name += "_epox";
            } else if(dm.CheckFrameInternalCarbonUnderHydro(atom)){
                name += "_hydro";
            }
            if(dm.GetDistance(atom, atom_i)< MaxBoundLength()){ //считаем связью все что меньше 1.6
                bool condition = ((atom.type == AtomType::C && atom_i.type == AtomType::C)
                        || (atom.type == AtomType::H && atom_i.type == AtomType::C)
                        || (atom.type == AtomType::C && atom_i.type == AtomType::H)
                );
                if(condition){
                    dm.RemoveDistance(atom, atom_i);
                    if(count_r < max_count_r
                    && !dm.CheckFrameInternalCarbonUnderFG(atom)
                    && !dm.CheckFrameInternalCarbonUnderFG(atom_i)) {
                        count_r++;
                    }
                    else{
                        InternalCoordinate i_cord(
                                count++,
                                InternalCoordinateTypeName::Type1,
                                vector<Atom>{atom, atom_i},
                                name);
                        result.Add(i_cord);
                    }
                }
            }
        }
    }
    DistancesManager dm2(c_cords);

    for(auto& atom : dm2){
        for(int i = 0; i < dm.Size() - 1; i++) {
            string name;
            Atom atom_i = dm2.GetAtom(atom, i);
            if((dm2.CheckFrameExternalCarbon(atom_i))
            && dm2.CheckFrameExternalHydrogen(atom)
            && dm2.GetDistance(atom_i, atom) > 6
               && dm2.GetDistance(atom_i, atom) < 10
            ){
                name = "hc";
                InternalCoordinate i_cord(
                        count++,
                        InternalCoordinateTypeName::Type1,
                        vector<Atom>{atom, atom_i},
                        name);
                result.Add(i_cord);
                dm2.RemoveDistance(atom, atom_i);

            }
            if((dm2.CheckFrameExternalHydrogen(atom_i))
               && dm2.CheckFrameExternalHydrogen(atom)
               && dm2.GetDistance(atom_i, atom) > 6
               && dm2.GetDistance(atom_i, atom) < 10
                    ){
                name = "cc";
                InternalCoordinate i_cord(
                        count++,
                        InternalCoordinateTypeName::Type1,
                        vector<Atom>{atom, atom_i},
                        name);
                result.Add(i_cord);
                dm2.RemoveDistance(atom, atom_i);
                break;
            }
        }
    }
    return result;
}








