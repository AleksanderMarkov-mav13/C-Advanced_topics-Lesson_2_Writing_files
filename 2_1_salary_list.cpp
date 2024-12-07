#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    cout << "\033[2J\033[1;1H";
    cout << "You can put date about salary your workers here." << endl;
    cout << "Input step by step: Surname, Name, Date of paiment and Sum." << endl;
    string surname;
    string name;
    string date;
    string pay_sum;
    int sal_sum;
    ofstream file("vedomost_1.txt", ios::app);
    file << endl;
    while (true) {
        cin >> surname;
        if (surname == "0")
        {
            break;
        }
        file << surname << " ";
        cin >> name;
        file << name << " ";
        while (true) {
            cin >> date;
            try {
                int date_number = stoi(date.substr(0,2));
                int month = stoi(date.substr(3, 2));
                int year = stoi(date.substr(6, 4));
                // cout << date_number << " " << month << " " << year << endl;
                if ((date_number >= 1 && date_number <= 31) & (month >= 1 && month <= 12))
                {
                    break;
                }
                else {
                    cout << "Incorrect date! Repeat input date of payment: "<< endl;
                }
            }
            catch (const invalid_argument &e)
            {
                cerr << "ERROR! It's not a date! Please, repeat your input:" << endl;
            }
        }
        file << date << " ";

        while (true) {
            cin >> pay_sum;
            try {
                sal_sum = stoi(pay_sum);
                break;
            }
            catch (const invalid_argument &e) {
            cerr << "ERROR! It's not a number! Please, repeat your input:" << endl;
            }
        }
        file << sal_sum << endl;
        cout << "Next worker: " << endl;
    }
    file.close();
}