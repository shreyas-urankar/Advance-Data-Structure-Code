#include <iostream>
using namespace std;

class Hashing {
public:
    int i, j, key, n, s;
    int matrix[20][20];
    void create();
    void insert(int key, int n);
    void display();
    void search(int key);

    Hashing() {
        for (i = 0; i < 20; i++) {
            matrix[0][i] = i;
            matrix[1][i] = 0;
        }
    }
};

void Hashing::create() {
    cout << "\nEnter the size of Hash table:-";
    cin >> s;
    for (i = 0; i < s; i++) {
        cout << "\nEnter the number:- ";
        cin >> n;
        key = n % s;
        if (matrix[1][key] == 0) {
            matrix[1][key] = n;
        } else {
            insert((key + 1) % s, n);
        }
    }
}

void Hashing::insert(int key, int n) {
    if (matrix[1][key] == 0) {
        matrix[1][key] = n;
    } else {
        insert((key + 1) % s, n);
    }
}

void Hashing::display() {
    for (j = 0; j < s; j++) {
        cout << matrix[0][j] << " " << matrix[1][j] << endl;
    }
}

void Hashing::search(int key) {
    bool found = false;
    for (i = 0; i < s; i++) {
        if (matrix[1][i] == key) {
            cout << "Key " << key << " found at index " << i << "." << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Key " << key << " not found in the hash table." << endl;
    }
}

int main() {
    int option, searchKey;
    Hashing h;
    do {
        cout << "\nWelcome to the program of Hashing using Linear Probing.";
        cout << "\n1) Create Hash table.";
        cout << "\n2) Display Hash table";
        cout << "\n3) Search.";
        cout << "\n4) Exit from Hashing using Linear Probing program.";
        cout << "\n...........................................................";
        cout << "\nEnter any one operation you want to perform:-";
        cin >> option;
        switch (option) {
            case 1:
                h.create();
                break;
            case 2:
                h.display();
                break;
            case 3:
                cout << "\nEnter the key to search:-";
                cin >> searchKey;
                h.search(searchKey);
                break;
            case 4:
                cout << "Exit" << endl;
                break;
            default:
                cout << "Invalid option. Please try again." << endl;
        }
    } while (option != 4);
    return 0;
}
