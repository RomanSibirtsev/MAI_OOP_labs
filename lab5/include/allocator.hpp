#pragma once

#include <iostream>
#include <memory>
#include <chrono>
#include <vector>
#include <map>
#include <utility>

template <class T, size_t SIZE>
class Allocator {
private:
    T* _used_blocks;
    T **_free_blocks;
    uint64_t _free_count;
public:
    using value_type = T;
    using pointer = T*;
    using const_pointer = const T*;
    using size_type = std::size_t;

    Allocator() {
        _used_blocks = static_cast<T*>(malloc(sizeof(T) * SIZE));
        _free_blocks = static_cast<T**>(malloc(sizeof(T*) * SIZE));

        for (uint64_t i = 0; i < SIZE; ++i) {
            _free_blocks[i] = _used_blocks + i * sizeof(T);
        }
        _free_count = SIZE;
    }

    ~Allocator() {
        free(_used_blocks);
        delete[] _free_blocks;
    }

    T *allocate(size_t n) {
        T *result = nullptr;
        size_t newSize = n;
        for (size_t i = 0; i < newSize; ++i) {
            if (_free_count > 0) {
                result = _free_blocks[--_free_count];
            } else {
                throw std::bad_alloc();
            }
        }
        return result;
    }

    void deallocate(T *pointer, size_t) {
        _free_blocks[_free_count++] = pointer;
    }

    template <class U>
    struct rebind {
        using other = Allocator<U, SIZE>;
    };

    template <typename U, typename... Args>
    void construct(U *p, Args &&...args) {
        new (p) U(std::forward<Args>(args)...);
    }

    void destroy(pointer p) {
        p->~T();
    }
};
