#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <cstddef>

template <typename T>
struct node {
  T key_value;
  node* left;
  node* right;
};

template <typename Key, typename T>
class binary_tree {
public:
  binary_tree() : root_(nullptr) {}

  bool empty() const { return root_ ? false : true; }

  /// if find key value will be replace
  void insert(const Key& key, const T& value) {
    if (root_) {
      ++count_;
    }
    else {
      root_ = new node<T> { value, nullptr, nullptr };
      ++count_;
    }
  }

  void erase(const Key& k) {
    node<T>* pnode = find(k);
    if (!pnode) { return /*void*/; }
    --count_;
  }

  node<T>* find(const Key& k) {
    if ( ! root_) { return nullptr; }
    return nullptr;
  }

  size_t count(const Key& key) { return 0u; }

private:
  node<T>* root_;
  size_t count_;
};


#endif // BINARY_TREE_H
