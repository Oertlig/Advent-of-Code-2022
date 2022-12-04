#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int current_calories = 0;
    int highest_calories = 0;
    int elf = 0;
    int most_prepared_elf;
    int sum = 0;

    vector<int> elves;
    string number;
    ifstream input ("input.txt");

    while(input) {
        getline(input, number);
        if(isdigit(number[0]) == true) {
            current_calories += stoi(number);
        } else {
            elf++;
            elves.push_back(current_calories);
            // if(current_calories > highest_calories) {
            //     highest_calories = current_calories;
            //     most_prepared_elf = elf;
            // }
            // cout << "[+] Elf " << elf  << ": " << current_calories << " calories" << endl;
            current_calories = 0;
        }
    }
    sort(elves.begin(), elves.end());

    // for(int i = 0; i < elves.size(); i++) {
    //    cout << "[+] Elf " << i  << " has " << elves.at(i) << " calories" << endl;
    // }
    cout << "[+] Elf " << elves.size()-1 << " has the most calories at " << elves.at(elves.size()-1) << endl;
    sum = elves.at(elves.size()-1) + elves.at(elves.size()-2) + elves.at(elves.size()-3); 
    cout << "[+] Sum of the top 3 elves are: " << sum << endl;  
    return 0;
}