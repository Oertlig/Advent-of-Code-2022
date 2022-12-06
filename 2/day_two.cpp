#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <map>

using namespace std;


/*
    A - Rock - X  [1pt]
    B - Paper - Y [2pts]
    C - Scissors - Z [3pts]

    Loss [0pts]
    Tie [3pts]
    Win [6pts]
*/
int rock_paper_scissors(char shapeA, char shapeX) {
    int score = 0;
    switch (shapeA) {
        case 'A': // Rock
            switch (shapeX) {
            case 'X': // Rock
                score += (1 + 3);
                break;
            case 'Y': // Paper
                score += (2 + 6);
                break;
            case 'Z': // Scissors
                score += (3 + 0);
                break;
            default:
                break;
            }
            
            break;
        case 'B': // Paper

            switch (shapeX) {
            case 'X': // Rock
                score += (1 + 0);
                break;
            case 'Y': // Paper
                score += (2 + 3);
                break;
            case 'Z': // Scissors
                score += (3 + 6);
                break;
            default:
                break;
            }

            break;
        case 'C': // Scissors

            switch (shapeX) {
            case 'X': // Rock
                score += (1 + 6);
                break;
            case 'Y': // Paper
                score += (2 + 0);
                break;
            case 'Z': // Scissors
                score += (3 + 3);
                break;
            default:
                break;
            }

            break;
        default:
            break;
        }
    return score;
}

/*
    A - Rock [1pt]
    B - Paper [2pts]
    C - Scissors [3pts]

    X - Loss [0pts]
    Y - Tie [3pts]
    Z - Win [6pts]
*/
int win_draw_lose(char shapeA, char shapeX) {
    int score = 0;
    switch (shapeA) {
        case 'A': // Rock
            switch (shapeX) {
            case 'X': // Lose
                score += (3 + 0);
                break;
            case 'Y': // Tie
                score += (1 + 3);
                break;
            case 'Z': // Win
                score += (2 + 6);
                break;
            default:
                break;
            }
            
            break;
        case 'B': // Paper

            switch (shapeX) {
            case 'X': // Lose
                score += (1 + 0);
                break;
            case 'Y': // Tie
                score += (2 + 3);
                break;
            case 'Z': // Win
                score += (3 + 6);
                break;
            default:
                break;
            }

            break;
        case 'C': // Scissors

            switch (shapeX) {
            case 'X': // Lose
                score += (2 + 0);
                break;
            case 'Y': // Tie
                score += (3 + 3);
                break;
            case 'Z': // Win
                score += (1 + 6);
                break;
            default:
                break;
            }

            break;
        default:
            break;
        }
    return score;
}

int main() {
    
    char shapeA;
    char shapeX;
    char space;
    int score = 0;
    int score2 = 0;

    map <char, int> Player1;
    map <char, int> Player2;

    ifstream input ("day_2_input.txt");

    while(input) {
        input >> shapeA;
        input >> shapeX;
    
        score += rock_paper_scissors(shapeA, shapeX);
        score2 += win_draw_lose(shapeA, shapeX);

        shapeA = ' ';
        shapeX = ' ';
    }

    cout << "Part 1 Score is: " << score << endl;
    cout << "Part 2 Score is: " << score2 << endl;
    return 0;
}