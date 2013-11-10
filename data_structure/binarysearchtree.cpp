#include "binarysearchtree.h"

template<class Key, class Value>
void BinarySearchTree<Key, Value>::clearHelper(BinaryTreeNode<Key, Value>* subRoot)
{
    if (subRoot == NULL) {
        return;
    } 
    else {
        clearHelper(subRoot->left);
        clearHelper(subRoot->right);
        delete subRoot;
    }
}

template<class Key, class Value>
BinaryTreeNode<Key, Value>* BinarySearchTree<Key, Value>::insertHelper(BinaryTreeNode<Key, Value>* subRoot, const Key& key, const Value& value)
{
    if (subRoot == NULL) {
        subRoot = new BinaryTreeNode<Key, Value>(key, value);
    }
    else if (subRoot->keyEquals(key) > 0) {
        subRoot->right = insertHelper(subRoot->right, key, value);
    } 
    else if (subRoot->keyEquals(key) <= 0) {
        subRoot->left = insertHelper(subRoot->left, key, value);
    }
    return subRoot;
}

template<class Key, class Value>
BinaryTreeNode<Key, Value>* BinarySearchTree<Key, Value>::deleteMin(BinaryTreeNode<Key, Value>* subRoot, BinaryTreeNode<Key, Value>*& pNode)
{
    if (subRoot->left) { // find the minest
        subRoot->left = deleteMin(subRoot->left, pNode);
        return subRoot;
    } 
    else {  // find it! and return it's right;
        pNode = subRoot;
        return subRoot->right;
    }
}

template<class Key, class Value>
BinaryTreeNode<Key, Value>* BinarySearchTree<Key, Value>::removeHelper(BinaryTreeNode<Key, Value>* subRoot, const Key& key, BinaryTreeNode<Key, Value>*& pNode)
{
    if (subRoot == NULL) {
        return NULL;
    }
    else if (subRoot->keyEquals(key) > 0) { 
        subRoot->right = removeHelper(subRoot->right, key, pNode);
    }
    else if (subRoot->keyEquals(key) < 0) {
        subRoot->left = removeHelper(subRoot->left, key, pNode);
    }
    else { // remove target is current node;
        BinaryTreeNode<Key, Value> *pTmp;
        pNode = subRoot;
        if (subRoot->left == NULL) { // left child is null, 
            subRoot = subRoot->right;
        }
        else if (subRoot->right == NULL) {
            subRoot = subRoot->left;
        } 
        else { // both children are not null, remove it's successor
            Value rTmpValue = subRoot->getValue();
            subRoot->right = deleteMin(subRoot->right, pTmp);
            subRoot->setValue(pTmp->value());
            pTmp->setValue(rTmpValue);
            pNode = pTmp;
        }

    }
    return subRoot;
}

template<class Key, class Value>
int BinarySearchTree<Key, Value>::findHelper(BinaryTreeNode<Key, Value>* subRoot, const Key& key, Value& value)
{
    if (subRoot == NULL) {
        return URANUS_EMPTY_TREE;
    }
    else if (subRoot->keyEqual(key) > 0) {
        return findHelper(subRoot->right, key, value);
    }
    else if (subRoot->KeyEqual(key) < 0) {
        return findHelper(subRoot->left, key, value);
    }
    else {
        value = subRoot->value();
        return URANUS_SUCCESS;
    }
}

template<class Key, class Value>
int BinarySearchTree<Key, Value>::heightHelper(BinaryTreeNode<Key, Value>* subRoot)
{
    int leftHeight = heightHelper(subRoot->left);
    int rightHeight = heightHelper(subRoot->right);
    return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
}
