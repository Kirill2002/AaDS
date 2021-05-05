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


	static int check_height(BBST<T>* p);
	static int balance_factor(BBST<T>* p);
	static void fix_height(BBST<T>* p);
	static BBST<T>* right_rotation(BBST<T>* p);
	static BBST<T>* left_rotation(BBST<T>* p);
	static BBST<T>* balance(BBST<T>* p);
};

template<typename T>
int BBST<T>::check_height(BBST<T>* p)
{
	return p ? p->height : 0;
}

template<typename T>
int BBST<T>::balance_factor(BBST<T>* p)
{
	return check_height(p->right) - check_height(p->left);
}

template<typename T>
void BBST<T>::fix_height(BBST<T>* p)
{
	int hl = check_height(p->left);
	int hr = check_height(p->right);
	p->height = max(hl, hr) + 1;
}

template<typename T>
BBST<T>* BBST<T>::right_rotation(BBST<T>* p)
{
	BBST<T>* q = p->left;
	p->left = q->right;
	q->right = p;
	fix_height(p);
	fix_height(q);
	return q;
}

template<typename T>
BBST<T>* BBST<T>::left_rotation(BBST<T>* p)
{
	BBST<T>* q = p->right;
	p->right = q->left;
	q->left = p;
	fix_height(p);
	fix_height(q);
	return q;
}

template<typename T>
BBST<T>* BBST<T>::balance(BBST<T>* p)
{
	fix_height(p);
	if(balance_factor(p) == 2)
	{
		if(balance_factor(p->right) < 0)
			p->right = right_rotation(p->right);
		return left_rotation(p);
	}
	if(balance_factor(p) == -2)
	{
		if(balance_factor(p->left) > 0)
			p->left = left_rotation(p->left);
		return right_rotation(p);
	}
	return p;
}


int main()
{
	
}