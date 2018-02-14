#include "DoublyLinkedListNode.h"

template<class T>
class DoublyLinkedList
{
private:
	DoublyLinkedListNode<T> * GetDataAllocated(T data)
	{
		DoublyLinkedListNode<T> *temp = (DoublyLinkedListNode<T> *)malloc(sizeof(DoublyLinkedListNode<T>));
		temp->data = data;
		temp->next = NULL;
		temp->prev = NULL;
		return temp;
	}

public:
	DoublyLinkedListNode<T> *head;
	DoublyLinkedList(T data)
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

	void AddDataToEnd(T data)
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

	void AddDataAtStart(T data)
	{
		auto temp = GetDataAllocated(data);
		temp->next = head;
		head->prev = temp;
		head = temp;
	}

	void DeleteDataFromStartOfDoublyLinkedList(T data)
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
	void DeleteAllOccurencesOfDataFromDoublyLinkedList(T data)
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
		DoublyLinkedListNode<T> *temp;
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
