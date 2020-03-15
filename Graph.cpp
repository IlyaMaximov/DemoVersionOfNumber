#include "Graph.h"

Graph::Graph(sf::Vector2f upper_left_corner, sf::Vector2f lower_right_corner, sf::RenderWindow *window):
    upper_left_corner_(upper_left_corner),
    lower_right_corner_(lower_right_corner),
    upper_right_corner_(sf::Vector2f(lower_right_corner.x, upper_left_corner.y)),
    lower_left_corner_(sf::Vector2f(upper_left_corner.x, lower_right_corner.y)),
    height_(lower_left_corner_.y - upper_left_corner_.y),
    width_(lower_right_corner_.x - lower_left_corner_.x),
    window_(window) {

    if (!font_.loadFromFile("arial.ttf")) {
        throw std::runtime_error("");
    }
}

Graph::Graph(sf::Vector2f upp_left_cor, sf::Vector2f low_right_cor, const std::string& title, sf::RenderWindow *window):
    Graph(upp_left_cor, low_right_cor, window) {
    title_ = title;
}


void Graph::addChart(SortType sort_type, OperationType operation_type, const sf::Color& color) {
    if (std::find(charts_.begin(), charts_.end(),
            Chart(sort_type, operation_type, color, this)) == charts_.end()) {
        charts_.emplace_back(sort_type, operation_type, color, this);
    }
}

void Graph::delChart(SortType sort_type, OperationType operation_type, const sf::Color& color) {
    auto iter = std::find(charts_.begin(), charts_.end(),Chart(sort_type, operation_type, color, this));
    if (iter != charts_.end()) {
        charts_.emplace_back(sort_type, operation_type, color, this);
    }
}

void Graph::addTitle(const std::string& title) {
    title_ = title;
}

void Graph::delTitle(const std::string& title) {
    title_ = "";
}

void Graph::addChartsDescriptions() {
    description_ = true;
}

void Graph::delChartsDescriptions() {
    description_ = false;
}

void Graph::print() const {
    draw_coordinate_axis();
    draw_title();
    for (const Chart& chart: charts_) {
        chart.print();
    }
    if (description_)
        draw_description();
}

void Graph::draw_coordinate_axis() const {
    size_t line_width = 2;
    float arrow_rotate = 15.f;
    size_t arrow_lenght = 30;

    // Building a vertical axis
    sf::RectangleShape vertical_line(sf::Vector2f(height_, line_width));
    vertical_line.setFillColor(sf::Color::Black);
    vertical_line.rotate(90);
    vertical_line.setPosition(upper_left_corner_);

    sf::RectangleShape vertical_arrow1(sf::Vector2f(arrow_lenght, line_width));
    vertical_arrow1.setFillColor(sf::Color::Black);
    vertical_arrow1.setPosition(upper_left_corner_);
    sf::RectangleShape vertical_arrow2 = vertical_arrow1;
    vertical_arrow1.rotate(90.f - arrow_rotate);
    vertical_arrow2.rotate(90.f + arrow_rotate);

    window_->draw(vertical_line);
    window_->draw(vertical_arrow1);
    window_->draw(vertical_arrow2);

    // Building a horizontal axis
    sf::RectangleShape horizontal_line(sf::Vector2f(width_, line_width));
    horizontal_line.setFillColor(sf::Color::Black);
    horizontal_line.setPosition(lower_left_corner_);

    sf::RectangleShape horizontal_arrow1(sf::Vector2f(arrow_lenght, line_width));
    horizontal_arrow1.setFillColor(sf::Color::Black);
    horizontal_arrow1.setPosition(lower_right_corner_.x, lower_right_corner_.y + line_width);
    sf::RectangleShape horizontal_arrow2 = horizontal_arrow1;
    horizontal_arrow1.rotate(180.f + arrow_rotate);
    horizontal_arrow2.rotate(180.f - arrow_rotate);

    window_->draw(horizontal_line);
    window_->draw(horizontal_arrow1);
    window_->draw(horizontal_arrow2);
}

void Graph::draw_title() const {
    sf::Text text_title;
    text_title.setFont(font_);
    text_title.setString(title_);
    text_title.setFillColor(sf::Color::Black);
    text_title.setPosition(upper_left_corner_.x, upper_left_corner_.y - 50);
    window_->draw(text_title);
}

void Graph::draw_description() const {
    sf::Text text;
    text.setFont(font_);
    size_t shift = 0;
    for (const Chart& chart: charts_) {
        std::string sort_type;
        if (chart.getSortType() == SortType::Bubble_Sort) {
            sort_type = "Bubble Sort";
        } else if (chart.getSortType() == SortType::Merge_Sort) {
            sort_type = "Merge Sort";
        } else {
            sort_type = "Quick Sort";
        }

        text.setString(sort_type);
        text.setCharacterSize(30);
        text.setFillColor(chart.getColor());
        text.setPosition((upper_right_corner_.x - text.getGlobalBounds().width - 50),
                          upper_right_corner_.y + shift);
        shift += 50;
        window_->draw(text);
    }
}