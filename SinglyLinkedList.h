#include <iostream>
using namespace std;

struct SinglyLinkedListNode
{
	int data;
	struct SinglyLinkedListNode * next;
};

class SinglyLinkedList
{
private:
	struct SinglyLinkedListNode *head;

	struct SinglyLinkedListNode * GetDataAllocated(int data)
	{
		struct SinglyLinkedListNode* temp = (struct SinglyLinkedListNode*)malloc(sizeof(struct SinglyLinkedListNode));
		temp->data = data;
		temp->next = NULL;
		return temp;
	}

public:

	SinglyLinkedList(int data)
	{
		head = GetDataAllocated(data);
	}

	void PrintLinkedList()
	{
		auto current = head;
		while(current != NULL)
		{
			cout<<current->data<<"->";
			current = current->next;
		}
		cout<<"NULL"<<endl;
	}

	void AddDataToEnd(int data)
	{
		auto elementNode = GetDataAllocated(data);
		auto temp = head;
		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = elementNode;
	}

	void AddDataAtStart(int data)
	{
		auto temp = GetDataAllocated(data);
		temp->next = head;
		head = temp;
	}

	void DeleteDataFromStartOfLL(int data)
	{
		auto temp = head;
		while(temp->data == data)
		{
			temp = temp->next;
		}
		head = temp;
	}
	void DeleteAllOccurencesOfDataFromLL(int data)
	{
		DeleteDataFromStartOfLL(data);
		auto temp = head;
		while(temp != NULL && temp->next != NULL)
		{
			if(temp->next->data == data)
				temp->next = temp->next->next;
			else
				temp = temp->next;
		}
	}

	void ReverseLL()
	{
		struct SinglyLinkedListNode* previous = NULL, *next;
		auto current = head;
		while(current != NULL)
		{
			next = current->next;
			current->next = previous;
			previous = current;
			current = next;
		}
		head = previous;
	}
};

