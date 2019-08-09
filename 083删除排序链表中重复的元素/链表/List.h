#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef struct NodeList
{
	struct NodeList *next;
	int value;
}NodeList;


NodeList *Init();
NodeList *Push(NodeList *N , int value);
NodeList *deleteDuplicates(NodeList *N);
void NodePri(NodeList *N);