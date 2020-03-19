#include "BinaryTreeNode.h"
/*/////////////////////////////////////////////////////////*/
template<class T>
inline BinaryTreeNode<T>::BinaryTreeNode(T* data)
	:m_data(data), m_left(nullptr), m_right(nullptr)
{
}
/*/////////////////////////////////////////////////////////*/
/*---------------------------------------------------------*/
/*/////////////////////////////////////////////////////////*/
template<class T>
BinaryTreeNode<T>::~BinaryTreeNode()
{
}
/*/////////////////////////////////////////////////////////*/
/*---------------------------------------------------------*/
/*/////////////////////////////////////////////////////////*/
template<class T>
bool BinaryTreeNode<T>::insertElement(BinaryTreeNode<T>* newNode, int lvl)
{
	if (*(newNode->getData()) < *m_data)
	{
		if (m_left == nullptr) { m_left = newNode; m_left->setLvl(lvl); }
		else { return m_left->insertElement(newNode, lvl+1); }
	}
	else if(*(newNode->getData()) > *m_data)
	{
		if (m_right == nullptr) { m_right = newNode; m_right->setLvl(lvl); }
		else { return m_right->insertElement(newNode, lvl+1); }
	}
	else
	{
		return false;
	}
	return true;
}
/*/////////////////////////////////////////////////////////*/
/*---------------------------------------------------------*/
/*/////////////////////////////////////////////////////////*/
template<class T>
BinaryTreeNode<T>* BinaryTreeNode<T>::deleteElement(T* data)
{
	BinaryTreeNode<T>* aux = this;

	if ((*data < *m_data) && (m_left != nullptr)) { m_left = m_left->deleteElement(data); }
	else if ((*data > *m_data)&&(m_right!=nullptr)) { m_right = m_right->deleteElement(data); }
	else // Found element
	{
		// No child
		if (m_left == nullptr && m_right == nullptr)
		{
			delete aux;
			aux = nullptr;
		}
		// One child
		else if (m_left == nullptr)
		{
			aux = m_right;
		}
		else if (m_right == nullptr)
		{
			aux = m_left;
		}
		// Two Children
		else
		{
			BinaryTreeNode<T>* minNode = getMinRight();
			m_data = minNode->getData();
			m_right = m_right->deleteElement(m_data);
		}
	}
	return aux;
}
/*/////////////////////////////////////////////////////////*/
/*---------------------------------------------------------*/
/*/////////////////////////////////////////////////////////*/
template<class T>
BinaryTreeNode<T>* BinaryTreeNode<T>::balanceSubTree(vector<BinaryTreeNode<T>>* vNodes, int vStart, int vEnd)
{
	int mid = (vStart + vEnd) / 2;
	cout << vStart << " ";
	cout << vEnd << " ";
	cout << mid << endl;

	if (vStart >= vEnd) 
	{
		cout << "-Termina recursión-" << endl;
		return nullptr; 
	}

	BinaryTreeNode<T>* aux = &(vNodes->at(mid));
	if (aux != nullptr)
	{
		aux->m_left = aux->balanceSubTree(vNodes, 0, mid);
		aux->m_right = aux->balanceSubTree(vNodes, mid + 1, vEnd);
		cout << "Termina balance de subarbol" << " ";
		cout << vStart << " ";
		cout << vEnd << " ";
		cout << mid << endl;
	}
	return aux;
}
/*/////////////////////////////////////////////////////////*/
/*---------------------------------------------------------*/
/*Print Elements*/
/*---------------------------------------------------------*/
/*/////////////////////////////////////////////////////////*/
template<class T>
void BinaryTreeNode<T>::in_order()
{
	if (m_left != nullptr)
	{
		m_left->in_order();
	}
	cout << " " << *m_data;
	if (m_right != nullptr)
	{
		m_right->in_order();
	}
}
/*/////////////////////////////////////////////////////////*/
/*---------------------------------------------------------*/
/*/////////////////////////////////////////////////////////*/
template<class T>
void BinaryTreeNode<T>::pre_order()
{
	cout << " " << *m_data;
	if (m_left != nullptr)
	{
		m_left->pre_order();
	}
	if (m_right != nullptr)
	{
		m_right->pre_order();
	}
}
/*/////////////////////////////////////////////////////////*/
/*---------------------------------------------------------*/
/*/////////////////////////////////////////////////////////*/
template<class T>
void BinaryTreeNode<T>::post_order()
{
	if (m_left != nullptr)
	{
		m_left->post_order();
	}
	if (m_right != nullptr)
	{
		m_right->post_order();
	}
	cout<<" " << *m_data;
}
/*/////////////////////////////////////////////////////////*/
/*---------------------------------------------------------*/
/*/////////////////////////////////////////////////////////*/
template<class T>
void BinaryTreeNode<T>::stackPrint()
{
	std::stack<BinaryTreeNode<T>> st;
	st.push(*this);
	while (!st.empty())
	{
		BinaryTreeNode<T> aux = (BinaryTreeNode<T>)st.top();
		st.pop();
		cout << *(aux.getData()) << endl;
		if (aux.m_right != nullptr)
		{
			st.push(*(aux.getRight()));
		}
		if (aux.m_left != nullptr)
		{
			st.push(*(aux.getLeft()));
		}
	}
}
/*/////////////////////////////////////////////////////////*/
/*---------------------------------------------------------*/
/*/////////////////////////////////////////////////////////*/
template<class T>
void BinaryTreeNode<T>::breadthFirstTraversal()
{
	queue<BinaryTreeNode<T>> qu;
	qu.push(*this);
	while (!qu.empty())
	{
		BinaryTreeNode<T> aux = (BinaryTreeNode<T>)qu.front();
		qu.pop();
		cout << *(aux.getData()) << " lvl: " << aux.getLvl() << endl;
		if (aux.m_left != nullptr)
		{
			qu.push(*(aux.getLeft()));
		}
		if (aux.m_right != nullptr)
		{
			qu.push(*(aux.getRight()));
		}
	}
}
/*/////////////////////////////////////////////////////////*/
/*---------------------------------------------------------*/
/*/////////////////////////////////////////////////////////*/
template<class T>
void BinaryTreeNode<T>::getAllElements(vector<BinaryTreeNode<T>> *vNodes)
{
	vNodes->push_back(*this);
	if (m_left != nullptr)
	{
		m_left->getAllElements(vNodes);
	}
	if (m_right != nullptr)
	{
		m_right->getAllElements(vNodes);
	}
}
/*/////////////////////////////////////////////////////////*/
/*---------------------------------------------------------*/
/*/////////////////////////////////////////////////////////*/
template<class T>
BinaryTreeNode<T>* BinaryTreeNode<T>::getMin(BinaryTreeNode<T>* root)
{
	while (root->m_left != nullptr) { root = root->m_left; }
	return root;
}
/*/////////////////////////////////////////////////////////*/
/*---------------------------------------------------------*/
/*/////////////////////////////////////////////////////////*/
template<class T>
BinaryTreeNode<T>* BinaryTreeNode<T>::getMinRight()
{
	BinaryTreeNode<T>* aux = m_right;
	while (aux->m_left != nullptr) { aux = aux->m_left; }
	return aux;
}
/*/////////////////////////////////////////////////////////*/