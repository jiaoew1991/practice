#include "binarysearchtree.h"

template<class Key, class Value>
void BinarySearchTree<Key, Value>::clearHelper(
		BinaryTreeNode<Key, Value>* subRoot)
{
	if (subRoot == NULL)
	{
		return;
	}
	else
	{
		clearHelper(subRoot->leftChild());
		clearHelper(subRoot->rightChild());
		delete subRoot;
	}
}

template<class Key, class Value>
BinaryTreeNode<Key, Value>* BinarySearchTree<Key, Value>::insertHelper(
		BinaryTreeNode<Key, Value>* subRoot, const Key& key, const Value& value)
{
	if (subRoot == NULL)
	{
		createTreeNode(key, value, subRoot);
	}
	else if (subRoot->keyEquals(key) > 0)
	{
		subRoot->setRightChild(insertHelper(subRoot->rightChild(), key, value));
	}
	else if (subRoot->keyEquals(key) <= 0)
	{
		subRoot->setLeftChild(insertHelper(subRoot->leftChild(), key, value));
	}
	return subRoot;
}

template<class Key, class Value>
BinaryTreeNode<Key, Value>* BinarySearchTree<Key, Value>::deleteMin(
		BinaryTreeNode<Key, Value>* subRoot, BinaryTreeNode<Key, Value>*& pNode)
{
	if (subRoot->leftChild())
	{ // find the minest
		subRoot->setLeftChild(deleteMin(subRoot->leftChild(), pNode));
		return subRoot;
	}
	else
	{  // find it! and return it's right;
		pNode = subRoot;
		return subRoot->rightChild();
	}
}

template<class Key, class Value>
BinaryTreeNode<Key, Value>* BinarySearchTree<Key, Value>::removeHelper(
		BinaryTreeNode<Key, Value>* subRoot, const Key& key,
		BinaryTreeNode<Key, Value>*& pNode)
{
	if (subRoot == NULL)
	{
		return NULL;
	}
	else if (subRoot->keyEquals(key) > 0)
	{
		subRoot->setRightChild(removeHelper(subRoot->rightChild(), key, pNode));
	}
	else if (subRoot->keyEquals(key) < 0)
	{
		subRoot->setLeftChild(removeHelper(subRoot->leftChild(), key, pNode));
	}
	else
	{ // remove target is current node;
		BinaryTreeNode<Key, Value> *pTmp;
		pNode = subRoot;
		if (subRoot->leftChild() == NULL)
		{ // left child is null,
			subRoot = subRoot->rightChild();
		}
		else if (subRoot->rightChild() == NULL)
		{
			subRoot = subRoot->leftChild();
		}
		else
		{ // both children are not null, remove it's successor
			Value rTmpValue;
			subRoot->value(rTmpValue);
			subRoot->setRightChild(deleteMin(subRoot->rightChild(), pTmp));

			Value rPValue;
			Key rPKey;
			pTmp->value(rPValue);
			pTmp->key(rPKey);
			subRoot->setValue(rPValue);
			subRoot->setKey(rPKey);
			pTmp->setValue(rTmpValue);
			pNode = pTmp;
		}

	}
	return subRoot;
}

template<class Key, class Value>
int BinarySearchTree<Key, Value>::findHelper(
		BinaryTreeNode<Key, Value>* subRoot, const Key& key, Value& value)
{
	if (subRoot == NULL)
	{
		return URANUS_EMPTY_TREE;
	}
	else if (subRoot->keyEquals(key) > 0)
	{
		return findHelper(subRoot->rightChild(), key, value);
	}
	else if (subRoot->keyEquals(key) < 0)
	{
		return findHelper(subRoot->leftChild(), key, value);
	}
	else
	{
		subRoot->value(value);
		return URANUS_SUCCESS;
	}
}

template<class Key, class Value>
int BinarySearchTree<Key, Value>::heightHelper(
		BinaryTreeNode<Key, Value>* subRoot)
{
	if (subRoot == NULL)
	{
		return 0;
	}
	int leftHeight = heightHelper(subRoot->leftChild());
	int rightHeight = heightHelper(subRoot->rightChild());
	return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
}

template<class Key, class Value>
std::ostream& BinarySearchTree<Key, Value>::outputHelper(std::ostream& os,
		BinaryTreeNode<Key, Value>* subRoot, int tabSize)
{
	if (subRoot == NULL)
	{
		return os;
	}
	for (int i = 0; i < tabSize; i++)
	{
		os << "  ";
	}
	Value value;
	subRoot->value(value);
	os << value << std::endl;
	outputHelper(os, subRoot->leftChild(), tabSize + 1);
	outputHelper(os, subRoot->rightChild(), tabSize + 1);
	return os;
}
