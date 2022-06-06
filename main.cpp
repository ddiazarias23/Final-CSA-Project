#include <iostream>
#include "numberguesser.h"
#include "rps.h"
#include "tictactoe.h"

using namespace std;

int main(){

    int userChoice;
    int menu_choice;
    bool temp = true;
    cout<<"Welcome to the Game Center\n";
    cout<<"Select Your Game:\n";
    cout<<"1 - Number Guesser\n" << "2 - Tic Tac Toe\n" << "3 - Rock Paper Scissors:\n";
    cin >> userChoice;
    while(userChoice > 3 || userChoice < 1){
        cout<<"Remember the options:\n1 for Number Guesser\n2 for Tic TacToe\n3 for Rock Paper Scissors:\n";
        cin>>userChoice;
    }
    if(userChoice == 1){
        ng_main();
        while(temp) {
            cout << "\nBack to menu? (1 = yes/ 2 = no)\n";
            cin >> menu_choice;
            while (menu_choice > 3 || menu_choice < 1) {
                cout << "Remember the options\n1 = yes\n2 = no\n";
                cin >> menu_choice;
            }
            if (menu_choice == 1) {
                temp = true;
                main();
            }else if (menu_choice == 2) {
                temp = false;
                cout << "Thanks for playing!!";
                continue;
            }
        }
    }else if(userChoice == 2){
        ttt_main();
        while(temp) {
            cout << "\nBack to menu? (1 = yes/ 2 = no)\n";
            cin >> menu_choice;
            while (menu_choice > 3 || menu_choice < 1) {
                cout << "Remember the options\n1 = yes\n2 = no\n";
                cin >> menu_choice;
            }
            if (menu_choice == 1) {
                temp = true;
                main();
            } else if (menu_choice == 2) {
                temp = false;
                cout << "Thanks for playing!!";
                continue;
            }
        }
    }else if(userChoice == 3) {
        rps_main();
        while (temp) {
            cout << "\nBack to menu? (1 = yes/ 2 = no)\n";
            cin >> menu_choice;
            while (menu_choice > 3 || menu_choice < 1) {
                cout << "Remember the options\n1 = yes\n2 = no\n";
                cin >> menu_choice;
            }
            if (menu_choice == 1) {
                temp = true;
                main();
            } else if (menu_choice == 2) {
                temp = false;
                cout << "Thanks for playing!!";
                continue;
            }
        }
    }
}