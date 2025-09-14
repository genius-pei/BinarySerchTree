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
		
		while (cur)//ȷ���²���ֵ��λ��
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
	void InOrder()//�޷�ֱ�ӵ��ø���Ƕ��һ��
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

		while (cur)//ȷ���²���ֵ��λ��
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

		while (cur)//ȷ���²���ֵ��λ��
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
			else//׼��ɾ��
			{
				if (cur->_left == nullptr)//��Ϊ��
				{
					if (cur != _root)
					{
						if (cur == parent->_left)//���Ҫɾ��������ڵ�
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
				else if (cur->_right==nullptr)//��Ϊ��
				{
					if (cur != _root)
					{
						if (cur == parent->_left)//���Ҫɾ��������ڵ�
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
				else//���Ҷ���Ϊ��,�������ʺϵĽڵ��������С���ҽڵ㣬����������ڵ�
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
	void _InOrder(Node* root)//����������
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

