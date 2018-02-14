#include "BinaryTree.h"

using namespace std;

template <class T>
class BinarySearchTree: public BinaryTree<T>
{
	BinaryTreeNode<T> *bstRoot;
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
	BinarySearchTree(T data): BinaryTree<T>(data)
	{
		bstRoot = this->root;
	}
	T GetInOrderSuccessor(T data);
	T GetInOrderPredecessor(T data);
	void PrintTraversals()
	{
		cout<<"\nInOrder: ";
		PrintInOrderTraversalOfBinarySearchTree(bstRoot);
		cout<<"\nPreOrder: ";
		PrintPreOrderTraversalOfBinarySearchTree(bstRoot);
		cout<<"\nPostOrder: ";
		PrintPostOrderTraversalOfBinarySearchTree(bstRoot);
	}


	void InsertElementInBinarySearchTree(T data)
	{
		auto node = this->CreateBinaryTreeNode(data);
		RecursiveInsertionInBinarySearchTree(bstRoot, node);
	}

	void FindElementInBinarySearchTree(T data)
	{
		auto node = CreateBinaryTreeNode(data);
		if(RecursivlyFindElementInBinarySearchTree(bstRoot, node))
		{
			cout<<"Element Found in BinarySearchTree"<<endl;
		}
		else
			cout<<"Element Not Found"<<endl;
	}

	BinaryTreeNode<T> * FindNodeInBinarySearchTree(T data)
	{
		BinaryTreeNode<T> *temp = bstRoot;
		while(temp != NULL && temp->data != data)
		{
			if(temp->data > data)
				temp = temp->left;
			else
				temp = temp->right;
		}
		return temp;
	}


};

template <class T>
T BinarySearchTree<T>::GetInOrderSuccessor(T data)
{
	BinaryTreeNode<T> *targetNode = FindNodeInBinarySearchTree(data);
	if(targetNode->right != NULL)
	{
		targetNode = targetNode->right;
		while(targetNode->left!=NULL)
			targetNode = targetNode->left;
		return targetNode->data;
	}
	BinaryTreeNode<T> *currentNode = bstRoot;
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

template <class T>
T BinarySearchTree<T>::GetInOrderPredecessor(T data)
{
	BinaryTreeNode<T> *targetNode = FindNodeInBinarySearchTree(data);
	if(targetNode->left != NULL)
	{
		targetNode = targetNode->left;
		while(targetNode->right!=NULL)
			targetNode = targetNode->right;
		return targetNode->data;
	}
	BinaryTreeNode<T> *currentNode = bstRoot;
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
