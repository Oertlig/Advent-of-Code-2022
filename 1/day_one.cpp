#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;

int main() {
    int current_calories = 0;
    int highest_calories = 0;
    int elf = 0;
    int most_prepared_elf;
    string number;
    ifstream input ("input.txt");

    while(input) {
        getline(input, number);
        if(isdigit(number[0]) == true) {
            current_calories += stoi(number);
        } else {
            elf++;
            if(current_calories > highest_calories) {
                highest_calories = current_calories;
                most_prepared_elf = elf;
            }
            // cout << "[+] Elf " << elf  << ": " << current_calories << " calories" << endl;
            current_calories = 0;
        }
    }

    cout << "[+] Elf " << most_prepared_elf  << " has the most calories at: " << highest_calories << " calories" << endl;
    return 0;
}