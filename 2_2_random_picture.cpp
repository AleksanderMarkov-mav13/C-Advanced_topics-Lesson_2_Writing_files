#include <fstream>
#include <iostream>
#include <ctime>
using namespace std;
int main()
{
    srand(time(nullptr));
    cout << "\033[2J\033[1;1H";
    cout << "We drow a picture according your size with random numbers." << endl;
    cout << "Input hight: ";
    int hight, widht = 0;
    int random_number;
    cin >> hight;
    while (widht < 1 || widht > 40) {
        cout << "Input widht: ";
        cin >> widht;
        if (widht < 1) cout << "The width of your image must not be less than zero. Please repeat your input! " << endl;
        if (widht > 40) cout << "The widht of your picture must not be more than 40. Please repeat your input! " << endl;
    }
    ofstream file ("picture.txt");
    for (int i = 0; i < hight; i++) {
        for (int j = 0; j < widht; j++) {
            file << rand() % 2 << " ";
        }
        if (i != hight - 1) file << endl;
    }
    file.close ();
    cout << "Done! Look at your picture in file picture.txt from this directory!";
}