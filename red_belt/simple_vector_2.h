#include <cstdint>
#include <stdexcept>

using namespace std;

// Реализуйте SimpleVector в этом файле
// и отправьте его на проверку

template <typename T>
class SimpleVector {
public:
  SimpleVector();
  explicit SimpleVector(size_t size);
  ~SimpleVector();

  T& operator[](size_t index);
  const T& operator[](size_t index) const;

  void operator=(const SimpleVector& other);

  T* begin();
  T* end();

  const T* begin() const;
  const T* end() const;

  size_t Size() const;
  size_t Capacity() const;
  void Move();
  void PushBack(T value);
//  void PushBack(T&& value);

  // При необходимости перегрузите
  // существующие публичные методы

private:
    T* data_;
    size_t size_;
    size_t capacity_;
};

template <typename T>
SimpleVector<T>::SimpleVector()
    : data_(nullptr),
            size_(0),
            capacity_(0){}

template <typename T>
SimpleVector<T>::SimpleVector(size_t size){
    if(size != 0){
        data_ = new T[size];
        size_ = size;
        capacity_ = size;

    } else{
        data_ = nullptr;
        size_ = size;
        capacity_ = 0;
    }
}

template <typename T>
SimpleVector<T>::~SimpleVector(){
    delete [] data_;
};

template <typename T>
T& SimpleVector<T>::operator[](size_t index){
    if(index >= size_){
        throw invalid_argument("");
    }
    return data_[index];
};

template <typename T>
const T& SimpleVector<T>::operator[](size_t index) const {
    if(index >= size_){
        throw invalid_argument("");
    }
    return data_[index];
};

template <typename T>
void SimpleVector<T>::operator=(const SimpleVector& other){
    delete [] data_;
    data_ = new T [other.Capacity()];
    capacity_ = other.Capacity();
    size_ = other.Size();
    for (int i = 0; i < other.Size(); ++i){
        data_[i] = other[i];
    };
}

template <typename T>
T* SimpleVector<T>::begin(){
    return data_;
};

template <typename T>
T* SimpleVector<T>::end(){
    return data_ + size_;
};

template <typename T>
const T* SimpleVector<T>::begin() const {
    return data_;
};

template <typename T>
const T* SimpleVector<T>::end() const{
    return data_ + size_;
}

template <typename T>
void SimpleVector<T>::Move(){
    T* tmp_data = new T [Size()];
    move(data_, data_+ size_, tmp_data);
    size_t new_capacity = 2 * capacity_;
    size_t old_size = size_;
    delete [] data_;
    data_ = new T [new_capacity];
    size_ = old_size;
    capacity_ = new_capacity;
    move(tmp_data, tmp_data + size_, data_);
    delete [] tmp_data;

}

template <typename T>
size_t SimpleVector<T>::Size() const{
    return size_;
};

template <typename T>
size_t SimpleVector<T>::Capacity() const{
    return capacity_;
};

template <typename T>
void SimpleVector<T>::PushBack(T value) {
    if (capacity_ == 0) {
        data_ = new T[1];
        *data_ = move(value);
        size_ = 1;
        capacity_ = 1;
    } else {
        if (Size() == Capacity()) {
            Move();
        }
        data_[Size()] = move(value);
        ++size_;
    }
};

//template <typename T>
//void SimpleVector<T>::PushBack(T&& value) {
//    if (capacity_ == 0) {
//        data_ = new T[1];
//        *data_ = move(value);
//        size_ = 1;
//        capacity_ = 1;
//    } else {
//        if (Size() == Capacity()) {
//            Move();
//        }
//        data_[Size()] = move(value);
//        ++size_;
//    }
//};
