


//NAME AND RECITATION

//Bhavin Soni - LA
//Viveg Prashad - LB
//Giannis Satsios - LB
//Ahmet Ay - LH






#include <iostream>
#include <string>
#include <list>

using namespace std;

static const int point = 1; //for the min max algorithm


static enum {start, stop, InSession, ow, xw, draw} state;       //this will be used to determine the state of game. dont really do anything but makes it easier to determine results
                                                                //start - game start; stop -game stops; inSession - game is currently on ;
                                                                //ow = o wins ; xw = x wins; draw = draw in game


typedef struct {    //assigns these variables to the variable player
    string name;
    char symbol;
    int move;
    bool selected;
    bool win;
} player;


void gameboard();                   // shows board
void move();                        // players/computers move
void goption();                     // game options for player v player or player v computer
void playchar();                    // player character, x or o
void playname();                    // player's name
void playwin();                     // results of game
void newboard();                    // board is updated and shows new game
void newscreen();                   // updates the screen
void legalmove();                   // determines legality of move
void compreset();                   // displays computer's move on board
void boardreset();                  // clears the board, removes all move that has been made
void newplaymove();                 // players move is set to a new value to let it move on board
void gametitle();                   // title of game
void currboard();                   // shows what the game board looks like after moves
void currpos();                     // shows current postion on the board

bool wrongchar();                   // checks if the player types in anything besdies x or o
bool wrongmove();                   // checks if player moves in an occupied spot or outside the matrix
bool gend();                        // checks if  game ended
bool spacefree();                   // checks if the player put thier respective piece on a free spot



void compmoves(char _board[9], list<int> &move_list);  //determines the number of free spaces on board (MIN MAX ALG)

void compenumstate(char board[9]);   //checks the enum state of the board for the computer. helps evaluate game results

int comppoint(char _board[9], player _player); //MIN MAX ALG - computer point system, +point if winning, -point of losing (blocking), 0 = draw


int MiniMax(char _board[9], player _player);	// main min max alg - - sets up the function/game
int Miturn(char _board[9], player _player);       //min
int MaxMove(char _board[9], player _player);       //max



static player play1, play2, currplay;      //player1 , player 2, current player ; static helps it be initialized once throughout code
static string gameoption;                 //game option - this is a string instead of void to help issue a value to be implemented in the code - player v player or player v computer

static char board[9] = {0};             //sets up the martix of the playing field
static char x_o;                        //weather player is x or o
static int turn;                       //shows the last/next turn


void goption() {                        //game type
    cout << "   Player vs Computer --> Enter 1" << endl;
    cout << "   Player vs Player --> Enter 2" << endl;
    cout << "   Quit Game --> Enter 3 " << endl;
    cout << "     NOTE: Player 2 is also the Computer in the mode Player vs Computer"<<endl;
    int choice;
    cin >> choice;
    if(!cin.good()) {
        cout << "Must enter one of the numbers presented in the menu." << endl;
        newscreen();
    }
    switch(choice) {
        
        case 1:
            gameoption = "Player vs Computer";
            break;
        
        case 2:
            gameoption = "Player vs Player";
            break;
        
        case 3:
            cout<<"GAME OVER"<<endl;
            state = stop;
            break;
        
        default:
            cout << "Must enter one of these sections." << endl;
            newscreen();
    }
}


void playname() {
    if(gameoption == "Player vs Computer") {
        cout << "You are Player 1"<<endl;
        play1.name= "Player 1";
        play2.name= "Player 2";
    }
    
    if(gameoption == "Player vs Player") {
        cout<<"You are Player 1"<<endl;
        play1.name= "Player 1";
        cout<<"You will be facing Player 2"<<endl;
        play2.name="Player 2";
    }
}



// gets symbol for the current player
void playchar() {
    if(gameoption == "Player vs Computer") {
        int selection = rand() % 2;             //random selction between 0 and 2...randomly assigns who goes first
        if(selection == 0) {
            rand() % 2 == 0 ? play2.symbol = 'X' : play2.symbol = 'O'; //if random number between 0 and 2 is 0, player 2 = X or else = o
            x_o = play2.symbol;
            play2.selected = 1;
        }
        else if(selection == 1) {
            cout << play1.name <<" What would you like to be, X or O? Enter X or O.(CAPITALS): ";
            cin >> play1.symbol;
            x_o = play1.symbol;
            play1.selected = 1;
        }
    }
    
    else if(gameoption == "Player vs Player") {
        int sel = rand() % 2;      //used sel in order to select the value we need, selection was already used above...again random assign
        string player_name = "";    //used so that value of player name is initiated
        if(sel == 0) {
            player_name = play1.name;
            play1.selected = 1;
        }
        else if(sel == 1) {
            player_name = play2.name;
            play2.selected = 1;
        }
        cout << player_name <<" What would you like to be, X or O? Enter X or O.(CAPITALS): ";
        if(sel == 0) {
            cin >> play1.symbol;
            x_o = play1.symbol;
        } else {
            cin >> play2.symbol;
            x_o = play2.symbol;
        }
    }
    
    if(!cin.good() || wrongchar()) {
        cout << "Must be either X or O" << endl;
        playchar();
    }
    if(!play2.selected) {
        play1.symbol == 'X' ? play2.symbol = 'O' : play2.symbol = 'X'; //if player 1 is x then player 2 will be o
        play1.symbol == 'O' ? play2.symbol = 'X' : play2.symbol = 'O';
    } else if(!play1.selected) {
        play2.symbol == 'X' ? play1.symbol = 'O' : play1.symbol = 'X'; //if player 2 is x then player 1 will be o
        play2.symbol == 'O' ? play1.symbol = 'X' : play1.symbol = 'O';
    }
    state = InSession;  //state function = the game is in session
}


void move() {               //player's move
    cin.sync();
    if(gameoption == "Player vs Player") {
        if(play1.selected) {
            cout << play1.name << " Enter move from 1-9: ";
            cin >> play1.move;
            turn = play1.move;
            x_o = play1.symbol;
            play1.selected = 0;
            play2.selected = 1;
            currplay = play1;
        } else if(play2.selected) {
            cout << play2.name << " Enter move from 1-9: ";
            cin >> play2.move;
            turn = play2.move;
            x_o = play2.symbol;
            play1.selected = 1;
            play2.selected = 0;
            currplay = play2;
        }
    }
    
    else if(gameoption == "Player vs Computer") {
        if(play1.selected) {
            cout << play1.name << " Enter move from 1-9: ";
            cin >> play1.move;
            turn = play1.move;
            x_o = play1.symbol;
            currplay = play1;
            play1.selected = 0;
            play2.selected = 1;
            
        } else if(play2.selected) {
            play2.move = MiniMax(board, play2); //implementation of the MinMax algorithm for the computer
            turn = play2.move;
            x_o = play2.symbol;
            currplay = play2;
            play1.selected = 1;
            play2.selected = 0;
            compreset();
            
        }
    }
    
    legalmove();
    if(gend()) {
        return;
    }
}


void playwin() {
    if(state == xw && play1.symbol == 'X') {      //determines who wins at the end of the game...bunch of if-statements
        play1.win = 1;
        cout<<"Player 1 WON!"<<endl;
    } else if(state == ow && play1.symbol == 'O') {
        play1.win = 1;
        cout<<"Player 1 WON!"<<endl;
    } else if(state == xw && play2.symbol == 'X') {
        play2.win = 1;
        cout<<"Player 2 WON!"<<endl;
    } else if(state == ow && play2.symbol == 'O') {
        play2.win = 1;
        cout<<"Player 2 WON!"<<endl;
    } else {
        cout<<"DRAW!"<<endl;
    }
}


bool wrongchar() {                           //sets weather X or O was input correctly
    return (x_o != 'X' && x_o != 'O');
}


bool wrongmove() {                        //determines if move selected was valid or not by being between the matrix of 0-10
    return !(turn > 0 && turn < 10);
}


void newplaymove() {                 //sets players moves after restting
    play1.move = -1;
    play2.move = -1;
}


bool gend() {
    return (state == xw || state == ow || state == draw); //uses enumerators to determine the results of the game
}

void compreset() {                        //sets game to InSession--basically a reset
    state = InSession;
}


void boardreset() {                        //clears and resets board
    for(int i = 0; i < 9; ++i) {
        board[i] = 0;
    }
}


void newboard() {                           //updates the board
    if(state == InSession) {
        if(play1.move != -1 && play2.move == -1) {
            board[play1.move - 1] = play1.symbol;
        } else if(play2.move != -1) {
            board[play2.move - 1] = play2.symbol;
        }
    }
}


void currpos() {
    newboard();
    currboard();
    compenumstate(board);
}


bool spacefree() {                              //shows if space is free
    if(play1.move != -1 && play2.move == -1) {
        return board[play1.move - 1] == 0;
    } else if(play2.move != -1) {
        return board[play2.move - 1] == 0;
    }
    return 0;
}


void gameboard() {                  //GAMEBOARD
    cout << endl;
    cout << " " << board[0] << " | " << board[1] << " | " << board[2] << endl;
    cout << "**********" << endl;
    cout <<  " " << board[3] << " | " << board[4] << " | " << board[5] << endl;
    cout << "**********" << endl;
    cout <<  " " << board[6] << " | " << board[7] << " | " << board[8] << endl;
    cout << endl;
}

// displays the progress of the game
void currboard() {
    cout << "Board after "<<currplay.name<<"'s move" << endl;
    gameboard();
}


void legalmove() {
    if(wrongmove() || !spacefree()) {           //check if move is correct. if spot not free then tells user to put it somewhere else
        cout << "You cannot do that!" << endl;
        if(play2.move == -1) {
            play1.selected = 1;
            play2.selected = 0;
        } else {
            play1.selected = 0;
            play2.selected = 1;
        }
        if(gameoption == "Player vs Computer") {
            play1.selected = 1;
            play2.selected = 0;
        }
        move();
    }
}



//GAME TITLE
void gametitle() {
    cout << "************************************" << endl;
    cout << "*  The Greatest Tic-Tac-Toe Game   *" << endl;
    cout << "************************************" << endl;
}


void newscreen() {      //basically refreshes screen
    gametitle();
    goption();
}


void compenumstate(char board[9]) {                            //states the rules of winning and what is considered a draw
    if ((board[0] == x_o && board[1] == x_o && board[2] == x_o) ||                  //across and diagonal are considered wins.
        (board[3] == x_o && board[4] == x_o && board[5] == x_o) ||
        (board[6] == x_o && board[7] == x_o && board[8] == x_o) ||
        (board[0] == x_o && board[3] == x_o && board[6] == x_o) ||
        (board[1] == x_o && board[4] == x_o && board[7] == x_o) ||
        (board[2] == x_o && board[5] == x_o && board[8] == x_o) ||
        (board[0] == x_o && board[4] == x_o && board[8] == x_o) ||
        (board[2] == x_o && board[4] == x_o && board[6] == x_o))
    {
        if(x_o == 'X') {                                //if x is any of the spots show above then x wins else o wins
            state = xw;
        } else if(x_o == 'O') {
            state = ow;
        }
    }
    else {                                                  //if none of them are 3 in a row, then its a draw
        state = draw;
        for(int i = 0; i < 9; ++i) {
            if(board[i] == 0) {
                state = InSession;
                break;
            }
        }
    }
}

/////////////////////////////////////////////////////////////////////////////THIS IS THE MIN MAX ALGORITHM (HAD TO LOOK THIS UP FOR AI MOVES)


void compmoves(char _board[9], list<int> &move_list) {    //setsup the region bounded within the tic tac toe grid adn evaluates all spots
    for(int i = 0; i < 9; ++i) {
        if(_board[i] == 0) {
            move_list.push_back(i);  //mves the value into the desginated spot
        }
    }
}


int comppoint(char _board[9], player _player) {   //board is the calculated in terms of the winning and draw conditions
    compenumstate(_board);
    if(gend()) {
        if((state == xw && _player.symbol == 'X') || (state == ow && _player.symbol == 'O')) {
            return +point;                              //counts positive points toward moves
        } else if((state == xw && _player.symbol == 'O') || (state == ow && _player.symbol == 'X')) {
            return -point;                               //counts negative points towards moves
        } else if(state == draw) {
            return 0;
        }
    }
    return -1;
}


int MiniMax(char _board[9], player _player) {   //helps provide the best move from the AI
    int best_val = -point, index = 0;
    list<int> move_list;
    char best_moves[9] = {0};  //list bests mvoes from the matrix of the tic tac toe game
    compmoves(_board, move_list);   //evaluates the free spots
    while(!move_list.empty()) {
        _board[move_list.front()] = _player.symbol;
        x_o = _player.symbol;
        int val = Miturn(_board, _player);
        if(val > best_val) {
            best_val = val;   //value of next mvoe is better than the best move then val is the next new best move and put in that spot
            index = 0;
            best_moves[index] = move_list.front() + 1;
        } else if(val == best_val) {
            best_moves[++index] = move_list.front() + 1;  //if equal in value it will be placed in that spot
        }
        _board[move_list.front()] = 0;
        move_list.pop_front();
    }
    if(index > 0) {
        index = rand() % index;
    }
    return best_moves[index];
}


int Miturn(char _board[9], player _player) {                   //min code reprsents the computer
    int pos_value = comppoint(_board, _player);
    if(pos_value != -1) {
        return pos_value;
    }
    int best_val = +point;                           //counts positve points (winning)
    list<int> move_list;
    compmoves(_board, move_list);
    while(!move_list.empty()) {
        _player.symbol == 'X' ? x_o = 'O' : x_o = 'X';
        _board[move_list.front()] = x_o;
        int val = MaxMove(_board, _player);                 //evaluates best move in this circumstance
        if(val < best_val) {
            best_val = val;
        }
        _board[move_list.front()] = 0;
        move_list.pop_front();
    }
    return best_val;
}


int MaxMove(char _board[9], player _player) {                       //max code represents the player
    int pos_value = comppoint(_board, _player);
    if(pos_value != -1) {
        return pos_value;
    }
    int best_val = -point;                                   //counts negative points (blocking)
    list<int> move_list;
    compmoves(_board, move_list);
    while(!move_list.empty()) {
        _player.symbol == 'X' ? x_o = 'X' : x_o = 'O';
        _board[move_list.front()] = x_o;
        int val = Miturn(_board, _player);                 //evaluates best move in this circumstance
        if(val > best_val) {
            best_val = val;
        }
        _board[move_list.front()] = 0;
        move_list.pop_front();
    }
    return best_val;
}

//////////////////////////////////////////////////////////////////////////MIN MAX ALGORITHM ^^^





int main() {                        //main code runs in terms of the vid functions defined above
    
    gametitle();
    goption();
    
    if(state != stop) {
        playname();
        playchar();
        
        while(state != stop) {
            while(state == InSession) {
                newplaymove();
                move();
                currpos();
            }
            
            if(gend()) {
                playwin();
                compreset();
                boardreset();
                gametitle();
            }
            
            goption();
        }
    }
    return 0;
}
