#include "SinglyLinkedListNode.h"

template<class T>
class SinglyLinkedList
{
private:
	SinglyLinkedListNode<T> *head;
	SinglyLinkedListNode<T> *GetDataAllocated(T data)
	{
		SinglyLinkedListNode<T> *temp = (SinglyLinkedListNode<T>*)malloc(sizeof( SinglyLinkedListNode<T>));
		temp->data = data;
		temp->next = NULL;
		return temp;
	}

public:
	SinglyLinkedList(T data)
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

	void AddDataToEnd(T data)
	{
		auto elementNode = GetDataAllocated(data);
		auto temp = head;
		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = elementNode;
	}

	void AddDataAtStart(T data)
	{
		auto temp = GetDataAllocated(data);
		temp->next = head;
		head = temp;
	}

	void DeleteDataFromStartOfLL(T data)
	{
		auto temp = head;
		while(temp->data == data)
		{
			temp = temp->next;
		}
		head = temp;
	}
	void DeleteAllOccurencesOfDataFromLL(T data)
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
		SinglyLinkedListNode<T> *previous = NULL, *next;
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

