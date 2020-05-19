#ifndef VECTOR_H_
#define VECTOR_H_

#include <cstddef>
#include <cstring>
#include <exception>
#include <climits>


namespace dsa {

template<typename T>
class vector {
public:
  vector() :
          capacity_{0},
          size_{0},
          data_{new T[capacity_]} {}

  ~vector() {
    delete[] data_;
  }

  std::size_t capacity() const;

  std::size_t size() const;

  T& at(const std::size_t& i);

  const T& at(const std::size_t& i) const;

  void push_back(const T &val);

  void pop_back();

  const T *data() const noexcept;

  void clear() noexcept;

private:
  std::size_t calculate_growth(const size_t new_size) const;

private:
  std::size_t capacity_;
  std::size_t size_;
  T *data_;
  const std::size_t kN = 2u;
};



template<typename T>
std::size_t vector<T>::capacity() const {
  return capacity_;
}



template<typename T>
std::size_t vector<T>::size() const {
  return size_;
}



template<typename T>
T& vector<T>::at(const std::size_t& i) {
  if (size_ == 0u || i > size_ - 1u) throw std::out_of_range("out of range");
  return data_[i];
}



template<typename T>
const T& vector<T>::at(const std::size_t& i) const {
  if (size_ == 0u || i > size_ - 1u) throw std::out_of_range("out of range");
  return data_[i];
}



template<typename T>
void vector<T>::push_back(const T &val) {
  if (capacity_ == 0) {
    data_ = new T[1];
    capacity_ = 1;
  } else {
    std::size_t unused_capacity = capacity_ - size_;
    if (unused_capacity == 0) {
      T* tmp = new T[capacity_];
      memcpy(tmp, data_, capacity_ * sizeof(T));
      delete[] data_;
      std::size_t new_capacity = calculate_growth(size_ + 1);
      data_ = new T[new_capacity];
      memcpy(data_, tmp, capacity_ * sizeof(T));
      capacity_ = new_capacity;
      delete[] tmp;
    }
  }
  data_[size_++] = val;
}



template<typename T>
void vector<T>::pop_back() {
  if (!data_ && size_ == 0) return; // todo throw exception
  --size_;
}



template<typename T>
const T *vector<T>::data() const noexcept {
  return data_;
}


template<typename T>
void vector<T>::clear() noexcept {
  size_ = 0;
}



template<typename T>
std::size_t vector<T>::calculate_growth(const size_t new_size) const {
  const std::size_t old = capacity();
  if (old > std::numeric_limits<std::size_t>::max() - old / 2) {
    return new_size; // geometric growth would overflow
  }
  const std::size_t geometric = old + old / 2;
  if (geometric < new_size) {
    return new_size; // geometric growth would be insufficient
  }
  return geometric; // geometric growth is sufficient
}



} // namespace dsa

#endif // VECTOR_H_