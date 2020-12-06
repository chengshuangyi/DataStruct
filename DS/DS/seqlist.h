#ifndef _SEQLIST_H_
#define _SEQLIST_H_

#include"common.h"
#define ElemType int
#define SEQLIST_DEFAULT_SIZE 8

//����˳���Ľṹ
typedef struct SeqList
{
	ElemType *base;
	size_t capacity;
	size_t size;
}SeqList;


// �����ݵĹ���:��ɾ��� 
void SeqListInit(SeqList* plist);
//void SeqListDestory(SeqList* plist);
//
void SeqListPrint(SeqList* plist);
void SeqListPushBack(SeqList* plist, ElemType x);
void SeqListPushFront(SeqList* plist, ElemType x);
void SeqListPopFront(SeqList* plist);
void SeqListPopBack(SeqList* plist);
//
//// ˳������
//int SeqListFind(SeqList* plist, ElemType x);
//// ˳�����posλ�ò���x
//void SeqListInsert(SeqList* plist, size_t pos, ElemType x);
//// ˳���ɾ��posλ�õ�ֵ
//void SeqListErase(SeqList* plist, size_t pos);

#endif  //_SEQLIST_H_
