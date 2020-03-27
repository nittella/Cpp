#include "converter.h"
#include "calculate_distance.h"
#include "circles_dict.h"

InternalAtomsCoordinates ConvertToInternal(
        const CartesianAtomsCoordinates& c_cords){
    InternalAtomsCoordinates result;
    int count = 1;
    int prev_circle = 1;
    bool count_t2 = true;
    for (auto [CircleNumber, Atoms] : CIRCLE_DICT){


        int prev_atom = Atoms[5];
        AtomType type = AtomType::C;
        if(CircleNumber >= 10){
            type = AtomType::H;
        }
        for(int i = 0; i < 6; i++){
            string name = "circle" + to_string(CircleNumber) + "_" + to_string(i);
            InternalCoordinate i_cord(
                    count++,
                    InternalCoordinateTypeName::Type1,
                    vector<Atom>{{type, prev_atom},
                                 {type, Atoms[i]}
                                 },
                    name);
            result.Add(i_cord);
            if(i < 5 && count_t2){
                InternalCoordinate i_cord2(
                        count++,
                        InternalCoordinateTypeName::Type2,
                        vector<Atom>{{type, Atoms[i]},
                                     {type, prev_atom},
                                     {type, Atoms[i+1]}
                        },
                        name);
                result.Add(i_cord2);
                count_t2 = false;
            } else {
                count_t2 = true;
            }


            prev_atom = Atoms[i];
        }
        string name = "circle" + to_string(CircleNumber);
        InternalCoordinate i_cord3_1(
                count++,
                InternalCoordinateTypeName::Type4,
                vector<Atom>{{type, Atoms[0]},
                             {type, Atoms[1]},
                             {type, Atoms[3]},
                             {type, Atoms[4]}
                },
                name);
        result.Add(i_cord3_1);

        InternalCoordinate i_cord3_2(
                count++,
                InternalCoordinateTypeName::Type4,
                vector<Atom>{{type, Atoms[1]},
                             {type, Atoms[2]},
                             {type, Atoms[4]},
                             {type, Atoms[5]}
                },
                name);
        result.Add(i_cord3_2);


        InternalCoordinate i_cord3_3(
                count++,
                InternalCoordinateTypeName::Type3,
                vector<Atom>{{type, Atoms[0]},
                             {type, Atoms[1]},
                             {type, Atoms[3]},
                             {type, Atoms[5]}
                },
                name);
        result.Add(i_cord3_3);

        if(CircleNumber > 1){
            for(int i = 0; i < 6; i++){
                int k = i + 1;
                int l = i - 1;
                if(i == 0){
                    l = 5;
                } else if(i == 5){
                    k = 0;
                }
                string name = "c-c" + to_string(CircleNumber) + "_" + to_string(prev_circle);
                InternalCoordinate i_cord4(
                        count++,
                        InternalCoordinateTypeName::Type2,
                        vector<Atom>{{type, CIRCLE_DICT[CIRCLE_CONECTION[CircleNumber]][i]},
                                     {type, Atoms[i]},
                                     {type, CIRCLE_DICT[CIRCLE_CONECTION[CircleNumber]][k]},
                        },
                        name);
                result.Add(i_cord4);
                InternalCoordinate i_cord5(
                        count++,
                        InternalCoordinateTypeName::Type3,
                        vector<Atom>{{type, Atoms[i]},
                                     {type, CIRCLE_DICT[CIRCLE_CONECTION[CircleNumber]][i]},
                                     {type, CIRCLE_DICT[CIRCLE_CONECTION[CircleNumber]][k]},
                                     {type, CIRCLE_DICT[CIRCLE_CONECTION[CircleNumber]][l]}
                        },
                        name);
                result.Add(i_cord5);
            }
            prev_circle = CircleNumber;
        }
    }

    return result;
}