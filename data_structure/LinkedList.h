/**
 * @file LinkedList.h
 * @brief define linkedlist based on link
 * @author jiaoew
 * @version 0.1
 * @date 2013-11-03
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include "list.h"

template<class T>
class LinkedList: public List<T>
{
public:
	LinkedList() 
    {
        this->init();
    }
	virtual ~LinkedList()
    {
        this->removeAll();
    }
    /**
     * @override
     */
    void clear()
    {
        this->removeAll();
        this->init();
    }
    /**
     * @override
     */
    int insert(const T& elem);
    /**
     * @override
     */
    int append(const T& elem);
    /**
     * @override
     */
    int remove(T& elem);

    /**
     * @override
     */
    void setStart()
    {
        mIndex = mHead;
        rightCnt += leftCnt;
        leftCnt = 0;
    }
    /**
     * @override
     */
    void setEnd()
    {
        mIndex = mTail;
        leftCnt += rightCnt;
        rightCnt = 0;
    }
    /**
     * @override
     */
    void prev();
    /**
     * @override
     */
    void next()
    {
        if (mIndex != mTail)
        {
            mIndex = mIndex->next;
            rightCnt--;
            leftCnt++;
        }
    }
    /**
     * @override
     */
    int leftLength() 
    {
        return leftCnt;
    }
    /**
     * @override
     */
    int rightLength()
    {
        return rightCnt;
    }
    /**
     * @override
     */
    int setPos(const int pos);
    /**
     * @override
     */
    int getValue(T& elem) 
    {
        if (rightCnt == 0)
        {
            return URANUS_EMPTY_ARRAY;
        }
        elem = mIndex->next->value;
        return URANUS_SUCCESS;
    }

    /**
     * @override
     */
    friend std::ostream& operator<< (std::ostream& os, LinkedList<T> &tList) 
    {
        LinkedNode<T> *pWalker = tList.mHead->next;
        os << "[";
        while (pWalker)
        {
            os << pWalker->value;
            if (pWalker != tList.mTail)
            {
                os << ","; 
            }
            pWalker = pWalker->next;
        }
        os << "]" << std::endl;
        return os;
    }
    template<class U>
    class LinkedNode
    {
    public:
        LinkedNode(const U& pValue, LinkedNode<U>* pNext = NULL) 
        {
            value = pValue;
            next = pNext;
        }
        LinkedNode(LinkedNode<U>* pNext = NULL) 
        {
            next = pNext;
        }
        virtual ~LinkedNode() 
        {
            value = 0;
            next = NULL;
        }
        LinkedNode<U> *next;
        U value;
    };
private:
    void removeAll()
    {
        LinkedNode<T> *tmp = this->mHead;
        while (mHead != NULL) {
            mHead = mHead->next;
            delete tmp;
            tmp = mHead;
        }
    }
    void init()
    {
        mIndex = mHead = mTail = new LinkedNode<T>;
        leftCnt = rightCnt = 0;
    }
private:
    LinkedNode<T> *mHead; //链表头指针
    LinkedNode<T> *mTail; //链表尾指针，指向最后一个元素
    LinkedNode<T> *mIndex; //指向当前元素
    int leftCnt; //左半部分的长度，不包含当前元素
    int rightCnt; //右半部分的长度，包含当前元素
};

#include "linkedlist.cpp"

#endif /* LINKEDLIST_H_ */
