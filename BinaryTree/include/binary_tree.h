#include <cstddef>
#include <iostream>


template <typename Key, typename T>
struct node {
  Key key;
  T value;
  node* left;
  node* right;
};

template <typename Key, typename T>
class binary_tree {
public:
  binary_tree();

  size_t count() const;
  bool empty() const;
  void erase(const Key& key);
  T* find(const Key& key) const;
  void insert(const Key& key, const T& value);

  void print_infix_travers() const;
  void print_prefix_travers() const;
  void print_postfix_travers() const;

private:
  void remove_node(node<Key, T>* pnode);
  void erase(const Key& key, node<Key, T>* parent, node<Key, T>* pnode);
  node<Key, T>* find(const Key& key, node<Key, T>* pnode) const;
  void insert(const Key& key, const T& value, node<Key, T>* pnode);

  void print_infix_travers(const node<Key, T>* pnode) const;
  void print_prefix_travers(const node<Key, T>* pnode) const;
  void print_postfix_travers(const node<Key, T>* pnode) const;

private:
  node<Key, T>* root_;
  size_t count_;
};



template <typename Key, typename T>
inline void binary_tree<Key, T>::remove_node(node<Key, T>* pnode) {
  delete pnode;
  pnode = nullptr;
}



template <typename Key, typename T>
inline void binary_tree<Key, T>::print_infix_travers(const node<Key, T>* pnode) const {
  if ( ! pnode) {
    return /*void*/;
  }
  print_infix_travers(pnode->left);
  std::cout << pnode->key << " ";
  print_infix_travers(pnode->right);
}



template <typename Key, typename T>
inline void binary_tree<Key, T>::print_prefix_travers(const node<Key, T>* pnode) const {
  if ( ! pnode) {
    return /*void*/;
  }
  std::cout << pnode->key << " ";
  print_postfix_travers(pnode->left);
  print_postfix_travers(pnode->right);
}



template <typename Key, typename T>
inline void binary_tree<Key, T>::print_postfix_travers(const node<Key, T>* pnode) const {
  if ( ! pnode) {
    return /*void*/;
  }
  print_postfix_travers(pnode->right);
  std::cout << pnode->key << " ";
  print_postfix_travers(pnode->left);
}



template <typename Key, typename T>
inline void binary_tree<Key, T>::print_infix_travers() const {
  print_infix_travers(root_);
}



template <typename Key, typename T>
inline void binary_tree<Key, T>::print_prefix_travers() const {
  print_prefix_travers(root_);
}



template <typename Key, typename T>
inline void binary_tree<Key, T>::print_postfix_travers() const {
  print_postfix_travers(root_);
}



template <typename Key, typename T>
inline binary_tree<Key, T>::binary_tree() : root_(nullptr), count_{0u} {

}



template <typename Key, typename T>
inline void binary_tree<Key, T>::erase(const Key& key, node<Key, T>* parent, node<Key, T>* pnode) {
  if ( ! parent || ! pnode) {
    return /*void*/;
  }

  if (pnode->right && key > pnode->key) {
    erase(key, pnode, pnode->right);
  }
  else if (pnode->left && key < pnode->key) {
    erase(key, pnode, pnode->left);
  }
  else if (key == pnode->key) {
    if (pnode->left && pnode->right) {
      node<Key, T>* predecessor = pnode->right;
      node<Key, T>* successor = pnode->right;
      while (successor->left) {
        predecessor = successor;
        successor = successor->left;
      }
      predecessor->left = successor->right;
      pnode->key = successor->key;
      pnode->value = successor->value;
      remove_node(successor);
      remove_node(predecessor);
      --count_;
      return /*void*/;
    }
    else if (pnode->left) {
      const bool is_pnode_right_side = pnode->key > parent->key;
      if (is_pnode_right_side) {
        parent->right = pnode->left;
      }
    }
    else if (pnode->right) {
      const bool is_pnode_left_side = pnode->key < parent->key;
      if (is_pnode_left_side) {
        parent->left = pnode->right;
      }
    }
    remove_node(pnode);
    --count_;
  }
}



template <typename Key, typename T>
inline node<Key, T>* binary_tree<Key, T>::find(const Key& key, node<Key, T>* pnode) const {
  if (!pnode) {
    return nullptr;
  }
  if (pnode->key == key) {
    return pnode;
  }
  if (pnode->right && key > pnode->key) {
    find(key, pnode->right);
  }
  else if (pnode->left && key < pnode->key) {
    find(key, pnode->left);
  }
  return nullptr;
}



template <typename Key, typename T>
inline void binary_tree<Key, T>::insert(const Key& key, const T& value, node<Key, T>* pnode) {
  if (!pnode) {
    pnode = new node<Key, T>{ key, value, nullptr, nullptr };
    ++count_;
    return /*void*/;
  }
  if (key > pnode->key) {
    insert(key, value, pnode->right);
  }
  else if (key < pnode->key) {
    insert(key, value, pnode->left);
  }
  else if (pnode->key == key) {
    pnode->value = value;
  }
}



template <typename Key, typename T>
inline size_t binary_tree<Key, T>::count() const {
  return count_;
}



template <typename Key, typename T>
inline bool binary_tree<Key, T>::empty() const {
  return root_ ? false : true;
}



template <typename Key, typename T>
inline void binary_tree<Key, T>::erase(const Key& key) {
  if (!root_) {
    return /*void*/;
  }
  if (key > root_->key) {
    erase(key, root_, root_->right);
  }
  else if (key < root_->key) {
    erase(key, root_, root_->left);
  }
  else if (key == root_->key) {
    erase(key, root_, root_);
  }
}



template <typename Key, typename T>
inline T* binary_tree<Key, T>::find(const Key& key) const {
  node<Key, T>* pnode = find(key, root_);
  return pnode ? &pnode->value : nullptr;
}



template <typename Key, typename T>
inline void binary_tree<Key, T>::insert(const Key& key, const T& value) {
  insert(key, value, root_);
}
