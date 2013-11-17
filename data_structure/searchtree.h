/**
 * @file searchtree.h
 * @brief 定义搜索树SearchTree接口
 * @author jiaoew
 * @version 0.1
 * @date 2013-11-09
 */
#include "common/error_code.h"
#include "common/log.h"

template<class Key, class Value>
class TreeNode
{
public:
	TreeNode(const Key& key, const Value& value)
	{
		mKey = key;
		mData = value;
	}
	virtual ~TreeNode()
	{
	}
	/**
	 * @brief @Setter
	 *
	 * @param   value
	 */
	virtual void setValue(const Value& value)
	{
		mData = value;
	}

	/**
	 * @brief @Getter
	 *
	 * @param   value
	 */
	virtual void value(Value& value)
	{
		value = mData;
	}

	/**
	 * @brief @Setter
	 *
	 * @param   key
	 */
	virtual void setKey(const Key& key)
	{
		mKey = key;
	}

	/**
	 * @brief @Getter
	 *
	 * @param   key
	 */
	virtual void key(Key& key)
	{
		key = mKey;
	}

	/**
	 * @brief compare key with mKey
	 *
	 * @param   key
	 *
	 * @returns     key > mKey return 1
	 *              key < mKey return -1
	 *              key == mKey return 0;
	 */
	virtual int keyEquals(const Key& key)
	{
		if (key == mKey)
		{
			return 0;
		}
		else if (key > mKey)
		{
			return 1;
		}
		else
		{
			return -1;
		}
	}

private:
	Value mData;
	Key mKey;

};
/**
 * @brief 搜索树接口
 *
 * @tparam Key      key类型
 * @tparam Value    存储值的类型
 */
template<class Key, class Value>
class SearchTree
{
public:
	/**
	 * @brief 清空树
	 */
	virtual void clear() = 0;

	/**
	 * @brief 插入一个新的节点
	 *
	 * @param   key     节点的➹
	 * @param   elem    节点的valuec
	 *
	 * @returns   URANUS_SUCCESS for success others for failed
	 */
	virtual int insert(const Key& key, const Value& elem) = 0;

	/**
	 * @brief 删除一个节点
	 *
	 * @param   key     通过key删除节点
	 * @param   value   该节点的值
	 *
	 * @returns   URANUS_SUCCESS for success others for failed
	 */
	virtual int remove(const Key& key, Value& value) = 0;

	/**
	 * @brief  通过key找到相应的值
	 *
	 * @param   key
	 * @param   value
	 *
	 * @returns   URANUS_SUCCESS for success others for failed
	 */
	virtual int find(const Key& key, Value& value) = 0;

	/**
	 * @brief 得到树大小
	 *
	 * @returns
	 */
	virtual int size() = 0;

	/**
	 * @brief 树的高度
	 *
	 * @returns
	 */
	virtual int height() = 0;

};
