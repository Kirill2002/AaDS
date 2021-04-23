#include <iostream>
using namespace std;

template<typename T>
class BBST
{
private:
	T key;
	int height;
	BBST* left;
	BBST* right;
public:
	BBST();
	~BBST();
	
	void PrintSorted();
	int CountNode();
	int SumKeys();
	void DeleteEven();
	BBST* FindMiddle();
	T FindSecondLargest();
	BBST* CopyBBST();
	BBST* InsertBBST(const BBST& a);
	bool ContainsBBST(const BBST& a);
	bool IsBalanced();
	bool EqualsBBST(const BBST& a);
	BBST* SymetricalBBST();
	T FatherNode(T k);
	int CommonAncestor(T a, T b);
};

int main()
{
	
}