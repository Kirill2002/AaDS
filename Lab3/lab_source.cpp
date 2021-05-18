#include <iostream>
using namespace std;

template<typename T>
class ArrayList
{
private:
	T* array;
	int last;
	int max_length;
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
	
};

int main()
{

}
