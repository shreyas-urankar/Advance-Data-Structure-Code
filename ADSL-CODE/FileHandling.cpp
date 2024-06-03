#include <iostream>
#include <fstream>
using namespace std;

class File {
public:
    string read;
    fstream l;
    fstream temp;
    void add();
    void display();
    void search();
    void modify();
    void deleteRec();
} j;

void File::add() {
    char name[20], age[10], job[10];
    l.open("C:\\Users\\urankar\\OneDrive\\Desktop\\shreyas.txt", ios::app);
    cout << "Enter your name :- ";
    cin >> name;
    cout << "Enter your age :- ";
    cin >> age;
    cout << "Enter your job profile :- ";
    cin >> job;
    l << name << "  " << age << "  " << job << endl;
    l.close();
}

void File::display() {
    int i = 0;
    cout << "  Name" << "   " << "Age" << "  " << "Job" << endl;
    l.open("C:\\Users\\urankar\\OneDrive\\Desktop\\shreyas.txt", ios::in);
    while (getline(l, read)) {
        i++;
        cout << i << " " << read << endl;
    }
    l.close();
}

void File::search() {
    char search[30];
    cout << "Enter the stat to search :- ";
    cin >> search;
    l.open("C:\\Users\\urankar\\OneDrive\\Desktop\\shreyas.txt", ios::in);
    while (getline(l, read)) {
        if (read.find(search, 0) != string::npos) {
            cout << read << endl;
        }
    }
    l.close();
}

void File::modify() {
    char name[10], age[5], job[10];
    int target;
    cout << "Enter the entry number to modify :- ";
    cin >> target;
    l.open("C:\\Users\\urankar\\OneDrive\\Desktop\\shreyas.txt", ios::in);
    temp.open("C:\\Users\\urankar\\OneDrive\\Desktop\\Temp.txt", ios::out);
    int linenumber = 1;
    while (getline(l, read)) {
        if (linenumber == target) {
            cout << "Enter your name :- ";
            cin >> name;
            cout << "Enter your age :- ";
            cin >> age;
            cout << "Enter your job profile :- ";
            cin >> job;
            temp << name << " " << age << " " << job;
        } else {
            temp << read << endl;
        }
        linenumber++;
    }
    l.close();
    temp.close();
    remove("C:\\Users\\urankar\\OneDrive\\Desktop\\shreyas.txt");
    rename("C:\\Users\\urankar\\OneDrive\\Desktop\\Temp.txt", "C:\\Users\\urankar\\OneDrive\\Desktop\\madhura.txt");
}

void File::deleteRec() {
    int linenumber = 1;
    int target;
    cout << "Enter the entry to delete :- ";
    cin >> target;
    l.open("C:\\Users\\urankar\\OneDrive\\Desktop\\shreyas.txt", ios::in);
    temp.open("C:\\Users\\urankar\\OneDrive\\Desktop\\temp.txt", ios::out);
    while (getline(l, read)) {
        if (linenumber == target) {
            // Skip the line to delete
        } else {
            temp << read << endl;
        }
        linenumber++;
    }
    l.close();
    temp.close();
    remove("C:\\Users\\urankar\\OneDrive\\Desktop\\shreyas.txt");
    rename("C:\\Users\\urankar\\OneDrive\\Desktop\\temp.txt", "C:\\Users\\urankar\\OneDrive\\Desktop\\shreyas.txt");
}

int main() {
    int option;
    bool s = true;
    while (s) {
        cout << "---------------MENU---------------" << endl;
        cout << "1 - ADD" << endl;
        cout << "2 - DISPLAY" << endl;
        cout << "3 - SEARCH" << endl;
        cout << "4 - MODIFY" << endl;
        cout << "5 - DELETE" << endl;
        cout << "0 - EXIT" << endl;
        cout << "----------------------------------" << endl;
        cout << "OPTION :- ";
        cin >> option;
        switch (option) {
            case 1: {
                j.add();
                break;
            }
            case 2: {
                j.display();
                break;
            }
            case 3: {
                j.search();
                break;
            }
            case 4: {
                j.modify();
                break;
            }
            case 5: {
                j.deleteRec();
                break;
            }
            case 0: {
                cout << "Exit";
                s = false;
                break;
            }
        }
    }
}
