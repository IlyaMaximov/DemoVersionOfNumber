#ifndef DEMOVERSIONOFNUMBER_GRAPH_H
#define DEMOVERSIONOFNUMBER_GRAPH_H

#include <iostream>
#include <vector>
#include <string>

#include "Chart.h"

class Graph {
    friend class Chart;
public:
    explicit Graph(sf::Vector2f, sf::Vector2f, sf::RenderWindow*);
    explicit Graph(sf::Vector2f, sf::Vector2f, const std::string&, sf::RenderWindow*);

    void addChart(SortType, OperationType, const sf::Color&);
    void delChart(SortType, OperationType, const sf::Color&);
    void addTitle(const std::string&);
    void delTitle(const std::string&);
    void addChartsDescriptions();
    void delChartsDescriptions();

    void print() const;

private:

    void draw_coordinate_axis() const;
    void draw_title() const;
    void draw_description() const;

    const sf::Vector2f upper_left_corner_;
    const sf::Vector2f lower_left_corner_;
    const sf::Vector2f upper_right_corner_;
    const sf::Vector2f lower_right_corner_;
    const size_t height_, width_;
    bool description_ = false;
    std::vector<Chart> charts_{};
    std::string title_ = "";
    sf::RenderWindow* window_ = nullptr;
    sf::Font font_;
};


#endif
