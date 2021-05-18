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
}
