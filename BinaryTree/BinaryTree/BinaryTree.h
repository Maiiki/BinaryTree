#pragma once
#include "BinaryTreeNode.h"

template<class T>
class BinaryTree
{
private:
	BinaryTreeNode<T>* m_root;
	int m_size;
public:
	BinaryTree();
	~BinaryTree();
	bool insertElement(T* data);
	bool deleteElement(T* data);
	bool deleteElementTwo(T* data);
	void balanceTree();
	inline bool isEmpty() { return (m_size == 0); }
	inline int treeSize() { return m_size; }
	inline void in_order() { if (m_root != nullptr) { m_root->in_order(); } }
	inline void pre_order() { if (m_root != nullptr) { m_root->pre_order(); } }
	inline void post_order() { if (m_root != nullptr) { m_root->post_order(); } }
	inline void stackPrint() { if (m_root != nullptr) { m_root->stackPrint(); } }
	inline void breadthFirstTraversal() { if (m_root != nullptr) { m_root->breadthFirstTraversal(); } }
};
