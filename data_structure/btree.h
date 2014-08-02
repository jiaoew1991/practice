#ifndef BTREE_H
#define BTREE_H

#include "searchtree.h"
#include "arraylist.h"

template<class Key, class Value>
class BTreeNode
{
public:
    BTreeNode(const int degree)
    {
        mDegree = degree;
        mKeys = new ArrayList<Key*>(degree * 2 - 1);
        mChildNodes = new ArrayList<BTreeNode<Key, Value>*>(degree * 2);

        isLeaf = true;
    }
    virtual ~BTreeNode() 
    {
        if (mKeys)
        {
            delete mKeys;
        }
        if (mChildNodes) 
        {
            delete mChildNodes;
        }
    }


private:
    ArrayList<Key*>* mKeys;
    ArrayList<BTreeNode<Key, Value>*>* mChildNodes;

    int mDegree;
    bool isLeaf;
};

template<class Key, class Value>
class BTree : public SearchTree<Key, Value>
{
public:
    BTree(int degree) : SearchTree<Key, Value>()
    {
        mDegree = degree;
        mRoot = NULL;
    }
    virtual ~BTree()
    {
        mRoot = NULL;
    }

    /*
     * @override
     */
    void clear()
    {
        this->clearHelper(mRoot);
        mSize = 0;
    }

    /*
     * @override
     */
    int insert(const Key& key, const Value& elem)
    {
        mRoot = insertHelper(mRoot, key, elem);
        mSize++;
        return URANUS_SUCCESS;
    }

    /*
     * @override
     */
    int remove(const Key& key, Value& value)
    {
        BTreeNode<Key, Value>* pNode = NULL;
        mRoot = removeHelper(mRoot, key, pNode);
        if (!pNode)
        {
            return URANUS_FIND_NOTHING;
        }
        pNode->value(value);
        delete pNode;
        mSize--;
        return URANUS_SUCCESS;
    }

    /*
     * @override
     */
    int find(const Key& key, Value& value)
    {
        return findHelper(mRoot, key, value);
    }

    /*
     * @override
     */
    int size()
    {
        return mSize;
    }

    /*
     * @override
     */
    int height()
    {
        return heightHelper(mRoot);
    }

    friend std::ostream& operator<<(std::ostream& os, BTree<Key, Value>& tree)
    {
        return tree.outputHelper(os, tree.mRoot);
    }
protected:

    virtual std::ostream& outputHelper(std::ostream& os, BTree<Key, Value>* subRoot);

    virtual int clearHelper(BTree<Key, Value>* subRoot);

    virtual int findHelper(BTree<Key, Value>* subRoot, const Key& key, Value& value);

    virtual BTree<Key, Value>* insertHelper(BTree<Key, Value>* subRoot, const Key& key, const Value& value);

    virtual BTree<Key, Value>* removeHelper(BTree<Key, Value>* subRoot, const Key& key, Value& value);

    virtual int heightHelper(BTree<Key, Value>*);
private:
    int mDegree;
    int mSize;

    BTreeNode<Key, Value>* mRoot;
};

#include "btree.cpp"

#endif /* end of include guard: BTREE_H */
