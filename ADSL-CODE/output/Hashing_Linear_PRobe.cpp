#include <iostream>
using namespace std;

class Hashing
{
public:
    int matrix[5];
    int key;
    int n;
    int i;
    Hashing()
    {
        for (i = 0; i < 5; i++)
        {
            matrix[i] = 0;
        }
    }
    void create();
    void insert(int key, int n);
    void display();
    void search(int key);
};

void Hashing::create()
{
    for (i = 0; i < 5; i++)
    {
        cout << "Enter the number:-";
        cin >> n;
        key = n % 5;
        if (matrix[i] == 0)
        {
            matrix[key] = n;
        }
        else
        {
            insert((key + 1) % 5, n);
        }
    }
}

void Hashing::insert(int key, int n)
{
    if (matrix[key] == 0)
    {
        matrix[key] = n;
    }
    else
    {
        insert((key + 1) % 5, n);
    }
}

void Hashing::display(){
    for(i=0;i<5;i++){
        cout<<i<<" "<<"Key"<<" "<<matrix[i]<<endl;
    }
}

void Hashing::search(int key){
    bool found = false;
    for(i=0;i<5;i++){
        if (matrix[i]==key){
            cout<<"Key"<<" "<<key<<" "<<"found at the the index"<<" "<<i<<"."<<endl;
            found=true;
            break;
        }
    }
    if(matrix[i]!=key){
        cout<<"Key"<<" "<<key<<" "<<"not found in the hash table."<<endl;
    }
}

int main(){
    bool s = true;
    int option,searchKey;
    Hashing h;
    cout << "\nWelcome to the program of hashing";
    do
    {
        cout << "\nEnter the operation you want to perform";
        cout << "\n1. Create Hash Table." << endl;
        cout << "2. Display Hash Table." << endl;
        cout << "3. Search in Hash Table." << endl;
        cout << "4. Exit " << endl;
        cout<<"-------------------------------------------"<<endl;
        cout<<"Enter the option:-";
        cin >> option;
        switch(option){
            case 1:
            {
                h.create();
                break;
            }
            case 2:
            {
                h.display();
                break;
            }
            case 3:
            {
                cout<<"Enter key to search:-";
                cin>>searchKey;
                h.search(searchKey);
                break;
            }
            case 4:
            {
                cout<<"Exit"<<endl;
                s=false;
                break;
            }
            default:
            {
                cout<<"Invalid option. Please try again."<<endl;
                break;
            }
        }
    } while (s);
    return 0;
}