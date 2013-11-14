/**
 * @file avlsearchtree.h
 * @brief define interface for AVL tree
 * @author jiaoew
 * @version 0.1
 * @date 2013-11-10
 */
#ifndef AVLSEARCHTREE_H
#define AVLSEARCHTREE_H

#include "balancetree.h"

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

    int leftHeight() 
    {
        AVLTreeNode<Key, Value>* pleftChild = leftChild();
        return pleftChild ? pleftChild->height : 0;
    }

    int rightHeight() 
    {
        AVLTreeNode<Key, Value>* pRightChild = rightChild();
        return pRightChild ? pRightChild->height : 0;
    }

    /**
     * @override
     */
    AVLTreeNode<Key, Value>* leftChild() 
    {
        return (AVLTreeNode<Key, Value>*) BinaryTreeNode<Key, Value>::leftChild();
    }

    /**
     * @override
     */
    AVLTreeNode<Key, Value>* rightChild()
    {
        return (AVLTreeNode<Key, Value>*) BinaryTreeNode<Key, Value>::rightChild();
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
class AVLSearchTree : public BalanceTree<Key, Value>
{
public:
    AVLSearchTree() : BalanceTree<Key, Value>()
    {
    }
    virtual ~AVLSearchTree()
    {
    }

    /**
     * @override
     */
    virtual int height()
    {
        return ((AVLTreeNode<Key, Value>*) this->mRoot)->height;
    }

protected:
    /**
     * @override
     */
    virtual BinaryTreeNode<Key, Value>* insertHelper(BinaryTreeNode<Key, Value>*, const Key&, const Value&);

    /**
     * @override
     */
    virtual BinaryTreeNode<Key, Value>* removeHelper(BinaryTreeNode<Key, Value>*, const Key&, BinaryTreeNode<Key, Value>*&);

    /**
     * @override
     */
    virtual BinaryTreeNode<Key, Value>* deleteMin(BinaryTreeNode<Key, Value>*, BinaryTreeNode<Key, Value>*&);

    /**
     * @override
     */
    virtual int createTreeNode(const Key& key, const Value& value, BinaryTreeNode<Key, Value>*& pNode) 
    {
        pNode = new AVLTreeNode<Key, Value>(key, value);
        return URANUS_SUCCESS;
    }


private:

    /**
     * @breif 左旋之后更新字数根节点的高度
     * @override
     */
    virtual AVLTreeNode<Key, Value>* leftRotate(AVLTreeNode<Key, Value>* subRoot)
    {
        subRoot = (AVLTreeNode<Key, Value>*) BalanceTree<Key, Value>::leftRotate(subRoot);
        adjustHeight(subRoot->leftChild());
        adjustHeight(subRoot);
        return subRoot;
    }

    /**
     * @breif 右旋之后更新字数根节点的高度
     * @override
     */
    virtual AVLTreeNode<Key, Value>* rightRotate(AVLTreeNode<Key, Value>* subRoot)
    {
        subRoot = (AVLTreeNode<Key, Value>*) BalanceTree<Key, Value>::rightRotate(subRoot);
        std::cout << subRoot << std::endl;
        std::cout << "adjust right height" << std::endl;
        adjustTree(subRoot->rightChild());
        std::cout << "adjust left height" << std::endl;
        adjustHeight(subRoot);
        return subRoot;
    }
    /**
     * @brief 调整树的结构
     *
     * @param   AVLTreeNode 子树的根节点
     *
     * @returns   子树的根节点
     */
    BinaryTreeNode<Key, Value>* adjustTree(AVLTreeNode<Key, Value>*);

    int adjustHeight(AVLTreeNode<Key, Value>* subRoot)
    {
        subRoot = (AVLTreeNode<Key, Value>*) subRoot;
        if (subRoot == NULL) {
            return URANUS_EMPTY_TREE;
        }
        int leftHeight = subRoot->leftHeight();
        int rightHeight = subRoot->rightHeight();
        subRoot->height = (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
        return URANUS_SUCCESS;
    }
};

#include "avlsearchtree.cpp"

#endif /* end of include guard: AVLSEARCHTREE_H */
