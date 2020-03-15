#include <iostream>
#include <SFML/Graphics.hpp>

#include "Graph.h"

struct MyConst{
    static const size_t width_guard_space;
    static const size_t height_guard_space;
    static const size_t desktop_width;
    static const size_t desktop_height;
};

const size_t MyConst::width_guard_space = 50;
const size_t MyConst::height_guard_space = 50;
const size_t MyConst::desktop_width = sf::VideoMode::getDesktopMode().width;
const size_t MyConst::desktop_height = sf::VideoMode::getDesktopMode().height;

int main() {
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::RenderWindow window(sf::VideoMode::getDesktopMode(),
                       "Plotting the effectiveness of standard sorts",
                       sf::Style::Default, settings);

    while (window.isOpen())
    {
        sf::Event event{};
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear(sf::Color::White);

        size_t graph_w = (MyConst::desktop_width - 4 * MyConst::width_guard_space) / 2;
        size_t graph_h = MyConst::desktop_height - 3 * MyConst::height_guard_space;

        Graph compare_graph(sf::Vector2f(MyConst::width_guard_space, MyConst::height_guard_space),
            sf::Vector2f(MyConst::width_guard_space + graph_w, MyConst::height_guard_space + graph_h),
            &window);
        compare_graph.addChart(SortType::Bubble_Sort, OperationType::Compare, sf::Color::Red);
        compare_graph.addChart(SortType::Merge_Sort, OperationType::Compare, sf::Color::Blue);
        compare_graph.addChart(SortType::Quick_Sort, OperationType::Compare, sf::Color::Green);
        compare_graph.addTitle("Comparison operations");
        compare_graph.addChartsDescriptions();

        compare_graph.print();

        Graph assignment_graph(sf::Vector2f(MyConst::width_guard_space * 2 + graph_w, MyConst::height_guard_space),
                sf::Vector2f(MyConst::width_guard_space * 2 + graph_w * 2, MyConst::height_guard_space + graph_h),
                &window);
        assignment_graph.addChart(SortType::Bubble_Sort, OperationType::Assignment, sf::Color::Red);
        assignment_graph.addChart(SortType::Merge_Sort, OperationType::Assignment, sf::Color::Blue);
        assignment_graph.addChart(SortType::Quick_Sort, OperationType::Assignment, sf::Color::Green);
        assignment_graph.addTitle("Assignment operations");
        assignment_graph.addChartsDescriptions();

        assignment_graph.print();

        window.display();
    }

    return 0;
}