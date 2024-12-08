#include <fstream>
#include <iostream>
using namespace std;
int main()
{
    cout << "\033[2J\033[1;1H";
    cout << "Hello! Here you can catch some fish!" << endl;
    cout << "There are some types of fish in our river:" << endl;
    cout << "sunfish, shad, carp, bass, pike, bullhead, catfish, roach, walleye " << endl;
    cout << "Input name of fish you want to catch now: ";
    string fish_name;
    string river_fish;
    int count = 0;
    cin >> fish_name;
    ifstream river("river.txt");
    ofstream basket("basket.txt", ios::app);
    while (!river.eof()) {
        river >> river_fish;
        if (fish_name == river_fish) {
            count ++;
            basket << fish_name << endl;
        }
    }
    if (count > 0) {
        cout << "You have cought " << count << " fish today!" << endl;
        cout << "We put all of them into your basket";
    }
    else {
        cout << "Sorry! There is not such fish like " << fish_name << " in our river!";
    }
    river.close();
    basket.close();
    return 0;
}