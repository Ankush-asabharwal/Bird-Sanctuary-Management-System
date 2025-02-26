// You are designing a Bird Sanctuary Management System where different types of birds reside. 
// Each bird has a name, species, and sound. 
// The sanctuary should allow:
// ->Adding new birds.
// ->Displaying all birds.
// ->Searching for a bird by species.
// ->Removing birds.

#include<iostream>
#include<vector>
using namespace std;

class bird{
    public :
    string name;
    string species;
    string sound;

    bird(string n, string sp, string s){
        name = n;
        species = sp;
        sound = s;
    }
};

class Store{
    public :
    vector<bird> vec;

    void add(string n, string sp, string s){
        bird d(n,sp,s);
        vec.push_back(d);
    }

    void display(){
        if(vec.empty()){
            cout << "No birds data" << endl;
            return;
        }

        for(auto it : vec){
            cout << "Bird name : " << it.name << endl; 
            cout << "Bird speices : " << it.species << endl; 
            cout << "Bird sound : " << it.sound << endl; 
            cout << "- - - - - - - - - -" << endl;
        }
    }

    void search(string speicesName){
        for(auto i : vec){
            if(speicesName == i.species){
                cout << "Bird found named : " << i.name << endl; 
                return;
            }
        }
        cout << "Bird not found" << endl;
    }

    void remove(const string& name) {
        for (auto it = vec.begin(); it != vec.end();) {
            if (it->name == name) {
                it = vec.erase(it);
                cout << "Bird removed successfully." << endl;
                return;
            } else {
                ++it;
            }
        }
        cout << "Bird not found for removal." << endl;
    }

    // void remove(string name){
    //     for(auto i : vec){
    //         if(name == i.name){
    //             vec.erase(vec.begin()+i);
    //         }
    //     }
    // }
};

int main() {
    Store s;
    int num;

    do {
        cout << "Menu:\n";
        cout << "1. Add new bird\n";
        cout << "2. Display all birds\n";
        cout << "3. Search for a bird by species\n";
        cout << "4. Remove a bird\n";
        cout << "5. Exit\n";
        cout << "---------------------------------\n";
        cout << "Enter your choice: ";
        cin >> num;

        string name, species, sound;

        switch (num) {
            case 1:
                cout << "Enter bird name: ";
                cin >> name;
                cout << "Enter species: ";
                cin >> species;
                cout << "Enter bird sound: ";
                cin >> sound;
                s.add(name, species, sound);
                break;

            case 2:
                s.display();
                break;

            case 3:
                cout << "Enter species to search: ";
                cin >> species;
                s.search(species);
                break;

            case 4:
                cout << "Enter bird name to remove: ";
                cin >> name;
                s.remove(name);
                break;

            case 5:
                cout << "Exiting..." << endl;
                break;

            default:
                cout << "Invalid choice. Try again!" << endl;
        }

    } while (num != 5);

    return 0;

}