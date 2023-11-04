#include <bits/stdc++.h>
using namespace std;
void AddPlayer();
void PrintAll();
void GetCertainPlayer();
void MainMenu();
void SortTheList();
// mohamed mostafa
// 20220309
// problem 5
// s23
struct Player{
    string name;
    int score;
    Player(){
        name = "AAA";
        score = 0;
    }
};
Player players[10];

int main(){
    MainMenu();

}

void MainMenu(){
    int optionNumber;
    do{
        cout << "Please enter the number of option that you want" << "\n" << "1- add new player and score" << "\n" << "2- print top 10 players";
        cout << "\n" << "3- a certain player's high score" << "\n"<<"4- Exit"<< endl;
        cin>> optionNumber;
    } while (!(optionNumber>= 1 && optionNumber <= 4));
    switch (optionNumber) {
        case 1:
            AddPlayer();
            break;
        case 2:
            PrintAll();
            break;
        case 3:
            GetCertainPlayer();
            break;
        case 4:
            cout << "thank you for using my app";
            break;
    }
}

void AddPlayer(){
    Player newPlayer;
    cout<< "enter the player name"<< endl;
    cin >> newPlayer.name;
    cout << "enter the player score" << endl;
    cin>> newPlayer.score;
    if(newPlayer.score> players[9].score){
        players[9].score = newPlayer.score;
        players[9].name = newPlayer.name;
        SortTheList();
    }

    MainMenu();
}
void PrintAll(){
    for (int i = 0 ; i< 10 ; i++){
        cout << players[i].name << "    " << players[i].score << endl;
    }
    MainMenu();
}
void GetCertainPlayer(){
    string playerName;
    cout << "enter player name"<< endl;
    cin>> playerName;
    for (int i = 0 ; i< 10 ; i++){
        if(playerName == players[i].name){
            cout<< "this player's high score is: " << players[i].score << endl;
            MainMenu();
            return;
        }
    }
    cout << "this player is not in the top 10 list";
}
void SortTheList(){
    for(int i = 0; i < 10 ; i++){
        for (int j = i+1 ; j < 10 ; j++){
            if(players[j].score > players[i].score){
                // swap
                Player temp = players[i];
                players[i] = players[j];
                players[j] = temp;
            }
        }
    }
}



