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
	LinkedList();
	virtual ~LinkedList();
private:
    void removeAll()
    {
        
    }
private:
    class LinkedNode<T> {
        T value;
        LinkedNode<T> *next;
    };
    LinkedNode<T> *mHead;
    LinkedNode<T> *mIndex;
};

#include "linkedlist.cpp"
#endif /* LINKEDLIST_H_ */
