#ifndef VECTOR_H_
#define VECTOR_H_

#include <cstddef>
#include <cstring>
#include <exception>


namespace dsa {

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

  T& at(const std::size_t& i);

  const T& at(const std::size_t& i) const;

  void push_back(const T &val);

  void pop_back();

  const T *data() const noexcept;

private:
  std::size_t capacity_;
  std::size_t size_;
  T *data_;
  const std::size_t kN = 2u;
};



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
void vector<T>::pop_back() {
  if (!data_ && size_ == 0) return; // todo throw exception
  --size_;
}



template<typename T>
const T *vector<T>::data() const noexcept {
  T* diff = data_ - (capacity_ - size_);

  return data_;
}


} // namespace dsa

#endif // VECTOR_H_