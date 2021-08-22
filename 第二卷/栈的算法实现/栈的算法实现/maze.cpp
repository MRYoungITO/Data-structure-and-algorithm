#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "maze.h"
#include <assert.h>

#define ROW 6
#define COL 6

typedef struct _Maze {
	int map[ROW][COL];
}Maze;

void InitMaze(Maze* m, int map[ROW][COL]) {//�Թ��ĳ�ʼ��

	for (int i = 0; i < ROW; ++i)
	{
		for (int j = 0; j < COL; ++j)
		{
			m->map[i][j] = map[i][j];
		}
	}
}

void PrintMaze(Maze* m) {//��ӡ�Թ�

	for (int i = 0; i < ROW; ++i)
	{
		for (int j = 0; j < COL; ++j)
		{
			printf("%d ", m->map[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int IsValidEnter(Maze* m, Position cur) {//�ж��Ƿ�����Ч�����

	assert(m);

	if ((cur._x == 0 || cur._x == ROW - 1)
		|| (cur._y == 0 || cur._y == COL - 1)
		&& (m->map[cur._x][cur._y] == 1))
		return 1;
	else
		return 0;
}

int IsNextPass(Maze* m, Position cur, Position next) {//�жϵ�ǰ�ڵ����һ���ڵ��ܷ���ͨ

	assert(m);

	//�ж�next �ڵ��Ƿ�Ϊcur ����һ�ڵ�
	if (((next._x == cur._x) && ((next._y == cur._y + 1) || (next._y ==
		cur._y - 1))) //��ͬһ���ϲ�������
		|| ((next._y == cur._y) && ((next._x == cur._x + 1) || (next._x ==
			cur._x - 1)))) {//����ͬһ���ϲ�������

			//�ж���һ���ڵ��Ƿ����Թ�����
		if (((next._x >= 0 && next._x < ROW) || (next._y >= 0 && next._y
			< COL))
			&& (m->map[next._x][next._y] == 1)) {
			return 1;
		}
	}
	return 0;
}

int IsValidExit(Maze* m, Position cur, Position enter) {//�жϵ�ǰ�ڵ��ǲ�����Ч���Թ�����

	assert(m);
	//�������ȵñ�֤�ýڵ㲻����ڵ㣬���ֻҪ�������Թ��ı߽缴��
	if ((cur._x != enter._x || cur._y != enter._y)
		&& ((cur._x == 0 || cur._x == ROW - 1)
			|| (cur._y == 0 || cur._y == COL - 1)))
	{
		return 1;
	}
	else {
		return 0;
	}
}

int PassMaze(Maze* m, Position enter, SqStack* s) {//���Թ�ͨ·

	assert(m && IsValidEnter(m, enter) == 1); //�Ը����Թ�����ڽ��кϷ����ж�

	Position cur = enter;
	Position next;

	PushStack(*s, cur); //���Ƚ��Թ������ѹ��ջ��
	m->map[cur._x][cur._y] = 2; //�����ֵ��Ϊ2
	//PrintMaze(m);

	while (!IsEmpty(*s)) {
		cur = *GetTop(*s);
		//printf("cur: %d %d\n",cur._x, cur._y);
		if (IsValidExit(m, cur, enter) == 1) {//�жϵ�ǰλ���Ƿ����
			return 1;
		}

		//��������һ��������ǰ�ڵ����һ���ڵ��ܲ�����ͨ
		next = cur;
		next._y = cur._y - 1;
		if (IsNextPass(m, cur, next) == 1)
		{
			PushStack(*s, next);
			m->map[next._x][next._y] = m->map[cur._x][cur._y] + 1;
			//PrintMaze(m);
			continue;
		}

		//��������һ��:����ǰ�ڵ����һ���ڵ��ܲ�����ͨ
		next = cur;
		next._x = cur._x - 1;
		if (IsNextPass(m, cur, next) == 1) //next �ڵ��ܹ���ͨʱ������ѹ��ջ��
		{
			PushStack(*s, next);
			m->map[next._x][next._y] = m->map[cur._x][cur._y] + 1; //�� next �ڵ��ֵ����cur �ڵ��ֵ��1
				//PrintMaze(m);
			continue;
		}

		//�ң�����ǰ�ڵ�����ҵ�һ���ڵ��ܲ�����ͨ
		next = cur;
		next._y = cur._y + 1;
		if (IsNextPass(m, cur, next) == 1)
		{
			PushStack(*s, next);
			m->map[next._x][next._y] = m->map[cur._x][cur._y] + 1;
			//PrintMaze(m);
			continue;
		}

		//�£�����ǰ�ڵ����һ���ڵ��ܲ�����ͨ
		next = cur;
		next._x = cur._x + 1;
		if (IsNextPass(m, cur, next) == 1)
		{
			PushStack(*s, next);
			m->map[next._x][next._y] = m->map[cur._x][cur._y] + 1;
			//PrintMaze(m);
			continue;
		}

		//�ߵ�����˵����ǰ�ڵ���ĸ������߲�ͨ�����л��ݣ���ǰһ���ڵ�δ�������ķ����Ƿ�����ͨ
		Position tmp;
		PopStack(*s, tmp);
	}
	return 0;
}

int main(void) {

	int map[ROW][COL] = { //�ö�ά��������Թ���1 ����ͨ·��0 ����ǽ
	0,0,1,0,0,0,
	0,0,1,1,1,0,
	0,0,1,0,0,0,
	0,1,1,1,1,0,
	0,0,1,0,1,0,
	0,0,0,0,1,0
	};

	Maze m;
	Position enter; //�Թ����
	enter._x = 0;
	enter._y = 2;
	InitMaze(&m, map);
	PrintMaze(&m);
	//system("pause");
	//exit(0);
	SqStack s; //����ջ���������߹�������켣�����ڻ���
	InitStack(s); //ջ�ĳ�ʼ

	int ret = PassMaze(&m, enter, &s); //ʹ��ջ�ͻ��ݷ��⿪�Թ�
	if (ret) {
		printf("��ϲ�㣡�����ҵ��˳���~\n");
	}
	else {
		printf("�����ұ���ʵ��û�г���~\n");
	}
	PrintMaze(&m);
	system("pause");
	return 0;
}