#include<iostream>
#define OK 1
#define ERROR 0
using namespace std;
typedef char SElemType;
typedef int Status;
#define MAXSIZE 100
typedef struct //ջ��˳��洢�ṹ
{
	SElemType* base;
	SElemType* top;
	int stacksize;
}SqStack;
Status InitStack(SqStack& S)//����һ����ջ
{
	S.base = new SElemType[MAXSIZE];
	if (!S.base)
		return ERROR;
	S.top = S.base;
	S.stacksize = MAXSIZE;
	return OK;
}
Status Push(SqStack& S, SElemType e) //��ջ
{
	if (S.top - S.base == S.stacksize)
		return ERROR;
	*S.top++ = e;
	return OK;
}
Status Pop(SqStack& S, SElemType& e)  //��ջ
{
	if (S.top == S.base)
		return ERROR;
	e = *--S.top;
	return OK;
}
SElemType GetTop(SqStack S)  //ȡջ��Ԫ��
{
	if (S.top != S.base)
		return *(S.top - 1);
}
Status StackEmpty(SqStack S)  //�ж�Ԫ��
{
	if (S.top == S.base)
		return OK;
	else
		return ERROR;
}
void Matching()
{
	SqStack S;
	InitStack(S);
	int flag = 1,count=1;
	char ch,x;
	cin >> ch;
	while (ch != '#' && flag && count <= 100) {
		switch (ch) {
		case '{':
		case '[':
		case '(':		
			Push(S, ch);
			break;
		case ')':
			if (!StackEmpty(S) && GetTop(S) == '(')
				Pop(S, x);
			else flag = 0;
			break;
		case ']':
			if (!StackEmpty(S) && GetTop(S) == '[')
				Pop(S, x);
			else flag = 0;
			break;
		case '}':
			if (!StackEmpty(S) && GetTop(S) == '{')
				Pop(S, x);
			else flag = 0;
			break;
		}
		
		cin >> ch;
		count++;
	}
	if (StackEmpty(S) && flag)
		cout << "ƥ��ɹ�" << endl;
	else
		cout << "ƥ��ʧ��" << endl;
	
}

int main()
{
	Matching();	
	return 0;
	
}