#include "Octal.hpp"

Octal::Octal() : size{0}, data{nullptr} {}

Octal::Octal(const size_t & n, unsigned char t) : size{n} {
    if (!('0' <= t <= '7')) {
        throw std::invalid_argument("not 8th system");
    }
    this->data = new u_char[n];
    for (size_t i = 0; i < n; ++i) {
        this->data[i] = t - '0';
    }
};

Octal::Octal(const std::initializer_list<unsigned char> &t) {
    this->size = t.size();
    this->data = new u_char[this->size];
    size_t i = this->size - 1;
    for (auto c : t) {
        if (!('0' <= c <= '7')) {
            throw std::invalid_argument("not 8th system");
        }
        this->data[i--] = c - 48;
    }
};

Octal::Octal(const std::string &t) { 
    this->size = t.size(); 
    this->data = new u_char[this->size];
    for (size_t i = 0; i < this->size; ++i) {
        if (!('0' <= t[i] && t[i] <= '7')) {
            throw std::invalid_argument("not 8th system");
        }
        this->data[i] = t[t.size() - 1 - i] - 48;
    }
};

Octal::Octal(const Octal& other) {
    this->size = other.size;
    this->data = new u_char[size];
    for (size_t i = 0; i < size; ++i) {
        this->data[i] = other.data[i];
    }
};

Octal::Octal(Octal&& other) noexcept {
    this->size = other.size;
    this->data = other.data;

    other.size = 0;
    other.data = nullptr;
};

Octal Octal::operator+(Octal const& obj) {
    std::string res(std::max(this->size, obj.size) + 1, '0');
    size_t i = 0;
    int tmp = 0;

    for (; i < std::min(this->size, obj.size); ++i) {
        res[i] = ((this->data[i] + obj.data[i] + tmp) % 8) + '0';
        tmp = (this->data[i] + obj.data[i] + tmp) / 8;
    }

    for (; i < this->size; ++i) {
        res[i] = (this->data[i] + tmp) % 8 + '0';
        tmp = (this->data[i] + tmp)/ 8;
    }

    for (; i < obj.size; ++i) {
        res[i] = (obj.data[i] + tmp) % 8 + '0';
        tmp = (obj.data[i] + tmp) / 8;
    }

    if (tmp != 0) {
        res[i] += 1;
    }

    if (res[res.size() - 1] == '0') {
        res.erase(res.size() - 1, 1);
    }

    std::reverse(res.begin(), res.end());

    return Octal(res);
}

Octal Octal::operator-(Octal const& obj) {
    if (*this < obj) {
        throw std::logic_error("answer can`t be negative"); 
    }
    std::string res(std::max(this->size, obj.size), '0');
    size_t i = 0;
    int tmp = 0;
    for (; i < obj.size; ++i) {
        if (this->data[i] < obj.data[i] + tmp) {
            res[i] = (this->data[i] - obj.data[i] + 8) + '0';
            tmp = 1;
        } else {
            res[i] = (this->data[i] - obj.data[i] - tmp) + '0';
            tmp = 0;
        }
    }

    for (; i < this->size; ++i)
        res[i] = this->data[i] + '0';

    for (; i < obj.size; ++i)
        res[i] = obj.data[i] + '0';

    while (res[res.size() - 1] == '0' && res.size() > 1) {
         res.erase(res.size() - 1, 1);
    }

    std::reverse(res.begin(), res.end());

    return Octal(res);
}

void Octal::operator=(Octal const& obj) {
    if (&obj != this) {
        delete[] this->data;
        this->size = obj.size;
        this->data = new u_char[this->size];
        for (size_t i = 0; i < this->size; ++i) {
            this->data[i] = obj.data[i];
        }
    }
}

bool Octal::operator>(Octal const& obj) {
    if (this->size == obj.size) {
        int i = this->size - 1;
        while (this->data[i] == obj.data[i]) {
            --i;
        }
        if (i < 0) return 0;
        else return (this->data[i] > obj.data[i]);

    }
    else return this->size > obj.size;
}

bool Octal::operator<(Octal const& obj) {
    if (this->size == obj.size) {
        int i = this->size - 1;
        while (this->data[i] == obj.data[i]) {
            --i;
        }
        if (i < 0) return 0;
        else return (this->data[i] < obj.data[i]);

    }
    else return this->size < obj.size;
}
bool Octal::operator==(Octal const& obj) const {
    if (this->size != obj.size) return 0;
    else {
        int i = this->size - 1;
        while (this->data[i] == obj.data[i] and i >= 0) {
            --i;
        }
        return (i < 0);
    }
}

Octal::~Octal() noexcept{
    if (this->size > 0) {
        this->size = 0;
        delete[] this->data;
        this->data = nullptr;
    }
} 
      
std::ostream& operator<<(std::ostream& os, const Octal& obj) {
    for (size_t i{0}; i < obj.size; ++i)
        os << int(obj.data[obj.size - i - 1]);
    return os;
}