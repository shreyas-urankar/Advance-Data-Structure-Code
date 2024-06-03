#include <iostream>
using namespace std;

class Graph
{
public:
    int n, e, v1, v2;
    int adjMatrix[20][20];
    void create();
    void display();
    Graph()
    {
        for (int i = 0; i < 20; i++)
        {
            for (int j = 0; j < 20; j++)
            {
                adjMatrix[i][j] = 0;
            }
        }
    }
};

void Graph ::create()
{
    cout << "Enter Number of Vertices :- ";
    cin >> n;
    cout << "Enter Number of Edges :- ";
    cin >> e;
    for (int i = 0; i < e; i++)
    {
        cout << "Enter an edge :- ";
        cin >> v1 >> v2;
        adjMatrix[v1][v2] = 1;
        adjMatrix[v2][v1] = 1;
    }
}

void Graph ::display()
{
    for (int i = 1; i <= n; i++)
    {
        cout << endl;
        for (int j = 1; j <= n; j++)
        {
            cout << adjMatrix[i][j];
        }
    }
}

int main()
{
    Graph g;
    bool s = true;
    while (s)
    {
        cout << "Welcome To Graph" << endl;
        cout << "1 - Create/Read Graph" << endl;
        cout << "2 - Display Graph / Read" << endl;
        cout << "Exit" << endl;
        int choice;
        cout << "Enter Your Choice :- ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            g.create();
            cout << endl;
            break;
        }
        case 2:
        {
            g.display();
            cout << endl;
            break;
        }
        case 3:
        {
            cout << "Exit" << endl;
            s = false;
            break;
        }
            
        }
        
    }
}
