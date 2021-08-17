#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<windows.h>
struct Node
{
	int data;
	struct Node* next;
	struct Node* prev;
	bool head;
};

void AddToList(int data, struct Node* head);
void RemoveFromList(int data, struct Node* head);
void PrintLinkedList(struct Node* head);

int main(int arc, char* argv[])
{
	
	struct Node* head = (struct Node*)malloc(sizeof(struct Node));
	head->data = 5;
	head->next = NULL;
	head->prev = NULL;
	head->head = 1;
	AddToList(3, head);
	AddToList(8, head);
	AddToList(2, head);
	AddToList(9, head);
	PrintLinkedList(head);
	RemoveFromList(3, head);
	AddToList(11, head);
	AddToList(43, head);
	RemoveFromList(9, head);
	RemoveFromList(8, head);
	AddToList(37, head);
	PrintLinkedList(head);
	sleep(5);
}
//Adds a new node with the given data to the end of the list
void AddToList(int data, struct Node* head)
{
	struct Node* newNode = malloc(sizeof(struct Node));
	newNode->next = NULL;
	newNode->prev = NULL;
	newNode->data = data;
	newNode->head = 0;
	struct Node* currNode = head;
	while(currNode->next != NULL)
	{
		currNode = currNode->next;
	}
	currNode->next = newNode;
	newNode->prev = currNode;
}
//removes a node with the given data from the list assuming it exists within.
void RemoveFromList(int data, struct Node* head)
{
	struct Node* currNode = head;
	while(currNode->data != data && currNode->next != NULL)
	{
		currNode = currNode->next;
	}
	if(data == currNode->data)
	{
		if(!currNode->head)
		{
			currNode->prev->next = currNode->next;
			if(currNode->next != NULL)
			{
				currNode->next->prev = currNode->prev;
			}
		}
		//if the node being deleted is the head
		else
		{
			if(currNode->next != NULL)
			{
				currNode->next->prev = NULL;
				currNode->next->head = true;
			}
		}
		free(currNode);
	}
	else
	{
		printf("COULD NOT DETECT NODE WITH DATA %d\n", data);
	}
}

void PrintLinkedList(struct Node* head)
{
	struct Node* currNode = head;
	while(currNode->next != NULL)
	{
		printf("%d ", currNode->data);
		currNode = currNode->next;
	}
	printf("%d \n", currNode->data);
}