#include <iostream>
using namespace std;

template<typename U>
struct DoublyLinkedListNode
{
	U data;
	DoublyLinkedListNode<U> *next, *prev;
};
