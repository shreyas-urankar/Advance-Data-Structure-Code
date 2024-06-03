#include <iostream>
using namespace std;

class Prims {
public:
    int costMatrix[20][20];
    int v1, v2;
    int Visit[20];
    int row, col;
    int weight;
    int vertices, edges;
    int finalCost = 0;
    int i, j, k;
    void create();
    void display();
    void MST();
    Prims() {
        for (row = 1; row <= 10; row++) {
            for (col = 1; col <= 10; col++) {
                costMatrix[row][col] = -1;
            }
        }
        for (i = 0; i <= 20; i++) {
            Visit[i] = 0;
        }
    }
};

void Prims::create() {
    cout << "Enter the number of vertices:-";
    cin >> vertices;
    cout << "Enter the number of edges:-";
    cin >> edges;
    for (i = 1; i <= edges; i++) {
        cout << "Enter an edge(Vertices v1 and v2):-";
        cin >> v1 >> v2;
        cout << "\nEnter its weight:-";
        cin >> weight;
        costMatrix[v1][v2] = weight;
        costMatrix[v2][v1] = weight;
    }
}

void Prims::display() {
    cout << "The matrix representation is:-";
    for (row = 1; row <= vertices; row++) {
        for (col = 1; col <= vertices; col++) {
            cout << costMatrix[row][col] << " ";
        }
        cout << endl;
    }
}

void Prims::MST() {
    cout << "Enter the starting vertex:-";
    cin >> v1;
    Visit[v1] = 1;
    int min;
    for (k = 1; k <= vertices - 1; k++) {
        min = 999;
        for (i = 1; i <= vertices; i++) {
            for (j = 1; j <= vertices; j++) {
                if (Visit[i] == 1 && Visit[j] == 0) {
                    if (costMatrix[i][j] != -1 && min >= costMatrix[i][j]) {
                        min = costMatrix[i][j];
                        row = i;
                        col = j;
                    }
                    finalCost = finalCost + min;
                    Visit[col] = 1;
                    costMatrix[row][col] = -1;
                    costMatrix[col][row] = -1;
                }
            }
        }
        cout << "\nThe cost of matrix is:-" << finalCost<<endl;
    }
}

int main() {
    int menu;
    Prims pr;
    cout << "Welcome to Prims Algorithm."<<endl;
    do {
       
        cout << "1 Read Graph." << endl;
        cout << "2 Display Graph." << endl;
        cout << "3 Prims." << endl;
        cout << "4 Exit." << endl;
         cout << "\nEnter the operation you want to perform:-";
        cin >> menu;
        switch (menu) {
        case 1: {
            pr.create();
            break;
        }
        case 2: {
            pr.display();
            break;
        }
        case 3: {
            pr.MST();
            break;
        }
        default: {
            cout << "\nYou have entered an invalid option. Please enter a valid option. ";
            break;
        }
        }
    } while (menu != 4);
    return 0;
}
