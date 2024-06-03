#include <iostream>
using namespace std;

class Graph
{
public:
    int n, e, v1, v2;
    int adjMatrix[20][20];
    bool visited[20];

    Graph()
    {
        for (int i = 0; i < 20; i++)
        {
            for (int j = 0; j < 20; j++)
            {
                adjMatrix[i][j] = 0;
            }
            visited[i] = false;
        }
    }

    void create();
    void display();
    void DFS(int vertex);
    void BFS(int vertex);
};

void Graph::create()
{
    cout << "Enter Number of Vertices :- ";
    cin >> n;
    cout << "Enter Number of Edges :- ";
    cin >> e;
    for (int i = 0; i < e; i++)
    {
        cout << "Enter an edge (vertex1 vertex2) :- ";
        cin >> v1 >> v2;
        adjMatrix[v1][v2] = 1;
        adjMatrix[v2][v1] = 1;
    }
}

void Graph::display()
{
    cout << "Adjacency Matrix:" << endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
}

void Graph::DFS(int vertex)
{
    visited[vertex] = true;
    cout << vertex << " ";

    for (int i = 1; i <= n; i++)
    {
        if (adjMatrix[vertex][i] && !visited[i])
        {
            DFS(i);
        }
    }
}

void Graph::BFS(int vertex)
{
    bool *visited = new bool[n + 1];
    for (int i = 1; i <= n; i++)
        visited[i] = false;

    int queue[20], front = 0, rear = 0;
    queue[rear++] = vertex;
    visited[vertex] = true;

    while (front < rear)
    {
        int v = queue[front++];
        cout << v << " ";

        for (int i = 1; i <= n; i++)
        {
            if (adjMatrix[v][i] && !visited[i])
            {
                queue[rear++] = i;
                visited[i] = true;
            }
        }
    }
    delete[] visited;
}

int main()
{
    Graph g;
    bool s = true;
    while (s)
    {
        cout << "\nWelcome To Graph" << endl;
        cout << "1 - Create/Read Graph" << endl;
        cout << "2 - Display Graph / Read" << endl;
        cout << "3 - DFS Traversal" << endl;
        cout << "4 - BFS Traversal" << endl;
        cout << "5 - Exit" << endl;
        int choice;
        cout << "Enter Your Choice :- ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            g.create();
            cout << endl;
            break;
        case 2:
            g.display();
            cout << endl;
            break;
        case 3:
            cout << "DFS Traversal: ";
            for (int i = 1; i <= g.n; i++)
            {
                if (!g.visited[i])
                    g.DFS(i);
            }
            cout << endl;
            break;
        case 4:
            cout << "BFS Traversal: ";
            for (int i = 1; i <= g.n; i++)
            {
                if (!g.visited[i])
                    g.BFS(i);
            }
            cout << endl;
            break;
        case 5:
            cout << "Exiting program. Goodbye!" << endl;
            s = false;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;
}
