#include <iostream>
using namespace std;

class Graph
{
public:
    int t_edges, t_nodes;
    int parent[10];
    typedef struct Edges
    {
        int v1, v2, cost;
    } ED;
    ED e[10];

    void create();
    void display();
    void kruskal();
    int min_edge();
    int find(int);
};

void Graph::create()
{
    cout << "\n Enter no. of nodes: ";
    cin >> t_nodes;
    cout << "\n Enter no. of edges: ";
    cin >> t_edges;

    for (int i = 0; i < t_edges; i++)
    {
        cout << "\n Enter edge v1 and v2 and the cost of the edge: ";
        cin >> e[i].v1 >> e[i].v2 >> e[i].cost;
    }
}

void Graph::display()
{
    cout << "\n The graph contains the following edges: " << endl;
    for (int i = 0; i < t_edges; i++)
    {
        cout << e[i].v1 << "\t " << e[i].v2 << "\t " << e[i].cost << "\t " << endl;
    }
}

void Graph::kruskal()
{
    int u, v;
    int i, j, k;
    int mst_cost = 0;

    for (int i = 0; i < t_nodes; i++)
        parent[i] = i;

    int pos;
    for (int count = 0; count < t_nodes - 1; count++)
    {
        pos = min_edge();

        u = e[pos].v1;
        v = e[pos].v2;

        j = find(u);
        k = find(v);

        if (j != k)
        {
            cout << "\n Edge included in MST: " << u << " - " << v << " with cost " << e[pos].cost;
            mst_cost += e[pos].cost;
            parent[k] = j;
            e[pos].cost = 9999;
        }
        else
        {
            cout << "\n Edge " << u << " - " << v << " forms a cycle.";
        }
    }
    cout << "\n\n Total cost of MST: " << mst_cost;
}

int Graph::find(int p)
{
    if (parent[p] == p)
        return p;
    else
        return find(parent[p]);
}

int Graph::min_edge()
{
    int min = 999;
    int index = -1;
    for (int i = 0; i < t_edges; i++)
    {
        if (min > e[i].cost)
        {
            min = e[i].cost;
            index = i;
        }
    }
    return index;
}

int main()
{
    int choice;
    Graph g;
    cout << "Welcome to Kruskal's Method" << endl;
    do
    {
        cout << "\n 1. Read a graph.";
        cout << "\n 2. Display the graph.";
        cout << "\n 3. Kruskal's method to find MST.";
        cout << "\n 4. Exit";
        cout << "\n Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            g.create();
            break;
        case 2:
            g.display();
            break;
        case 3:
            g.kruskal();
            break;
        case 4:
            cout << "\n Exiting..." << endl;
            break;
        }
    } while (choice != 4);
    return 0;
}
