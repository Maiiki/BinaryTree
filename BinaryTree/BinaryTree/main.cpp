#include "BinaryTree.h"
#include "BinaryTree_Impl.cpp"
#include <vector>
#include <stdlib.h>
#include <time.h>


int main()
{
	srand(time(NULL));
	BinaryTree<int> iTest;
	//vector<int> vNums = { 7,3,11,2,9,6,20,8,5,4,1 };
	vector<int> vNums = { 11,10,9};
	
	//for (size_t i = 0; i < 10; i++)
	//{
	//	vNums.push_back(rand() % 100 + 1);
	//}

	//for (size_t i = 0; i < vNums.size(); i++)
	//{
	//	iTest.insertElement(&vNums[i]);
	//}

	for (size_t i = 0; i < vNums.size(); i++)
	{
		iTest.insertElement(&vNums[i]);
	}

	/*cout << "In order:\t"; iTest.in_order(); cout << endl;
	cout << "Post order:\t"; iTest.post_order(); cout << endl;
	cout << "Pre order:\t"; iTest.pre_order(); cout << endl;

	int num = 7;
	iTest.deleteElementTwo(&num);
	cout << "Deleted: " << num << endl;
	
	cout << "In order deleted:\t"; iTest.in_order(); cout << endl;
	cout << "Post order deleted:\t"; iTest.post_order(); cout << endl;
	cout << "Pre order deleted:\t"; iTest.pre_order(); cout << endl;*/
	iTest.breadthFirstTraversal();
	cout << endl << "Balanced:" << endl;
	iTest.balanceTree();
	cout << "Pre order :\t"; iTest.pre_order(); cout << endl;
	cout << "In order :\t"; iTest.in_order(); cout << endl;
	iTest.breadthFirstTraversal();

	/*system("pause");
	system("close");*/
	return 0;
}