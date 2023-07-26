#include<iostream>
#define OK 1
#define ERROR 0
using namespace std;
typedef char SElemType;
typedef int Status;
#define MAXSIZE 100
typedef struct //栈的顺序存储结构
{
	SElemType* base;
	SElemType* top;
	int stacksize;
}SqStack;
Status InitStack(SqStack& S)//构造一个空栈
{
	S.base = new SElemType[MAXSIZE];
	if (!S.base)
		return ERROR;
	S.top = S.base;
	S.stacksize = MAXSIZE;
	return OK;
}
Status Push(SqStack& S, SElemType e) //入栈
{
	if (S.top - S.base == S.stacksize)
		return ERROR;
	*S.top++ = e;
	return OK;
}
Status Pop(SqStack& S, SElemType& e)  //出栈
{
	if (S.top == S.base)
		return ERROR;
	e = *--S.top;
	return OK;
}
SElemType GetTop(SqStack S)  //取栈顶元素
{
	if (S.top != S.base)
		return *(S.top - 1);
}
Status StackEmpty(SqStack S)  //判断元素
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
		cout << "匹配成功" << endl;
	else
		cout << "匹配失败" << endl;
	
}

int main()
{
	Matching();	
	return 0;
	
}