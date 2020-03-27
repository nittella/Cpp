#include "converter.h"
#include "circles_dict.h"

InternalAtomsCoordinates ConvertToInternal(
        const CartesianAtomsCoordinates& c_cords) {
    InternalAtomsCoordinates result;
    int count = 1;
    AtomType type = AtomType::C;
    // coords for circle 1
    string name = "c0_";
    string name_cc = name + "CC";
    int prev_atom = CIRCLE_DICT.at(0)[5];
    for (auto atom : CIRCLE_DICT.at(0)) {

        InternalCoordinate r_cc(
                count++,
                InternalCoordinateTypeName::Type1,
                vector<Atom>{{type, prev_atom},
                             {type, atom}},
                name_cc);
        result.Add(r_cc);
        prev_atom = atom;
    }


    string name_accc = name + "CCC";
    InternalCoordinate a_ccc1(
            count++,
            InternalCoordinateTypeName::Type2,
            vector<Atom>{{type, CIRCLE_DICT.at(0)[1]},
                         {type, CIRCLE_DICT.at(0)[0]},
                         {type, CIRCLE_DICT.at(0)[2]}},
            name_accc);
    result.Add(a_ccc1);
    InternalCoordinate a_ccc2(
            count++,
            InternalCoordinateTypeName::Type2,
            vector<Atom>{{type, CIRCLE_DICT.at(0)[3]},
                         {type, CIRCLE_DICT.at(0)[4]},
                         {type, CIRCLE_DICT.at(0)[2]}},
            name_accc);
    result.Add(a_ccc2);
    InternalCoordinate a_ccc3(
            count++,
            InternalCoordinateTypeName::Type2,
            vector<Atom>{{type, CIRCLE_DICT.at(0)[5]},
                         {type, CIRCLE_DICT.at(0)[0]},
                         {type, CIRCLE_DICT.at(0)[4]}},
            name_accc);
    result.Add(a_ccc3);

    string name_tacccc = name + "CCCC";
    InternalCoordinate ta_cccc1(
            count++,
            InternalCoordinateTypeName::Type3,
            vector<Atom>{{type, CIRCLE_DICT.at(0)[0]},
                         {type, CIRCLE_DICT.at(0)[1]},
                         {type, CIRCLE_DICT.at(0)[2]},
                         {type, CIRCLE_DICT.at(0)[3]}},
            name_tacccc);
    result.Add(ta_cccc1);

    InternalCoordinate ta_cccc2(
            count++,
            InternalCoordinateTypeName::Type3,
            vector<Atom>{{type, CIRCLE_DICT.at(0)[2]},
                         {type, CIRCLE_DICT.at(0)[3]},
                         {type, CIRCLE_DICT.at(0)[4]},
                         {type, CIRCLE_DICT.at(0)[5]}},
            name_tacccc);
    result.Add(ta_cccc2);

    InternalCoordinate ta_cccc3(
            count++,
            InternalCoordinateTypeName::Type3,
            vector<Atom>{{type, CIRCLE_DICT.at(0)[4]},
                         {type, CIRCLE_DICT.at(0)[5]},
                         {type, CIRCLE_DICT.at(0)[0]},
                         {type, CIRCLE_DICT.at(0)[1]}},
            name_tacccc);
    result.Add(ta_cccc3);

//    name = "c2_";
//    string name_cc2 = name + "CC";
//    prev_atom = CIRCLE_DICT.at(2)[5];
//    for (auto atom : CIRCLE_DICT.at(2)) {
//
//        InternalCoordinate r_cc(
//                count++,
//                InternalCoordinateTypeName::Type1,
//                vector<Atom>{{type, prev_atom},
//                             {type, atom}},
//                name_cc2);
//        result.Add(r_cc);
//        prev_atom = atom;
//    }
//
//    string name_accc2 = name + "CCC";
//    InternalCoordinate a_ccc12(
//            count++,
//            InternalCoordinateTypeName::Type2,
//            vector<Atom>{{type, CIRCLE_DICT.at(2)[1]},
//                         {type, CIRCLE_DICT.at(2)[0]},
//                         {type, CIRCLE_DICT.at(2)[2]}},
//            name_accc2);
//    result.Add(a_ccc12);
//    InternalCoordinate a_ccc22(
//            count++,
//            InternalCoordinateTypeName::Type2,
//            vector<Atom>{{type, CIRCLE_DICT.at(2)[3]},
//                         {type, CIRCLE_DICT.at(2)[4]},
//                         {type, CIRCLE_DICT.at(2)[2]}},
//            name_accc2);
//    result.Add(a_ccc22);
//    InternalCoordinate a_ccc32(
//            count++,
//            InternalCoordinateTypeName::Type2,
//            vector<Atom>{{type, CIRCLE_DICT.at(2)[5]},
//                         {type, CIRCLE_DICT.at(2)[0]},
//                         {type, CIRCLE_DICT.at(2)[4]}},
//            name_accc2);
//    result.Add(a_ccc32);
//
//    string name_tacccc2 = name + "CCCC";
//    InternalCoordinate ta_cccc12(
//            count++,
//            InternalCoordinateTypeName::Type3,
//            vector<Atom>{{type, CIRCLE_DICT.at(2)[0]},
//                         {type, CIRCLE_DICT.at(2)[1]},
//                         {type, CIRCLE_DICT.at(2)[2]},
//                         {type, CIRCLE_DICT.at(2)[3]}},
//            name_tacccc2);
//    result.Add(ta_cccc12);
//
//    InternalCoordinate ta_cccc22(
//            count++,
//            InternalCoordinateTypeName::Type3,
//            vector<Atom>{{type, CIRCLE_DICT.at(2)[2]},
//                         {type, CIRCLE_DICT.at(2)[3]},
//                         {type, CIRCLE_DICT.at(2)[4]},
//                         {type, CIRCLE_DICT.at(2)[5]}},
//            name_tacccc2);
//    result.Add(ta_cccc22);
//
//    InternalCoordinate ta_cccc32(
//            count++,
//            InternalCoordinateTypeName::Type3,
//            vector<Atom>{{type, CIRCLE_DICT.at(2)[4]},
//                         {type, CIRCLE_DICT.at(2)[5]},
//                         {type, CIRCLE_DICT.at(2)[0]},
//                         {type, CIRCLE_DICT.at(2)[1]}},
//            name_tacccc2);
//    result.Add(ta_cccc32);
//
//    name = "c3_";
//    string name_cc3 = name + "CC";
//    prev_atom = CIRCLE_DICT.at(3)[5];
//    for (auto atom : CIRCLE_DICT.at(3)) {
//
//        InternalCoordinate r_cc(
//                count++,
//                InternalCoordinateTypeName::Type1,
//                vector<Atom>{{type, prev_atom},
//                             {type, atom}},
//                name_cc3);
//        result.Add(r_cc);
//        prev_atom = atom;
//    }
//    string name_accc3 = name + "CCC";
//    InternalCoordinate a_ccc13(
//            count++,
//            InternalCoordinateTypeName::Type2,
//            vector<Atom>{{type, CIRCLE_DICT.at(3)[1]},
//                         {type, CIRCLE_DICT.at(3)[0]},
//                         {type, CIRCLE_DICT.at(3)[2]}},
//            name_accc3);
//    result.Add(a_ccc13);
//    InternalCoordinate a_ccc23(
//            count++,
//            InternalCoordinateTypeName::Type2,
//            vector<Atom>{{type, CIRCLE_DICT.at(3)[3]},
//                         {type, CIRCLE_DICT.at(3)[4]},
//                         {type, CIRCLE_DICT.at(3)[2]}},
//            name_accc3);
//    result.Add(a_ccc23);
//    InternalCoordinate a_ccc33(
//            count++,
//            InternalCoordinateTypeName::Type2,
//            vector<Atom>{{type, CIRCLE_DICT.at(3)[5]},
//                         {type, CIRCLE_DICT.at(3)[0]},
//                         {type, CIRCLE_DICT.at(3)[4]}},
//            name_accc3);
//    result.Add(a_ccc33);
//
//    string name_tacccc3 = name + "CCCC";
//    InternalCoordinate ta_cccc13(
//            count++,
//            InternalCoordinateTypeName::Type3,
//            vector<Atom>{{type, CIRCLE_DICT.at(3)[0]},
//                         {type, CIRCLE_DICT.at(3)[1]},
//                         {type, CIRCLE_DICT.at(3)[2]},
//                         {type, CIRCLE_DICT.at(3)[3]}},
//            name_tacccc3);
//    result.Add(ta_cccc13);
//
//    InternalCoordinate ta_cccc23(
//            count++,
//            InternalCoordinateTypeName::Type3,
//            vector<Atom>{{type, CIRCLE_DICT.at(3)[2]},
//                         {type, CIRCLE_DICT.at(3)[3]},
//                         {type, CIRCLE_DICT.at(3)[4]},
//                         {type, CIRCLE_DICT.at(3)[5]}},
//            name_tacccc3);
//    result.Add(ta_cccc23);
//
//    InternalCoordinate ta_cccc33(
//            count++,
//            InternalCoordinateTypeName::Type3,
//            vector<Atom>{{type, CIRCLE_DICT.at(3)[4]},
//                         {type, CIRCLE_DICT.at(3)[5]},
//                         {type, CIRCLE_DICT.at(3)[0]},
//                         {type, CIRCLE_DICT.at(3)[1]}},
//            name_tacccc3);
//    result.Add(ta_cccc33);

    // for every circle except first
    for (int i = 1; i < CIRCLE_DICT.size(); i++) {
        name = "c" + to_string(i) + "_";

        for (int j = 0; j < CIRCLE_DICT.at(i).size(); j++) {
            string name_rmd = name + "DM";
            int daughter_atom = CIRCLE_DICT.at(i)[j];
            int mother_atom_1 = CIRCLE_DICT.at(CIRCLE_CONECTION.at(i))[j];
            InternalCoordinate r_md(
                    count++,
                    InternalCoordinateTypeName::Type1,
                    vector<Atom>{{type, daughter_atom},
                                 {type, mother_atom_1}},
                    name_rmd);
            result.Add(r_md);
        }
        if (i != 2 && i != 3) {
            for (int j = 0; j < CIRCLE_DICT.at(i).size(); j++) {
                int daughter_atom = CIRCLE_DICT.at(i)[j];
                int mother_atom_1 = CIRCLE_DICT.at(CIRCLE_CONECTION.at(i))[j];
                string name_admm = name + "DMM";
                int k = j + 1;
                if (j == 5) {
                    k = 0;
                }
                int mother_atom_2 = CIRCLE_DICT.at(CIRCLE_CONECTION.at(i))[k];
                InternalCoordinate a_dmm(
                        count++,
                        InternalCoordinateTypeName::Type2,
                        vector<Atom>{{type, mother_atom_1},
                                     {type, daughter_atom},
                                     {type, mother_atom_2}},
                        name_admm);
                result.Add(a_dmm);
            }

            string name_dmmd = name + "DMMD";
            InternalCoordinate ta_dmmd1(
                    count++,
                    InternalCoordinateTypeName::Type3,
                    vector<Atom>{{type, CIRCLE_DICT.at(i)[0]},
                                 {type, CIRCLE_DICT.at(CIRCLE_CONECTION.at(i))[0]},
                                 {type, CIRCLE_DICT.at(CIRCLE_CONECTION.at(i))[1]},
                                 {type, CIRCLE_DICT.at(i)[1]}},
                    name_dmmd);
            result.Add(ta_dmmd1);

            InternalCoordinate ta_dmmd2(
                    count++,
                    InternalCoordinateTypeName::Type3,
                    vector<Atom>{{type, CIRCLE_DICT.at(i)[2]},
                                 {type, CIRCLE_DICT.at(CIRCLE_CONECTION.at(i))[2]},
                                 {type, CIRCLE_DICT.at(CIRCLE_CONECTION.at(i))[3]},
                                 {type, CIRCLE_DICT.at(i)[3]}},
                    name_dmmd);
            result.Add(ta_dmmd2);

            InternalCoordinate ta_dmmd3(
                    count++,
                    InternalCoordinateTypeName::Type3,
                    vector<Atom>{{type, CIRCLE_DICT.at(i)[4]},
                                 {type, CIRCLE_DICT.at(CIRCLE_CONECTION.at(i))[4]},
                                 {type, CIRCLE_DICT.at(CIRCLE_CONECTION.at(i))[5]},
                                 {type, CIRCLE_DICT.at(i)[5]}},
                    name_dmmd);
            result.Add(ta_dmmd3);

            string name_dmmm = name + "DMMM";
            InternalCoordinate ta_dmmm1(
                    count++,
                    InternalCoordinateTypeName::Type3,
                    vector<Atom>{{type, CIRCLE_DICT.at(i)[0]},
                                 {type, CIRCLE_DICT.at(CIRCLE_CONECTION.at(i))[0]},
                                 {type, CIRCLE_DICT.at(CIRCLE_CONECTION.at(i))[1]},
                                 {type, CIRCLE_DICT.at(CIRCLE_CONECTION.at(i))[2]}},
                    name_dmmm);
            result.Add(ta_dmmm1);

            InternalCoordinate ta_dmmm2(
                    count++,
                    InternalCoordinateTypeName::Type3,
                    vector<Atom>{{type, CIRCLE_DICT.at(i)[2]},
                                 {type, CIRCLE_DICT.at(CIRCLE_CONECTION.at(i))[2]},
                                 {type, CIRCLE_DICT.at(CIRCLE_CONECTION.at(i))[3]},
                                 {type, CIRCLE_DICT.at(CIRCLE_CONECTION.at(i))[4]}},
                    name_dmmm);
            result.Add(ta_dmmm2);

            InternalCoordinate ta_dmmm3(
                    count++,
                    InternalCoordinateTypeName::Type3,
                    vector<Atom>{{type, CIRCLE_DICT.at(i)[4]},
                                 {type, CIRCLE_DICT.at(CIRCLE_CONECTION.at(i))[4]},
                                 {type, CIRCLE_DICT.at(CIRCLE_CONECTION.at(i))[5]},
                                 {type, CIRCLE_DICT.at(CIRCLE_CONECTION.at(i))[0]}},
                    name_dmmm);
            result.Add(ta_dmmm3);
        }
    }

    int count_t3 = true;
    for(int i = 0; i < CIRCLE_DICT.at(1).size(); i++){
        int k = i + 1;
        if(i == 5){
            k = 0;
        }
        int l = i - 1;
        if(i == 0){
            l = 5;
        }
        name = "c2c3_";
        string name_mdd = name + "MD2D3";
        InternalCoordinate a_mdd(
                count++,
                InternalCoordinateTypeName::Type2,
                vector<Atom>{
                        {type, CIRCLE_DICT.at(2)[i]},
                        {type, CIRCLE_DICT.at(1)[i]},
                        {type, CIRCLE_DICT.at(3)[k]}
                },
                name_mdd);
        result.Add(a_mdd);

        string name_dmd = name + "D3MD2";
        InternalCoordinate a_dmd(
                count++,
                InternalCoordinateTypeName::Type2,
                vector<Atom>{
                        {type, CIRCLE_DICT.at(1)[i]},
                        {type, CIRCLE_DICT.at(2)[i]},
                        {type, CIRCLE_DICT.at(3)[i]}
                },
                name_dmd);
        result.Add(a_dmd);

        string name_mddm = name + "snake";
        InternalCoordinate ta_mddm(
                count++,
                InternalCoordinateTypeName::Type3,
                vector<Atom>{
                        {type, CIRCLE_DICT.at(3)[i]},
                        {type, CIRCLE_DICT.at(1)[i]},
                        {type, CIRCLE_DICT.at(2)[i]},
                        {type, CIRCLE_DICT.at(3)[k]}
                },
                name_mddm);
        result.Add(ta_mddm);

        string name_2 = name + "MDDM";
        InternalCoordinate ta_2(
                count++,
                InternalCoordinateTypeName::Type3,
                vector<Atom>{
                        {type, CIRCLE_DICT.at(1)[i]},
                        {type, CIRCLE_DICT.at(2)[i]},
                        {type, CIRCLE_DICT.at(3)[k]},
                        {type, CIRCLE_DICT.at(1)[k]}
                },
                name_2);
        result.Add(ta_2);


    }
    return result;
}