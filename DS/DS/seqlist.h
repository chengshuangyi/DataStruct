#ifndef _SEQLIST_H_
#define _SEQLIST_H_

#include"common.h"
#define ElemType int
#define SEQLIST_DEFAULT_SIZE 8

//定义顺序表的结构
typedef struct SeqList
{
	ElemType *base;
	size_t capacity;
	size_t size;
}SeqList;


// 对数据的管理:增删查改 
void SeqListInit(SeqList* plist);
//void SeqListDestory(SeqList* plist);
//
void SeqListPrint(SeqList* plist);
void SeqListPushBack(SeqList* plist, ElemType x);
void SeqListPushFront(SeqList* plist, ElemType x);
void SeqListPopFront(SeqList* plist);
void SeqListPopBack(SeqList* plist);
//
//// 顺序表查找
//int SeqListFind(SeqList* plist, ElemType x);
//// 顺序表在pos位置插入x
//void SeqListInsert(SeqList* plist, size_t pos, ElemType x);
//// 顺序表删除pos位置的值
//void SeqListErase(SeqList* plist, size_t pos);

#endif  //_SEQLIST_H_
