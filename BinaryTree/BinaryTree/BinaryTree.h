#pragma once
//#include<stdio.h>
//#include<stdlib.h>
#include"Queue.h"

//�����¶������ڵ�
BTNode *CreatNode(BTDataType a);

// ͨ��ǰ�����������"ABD##E#H##CF##G##"����������
BTNode* BTCreate(BTDataType* a, int* pi);

// ����������
void BTDestory(BTNode* root);

// �������ڵ����
int BTSize(BTNode* root);

// ������Ҷ�ӽڵ����
int BTLeafSize(BTNode* root);

// ��������k��ڵ����
int BTLevelKSize(BTNode* root, int k);

// ����������ֵΪx�Ľڵ�
BTNode* BTFind(BTNode* root, BTDataType x);

// ������ǰ����� 
void BTPrevOrder(BTNode* root);

// �������������
void BTInOrder(BTNode* root);

// �������������
void BTPostOrder(BTNode* root);

// �������
void BTLevelOrder(BTNode* root);

// �ж϶������Ƿ�����ȫ������
int BTComplete(BTNode* root);