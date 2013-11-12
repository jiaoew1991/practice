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
class BinaryTreeNode : public TreeNode<Key, Value>
{
public:
    BinaryTreeNode(const Key& key, const Value& value) : TreeNode<Key, Value>(key, value)
    {
        right = left = NULL;
    }
    virtual ~BinaryTreeNode() 
    {
        right = left = NULL;
    }

public:
    BinaryTreeNode<Key, Value> *left; // left child node pointer;
    BinaryTreeNode<Key, Value> *right; // right child node pointer;
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
        pNode->value(value);
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

    friend std::ostream& operator<< (std::ostream& os, BinarySearchTree<Key, Value>& tree)
    {
        return tree.outputHelper(os, tree.mRoot, 0);
    }
protected:
    virtual void clearHelper(BinaryTreeNode<Key, Value>*);

    /**
     * @brief 向子树中插入新的节点，并返回子树的根节点
     *
     * @param   BinaryTreeNode  子树的根
     * @param   key             要插入的key
     * @param   value           要插入的value
     *
     * @returns     子树的根节点
     */
    virtual BinaryTreeNode<Key, Value>* insertHelper(BinaryTreeNode<Key, Value>*, const Key& key, const Value& value);

    /**
     * @brief 删除子树的节点，并返回子树的根节点
     *
     * @param   BinaryTreeNode  子树的根
     * @param   key             要删除的节点的key
     * @param   pNode           被删除的节点的指针
     *
     * @returns     子树的根节点
     */
    virtual BinaryTreeNode<Key, Value>* removeHelper(BinaryTreeNode<Key, Value>*, const Key& key, BinaryTreeNode<Key, Value>*& pNode);

    /**
     * @brief 删除子树中key最小的节点
     *
     * @param   BinaryTreeNode  子树的根
     * @param   BinaryTreeNode  被删除的节点的指针
     *
     * @returns     子树的根节点
     */
    virtual BinaryTreeNode<Key, Value>* deleteMin(BinaryTreeNode<Key, Value>*, BinaryTreeNode<Key, Value>*&);

    /**
     * @brief 通过key查找子树
     *
     * @param   BinaryTreeNode  子树的根节点
     * @param   key             要查找的key
     * @param   value           查到的value
     *
     * @returns   URANS_SUCCESS for find it others not
     */
    virtual int findHelper(BinaryTreeNode<Key, Value>*, const Key& key, Value& value);

    /**
     * @brief 获取字数的高度
     *
     * @param   BinaryTreeNode  子树的根节点
     *
     * @returns   子树的高度
     */
    virtual int heightHelper(BinaryTreeNode<Key, Value>*);

    /**
     * @brief 打印子树到输出流
     *
     * @param   os          输出流
     * @param   subRoot     子树的根节点
     * @param   tabSize     要打印的空格数
     *
     * @returns   outpustream
     */
    virtual std::ostream& outputHelper(std::ostream& os, BinaryTreeNode<Key, Value>* subRoot, int tabSize);

    /**
     * @brief 创建新的节点
     *
     * @param   key
     * @param   value
     * @param   pNode
     *
     * @returns   URANUS_SUCCESS for success;
     */
    virtual int createTreeNode(const Key& key, const Value& value, BinaryTreeNode<Key, Value>*& pNode) 
    {
        pNode = new BinaryTreeNode<Key, Value>(key, value);
        return URANUS_SUCCESS;
    }
protected:
    BinaryTreeNode<Key, Value>* mRoot;
    int nodeCnt;
};

#include "binarysearchtree.cpp"

#endif /* end of include guard: BINARYSEARCHTREE_H */
