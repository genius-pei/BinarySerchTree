#pragma once
template<class k>
struct BSTnode
{
	k _key;
	BSTnode<k>* _left;
	BSTnode<k>* _right;
	BSTnode(const k& key)
		:_key(key)
		, _left(nullptr)
		, _right(nulllptr)
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
		Node* cur = _root;
		while (cur)
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
				return false;
			}
		}
	}
private:
	Node* _root = nullptr;
};
