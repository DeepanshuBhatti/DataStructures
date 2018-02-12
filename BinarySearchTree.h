#include <iostream>
#include <queue>
#include "BinaryTreeNode.h"

using namespace std;

template <typename T>
class BinarySearchTree
{
	BinaryTreeNode<T> *root;
	BinaryTreeNode<T> *CreateBinaryTreeNode(T data)
	{
		BinaryTreeNode<T> *tempNode = (BinaryTreeNode<T> *)malloc(sizeof(BinaryTreeNode<T>));
		tempNode->data = data;
		tempNode->left = NULL;
		tempNode->right = NULL;
		return tempNode;
	}
	void RecursiveInsertionInBinarySearchTree(BinaryTreeNode<T> *current, BinaryTreeNode<T> *node)
	{
		if(node->data <= current->data)
		{
			if(current->left == NULL)
			{
				current->left = node;
				return;
			}
			RecursiveInsertionInBinarySearchTree(current->left, node);
		}
		else
		{
			if(current->right == NULL)
			{
				current->right = node;
				return;
			}
			RecursiveInsertionInBinarySearchTree(current->right, node);
		}
	}
	bool RecursivlyFindElementInBinarySearchTree(BinaryTreeNode<T> *current, BinaryTreeNode<T> *node)
	{
		if(current == NULL)
			return false;
		if(current->data == node->data)
			return true;
		return RecursivlyFindElementInBinarySearchTree(current->left, node) || RecursivlyFindElementInBinarySearchTree(current->right, node);
	}
	void PrintInOrderTraversalOfBinarySearchTree(BinaryTreeNode<T> *current)
	{
		if(current == NULL)
			return;
		PrintInOrderTraversalOfBinarySearchTree(current->left);
		cout<<current->data<<" ";
		PrintInOrderTraversalOfBinarySearchTree(current->right);
	}
	void PrintPreOrderTraversalOfBinarySearchTree(BinaryTreeNode<T> *current)
	{
		if(current == NULL)
			return;
		cout<<current->data<<" ";
		PrintInOrderTraversalOfBinarySearchTree(current->left);
		PrintInOrderTraversalOfBinarySearchTree(current->right);
	}
	void PrintPostOrderTraversalOfBinarySearchTree(BinaryTreeNode<T> *current)
	{
		if(current == NULL)
			return;
		PrintInOrderTraversalOfBinarySearchTree(current->left);
		PrintInOrderTraversalOfBinarySearchTree(current->right);
		cout<<current->data<<" ";
	}
public:
	BinarySearchTree(T data)
	{
		root = CreateBinaryTreeNode(data);
	}

	void PrintBinarySearchTree()
	{
		queue<BinaryTreeNode<T> *>  q;
		q.push(root);
		while(!q.empty())
		{
			BinaryTreeNode<T> *current = q.front();
			cout<<current->data<<" (";
			if(current->left != NULL)
			{
				cout<<"L="<<current->left->data<<" ";
				q.push(current->left);
			}
			else
				cout<<"L=NULL ";
			if(current->right != NULL)

			{
				cout<<"R="<<current->right->data<<")\n";
				q.push(current->right);
			}
			else
				cout<<"R=NULL)\n";
			q.pop();
		}
	}

	void PrintTraversals()
	{
		cout<<"\nInOrder: ";
		PrintInOrderTraversalOfBinarySearchTree(root);
		cout<<"\nPreOrder: ";
		PrintPreOrderTraversalOfBinarySearchTree(root);
		cout<<"\nPostOrder: ";
		PrintPostOrderTraversalOfBinarySearchTree(root);
	}


	void InsertElementInBinarySearchTree(T data)
	{
		auto node = CreateBinaryTreeNode(data);
		RecursiveInsertionInBinarySearchTree(root, node);
	}

	void FindElementInBinarySearchTree(T data)
	{
		auto node = CreateBinaryTreeNode(data);
		if(RecursivlyFindElementInBinarySearchTree(root, node))
		{
			cout<<"Element Found in BinarySearchTree"<<endl;
		}
		else
			cout<<"Element Not Found"<<endl;
	}

	BinaryTreeNode<T> * FindNodeInBinarySearchTree(T data)
	{
		BinaryTreeNode<T> *temp = root;
		while(temp != NULL && temp->data != data)
		{
			if(temp->data > data)
				temp = temp->left;
			else
				temp = temp->right;
		}
		return temp;
	}

	T GetInOrderPredecessor(T data)
	{
		BinaryTreeNode<T> *targetNode = FindNodeInBinarySearchTree(data);
		if(targetNode->left != NULL)
		{
			targetNode = targetNode->left;
			while(targetNode->right!=NULL)
				targetNode = targetNode->right;
			return targetNode->data;
		}
		BinaryTreeNode<T> *currentNode = root;
		BinaryTreeNode<T> *predecessorNode = NULL;
		while(currentNode->data != targetNode->data)
		{
			if(targetNode->data > currentNode->data)
			{
				predecessorNode = currentNode;
				currentNode = currentNode->right;
			}
			else
				currentNode = currentNode->left;
		}
		if(predecessorNode != NULL)
			return predecessorNode->data;
		else
			return (T)NULL;
	}

	T GetInOrderSuccessor(T data)
	{
		BinaryTreeNode<T> *targetNode = FindNodeInBinarySearchTree(data);
		if(targetNode->right != NULL)
		{
			targetNode = targetNode->righ;
			while(targetNode->left!=NULL)
				targetNode = targetNode->left;
			return targetNode->data;
		}
		BinaryTreeNode<T> *currentNode = root;
		BinaryTreeNode<T> *successorNode = NULL;
		while(currentNode->data != targetNode->data)
		{
			if(targetNode->data <= currentNode->data)
			{
				successorNode = currentNode;
				currentNode = currentNode->left;
			}
			else
				currentNode = currentNode->right;
		}
		if(successorNode != NULL)
			return successorNode->data;
		else
			return (T)NULL;
	}
};
