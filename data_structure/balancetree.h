#include "binarysearchtree.h"

template<class Key, class Value>
class BalanceTree : BinarySearchTree<Key, Value>
{
    BalanceTree(const Key& key, const Value& value) : BinarySearchTree<Key, Value>(key, value) {};
protected:

    /**
     * @brief 子树左旋
     *
     * @param   BinaryTreeNode 子树的根节点
     *
     * @returns   子树新的根节点
     */
    virtual BinaryTreeNode<Key, Value>* leftRotate(BinaryTreeNode<Key, Value>*);

    /**
     * @brief 子树右旋
     *
     * @param   BinaryTreeNode 子树的根节点
     *
     * @returns   子树新的根节点
     */
    virtual BinaryTreeNode<Key, Value>* rightRotate(BinaryTreeNode<Key, Value>*);
};
