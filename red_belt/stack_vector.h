#pragma once

#include <stdexcept>
#include <array>
using namespace std;

template <typename T, size_t N>
class StackVector {
public:
  explicit StackVector(size_t a_size = 0){
      if (a_size > N){
          throw invalid_argument("");
      }
      size_ = a_size;
  };

  T& operator[](size_t index){
      if(index >= size_){
          throw invalid_argument("");
      }
      return data_[index];
  };
  const T& operator[](size_t index) const{
      if(index >= size_){
          throw invalid_argument("");
      }
      return data_[index];
  };

  T* begin(){
      return data_.begin();
  };
  T* end(){
      return data_.data() + size_;
  };
  const T* begin() const{
      return data_.begin();
  };
  const T* end() const{
      return data_.data() + size_;
  };

  size_t Size() const{
      return size_;
  };
  size_t Capacity() const{
      return N;
  };

  void PushBack(const T& value){
      if(size_ == N){
          throw overflow_error("");
      }
      data_[size_++] = value;
  };
  T PopBack(){
      if(size_ == 0){
          throw underflow_error("");
      }
      --size_;
      return data_[size_];
  };

private:
    array<T, N> data_;
    size_t size_;
};

