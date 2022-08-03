 #include<iostream>
 using namespace std;

 char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
 char current_marker;
 int current_player;

void drawboard()
{
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "-----------\n";
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "-----------\n";
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
}

bool placeMarker(int slot)
{
    int row = slot / 3;
    int col;
    if(slot % 3 == 0){
        row = row - 1;
        col = 2;
    }
    else col = slot % 3 - 1;
   
    if(board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = current_marker;
        return true;
    }
    else{
        return false;
    }
}

int winner()
{
    for(int i=0 ; i<3 ; i++)
    {
        //rows
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2]) return current_player;
        //columns
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i]) return current_player;
    }
    //diagonals
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2]) return current_player;
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0]) return current_player;

    return 0;
}

void swap_player_and_marker()
{
    if(current_marker == 'X') current_marker = 'O';
    else current_marker = 'X';

    if(current_player == 1) current_player = 2;
    else current_player = 1;
}

void game()
{
    cout<< "Player One, Choose your Marker X or O: ";
    char marker_p1;
    cin >> marker_p1;

    current_player = 1;
    current_marker = marker_p1;

    drawboard();

    int player_won;

    for(int i=0 ; i<9 ; i++)
    {
        cout << "It's player " << current_player << "'s turn. Enter your slot: ";
        int slot;
        cin>>slot;

        if(slot < 1 || slot > 9){
            cout << "That Slot is Invalid! Try another slot!\n";
             i--;
            continue;
        }
        if(!placeMarker(slot)) { 
        cout << "That Slot Occupied! Try another slot!\n";
        i--;
        continue;
        }
        drawboard();
        player_won = winner();
        if(player_won == 1) { cout << "Player One Won! Congratulations!"; break; }
        if(player_won == 2) { cout << "Player Two Won! Congratulations!"; break; }
        swap_player_and_marker();
        
    }
    if(player_won == 0) cout << "It's a TIE!";
}
int main()
{
    game();
}