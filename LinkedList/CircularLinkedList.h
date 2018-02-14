#include "SinglyLinkedListNode.h"

template<class T>
class CircularLinkedList
{
private:
	SinglyLinkedListNode<T> *GetDataAllocated(T data)
	{
		SinglyLinkedListNode<T> *temp = (SinglyLinkedListNode<T> *)malloc(sizeof(SinglyLinkedListNode<T>));
		temp->data = data;
		temp->next = temp;
		return temp;
	}

public:
	SinglyLinkedListNode<T> *head;
	CircularLinkedList(T data)
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

	void AddDataToEndOfCircularLinkedlist(T data)
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

	void AddDataAtStartOfCircularLinkedList(T data)
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
};
