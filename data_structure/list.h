/**
 * @file list.h
 * @brief 定义list抽象接口
 * @author jiaoew
 * @version 0.1
 * @date 2013-11-01
 */
#ifndef LIST_H
#define LIST_H
#include "common/error_code.h"

template<class T>
class List
{
public:

	/**
	 * @brief 清空列表
	 */
	virtual void clear() = 0;
	/**
	 * @brief 向列表开头中插入元素
	 *
	 * @param   T element to be inserted
	 *
	 * @returns 1 for success others for error
	 */
	virtual int insert(const T&) = 0;
	/**
	 * @brief 向列表最后添加元�?
	 * @param   T element to be appended
	 *
	 * @returns 1 for success others for error
	 */
	virtual int append(const T&) = 0;
	/**
	 * @brief 删除并返回列表最后一个元�?
	 * @param   T element removed
	 *
	 * @returns 1 for success others for error
	 */
	virtual int remove(T&) = 0;
	/**
	 * @brief 设置到列表的�?��
	 */
	virtual void setStart() = 0;
	/**
	 * @brief 放置到列表末�?
	 */
	virtual void setEnd() = 0;
	/**
	 * @brief 向前移动�?��位置
	 */
	virtual void prev() = 0;
	/**
	 * @brief 向后移动�?��位置
	 */
	virtual void next() = 0;
	/**
	 * @brief 左边部分的长�?
	 * @returns 当前位置左边元素个数
	 */
	virtual int leftLength() = 0;
	/**
	 * @brief 右部的长�?
	 * @returns 当前位置右边元素个数
	 */
	virtual int rightLength() = 0;
	/**
	 * @brief 设置当前位置
	 *
	 * @param   pos
	 *
	 * @returns 1 for success others for error
	 */
	virtual int setPos(const int pos) = 0;
	/**
	 * @brief 得到当前元素�?
	 * @param   T returns
	 *
	 * @returns 1 for success others for error
	 */
	virtual int getValue(T&) = 0;
};

#endif /* end of include guard: LIST_H */
