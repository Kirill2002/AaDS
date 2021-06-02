#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int n)
{
	for(int i = 2; i <= sqrt(n); ++i)
		if(n % i == 0)
			return 0;
	return 1;

}

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

		array[++last] = item;
	}


	void printList()
	{
		for(int i = 0; i <= last; ++i)
		{
			cout << array[i] << ' ';
		}
	}

	~List()
	{
		delete[] array;
	}
	
};


int main()
{
	List a(2);
	a.addItem(3);
	a.addItem(2);
	a.addItem(1);
	a.printList();


}