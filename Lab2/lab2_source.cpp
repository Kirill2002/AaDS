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
	BBST(T k);
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


	friend int height(BBST<T>* p);
	friend int balance_factor(BBST<T>* p);
	friend void fix_height(BBST<T>* p);

};

template<typename T>
int height(BBST<T>* p)
{
	return p ? p->height : 0;
}

template<typename T>
int balance_factor(BBST<T>* p)
{
	return height(p->right) - height(p->left);
}

template<typename T>
void fix_height(BBST<T>* p)
{
	int hl = height(p->left);
	int hr = height(p->right);
	p->height = max(hl, hr) + 1;
}

int main()
{
	
}