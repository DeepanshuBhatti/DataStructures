#include <iostream>
using namespace std;

struct DoublyLinkedListNode
{
	int data;
	struct DoublyLinkedListNode *next, *prev;
};

class DoublyLinkedList
{
private:
	struct DoublyLinkedListNode * GetDataAllocated(int data)
	{
		struct DoublyLinkedListNode* temp = (struct DoublyLinkedListNode*)malloc(sizeof(struct DoublyLinkedListNode));
		temp->data = data;
		temp->next = NULL;
		temp->prev = NULL;
		return temp;
	}

public:
	struct DoublyLinkedListNode *head;
	DoublyLinkedList(int data)
	{
		head = GetDataAllocated(data);
	}

	void PrintDoublyLinkedList()
	{
		cout<<"NULL<=>";
		auto t = head;
		while(t != NULL)
		{
			cout<<t->data<<"<=>";
			t = t->next;
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
		elementNode->prev = temp;
	}

	void AddDataAtStart(int data)
	{
		auto temp = GetDataAllocated(data);
		temp->next = head;
		head->prev = temp;
		head = temp;
	}

	void DeleteDataFromStartOfDoublyLinkedList(int data)
	{
		auto temp = head;
		while(temp->data == data)
		{
			temp = temp->next;
		}
		temp->prev = NULL;
		head = temp;
	}

	// TODO: Function Incorrect
	void DeleteAllOccurencesOfDataFromDoublyLinkedList(int data)
	{
		DeleteDataFromStartOfDoublyLinkedList(data);
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
	}

	void ReverseDoublyLinkedList()
	{
		auto current = head;
		struct DoublyLinkedListNode* temp;
		while(current != NULL)
		{
			temp = current->prev;
			current->prev = current->next;
			current->next = temp;
			current =  current->prev;
		}
		if(temp != NULL)
			head = temp->prev;
	}
};
