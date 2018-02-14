#include <iostream>
#include <queue>
#include "BinaryTreeNode.h"

using namespace std;

template <class U>
class BinaryTree
{
protected:
	BinaryTreeNode<U> *root;
	BinaryTreeNode<U>* CreateBinaryTreeNode(U data)
	{
		BinaryTreeNode<U>* temp = (BinaryTreeNode<U>*)malloc(sizeof(BinaryTreeNode<U>));
		temp->data = data;
		temp->left = NULL;
		temp->right = NULL;
		return temp;
	}
public:
	BinaryTree(U data)
	{
		root = CreateBinaryTreeNode(data);
	}

	void PrintBinaryTree()
	{
		queue<BinaryTreeNode<U>*> binaryTreeQueue;
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

	void InsertElementInBinaryTree(U data)
	{
		auto current = GetDataAllocated(data);
		//InsertRecursivly(root, current);
		InsertInBinaryTree(current);

	}

	void InsertInBinaryTree(BinaryTreeNode<U>* elementNode)
	{
		queue<BinaryTreeNode<U>*> binaryTreeQueue;
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
};
