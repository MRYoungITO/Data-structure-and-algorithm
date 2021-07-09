#pragma once
#ifndef _SIZEFILTER_
#define _SIZEFILTER_

#include <iostream>
#include <set>

using namespace std;


template <class _Ty,
	class _Container = set<_Ty>>

	class SizeFilter {

	typedef SizeFilter<_Ty, _Container> _Myt;
	typedef typename _Container::value_type value_type;
	typedef typename _Container::size_type size_type;

	public:

		SizeFilter() :c() {
			//默认构造函数
		}

		SizeFilter(const _Myt& _Right) :c(_Right.c) {
			//使用SizeFilter容器来构造函数
			this->c = _Right.c;
			return this->c;
		}

		SizeFilter(const _Container& Cont) :c(Cont.c) {
			//使用通用的容器来构造函数
			this->c = Cont.c;
			return this->c;
		}

		_Myt& operator=(const _Myt& _Right) {
			//赋值运算符重载
			this->c = _Right.c;
			return (*this);
		}

		bool empty() const {
			//确认容器中元素是否为空
			return c.empty();
		}

		typename _Container::size_type size() const {
			//确认元素个数
			return c.size();
		}

		bool insert(const value_type& _Val) {
			//在容器中插入元素
			typename _Container::iterator cit = c.insert(c.begin(), _Val);
			if (cit != c.end()) {
				cout << "插入" << _Val << "成功!" << endl;
				return true;
			}
			else {
				cout << "插入" << _Val << "失败!" << endl;
				return false;
			}
		}

		bool erase(const value_type& _Val) {
			//在容器中删除元素
			if (c.erase(_Val) > 0) {
				return true;
			}
			else {
				return false;
			}
		}

		pair<value_type, bool> getMin() {
			pair<value_type, bool> ret;
			typename _Container::iterator cit1 = c.begin();
			if (cit1 != c.end()) {
				ret.first = *cit1;
				ret.second = true;
				return ret;
			}
			else {
				ret.second = false;
				return ret;
			}
		}

		pair<value_type, bool> getMax() {
			pair<value_type, bool> ret;
			typename _Container::iterator cit2 = c.end();
			if (c.size() > 0) {
				ret.first = *(--cit2);
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
