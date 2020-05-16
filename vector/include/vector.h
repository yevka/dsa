#ifndef VECTOR_H_
#define VECTOR_H_

#include <cstddef>
#include <cstring>


namespace yevka {

template<typename T>
class vector {
public:
  vector() :
          capacity_{2},
          size_{0},
          data_{new T[capacity_]} {}

  ~vector() {
    delete[] data_;
  }

  void push_back(const T &val);

  const T *data() const noexcept;

private:
  std::size_t capacity_;
  std::size_t size_;
  T *data_;
  const std::size_t kN = 2u;
};


template<typename T>
void vector<T>::push_back(const T &val) {
  if (size_ + 1 > capacity_) {
    T* tmp = new T[capacity_];
    memcpy(tmp, data_, capacity_ * sizeof(T));
    delete[] data_;
    data_ = new T[capacity_ * kN];
    memcpy(data_, tmp, capacity_ * sizeof(T));
    capacity_ *= kN;
    delete[] tmp;
  }
  data_[size_++] = val;
}


template<typename T>
const T *vector<T>::data() const noexcept {
  return data_;
}


} // namespace yevka

#endif // VECTOR_H_