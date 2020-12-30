#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

//数据类型
typedef int DataType;

//结构体定义
typedef struct ListNode
{
	DataType data;
	ListNode *prev;
	ListNode *next;
}ListNode;

//双链表的增删改查

//尾部插入删除
void ListPushBack(ListNode *phead,DataType x);