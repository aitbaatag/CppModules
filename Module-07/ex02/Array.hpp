#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>
#include <stdexcept>
template <typename T> class Array {
private:
  T *data;
  size_t size;

public:
  Array(size_t n) : size(n) { data = new T[n]; }
  Array(const Array &other) : size(other.size) {
    data = new T[size];
    for (size_t i = 0; i < size; i++) {
      data[i] = other.data[i];
    }
  }
  Array &operator=(const Array &other) {
    if (this != &other) {
      delete[] data;
      *this = Array(other);
    }
    return *this;
  }
  ~Array() { delete[] data; }
  T &operator[](size_t index) {
    if (index >= size) {
      throw std::out_of_range("Index out of range");
    }
    return data[index];
  }
  size_t getSize() const { return size; }
};

#endif
