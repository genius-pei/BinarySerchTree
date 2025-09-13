#pragma once
#include<iostream>
using namespace std;
template<class k>

struct BSTnode
{
	k _key;
	BSTnode<k>* _left;
	BSTnode<k>* _right;
	BSTnode(const k& key)
		:_key(key)
		, _left(nullptr)
		, _right(nullptr)
	{

	}
};
template<class k>
class BSTree
{
	typedef BSTnode<k> Node;
public:
	bool insert(const k& key)
	{
		if (_root == nullptr)
		{
			_root = new Node(key);
			return true;
		}
		Node* parent = nullptr;
		Node* cur = _root;
		
		while (cur)//确定新插入值的位置
		{
			if (cur->_key < key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_key > key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return false;
			}
		}
		cur = new Node(key);
		if (parent->_key < key)
		{
			parent->_right = cur;
		}
		else
		{
			parent->_left = cur;
		}

		return true;
	}
	void InOrder()//无法直接调用根，嵌套一层
	{
		_InOrder(_root);
	}
	bool Find(const K& key)
	{
		Node* cur = _root;

		while (cur)//确定新插入值的位置
		{
			if (cur->_key < key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_key > key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return true;
			}
			return false;
		}
	}
private:
	void _InOrder(Node* root)//中序，左中右
	{
		if (root == nullptr)
		{
			return;
		}
		_InOrder(root->_left);
		cout << root->_key << " ";
		_InOrder(root->_right);
	}
private:
	Node* _root = nullptr;
};

