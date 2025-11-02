// COMSC-210 | Lab 28 | Majd Bohsali
// IDE uses: Visual Studio Code
#include <iostream>
#include <fstream>
#include <iomanip>
#include <list>
#include "Goat.h"
using namespace std;

const int SZ_NAMES = 200, SZ_COLORS = 25;

int select_goat(list<Goat> trip);
void delete_goat(list<Goat>& trip);
void add_goat(list<Goat>& trip, string [], string []);
void display_trip(list<Goat> trip);
void deleteAllGoats(list<Goat>& trip);
void sortGoatsByName(list<Goat>& trip);
void returnYoungestGoat(list<Goat> trip);
void returnOldestGoat(list<Goat>& trip);
void calculateAverageAge(list<Goat>& trip);
void reverseGoatOrder(list<Goat>& trip);
void removeGoatsOfAge(list<Goat>& trip);
void getCountGoatsOfAge(list<Goat>& trip);
int main_menu();
int main() {
    srand(time(0));
    bool again;

    // read & populate arrays for names and colors
    ifstream fin("names.txt");
    string names[SZ_NAMES];
    int i = 0;
    while (fin >> names[i++]);
    fin.close();
    ifstream fin1("colors.txt");
    string colors[SZ_COLORS];
    i = 0;
    while (fin1 >> colors[i++]);
    fin1.close();

    // create & populate a trip of Goats using std::list of random size 8-15
    int tripSize = rand() % 8 + 8;
    list<Goat> trip;
    int age;
    string name, color;
    for (int i = 0; i < tripSize; i++) {
        age = rand() % MAX_AGE;  // defined in Goat.h
        name = names[rand() % SZ_NAMES];
        color = colors[rand() % SZ_COLORS];
        Goat tmp(name, age, color);
        trip.push_back(tmp);
    }
    
    // Goat Manager 3001 Engine
    int sel = main_menu();
    while (sel != 12) {
        switch (sel) {
            case 1:
                cout << "Adding a goat.\n";
                add_goat(trip, names, colors);
                break;
            case 2:    
                cout << "Removing a goat.\n";
                delete_goat(trip);
                break;
            case 3:    
                cout << "Displaying goat data.\n";
                display_trip(trip);
                break;
            case 4:    
                cout << "\n";
                deleteAllGoats(trip); 
                break;
            case 5:    
                cout << "\n";
                sortGoatsByName(trip); 
                break;
            case 6:    
                cout << "\n";
                returnYoungestGoat(trip);
                break;
            case 7:    
                cout << "\n";
                returnOldestGoat(trip); 
                break;
            case 8:    
                cout << "\n";
                calculateAverageAge(trip);
                break;
            case 9:    
                cout << "\n";
                reverseGoatOrder(trip);
                break;
            case 10:    
                cout << "\n";
                removeGoatsOfAge(trip); 
                break;
            case 11:    
                cout << "\n";
                getCountGoatsOfAge(trip); 
                break;
            default:
                cout << "Invalid selection.\n";
                break;
        }
        sel = main_menu();
    }
    
    return 0;
}

int main_menu() {
    cout << "*** GOAT MANAGER 3001 ***\n";
    cout << "[1] Add a goat\n";
    cout << "[2] Delete a goat\n";
    cout << "[3] List goats\n";
    cout << "[4] Delete all goats\n";
    cout << "[5] Sort goats by name\n";
    cout << "[6] Return youngest goat\n";
    cout << "[7] Return oldest goat\n";
    cout << "[8] Calculate average goat age\n";
    cout << "[9] Reverse goat order\n";
    cout << "[10] Remove goats of specific age\n";
    cout << "[11] Get count of specific age\n";
    cout << "[12] Quit\n";
    cout << "Choice --> ";
    int choice;
    cin >> choice;
    while (choice < 1 || choice > 12) {
        cout << "Invalid, again --> ";
        cin >> choice;
    }
    return choice;
}

void delete_goat(list<Goat> &trip) {
    cout << "DELETE A GOAT\n";
    int index = select_goat(trip);
    auto it = trip.begin();
    advance(it, index-1);
    trip.erase(it);
    cout << "Goat deleted. New trip size: " << trip.size() << endl;
}

void add_goat(list<Goat> &trip, string nms[], string cls[]) {
    cout << "ADD A GOAT\n";
    int age = rand() % MAX_AGE;
    string nm = nms[rand() % SZ_NAMES];
    string cl = cls[rand() % SZ_COLORS];
    Goat tmp(nm, age, cl);
    trip.push_back(tmp);
    cout << "Goat added. New trip size: " << trip.size() << endl;
}

void display_trip(list<Goat> trp) {
    int i = 1;
    for (auto gt: trp)
        cout << "\t" 
             << "[" << i++ << "] "
             << gt.get_name() 
             << " (" << gt.get_age() 
             << ", " << gt.get_color() << ")\n";
}

int select_goat(list<Goat> trp) {
    int input;
    cout << "Make a selection:\n";
    display_trip(trp);
    cout << "Choice --> ";
    cin >> input;
    while (input < 1 || input > trp.size()) {
        cout << "Invalid choice, again --> ";
        cin >> input;
    }
    return input;
}

void deleteAllGoats(list<Goat>& trip) {
    // Milestone 1
}

void sortGoatsByName(list<Goat>& trip) {
    // Milestone 2
}

void returnYoungestGoat(list<Goat> trip) {
    // Milestone 3
}

void returnOldestGoat(list<Goat>& trip) {
    // Milestone 4
}

void calculateAverageAge(list<Goat>& trip) {
    // Milestone 5
}

void reverseGoatOrder(list<Goat>& trip) {
    // Milestone 6
}

void removeGoatsOfAge(list<Goat>& trip) {
    // Milestone 7
}

void getCountGoatsOfAge(list<Goat>& trip) {
    // Milestone 8
}