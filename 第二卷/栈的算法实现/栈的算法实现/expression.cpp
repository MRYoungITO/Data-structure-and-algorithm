#include <stdio.h>
#include <iostream>
#include "expression.h"

using namespace std;

//�Ƚ�lhs �����ȼ��Ƿ񲻸���rhs��rhs ��ʾջ���ķ���
bool isLarger(const int& lhs, const int& rhs) {

	if ((rhs == '+' || rhs == '-') && (lhs == '*' || lhs == '/')) {
		return true;
	}

	return false;
}

int operate(int left, int right, int op) {//���������ֵ

	int result = 0;
	cout << "left:" << left << " right:" << right << (char)op << endl;
	switch (op)
	{
	case '+':
		result = left + right;
		break;
	case '-':
		result = left - right;
		break;
	case '*':
		result = left * right;
		break;
	case '/':
		result = left / right;
		break;
	default:
		break;
	}
	cout << "result: " << result << endl;

	return result;
}

int calculate(string input)
{
	SqStack data_stack; //��������ջ
	SqStack opt_stack; //�������ջ 
	int status = 0; //0-�����������1-���������"+-*/" 2-�����Ҳ�����
	int ldata = 0, rdata = 0;
	char last_opt = '\0';

	//��ʼ��ջ���������Ͳ�����
	InitStack(data_stack);
	InitStack(opt_stack);

	for (int i = 0; i < input.length(); i++) {
		if (isspace(input[i])) continue; //�ո���Ⱥ��Ե�
		switch (status) {
		case 0:
			if (isdigit(input[i])) {
				ldata *= 10;
				ldata += input[i] - '0';
			}
			else {
				cout << "�õ��������:" << ldata << endl;
				PushStack(data_stack, ldata); //���������ջ
				i--;
				status = 1;
			}
			break;
		case 1:
			if (input[i] == '+' || input[i] == '-' || input[i] == '*' ||
				input[i] == '/') {
				if (IsEmpty(opt_stack)) { //��һ�������,��ʱ�����κδ������������ջ����
					cout << "����ջΪ��" << endl;
					PushStack(opt_stack, input[i]); //��������ջ
					cout << "����" << (char)input[i] << "��ջ" << endl;
					status = 2;
				}
				else { //�ǵ�һ�������������֮ǰ��������Ƚ����ȼ�
					cout << "isLarger:" << (char)(*GetTop(opt_stack)) << " &" << input[i] << endl;
					if (isLarger(input[i], *GetTop(opt_stack))) {
						cout << "true" << endl;
						PushStack(opt_stack, input[i]); //��������ջ
						cout << "����" << (char)input[i] << "��ջ" << endl;
						status = 2;
						rdata = 0;
					}
					else { //��ǰ����������ȼ�������ǰһ��������������ǰһ���������ֵ
						int left = 0, right = 0;
						int opt;
						cout << "false" << endl;
						do {
							PopStack(data_stack, right);
							PopStack(data_stack, left);
							PopStack(opt_stack, opt);
							cout << "����" << (char)opt << "��ջ" << endl;
							cout << "����ǰһ�������" << (char)opt << endl;
							int result = operate(left, right, opt);
							PushStack(data_stack, result);
						} while (!IsEmpty(opt_stack) && !isLarger(input[i],
							*GetTop(opt_stack)));

						PushStack(opt_stack, input[i]);
						cout << "����" << (char)input[i] << "��ջ" << endl;
						status = 2;
						rdata = 0;
					}
				}
			}
			else if (input[i] == '=') {//������
				int opt, result;
				do {
					PopStack(data_stack, rdata);
					PopStack(data_stack, ldata);
					PopStack(opt_stack, opt);
					result = operate(ldata, rdata, opt);
					PushStack(data_stack, result);
				} while (!IsEmpty(opt_stack));
				return result;
			}
			else {
				cerr << "�������������" << endl;
			}
			break;
		case 2:
			if (isdigit(input[i])) {
				rdata *= 10;
				rdata += input[i] - '0';
			}
			else {
				cout << "�õ��Ҳ�����:" << rdata << endl;
				PushStack(data_stack, rdata); //�Ҳ�������ջ
				i--;
				status = 1;
			}
			break;
		}
	}
	return -1;//���Ľ��Ϊջ��Ԫ��
}

int main(int argc, char const* argv[])
{
	string str = "12+3*6/3+4*5=";
	cout << calculate(str) << endl;
	system("pause");
	return 0;
}