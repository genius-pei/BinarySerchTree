#define _CRT_SECURE_NO_WARNINGS

#include"tree.h"

int main()
{
	int a[] = { 2,4,3,6,8,7,5,9 };
	BSTree<int> t1;
	for (auto e : a)
	{
		t1.insertR(e);
	}
	t1.InOrder();
	t1.Erase(5);
	cout << endl;
	t1.InOrder();
	return 0;
}

