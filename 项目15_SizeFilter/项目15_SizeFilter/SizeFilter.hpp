#pragma once
#ifndef _SIZEFILTER_
#define _SIZEFILTER_

#include <iostream>
#include <set>

using namespace std;

template <class _Ty,
	class _Container = set<_Ty>>

	class sizeFilter {
	public:

		typedef sizeFilter<_Ty, _Container> _Myt;
		typedef typename _Container::size_type size_type;
		typedef typename _Container::value_type value_type;

		sizeFilter() :c() {
			// 默认构造函数, 初始化内置容器
		}

		sizeFilter(const _Myt& _Right) :c(_Right.c) {
			// 构造函数, 通过指定特定的sizeFilter容器构造
		}

		sizeFilter(const _Container& _Cont) :c(_Cont.c) {
			//构造函数, 通过指定特定的容器构造
		}

		_Myt& operator=(const _Myt& _Right) { //A = B = C = D
			//使用另一个sizeFilter 赋值
			this->c = _Right.c;
			return (*this);
		}

		bool empty() const {
			//测试 SizeFilter 是否为空
			return (c.empty());
		}

		size_type size() const {
			//测试SizeFilter的长度
			return (c.size());
		}

		bool insert(const value_type& _Val) {
			//插入元素
			pair<_Container::iterator, bool> ret = c.insert(_Val);
			if (ret.second) {
				cout << "插入" << _Val << "成功!" << endl;
				return true;
			}
			else {
				cout << "插入" << _Val << "失败!" << endl;
				return false;
			}

		}

		bool erase(const value_type& _val) {
			// 擦除元素
			if (c.erase(_val) > 0) {
				return true;
			}
			else {
				return false;
			}
		}

		pair<value_type, bool> getMin() {
			//获取最小值
			pair<value_type, bool> ret;
			typename _Container::iterator min = c.begin();

			if (min != c.end()) {	//存在最小值
				ret.first = *min;
				ret.second = true;
				return ret;
			}
			else {
				ret.second = false;
				return ret;
			}
		}

		pair<value_type, bool> getMax() {
			//获取最大值
			pair<value_type, bool> ret;
			typename _Container::iterator end = c.end();
			if (c.size()>0) {	//存在最小值
				ret.first = *(--end);
				ret.second = true;
				return ret;
			}
			else {
				ret.second = false;
				return ret;
			}
		}

	protected:
		_Container c;
};


#endif // !_SIZEFILTER_
