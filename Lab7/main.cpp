/*
 * main.cpp
 *
 * Starter code for the Circle Markers lab, CSCI 262
 */

#include <iostream>
#include <list>
#include <vector>

using namespace std;

void rotateCircle(list<int> &game, int direction, int rotations);

int main()
{
    int players = 0;
    int markers = 0;

    cout << "How many players will there be?" << endl;
    cin >> players;

    cout << endl;
    cout << "What is the highest numbered marker?" << endl;
    cin >> markers;

    cout << endl;

    // Keep track of player scores; players are numbered 1..n.  
    // A map would work fine here, too.
    vector<int> scores(players + 1, 0);

    // This will hold our circle of markers
    list<int> game;
    game.push_front(0);
    int cplayer = 1;

    // Loop over all the rest of the markers
    for (int m = 1; m <= markers; m++)
    {
        if (m % 23 == 0)
        {
          rotateCircle(game, -1, 7);//get the point value 7c
          scores[cplayer] += m + game.front();//add them to the score
          game.pop_front();
          //rotateCircle(game, 1, 1);//set new mark
        }
        else
        {
          rotateCircle(game, 1, 2);
          game.push_front(m);
        }
        cplayer++;
        if (cplayer > players)
        {
          cplayer = 1;
        }
    }
    int maxplayer = 0;
    int maxscore = 0;
    for (int i = 1; i < scores.size(); i++)
    {
      //cout << scores[i] << endl;
      if (scores[i] > maxscore)
      {
        maxplayer = i;
        maxscore = scores[i];
      }
    }
 
    cout << "The winner is player " << maxplayer << " with a score of " << maxscore << "!" << endl;
}

void rotateCircle(list<int> &game, int direction, int rotations)
{
  int slot = 0;
  for (int i = 0; i < rotations; i++)
  {
    if (direction == 1)
    {
      slot = game.front();
      game.pop_front();
      game.push_back(slot);
    }
    else
    {
      slot = game.back();
      game.pop_back();
      game.push_front(slot);
    }
  }
}


