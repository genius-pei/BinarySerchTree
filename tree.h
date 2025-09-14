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
	bool insertR(const k& key)
	{
		return _Insert(_root,key);
	}
	bool Find(const k& key)
	{
		Node* cur = _root;

		while (cur)//确定新插入值的位置
		{
			if (cur->_key < key)
			{
				cur = cur->_right;
			}
			else if (cur->_key > key)
			{
				cur = cur->_left;
			}
			else
			{
				return true;
			}
			return false;
		}
	}
	bool Erase(const k& key)
	{
		
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
			else//准备删除
			{
				if (cur->_left == nullptr)//左为空
				{
					if (cur != _root)
					{
						if (cur == parent->_left)//如果要删除的是左节点
						{
							parent->_left = cur->_right;
						}
						else
						{
							parent->_right = cur->_right;
						}
					}
					else
					{
						_root = cur->_right;
					}


					delete cur;
				}
				else if (cur->_right==nullptr)//右为空
				{
					if (cur != _root)
					{
						if (cur == parent->_left)//如果要删除的是左节点
						{
							parent->_left = cur->_right;
						}
						else
						{
							parent->_right = cur->_right;
						}
					}
					else
					{
						_root = cur->_left;
					}
					delete cur;
				}
				else//左右都不为空,找子树适合的节点替代，最小的右节点，或者最大的左节点
				{
					Node* minrightparent = cur;
					Node* minright = cur->_right;
					{
						while (minright->_left)
						{
							minrightparent = minright;
							minright = minright->_left;
						}
						swap(cur->_key, minright->_key);
						if (minright == minrightparent->_left)
						{
							minrightparent->_left = minright->_right;
						}
						else
						{
							minrightparent->_right = minright->_right;
						}
						delete minright;
					}
				}
				return true;
			}

		}

		return false;
	}
private:
	 bool _Insert(Node*& root,const k& key)
	 {
		 if (root == nullptr)
		 {
			 root = new Node(key);
			 return true;
		 }
		 if (root->_key < key)
		 {
			 return _Insert(root->_right, key);
		 }
		 else if (root->_key > key)
		 {
			 return _Insert(root->_left, key);
		 }
		 else
		 {
			 return false;
		 }
	 }
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

