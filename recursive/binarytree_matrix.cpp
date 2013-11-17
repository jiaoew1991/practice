/*
 * binarytree_matrix.cpp
 *
 *  Created on: 2013年11月17日
 *      Author: jiaoew
 */
#include "common/error_code.h"
#include "common/log.h"
#include <gtest/gtest.h>

Logger logger = log4cplus::Logger::getInstance("binarymatrix");

struct TreeNode
{
	TreeNode* left;
	TreeNode* right;
	int value;
	int index;
	TreeNode(int v)
	{
		value = v;
		left = right = NULL;
		index = 0;
	}
};
class Matrix
{
public:
	Matrix(int n)
	{
		mDimension = n;
		mData = new int*[n];
		for (int i = 0; i < n; ++i)
		{
			mData[i] = new int[n];
			for (int j = 0; j < n; ++j)
			{
				mData[i][j] = 0;
			}
		}
	}
	~Matrix()
	{
		if (mData)
		{
			for (int i = 0; i < mDimension; ++i)
			{
				if (mData[i])
				{
					delete[] mData[i];
				}
			}
			delete[] mData;
		}
	}
	int setValue(const int i, const int j, const int value)
	{
		if (i >= mDimension || j >= mDimension)
		{
			return URANUS_INDEX_OUT_ARRAY;
		}
		mData[i][j] = value;
		mData[j][i] = value;
		mData[i][j] = value;
		return URANUS_SUCCESS;
	}

	friend std::ostream& operator<<(std::ostream& os, Matrix& matrix)
	{
		for (int i = 0; i < matrix.mDimension; ++i)
		{
			os << "[";
			for (int j = 0; j < matrix.mDimension; ++j)
			{
				os << matrix.mData[i][j];
				if (j != matrix.mDimension - 1)
				{
					os << ",";
				}
			}
			os << "]\n";
		}
		return os;
	}

private:
	int mDimension;
	int** mData;
};


TreeNode* binarytreeInsert(TreeNode* node, int value, int index)
{
	if (node == NULL)
	{
		node = new TreeNode(value);
		node->index = index;
	}
	else if (value > node->value)
	{
		node->right = binarytreeInsert(node->right, value, index);
	}
	else if (value < node->value)
	{
		node->left = binarytreeInsert(node->left, value, index);
	}
	return node;
}

void binaryMatrixHelper(TreeNode* treeLeft, TreeNode* treeRight, int baseLength,
		Matrix& matrix, bool isRecurisve = true)
{
	if (!treeLeft || !treeRight)
	{ // 左树为空，或右树为空则不必修改matrix
		return;
	}
	matrix.setValue(treeLeft->index, treeRight->index, baseLength + 1);
	binaryMatrixHelper(treeLeft->left, treeRight, baseLength + 1, matrix,
			isRecurisve);
	binaryMatrixHelper(treeLeft->right, treeRight, baseLength + 1, matrix,
			isRecurisve);
	if (isRecurisve)
	{
		binaryMatrixHelper(treeLeft, treeRight->left, baseLength + 1, matrix,
				isRecurisve);
		binaryMatrixHelper(treeLeft, treeRight->right, baseLength + 1, matrix,
				isRecurisve);
	}
}

void binarytreeMatrix(TreeNode* treeRoot, Matrix& oMatrix)
{
	if (treeRoot == NULL)
	{
		return;
	}
	LOG4CPLUS_DEBUG(logger, "tree value");
	LOG4CPLUS_DEBUG(logger, treeRoot->value);
	binarytreeMatrix(treeRoot->left, oMatrix);
	binarytreeMatrix(treeRoot->right, oMatrix);
	binaryMatrixHelper(treeRoot->left, treeRoot, 0, oMatrix, false);
	binaryMatrixHelper(treeRoot->right, treeRoot, 0, oMatrix, false);
	binaryMatrixHelper(treeRoot->left, treeRoot->right, 1, oMatrix);
	LOG4CPLUS_DEBUG(logger, "left right finished");
}

TEST(recurive, binarytreematrix)
{
	LOG4CPLUS_DEBUG(logger, "test it");
	TreeNode* root = NULL;
	int testData[] =
	{ 9, 23, 3, 34, 12, 8, 1, 2, 10, 14, 18, 4 };
	int dataLength = sizeof testData / sizeof testData[0];
	LOG4CPLUS_DEBUG(logger, "init binary tree");
	for (int i = 0; i < dataLength; ++i)
	{
		root = binarytreeInsert(root, testData[i], i);
	}
	LOG4CPLUS_DEBUG(logger, "init matrix");
	Matrix matrix(dataLength);
	LOG4CPLUS_DEBUG(logger, "change matrix");
	binarytreeMatrix(root, matrix);
	LOG4CPLUS_DEBUG(logger, "change matrix finish");
	std::cout << matrix << std::endl;
}

int main(int argc, char **argv)
{
	INIT_LOG("matrix");
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
