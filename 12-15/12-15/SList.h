#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

typedef int SLDataType;
//���
typedef struct SListNode
{
	SLDataType data;
	struct SListNode *next;
}SListNode;

// ��̬����һ���ڵ�
SListNode* BuySListNode(SLDataType x);

// �������ӡ
void SListPrint(SListNode* plist);

// ������β��
void SListPushBack(SListNode** pplist, SLDataType x);

// �������ͷ��
void SListPushFront(SListNode** pplist, SLDataType x);

// �������βɾ
void SListPopBack(SListNode** pplist);

// ������ͷɾ
void SListPopFront(SListNode** pplist);

// ���������
SListNode* SListFind(SListNode* plist, SLDataType x);

// ��������posλ��֮�����x,����˼��Ϊʲô����posλ��֮ǰ���룿
void SListInsertAfter(SListNode* pos, SLDataType x);

// ������ɾ��posλ��֮���ֵ,����˼��Ϊʲô��ɾ��posλ�ã�
void SListEraseAfter(SListNode* pos);

// �����������
void SListDestory(SListNode* plist);
