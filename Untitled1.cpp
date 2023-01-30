#include <iostream>
#include <string>
#include <fstream>
using namespace std ;
char Blocks[3][3] = {'1','2','3','4','5','6','7','8','9'};
string player1 ;
string player2 ;
string temp ;
char xo = 'X';
int n ;
void Draw(){
    system("cls");
    cout<<"Tic Tac Toe by AryaKh"<<endl;
    for (int i = 0; i <3 ; i++) {
        for (int j = 0; j <3 ; j++) {
            cout<<Blocks[i][j]<<" ";
        }
        cout<<endl;

    }
}
void Input(){
    int x ;
    cout<<"It's "<< temp <<" turn. " <<"Press the number of block you want to choose... ";
    cin>>x;
    if(x>9 || x<1){
        cout<<"oops! you've entered wrong number! "<<endl;
        Input();
    }
    if(x==1){
        if(Blocks[0][0] == '1')
            Blocks[0][0] = xo ;
        else {
            cout<<"Block is already in use , try again sotoon. "<<endl;
            Input();
        }
    }

    else if(x==2){
        if(Blocks[0][1] == '2')
            Blocks[0][1] = xo ;
        else {
            cout<<"Block is already in use , try again sotoon. "<<endl;
            Input();
        }
    }
    else if(x==3){
        if(Blocks[0][2] == '3')
            Blocks[0][2] = xo ;
        else {
            cout<<"Block is already in use , try again sotoon. "<<endl;
            Input();
        }
    }
    else if(x==4){
        if(Blocks[1][0] == '4')
            Blocks[1][0] = xo ;
        else {
            cout<<"Block is already in use , try again sotoon. "<<endl;
            Input();
        }
    }
    else if(x==5){
        if(Blocks[1][1] == '5')
            Blocks[1][1] = xo ;
        else {
            cout<<"Block is already in use , try again sotoon. "<<endl;
            Input();
        }
    }
    else if(x==6){
        if(Blocks[1][2] == '6')
            Blocks[1][2] = xo ;
        else {
            cout<<"Block is already in use , try again sotoon. "<<endl;
            Input();
        }
    }
    else if(x==7){
        if(Blocks[2][0] == '7')
            Blocks[2][0] = xo ;
        else {
            cout<<"Block is already in use , try again sotoon. "<<endl;
            Input();
        }
    }
    else if(x==8){
        if(Blocks[2][1] == '8')
            Blocks[2][1] = xo ;
        else {
            cout<<"Block is already in use , try again sotoon. "<<endl;
            Input();
        }
    }
    else if(x==9){
        if(Blocks[2][2] == '9')
            Blocks[2][2] = xo ;
        else {
            cout<<"Block is already in use , try again sotoon. "<<endl;
            Input();
        }
    }
}
void ChangePlayer(){
    if (xo=='X'){
        xo = 'O' ;
    }else xo = 'X' ;
}
char CheckWin(){
    //player 1
    if(Blocks[0][0]=='X' && Blocks[0][1]=='X' && Blocks[0][2]=='X')
        return 'X';
    if(Blocks[1][0]=='X' && Blocks[1][1]=='X' && Blocks[1][2]=='X')
        return 'X';
    if(Blocks[2][0]=='X' && Blocks[2][1]=='X' && Blocks[2][2]=='X')
        return 'X';
    if(Blocks[0][0]=='X' && Blocks[1][0]=='X' && Blocks[2][0]=='X')
        return 'X';
    if(Blocks[0][1]=='X' && Blocks[1][1]=='X' && Blocks[2][1]=='X')
        return 'X';
    if(Blocks[0][2]=='X' && Blocks[1][2]=='X' && Blocks[2][2]=='X')
        return 'X';
    if(Blocks[0][0]=='X' && Blocks[1][1]=='X' && Blocks[2][2]=='X')
        return 'X';
    if(Blocks[0][2]=='X' && Blocks[1][1]=='X' && Blocks[2][0]=='X')
        return 'X';
   //Player 2
    if(Blocks[0][0]=='O' && Blocks[0][1]=='O' && Blocks[0][2]=='O')
        return 'O';
    if(Blocks[1][0]=='O' && Blocks[1][1]=='O' && Blocks[1][2]=='O')
        return 'O';
    if(Blocks[2][0]=='O' && Blocks[2][1]=='O' && Blocks[2][2]=='O')
        return 'O';
    if(Blocks[0][0]=='O' && Blocks[1][0]=='O' && Blocks[2][0]=='O')
        return 'O';
    if(Blocks[0][1]=='O' && Blocks[1][1]=='O' && Blocks[2][1]=='O')
        return 'O';
    if(Blocks[0][2]=='O' && Blocks[1][2]=='O' && Blocks[2][2]=='O')
        return 'O';
    if(Blocks[0][0]=='O' && Blocks[1][1]=='O' && Blocks[2][2]=='O')
        return 'O';
    if(Blocks[0][2]=='O' && Blocks[1][1]=='O' && Blocks[2][0]=='O')
        return 'O';

    return '/';

}

void Scoreboard()
{
	fstream write("scoreboard.txt");
	while(write >> temp)
	{
	cout << temp << " ";
	}
}

void menu()
{	int input_menu;
	cout << "\n1) Start game \n2) Scoreboard \n3) Exit \n";
	cin >> input_menu;
	if(input_menu==1)
	{
	cout<<"Enter 1st player name: ";
    cin>>player1;
    cout<<endl;
    cout<<"Enter 2nd player name: ";
    cin>>player2;
    cout<<endl;
	temp = player1;
    n = 0;
    Draw();
     while (true){
    n++;
    Input();
    Draw();
    if(CheckWin()=='X'){
        cout<<player1<<" wins !!!"<<endl;
		fstream write("scoreboard.txt",ios::app);
			write << player1 << " won " << player2 <<".\n";
			write.close(); 
        break;
    }else if(CheckWin()=='O'){
        cout<<player2<<" wins !!!"<<endl;
		fstream write("scoreboard.txt",ios::app);
			write << player2 << " won " << player1 <<".\n";
			write.close();
        break;
    }else if(CheckWin()=='/' && n==9){
        cout<<"Draw !!!"<<endl;
        fstream write("scoreboard.txt",ios::app);
		cout << player1 << " and " << player2 << " draw.\n";
		write.close();
		break;
    }
    ChangePlayer();
        if(n%2==0)
        temp = player1;
    else if(n%2==1)
        temp = player2;
     }
	}
	else if(input_menu==2)
	{
		Scoreboard();
	}
	else if(input_menu==3)
	{
		exit(0);
	}
}

 int main() 
{
	while(true)
	{
		menu();
	
	}
	return 0;
}
