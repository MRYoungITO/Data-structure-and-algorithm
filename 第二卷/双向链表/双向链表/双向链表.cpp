#include<iostream> 
#include<string> 
#include<stdlib.h> 

using namespace std; 

typedef struct _DoubleLinkNode {
	int data; //结点的数据域 
	struct _DoubleLinkNode* next; //下一个节点的指针域 
	struct _DoubleLinkNode* prev; //上一个结点的指针域 
}DbLinkNode, DbLinkList; //LinkList 为指向结构体 LNode 的指针类型 

bool DbList_Init(DbLinkList*& L) {//构造一个空的双向链表 L  
	L = new DbLinkNode; //生成新结点作为头结点，用头指针 L 指向头结点 
	if (!L)return false; //生成结点失败 

	L->next = NULL; //头结点的 next 指针域置空 
	L->prev = NULL; //头结点的 prev 指针域置空 
	L->data = -1;

	return true;
}

//前插法 
bool DbListInsert_front(DbLinkList*& L, DbLinkNode* node) {
	if (!L || !node) return false; //1.只有头节点 

	if (L->next == NULL) {
		node->next = NULL; 
		node->prev = L; //新节点 prev 指针指向头节点 
		L->next = node; //头节点 next 指针指向新节点 
	}
	else {
		L->next->prev = node; //第二个节点的 prev 指向新节点 
		node->next = L->next; //新节点 next 指针指向第二个节点 
		node->prev = L; //新节点 prev 指针指向头节点 
		L->next = node; //头节点 next 指针指向新节点，完成插入 
	}

	return true;
}

//尾插法 
bool DbListInsert_back(DbLinkList*& L, DbLinkNode* node) {
	DbLinkNode* last = NULL;

	if (!L || !node) return false;

	last = L;

	while (last->next) last = last->next;

	node->next = NULL;
	last->next = node;
	node->prev = last;
	return true;
}

//指定位置插入 
bool DbLink_Insert(DbLinkList*& L, int i, int& e) {
	if (!L || !L->next) return false;

	if (i < 1) return false;

	int j = 0;

	DbLinkList* p, * s;

	p = L;

	while (p && j < i) { //查找位置为 i 的结点，p 指向该结点 
		p = p->next;
		j++;
	}
	if (!p || j != i) {
		cout << "不存在节点：" << i << endl;
		return false;
	}
	cout << "p: " << p << endl;
	s = new DbLinkNode; //生成新节点 
	s->data = e;
	s->next = p;
	s->prev = p->prev;
	p->prev->next = s;
	p->prev = s;
	return true;
}

void DbLink_Print(DbLinkList*& L) {
	DbLinkNode* p = NULL;
	if (!L) {
		cout << "链表为空." << endl;
		return;
	}
	p = L;
	while (p->next) {
		cout << p->next->data << "\t";
		p = p->next;
	} //逆向打印 
	cout << endl << "逆向打印" << endl;
	while (p) {
		cout << p->data << "\t"; p = p->prev;
	}
	cout << endl;
}

bool DbLink_GetElem(DbLinkList*& L, int i, int& e) { //双向链表的取值  
	//在带头结点的双向链表 L 中查找第 i 个元素 
	//用 e 记录 L 中第 i 个数据元素的值 
	int index;
	DbLinkList* p;

	if (!L || !L->next) return false;

	p = L->next;
	index = 1;

	while (p && index < i) {//顺链表向后扫描，直到 p 指向第 i 个元素或 p 为空 
		p = p->next; //p 指向下一个结点 
		index++; //计数器 index 相应加 1 
	}

	if (!p || index > i) {
		return false; //i 值不合法,i＞n 或 i<=0 
	}

	e = p->data;
	return true;
}

bool DbLink_Delete(DbLinkList*& L, int i) {//双向链表的删除  

	DbLinkList* p;

	int index = 0;

	if (!L || !L->next) {
		cout << "双向链表为空!" << endl;
		return false;
	}

	if (i < 1) return false; //不能删除头节点

	p = L;
	while (p && index < i) {
		p = p->next;
		index++;
	}

	if (!p) { //当节点不存在时，返回失败 
		return false;
	}
	p->prev->next = p->next; //改变删除结点前驱结点的 next 指针域 
	p->next->prev = p->prev; //改变删除节点后继节点的 prev 指针域 
	delete p; //释放被删除结点的空间 
	return true;
}

void DbLink_Destroy(DbLinkList*& L) { //双向链表的销毁  

	//定义临时节点 p 指向头节点 
	DbLinkList *p = L; 
	cout<<"销毁链表!"<<endl; 

	while (p) {
		L = L->next; //L 指向下一个节点 
		cout << "删除元素: " << p->data << endl;
		delete p; //删除当前节点 
		p = L; //p 移向下一个节点 
	}
}

int main(void) {
	DbLinkList* L = NULL;
	DbLinkNode* s = NULL;

	//1. 初始化一个空的双向链表 
	DbList_Init(L);

	//2. 使用前插法插入数据 
	int n;

	cout << "前插法创建双向链表" << endl;
	std::cout << "请输入元素个数 n：";
	cin >> n;
	cout << "\n 请依次输入 n 个元素：" << endl;

	while (n > 0) {
		s = new DbLinkNode; //生成新节点 s

		cin >> s->data;
		DbListInsert_front(L, s);
		n--;
	}

	//3. 使用尾插法插入数据 
	cout << "尾插法创建双向链表" << endl;
	std::cout << "请输入元素个数 n：";
	cin >> n;
	cout << "\n 请依次输入 n 个元素：" << endl;

	while (n > 0) {
		s = new DbLinkNode; //生成新节点 s 

		cin >> s->data;
		DbListInsert_back(L, s);
		n--;
	}

	//4. 双向链表的输出 
	DbLink_Print(L);

	//5. 任意位置插入元素 
	for (int j = 0; j < 3; j++) {
		int i, x;
		cout << "请输入插入的位置和元素（用空格隔开）:";
		cin >> i;
		cin >> x;

		if (DbLink_Insert(L, i, x)) {
			cout << "插入成功.\n\n";
		}
		else {
			cout << "插入失败!\n\n";
		}

		DbLink_Print(L);
	}

	//6. 双向链表根据位置获取元素 
	int element = 0;
	if (DbLink_GetElem(L, 2, element)) {
		cout << "获取第二个元素成功, 值：" << element << endl;
	}
	else {
		cout << "获取第二个元素失败!" << endl;
	}

	//7. 双向链表删除元素 
	if (DbLink_Delete(L, 2)) {
		cout << "删除第 2 个元素成功!" << endl;
		DbLink_Print(L);
	}
	else {
		cout << "删除第 2 个元素失败!" << endl;
	}

	if (DbLink_Delete(L, 1)) {
		cout << "删除第 1 个元素成功!" << endl;
		DbLink_Print(L);
	}
	else {
		cout << "删除第 1 个元素失败!" << endl;
	}

	//8. 销毁双向链表 
	DbLink_Destroy(L);
	system("pause");
	return 0;
}