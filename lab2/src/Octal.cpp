#include "Octal.hpp"

Octal::Octal(const size_t & n, unsigned char t) {
    this->data = std::vector<u_char>(n, t);
};

Octal::Octal(const std::initializer_list<unsigned char> &t) : data{t} {
    u_char swap;
    size_t s = this->data.size();
    for (size_t i{0}; i < s / 2; ++i) {
        swap = this->data[i];
        this->data[i] = this->data[s - 1 - i];
        this->data[s - 1 - i] = swap;
    }
};

Octal::Octal(const std::string &t) {
    this->data = std::vector<u_char>(t.size(), 0);
    for (size_t i{0}; i < t.size(); ++i) {
        this->data[i] = t[t.size() - 1 - i] - 48;
    }
};

Octal::Octal(const Octal& other) : data{other.data} {};

// Octal(Octal&& other) noexcept;
Octal Octal::operator+(Octal const& obj) {

    Octal result(std::max(this->data.size(), obj.data.size()), 0);
    size_t i = 0;
    std::vector<u_char> new_data;
    int tmp = 0;

    for (; i < std::min(this->data.size(), obj.data.size()); ++i) {
        result.data[i] = ((this->data[i] + obj.data[i] + tmp) % 8);
        tmp = (this->data[i] + obj.data[i] + tmp) / 8;
    }

    for (; i < this->data.size(); ++i)
        result.data[i] = this->data[i];
    for (; i < obj.data.size(); ++i)
        result.data[i] = obj.data[i];

    return result;
}

Octal Octal::operator-(Octal const& obj) {
    Octal result(std::max(this->data.size(), obj.data.size()),0);
    size_t i = 0;
    int tmp = 0;
    for (; i < obj.data.size(); ++i) {
        if (this->data[i] < obj.data[i] + tmp) {
            result.data[i] = this->data[i] - obj.data[i] + 8;
            tmp = 1;
        } else {
            result.data[i] = this->data[i] - obj.data[i] - 1;
            tmp = 0;
        }

    }

    if (result.data[this->data.size() - 1] == 0)
        result.data.erase(result.data.begin() + this->data.size() - 1);

    return result;
}

void Octal::operator=(Octal const& obj) {
    this->data = obj.data;
}
bool Octal::operator>(Octal const& obj) {
    if (this->data.size() == obj.data.size()) {
        int i = this->data.size() - 1;
        while (this->data[i] == obj.data[i]) {
            --i;
        }
        if (i < 0) return 0;
        else return (this->data[i] > obj.data[i]);

    }
    else return this->data.size() > obj.data.size();
}
bool Octal::operator<(Octal const& obj) {
    if (this->data.size() == obj.data.size()) {
        int i = this->data.size() - 1;
        while (this->data[i] == obj.data[i]) {
            --i;
        }
        if (i < 0) return 0;
        else return (this->data[i] < obj.data[i]);

    }
    else return this->data.size() < obj.data.size();
}
bool Octal::operator==(Octal const& obj) {
    if (this->data.size() != obj.data.size()) return 0;
    else {
        int i = this->data.size() - 1;
        while (this->data[i] == obj.data[i] and i >= 0) {
            --i;
        }
        return (i < 0);
    }
}
      
std::ostream& operator<<(std::ostream& os, const Octal& obj) {
    for (size_t i{0}; i < obj.data.size(); ++i)
        os << int(obj.data[i]) << std::endl;
    return os;
}