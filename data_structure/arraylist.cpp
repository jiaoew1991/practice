/**
 * @file arraylist.cpp
 * @brief 实现arraylist接口 
 * @author jiaoew
 * @version 0.1
 * @date 2013-11-03
 */
#include "arraylist.h"

template<class T>
int ArrayList<T>::insert(const T& elem)
{
    if (this->mListSize == this->mMaxSize)
    {
        return URANUS_INDEX_OUT_ARRAY;
    }
    for (int i = this->mListSize; i > this->mIndex; i--)
    {
        this->mData[i] = this->mData[i -1];
    }
    this->mData[this->mIndex] = elem;
    this->mListSize ++;
    this->mIndex ++;
    return URANUS_SUCCESS;
}

template<class T>
int ArrayList<T>::append(const T& elem)
{
    if (this->mListSize == this->mMaxSize)
    {
        return URANUS_INDEX_OUT_ARRAY;
    }
    this->mData[this->mListSize] = elem;
    this->mListSize ++;
    return URANUS_SUCCESS;
}

template<class T>
int ArrayList<T>::remove(T& elem)
{
    if (this->mListSize == 0)
    {
        return URANUS_EMPTY_ARRAY;
    }
    elem = this->mData[this->mIndex];
    for (int i = this->mIndex; i < this->mListSize; i++)
    {
        this->mData[i] = this->mData[i+1];
    }
    return URANUS_SUCCESS;
}

