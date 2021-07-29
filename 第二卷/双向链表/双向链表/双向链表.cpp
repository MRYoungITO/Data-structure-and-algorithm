#include<iostream> 
#include<string> 
#include<stdlib.h> 

using namespace std; 

typedef struct _DoubleLinkNode {
	int data; //���������� 
	struct _DoubleLinkNode* next; //��һ���ڵ��ָ���� 
	struct _DoubleLinkNode* prev; //��һ������ָ���� 
}DbLinkNode, DbLinkList; //LinkList Ϊָ��ṹ�� LNode ��ָ������ 

bool DbList_Init(DbLinkList*& L) {//����һ���յ�˫������ L  
	L = new DbLinkNode; //�����½����Ϊͷ��㣬��ͷָ�� L ָ��ͷ��� 
	if (!L)return false; //���ɽ��ʧ�� 

	L->next = NULL; //ͷ���� next ָ�����ÿ� 
	L->prev = NULL; //ͷ���� prev ָ�����ÿ� 
	L->data = -1;

	return true;
}

//ǰ�巨 
bool DbListInsert_front(DbLinkList*& L, DbLinkNode* node) {
	if (!L || !node) return false; //1.ֻ��ͷ�ڵ� 

	if (L->next == NULL) {
		node->next = NULL; 
		node->prev = L; //�½ڵ� prev ָ��ָ��ͷ�ڵ� 
		L->next = node; //ͷ�ڵ� next ָ��ָ���½ڵ� 
	}
	else {
		L->next->prev = node; //�ڶ����ڵ�� prev ָ���½ڵ� 
		node->next = L->next; //�½ڵ� next ָ��ָ��ڶ����ڵ� 
		node->prev = L; //�½ڵ� prev ָ��ָ��ͷ�ڵ� 
		L->next = node; //ͷ�ڵ� next ָ��ָ���½ڵ㣬��ɲ��� 
	}

	return true;
}

//β�巨 
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

//ָ��λ�ò��� 
bool DbLink_Insert(DbLinkList*& L, int i, int& e) {
	if (!L || !L->next) return false;

	if (i < 1) return false;

	int j = 0;

	DbLinkList* p, * s;

	p = L;

	while (p && j < i) { //����λ��Ϊ i �Ľ�㣬p ָ��ý�� 
		p = p->next;
		j++;
	}
	if (!p || j != i) {
		cout << "�����ڽڵ㣺" << i << endl;
		return false;
	}
	cout << "p: " << p << endl;
	s = new DbLinkNode; //�����½ڵ� 
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
		cout << "����Ϊ��." << endl;
		return;
	}
	p = L;
	while (p->next) {
		cout << p->next->data << "\t";
		p = p->next;
	} //�����ӡ 
	cout << endl << "�����ӡ" << endl;
	while (p) {
		cout << p->data << "\t"; p = p->prev;
	}
	cout << endl;
}

bool DbLink_GetElem(DbLinkList*& L, int i, int& e) { //˫�������ȡֵ  
	//�ڴ�ͷ����˫������ L �в��ҵ� i ��Ԫ�� 
	//�� e ��¼ L �е� i ������Ԫ�ص�ֵ 
	int index;
	DbLinkList* p;

	if (!L || !L->next) return false;

	p = L->next;
	index = 1;

	while (p && index < i) {//˳�������ɨ�裬ֱ�� p ָ��� i ��Ԫ�ػ� p Ϊ�� 
		p = p->next; //p ָ����һ����� 
		index++; //������ index ��Ӧ�� 1 
	}

	if (!p || index > i) {
		return false; //i ֵ���Ϸ�,i��n �� i<=0 
	}

	e = p->data;
	return true;
}

bool DbLink_Delete(DbLinkList*& L, int i) {//˫�������ɾ��  

	DbLinkList* p;

	int index = 0;

	if (!L || !L->next) {
		cout << "˫������Ϊ��!" << endl;
		return false;
	}

	if (i < 1) return false; //����ɾ��ͷ�ڵ�

	p = L;
	while (p && index < i) {
		p = p->next;
		index++;
	}

	if (!p) { //���ڵ㲻����ʱ������ʧ�� 
		return false;
	}
	p->prev->next = p->next; //�ı�ɾ�����ǰ������ next ָ���� 
	p->next->prev = p->prev; //�ı�ɾ���ڵ��̽ڵ�� prev ָ���� 
	delete p; //�ͷű�ɾ�����Ŀռ� 
	return true;
}

void DbLink_Destroy(DbLinkList*& L) { //˫�����������  

	//������ʱ�ڵ� p ָ��ͷ�ڵ� 
	DbLinkList *p = L; 
	cout<<"��������!"<<endl; 

	while (p) {
		L = L->next; //L ָ����һ���ڵ� 
		cout << "ɾ��Ԫ��: " << p->data << endl;
		delete p; //ɾ����ǰ�ڵ� 
		p = L; //p ������һ���ڵ� 
	}
}

int main(void) {
	DbLinkList* L = NULL;
	DbLinkNode* s = NULL;

	//1. ��ʼ��һ���յ�˫������ 
	DbList_Init(L);

	//2. ʹ��ǰ�巨�������� 
	int n;

	cout << "ǰ�巨����˫������" << endl;
	std::cout << "������Ԫ�ظ��� n��";
	cin >> n;
	cout << "\n ���������� n ��Ԫ�أ�" << endl;

	while (n > 0) {
		s = new DbLinkNode; //�����½ڵ� s

		cin >> s->data;
		DbListInsert_front(L, s);
		n--;
	}

	//3. ʹ��β�巨�������� 
	cout << "β�巨����˫������" << endl;
	std::cout << "������Ԫ�ظ��� n��";
	cin >> n;
	cout << "\n ���������� n ��Ԫ�أ�" << endl;

	while (n > 0) {
		s = new DbLinkNode; //�����½ڵ� s 

		cin >> s->data;
		DbListInsert_back(L, s);
		n--;
	}

	//4. ˫���������� 
	DbLink_Print(L);

	//5. ����λ�ò���Ԫ�� 
	for (int j = 0; j < 3; j++) {
		int i, x;
		cout << "����������λ�ú�Ԫ�أ��ÿո������:";
		cin >> i;
		cin >> x;

		if (DbLink_Insert(L, i, x)) {
			cout << "����ɹ�.\n\n";
		}
		else {
			cout << "����ʧ��!\n\n";
		}

		DbLink_Print(L);
	}

	//6. ˫���������λ�û�ȡԪ�� 
	int element = 0;
	if (DbLink_GetElem(L, 2, element)) {
		cout << "��ȡ�ڶ���Ԫ�سɹ�, ֵ��" << element << endl;
	}
	else {
		cout << "��ȡ�ڶ���Ԫ��ʧ��!" << endl;
	}

	//7. ˫������ɾ��Ԫ�� 
	if (DbLink_Delete(L, 2)) {
		cout << "ɾ���� 2 ��Ԫ�سɹ�!" << endl;
		DbLink_Print(L);
	}
	else {
		cout << "ɾ���� 2 ��Ԫ��ʧ��!" << endl;
	}

	if (DbLink_Delete(L, 1)) {
		cout << "ɾ���� 1 ��Ԫ�سɹ�!" << endl;
		DbLink_Print(L);
	}
	else {
		cout << "ɾ���� 1 ��Ԫ��ʧ��!" << endl;
	}

	//8. ����˫������ 
	DbLink_Destroy(L);
	system("pause");
	return 0;
}