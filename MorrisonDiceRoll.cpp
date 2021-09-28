#include<iostream>
#include<cstdlib>
#include<ctime>
#include<windows.h>
using namespace std;
int main()
//a program that has a "Player 1" and "Player 2" variable/
//Have the user enter a name for Player 1 and Player 2/
//Have your program roll a 20 sided die for each Player and store that information/
//If the dice roll is a 1 also store that the roll was a "Critical Failure" and if the dice roll was a 20 store that the roll was a "Critical Success"/

//show the user the rolls
//show if the roll was a critical failure or critical success
//output the Winner (the player with the highest roll)
//If both rolls are the same output that the players were "Evenly Matched"
{
    HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);
    string player1;
    string player2;
    int p1roll;
    int p2roll;
    int p1color = 7;
    int p2color = 7;
    string p1crit;
    string p2crit;
    string winner;

    cout << "Enter Player 1 name:";
    cin >> player1;
    cout << "Enter Player 2 name:";
    cin >> player2;

    srand(time(0));
    p1roll = rand() % (20 - 1 + 1) + 1;
    p2roll = rand() % (20 - 1 + 1) + 1;

    if (p1roll == 1) {
        p1color = 12;
        p1crit = "Critical Failure";
    } else if (p1roll == 20) {
        p1color = 10;
        p1crit = "Critical Success";
    };

    if (p2roll == 1) {
        p2color = 12;
        p2crit = "Critical Failure";
    } else if (p2roll == 20) {
        p2color = 10;
        p2crit = "Critical Success";
    };

    if (p1roll > p2roll) {
        winner = player1;
    } else if (p1roll < p2roll) {
        winner = player2;
    } else {
        winner = "No one your Evenly Matched play again.";
    };
    
    cout << "The two Players play the game, here are the results."<< endl;
    cout << "Player 1 rolls:" << p1roll << endl;
    cout << "Player 2 rolls:" << p2roll << endl;
    cout << "-------------------------------" << endl;
    cout << "Player 1 critical status: "; 
    SetConsoleTextAttribute ( screen, p1color);
    cout << p1crit << endl;
    SetConsoleTextAttribute ( screen, 7);
    cout << "Player 2 critical status: ";
    SetConsoleTextAttribute ( screen, p2color);
    cout << p2crit << endl;
    SetConsoleTextAttribute ( screen, 7);
    cout << "-------------------------------" << endl;
    cout << "Winner is " << winner << endl;
    return 0;
}