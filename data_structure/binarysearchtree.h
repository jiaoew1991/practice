/**
 * @file binarysearchtree.h
 * @brief 定义二叉搜索树BinarySearchTree接口
 * @author jiaoew
 * @version 0.1
 * @date 2013-11-09
 */
#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include "searchtree.h"

/**
 * @brief 定义二叉树节点
 *
 * @tparam Value
 */
template<class Key, class Value>
class BinaryTreeNode
{
public:
    BinaryTreeNode(const Key& key, const Value& value) 
    {
        mKey = key;
        mData = value;
        right = left = NULL;
    }
    virtual ~BinaryTreeNode();

    /**
     * @brief @Setter
     *
     * @param   value
     */
    void setValue(const Value& value)
    {
        mData = value;
    }
    /**
     * @brief @Getter
     *
     * @param   value
     */
    void value(Value& value) 
    {
        value = mData;
    }

    int keyEquals(const Key& key)
    {
        if (key == mKey) {
            return 0;
        } 
        else if (key > mKey) {
            return 1;
        }
        else {
            return -1;
        }
    }

public:
    BinaryTreeNode<Key, Value> *left; // left child node pointer;
    BinaryTreeNode<Key, Value> *right; // right child node pointer;

private:
    Value mData;
    Key mKey;
};
/**
 * @brief 定义二叉搜索树接口，继承自SearchTree
 *
 * @tparam Key
 * @tparam Value
 */
template<class Key, class Value>
class BinarySearchTree
{
public:
    BinarySearchTree() 
    {
        mRoot = NULL;
        nodeCnt = 0;
    }

    virtual ~BinarySearchTree() 
    {
        clearHelper(mRoot);
        mRoot = NULL;
        nodeCnt = 0;
    }

    /**
     * @Override
     */
    void clear() 
    {
        clearHelper(mRoot);
    }

    /**
     * @Override
     */
    int insert(const Key& key, const Value& value)
    {
        mRoot = insertHelper(mRoot, key, value);
        nodeCnt++;
        return URANUS_SUCCESS;
    }

    /**
     * @Override
     */
    int remove(const Key& key, Value& value)
    {
        BinaryTreeNode<Key, Value>* pNode = NULL;
        mRoot = removeHelper(mRoot, key, pNode);
        if (pNode == NULL) {
            return URANUS_FIND_NOTHING;
        }
        value = pNode->value();
        delete pNode;
        nodeCnt--;
        return URANUS_SUCCESS;
    }

    /**
     * @Override
     */
    int find(const Key& key, Value& value)
    {
        return findHelper(mRoot, key, value);
    }

    /**
     * @Override
     */
    int size()
    {
        return nodeCnt;
    }

    /**
     * @Override
     */
    int height()
    {
        return heightHelper(mRoot);
    }
private:
    void clearHelper(BinaryTreeNode<Key, Value>*);

    /**
     * @brief 向子树中插入新的节点，并返回子树的根节点
     *
     * @param   BinaryTreeNode  子树的根
     * @param   key             要插入的key
     * @param   value           要插入的value
     *
     * @returns     子树的根节点
     */
    BinaryTreeNode<Key, Value>* insertHelper(BinaryTreeNode<Key, Value>*, const Key& key, const Value& value);

    BinaryTreeNode<Key, Value>* removeHelper(BinaryTreeNode<Key, Value>*, const Key& key, BinaryTreeNode<Key, Value>*& pNode);

    BinaryTreeNode<Key, Value>* deleteMin(BinaryTreeNode<Key, Value>*, BinaryTreeNode<Key, Value>*&);
    int findHelper(BinaryTreeNode<Key, Value>*, const Key& key, Value& value);

    int heightHelper(BinaryTreeNode<Key, Value>*);

private:
    BinaryTreeNode<Key, Value> *mRoot;
    int nodeCnt;
};

#include "binarysearchtree.cpp"

#endif /* end of include guard: BINARYSEARCHTREE_H */

     * @param   BinaryTreeNode  子树的根节点
