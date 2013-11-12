/**
 * @file avlsearchtree.h
 * @brief define interface for AVL tree
 * @author jiaoew
 * @version 0.1
 * @date 2013-11-10
 */
#ifndef AVLSEARCHTREE_H
#define AVLSEARCHTREE_H

#include "binarysearchtree.h"

/**
 * @brief define and implement AVLTreeNode class, it's the node of AVL tree
 *
 * @tparam Key      key type
 * @tparam Value    data type
 */
template<class Key, class Value>
class AVLTreeNode : public BinaryTreeNode<Key, Value>
{
public:
    AVLTreeNode(const Key& key, const Value& value) : BinaryTreeNode<Key, Value>(key, value)
    {
        height = 0;
    }
    virtual ~AVLTreeNode() 
    {
    }

    int leftHeight() const 
    {
        return this->left ? this->left->height : 0;
    }

    int rightHeight() const 
    {
        return this->right ? this->right->height : 0;
    }

public:
    int height;                     // height of the subtree
};

/**
 * @brief define AVLSearchTree interface
 *
 * @tparam Key      key type
 * @tparam Value    value type
 */
template<class Key, class Value>
class AVLSearchTree : public BinarySearchTree<Key, Value>
{
public:
    AVLSearchTree() : BinarySearchTree<Key, Value>()
    {
    }
    virtual ~AVLSearchTree()
    {
    }

protected:
    /**
     * @override
     */
    virtual AVLTreeNode<Key, Value>* insertHelper(AVLTreeNode<Key, Value>*, const Key&, const Value&);

    /**
     * @override
     */
    virtual AVLTreeNode<Key, Value>* removeHelper(AVLTreeNode<Key, Value>*, const Key&, AVLTreeNode<Key, Value>*&);

    /**
     * @override
     */
    virtual AVLTreeNode<Key, Value>* deleteMin(AVLTreeNode<Key, Value>*, AVLTreeNode<Key, Value>*&);

    /**
     * @override
     */
    virtual int createTreeNode(const Key& key, const Value& value, BinaryTreeNode<Key, Value>*& pNode) 
    {
        pNode = AVLTreeNode<Key, Value>(key, value);
        return URANUS_SUCCESS;
    }

    /**
     * @brief 调整树的结构
     *
     * @param   AVLTreeNode 子树的根节点
     *
     * @returns   子树的根节点
     */
    AVLTreeNode<Key, Value>* adjustTree(AVLTreeNode<Key, Value>*);
private:

    int adjustHeight(const AVLTreeNode<Key, Value>* subRoot)
    {
        if (subRoot == NULL) {
            return URANUS_EMPTY_TREE;
        }
        int leftHeight = subRoot->leftHeight();
        int rightHeight = subRoot->rightHeight();
        subRoot->height = leftHeight > rightHeight ? leftHeight : rightHeight;
    }
};

#include "avlsearchtree.cpp"

#endif /* end of include guard: AVLSEARCHTREE_H */
