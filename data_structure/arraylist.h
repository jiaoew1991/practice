/**
 * @file arraylist.h
 * @brief define arraylist class which is extended from list
 * @author jiaoew
 * @version 0.1
 * @date 2013-11-03
 */
#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include "list.h"


/**
 * @brief 定义模版类arraylist，基于数组实现的列表
 *
 * @tparam T
 */
template<class T>
class ArrayList: public List<T>
{
    public:
        ArrayList(int size = 10)
        {
            this->mMaxSize = size;
            this->mListSize = this->mIndex = 0;
            this->mData = new T[size];
        }
        virtual ~ArrayList()
        {
            delete[] this->mData;
        }

        //@override
        void clear()
        {
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
        void setStart()
        {
            this->mIndex = 0;
        }

        //@override
        void setEnd()
        {
            this->mIndex = this->mListSize;
        }

        //@override
        void prev()
        { 
            if (this->mIndex != 0)
            {
                this->mIndex--;
            }
        }

        //@override
        void next()
        { 
            if (this->mIndex < this->mListSize - 1)
            {
                this->mIndex++;
            }
        }

        //@override
        int leftLength()
        {
            return this->mIndex;
        }

        //@override
        int rightLength()
        {
            return this->mListSize - this->mIndex;
        }

        //@override
        int setPos(const int pos)
        {
            if (pos < 0 || pos > this->mListSize - 1) 
            {
                return URANUS_INDEX_OUT_ARRAY;
            }
            this->mIndex = pos;
            return URANUS_SUCCESS;
        }

        //@override
        int getValue(T& elem)
        {
            if (this->rightLength() == 0)
            {
                return  URANUS_INDEX_OUT_ARRAY;
            }
            elem = this->mData[this->mIndex];
            return URANUS_SUCCESS;
        }

        //@override
        friend std::ostream& operator<<(std::ostream& os, ArrayList<T>& tList)
        {
            os << "[";
            for (int i = 0; i < tList.mListSize; i++)
            {
                os << tList.mData[i];
                if (i != tList.mListSize - 1)
                {
                    os << ",";
                }
            }
            os << "]";
            return os;
        }

    private:
        int mListSize;
        int mMaxSize;
        int mIndex;
        T* mData;
};

#include "arraylist.cpp"
#endif /* end of include guard: ARRAYLIST_H */
