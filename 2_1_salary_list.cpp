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
    int sal_sum;
    ofstream file("vedomost_1.txt");
    while (true) {
        cin >> surname;
        if (surname == "0")
        {
            break;
        }
        file << surname << " ";
        cin >> name;
        file << name << " ";
        cin >> date;
        file << date << " ";
        cin >> sal_sum;
        file << sal_sum << endl;
    }
    file.close();
}