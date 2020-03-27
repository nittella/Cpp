#include "test_runner.h"
#include <algorithm>
#include <memory>
#include <vector>
#include <iterator>

using namespace std;

template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end) {
    if(range_end - range_begin >= 2){
        size_t range_size = range_end - range_begin;
        vector<typename RandomIt::value_type> data;
        data.reserve(range_size);
        move(range_begin, range_end, back_inserter(data));
        RandomIt first_third_end = data.begin() + range_size / 3;
        RandomIt second_third_end = first_third_end + range_size / 3;
        MergeSort(
                data.begin(),
                first_third_end
                );
        MergeSort(
                first_third_end,
                second_third_end
                );
        MergeSort(
                second_third_end,
                data.end()
                );
        vector<typename RandomIt::value_type> tmp;
        tmp.reserve(range_size * 2 / 3);
        merge(
                make_move_iterator(data.begin()),
                make_move_iterator(first_third_end),
                make_move_iterator(first_third_end),
                make_move_iterator(second_third_end),
                back_inserter(tmp)
                );
        merge(
                make_move_iterator(tmp.begin()),
                make_move_iterator(tmp.end()),
                make_move_iterator(second_third_end),
                make_move_iterator(data.end()),
                range_begin
                );
    }
}

class NonCopyableString : public string {
public:
    using string::string;
    NonCopyableString(string&& other) : string(move(other)) {}
    NonCopyableString(const NonCopyableString&) = delete;
    NonCopyableString(NonCopyableString&&) = default;
    NonCopyableString& operator=(const NonCopyableString&) = delete;
    NonCopyableString& operator=(NonCopyableString&&) = default;
};


void TestIntVector() {
  vector<int> numbers = {6, 1, 3, 9, 1, 9, 8, 12, 1};
  MergeSort(begin(numbers), end(numbers));
  ASSERT(is_sorted(begin(numbers), end(numbers)));
}

void TestNonCopyableString(){
    vector<NonCopyableString> strings;
    strings.reserve(10);
    for (int i = 0; i < 9; i++){
        strings.push_back(NonCopyableString(to_string(9-i)));
    }
    MergeSort(begin(strings), end(strings));
    ASSERT(is_sorted(begin(strings), end(strings)));
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestIntVector);
  RUN_TEST(tr, TestNonCopyableString);
  return 0;
}
