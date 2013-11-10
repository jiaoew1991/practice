/*
 * LinkedList_test.cpp
 *
 *  Created on: 2013年11月1日
 *      Author: jiaoew
 */

#include "linkedlist.h"
#include <gtest/gtest.h>
#include <iostream>

TEST(normalTest, testInt)
{
    LinkedList<int> ll;
    for (int i = 0; i < 20; i++) {
        ll.append(i);
    }
    EXPECT_EQ(ll.leftLength(), 0);
    EXPECT_EQ(ll.rightLength(), 20);
    int value;
    ll.getValue(value);
    EXPECT_EQ(value, 0);

    EXPECT_EQ(ll.setPos(22), URANUS_INDEX_OUT_ARRAY);

    ll.setPos(5);
    ll.getValue(value);
    EXPECT_EQ(value, 5);

    ll.next();
    ll.next();
    ll.getValue(value);
    EXPECT_EQ(value, 7);

    ll.prev();
    ll.getValue(value);
    EXPECT_EQ(value, 6);
    
    ll.setEnd();
    ll.getValue(value);
    EXPECT_EQ(value, 6);

    ll.setStart();
    ll.getValue(value);
    EXPECT_EQ(value, 0);
    
    ll.clear();
    EXPECT_EQ(ll.leftLength(), 0);
    EXPECT_EQ(ll.rightLength(), 0);
}
TEST(outOfBundle, testInt)
{
    LinkedList<int> ll;
    for (int i = 0; i < 15; i++) {
        ll.append(i);
    }
    ll.insert(4);
    ll.setPos(1);
    ll.prev();
    int value;
    ll.getValue(value);
    EXPECT_EQ(value, 4);

    ll.setPos(13);
    for (int i = 0; i < 8; i++) {
        int rst = ll.remove(value);
        if (i < 3) {
            EXPECT_EQ(value, 12+i);
        } else {
            EXPECT_EQ(rst, URANUS_INDEX_OUT_ARRAY);
        }
    }
}
int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
