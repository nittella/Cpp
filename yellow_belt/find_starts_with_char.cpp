#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

template <typename RandomIt>
RandomIt FindPrefix(RandomIt range_begin, RandomIt range_end, char prefix){
    auto half = range_begin + (range_end - range_begin) / 2;
    if ((*half)[0] == prefix ){
        return half;
    } else if ((*half)[0] > prefix){
        return FindPrefix(range_begin, half, prefix);
    } else {
        return FindPrefix(half, range_end, prefix);
    }
};

template <typename RandomIt>
RandomIt FindLowerBound(RandomIt it, char prefix){
    if ((*prev(it))[0] == prefix){
        return FindLowerBound(prev(it), prefix);
    } else {
        return it;
    }
};

template <typename RandomIt>
RandomIt FindUpperBound(RandomIt it, char prefix){
    if ((*next(it))[0] == prefix){
        return FindUpperBound(next(it), prefix);
    } else {
        return next(it);
    }
};
template <typename T>
bool compare(const T& a, const T& b){
    return a[0] > b[0];
}

template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith( RandomIt range_begin, RandomIt range_end, char prefix){
//    if (range_end - range_begin == 0){
//        return make_pair(range_begin, range_end);
//    }
//    RandomIt it = FindPrefix(range_begin, range_end, prefix);
    return equal_range(range_begin, range_end, string(1, prefix),
            [](const auto& a, const auto& b){
//        cout << a << " " << b << endl;
        return a[0] < b[0];});
};

  int main() {
    const vector<string> sorted_strings = {"moscow", "murmansk", "vologda"};

    const auto m_result =
            FindStartsWith(begin(sorted_strings), end(sorted_strings), 'm');
    for (auto it = m_result.first; it != m_result.second; ++it) {
      cout << *it << " ";
    }
    cout << endl;

    const auto p_result =
            FindStartsWith(begin(sorted_strings), end(sorted_strings), 'p');
    cout << (p_result.first - begin(sorted_strings)) << " " <<
         (p_result.second - begin(sorted_strings)) << endl;

    const auto z_result =
            FindStartsWith(begin(sorted_strings), end(sorted_strings), 'z');
    cout << (z_result.first - begin(sorted_strings)) << " " <<
         (z_result.second - begin(sorted_strings)) << endl;

    return 0;
  }
