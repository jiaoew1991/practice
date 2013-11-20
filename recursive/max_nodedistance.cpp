/*
 * max_nodedistance.cpp
 *
 *  Created on: 2013年11月18日
 *      Author: jiaoew
 */

#include <gtest/gtest.h>
#include "common/error_code.h"
#include "common/log.h"

struct TreeNode
{
	TreeNode* left;
	TreeNode* right;
	int value;
	TreeNode(int v)
	{
		value = v;
		left = right = NULL;
	}
};

TreeNode* binarytreeInsert(TreeNode* node, int value)
{
	if (node == NULL)
	{
		node = new TreeNode(value);
	}
	else if (value > node->value)
	{
		node->right = binarytreeInsert(node->right, value);
	}
	else if (value < node->value)
	{
		node->left = binarytreeInsert(node->left, value);
	}
	return node;
}

void binarytreeClear(TreeNode* node)
{
	if (!node)
	{
		return;
	}
	binarytreeClear(node->left);
	binarytreeClear(node->right);
	delete node;
	node = NULL;
}

int maxNodeDistance(TreeNode* treeRoot, int* outTreeHeight)
{
	if (!treeRoot)
	{
		*outTreeHeight = 0;
		return 0;
	}
	int leftHeight = 0;
	int rightHeight = 0;
	int leftDistance = maxNodeDistance(treeRoot->left, &leftHeight);
	int rightDistance = maxNodeDistance(treeRoot->right, &rightHeight);
	*outTreeHeight =
			leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
	int max = leftDistance;
	if (max < rightDistance)
	{
		max = rightDistance;
	}
	if (max < leftHeight + rightHeight)
	{
		max = leftHeight + rightHeight;
	}
	return max;
}

TEST(recursive, maxnodedistance)
{
	TreeNode* root = NULL;
	int testData[] =
	{ 9, 23, 3, 34, 12, 8, 1, 2, 10, 14, 18, 4 };
	int dataLength = sizeof testData / sizeof testData[0];
	for (int i = 0; i < dataLength; ++i)
	{
		root = binarytreeInsert(root, testData[i]);
	}
	int height = 0;
	int rtn = maxNodeDistance(root, &height);
	EXPECT_EQ(rtn, 7);
	EXPECT_EQ(height, 5);
	binarytreeClear(root);

	root = NULL;
	int testData2[] =
	{ 1, 9, 23, 12, 34, 10, 14, 18, 3, 8, 4 };
	dataLength = sizeof testData2 / sizeof testData2[0];
	for (int i = 0; i < dataLength; ++i)
	{
		root = binarytreeInsert(root, testData2[i]);
	}
	rtn = maxNodeDistance(root, &height);
	EXPECT_EQ(rtn, 7);
	EXPECT_EQ(height, 6);
}

int main(int argc, char **argv)
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
