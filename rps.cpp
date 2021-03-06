#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

//variables
int c_choice = 0;
int u_choice = 0;
const int ROCK = 1;
const int PAPER = 2;
const int SCISSORS = 3;
int response;
bool play = false;
//Function Definitions
void computerChoice(int & c_choice) {
    srand(time(0));
    const int MAX_VALUE = 3;
    const int MIN_VALUE = 1;
    c_choice = (rand() % (MAX_VALUE - MIN_VALUE + 1) + MIN_VALUE);
}
void userChoice(int & u_choice) {
    int choice;
    cout << "Please enter choice: \n";
    cin >> choice;
    while (choice < 1 || choice > 3) {
        cout << "Remember \n";
        cout << "- - - - - - - - - - - - - - - \n";
        cout << "1 = Rock\n" << "2 = Paper \n" << "3 = Scissors \n";
        cout << "- - - - - - - - - - - - - - - \n" << "Please enter choice: \n";
        cin >> choice;
    }
    u_choice = choice;
}

void showChoices(int &, int &) {
    cout << "\n You Picked: " ;
    if (u_choice == 1){
        cout << "Rock";
    }else if(u_choice == 2) {
        cout << "Paper";
    }else if(u_choice == 3){
        cout << "Scissors";
    }
    cout << "\n Computer Picked: ";
}

void winner (int u_choice, int c_choice ) {
    if(u_choice == c_choice) {
        cout<<"Its a tie... go again.\n";
        userChoice(u_choice);
        showChoices(u_choice, c_choice);

        //Simulate computer choice function
        computerChoice(c_choice);
        cout << c_choice;
        if (c_choice == 1) {
            cout << " = Rock" << "\n- - - - - - - - - - - - - - - \n";
        } else if (c_choice == 2) {
            cout << " = Paper" << "\n- - - - - - - - - - - - - - -\n";
        } else if (c_choice == 3) {
            cout << " = Scissors" << "\n- - - - - - - - - - - - - - - \n";
        }
        winner(u_choice, c_choice);
    }else if (u_choice == ROCK) {
        if (c_choice == PAPER) {
            cout << "Computer Wins!\nSince Paper beats Rock \n";
        } else if (c_choice == SCISSORS) {
            cout << "You WIN!\nSince Rock beats Scissors \n";
        }
    } else if (u_choice == PAPER) {
        if (c_choice == SCISSORS) {
            cout << "Computer Wins!\nSince Scissors beats Paper \n";
        } else if (c_choice == ROCK) {
            cout << "You WIN!\nSince Paper beats Rock \n";
        }
    } else if (u_choice == SCISSORS) {
        if (c_choice == ROCK) {
            cout << "Computer Wins!\nSince Rock beats Scissors \n";
        } else if (c_choice == PAPER) {
            cout << "You WIN!\nSince Scissors beats Paper \n";
        }
    }
}

void playAgain() {
    play = false;
    cout<< "Do you want to play again? (1 to Play Again/2 to Quit)\n";
    cin >> response;
    while (response != 1 && response != 2) {
        cout << "Invalid response. Try Again (1 to Play Again/2 to Quit)\n";
        cin >> response;
    }
    if (response == 1) {
        play = true;
        cout << "\n Rules\n" << "1 = Rock\n" << "2 = Paper \n" << "3 = Scissors \n";
        cout << "- - - - - - - - - - - - - - - \n";
        cout << "Rock (1) beats Scissors (3) \n" << "Scissors (3) beats Paper (2) \n" << "Paper (2) beats Rock (1) \n";
        cout << "- - - - - - - - - - - - - - - \n" << "Its you vs the computer. First to three WINS! \n";
        cout << "- - - - - - - - - - - - - - - \n" << "Let the Games Begin!! \n";
        cout << "- - - - - - - - - - - - - - - \n";
        userChoice(u_choice);
        showChoices(u_choice, c_choice);
        //Simulate computer choice function
        computerChoice(c_choice);
        cout << c_choice;
        if (c_choice == 1) {
            cout << " = Rock" << "\n- - - - - - - - - - - - - - - \n";
        } else if (c_choice == 2) {
            cout << " = Paper" << "\n- - - - - - - - - - - - - - -\n";
        } else if (c_choice == 3) {
            cout << " = Scissors" << "\n- - - - - - - - - - - - - - - \n";
        }
        winner(u_choice, c_choice);
    }else if (response == 2) {
        play = false;
        cout << "Thanks for playing";
    }
}

void rps_main() {
    //Sets the rules and how one could win/lose
    cout << "\n Rules\n" << "1 = Rock\n" << "2 = Paper \n" << "3 = Scissors \n";
    cout << "- - - - - - - - - - - - - - - \n";
    cout << "Rock (1) beats Scissors (3) \n" << "Scissors (3) beats Paper (2) \n" << "Paper (2) beats Rock (1) \n";
    cout << "- - - - - - - - - - - - - - - \n" << "Its you vs the computer. First to three WINS! \n";
    cout << "- - - - - - - - - - - - - - - \n" << "Let the Games Begin!! \n";
    cout << "- - - - - - - - - - - - - - - \n";
    //User choice function
    userChoice(u_choice);
    showChoices(u_choice, c_choice);
    //Simulate computer choice function
    computerChoice(c_choice);
    cout << c_choice;
    if (c_choice == 1) {
        cout << " = Rock" << "\n- - - - - - - - - - - - - - - \n";
    } else if (c_choice == 2) {
        cout << " = Paper" << "\n- - - - - - - - - - - - - - -\n";
    } else if (c_choice == 3) {
        cout << " = Scissors" << "\n- - - - - - - - - - - - - - - \n";
    }
    winner(u_choice, c_choice);
    playAgain();
    while (play != false) {
        playAgain();
    }
}