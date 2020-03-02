#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <tuple>
#include <cmath>
#include <SFML/Graphics.hpp>

#include "DemoVersionOfNumber.h"
#include "Sorts.h"

std::random_device rd;
int RAND_CONSTANT = rd();

enum class SortType {
    Bubble_Sort,
    Merge_Sort,
    Quick_Sort
};

struct SortConditions {
    SortType sort_type;
    size_t number_elements;
};

size_t get_sort_statistic(SortConditions info) {
    std::mt19937 mt(RAND_CONSTANT);
    std::uniform_int_distribution<> gen(INT32_MIN, INT32_MAX);

    size_t ARRAY_SIZE = info.number_elements;
    std::vector<DemoVersionOfNumber<int>> mass;
    mass.reserve(ARRAY_SIZE);
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        mass.emplace_back(gen(mt));
    }

    if (info.sort_type == SortType::Bubble_Sort) {
        BubbleSort(mass.begin(), mass.end());
    } else if (info.sort_type == SortType::Merge_Sort) {
        MergeSort(mass.begin(), mass.end());
    } else {
        std::sort(mass.begin(), mass.end());
    }

    size_t number_conditions = 0;
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        number_conditions += mass[i].getComparisonOperation();
    }
    return std::sqrt(number_conditions);
}

void draw_coordinate_axis(sf::RenderWindow& window) {
    float line_width = 2;
    float arrow_rot = 20.f;

    sf::RectangleShape vertical_line(sf::Vector2f(750.f, line_width));
    vertical_line.setFillColor(sf::Color::Black);
    vertical_line.rotate(90.f);
    vertical_line.setPosition(50, 25);

    sf::RectangleShape vertical_arrow1(sf::Vector2f(25.f, line_width));
    vertical_arrow1.setFillColor(sf::Color::Black);
    vertical_arrow1.setPosition(50, 25);
    sf::RectangleShape vertical_arrow2 = vertical_arrow1;
    vertical_arrow1.rotate(90.f - arrow_rot);
    vertical_arrow2.rotate(90.f + arrow_rot);


    sf::RectangleShape horizontal_line(sf::Vector2f(1350.f, line_width));
    horizontal_line.setFillColor(sf::Color::Black);
    horizontal_line.setPosition(25, 750);

    sf::RectangleShape horizontal_arrow1(sf::Vector2f(30.f, line_width));
    horizontal_arrow1.setFillColor(sf::Color::Black);
    horizontal_arrow1.setPosition(1375, 750 + line_width);
    sf::RectangleShape horizontal_arrow2 = horizontal_arrow1;
    horizontal_arrow1.rotate(180.f + arrow_rot);
    horizontal_arrow2.rotate(180.f - arrow_rot);


    window.draw(vertical_line);
    window.draw(vertical_arrow1);
    window.draw(vertical_arrow2);

    window.draw(horizontal_line);
    window.draw(horizontal_arrow1);
    window.draw(horizontal_arrow2);
}

void draw_sort_graph(SortType sort_type, sf::Color color_graph, sf::RenderWindow& window) {
    size_t MAX_ELEMENTS = 1300;
    size_t STEP = 1;
    if (sort_type == SortType::Bubble_Sort) {
        MAX_ELEMENTS = 380;
    }

    sf::Vertex vertices[2];
    vertices[0] = sf::Vertex(sf::Vector2f(50, 750), color_graph);
    size_t elements_tmp = 0;
    while (elements_tmp != MAX_ELEMENTS) {
        elements_tmp += 1;
        float num_oper = get_sort_statistic({sort_type, elements_tmp});
        vertices[1] = sf::Vertex(sf::Vector2f(50 + elements_tmp, 750 - num_oper), color_graph);
        window.draw(vertices, 2, sf::Lines);
        vertices[0] = vertices[1];
    }
}

void draw_explanatory_text(sf::RenderWindow& window) {
    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        throw std::runtime_error("");
    }

    sf::Text text;
    text.setFont(font);
    text.setString("Bubble Sort");
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::Red);
    text.setPosition(440, 50);
    window.draw(text);

    text.setString("Merge Sort");
    text.setFillColor(sf::Color::Blue);
    text.setPosition(1230, 610);
    window.draw(text);

    text.setString("Quick Sort");
    text.setFillColor(sf::Color::Green);
    text.setPosition(1230, 550);
    window.draw(text);


    text.setString("Graph of function of the form");
    text.setFillColor(sf::Color::Black);
    text.setPosition(450, 300);
    window.draw(text);

    text.setString("SQRT(NUMBER_OF_COMPARISONS)");
    text.setPosition(450, 330);
    window.draw(text);
}

void draw_picture(sf::RenderWindow& window) {
    sf::Texture texture;
    texture.loadFromFile("picture.jpg");
    sf::Sprite picture(texture);
    picture.scale(0.5f, 0.5f);
    picture.setPosition(900, 0);

    window.draw(picture);
}


int main() {

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::RenderWindow window(sf::VideoMode(1400, 800),
            "Plotting the effectiveness of standard sorts", sf::Style::Default, settings);

    while (window.isOpen())
    {
        sf::Event event{};
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear(sf::Color(245, 245, 245, 0));

        draw_coordinate_axis(window);
        draw_sort_graph(SortType::Bubble_Sort, sf::Color::Red, window);
        draw_sort_graph(SortType::Merge_Sort, sf::Color::Blue, window);
        draw_sort_graph(SortType::Quick_Sort, sf::Color::Green, window);
        draw_explanatory_text(window);
        draw_picture(window);

        window.display();
    }
    return 0;
}