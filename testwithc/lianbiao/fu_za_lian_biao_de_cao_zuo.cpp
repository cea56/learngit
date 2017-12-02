#include "stdafx.h"
#include "malloc.h"


//---------------------------------------------------------------------------------------------------
//					单向加尾链表

typedef struct linkednode
{
	char data;
	struct linkednode *next;
}snode ,*ptr;


//单项加尾链表的查找
//设置尾部监督元的思想

ptr searchB(ptr p, ptr last, char x)	// 链表名（链表首节点名），链表尾部节点，结束查找的标志
{
	last->data = x;	//设置尾部监督元
	while (p->data != x)
		p = p->next;					//向下指向下一个节点
	if (p != last)
		return p;						//指针没有指向尾部结束标志，表明查找成功
	return NULL;
}

//单项加尾链表：
void main_1()
{
	ptr head, last;
	head = last = (ptr)malloc(sizeof(snode));
	last->next = NULL;
}
//-------------------------------------------------------------------------------------------------------



//-----------------------------------------------------------
//				单项加头循环链表

void lianbiaoshuchu0(ptr p)							//链表输出定义函数
{
	printf("链表中的节点序列为：\n");
	while (p != NULL)
	{
		printf("%5c", p->data);
		p = p->next;								//输出下一个数据
	}
}

void lianbiaoshuchu2(ptr p,ptr head)							//链表输出定义函数
{
	printf("链表中的节点序列为：\n");
	while (p->next != head)							//判断尾部节点是否指向头部节点
	{
		printf("%5c", p->data);
		p = p->next;								//输出下一个数据
	}
	printf("\n");
}


void main()
{
	ptr head, last,p;
	head = last = (ptr)malloc(sizeof(snode));
	last->next = head;				//  尾部指向头部，构成循环

	//插入数据示例
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
	last->next = head;       //链表已经构成循环，输出时应加以注意

	//lianbiaoshuchu0(head);  //这个输出函数没有对链表尾部进行 last->next=head 判断，会造成输出循环

	lianbiaoshuchu2(head,head);
}