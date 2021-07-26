#include <iostream>
#include <Windows.h>

using namespace std;

typedef struct _LinkNode {
	int data;	//结点的数据域
	struct _LinkNode* next;	//结点的指针域
}LinkNode, LinkList; //链表节点、链表		LinkList为指向结构体LinkNode的指针类型

bool InitList(LinkList*& L) {
	L = new LinkNode;
	
	if (!L)return false;	//生成节点失败

	L->next = NULL;
	L->data = -1;
	return true;
}

//前插法
bool listInsert_front(LinkList*& L, LinkNode* node) {
	if (!L || !node)return false;

	node->next = L->next;
	L->next = node;
	return true;
}

//尾插法
bool listInsert_back(LinkList*& L, LinkNode* node) {
	LinkNode* last = NULL;

	if (!L || !node)return false;

	last = L;

	while (last->next)last = last->next;

	node->next = NULL;
	last->next = node;
	return true;
}

//指定位置插入
bool linkInsert(LinkList*& L, int i, int& e) {
	if (!L)return false;

	int j = 0;	//设定对节点进行计数的变量
	LinkNode* p, * s;

	p = L;

	while (p && j < i - 1) {//查找位置 为i-1的结点, p指向该结点
		p = p->next;
		j++;
	}

	if (!p || j > i - 1) {
		return false;
	}

	s = new LinkNode;	//生成新节点
	s->data = e;
	s->next = p->next;
	p->next = s;
	return true;
}

void LinkPrint(LinkList*& L) {
	LinkNode* p = NULL;	//定义临时的结点指针 p, 为了遍历L中的所有指针

	if (!L) {
		cout << "链表为空. " << endl;
		return;
	}

	p = L->next;

	while (p) {
		cout << p->data << "\t";
		p = p->next;
	}

	cout << endl;
}

bool Link_GetElem(LinkList*& L, int i, int& e) {
	 
	//在带头节点的点链表L中查找第i个元素
	//用e记录L中第i个的数据元素的值

	int index;
	LinkNode* p;

	if (!L || !L->next)return false;

	p = L->next;
	index = 1;

	while (p && index < i) {//顺链域向后扫描, 直到指向第i个元素或为空		
		p = p->next;		//p指向下一个结点
		index++;			//计数器index相应加1
	}

	if (!p || index > i) {//i值不合法, i>n或i<=0
		return false;
	}

	if (!p)return false; //查无此值

	e = p->data;
	return true;
}

bool Link_FindElem(LinkList*& L, int e, int& index) {	//按值查找

	//在带头结点的单链表L中查找值为e的元素
	LinkNode* p;
	p = L->next;
	index = 1;

	if (!L || !L->next) {
		index = 0;
		return false;
	}

	while (p && p->data != e) {
		p = p->next;
		index++;
	}

	if (!p) {
		index = 0;
		return false;  //查无此值
	}

	return true;
}

bool LinkDelete(LinkList*& L, int i) {	//单链表的删除

	LinkNode* p, * q;

	int index = 0;
	p = L;

	if (!L || !L->next) {
		return false;
	}

	while ((p->next) && (index < i - 1)) {
		p = p->next;
		index++;
	}

	if (!(p->next) || (index > i - 1))return false;	//当i>n或i<1时, 删除位置不合理

	q = p->next;		//临时保存被删结点的地址以备释放空间
	p->next = q->next;	//改变删除结点前驱结点的指针域
	delete q;			//释放被删除结点的空间
	return true;
}

void LinkDestroy(LinkList*& L) {  //单链表的销毁

	//定义临时节点p指向头节点
	LinkNode* p = L;
	cout << "销毁链表!" << endl;

	while (p) {
		L = L->next;  //L指向下一个节点
		cout << "删除元素: " << p->data << endl;
		delete p;	  //删除当前节点
		p = L;		  //p移向像一个节点
	}
}

int main(void) {
	LinkList* L = NULL;
	LinkNode* s = NULL;

	//1. 初始化一个空的链表
	InitList(L);

	//2. 使用前插法插入数据
	//int n;
	//
	//cout << "前插法创建单链表" << endl;
	//cout << "请输入元素个数n: ";
	//cin >> n;
	//cout << "\n请一次输入n个元素: " << endl;

	//while (n > 0) {
	//	s = new LinkNode;	//生成新节点 s
	//	if (!s)break;
	//	cin >> s->data;
	//	listInsert_front(L, s);
	//	
	//	n--;
	//}

	//3. 使用后插法插入数据
	//int n;

	//cout << "尾插法创建单链表" << endl;
	//cout << "请输入元素个数n: ";
	//cin >> n;
	//cout << "\n请依次输入n个元素: " << endl;

	//while (n > 0) {
	//	s = new LinkNode;	//生成新节点 s
	//	if (!s)break;
	//	cin >> s->data;
	//	listInsert_back(L, s);

	//	n--;
	//}

	//4. 单链表的输出
	LinkPrint(L);

	//5. 任意位置插入元素
	for (int j = 0; j < 3; j++) {
		int i, x;
		cout << "请输入插入的位置和元素(用空格隔开): ";
		cin >> i;
		cin >> x;

		if (linkInsert(L, i, x)) {
			cout << "插入成功.\n\n";
		}
		else {
			cout << "插入失败.\n\n";
		}
		cout << endl;

		LinkPrint(L);
	}

	//6. 单链表根据位置获取元素
	int element = 0;
	if (Link_GetElem(L, 2, element)) {
		cout << "获取第二个元素成功, 值: " << element << endl;
	}
	else {
		cout << "获取第二个元素失败!" << endl;
	}

	/*if (Link_GetElem(L, 4, element)) {
		cout << "获取第四个元素成功, 值: " << element << endl;
	}
	else {
		cout << "获取第四个元素失败!" << endl;
	}*/

	//7. 单链表根据值查询元素所在的位置
	int index = 0;
	if (Link_FindElem(L, 10, index)) {
		cout << "查找元素10存在, 所在位置: " << index << endl;
	}
	else {
		cout << "不存在元素 10." << endl;
	}

	//8. 单链表删除元素
	if (LinkDelete(L, 2)) {
		cout << "删除第2个元素成功!" << endl;
		LinkPrint(L);
	}
	else {
		cout << "删除第2个元素失败!" << endl;
	}

	//9. 销毁单链表
	LinkDestroy(L);
	system("pause");
	return 0;
}