#ifndef DEMOVERSIONOFNUMBER_SORTS_H
#define DEMOVERSIONOFNUMBER_SORTS_H

template <class T>
void Swap(T& lhs, T& rhs) {
    T tmp = lhs;
    lhs = rhs;
    rhs = tmp;
}

template <typename RandomIt>
void BubbleSort(RandomIt range_begin, RandomIt range_end) {
    size_t range_length = range_end - range_begin;
    if (range_length < 2) {
         return;
    }

    for (size_t i = 0; i < range_length; ++i) {
        bool sort_is_correct = true;
        for (auto it = range_begin; it < range_end - 1; ++it) {
            if (*it > *(it + 1)) {
                Swap(*it, *(it + 1));
                sort_is_correct = false;
            }
        }
        if (sort_is_correct) {
            return;
        }
    }
}

template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end) {
    size_t range_length = range_end - range_begin;
    if (range_length < 2) {
        return;
    }

    RandomIt mid = range_begin + range_length / 2;
    MergeSort(range_begin, mid);
    MergeSort(mid, range_end);
    std::vector<typename RandomIt::value_type> arr_tmp;
    merge(range_begin, mid, mid, range_end, back_inserter(arr_tmp));
    std::copy(arr_tmp.begin(), arr_tmp.end(), range_begin);
}
#endif //DEMOVERSIONOFNUMBER_SORTS_H