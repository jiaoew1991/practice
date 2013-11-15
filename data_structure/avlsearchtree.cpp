#include <cmath>
#include "avlsearchtree.h"

template<class Key, class Value>
BinaryTreeNode<Key, Value>* AVLSearchTree<Key, Value>::insertHelper(BinaryTreeNode<Key, Value>* subRoot, const Key& key, const Value& value) {
    subRoot = BinarySearchTree<Key, Value>::insertHelper(subRoot, key, value);
    AVLTreeNode<Key, Value>* avlSubRoot = (AVLTreeNode<Key, Value>*) subRoot;
    adjustHeight(avlSubRoot);
    return this->adjustTree(avlSubRoot);
}

template<class Key, class Value>
BinaryTreeNode<Key, Value>* AVLSearchTree<Key, Value>::removeHelper(BinaryTreeNode<Key, Value>* subRoot, const Key& key, BinaryTreeNode<Key, Value>*& pNode) {
    log4cplus::Logger logger = log4cplus::Logger::getInstance(LOG4CPLUS_TEXT("delete"));
    subRoot = BinarySearchTree<Key, Value>::removeHelper(subRoot, key, pNode);
    if (subRoot == NULL) {
        return NULL;
    }
    AVLTreeNode<Key, Value>* avlSubRoot = (AVLTreeNode<Key, Value>*) subRoot;
    adjustHeight(avlSubRoot);
    return this->adjustTree(avlSubRoot);
}

template<class Key, class Value>
BinaryTreeNode<Key, Value>* AVLSearchTree<Key, Value>::deleteMin(BinaryTreeNode<Key, Value>* subRoot, BinaryTreeNode<Key, Value>*& pNode) 
{
    subRoot = BinarySearchTree<Key, Value>::deleteMin(subRoot, pNode);
    AVLTreeNode<Key, Value>* avlSubRoot = (AVLTreeNode<Key, Value>*) subRoot;
    adjustHeight(avlSubRoot);
    return subRoot;
}

template<class Key, class Value>
BinaryTreeNode<Key, Value>* AVLSearchTree<Key, Value>::adjustTree(AVLTreeNode<Key, Value>* subRoot) {
    int leftH = subRoot->leftHeight();
    int rightH = subRoot->rightHeight();
    AVLTreeNode<Key, Value>* leftChild = subRoot->leftChild();
    AVLTreeNode<Key, Value>* rightChild = subRoot->rightChild();
    if (abs(leftH - rightH) <= 1) { // it is okay, don't need adjust
        return subRoot;
    }
    else if (leftH - rightH > 1) { // left subtree's height is too large
        if (leftChild->leftHeight() > subRoot->rightHeight()) {
            subRoot = this->rightRotate(subRoot);
        } 
        else {
            log4cplus::Logger logger = log4cplus::Logger::getInstance(LOG4CPLUS_TEXT("rotate"));
            LOG4CPLUS_DEBUG(logger, "first right rotate");
            subRoot = this->rightRotate(subRoot);

            LOG4CPLUS_DEBUG(logger, "second right rotate");

            subRoot->setRightChild(this->rightRotate(subRoot->rightChild()));

            LOG4CPLUS_DEBUG(logger, this->toString());

            subRoot = this->leftRotate(subRoot);
        }
    }
    else {
        if (rightChild->rightHeight() > subRoot->leftHeight()) {
            subRoot = this->leftRotate(subRoot);
        }
        else {
            subRoot = this->leftRotate(subRoot);
            subRoot->setLeftChild(this->leftRotate(subRoot->leftChild()));
            subRoot = this->rightRotate(subRoot);
        }
    }
    return subRoot;
}
