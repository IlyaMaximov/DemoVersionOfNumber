#ifndef DEMOVERSIONOFNUMBER_DEMOVERSIONOFNUMBER_H
#define DEMOVERSIONOFNUMBER_DEMOVERSIONOFNUMBER_H

#include <iostream>

template <typename T>
class DemoVersionOfNumber;

template <typename T>
std::istream& operator>> (std::istream &in, DemoVersionOfNumber<T> &num) {
    in >> num.value_;
    return in;
}
template <typename T>
std::ostream& operator<<(std::ostream &out, const DemoVersionOfNumber<T> &num) {
    out << num.value_;
    return out;
}

template <typename T>
bool operator==(DemoVersionOfNumber<T> &lhs, DemoVersionOfNumber<T> &rhs) {
    ++lhs.comparison_operation_num_;
    ++rhs.comparison_operation_num_;
    return lhs.value_ == rhs.value_;
}
template <typename T>
bool operator<(DemoVersionOfNumber<T> &lhs, DemoVersionOfNumber<T> &rhs) {
    ++lhs.comparison_operation_num_;
    ++rhs.comparison_operation_num_;
    return lhs.value_ < rhs.value_;
}
template <typename T>
bool operator>(DemoVersionOfNumber<T> &lhs, DemoVersionOfNumber<T> &rhs) {
    ++lhs.comparison_operation_num_;
    ++rhs.comparison_operation_num_;
    return rhs < lhs;
}
template <typename T>
bool operator<=(DemoVersionOfNumber<T> &lhs, DemoVersionOfNumber<T> &rhs) {
    ++lhs.comparison_operation_num_;
    ++rhs.comparison_operation_num_;
    return lhs < rhs || lhs == rhs;
}
template <typename T>
bool operator>=(DemoVersionOfNumber<T> &lhs, DemoVersionOfNumber<T> &rhs) {
    ++lhs.comparison_operation_num_;
    ++rhs.comparison_operation_num_;
    return rhs <= lhs;
}

template<typename T>
DemoVersionOfNumber<T> operator+(const DemoVersionOfNumber<T> &lhs, const DemoVersionOfNumber<T> &rhs) {
    return DemoVersionOfNumber<T>(lhs.value_ + rhs.value_);
}
template<typename T>
DemoVersionOfNumber<T> operator-(const DemoVersionOfNumber<T> &lhs, const DemoVersionOfNumber<T> &rhs) {
    return DemoVersionOfNumber<T>(lhs.value_ - rhs.value_);
}
template<typename T>
DemoVersionOfNumber<T> operator*(const DemoVersionOfNumber<T> &lhs, const DemoVersionOfNumber<T> &rhs) {
    return DemoVersionOfNumber<T>(lhs.value_ * rhs.value_);
}
template<typename T>
DemoVersionOfNumber<T> operator/(const DemoVersionOfNumber<T> &lhs, const DemoVersionOfNumber<T> &rhs) {
    return DemoVersionOfNumber<T>(lhs.value_ / rhs.value_);
}
template<typename T>
DemoVersionOfNumber<T> operator%(const DemoVersionOfNumber<T> &lhs, const DemoVersionOfNumber<T> &rhs) {
    return DemoVersionOfNumber<T>(lhs.value_ % rhs.value_);
}


template <typename T>
class DemoVersionOfNumber {
public:
    explicit DemoVersionOfNumber(T value = 0): value_(value) {
        if (std::is_same<T, float>::value || std::is_same<T, const float>::value ||
            std::is_same<T, double>::value || std::is_same<T, const double>::value ||
            std::is_same<T, long double>::value || std::is_same<T, const long double>::value) {
            throw std::invalid_argument("Type must be an integer");
        }
    }
    ~DemoVersionOfNumber() = default;
    DemoVersionOfNumber(const DemoVersionOfNumber&) = default;
    DemoVersionOfNumber& operator=(const DemoVersionOfNumber&);

    friend std::istream& operator>> <T>(std::istream&, DemoVersionOfNumber&);
    friend std::ostream& operator<< <T>(std::ostream&, const DemoVersionOfNumber&);

    // unary arithmetic operations
    DemoVersionOfNumber<T>& operator++();
    DemoVersionOfNumber<T>& operator--();
    DemoVersionOfNumber<T> operator++(int);
    DemoVersionOfNumber<T> operator--(int);

    //binary comparison operations
    friend bool operator== <T>(DemoVersionOfNumber&, DemoVersionOfNumber&);
    friend bool operator< <T>(DemoVersionOfNumber&, DemoVersionOfNumber&);
    friend bool operator> <T>(DemoVersionOfNumber&, DemoVersionOfNumber&);
    friend bool operator<= <T>(DemoVersionOfNumber&, DemoVersionOfNumber&);
    friend bool operator>= <T>(DemoVersionOfNumber&, DemoVersionOfNumber&);

    //binary arithmetic operations
    friend DemoVersionOfNumber operator+ <T>(const DemoVersionOfNumber&, const DemoVersionOfNumber&);
    friend DemoVersionOfNumber operator- <T>(const DemoVersionOfNumber&, const DemoVersionOfNumber&);
    friend DemoVersionOfNumber operator* <T>(const DemoVersionOfNumber&, const DemoVersionOfNumber&);
    friend DemoVersionOfNumber operator/ <T>(const DemoVersionOfNumber&, const DemoVersionOfNumber&);
    friend DemoVersionOfNumber operator% <T>(const DemoVersionOfNumber&, const DemoVersionOfNumber&);

    DemoVersionOfNumber<T>& operator+=(const DemoVersionOfNumber<T>&);
    DemoVersionOfNumber<T>& operator-=(const DemoVersionOfNumber<T>&);
    DemoVersionOfNumber<T>& operator*=(const DemoVersionOfNumber<T>&);
    DemoVersionOfNumber<T>& operator/=(const DemoVersionOfNumber<T>&);
    DemoVersionOfNumber<T>& operator%=(const DemoVersionOfNumber<T>&);

    [[nodiscard]] T getValue() const {
        return value_;
    }

    [[nodiscard]] size_t getCompOperationCnt() const {
        return comparison_operation_num_;
    }

    [[nodiscard]] size_t getAssignmentOperationCnt() const {
        return assignment_num_;
    }

private:
    T value_;
    size_t comparison_operation_num_ = 0;
    size_t assignment_num_ = 0;
};

template<typename T>
DemoVersionOfNumber<T> &DemoVersionOfNumber<T>::operator=(const DemoVersionOfNumber<T> &new_num) {
    if (this != &new_num) {
        value_ = new_num.value_;
        ++assignment_num_;
    }
    return (*this);
}

template <typename T>
DemoVersionOfNumber<T> &DemoVersionOfNumber<T>::operator++() {
    ++value_;
    return *this;
}
template <typename T>
DemoVersionOfNumber<T> &DemoVersionOfNumber<T>::operator--() {
    --value_;
    return *this;
}

template <typename T>
DemoVersionOfNumber<T> DemoVersionOfNumber<T>::operator++(int) {
    DemoVersionOfNumber<T> value_tmp(*this);
    ++(*this);
    return value_tmp;
}
template <typename T>
DemoVersionOfNumber<T> DemoVersionOfNumber<T>::operator--(int) {
    DemoVersionOfNumber<T> value_tmp(*this);
    --(*this);
    return value_tmp;
}

template<typename T>
DemoVersionOfNumber<T> &DemoVersionOfNumber<T>::operator+=(const DemoVersionOfNumber<T> &num) {
    value_ += num.value_;
    return (*this);
}
template<typename T>
DemoVersionOfNumber<T> &DemoVersionOfNumber<T>::operator-=(const DemoVersionOfNumber<T> &num) {
    value_ -= num.value_;
    return (*this);
}
template<typename T>
DemoVersionOfNumber<T> &DemoVersionOfNumber<T>::operator*=(const DemoVersionOfNumber<T> &num) {
    value_ *= num.value_;
    return (*this);
}
template<typename T>
DemoVersionOfNumber<T> &DemoVersionOfNumber<T>::operator/=(const DemoVersionOfNumber<T> &num) {
    value_ /= num.value_;
    return (*this);
}
template<typename T>
DemoVersionOfNumber<T> &DemoVersionOfNumber<T>::operator%=(const DemoVersionOfNumber<T> &num) {
    value_ %= num.value_;
    return (*this);
}


#endif //DEMOVERSIONOFNUMBER_DEMOVERSIONOFNUMBER_H
