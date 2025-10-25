#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>
#include <iostream>
#include <stdexcept>
template <typename T> class Array {
private:
  T *data;
  unsigned int size;

public:
  Array() : size(0), data(NULL) {}

  Array(unsigned int n) : size(n) { data = new T[n]; }

  Array(const Array &other) : data(NULL), size(other.size) { *this = other; }

  Array &operator=(const Array &other) {
    if (this != &other) {
      delete[] data;
      size = other.size;
      data = new T[size];
      for (unsigned int i = 0; i < size; i++) {
        data[i] = other.data[i];
      }
    }
    return *this;
  }

  ~Array() { delete[] data; }

  T &operator[](unsigned int index) {
    if (index >= size) {
      throw std::out_of_range("Index out of range");
    }
    return data[index];
  }

  T &operator[](unsigned int index) const {
    if (index >= size) {
      throw std::out_of_range("Index out of range");
    }
    return data[index];
  }

  unsigned int getSize() const { return size; }
};

#endif
