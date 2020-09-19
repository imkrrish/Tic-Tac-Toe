#include<iostream>

using namespace std;

class gameboard{
    char A[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
    public:
    void displayBoard();

};

void gameboard::displayBoard(){
    system("CLS");
    cout<<"\t\tT I C  T O C  T O E !!";
    cout<<"\n\n\t\tPlayer[X]\n\t\tPlayer[O]";
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
int main(){
    gameboard obj;
    obj.displayBoard();
    return 0;
}