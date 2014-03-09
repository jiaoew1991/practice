/*
 *        File: knapsack.cpp
 *       Brief: 背包问题
 *  Created on: 2013年11月18日
 *      Author: jiaoew
 *	   Version: v0.1
 *      
 */

#include "common/error_code.h"
#include "common/log.h"
#include "common/string_util.h"
#include <gtest/gtest.h>
#include <vector>

Logger logger = log4cplus::Logger::getInstance("knapsack");

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

TreeNode* binarytreeInsert(TreeNode* node, int value, int& rtn)
{
	if (node == NULL)
	{
		node = new TreeNode(value);
		rtn = 1;
	}
	else if (value > node->value)
	{
		node->right = binarytreeInsert(node->right, value, rtn);
	}
	else if (value < node->value)
	{
		node->left = binarytreeInsert(node->left, value, rtn);
	} 
    else 
    {
        rtn = 0;
    }
	return node;
}

int knapsack(int* goodsArray, int goodsLen, int sackSize)
{
	TreeNode* root = NULL;
	std::vector<int> rtnVector;
	for (int i = 0; i < goodsLen; ++i)
	{
		int rtn = 0;
		root = binarytreeInsert(root, goodsArray[i], rtn);
		if (rtn)
		{
			rtnVector.push_back(goodsArray[i]);
		}
		for (int j = 0, len = rtnVector.size() - 1; j < len; ++j)
		{
			root = binarytreeInsert(root, goodsArray[i] + rtnVector[j], rtn);
			if (rtn)
			{
				rtnVector.push_back(goodsArray[i] + rtnVector[j]);
			}
		}
	}
    LOG4CPLUS_DEBUG(logger, toStringList<int>(rtnVector));
	for (size_t i = 0; i < rtnVector.size(); ++i)
	{
		if (sackSize == rtnVector[i])
		{
			return 1;
		}
	}
	return 0;
}

TEST(recursive, knapsack)
{
    int testData[] = { 2,3, 5, 14, 9, 6};
    //int testData[] = { 2,3, 5 };
    int dataLen = sizeof testData / sizeof testData[0];
    int rtn = knapsack(testData, dataLen, 14);
    EXPECT_EQ(rtn, 1);
    rtn = knapsack(testData, dataLen, 25);
    EXPECT_EQ(rtn, 1);
    rtn = knapsack(testData, dataLen, 38);
    EXPECT_EQ(rtn, 0);
}

int main(int argc, char **argv)
{
    INIT_LOG("knapsack");
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
