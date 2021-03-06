#include <iostream>
using namespace std;

char grid[3][3] = {{'1', '2', '3'},{'4', '5', '6'},{'7', '8', '9'}};
int row;
int column;
char input = 'x';
string name1;
string name2;
bool draw = false;
int digit;
string tempName;
string t_response;
bool playAgain;
string n3;

void intro(){
    cout << "By: Daniel Diaz-Arias and Luis Eduardo Gonzalez\n" << "Tic-Tac-Toe\n";
    cout << "Enter the first player's name:\n";
    cin >> name1;
    cout << "Enter the second player's name:\n";
    cin >> name2;
    tempName = name1;
}

void board() {

    cout << "   |   |   \n";
    cout << " " << grid[0][0] << " | " << grid[0][1] << " | " << grid[0][2] << "\n";
    cout << "___|___|___\n";
    cout << "   |   |   \n";
    cout << " " << grid[1][0] << " | " << grid[1][1] << " | " << grid[1][2] << "\n";
    cout << "___|___|___\n";
    cout << "   |   |   \n";
    cout << " " << grid[2][0] << " | " << grid[2][1] << " | " << grid[2][2] << "\n";
    cout << "   |   |   \n";
}

void func2() {
    cout<<tempName<<" enter location :\n";
    cin >> digit;

    //----------
    while(digit < 1 || digit >9){
        cout << "Invalid Input, Please Try Again.\n";
        cin >> digit;
    }
    if(digit ==1) {
        row = 0;
        column = 0;
    }else if(digit == 2) {
        row = 0;
        column = 1;
    }else if(digit == 3) {
        row = 0;
        column = 2;
    }else if(digit == 4) {
        row = 1;
        column = 0;
    }else if(digit == 5) {
        row = 1;
        column = 1;
    }else if(digit == 6) {
        row = 1;
        column = 2;
    }else if(digit == 7) {
        row = 2;
        column = 0;
    }else if(digit == 8) {
        row = 2;
        column = 1;
    }else if(digit == 9) {
        row = 2;
        column = 2;
    }
    if(input == 'x' && grid[row][column] != 'x' && grid[row][column] != 'o'){
        grid[row][column] = 'x';
        tempName = name2;
        input = 'o';
    }else if(input == 'o' && grid[row][column] != 'x' && grid[row][column] != 'o'){
        grid[row][column] = 'o';
        tempName = name1;
        input = 'x';
    }else{
        cout << "This is not an empty space, Please Try Again. \n";
        func2();
    }
}

bool func3(){
    for(int i = 0; i < 3; i++){
        if(grid[i][0] == grid[i][1] && grid[i][0] == grid[i][2] || grid[0][i] == grid[1][i] && grid[0][i] == grid[2][i]){
            return false;
        }
    }
    if(grid[0][0] == grid[1][1] && grid[0][0] == grid[2][2] || grid[0][2] == grid[1][1] && grid[0][2] == grid[2][0]){
        return false;
    }
    for(int i =0; i < 3; i++){
        for(int j =0; j < 3; j++){
            if(grid[i][j] != 'x' && grid[i][j] != 'o'){
                return true;
            }
        }
    }
    draw = true;
    return false;
}

void t_playGame(){
    cout << name1 << " will have the first turn\n";
    cout << name2 << " will have the second turn\n";
    while(func3()){
        board();
        func2();
        func3();
    }
    if(input == 'x' && draw == false){
        board();
        cout <<"Congratulations, " << name2<< " has won Tic Tac Toe!"<<endl;
        cout << "Do you want to play again? (y/n):\n";
        cin >> t_response;
        if(t_response == "y"){
            playAgain = true;
        }else if(t_response == "n"){
            playAgain = false;
            cout<<"Thanks for playing!";
        }else{
            cout << "Invalid Input. Thanks for playing!";
            playAgain = false;
        }
    }else if(input == 'o' && draw == false){
        board();
        cout << "Congratulations, " << name1 << " has won Tic Tac Toe!"<<endl;
        cout << "Do you want to play again? (y/n):\n";
        cin >> t_response;
        if(t_response == "y"){
            playAgain = true;
        }else if(t_response == "n"){
            playAgain = false;
            cout<<"Thanks for playing!";
        }else{
            cout << "Invalid Input. Thanks for playing!";
            playAgain = false;
        }
    }else{
        board();
        cout << "Its a draw.\n"<<endl;
        cout << "Do you want to play again? (y/n):\n";
        cin >> t_response;
        if(t_response == "y"){
            draw = false;
            playAgain = true;
        }else if(t_response == "n"){
            playAgain = false;
        }else{
            cout << "Invalid Input. Thanks for playing!";
            playAgain = false;
        }
    }
}

void ttt_main() {
    intro();
    t_playGame();
    while(playAgain){
        grid[0][0] = '1';
        grid[0][1] = '2';
        grid[0][2] = '3';
        grid[1][0] = '4';
        grid[1][1] = '5';
        grid[1][2] = '6';
        grid[2][0] = '7';
        grid[2][1] = '8';
        grid[2][2] = '9';
        n3 = name1; //n1 = d, n2 = l, n3 -> l n1 = l, n3 = n1
        name1 = name2;
        name2 = n3;
        if(input == 'x'){
            input = 'o';
        }
        if(input == 'o'){
            input = 'x';
        }
        t_playGame();
    }
}

