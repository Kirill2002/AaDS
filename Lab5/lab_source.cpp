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

	int Separate()
	{
		int first_non_prime = 0;
		for(int i = 0; i < last; ++i)
		{
			if(isPrime(array[i]))
				swap(array[i], array[first_non_prime++]);
		}

		return first_non_prime;
	}


	~List()
	{
		delete[] array;
	}
	
};


int main()
{
	List a(2);

	for(int i = 1; i < 100; i += 5)
		a.addItem(i);

	cout << "Initial list:\n";
	a.printList();
	cout << "\nNow lets separate prime numbers from the others\n";
	cout << a.Separate() << " first numbers are prime\n";
	a.printList();
	


}