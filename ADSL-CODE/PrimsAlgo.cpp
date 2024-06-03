#include <iostream>
using namespace std;

class Prims
{
public:
    int costMatrix[20][20];
    int vertices;
    int edges;
    int v1, v2;
    int Visit[20];
    int row;
    int col;
    int weight;
    int min;
    int i, j;
    int finalCost = 0;
    void create();
    void display();
    void MST();

    Prims()
    {
        for (row = 1; row <= 20; row++)
        {
            for (col = 1; col <= 20; col++)
            {
                costMatrix[row][col] = 0;
            }
        }
        for (int i = 0; i <= 20; i++)
        {
            Visit[i] = 0;
        }
    }
};

void Prims::create()
{
    cout << "\nEnter number of vertices:-";
    cin >> vertices;
    cout << "\nEnter the number of edges:-";
    cin >> edges;
    for (i = 1; i <= edges; i++)
    {
        cout << "Enter an edge(Vertex V1 and V2):-";
        cin >> v1;
        cin>> v2;
        cout << "\nEnter its weight:-";
        cin >> weight;
        costMatrix[v1][v2] = weight;
        costMatrix[v2][v1]= weight;
    }
    cout<<endl;
}

void Prims::display()
{
    cout << "\nThe Matrix Representation is:-" << endl;
    for (row = 1; row <= vertices; row++)
    {
        for (col = 1; col <= vertices; col++)
        {
            cout << costMatrix[row][col] << " ";
        }
        cout << endl;
    }
}

void Prims::MST()
{
    cout << "\nEnter starting vertex:-";
    cin >> v1;
    Visit[v1] = 1;
    for (int k = 1; k <= vertices - 1; k++)
    {
        min = 999;
        for (int i = 1; i <= vertices; i++)
        {
            for (int j = 1; j <= vertices; j++)
            {
                if (Visit[i] == 1 && Visit[j] == 0)
                {
                    if (costMatrix[i][j] != 0 && min >= costMatrix[i][j])
                    {
                        min = costMatrix[i][j];
                        row = i;
                        col = j;
                    }
                }
            }
        }

        finalCost = finalCost + min;

        Visit[col] = 1;
        costMatrix[row][col] = 0;
        costMatrix[row][col] = 0;
    }
    cout << "\nThe cost of MST is:-" << finalCost;
}

int main()
{
    int ch;
    Prims p;
    do
    {
        cout << "\nWelcome to the program of prims.";
        cout << "\n1) Create Graph.";
        cout << "\n2) Display Graph.";
        cout << "\n3) Prims.";
        cout << "\nEnter the operation you want to perform:-";
        cin >> ch;
        switch (ch)
        {
        case 1:
            p.create();
            break;
        case 2:
            p.display();
            break;
        case 3:
            p.MST();
            break;
        default:
            cout << "\nEnter valid input.";
            break;
        }
    } while (ch != 3);
    return 0;
}