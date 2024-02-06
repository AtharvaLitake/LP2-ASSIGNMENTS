#include <iostream>
#include <vector>
using namespace std;
class greedy
{
public:
    // selection sort input
    vector<int> s;
    int size;
    // prims input
    int n;
    int a[10][10];
    string vertex[10];
    // selection sort functions starts here
    void input()
    {
        cout << "Enter Number of elements--";
        cin >> size;
        for (int i = 0; i < size; i++)
        {
            int a;
            cin >> a;
            s.push_back(a);
        }
    }
    void print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << s[i] << " ";
        }
        cout<<endl;
    }
    void selection()
    {
        int ptr1 = 0;
        int cnt=0;
        while (ptr1 != size - 1)
        {
            int min = 999999;
            int index = -1;
            for (int i = ptr1; i < size; i++)
            { 

                if (min > s[i])
                {
                    min = s[i];
                    index = i;
                }
            }
            // greedy about the minimum value
            int temp = s[ptr1];
            s[ptr1] = s[index];
            s[index] = temp;
            ptr1++;
            cout<<endl;
            cout<<"PASS---"<<cnt<<endl;
            cnt++;
            cout<<endl;
            print();
        }
    }
    // prims function starts here
    void pinput()
    {
        cout << "Enter Number of vertices" << endl;
        cin >> n;
        cout << "Enter Names of vertices" << endl;
        for (int i = 0; i < n; i++)
        {
            cout << "Enter Vertex " << i << " ---";
            cin >> vertex[i];
        }
        cout << "ENTER WEIGHTED EDGES";
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                if (i == j)
                {
                    a[i][j] = 0;
                    continue;
                }
                else
                {
                    cout << "\nEnter the cost of edge " << vertex[i] << " and " << vertex[j] << " : ";
                    cin >> a[i][j];
                    a[j][i] = a[i][j];
                }
            }
        }
    }
    void poutput()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }
    void pprims()
    {
        int visit[n], mincost = 0, count = 1, minindex = 0, cost = 0;
        int minorigin=0;
        for (int i = 0; i < n; i++)
        {
            visit[i] = 0;
        }
        visit[0] = 1;
        while (1)
        {
            mincost = 1000;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (visit[i] == 1 && a[i][j] != 0 && a[i][j] < mincost && visit[j] == 0)
                    {
                        mincost = a[i][j];
                        minindex = j;
                        minorigin=i;
                    }
                }
            }
            cout<<"EDGE ---"<<vertex[minorigin]<<" "<<vertex[minindex]<<endl;
            visit[minindex] = 1;
            cost = cost + mincost;
            count++;
            if (count == n)
            {
                break;
            }
        }
        cout << "COST OF MINIMUM SPANNING TREE----" << cost << endl;
    }
};
int main()
{
    while (true)
    {
        greedy g;
        cout<<endl;
        cout << "CHOOSE AMONGST FOLOWING 2----\n1.Selection Sort\n2.Prims Algorithm\n3.EXIT" << endl;
        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
            g.input();
            cout << "UNSORTED ARRAY---" << endl;
            g.print();
            cout << endl;
            g.selection();
            cout << "SORTED ARRAY----" << endl;
            cout<<endl;
            g.print();
            cout << endl;
            break;
        case 2:
            g.pinput();
            g.poutput();
            g.pprims();
            break;
        default:
            cout << "CHOOSE CORRECT OPTION" << endl;
            break;
        }
        if (choice == 3)
        {
            cout << "EXITING....." << endl;
            break;
        }
    }
}