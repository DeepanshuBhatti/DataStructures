#include<iostream>
#include<queue>

using namespace std;

struct BinaryTreeNode
{
	int data;
	struct BinaryTreeNode *left, *right;
};


class BinaryTree
{
private:
	struct BinaryTreeNode *root;
	struct BinaryTreeNode* GetDataAllocated(int data)
	{
		struct BinaryTreeNode* temp = (struct BinaryTreeNode*)malloc(sizeof(struct BinaryTreeNode));
		temp->data = data;
		temp->left = NULL;
		temp->right = NULL;
		return temp;
	}
public:
	BinaryTree(int data)
	{
		root = GetDataAllocated(data);
	}

	void PrintBinaryTree()
	{
		queue<struct BinaryTreeNode*> binaryTreeQueue;
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

	void InsertInBinaryTree(struct BinaryTreeNode* elementNode)
	{
		queue<struct BinaryTreeNode*> binaryTreeQueue;
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


	void InsertRecursivly(struct BinaryTreeNode* currentNode, struct BinaryTreeNode* elementNode)
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
