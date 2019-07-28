#ifndef SWAP_H_
#define SWAP_H_

namespace dsa {

template<class T>
void swap(T& a, T& b) {
  T tmp = a;
  a = b;
  b = tmp;
}

} // namespace dsa

#endif // SWAP_H_
