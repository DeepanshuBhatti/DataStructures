#include <iostream>
using namespace std;

template<typename U>
struct SinglyLinkedListNode
{
	U data;
	SinglyLinkedListNode<U> * next;
};
