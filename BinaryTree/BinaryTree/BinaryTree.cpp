#include "BinaryTree.h"

template<class T>
BinaryTree<T>::BinaryTree()
	:m_root(nullptr), m_size(0)
{
}

template<class T>
BinaryTree<T>::~BinaryTree()
{
}

template<class T>
inline bool BinaryTree<T>::insertElement(T* data)
{
	BinaryTreeNode<T>* newNode = nullptr;
	newNode = new BinaryTreeNode<T>(data);
	if (m_root == nullptr)
	{
		m_root = newNode;
		m_root->setLvl(0);
		cout << "m_root es NULL y data es " << *(m_root->getData()) << " " << m_root->getLvl() << endl;
	}
	else
	{
		if (m_root->insertElement(newNode, 1)) 
		{ 
			m_size++;
			return true; 
		}
		else 
		{ 
			delete newNode;
			return false;
		}
	}
	m_size++;
	return true;
}

template<class T>
bool BinaryTree<T>::deleteElement(T* data)
{
	if (m_root != nullptr) { return m_root = m_root->deleteElement(data); }
}

template<class T>
bool BinaryTree<T>::deleteElementTwo(T* data)
{
	if (m_root != nullptr) { return m_root = m_root->deleteElement(data); }
}

template<class T>
void BinaryTree<T>::balanceTree()
{
	//crear un vector de Nodos usando un metodo de recorrido (in-order)
	vector<BinaryTreeNode<T>> vNodes;
	m_root->getAllElements(&vNodes);
	BinaryTreeNode<T>* newRoot;
	newRoot = m_root->balanceSubTree(&vNodes, 0, vNodes.size() - 1);
}
