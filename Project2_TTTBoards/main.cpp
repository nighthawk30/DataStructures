/*Nathan Taylor
 * Solve Tic tac toe
 */

#include <iostream>
#include <set>
#include <string>

using namespace std;

int winCheck(string board, bool turn);
void tacoRecursion(set<string> &boardSpace, string board, int &xwins, int &owins, int &ties, bool turn);

/*
     0 | 1 | 2
    ---+---+---
     3 | 4 | 5
    ---+---+---
     6 | 7 | 8
 */

int main()
{
    set<string> boardSpace;
    int xwins = 0;
    int owins = 0;
    int ties = 0;
    tacoRecursion(boardSpace, "         ", xwins, owins, ties, false);
    cout << "Total Boards: " << boardSpace.size() << ", wins for 'O': " << owins << ", wins for 'X': ";
    cout << xwins << ", ties: " << ties << endl;
    cout << "Boards:" << endl;
    for (set<string>::iterator it = boardSpace.begin(); it != boardSpace.end(); it++)
    {
        cout << *it << endl;
    }

    return 0;
}

void tacoRecursion(set<string> &boardSpace, string board, int &xwins, int &owins, int &ties, bool turn)
{
    if (!boardSpace.count(board))//check if this board is in the set, if it is, do nothing, otherwise
    {
        boardSpace.insert(board);//add the board to the set
        int check = winCheck(board, turn);//check if there is a win or tie and update the counter
        if (check != -1)//if there is a win or tie, the board ends
        {
            switch(check)
            {
                case 0:
                    xwins++;
                    break;
                case 1:
                    owins++;
                    break;
                case 2:
                    ties++;
                    break;
            }
        }
        else//recurse - make a move for your turn
        {
            turn = !turn;
            char player;
            if (turn) player = 'X';
            else player = 'O';

            for (int i = 0; i < 9; i++)
            {
                if (board[i] == ' ')
                {
                    string move = board;
                    move[i] = player;
                    tacoRecursion(boardSpace, move,xwins, owins, ties, turn);
                }
            }
        }
    }
}



int winCheck(string board, bool turn)
{
    int winCheck = -1;
    bool win = false;
    bool tie = true;
    char player;
    if (turn)
    {
        player = 'X';
    }
    else
    {
        player = 'O';
    }
    //check win
    if (board[0] == player && board[1] == player && board[2] == player ||
        board[3] == player && board[4] == player && board[5] == player ||
        board[6] == player && board[7] == player && board[8] == player ||
        board[0] == player && board[3] == player && board[6] == player ||
        board[1] == player && board[4] == player && board[7] == player ||
        board[2] == player && board[5] == player && board[8] == player ||
        board[0] == player && board[4] == player && board[8] == player ||
        board[2] == player && board[4] == player && board[6] == player)
    {
        win = true;
    }
    //check tie
    for (int i = 0; i < 9; i++)
    {
        if (board[i] == ' ')
        {
            tie = false;
        }
    }
    if (tie)
    {
        winCheck = 2;
    }
    if (win)
    {
        winCheck = turn;
    }
    return winCheck;
}


//HOWWWWWW vanilla