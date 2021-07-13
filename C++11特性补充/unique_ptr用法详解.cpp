#include <stdio.h>
#include <Windows.h>
#include <iostream>
#include <string>
#include <memory>
#include <vector>

using namespace std;

int main1(void) {

	//弊端1. auto_ptr 被C++11抛弃的主要理由 p1 = p2, 复制或赋值都会改变资源的所有权
	auto_ptr<string>p1(new string("I'm martin"));
	auto_ptr<string>p2(new string("I'm Rock"));
	printf("p1: %p\n", p1.get());
	printf("p2: %p\n", p2.get());

	p1 = p2;

	printf("after p1 = p2\n");
	printf("p1: %p\n", p1.get());
	printf("p2: %p\n", p2.get());

	// 弊端2. 在 STL 容器中使用auto_ptr存在重大风险, 因为容器内的元素必须支持可复制(copyconstructable)和可赋值(assignable)
	vector<auto_ptr<string>> va;
	auto_ptr<string>p3(new string("I'm p3"));
	auto_ptr<string>p4(new string("I'm p4"));

	va.push_back(std::move(p3));
	va.push_back(std::move(p4));

	cout << "va[0]: " << *va[0] << endl;
	cout << "va[1]: " << *va[1] << endl;

	//风险来啦
	va[0] = va[1];
	cout << "va[0]: " << *va[0] << endl;
	cout << "va[1]: " << *va[1] << endl;

	//弊端3. 不支持对对象数组的内存管理
	//auto_ptr<int[]>ai(new int[5]);  //不能这样定义

	//auto_ptr 陷阱, 不能把同一段内存交给多个auto_ptr 变量去管理
	/*{
		auto_ptr<string>p2;

		string* str = new string("智能指针的内存管理陷阱");
		p2.reset(str);
		{
			auto_ptr<string>p1;
			p1.reset(str);
		}
		cout << "str: " << *p2 << endl;
	}*/
	
	system("pause");
	return 0;
}

int main(void) {

	//弊端1. auto_ptr 被C++11抛弃的主要理由 p1 = p2, 复制或赋值都会改变资源的所有权
	//unique_ptr 如何解决这个问题? 不允许显式的右值赋值和构造
	unique_ptr<string>p1(new string("I'm martin"));
	unique_ptr<string>p2(new string("I'm Rock"));
	printf("p1: %p\n", p1.get());
	printf("p2: %p\n", p2.get());

	//如果一定要转移, 使用move把左值转成右值
	p1 = std::move(p2);
	printf("p1: %p\n", p1.get());
	printf("p2: %p\n", p2.get());
	//p1 = p2;  //左值赋值禁止
	unique_ptr<string>p3(new string("I'm martin"));
	unique_ptr<string>p4(std::move(p3));  //左值拷贝构造也不行, 必须转成右值

	// 弊端2. 在 STL 容器中使用auto_ptr存在重大风险, 因为容器内的元素必须支持可复制(copyconstructable)和可赋值(assignable)
	vector<unique_ptr<string>> vu;
	unique_ptr<string>p5(new string("I'm p3"));
	unique_ptr<string>p6(new string("I'm p4"));

	vu.push_back(std::move(p5));
	vu.push_back(std::move(p6));

	cout << "v0[0]: " << *vu[0] << endl;
	cout << "v0[1]: " << *vu[1] << endl;

	//风险来啦
	/*va[0] = va[1];  //不支持直接赋值, 没有风险
	cout << "va[0]: " << *va[0] << endl;
	cout << "va[1]: " << *va[1] << endl;*/

	//弊端3. auto_ptr不支持对对象数组的内存管理
	//但是unique_ptr 支持对象数组的管理
	//auto_ptr<int[]>ai(new int[5]);  //不能这样定义
	unique_ptr<int[]>ui(new int[5]);  //自动会调用delete [] 函数去释放

	//auto_ptr 陷阱, 不能把同一段内存交给多个auto_ptr 变量去管理
	/*{
		auto_ptr<string>p2;

		string* str = new string("智能指针的内存管理陷阱");
		p2.reset(str);
		{
			auto_ptr<string>p1;
			p1.reset(str);
		}
		cout << "str: " << *p2 << endl;
	}*/

	system("pause");
	return 0;
}