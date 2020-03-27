#include <iostream>
#include <vector>
#include <list>

using namespace std;


class Line{
public:
    Line()
    : line_(1, -1){
        pointers_.assign(MAX_ATHLETS_COUNT_, line_.begin());
    };

    void AddToLine(int athlet_number, int pos){
        if(*pointers_[pos] == -1){
            pointers_[athlet_number] = line_.emplace(line_.end(),athlet_number);
        } else {
            pointers_[athlet_number] = line_.emplace(pointers_[pos], athlet_number);
        }
    };

    void PrintLine(){
        if(!line_.empty()){
            for (auto it = ++line_.begin(); it != line_.end(); it++){
                cout << *it;
                if(it != --line_.end()){
                    cout << ' ';
                }
            }
            cout << endl;
        }
    };
private:
    int MAX_ATHLETS_COUNT_ = 100'000;
    vector<list<int>::iterator> pointers_;
    list<int> line_;
};


int main(){
    int n;
    cin >> n;
    Line line;
    for (int i = 0; i < n; i++){
        int athlet_number, pos;
        cin >> athlet_number >> pos;
        line.AddToLine(athlet_number, pos);
    }
    line.PrintLine();

    return 0;
}