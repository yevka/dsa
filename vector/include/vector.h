#ifndef VECTOR_H_
#define VECTOR_H_

namespace yevka {

template<typename T>
class vector {
public:
  vector() : data_{nullptr} {}

  ~vector() {}

  void push_back(const T &val);

  const T *data() const noexcept;

private:
  T *data_;
};



template<typename T>
void vector<T>::push_back(const T &val) {

}



template<typename T>
const T * vector<T>::data() const noexcept {
  return data_;
}



} // namespace yevka

#endif // VECTOR_H_