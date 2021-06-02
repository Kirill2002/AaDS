#include <iostream>
using namespace std;

//ArrayList
class List
{
private:
	int* array;
	int max;
	int last;
public:
	List(int m = 10)
	{
		max = m;
		last = -1;
		array = new int[max];
	}


	bool isFull()
	{
		return last + 1 == max;
	}

	void addItem(int item)
	{
		if(isFull())
		{
			int* newArray = new int[max * 2];
			memcpy(newArray, array, max * sizeof(int));
			max *= 2;

			delete[] array;

			array = newArray;
		}

		array[last++] = item;
	}

	~List()
	{
		delete[] array;
	}
	
};


int main()
{

}