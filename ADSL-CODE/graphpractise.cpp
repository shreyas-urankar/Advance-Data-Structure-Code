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

void Graph::create()
{
    cout << "\n Enter the number of Vertices:-";
    cin >> n;
    cout << "\n Enter the number of Edges:-";
    cin >> e;
    for (int i = 0; i < e; i++)
    {
        cout << "\n Enter an edge(Start and End Vertices):-";
        cin >> v1 >> v2;
        adjMatrix[v1][v2] = 1;
        adjMatrix[v2][v1] = 1;
    }
}

void Graph::display()
{
    for (int i = 1; i <= n; i++)
    {
        cout << "\n";

        for (int j = 1; j <= e; j++)
        {
            cout << " " << adjMatrix[i][j];
        }
    }
}

int main()
{
    int ch;
    Graph shreyas;
    do
    {
        cout << "\nWelcome to the Graph Representation.";
        cout << "\n1) Create Graph.";
        cout << "\n2)Display Graph.";
        cout << "\n3)Exit.";
        cout << "\nEnter the option you want to perform:-";
        cin >> ch;
        switch (ch)
        {
        case 1:
            shreyas.create();
            cout << endl;
            break;
        case 2:
            shreyas.display();
            cout << endl;
            break;
        case 3:
            cout << "Thankyou visit Graph Representation again. ";
            break;
        default:
            cout << "Invalid option. Please insert a valid option from 1 to 3." << endl;
            break;
        }
    } while (ch != 3);
    return 0;
}
