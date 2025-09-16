#define _CRT_SECURE_NO_WARNINGS

#include"tree.h"
//
//int main()
//{
//	int a[] = { 2,4,3,6,8,7,5,9 };
//	BSTree<int> t1;
//	for (auto e : a)
//	{
//		t1.insertR(e);
//	}
//	t1.InOrder();
//	t1.Erase(5);
//	cout << endl;
//	t1.InOrder();
//	return 0;
//}
int main()
{
	string arr[] = { "苹果", "西瓜", "苹果","苹果","苹果", "苹果", "苹果", "西瓜", "苹果", "香蕉", "火龙果", "香蕉" };
	key_value::BSTree<string, int> t;
	for (auto& str : arr)
	{
		auto pNode = t.Find(str);
		if (pNode == nullptr)
		{
			t.Insert(str, 1);
		}
		else
		{
			pNode->_value++;
		}
	}

	t.InOrder();

	return 0;
}



