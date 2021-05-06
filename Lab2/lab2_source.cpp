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
node<T>* find_min(node<T>* p) 
{
    return p->left ? find_min(p->left) : p;
}

template<typename T>
node<T>* remove_min(node<T>* p)
{
    if (p->left == 0)
        return p->right;
    p->left = remove_min(p->left);
    return balance(p);
}

template<typename T>
node<T>* node_remove(node<T>* p, T k) 
{
    if (!p) return 0;
    if (k < p->key)
        p->left = node_remove(p->left, k);
    else if (k > p->key)
        p->right = node_remove(p->right, k);
    else 
    {
        node<T>* q = p->left;
        node<T>* r = p->right;
        delete p;
        if (!r) return q;
        node<T>* min = find_min(r);
        min->right = remove_min(r);
        min->left = q;
        return balance(min);
    }
    return balance(p);
}


template<typename T>
void print_in_order(node<T>* p)
{
    if (!p) return;
    print_in_order(p->left);
    cout << p->key << ' ';
    print_in_order(p->right);
}

template<typename T>
void print_in_order_reverse(node<T>* p)
{
    if (!p) return;
    
    print_in_order_reverse(p->right);
    cout << p->key << ' ';
    print_in_order_reverse(p->left);
    
}

template<typename T>
void count_node(node<T>* p, int& count)
{
    if (!p) return;
    if (p->left) ++count;
    count_node(p->left, count);
    count_node(p->right, count);
}

template<typename T>
void sum_keys(node<T>* p, long long &sum)
{
    if (!p) return;
    if (p->right) sum += p->right->key;
    sum_keys(p->left, sum);
    sum_keys(p->right, sum);
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



    void Insert(T k) {
        root = node_insert(root, k);
    }

    void Remove(T k)
    {
    	root = node_remove(root, k);
    }

    void PrintSorted()
    {
        print_in_order(root);
        cout << '\n';
        print_in_order_reverse(root);
    }

    int CountNode()
    {
        int res = 0;
        count_node(root, res);
        return res;
    }

    long long SumKeys()
    {
        long long res = 0;
        sum_keys(root, res);
        return res;
    }
};

template<typename T>
void delete_even(node<T>* p, BBST<T>& b)
{
    if (!p) return;
    if (p) b.Insert(p->key);	
    sum_keys(p->left, b);
    sum_keys(p->right, b);
}



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
    a.Insert(1);
    a.Insert(2);
    a.Insert(3);
    a.Insert(4);
    a.Insert(6);
    a.Print();
    cout << '\n';
    a.PrintSorted();
    cout << '\n';
    cout << a.CountNode();
    cout << '\n';
    cout << a.SumKeys();
}


