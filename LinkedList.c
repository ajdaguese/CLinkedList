#include<stdio.h>
struct Node
{
	int data;
	Node* next;
	Node* prev;
	bool head;
};

void addToList(int data);
void removeFromList(int data);