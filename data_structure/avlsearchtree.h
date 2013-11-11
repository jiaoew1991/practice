/**
 * @file avlsearchtree.h
 * @brief define interface for AVL tree
 * @author jiaoew
 * @version 0.1
 * @date 2013-11-10
 */
#include "balancetree.h"

/**
 * @brief define and implement AVLTreeNode class, it's the node of AVL tree
 *
 * @tparam Key      key type
 * @tparam Value    data type
 */
template<typename Key, typename Value>
class AVLTreeNode : TreeNode<Key, Value>
{
public:
    AVLTreeNode(const Key& key, const Value& value) : TreeNode<Key, Value>(key, value)
    {
        left = right = NULL;
        height = 0;
    }
    virtual ~AVLTreeNode() 
    {
        left = right = NULL;
    }

public:
    AVLTreeNode<Key, Value>* left;  // left child 
    AVLTreeNode<Key, Value>* right; // right child

    int height;                     // height of the subtree
};

/**
 * @brief define AVLSearchTree interface
 *
 * @tparam Key      key type
 * @tparam Value    value type
 */
template<class Key, class Value>
class AVLSearchTree : BalanceTree<Key, Value>
{
public:
    AVLSearchTree()
    {
        mRoot = NULL;
        nodeCnt = 0;
    }
    virtual ~AVLSearchTree()
    {
        clearHelper(mRoot);
    }

private:
    AVLTreeNode<Key, Value>* insertHelper(AVLTreeNode<Key, Value>*, const Key&, const Value&);

    AVLTreeNode<Key, Value>* removeHelper(AVLTreeNode<Key, Value>*, const Key&, AVLTreeNode<Key, Value>*&);
private:
    AVLTreeNode<Key, Value>* mRoot;
    int nodeCnt;
};
