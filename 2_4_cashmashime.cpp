#include <fstream>
#include <iostream>
#include <ctime>
using namespace std;
void full_cash () {
    srand(time(nullptr));
    ofstream cash ("cash_mashine.txt");
    for (int i = 0; i < 1000; i++){
        int banknote;
        int n = rand() % 100;
        if (n < 40) {banknote = 100;}
        else if (n < 50) {banknote = 200;}
        else if (n < 70) {banknote = 500;}
        else if (n < 90) {banknote = 1000;}
        else {banknote = 5000;}
        cash << banknote << endl;
    }
    cash.close();
}
void cash_save (int cash_state[]) {
    ofstream cashier("cash_mashine.txt");
    for (int i = 0; i < 1000; i++)
    {
        cashier << cash_state[i] << endl;
    }
    cashier.close();
}
int main()
{
    cout << "\033[2J\033[1;1H";
    cout << "Welcome to our cashmashime!" << endl;
    cout << "Input type of operation: " << endl;
    cout << " - if you want to get money " << endl;
    cout << "and + if you are collector and you are going to full cashmashime" << endl;
    char type;
    int cash_state[1000];
    while (true) {
        cin >> type;
        if (type == '+' || type == '-') {
            break;
        }
    }
    if (type == '+') { 
        full_cash (); 
    }
    else {
        int sum_remove = -1;
        cout << "Input removing sum: ";
        while (sum_remove <= 0 || sum_remove % 100 != 0)
        {
            cin >> sum_remove;
            if (sum_remove <= 0)
            {
                cout << "You can't take sum that equals null or less \n";
                cout << "Please, repeat your input ";
            }
            else if (sum_remove % 100 != 0) {
                cout << "The withdrawal amount must be a multiple of 100! \n";
                cout << "Please, repeat your input ";
            }
        }
        ifstream cash("cash_mashine.txt");
        for (int i = 0; i < 1000; i++) {
            cash >> cash_state [i];
        }
        int count = 0;
        while (sum_remove > 0 && count < 1000) {
            if (cash_state[count] <= sum_remove && cash_state[count] != 0)
            {
                sum_remove -= cash_state[count];
                cout << cash_state[count] << endl;
                cash_state[count] = 0;                
            }
            count++;
        }
        if (sum_remove > 0) {
            cout << "Sorry, but now there is not enough money for removing your sum. Try again later";
        }
        cash.close();
        if (sum_remove == 0) {
            cash_save(cash_state);
        }
    }
}