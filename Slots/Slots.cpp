#include <iostream>
#include <cstdlib>
#include <time.h>
#include <Windows.h>
using namespace std;
//C = Cherry, L = Lemon, B = Bell, R = BAR
//Multiple amounts of each to weigh the odds
char images[18] = { 'C', 'C', 'C', 'C', 'C', 'C', '7', 'B', 'B', 'B', 'B', 'R', 'R', 'L', 'L', 'L', 'L', 'L'};
char slot1, slot2, slot3;
int betAmount;
int balance = 1000;
bool canBet = false;
void bet() {
    cout << "C = Cherry, L = Lemon, B = Bell, R = BAR" << endl;
    cout << "Payouts: CCC = 25x, LLL = 50x, BBB = 100x, RRR = 250x, 777 = 500x" << endl << endl;
    cout << "How much do you want to bet? Your current balance is: " << balance << endl;
    while (canBet == false) {
        cin >> betAmount;
        if (betAmount > balance) {
            cout << "You cannout bet more than what you have" << endl;
            canBet = false;
        }
        else if (betAmount < 0) {
            cout << "You cannot bet a negative number" << endl;
        }
        else {
            canBet = true;
        }
    }
    system("cls");
}
void RNG() {
    srand(time(NULL));
    //these become indexes for the images array
    slot1 = rand() % 18;
    slot2 = rand() % 18;
    slot3 = rand() % 18;
}

void printScreen() {
    cout << "Current Balance: " << balance << endl;
    cout << "#################" << endl << "#################" << endl;
    cout << "## " << images[slot1] << " ## " << images[slot2] << " ## " << images[slot3] << " ##" << endl;
    cout << "#################" << endl << "#################" << endl << endl;
}
void payout() {
        if (slot1 <=5 && slot2 <=5 && slot3 <=5) {
            //Cherry
            balance += betAmount * 25;
            cout << "CONGRATS, YOU WIN!!" << endl;
            cout << "Your current balance is now " << balance;
        }
        else if (slot1 == 6 && slot2 == 6 && slot3 == 6) {
            //7
            balance += betAmount * 500;
            cout << "CONGRATS, YOU WIN!!" << endl;
            cout << "Your current balance is now " << balance;
        }
        else if ((7 <= slot1 && slot1 <= 10) && (7 <= slot2 && slot2 <= 10) && (7 <= slot3 && slot3 <= 10)) {
            //Bell
            balance += betAmount * 100;
            cout << "CONGRATS, YOU WIN!!" << endl;
            cout << "Your current balance is now " << balance;
        }
        else if ((11 <= slot1 && slot1 <= 12) && (11 <= slot2 && slot2 <= 12) && (11 <= slot3 && slot3 <= 12)) {
            //BAR
            balance += betAmount * 250;
            cout << "CONGRATS, YOU WIN!!" << endl;
            cout << "Your current balance is now " << balance;
        }
        else if (slot1 >= 13 && slot2 >= 13 && slot3 >= 13) {
            //Lemon
            balance += betAmount * 50;
            cout << "CONGRATS, YOU WIN!!" << endl;
            cout << "Your current balance is now " << balance;
        }
    }
int main()
{
        bet();
    while (true) {
        balance -= betAmount;
        if (balance < 0) {
            balance = 0;
            cout << "You ran out of money" << endl;
            system("pause");
            exit(0);
        }
        RNG();
        printScreen();
        payout();
        system("pause");
        system("cls");
    }
}