#include "stdafx.h"
#include "malloc.h"


//---------------------------------------------------------------------------------------------------
//					�����β����

typedef struct linkednode
{
	char data;
	struct linkednode *next;
}snode ,*ptr;


//�����β����Ĳ���
//����β���ලԪ��˼��

ptr searchB(ptr p, ptr last, char x)	// �������������׽ڵ�����������β���ڵ㣬�������ҵı�־
{
	last->data = x;	//����β���ලԪ
	while (p->data != x)
		p = p->next;					//����ָ����һ���ڵ�
	if (p != last)
		return p;						//ָ��û��ָ��β��������־���������ҳɹ�
	return NULL;
}

//�����β����
void main_1()
{
	ptr head, last;
	head = last = (ptr)malloc(sizeof(snode));
	last->next = NULL;
}
//-------------------------------------------------------------------------------------------------------



//-----------------------------------------------------------
//				�����ͷѭ������

void lianbiaoshuchu0(ptr p)							//����������庯��
{
	printf("�����еĽڵ�����Ϊ��\n");
	while (p != NULL)
	{
		printf("%5c", p->data);
		p = p->next;								//�����һ������
	}
}

void lianbiaoshuchu2(ptr p,ptr head)							//����������庯��
{
	printf("�����еĽڵ�����Ϊ��\n");
	while (p->next != head)							//�ж�β���ڵ��Ƿ�ָ��ͷ���ڵ�
	{
		printf("%5c", p->data);
		p = p->next;								//�����һ������
	}
	printf("\n");
}


void main()
{
	ptr head, last,p;
	head = last = (ptr)malloc(sizeof(snode));
	last->next = head;				//  β��ָ��ͷ��������ѭ��

	//��������ʾ��
	char pp;
	scanf_s("%c",&pp);

	while (pp != '@')
	{
		p = (ptr)malloc(sizeof(snode));
		p->data = pp;
		last->next=p;
		p->next = head;
		last = p;
		scanf_s("%c",&pp);
	}
	
	p = head; head = head->next; free(p);
	last->next = head;       //�����Ѿ�����ѭ�������ʱӦ����ע��

	//lianbiaoshuchu0(head);  //����������û�ж�����β������ last->next=head �жϣ���������ѭ��

	lianbiaoshuchu2(head,head);
}