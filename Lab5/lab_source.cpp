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


	~List()
	{
		delete[] array;
	}
	
};


int main()
{

}