#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <set>
using namespace std;

int main(){
    pair<int, string> pair1 = make_pair(5, "mama");
    pair<int, string> pair2 = make_pair(6, "a");
    if (pair1 < pair2){
        cout << "it's working" << '\n';
    } else {
        cout << "it isn't working" << '\n';
    }



    return 0;
}