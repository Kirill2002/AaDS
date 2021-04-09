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
	bool deleteItem(T item);
	bool search(T item);
	int size();
	void PrintList();
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
	Node<T>* tmp = m_first;
	if(!isFull())
	{
		if(m_count == 0)
		{
			m_first = new Node<T>(item, nullptr);
		}else
		{
			if(m_asc_order)
			{
				if(tmp->m_data >= item)
				{
					m_first = new Node<T>(item, m_first);
				}else
				{
					while(tmp->m_next != nullptr && tmp->m_next->m_data < item) tmp = tmp->m_next;
					tmp->m_next = new Node<T>(item, tmp->m_next);
				}
				
			}else
			{
				if(tmp->m_data <= item)
				{
					m_first = new Node<T>(item, m_first);
				}else
				{
					while(tmp->m_next != nullptr && tmp->m_next->m_data > item) tmp = tmp->m_next;
					tmp->m_next = new Node<T>(item, tmp->m_next);
				}
			}
			
			
			
		}

		++m_count;

	}else
	{
		cout << "There is no place for a new Node\n";
	}
	
}

template<typename T>
bool SortedList<T>::deleteItem(T item)
{
	if(m_count == 0) return 0;
	if(m_first->m_data == item)
	{
		Node<T>* tmp = m_first;
		m_first = m_first->m_next;
		delete tmp;
		--m_count;
		return 1;
	}
	Node<T>* tmp = m_first;

	if(m_asc_order)
	{
		while(tmp->m_next != nullptr && tmp->m_next->m_data < item) tmp = tmp->m_next; 
	}else
	{
		while(tmp->m_next != nullptr && tmp->m_next->m_data > item) tmp = tmp->m_next; 
	}

	if(tmp->m_next->m_data == item)
	{
		Node<T>* temp = tmp->m_next;
		tmp->m_next = temp->m_next;
		delete temp;
		--m_count;
		return 1;
	}

	return 0;

}

template<typename T>
bool SortedList<T>::search(T item)
{
	if(m_count == 0) return 0;
	Node<T>* tmp = m_first;
	do
	{
		if(tmp->m_data == item) return 1;
		tmp = tmp->m_next;
	}while(tmp != nullptr);
	
	return 0;	
}




template<typename T>
void SortedList<T>::PrintList()
{
	if(m_count == 0) return;
	Node<T>* tmp = m_first;
	do
	{
		cout << tmp->m_data << ' ';
		tmp = tmp->m_next;
	}while(tmp != nullptr);
	cout << '\n';
}




int main()
{
	SortedList<int> list;

	list.addItem(3);
	list.addItem(8);
	list.addItem(4);
	list.addItem(6);
	cout << list.search(0) << ' ' << list.search(3) << ' ' << list.search(8) << ' ' << list.search(6) << '\n';
	list.PrintList();

	list.deleteItem(4);
	list.deleteItem(5);
	list.deleteItem(3);

	list.PrintList();

	list.deleteItem(8);
	list.deleteItem(6);
	list.deleteItem(3);

	cout << list.search(0) << ' ' << list.search(3) << ' ' << list.search(8) << ' ' << list.search(6) << '\n';
	list.PrintList();
	

	return 0;
}