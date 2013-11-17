#include "binarysearchtree.h"

template<class Key, class Value>
class BalanceTree: public BinarySearchTree<Key, Value>
{
public:
	BalanceTree() :
			BinarySearchTree<Key, Value>()
	{
	}

	virtual ~BalanceTree()
	{
	}

protected:

	/**
	 * @brief 子树左旋
	 *
	 * @param   BinaryTreeNode 子树的根节点
	 *
	 * @returns   子树新的根节点
	 */
	virtual BinaryTreeNode<Key, Value>* leftRotate(
			BinaryTreeNode<Key, Value>* subRoot)
	{
		if (subRoot == NULL || subRoot->rightChild() == NULL)
		{
			return subRoot;
		}
		BinaryTreeNode<Key, Value>* pNode = subRoot->rightChild();
		subRoot->setRightChild(pNode->leftChild());
		pNode->setLeftChild(subRoot);
		return pNode;
	}

	/**
	 * @brief 子树右旋
	 *
	 * @param   BinaryTreeNode 子树的根节点
	 *
	 * @returns   子树新的根节点
	 */
	virtual BinaryTreeNode<Key, Value>* rightRotate(
			BinaryTreeNode<Key, Value>* subRoot)
	{
		log4cplus::Logger logger = log4cplus::Logger::getInstance(
				LOG4CPLUS_TEXT("rotate"));

		LOG4CPLUS_DEBUG(logger, "right rotate begin");
		LOG4CPLUS_DEBUG(logger, LOG4CPLUS_TEXT(subRoot));
		if (subRoot == NULL || subRoot->leftChild() == NULL)
		{
			return subRoot;
		}
		BinaryTreeNode<Key, Value>* pNode = subRoot->leftChild();
		subRoot->setLeftChild(pNode->rightChild());
		pNode->setRightChild(subRoot);

		LOG4CPLUS_DEBUG(logger, "right rotate end");
		Key key;
		pNode->key(key);
		LOG4CPLUS_DEBUG(logger, LOG4CPLUS_TEXT(key));
		return pNode;
	}
};
