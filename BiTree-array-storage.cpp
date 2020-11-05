#include <iostream>
using namespace std;

class BiTree
{
    char *tree;
    string str;
    string::iterator it = str.begin();
    int len;

public:
    BiTree()
    {
        tree = NULL;
        len = 0;
    }
    ~BiTree()
    {
        len = 0;
        delete tree;
    }
    void Create()
    {
        cin >> str;
        len = str.length();
        tree = new char[len];
        Create(0);
    }
    void Create(int i)
    {     
        if (i<len)
        {
            tree[i] = (*it);
            it++;
            Create(2 * i + 1);
            Create(2 * i + 2);
        }
    }
    void PreOrder()
    {
        PreOrder(0);
    }
    void PreOrder(int n)
    {
        if (*(tree + n) != '0' && n < len)
        {
            cout << (*(tree + n)) << ' ';
            PreOrder(2 * n + 1);
            PreOrder(2 * n + 2);
        }
    }
    void TreeHigh()
    {
        int high = 1;
        int last=0;
        for (int i = len - 1; i >= 0; i--)
            if(tree[i]!='0')
            {
                last = i;
                break;
            }
        while (last / 2 != 0)
        {
            high++;
            last = last / 2;
        }
        cout << high << endl;
    }
};

int main()
{
    int time;
    cin >> time;
    while (time--)
    {
        BiTree myTree;
        myTree.Create();
        myTree.TreeHigh();
    }
    return 0;
}