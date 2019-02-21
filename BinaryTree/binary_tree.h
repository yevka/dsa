#include <cstddef>
#include <iostream>

template <typename Key,typename T>
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

private:
    void erase(const Key& key, node<Key, T>* parent, node<Key, T> *&pnode);
    node<Key,T>* find(const Key& key, node<Key, T>* pnode) const;
    void insert(const Key& key, const T& value, node<Key, T>*& pnode);

private:
    node<Key, T>* root_;
    size_t count_;
};



template <typename Key, typename T>
inline binary_tree<Key, T>::binary_tree() : root_(nullptr) {

}



template <typename Key, typename T>
inline void binary_tree<Key, T>::erase(const Key& key, node<Key, T>* parent, node<Key, T>*& pnode) {
    if ( ! pnode) {
        return ;
    }

    if (pnode->key > key) {
        erase(key, pnode, pnode->right);
    }
    else if (pnode->key < key) {
        erase(key, pnode, pnode->left);
    }
    else if (pnode->key == key) {
        if (!pnode->left && !pnode->right) {
            delete pnode;
        }
        else if (!pnode->left) {

        }
        else if (!pnode->right) {

        }
        else if (pnode->left && pnode->right) {

        }
        else if (pnode->left) {

        }
        else if (pnode->right) {

        }
    }
}



template <typename Key, typename T>
inline node<Key,T>* binary_tree<Key, T>::find(const Key& key, node<Key, T>* pnode) const {
    if ( ! pnode) {
        return nullptr;
    }
    if(pnode->key == key) {
        return pnode;
    }
    if (pnode->key > key) {
        find(key, pnode->right);
    }
    else if(pnode->key < key) {
        find(key, pnode->left);
    }
    return nullptr;
}



template <typename Key, typename T>
inline void binary_tree<Key, T>::insert(const Key& key, const T& value, node<Key, T>*& pnode) {
    if( ! pnode) {
        pnode = new node<Key, T> { key, value, nullptr, nullptr };
        ++count_;
        return ;
    }
    if(pnode->key > key) {
        insert(key, value, pnode->right);
    }
    else if(pnode->key < key) {
        insert(key, value, pnode->left);
    }
    else {
        pnode->key = key;
    }
}



template <typename Key, typename T>
inline size_t binary_tree<Key, T>::count() const {
    return count_;
}



template <typename Key, typename T>
inline bool binary_tree<Key, T>::empty() const {
    return root_ ?  false : true;
}


template <typename Key, typename T>
inline void binary_tree<Key, T>::erase(const Key& key) {
    erase(key, root_, root_);
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
