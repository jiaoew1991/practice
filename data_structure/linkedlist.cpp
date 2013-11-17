/**
 * @file LinkedList.cpp
 * @brief 实现linkedlist接口
 * @author jiaoew
 * @version 0.1
 * @date 2013-11-07
 */
#include "linkedlist.h"

template<class T>
int LinkedList<T>::insert(const T& elem)
{
    mIndex->next = new LinkedNode<T>(elem, mIndex->next);
    if (mTail == mIndex) {
        mTail = mIndex->next;
    }
    rightCnt++;
    return URANUS_SUCCESS;
}

template<class T>
int LinkedList<T>::append(const T& elem)
{
    mTail = mTail->next = new LinkedNode<T>(elem);
    rightCnt++;
    return URANUS_SUCCESS;
}

template<class T>
int LinkedList<T>::remove(T& elem)
{
    if (mIndex->next == NULL) {
        return URANUS_INDEX_OUT_ARRAY;
    }
    elem = mIndex->next->value;
    LinkedNode<T> *pTmp = mIndex->next;
    mIndex->next = pTmp->next;
    if (mTail == pTmp) {
        mTail = mIndex;
    }
    delete pTmp;
    rightCnt--;
    return URANUS_SUCCESS;
}
template<class T>
int LinkedList<T>::setPos(const int pos)
{
    if (pos < 0) {
        return URANUS_INDEX_LESS_THAN_ZERO;
    }
    if (pos > rightCnt + leftCnt) {
        return URANUS_INDEX_OUT_ARRAY;
    }
    mIndex = mHead;
    for (int i = 0; i < pos; i++) {
        mIndex = mIndex->next;
    }
    return URANUS_SUCCESS;
}
template<class T>
void LinkedList<T>::prev()
{
    LinkedNode<T> *pWalker = mHead;
    while (pWalker->next != mIndex) {
        pWalker = pWalker->next;
    }
    mIndex = pWalker;
    leftCnt--;
    rightCnt++;
}
