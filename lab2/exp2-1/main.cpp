#include "book.h"
#include<iostream>
// BST implementation
#include "BST.h"
using namespace std;
int main()
{
	BST<int, Int*> tree1;
	BST<int, Int*> tree2;
	Int* it;
	int m;

	cout << "Size tree1: " << tree1.size() << "\n";
	cout << "Size tree2: " << tree2.size() << "\n";
	for (int i = 1;i <= 100;i++) {
		cout << "tree1:请输入一个在1-100的整数（以0结束）" << endl;
		cin >> m;
		if (m == 0)
			break;
		else
			tree1.insert(m, new Int(m));
	}
	for (int i = 1;i <= 100;i++) {
		cout << "tree2:请输入一个在1-100的整数(以0结束)" << endl;
		cin >> m;
		if (m == 0)
			break;
		else
			tree2.insert(m, new Int(m));
	}
	cout <<'\n'<< "Size tree1: " << tree1.size() << "\n";
	cout << "Size tree2: " << tree2.size() << "\n";
	cout << "The tree1 is:" << endl;
	tree1.print();
	//tree1.leaf();
	//tree1.leafnumber();
	cout <<'\n'<< "The tree2 is:" << endl;
	tree2.print();
	//tree2.leaf();
	//tree2.leafnumber();


}