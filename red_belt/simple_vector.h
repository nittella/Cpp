#pragma once

#include <cstdlib>
#include <stdexcept>

using namespace std;

// Реализуйте шаблон SimpleVector
template <typename T>
class SimpleVector {
public:
  SimpleVector()
  : data_(nullptr),
  size_(0),
  capacity_(0)
  {};
  explicit SimpleVector(size_t size) {
      if(size != 0){
          data_ = new T[size];
          size_ = size;
          capacity_ = size;

      } else{
          data_ = nullptr;
          size_ = size;
          capacity_ = 0;
      }
};
  ~SimpleVector(){
      delete [] data_;
  };

  T& operator[](size_t index){
      if(index >= size_){
          throw invalid_argument("");
      }
      return data_[index];
  };

  const T& operator[](size_t index) const {
      if(index >= size_){
          throw invalid_argument("");
      }
      return data_[index];
  };

  void operator=(const SimpleVector& other){
      delete [] data_;
      data_ = new T [other.Capacity()];
      capacity_ = other.Capacity();
      size_ = other.Size();
      for (int i = 0; i < other.Size(); ++i){
          data_[i] = other[i];
      };
  }

  T* begin(){
      return data_;
  };
  T* end(){
      return data_ + size_;
  };
  const T* begin() const {
      return data_;
  };
  const T* end() const{
      return data_ + size_;
  }

  void Move(){
      T* tmp_data = new T [Size()];
      for (int i = 0; i < Size(); i++){
          *(tmp_data + i) = *(data_ + i);
      }
      size_t new_capacity = 2 * capacity_;
      size_t old_size = size_;
      delete [] data_;
      data_ = new T [new_capacity];
      size_ = old_size;
      capacity_ = new_capacity;
      for (int i = 0; i < old_size; i++){
          *(data_ + i) = *(tmp_data + i);
      }
      delete [] tmp_data;

  }


  size_t Size() const{
      return size_;
  };
  size_t Capacity() const{
      return capacity_;
  };
  void PushBack(const T& value) {
      if (capacity_ == 0) {
          data_ = new T[1];
          *data_ = value;
          size_ = 1;
          capacity_ = 1;
      } else {
          if (Size() == Capacity()) {
              Move();
          }
          data_[Size()] = value;
          ++size_;
      }

  };

private:
    T* data_;
    size_t size_;
    size_t capacity_;
};
