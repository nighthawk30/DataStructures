/*
    hangman.cpp
        
    Method implementations for the hangman class.
    
    assignment: CSCI 262 Project - Evil Hangman        

    author: Nathan Taylor

    last modified:
*/

#include "hangman.h"

using namespace std;

// constructor
hangman::hangman()
{
  srand(time(NULL));
  ifstream inFile("dictionary.txt");
  string line;
  while(!inFile.eof())
  {
    getline(inFile, line);
    words_remaining.insert(line);
  }
  inFile.close();
}


// start_new_game()
//
// Setup a new game of hangman.
void hangman::start_new_game(int num_guesses, int word_length)
{
  guesses = num_guesses;
  length = word_length;
  set<string>::iterator it = words_remaining.begin();
  set<string> new_list;
  //build list of words
  while (it != words_remaining.end())
  {
    if (it->length() == word_length)
    {
      new_list.insert(*it);
    }
    it++;
  }
  //build display word
  for (int i = 0; i < length; i++)
  {
    display_word += "-";
  }
  words_remaining = new_list;
}


// process_guess()
//
// Process a player's guess - should return true/false depending on whether
// or not the guess was in the hidden word.  If the guess is incorrect, the
// remaining guess count is decreased.
bool hangman::process_guess(char c)
{
  //add character to list of guessed characters and sort the list
  guessed_chars += c;
  sort(guessed_chars.begin(), guessed_chars.end());
  //create a partition for each space in the word
  unordered_map<int, set<string>> partition;
  set<string> part2 = words_remaining;
  //go through the word
  for (int i = 0; i < length; i++)
  {
    //create a set for the location where the guess could go
    set<string> part1;
    for (set<string>::iterator itset = words_remaining.begin(); itset != words_remaining.end(); itset++)
    {
      //find the open spot in the word
      //create a partition where the guess is in the open spot in the word
      if (display_word[i] == '-' && (*itset)[i] == c)
      {
        part1.insert(*itset);
        part2.erase(*itset);
      }
    }
    if (part1.size() > 0)
    {
      partition.insert({i, part1});
    }
  }
  partition.insert({-1, part2});

  //prune the partitions to make sets where the character occurs in multiple spots
  for (unordered_map<int, set<string>>::iterator it = partition.begin(); it != partition.end(); it++)
  {
    for (set<string>::iterator itset = it->second.begin(); itset != it->second.end(); itset++)
    {
      for (int i = 0; i < length; i++)
      {

      }
    }
  }
  //find the biggest partition
  unordered_map<int, set<string>>::iterator itmap = partition.begin();
  int location_index = itmap->first;
  set<string> new_list = itmap->second;
  while (itmap != partition.end())
  {
    //cout << "Partition Size: " << itmap->second.size() << ", " << itmap->first << endl;
    if (itmap->second.size() > new_list.size())
    {
      location_index = itmap->first;
      new_list = itmap->second;
    }
    itmap++;
  }
  words_remaining = new_list;

  if (location_index == -1)//not chosen into word
  {
    guesses--;//remove a guess
    return false;
  }
  else//the letter was chosen
  {
    //find all places where the guessed letter in the same spot
    bool repeats[length];
    for (set<string>::iterator it = words_remaining.begin();
         it != words_remaining.end(); it++)
    {
      for (int i = 0; i < length; i++)
      {
        if ((*it)[i] != c)
        {
          repeats[i] = true;
        }
      }
    }
    //replace all locations in the display that have repeated letters
    //add the guess to the defined word
    for (int i = 0; i < length; i++)
    {
      if (!repeats[i])//there is a repetition in all words at that location
      {
        display_word[i] = c;
      }
    }
    return true;
  }
}

bool hangman::process_guess_part2(char c)
{
  /*TASKS
   1. Add guess to list of guessed letters
   2. Create partitions of the remaining words for each location where the guessed letter could go
   3. This will include a set where the words do not include the guessed letter
   4. Prune
   5. Loop through the partitions to find the one that is the biggest size
   6. If a partition with the letter is chosen, then find all the location that the words in the partition share the letter and replace those indeces with the guess
   7. Set the new partition to be the words remaining
   */

  //1
  guessed_chars += c;
  //2
  set<set<string>> partition;
  for (int i = 0; i < length; i++)//where could the guess go
  {
    if (display_word[i] == '-')
    {
      set<string> part;
      for (set<string>::iterator it = words_remaining.begin(); it != words_remaining.end(); it++)
      {
        if ((*it)[i] == c)
        {
          part.insert(*it);
        }
      }
      if (!part.empty())
      {
        partition.insert(part);
      }
    }
  }
  //3
  set<string> part;
  for (set<string>::iterator it = words_remaining.begin(); it != words_remaining.end(); it++)
  {
    bool notFound = true;
    for (int i = 0; i < length; i++)
    {
      if ((*it)[i] == c)
      {
        notFound = false;
      }
    }
    if (notFound)
    {
      part.insert(*it);
    }
  }
  if (!part.empty())
  {
    partition.insert(part);
  }
  //4
  set<string> bigFam = *partition.begin();
  for (set<set<string>>::iterator it = partition.begin(); it != partition.end(); it++)
  {
    if (it->size() > bigFam.size())
    {
      bigFam = *it;
    }
  }
  //5
  bool overlap[length];//where do all tiles overlap - the character to replace
  for (set<string>::iterator it = bigFam.begin(); it != bigFam.end(); it++)
  {
    for (int i = 0; i < length; i++)
    {
      if ((*it)[i] != c)
      {
        overlap[i] = true;
      }
    }
  }

  bool nooverlap = true;
  for (int i = 0; i < length; i++)
  {
    if (!overlap[i])
    {
      nooverlap = false;
    }
  }

  for (int i = 0; i < length; i++)
  {
    if (!overlap[i] && display_word[i] == '-')
    {
      display_word[i] = c;
    }
  }
  //6
  words_remaining = bigFam;
  //7 - extra stuff
  //prune
  if (!nooverlap)
  {
    correct_chars += c;
  }
  else
  {
    guesses--;
  }
  for (set<string>::iterator it = bigFam.begin(); it != bigFam.end(); it++)
  {
    for (int i = 0; i < length; i++)
    {
      if (display_word[i] == '-')
      {
        for (char j : correct_chars)
        {
          if ((*it)[i] == j)
          {
            words_remaining.erase(*it);
          }
          break;
        }
      }
    }
  }
  return !nooverlap;
}

// get_display_word()
//
// Return a representation of the hidden word, with unguessed letters
// masked by '-' characters.
string hangman::get_display_word()
{
    return display_word;
}


// get_guesses_remaining()
//
// Return the number of guesses remaining for the player.
int hangman::get_guesses_remaining()
{
    return guesses;
}

// get_guessed_chars()
//
// What letters has the player already guessed?  Return in alphabetic order.
string hangman::get_guessed_chars()
{
  sort(guessed_chars.begin(), guessed_chars.end());
  return guessed_chars;
}


// was_char_guessed()
//
// Return true if letter was already guessed.
bool hangman::was_char_guessed(char c)
{
  for (char i : guessed_chars)//ooh, a range based for loop
  {
    if (i == c)
    {
      return true;
    }
  }
  return false;
}


// is_won()
//
// Return true if the game has been won by the player.
bool hangman::is_won()
{
  //has been won if there are no more spaces
  for (char c : display_word)
  {
    if (c == '-')
    {
      return false;
    }
  }
  return true;
}


// is_lost()
//
// Return true if the game has been lost.
bool hangman::is_lost()
{
  if (guesses <= 0)
  {
    return true;
  }
  return false;
}


// get_hidden_word
//
// Return the true hidden word to show the player.
string hangman::get_hidden_word()
{
  //choose a random word remaining in the partition
  int hidden_index = rand() % words_remaining.size();
  set<string>::iterator it = words_remaining.begin();
  int cindex = 0;
  while (it != words_remaining.end())
  {
    if (cindex == hidden_index)
    {
      return *it;
    }
    cindex++;
  }
}

int hangman::get_words_remaining()
{
  return words_remaining.size();
}

void hangman::print_remaining()
{
  int counter = 0;
  for(set<string>::iterator it = words_remaining.begin();
       it != words_remaining.end(); it++)
  {
    cout << counter << ". " << *it << endl;
    counter++;
  }
}