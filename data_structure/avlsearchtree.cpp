#include <cmath>
#include "avlsearchtree.h"

template<class Key, class Value>
AVLTreeNode<Key, Value>* AVLSearchTree<Key, Value>::insertHelper(AVLTreeNode<Key, Value>* subRoot, const Key& key, const Value& value) {
    subRoot = BinaryTreeNode<Key, Value>::insertHelper(subRoot, key, value);
    adjustHeight(subRoot);
    return adjustTree(subRoot);
}

template<class Key, class Value>
AVLTreeNode<Key, Value>* AVLSearchTree<Key, Value>::removeHelper(AVLTreeNode<Key, Value>* subRoot, const Key& key, AVLTreeNode<Key, Value>*& pNode) {
    subRoot = BinaryTreeNode<Key, Value>::removeHelper(subRoot, key, pNode);
    adjustHeight(subRoot);
    return adjustTree(subRoot);
}

template<class Key, class Value>
AVLTreeNode<Key, Value>* AVLSearchTree<Key, Value>::deleteMin(AVLTreeNode<Key, Value>* subRoot, AVLTreeNode<Key, Value>*& pNode) 
{
    subRoot = BinaryTreeNode<Key, Value>::deleteMin(subRoot, pNode);
    adjustHeight(subRoot);
    return subRoot;
}

template<class Key, class Value>
AVLTreeNode<Key, Value>* AVLSearchTree<Key, Value>::adjustTree(AVLTreeNode<Key, Value>* subRoot) {
    int leftH = subRoot->leftHeight();
    int rightH = subRoot->rightHeight();
    if (abs(leftH - rightH) <= 1) { // it is okay, don't need adjust
        return subRoot;
    }
    else if (leftH - rightH > 1) { // left subtree's height is too large
        // TODO
    }
    else {
        // TODO
    }
}
