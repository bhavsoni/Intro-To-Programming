//
//  main.cpp
//  gameboard
//
//  Created by Bhavin Soni on 12/10/16.
//  Copyright © 2016 Bhavin Soni. All rights reserved.
//

#include <iostream>
using namespace std;
class gameboard {
private:
    char commonboard[3][3];
        char player;
    char playertwo;
    public:
    bool playervalidate(int x, int y) {
        return !(playerboard[x][y] == 1);
    }
    
    bool playertwovalidate(int x, int y) {
        return !(playertwoboard[x][y] == 1);
    }

    int playerboard[3][3];
    int playertwoboard[3][3];
    bool isfull(){
        for(int x =0; x<3;x++){
            for(int y=0;y<3;y++){
                if(commonboard[x][y]!='X'||commonboard[x][y]!='O'){
                    return false;}
            }
        }
        return true;
    }
    gameboard(){
        this->player = ' ';
        this->playertwo = ' ';
    }
    gameboard(char player, char playertwo) {
        this->player = player;
        this->playertwo = playertwo;
        
    }
    void playerupdate(int x, int y) {
        if (playervalidate(x, y)) {
            commonboard[x][y] = player;
            playerboard[x][y] = 1;
        }
    }
    
void playertwoupdate(int x, int y) {
        if (playertwovalidate(x, y)) {
            commonboard[x][y] = playertwo;
            playertwoboard[x][y] = 1;
        }
    }
    
    bool playercheck() {
        int rowone = playerboard[0][0] + playerboard[0][1] + playerboard[0][2];
        int rowtwo = playerboard[1][0] + playerboard[1][1] + playerboard[1][2];
        int rowthree = playerboard[2][0] + playerboard[2][1] + playerboard[2][2];
        int colone = playerboard[0][1] + playerboard[1][1] + playerboard[2][1];
        int coltwo = playerboard[0][0] + playerboard[1][0] + playerboard[2][0];
        int colthree = playerboard[0][2] + playerboard[1][2] + playerboard[2][2];
        int diagone = playerboard[0][0] + playerboard[1][1] + playerboard[2][2];
        int diagtwo = playerboard[2][0] + playerboard[1][1] + playerboard[0][2];
        if (rowone == 3 || rowtwo == 3 || rowthree == 3 || colone == 3 || coltwo == 3 || colthree == 3 || diagone == 3
            || diagtwo == 3) {
            return true;
        }
        return false;
    }
    
     bool playertwocheck() {
        int rowone = playertwoboard[0][0] + playertwoboard[0][1] + playertwoboard[0][2];
        int rowtwo = playertwoboard[1][0] + playertwoboard[1][1] + playertwoboard[1][2];
        int rowthree = playertwoboard[2][0] + playertwoboard[2][1] + playertwoboard[2][2];
        int colone = playertwoboard[0][1] + playertwoboard[1][1] + playertwoboard[2][1];
        int coltwo = playertwoboard[0][0] + playertwoboard[1][0] + playertwoboard[2][0];
        int colthree = playertwoboard[0][2] + playertwoboard[1][2] + playertwoboard[2][2];
        int diagone = playertwoboard[0][0] + playertwoboard[1][1] + playertwoboard[2][2];
        int diagtwo = playertwoboard[2][0] + playertwoboard[1][1] + playertwoboard[0][2];
        if (rowone == 3 || rowtwo == 3 || rowthree == 3 || colone == 3 || coltwo == 3 || colthree == 3 || diagone == 3
            || diagtwo == 3) {
            return true;
        }
        return false;
        
    }
    
    
     void displayboard() {
        for (int x = 0; x < 3; x++) {
            cout<<"|";
            for (int y = 0; y < 3; y++) {
                cout<<commonboard[x][y]; cout<< "|";
            }
            cout<<endl;
            cout<<"______";
        }
    }
};
class game {
public:
    bool playvsplay=false;
    gameboard board;
    char player1;
    char player2;
    void compvsplayer(){
        
    }
    
    void display(){
        int choice;
        choice=0;
        
        while(choice!=1&&choice!=2){
            cout<<"Welcome to Tic-Tac-Toe v1.0"<<endl;
            cout<< "Enter 1 for Player vs Player"<<endl;
            cout <<"Enter 2 for Player vs Computer"<<endl;
            cout<<"Press anything else to quit the game"<<endl;
            cin>>choice;
            if(choice==1){
                playvsplay=true;
                
            }else{
                playvsplay=false;
            }
    }
        choice = 0;
        if (playvsplay==true){
            while(player1!='X'||player1!='O'){
            cout<<"Player 1 goes first. What does Player 1 want be? Choose a letter PLayer 1 wants to be (X or O)."<<endl;
            cin>>player1;
            }
            player2 = (player1=='X')?'O':'X';
           
        }else{
            while(choice!=1&&choice!=2){
            cout<<"Does Player 1 want to go first or have the computer go first? Enter 1 to go first or 2 to go second."<<endl;
                cin>>choice;
            }
            while((player1!='X'&&player1!='O')||(player2!='X'&&player2!='O')){
            switch (choice){
                case 1: cout<<"Enter the letter you want to be."<<endl;
                    cin>>player1;
                    player2=(player1=='X')?'O':'X';
                    break;
                    
                case 2: cout<<"Enter the letter you want to be."<<endl;
                    cin>>player2;
                    player1=(player2=='X')?'O':'X';
                    break;
                    
            }
            }
        }
        
    }
    void playervsplayer(){
        int row; int column;
        board = gameboard(player1,player2);
        while(!board.isfull()){
            do{
        cout<<"player 1 enter row"<<endl;
        cin>>row;
        cout<<"enter a column"<<endl;
        cin>>column;
            }while(board.playervalidate(row, column));
            board.playerupdate(row, column);
            board.displayboard();
            if(board.playercheck()){
                cout<<"player1 wins"<<endl;
                break;
            }
            do{
                cout<<"player 2 enter row"<<endl;
                cin>>row;
                cout<<"enter a column"<<endl;
                cin>>column;
            }while(board.playertwovalidate(row, column));
            board.playertwoupdate(row, column);
            board.displayboard();
            if(board.playertwocheck()){
                cout<<"player2 wins"<<endl;
                break;
            }
         board.displayboard();
        }
        
    }

   game(){
      
    }
    
};
int main(){
    game game1;
    game1.display();
    game1.playervsplayer();
    
    return 0;
}
