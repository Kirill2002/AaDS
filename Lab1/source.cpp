#include <iostream>
using namespace std;

template<typename T>
struct Node
{
	T m_data;
	Node<T>* m_next;

	Node();
	Node(T data, Node<T>* next = nullptr);
};

template<typename T>
Node<T>::Node()
{
	m_next = nullptr;
}


template<typename T>
Node<T>::Node(T data, Node<T>* next)
{
	m_data = data;
	m_next = next;
}


int main()
{
	

	return 0;
}