#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>

using namespace std;

typedef struct _DoubleLinkNode {
	//int data; //�ڵ��������
	struct _DoubleLinkNode* next; //��һ���ڵ��ָ����
	struct _DoubleLinkNode* prev; //��һ���ڵ��ָ����
}DbLinkNode, DbLinkList;  //LinkList Ϊָ��ṹ��LNode��ָ������

typedef struct {
	int fd;
	time_t timeout;  //���ó�ʱʱ�̵�ʱ�����ʾ
	DbLinkNode node; //˫������ڵ� "�Ҽ�"
}ConnTimeout;

typedef struct {
	int x;				//���ǵ�x����
	int y;				//���ǵ�y����
	enum STATUS stat;	//״̬
	unsigned radius;	//���ǵİ뾶
	int step;			//ÿ����Ծ�ľ���
	int color;			//���ǵ���ɫ
	DbLinkNode node;	//˫������ڵ� "�Ҽ�"
}STAR;

bool InitLoopList(DbLinkList& L) { //����һ���յ�ѭ������

	L.next = NULL;	//ͷ����nextָ����ָ���Լ�
	L.prev = NULL;	//ͷ����prevָ����ָ���Լ�
	return true;
}

//β�巨 
bool DbListInsert_back(DbLinkList& L, DbLinkNode& node) {
	DbLinkNode* last = NULL;

	last = &L;

	while (last->next) last = last->next;

	node.next = NULL;
	last->next = &node;
	node.prev = last;
	return true;
}

int main(void) {
	ConnTimeout* cl = NULL, * s = NULL;;
	STAR* sl = NULL;
	int n = 0;

	//1. ��ʼ��һ���յ�˫������
	cl = new ConnTimeout;
	cl->fd = -1;

	sl = new STAR;
	sl->x = -1;
	
	InitLoopList(cl->node);
	InitLoopList(sl->node);

	//2. ʹ��β�巨
	cout << "β�巨����˫������" << endl; 
	std::cout << "������Ԫ�ظ��� n��"; 
	cin >> n; 
	cout << "\n ���������� n ��Ԫ�ص��ļ������" << endl;

	while (n > 0) {
		s = new ConnTimeout; //�����½ڵ� s 
		cin >> s->fd;
		printf("s �ĵ�ַ:%p node: %p\n", s, &(s->node));
		DbListInsert_back(cl->node, s->node);
		n--;
	}

	//3. ��������ڵ��������
	DbLinkNode* p = NULL;
	p = &(cl->node); 
	cout << "�������ӳ�ʱ�����еĽڵ㣺" << endl;

	while (p) {
		int offset = offsetof(ConnTimeout, node);
		ConnTimeout* ct = (ConnTimeout*)((size_t)p - offset);
		cout << ct->fd << endl;
		p = p->next;
	}

	//4. ����˫������ 
	p = &(cl->node); 
	cout<<"�������ӳ�ʱ�����еĽڵ㣺"<<endl; 
	while (p) {
		int offset = offsetof(ConnTimeout, node);
		ConnTimeout* ct = (ConnTimeout*)((size_t)p - offset);
		printf("offset: %u ct: %p p:%p\n", offset, ct, p);
		cout << ct->fd << endl;
		p = p->next;
		delete ct;
	}
	
	system("pause"); 
	return 0; 
}

	/*
	* ͨ���ڵ���ʵ��ڵ���ص�����
	ConnTimeout* ct = new ConnTimeout;
	DbLinkNode* p = &(ct->node);

	cout << "�����볬ʱ�ڵ��Ӧ��fd: ";
	cin >> ct->fd;

	cout << "\nͨ�������еĽڵ���ʽڵ��ϳ��ص�����: " << endl;
	int offset = offsetof(ConnTimeout, node);

	ConnTimeout* tmp = (ConnTimeout*)((size_t)p - offset);
	printf("offset: %d\n", offset);
	printf("ͨ������ڵ�node���ʵ�������: %d\n", tmp->fd);
	*/
//
//	system("pause");
//	return 0;
//}