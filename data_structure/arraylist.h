/**
 * @file arraylist.h
 * @brief 锟斤拷锟斤拷ArrayList锟斤拷
 * @author jiaoew
 * @version 0.1
 * @date 2013-11-01
 */
#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include "list.h"


/**
 * @brief 锟斤拷锟斤拷锟斤拷锟斤拷实锟街碉拷锟叫憋拷
 *
 * @tparam T
 */
template<class T>
class ArrayList: public List<T>
{
public:
    ArrayList(int size = 10) {
        this->mMaxSize = 10;
        this->mListSize = this->mIndex = 0;
        this->mData = new T[size];
    }
    virtual ~ArrayList() {
        delete[] this->mData;
    }
    
    //@override
    void clear() {
        delete[] this->mData;
        this->mIndex = this->mListSize = 0;
        this->mData = new T[this->mMaxSize];
    }

    //@override
    int insert(const T&);

    //@override
    int append(const T&);

    //@override
    int remove(T&);

    //@override
    void setStart() {
        this->mIndex = 0;
    }

    //@override
    void setEnd() {
        this->mIndex = this->mListSize;
    }

    //@override
    void prev() { 
        if (this->mIndex != 0) {
            this->mIndex--;
        }
    }

    //@override
    void next() { 
        if (this->mIndex < this->mListSize - 1) {
            this->mIndex++;
        }
    }

    //@override
    int leftLength() {
        return this->mIndex;
    }

    //@override
    int rightLength() {
        return this->mListSize - this->mIndex;
    }

    //@override
    int setPos(const int pos) {
        if (pos < 0 || pos > this->mListSize - 2)  {
            return -1;
        }
        this->mIndex = pos;
        return 0;
    }

    //@override
    int getValue(T& elem) {
        if (this->rightLength() == 0) {
            return -1;
        }
        elem = this->mData[this->mIndex];
        return 0;
    }

    //@override
    int toString(std::string&);

private:
    int mListSize;
    int mMaxSize;
    int mIndex;
    T* mData;
};

#include "arraylist.cpp"
#endif /* end of include guard: ARRAYLIST_H */
