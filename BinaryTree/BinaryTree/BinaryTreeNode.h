#pragma once
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
using namespace std;

template <class T>
class BinaryTreeNode
{
private:
	T* m_data;
	BinaryTreeNode<T>* m_left;
	BinaryTreeNode<T>* m_right;
	int m_lvl;

public:
	BinaryTreeNode(T * data);
	~BinaryTreeNode();

	/*MODIFY TREE----------------------------------------------*/
	bool insertElement(BinaryTreeNode<T>* newNode, int lvl);
	BinaryTreeNode<T>* deleteElement(T* data);
	BinaryTreeNode<T>* balanceSubTree(vector<BinaryTreeNode<T>>*vNode, int start, int end);
	
	/*PRINT ELEMENTS-------------------------------------------*/
	void in_order();
	void pre_order();
	void post_order();
	void stackPrint();
	void breadthFirstTraversal();

	/*---------------------------------------------------------*/
	inline T* getData() { return m_data; }
	inline BinaryTreeNode<T>* getLeft() { return m_left; }
	inline BinaryTreeNode<T>* getRight() { return m_right; }
	inline int getLvl() { return m_lvl; }
	void getAllElements(vector<BinaryTreeNode<T>> *vNodes); //Saves all the elements in order in a vector
	BinaryTreeNode<T>* getMin(BinaryTreeNode<T>* root); //Gets the minimum value in the branches starting from root
	BinaryTreeNode<T>* getMinRight(); //Gets the minimum value in the m_Right branches starting from actual node


	/*---------SET STUFF--------*/
	inline void setLeft(BinaryTreeNode<T>* newNode) { m_left = newNode; }
	inline void setRight(BinaryTreeNode<T>* newNode) { m_right = newNode; }
	inline void setData(T* data) { m_data = data; }
	inline void setLvl(int lvl) { m_lvl = lvl; }
};
