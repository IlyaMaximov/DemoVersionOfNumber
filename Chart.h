#ifndef DEMOVERSIONOFNUMBER_CHART_H
#define DEMOVERSIONOFNUMBER_CHART_H

#include <random>
#include <SFML/Graphics.hpp>
#include "DemoVersionOfNumber.h"
#include "Sorts.h"

class Graph;

enum class SortType {
    Bubble_Sort,
    Merge_Sort,
    Quick_Sort
};

enum class OperationType {
    Compare,
    Assignment
};

class Chart {
public:

    explicit Chart(SortType, OperationType, const sf::Color&, Graph* );
    [[nodiscard]] SortType getSortType() const;
    [[nodiscard]] OperationType  getOperationType() const;
    [[nodiscard]] sf::Color getColor() const;

    void print() const;

private:

    [[nodiscard]] size_t get_sort_statistic(size_t element_num) const;

    SortType sort_type_;
    OperationType operation_type_;
    sf::Color color_;
    Graph* graph_ptr_ = nullptr;
    static const int RAND_CONSTANT;
};

bool operator==(const Chart& lhs, const Chart& rhs);
bool operator!=(const Chart& lhs, const Chart& rhs);


#endif //DEMOVERSIONOFNUMBER_CHART_H
