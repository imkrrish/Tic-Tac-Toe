#include<iostream>

using namespace std;

class gameboard{
    char A[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
    int choice;
    char Turn = 'X';
    int row,col;
    bool draw = false;
    public:
    void displayBoard();
    void playerTurn();
    bool gameOver();
    void announceWinner();

};

void gameboard::displayBoard(){
    system("cls");
    cout<<"\t\tT I C  T O C  T O E !!";
    cout<<"\n\n\t\tPlayer1 [X]\n\t\tPlayer2 [O]";
    cout<<"\n\n\n";
    cout<<"\t\t\t     |     |     \n";
    cout<<"\t\t\t  "<<A[0][0]<<"  |  "<<A[0][1]<<"  |  "<<A[0][2]<<"  \n";
    cout<<"\t\t\t_____|_____|_____\n";
    cout<<"\t\t\t     |     |     \n";
    cout<<"\t\t\t  "<<A[1][0]<<"  |  "<<A[1][1]<<"  |  "<<A[1][2]<<"  \n";
    cout<<"\t\t\t_____|_____|_____\n";
    cout<<"\t\t\t     |     |     \n";
    cout<<"\t\t\t  "<<A[2][0]<<"  |  "<<A[2][1]<<"  |  "<<A[2][2]<<"  \n";
    cout<<"\t\t\t     |     |     \n";
}

void gameboard::playerTurn(){
    if (Turn == 'X'){
    cout<<"\n\n\t\tPlayer 1 [X] Turn:";
    }
    if (Turn == 'O'){
    cout<<"\n\n\t\tPlayer 2 [O] Turn:";
    }

    cin>>choice;

    switch (choice)
    {
    case 1: row = 0 ; col=0 ; break;
    case 2: row = 0 ; col=1 ; break;
    case 3: row = 0 ; col=2 ; break;
    case 4: row = 1 ; col=0 ; break;
    case 5: row = 1 ; col=1 ; break;
    case 6: row = 1 ; col=2 ; break;
    case 7: row = 2 ; col=0 ; break;
    case 8: row = 2 ; col=1 ; break;
    case 9: row = 2 ; col=2 ; break;
    
    default:
        cout<<"\t\tInvalid choise !! \n\t\tPlease try again...";
        break;
    }

    if (Turn == 'X' && A[row][col] != 'X' && A[row][col] != 'O'){
        A[row][col] = 'X';
        Turn = 'O';
    }

    else if(Turn == 'O' && A[row][col] != 'X' && A[row][col] != 'O'){
            A[row][col] = 'O';
            Turn = 'X';
    }
    else{
        cout<<"\t\t\tBox is already filled \n\t\t\tPlease try again";
        this->playerTurn();
    }
    this->displayBoard();
}

bool gameboard::gameOver(){
//check winner
    for(int i = 0; i < 3; i++){
        if( A[i][0] == A[i][1] && A[i][0] == A[i][2] || A[0][i] == A[1][i] && A[0][i] == A[2][i] ){
            return false;
        }
    }

    for(int i = 0; i < 3; i++){
    if( A[0][0] == A[1][1] && A[0][0] == A[2][2] || A[0][2] == A[1][1] && A[0][2] == A[2][0] ){
        return false;
        }
    }

//game is running
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if (A[i][j] != 'X' && A[i][j] != 'O')
            {
                return true;
            }
            
        }
    }

//draw game
draw = true;
return false;

}

void gameboard::announceWinner(){

    if( Turn == 'O' && draw == false){
        cout<<"\n\n\t\t*******Congratulations*******\n";
        cout<<"\n\t\t     Player1 [X] Wins !!!\n\n";
    }

    else if( Turn == 'X' && draw == false){
        cout<<"\n\n\t\t*******Congratulations*******\n";
        cout<<"\n\t\t     Player2 [O] Wins !!!\n\n";
    }
    
    else{
        cout<<"\n\n\t\t*** G A M E   D R A W ***\n";
    }

}


int main(){
    gameboard obj;

    while (obj.gameOver())
    {
        obj.displayBoard();
        obj.playerTurn();
        obj.gameOver();
    }

    obj.announceWinner();
    return 0;
}