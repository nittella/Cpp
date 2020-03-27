#include <iostream>
#include <string_view>
#include <string>
#include <fstream>
#include <array>
#include <set>
#include <iomanip>

#include "converter_2.h"
#include "deviation_reader.h"
using namespace std;

template <typename T>
ostream& operator<< (ostream& os, vector<T> v){
    for (auto& item : v){
        os << item << "\n";
    }
    return os;
}

template <typename Key, typename Value>
ostream& operator<< (ostream& os, pair<Key, Value> p){
    os << p.first << " " << p.second;
    return os;
}

int main(){
    CartesianAtomsCoordinates coordinates = ReadCoordinates("input104");

    map<Atom, vector<pair<double, Atom>>> dict = coordinates.CalculateDestinations();

    InternalAtomsCoordinates internal_coordinates = ConvertToInternal(coordinates);
    ofstream output("output");
    output << internal_coordinates;

//    Deviation dev = DeviationReader("deviations_c6h6");
//
//    ofstream out_3("out_3");
//    for (const auto& item : dev.CalculateBestType3(coordinates)){
//        out_3 << setw(8) << item.first;
//        for(int i = item.second.size() - 1; i >= 0; i--){
//            auto p = *next(item.second.begin(), i);
//            out_3 << setw(20) << p.first << " ";
//            for(const auto& atom : p.second){
//                out_3 << atom;
//            }
//        }
//        out_3 << '\n';
//    }
//    ofstream out_2("out_2");
//    for (const auto& item : dev.CalculateBestType2(coordinates)){
//        out_2 << setw(8) << item.first;
//        for(int i = item.second.size() - 1; i >= 0; i--){
//            auto p = *next(item.second.begin(), i);
//            out_2 << setw(20) << p.first << " ";
//            for(const auto& atom : p.second){
//                out_2 << atom;
//            }
//        }
//        out_2 << '\n';
//    }
//
//    ofstream out_1("out_1");
//    for(const auto& item : dev.CalculateBestType1(coordinates)){
//        out_1 << setw(8) << item.first;
//        for(const auto& p : item.second){
//            out_1 << setw(20) << p.first << " ";
//            out_1 << p.second.first << p.second.second;
//        }
//        out_1 << '\n';
//    }
    return 0;
}
