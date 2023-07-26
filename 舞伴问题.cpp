#include<iostream>
#include<string>
#define OK 1
#define ERROR 0
using namespace std;
#define MAXSIZE 100
typedef int Status;

typedef struct {
	char name[20]; //����
	char sex; //�Ա�'F'��ʾŮ�ԣ�'M'��ʾ����
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
	if (Q.front == Q.rear) //�ӿ�
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




void DancePartner(Person dancer[], int num) {//�ṹ����dancer�д���������Ů��num�������������
	InitQueue(Mdancers); //��ʿ���г�ʼ��
	InitQueue(Fdancers); //Ůʿ���г�ʼ��
	Person p;
	for (int i = 0; i <num; i++) //���ν������߸������Ա����
	{
		p = dancer[i];
		if (p.sex == 'F')
			EnQueue(Fdancers, p); //����Ů��
		else
			EnQueue(Mdancers, p); //�����ж�
	}
	cout << "The dancing partners are:" << endl;
	while (!QueueEmpty(Fdancers) && !QueueEmpty(Mdancers)) {//���������Ů��������
		DeQueue(Fdancers, p); //Ůʿ����
		cout << p.name << "  "; //�������Ůʿ����
		DeQueue(Mdancers, p); //��ʿ����
		cout << p.name << endl; //���������ʿ����
	}
	if (!QueueEmpty(Fdancers)) { //Ůʿ���зǿգ������ͷŮʿ������
		p = GetHead(Fdancers); //ȡŮʿ��ͷ
		cout << "The first man to get a partner is: " << endl;
		cout << p.name << endl;
	}
	else if (!QueueEmpty(Mdancers)) { //��ʿ���зǿգ������ͷ��ʿ������
		p = GetHead(Mdancers); //ȡ��ʿ��ͷ
		cout << "The first woman to get a partner is: " << p.name << endl;
	}

}
int main()
{
	int num;
	cout << "�������� ";
	cin >> num;
	Person dancer[MAXSIZE];
	for (int i = 0; i < num; i++)
	{
		cout << "�������" << i + 1 << "�����ߣ�";
		cin >> dancer[i].name >> dancer[i].sex;
	}
	DancePartner(dancer, num);
	return 0;
}