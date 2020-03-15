#include "Chart.h"
#include "Graph.h"

std::random_device rd;
const int Chart::RAND_CONSTANT = rd();

Chart::Chart(SortType sort_type, OperationType operation, const sf::Color& color, Graph *graph_ptr) :
        sort_type_(sort_type),
        operation_type_(operation),
        color_(color),
        graph_ptr_(graph_ptr) {}

SortType Chart::getSortType() const {
    return sort_type_;
}

OperationType Chart::getOperationType() const {
    return operation_type_;
}

sf::Color Chart::getColor() const {
    return color_;
}

size_t Chart::get_sort_statistic(size_t number_elements) const {
    std::mt19937 mt(RAND_CONSTANT);
    std::uniform_int_distribution<> gen(INT32_MIN, INT32_MAX);

    size_t ARRAY_SIZE = number_elements;
    std::vector<DemoVersionOfNumber<int>> mass;
    mass.reserve(ARRAY_SIZE);
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        mass.emplace_back(gen(mt));
    }

    if (getSortType() == SortType::Bubble_Sort) {
        BubbleSort(mass.begin(), mass.end());
    } else if (getSortType() == SortType::Merge_Sort) {
        MergeSort(mass.begin(), mass.end());
    } else {
        QuickSort(mass.begin(), mass.end());
    }

    size_t number_operations = 0;
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        if (getOperationType() == OperationType::Compare) {
            number_operations += mass[i].getCompOperationCnt();
        } else {
            number_operations += mass[i].getAssignmentOperationCnt();
        }
    }
    return number_operations;
}

void Chart::print() const {
    sf::Vertex vertices[2];
    vertices[0] = sf::Vertex(graph_ptr_->lower_left_corner_, color_);
    vertices[1] = sf::Vertex(graph_ptr_->lower_left_corner_, color_);
    size_t elements_tmp = 1, operation_cnt = get_sort_statistic(1);
    while (elements_tmp <= graph_ptr_->width_ && vertices[1].position.y != graph_ptr_->upper_left_corner_.y) {
        vertices[1].position.x += 2;
        vertices[1].position.y = std::max(graph_ptr_->lower_left_corner_.y - operation_cnt,
                                          graph_ptr_->upper_left_corner_.y);
        graph_ptr_->window_->draw(vertices, 2, sf::Lines);
        vertices[0] = vertices[1];
        elements_tmp += 1;
        operation_cnt = get_sort_statistic(elements_tmp);
    }
}

bool operator==(const Chart& lhs, const Chart& rhs) {
    return lhs.getOperationType() == rhs.getOperationType() && lhs.getSortType() == rhs.getSortType();
}

bool operator!=(const Chart& lhs, const Chart& rhs) {
    return !(lhs == rhs);
}
