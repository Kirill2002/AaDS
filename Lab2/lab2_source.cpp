#include <iostream>
#include <queue>
using namespace std;

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
    else
        p->right = node_insert(p->right, k);

    return balance(p);
}

template<typename T>
node<T>* findmin(node<T>* p) 
{
    return p->left ? findmin(p->left) : p;
}

template<typename T>
class BBST
{
private:
    node<T>* root;
public:
    BBST(T k)
    {
        root = new node<T>(k);
    }
    // ~BBST();

    void Print();
    void PrintPreOrder();
    void PrintSorted();
    int CountNode();
    int SumKeys();
    void DeleteEven();
    BBST<T>* FindMiddle();
    T FindSecondLargest();
    BBST<T>* CopyBBST();
    BBST<T>* InsertBBST(const BBST<T>& a);
    bool ContainsBBST(const BBST<T>& a);
    bool IsBalanced();
    bool EqualsBBST(const BBST<T>& a);
    BBST* SymetricalBBST();
    T FatherNode(T k);
    int CommonAncestor(T a, T b);



    void insert(T k) {
        root = node_insert(root, k);
    }

};




template<typename T>
void BBST<T>::Print()
{
    queue<pair<node<T>*, int>> q;
    q.push({ root, 0 });
    int cur_h = 0;
    while (!q.empty())
    {
        pair<node<T>*, int> tmp = q.front();
        q.pop();
        if (tmp.first != nullptr)
        {
            q.push({ tmp.first->left, tmp.second + 1 });
            q.push({ tmp.first->right, tmp.second + 1 });
            if (tmp.second > cur_h)
            {
                ++cur_h;
                cout << '\n';
            }
            cout << tmp.first->key << ' ';
        }

    }

}



int main()
{
    BBST<int> a(5);
    a.insert(1);
    a.insert(2);
    a.insert(3);
    a.insert(4);
    a.insert(6);
    a.Print();
}


