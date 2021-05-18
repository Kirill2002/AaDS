#include <iostream>
using namespace std;

template<typename T>
class ArrayList
{
private:
	T* array;
	int last;
	int max_length;

	void settleRoot(int root, int last)
	{
		int child, unsettled = root;
		while(2 * unsettled + 1 <= last)
		{
			if(2 * unsettled + 1 < last &&
			 array[2 * unsettled + 2] > array[2 * unsettled + 1])
				child = 2 * unsettled + 2;
			else 
				child = 2 * unsettled + 1;

			if(array[unsettled] < array[child])
			{
				swap(array[unsettled], array[child]);
				unsettled = child;
			}else break;
		}
	}
public:
	ArrayList(int max = 100)
	{
		max_length = max;
		array = new T[max];
		last = -1; 
	}

	~ArrayList()
	{
		delete[] array;
	}

	bool isEmpty()
	{
		return last == -1;
	}

	bool isFull()
	{
		return last == max_length - 1;
	}

	void printList()
	{
		for(int i = 0; i <= last; ++i)
			cout << array[i] << ' ';
	}

	int size()
	{
		return last + 1;
	}

	void addItem(T key)
	{
		if(isFull())
		{
			cout << "List overflow\n";
			return;
		}

		array[++last] = key;

	}

	void heapSort()
	{
		int n = last + 1;
		for(int i = n / 2; i>= 0; --i)
		{
			settleRoot(i, last);
		}

		for(int r = last - 1; r >= 0; --r)
		{
			swap(array[0], array[r + 1]);
			settleRoot(0, r);
		}
	}
	
};

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
	T popFirst();
	bool search(T item);
	int size();
	void PrintList();
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



template<typename T>
T List<T>::popFirst()
{

	T tmp = m_first->m_data;
	Node<T>* next = m_first->m_next;
	delete m_first;
	m_first = next;
	--m_count;

	return tmp;
}

template<typename T>
void List<T>::addItem(T item)
{
	m_first = new Node<T>(item, m_first);

}



template<typename T>
bool List<T>::isEmpty()
{
	return m_count == 0;
}

template<typename T>
bool List<T>::isFull()
{
	
	Node<T>* tmp;
	tmp = new Node<T>;
	if(tmp == nullptr) return 1;

	delete tmp;
	return 0;
}





template<typename T>
bool List<T>::search(T item)
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
int List<T>::size()
{
	return m_count;	
}

template<typename T>
void List<T>::makeEmpty()
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
void List<T>::PrintList()
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



template<typename T>
struct node
{
    T key;
    int height;
    node<T>* left;
    node<T>* right;
    node(T k)
    {
        key = k;
        left = right = nullptr;
        height = 1;
    }
};

template<typename T>
int check_height(node<T>* p)
{
    return p ? p->height : 0;
}

template<typename T>
int balance_factor(node<T>* p)
{
    return check_height(p->right) - check_height(p->left);
}

template<typename T>
void fix_height(node<T>* p)
{
    int hl = check_height(p->left);
    int hr = check_height(p->right);
    p->height = max(hl, hr) + 1;
}

template<typename T>
node<T>* right_rotation(node<T>* p)
{
    node<T>* q = p->left;
    p->left = q->right;
    q->right = p;
    fix_height(p);
    fix_height(q);
    return q;
}

template<typename T>
node<T>* left_rotation(node<T>* p)
{
    node<T>* q = p->right;
    p->right = q->left;
    q->left = p;
    fix_height(p);
    fix_height(q);
    return q;
}

template<typename T>
node<T>* balance(node<T>* p)
{
    fix_height(p);
    if (balance_factor(p) == 2)
    {
        if (balance_factor(p->right) < 0)
            p->right = right_rotation(p->right);
        return left_rotation(p);
    }
    if (balance_factor(p) == -2)
    {
        if (balance_factor(p->left) > 0)
            p->left = left_rotation(p->left);
        return right_rotation(p);
    }
    return p;
}


template<typename T>
node<T>* node_insert(node<T>* p, T k)
{
    if (!p) return new node<T>(k);
    if (k < p->key)
        p->left = node_insert(p->left, k);
    else if(k > p->key)
        p->right = node_insert(p->right, k);
    else
    	return p;

    return balance(p);
}

template<typename T>
node<T>* find_min(node<T>* p) 
{
    return p->left ? find_min(p->left) : p;
}

template<typename T>
node<T>* remove_min(node<T>* p)
{
    if (p->left == 0)
        return p->right;
    p->left = remove_min(p->left);
    return balance(p);
}

template<typename T>
node<T>* node_remove(node<T>* p, T k) 
{
    if (!p) return 0;
    if (k < p->key)
        p->left = node_remove(p->left, k);
    else if (k > p->key)
        p->right = node_remove(p->right, k);
    else 
    {
        node<T>* q = p->left;
        node<T>* r = p->right;
        delete p;
        if (!r) return q;
        node<T>* min = find_min(r);
        min->right = remove_min(r);
        min->left = q;
        return balance(min);
    }
    return balance(p);
}

template<typename T>
void make_empty(node<T>* p)
{
	if(!p) return;
	make_empty(p->left);
	make_empty(p->right);
	delete p;
}

template<typename T>
bool search(node<T>* p, T k)
{
	if(!p) return false;
	if(k > p->key)
		return search(p->right, k);
	else if(k < p->key)
		return search(p->left, k);
	return true;
}

template<typename T>
class BBST
{
private:
    node<T>* root;
public:
	BBST()
	{
		root = nullptr;
	}
    BBST(T k)
    {
        root = new node<T>(k);
    }
    ~BBST()
    {
    	make_empty(root);
    }



    bool IsEmpty() const
    {
    	if(root == nullptr) return 1;
    	return 0;
    }


    void Insert(T k) {
        root = node_insert(root, k);
    }

    void Remove(T k)
    {
    	root = node_remove(root, k);
    }



    bool IsBalanced()
    {
    	return true;
    }

    bool Search(T key)
    {
    	return search(root, key);
    }

    
};


int main()
{
	ArrayList<int> a(200);
	a.addItem(10);
	a.addItem(4);
	a.addItem(8);
	a.addItem(9);
	a.addItem(15);
	a.addItem(35);
	a.addItem(5);
	a.addItem(7);
	a.printList();
	cout << '\n';
	a.heapSort();
	a.printList();
}
