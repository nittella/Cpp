#include "print_vector_part.h"

void PrintVectorPart(const vector<int>& numbers){
  auto first_negative = find_if(
          begin(numbers), end(numbers),
          [](int number){return number < 0;}
          );
  PrintReverseRange(begin(numbers), first_negative);
};

void PrintReverseRange(vector<int>::const_iterator it_begin, const vector<int>::const_iterator it_end){
  auto it = it_end;
  while (it > it_begin){
    it--;
    cout << *it << " ";
  }
};