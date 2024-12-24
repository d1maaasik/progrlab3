#include <iostream>
#include <stdexcept>

class DynamicArray {
private:
    int* data;
    size_t capacity;
    size_t length;

    void resize(size_t new_capacity) {
        int* new_data = new int[new_capacity];
        for (size_t i = 0; i < length; ++i) {
            new_data[i] = std::move(data[i]);
        }
        delete[] data;
        data = new_data;
        capacity = new_capacity;
    }

public:
    
    DynamicArray() : data(nullptr), capacity(0), length(0) {}

    
    ~DynamicArray() {
         delete[] data;
    }

    
    DynamicArray(DynamicArray&& other) noexcept : data(other.data), capacity(other.capacity), length(other.length) {
        other.data = nullptr;
        other.capacity = 0;
        other.length = 0;
    }

    DynamicArray& operator=(DynamicArray&& other) noexcept {
        if (this != &other) {
            delete[] data;
            data = other.data;
            capacity = other.capacity;
            length = other.length;
            other.data = nullptr;
            other.capacity = 0;
            other.length = 0;
        }
        return *this;
    }

    
    void push_back(int value) {
        if (length == capacity) {
            resize(capacity == 0 ? 1 : capacity * 1.5);
        }
        data[length++] = value;
    }

    
    void insert(size_t index, int value) {
        if (index > length) throw std::out_of_range("Index out of range");
        if (length == capacity) {
            resize(capacity == 0 ? 1 : capacity * 1.5);
        }
        for (size_t i = length; i > index; --i) {
            data[i] = data[i - 1];
        }
        data[index] = value;
        ++length;
    }

    
    void erase(size_t index) {
        if (index >= length) throw std::out_of_range("Index out of range");
        for (size_t i = index; i < length - 1; ++i) {
            data[i] = data[i + 1];
        }
        --length;
    }

    
    size_t size() const {
        return length;
    }

    
    int& operator[](size_t index) {
        if (index >= length) throw std::out_of_range("Index out of range");
        return data[index];
    }

    
    class Iterator {
    private:
        int* ptr;

    public:
        Iterator(int* p) : ptr(p) {}

        int& operator*() {
            return *ptr;
        }

        Iterator& operator++() {
            ++ptr;
            return *this;
        }

        bool operator!=(const Iterator& other) const {
            return ptr != other.ptr;
        }
    };

    Iterator begin() {
        return Iterator(data);
    }

    Iterator end() {
        return Iterator(data + length);
    }

    
    void print() const {
        for (size_t i = 0; i < length; ++i) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }
};