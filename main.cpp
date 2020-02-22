#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

#include "DemoVersionOfNumber.h"
#include "Sorts.h"

int main() {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<> gen(INT32_MIN, INT32_MAX);

    //Test1
    {
        std::cout << "TEST 1 \n-----------------------------\n";
        const int ARRAY_SIZE = 20;

        std::vector<DemoVersionOfNumber<int>> quick_mass, merge_mass, bubble_mass;
        for (int i = 0; i < ARRAY_SIZE; ++i) {
            int value = gen(mt);
            bubble_mass.emplace_back(value);
            merge_mass.emplace_back(value);
            quick_mass.emplace_back(value);
        }

        BubbleSort(bubble_mass.begin(), bubble_mass.end());
        MergeSort(merge_mass.begin(), merge_mass.end());
        std::sort(quick_mass.begin(), quick_mass.end());

        for (auto &elem: bubble_mass) {
            std::cout << elem.getComparisonOperation() << " ";
        }
        std::cout << '\n';

        for (auto &elem: merge_mass) {
            std::cout << elem.getComparisonOperation() << " ";
        }
        std::cout << '\n';

        for (auto &elem: quick_mass) {
            std::cout << elem.getComparisonOperation() << " ";
        }
        std::cout << "\n\n";
    }

    //Test2
    {
        std::cout << "TEST 2 \n-----------------------------\n";
        std::cout << "Sorting an array of size 10000\n";
        const int ARRAY_SIZE = 10000;

        std::vector<DemoVersionOfNumber<int>> quick_mass, merge_mass, bubble_mass;
        for (int i = 0; i < ARRAY_SIZE; ++i) {
            int value = gen(mt);
            bubble_mass.emplace_back(value);
            merge_mass.emplace_back(value);
            quick_mass.emplace_back(value);
        }

        BubbleSort(bubble_mass.begin(), bubble_mass.end());
        MergeSort(merge_mass.begin(), merge_mass.end());
        std::sort(quick_mass.begin(), quick_mass.end());

        long long bubble_cnt = 0, merge_cnt = 0, quick_cnt = 0;
        for (int i = 0; i < ARRAY_SIZE; ++i) {
            bubble_cnt += bubble_mass[i].getComparisonOperation();
            merge_cnt += merge_mass[i].getComparisonOperation();
            quick_cnt += quick_mass[i].getComparisonOperation();
        }
        std::cout << "Total number of comparisons in Bubble Sort: " << bubble_cnt << '\n';
        std::cout << "Total number of comparisons in Merge Sort : " << merge_cnt << '\n';
        std::cout << "Total number of comparisons in Quick Sort : " << quick_cnt << '\n';
    }
    return 0;
}
