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
class SortedList
{
public:
	SortedList(bool asc_order = 1);
	~SortedList();
	bool isFull();
	bool isEmpty();
	void makeEmpty();
	void addItem(T item);
	int deleteItem(T item);
	bool search(T item);
	int size();
private:
	int m_count;
	bool m_asc_order;
	Node<T>* m_first;
};

template<typename T>
SortedList<T>::SortedList(bool asc_order)
{
	m_count = 0;
	m_first = nullptr;
	m_asc_order = asc_order;
}

template<typename T>
SortedList<T>::~SortedList()
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

template<typename T>
bool SortedList<T>::isEmpty()
{
	return m_count == 0;
}

template<typename T>
bool SortedList<T>::isFull()
{
	
	Node<T>* tmp;
	tmp = new Node<T>;
	if(tmp == nullptr) return 1;

	delete tmp;
	return 0;
}

template<typename T>
void SortedList<T>::addItem(T item)
{
	
	
}




int main()
{
	

	return 0;
}