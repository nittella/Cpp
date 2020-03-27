#include <vector>
#include <iostream>

using namespace std;

template <typename T>
class Deque{
public:
    Deque(){}

    bool Empty() const {
        return reverse_front_part.empty() && back_part.empty();
    }

    size_t Size() const {
        return reverse_front_part.size() + back_part.size();
    }

    T& operator[](size_t index){
        if(index < (reverse_front_part.size())){
            return reverse_front_part[reverse_front_part.size() - 1 - index];
        } else {
            return back_part[index - reverse_front_part.size()];
        }
    }

    const T& operator[](size_t index) const {
        if(index < (reverse_front_part.size())){
            return reverse_front_part[reverse_front_part.size() - 1 - index];
        } else {
            return back_part[index - reverse_front_part.size()];
        }
    }

    const T& At(size_t index) const {
        if(index >= Size()){
            throw out_of_range("");
        }
        if(index < (reverse_front_part.size())){
            return reverse_front_part.at(reverse_front_part.size() - 1 - index);
        } else {
            return back_part.at(index - reverse_front_part.size());
        }
    }

    T& At(size_t index) {
        if(index >= Size()){
            throw out_of_range("");
        }
        if(index < (reverse_front_part.size())){
            return reverse_front_part[reverse_front_part.size() - 1 - index];
        } else {
            return back_part[index - reverse_front_part.size()];
        }
    }

    T& Front(){
        if (Empty()){
            throw out_of_range("");
        } else if (reverse_front_part.empty()){
            return back_part.front();
        } else {
            return reverse_front_part.back();
        }
    }

    const T& Front() const {
        if (Empty()){
            throw out_of_range("");
        } else if (reverse_front_part.empty()){
            return back_part.front();
        } else {
            return reverse_front_part.back();
        }
    }

    T& Back(){
        if (Empty()){
            throw out_of_range("");
        } else if (back_part.empty()){
            return reverse_front_part.front();
        } else {
            return back_part.back();
        }
    }

    const T& Back() const {
        if (Empty()){
            throw out_of_range("");
        } else if (back_part.empty()){
            return reverse_front_part.front();
        } else {
            return back_part.back();
        }
    }

    void PushFront(const T& t){
        reverse_front_part.push_back(t);
    }

    void PushBack(const T& t){
        back_part.push_back(t);
    }

private:
    vector<T> reverse_front_part;
    vector<T> back_part;
};

int main(){
    Deque<int> d;
    cout << "Check empty deque: " << d.Empty()  << " | 1" << endl;
    cout << "Size of empty deque " << d.Size() << endl;
    cout << d.Front() <<  endl;
    return 0;
}