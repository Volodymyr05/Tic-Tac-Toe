#include <iostream>
using namespace std;

char field[9] = {};
void clearscreen(){
     for(int i=0;i<100;i++){
         cout<<endl;
  }
}
void clearfield(){
    for(int i=0;i<10;i++){
            field[i]='-';
    }
}
bool has_wonQ(char player){
  int wins[8][3] = {{0,1,2}, {3,4,5}, {6,7,8}, {0,3,6}, 
                     {1,4,7}, {2,5,8}, {0,4,8}, {2,4,6}};
    for(int i = 0; i<8; i++){
        int count = 0;
           for(int j = 0; j<3; j++){
               if(field[wins[i][j]] == player)
               count++;
    }
    if(count==3){
       return true;
    }
  }
return false;
}

void print_field(){
  cout<<endl;
   cout<<" TIC - TAC - TOE "<<endl;
   cout<<" Lets play the game ! "<<endl;
   cout<<" Player 1 moves (X) ..... Player 2 moves (0) "<<endl;
   cout<<  "          |         |       " <<endl;
   cout<<   "     "   << field[0] <<   "    |    " << field[1] << "    |    " << field[2] <<endl;
   cout<<   " _________|_________|________ " <<endl;
   cout<<  "          |         |       " <<endl;
   cout<<   "     "   << field[3] <<   "    |    " << field[4] << "    |    " << field[5] <<endl;
   cout<<   " _________|_________|________ " <<endl;
   cout<<  "          |         |       " <<endl;
   cout<<   "     "   << field[6] <<   "    |    " << field[7] << "    |    " << field[8] <<endl;
   cout<<  "          |         |       " <<endl;
}
int getchoice(){
     cout<<"\n Options for entering numbers: \n";
  cout<<"   |   |   " <<endl;
  cout<<" 1 | 2 | 3 " <<endl;
  cout<<"___|___|___" <<endl;
  cout<<"   |   |   " <<endl;
  cout<<" 4 | 5 | 6 " <<endl;
  cout<<"___|___|___" <<endl;
  cout<<"   |   |   " <<endl;
  cout<<" 7 | 8 | 9 " <<endl;
  cout<<"   |   |   " <<endl;
  cout<<"\n";

print_field();
  cout<< "\n Enter a number: ";
  int choice;
  cin>>choice;
  while(choice>9 || choice<1 || field[choice-1]!= '-'){ 
  cout<<"Enter a number from 1 to 9:\n";
  cin>>choice;
  }
  return choice;
}

char play_and_get_winner(){
    int turn=1;
while(!has_wonQ('X') && !has_wonQ('0')){
    clearscreen();
    int choice = getchoice();
    clearscreen();
        if(turn%2 == 1){
    field[choice-1]='X';
        if(has_wonQ('X')){
    cout<<"Player X win!\n";
    return 'X';
    }
    }
        else{
    field[choice-1]='0';
        if(has_wonQ('0')){
    cout <<"Player 0 win!\n";
    return '0';
    }
    }
    turn++;
        if(turn==9){
    cout << "The game is a draw !";
    return 'D';
    }
    }
    }
 int main(){
 int x_wins=0, o_wins=0, draw=0;
 clearfield();
 char winner = play_and_get_winner();
    print_field();
switch(winner){
      case 'X':
        x_wins++;
        break;
     case '0':
        o_wins++;
        break;
     case 'D':
        draw++;
        break;
    }
    cout<<"Player X: " << x_wins << ", Player 0: "<<o_wins << " Draw: "<<draw<<"\n\n";
    }

