#include<iostream>
#include<string>
#define OK 1
#define ERROR 0
using namespace std;
#define MAXSIZE 100
typedef int Status;

typedef struct {
	char name[20]; //姓名
	char sex; //性别，'F'表示女性，'M'表示男性
} Person;

typedef struct {
	Person* base;
	int front;
	int rear;
}SqQueue;
SqQueue Mdancers, Fdancers;  

Status InitQueue(SqQueue& Q)
{
	Q.base = new Person[MAXSIZE];
	if (!Q.base) return ERROR;
	Q.front = Q.rear = 0;
	return OK;
}

int QueueEmpty(SqQueue& Q) {
	if (Q.front == Q.rear) //队空
		return OK;
	else
		return ERROR;
}

Status EnQueue(SqQueue& Q, Person e)
{
	if ((Q.rear + 1) % MAXSIZE == Q.front) return ERROR;
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear + 1) % MAXSIZE;
	return OK;
}

Status DeQueue(SqQueue& Q, Person& e)
{
	if (Q.front == Q.rear) return ERROR;
	e = Q.base[Q.front];
	Q.front = (Q.front + 1) % MAXSIZE;
	return OK;
} 

Person GetHead(SqQueue Q) {
	if (Q.front != Q.rear) 
		return Q.base[Q.front]; 
}




void DancePartner(Person dancer[], int num) {//结构数组dancer中存放跳舞的男女，num是跳舞的人数。
	InitQueue(Mdancers); //男士队列初始化
	InitQueue(Fdancers); //女士队列初始化
	Person p;
	for (int i = 0; i <num; i++) //依次将跳舞者根据其性别入队
	{
		p = dancer[i];
		if (p.sex == 'F')
			EnQueue(Fdancers, p); //插入女队
		else
			EnQueue(Mdancers, p); //插入男队
	}
	cout << "The dancing partners are:" << endl;
	while (!QueueEmpty(Fdancers) && !QueueEmpty(Mdancers)) {//依次输出男女舞伴的姓名
		DeQueue(Fdancers, p); //女士出队
		cout << p.name << "  "; //输出出队女士姓名
		DeQueue(Mdancers, p); //男士出队
		cout << p.name << endl; //输出出队男士姓名
	}
	if (!QueueEmpty(Fdancers)) { //女士队列非空，输出队头女士的姓名
		p = GetHead(Fdancers); //取女士队头
		cout << "The first man to get a partner is: " << endl;
		cout << p.name << endl;
	}
	else if (!QueueEmpty(Mdancers)) { //男士队列非空，输出队头男士的姓名
		p = GetHead(Mdancers); //取男士队头
		cout << "The first woman to get a partner is: " << p.name << endl;
	}

}
int main()
{
	int num;
	cout << "输入人数 ";
	cin >> num;
	Person dancer[MAXSIZE];
	for (int i = 0; i < num; i++)
	{
		cout << "请输入第" << i + 1 << "个舞者：";
		cin >> dancer[i].name >> dancer[i].sex;
	}
	DancePartner(dancer, num);
	return 0;
}