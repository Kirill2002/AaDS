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
	int count;
	Node<T>* first;
};

template<typename T>
List<T>::List()
{
	count = 0;
	first = nullptr;
}


int main()
{
	

	return 0;
}