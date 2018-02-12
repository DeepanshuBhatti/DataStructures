#include <iostream>
using namespace std;

struct CircularLinkedListNode
{
	int data;
	struct CircularLinkedListNode *next;
};

class CircularLinkedList
{
private:
	struct CircularLinkedListNode * GetDataAllocated(int data)
	{
		struct CircularLinkedListNode* temp = (struct CircularLinkedListNode*)malloc(sizeof(struct CircularLinkedListNode));
		temp->data = data;
		temp->next = temp;
		return temp;
	}

public:
	struct CircularLinkedListNode *head;
	CircularLinkedList(int data)
	{
		head = GetDataAllocated(data);
	}

	void PrintCircularLinkedList()
	{
		auto current = head;
		while(current->next != head)
		{
			cout<<current->data<<"~>";
			current = current->next;
		}
		cout<<current->data<<"~>"<<endl;
	}

	void AddDataToEndOfCircularLinkedlist(int data)
	{
		auto elementNode = GetDataAllocated(data);
		auto temp = head;
		while(temp->next != head)
		{
			temp = temp->next;
		}
		temp->next = elementNode;
		elementNode->next = head;
	}

	void AddDataAtStartOfCircularLinkedList(int data)
	{
		auto elementNode = GetDataAllocated(data);
		auto temp = head;
		while(temp->next != head)
		{
			temp = temp->next;
		}
		temp->next = elementNode;
		elementNode->next = head;
		head = elementNode;
	}

	/*void DeleteDataFromStartOfCircularLinkedList(int data)
	{
		auto temp = head;
		while(temp->data == data)
		{
			temp = temp->next;
		}
		head = temp;
	}

	// TODO: Function Incorrect
	void DeleteAllOccurencesOfDataFromCircularLinkedList(int data)
	{
		DeleteDataFromStartOfCircularLinkedList(data);
		auto current = head;
		while(current != NULL && current->next != NULL)
		{
			if(current->next->data == data)
			{
				current->next = current->next->next;
				current->next->prev = current;
			}
			else
				current = current->next;
		}
	}*/

	void ReverseCircularLinkedList()
	{
		struct CircularLinkedListNode *next, *prev=NULL;
		auto current = head;
		do{
			next = current->next;
			current->next = prev;
			prev = current;
			current = next;
		}while(current != head);

		head->next = prev;
		head = prev;
	}
};
