#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

//数据类型
typedef int DataType;

//结构体定义
typedef struct ListNode
{
	DataType data;
	struct ListNode *prev;
	struct ListNode *next;
}ListNode;

//开辟一个链表节点
ListNode *BuyListNode(DataType x);
//销毁链表
void ListClear(ListNode *phead);
void ListDestory(ListNode *phead);

//链表初始化
ListNode *ListInit();

//打印链表
void PrintList(ListNode *phead);

//双链表的增删改查
//尾插
void ListPushBack(ListNode *phead,DataType x);
//尾删
void ListPopBack(ListNode *phead);
//头插
void ListPushFront(ListNode *phead, DataType x);
//头删
void ListPopFront(ListNode *phead);

//查找
ListNode *ListFind(ListNode *phead, DataType x);
//在pos位置前面插入
void ListInsert(ListNode *pos, DataType x);
//删除pos位置的结点
void ListErase(ListNode *pos);