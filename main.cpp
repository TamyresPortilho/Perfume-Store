#include <iostream>
#include <vector>


using namespace std;

const int HUGO_BOSS {0};
const int BURBERRY {1};
const int BVLGARI {2};
const int AZZARO {3};
const int EUPHORIA {4};
const int CKONE {5};
const int GIORGIO_ARMANI {6};
const int MON_PARIS {7};
const int COACH {8};
const int ONE_MOMENT {9};

int perfume_number {0};
const int SIZE {10};

// All the names of the perfumes that we have

string perfume_arr[SIZE] {"Boss in Emotion (Hugo Boss)", "Burberry Brit (Burberry)", "Omnia (Bvlgari)", "Azzaro Chrome (Azzaro)",
                        "Euphoria (Calvin Klein)", "CK One (Calvin Klein)", "Armani Code (Giorgio Armani)", "Mon Paris (YSL Beauty)", 
                        "Coach (Coach)", "One moment (Justin Bieber)"};

int price_arr[SIZE] {89, 112, 85, 89, 112, 89, 110, 135, 112, 85}; // Price of each perfume

void numberValidation() { // Only numbers 1 to 10
    
    while(!(cin >> perfume_number)) {
        
        cout << "Error: enter a number: ";
        cin.clear();
        cin.ignore(123, '\n');
    }
}

char charValidation() { // Only yes or no letters - (y/n) uppercase and lowercase
    char c {};
    while(!(cin >> c) || (c != 'Y' && c != 'y') && (c != 'N' && c != 'n')) {
        
        cout << "Error: enter Y/N: ";
        cin.clear();
        cin.ignore(123, '\n');
    }
    return c;
}

int choice (vector<string> &list,int price) { // The name of the perfume you chose and if it is the right one

    char chosing_perfume {};
    
    while (perfume_number <= 0 || perfume_number > 10) {
        
        cout << "\nSomething is wrong.." << endl;
        cout << "\nYou need to enter a value between 1 to 10: ";
        numberValidation();
    }
        
    do {
            
        cout << "\nYou chose " << perfume_arr [perfume_number - 1] << "." << " Is that correct? (Y/N): ";
        chosing_perfume = charValidation();
        
            if (chosing_perfume == 'Y' || chosing_perfume == 'y') {
                cout << "\nThat is good, let's proceed..." << endl;
                list.push_back(perfume_arr[perfume_number-1]);
                price = price + price_arr[perfume_number - 1]; // The total cost
                cout << "===============================================" << endl;
            }
            
            else {
                cout << "\nOh, I am sorry. Please, tell me which one you wanted: ";
                numberValidation();
            }
            
        } while (chosing_perfume == 'N' || chosing_perfume == 'n');
        return price;
    } 

void showVector(const vector<string> list) {
    
    cout << "\nHere is the list of are all the perfumes you chose:\n" << endl;
    for(int i = 0; i < list.size(); i++) {
        cout << list.at(i) << endl;
    }
}

int main() {
    
    char confirmation {};
    int price {0};

    vector<string> userList;
    
    cout << "Hello there! Welcome to Tamy's Perfumes Store!" << endl;
    cout << "\nThis store contains 10 types of the best seller 100ml Perfumes" << endl;

    cout << "===============================================" << endl;
    
// Perfumes' menu

    cout << "\nHere are some perfumes' names, brand and price that we have in stock: " << endl;
    cout << "\n1- " << perfume_arr [HUGO_BOSS] << " = " << "$" << price_arr[HUGO_BOSS] << endl; 
    cout << "2- " << perfume_arr [BURBERRY] << " = " << "$" << price_arr[BURBERRY] << endl;
    cout << "3- " << perfume_arr [BVLGARI] << " = " << "$" << price_arr[BVLGARI] << endl;
    cout << "4- " << perfume_arr [AZZARO] << " = " << "$" << price_arr[AZZARO] << endl;
    cout << "5- " << perfume_arr [EUPHORIA] << " = " << "$" << price_arr[EUPHORIA] << endl;
    cout << "6- " << perfume_arr [CKONE] << " = " << "$" << price_arr[CKONE] << endl;
    cout << "7- " << perfume_arr [GIORGIO_ARMANI] << " = " << "$" << price_arr[GIORGIO_ARMANI] << endl;
    cout << "8- " << perfume_arr [MON_PARIS] << " = " << "$" << price_arr[MON_PARIS] << endl;
    cout << "9- " << perfume_arr [COACH] << " = " << "$" << price_arr[COACH] << endl;
    cout << "10- " << perfume_arr [ONE_MOMENT] << " = " << "$" << price_arr[ONE_MOMENT] << endl;
    
    cout << "===============================================" << endl;
    
    cout  << "\nWhich perfume are your interested in? Let us know by writing the numbers 1 to 10: ";
    numberValidation();
    
    do {
    
        price = choice(userList, price);
        
        cout << "\nWould you like something else? (Y/N): ";
        confirmation = charValidation();
        
            if (confirmation == 'N' || confirmation == 'n') {
                cout << "\n\nThank you! I appreciated your choice!\n";
                cout << "===============================================" << endl;
            }
            else {
                cout  << "\nYou can choose here the one you like: ";
                numberValidation();
            }
    } while (confirmation == 'Y' || confirmation == 'y');
    
    showVector(userList);
    
    cout << "===============================================" << endl;
    
    cout << "\nLet's go to the payment!" << endl;
    
    cout << "The total cost is: $" << price << endl;
    
    cout << "\n\n===============================================" << endl;
    
    cout << "\nThank you for shopping with us!!!" << endl;
    
    cout << "\n===============================================" << endl;
    
    cout << endl;
    
    return 0;
}