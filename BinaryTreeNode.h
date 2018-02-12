#include<iostream>

using namespace std;

template<class T>
struct BinaryTreeNode
{
	T data;
	BinaryTreeNode<T> *left, *right;
};
