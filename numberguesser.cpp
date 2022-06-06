#include <iostream>
#include <cstdlib>
using namespace std;
static int guess;
int confirm;
bool n_play = false;

void restrictions(){
    while(guess > 100 || guess < 0){
        cout<<"Remember to guess numbers between 1 and 100.\n";
        cin >> guess;
    }
}

void game(){
    n_play = false;
    cout<< "Do you want to play again? (1 to Play Again/ 2 to Quit): \n";
    cin >> confirm;
    srand(time(0));
    while (confirm != 1 && confirm != 2) {
        cout << "Invalid response. Try Again (1 to Play Again/2 to Quit)\n";
        cin >> confirm;
    }
    if(confirm == 1) {
        n_play = true;
        cout << "Welcome to Try to Guess the Number!!\n";
        int number = rand() % 100 + 1;
        cout << "Guess a number between 1-100: ";
        cin >> guess;
        restrictions();
        while (number != guess) {
            if (guess < number) {
                restrictions();
                cout << "Too low. Guess higher... \n";
                cin >> guess;
            } else if (guess > number) {
                restrictions();
                cout << "Too high. Guess lower...\n";
                cin >> guess;
            }
        }
        cout << "Correct\nCongrats on guessing the correct number!!\n";
    }else if (confirm == 2) {
        n_play = false;
        cout << "Thanks for playing!";
    }
}

void ng_main() {
    srand(time(0));
    cout << "Welcome to Try to Guess the Number!!\n";
    int number = rand() % 100 + 1;
    cout << "Guess a number between 1-100: ";
    cin >> guess;
    restrictions();
    while (number != guess) {
        if (guess < number) {
            restrictions();
            cout << "Too low. Guess higher... \n";
            cin >> guess;
        } else if (guess > number) {
            restrictions();
            cout << "Too high. Guess lower...\n";
            cin >> guess;
        }
    }
    cout<< "Correct\nCongrats on guessing the correct number!!\n";
    game();
    while(n_play != false){
        game();
    }
}