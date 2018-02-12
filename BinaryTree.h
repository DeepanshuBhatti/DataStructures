#include <iostream>
#include <queue>
#include "BinaryTreeNode.h"

using namespace std;

template <typename T>
class BinaryTree
{
private:
	BinaryTreeNode<T> *root;
	BinaryTreeNode<T>* GetDataAllocated(T data)
	{
		BinaryTreeNode<T>* temp = (BinaryTreeNode<T>*)malloc(sizeof(BinaryTreeNode<T>));
		temp->data = data;
		temp->left = NULL;
		temp->right = NULL;
		return temp;
	}
public:
	BinaryTree(T data)
	{
		root = GetDataAllocated(data);
	}

	void PrintBinaryTree()
	{
		queue<BinaryTreeNode<T>*> binaryTreeQueue;
		binaryTreeQueue.push(root);
		while(!binaryTreeQueue.empty())
		{
			auto tempElement = binaryTreeQueue.front();
			cout<<tempElement->data<<" (";
			if(tempElement->left!=NULL)
			{
				binaryTreeQueue.push(tempElement->left);
				cout<<"L-"<<tempElement->left->data<<" ";
			}
			else
				cout<<"L-NULL ";
			if(tempElement->right!=NULL)
			{
				binaryTreeQueue.push(tempElement->right);
				cout<<"R-"<<tempElement->right->data<<")\n";
			}
			else
				cout<<"R-NULL)"<<endl;
			binaryTreeQueue.pop();
		}
	}

	void InsertElementInBinaryTree(int data)
	{
		auto current = GetDataAllocated(data);
		//InsertRecursivly(root, current);
		InsertInBinaryTree(current);

	}

	void InsertInBinaryTree(BinaryTreeNode<T>* elementNode)
	{
		queue<BinaryTreeNode<T>*> binaryTreeQueue;
		binaryTreeQueue.push(root);
		while(!binaryTreeQueue.empty())
		{
			auto tempElement = binaryTreeQueue.front();
			if(tempElement->left!=NULL)
			{
				binaryTreeQueue.push(tempElement->left);
			}
			else
			{
				tempElement->left = elementNode;
				break;
			}
			if(tempElement->right!=NULL)
			{
				binaryTreeQueue.push(tempElement->right);
			}
			else
			{
				tempElement->right = elementNode;
				break;
			}
			binaryTreeQueue.pop();
		}
	}


	void InsertRecursivly(BinaryTreeNode<T>* currentNode, BinaryTreeNode<T>* elementNode)
	{
		if(currentNode->left == NULL)
		{
			currentNode->left = elementNode;
			return;
		}
		else if(currentNode->right == NULL)
		{
			currentNode->right = elementNode;
			return;
		}
	}
};
