#include <iostream>
using namespace std;

class Hashing {
public:
    int matrix[20][20];
    int key,n,s;
    int number;
    
   Hashing()
    {
    for(int i=0;i<20;i++){
       matrix[0][i]=i;
       }
       for(int i=0;i<20;i++){
        matrix[1][i]=0;
       }
    }
    void create();
    void insert(int key, int n);
    void display();
    void search(int key);
};

void Hashing::create() {
    cout<<"Enter size of hash:- ";
    cin>>s;
    for (int i = 0; i < s; i++) {
        cout << "Enter number: ";
        cin >> n;
        key = n % s;

        if (matrix[1][key] == 0) {
            matrix[1][key] = n;
        } else if ((matrix[1][key] % s) == (n % s)) {
            insert((key + 1) % s, n);
        } else if ((n % s) != matrix[1][key] % s) {
            number = matrix[1][key];
            matrix[1][key] = n;
            insert((number) % s, number);
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
   for(int j=0;j<s;j++){
    cout<<matrix[0][j]<<" "<<matrix[1][j]<<endl;
        }
}

void Hashing::search(int key) {
    bool found = false;
    for (int i = 0; i < 5; i++) {
        if (matrix[1][i] == key) {
            cout << "Key " << key << " found at index " << i << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Key " << key << " not found in the hash table." << endl;
    }
}

int main() {
    bool s = true;
    Hashing h;
    int option, searchKey;

    while (s) {
        cout << "----------HASH TABLE LINEAR PROBING----------" << endl;
        cout << "1: Create" << endl;
        cout << "2: Display" << endl;
        cout << "3: Search" << endl;
        cout << "4: Exit" << endl;
        cout << "---------------------------------------------" << endl;
        cout << "Option :- ";
        cin >> option;

        switch (option) {
            case 1:
                h.create();
                break;
            case 2:
                h.display();
                break;
            case 3:
                cout << "Enter key to search: ";
                cin >> searchKey;
                h.search(searchKey);
                break;
            case 4:
                cout << "Exit" << endl;
                s = false;
                break;
            default:
                cout << "Invalid option. Please try again." << endl;
        }
    }
    return 0;
}
