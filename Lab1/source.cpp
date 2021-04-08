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

template<typename T>
class List
{
public:
	List();
	~List();
	bool isFull();
	bool isEmpty();
	void makeEmpty();
	void addItem(T item);
	int deleteItem(T item);
	bool search(T item);
	int size();
private:
	int m_count;
	Node<T>* m_first;
};

template<typename T>
List<T>::List()
{
	m_count = 0;
	m_first = nullptr;
}

template<typename T>
List<T>::~List()
{
	Node<T>* tmp;
	while(m_first != nullptr)
	{
		tmp = m_first;
		m_first = m_first->m_next;
		delete tmp;
	}

	m_count = 0;

}


int main()
{
	

	return 0;
}