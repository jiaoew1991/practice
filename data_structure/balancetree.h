#include "searchtree.h"

template<class Key, class Value>
class BalanceTree : SearchTree<Key, Value>
{
public:
    BalanceTree();
    ~BalanceTree();

protected:
    virtual void clearHelper(TreeNode<Key, Value>*);
    
private:
    /* data */
};
