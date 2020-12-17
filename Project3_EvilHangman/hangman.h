#ifndef _HANGMAN_H
#define _HANGMAN_H

/*
    hangman.h
        
    Class definition for the hangman class.

    assignment: CSCI 262 Project - Evil Hangman        

    author: Nathan Taylor

    last modified:
*/

#include <string>
#include <fstream>
#include <cstdlib>
#include <set>
#include <unordered_map>
#include <algorithm>
#include <ctime>
#include <iostream>

using namespace std;

/******************************************************************************
   class hangman

   Maintains game state for a game of hangman.

******************************************************************************/

class hangman
{
public:
  hangman();

    // start a new game where player gets num_guesses unsuccessful tries
    void start_new_game(int num_guesses, int word_length);

    // player guesses letter c; return whether or not char is in word
    bool process_guess(char c);

    bool process_guess_part2(char c);//it didn't work the first time and Im too lazy to delete it

    // display current state of word - guessed characters or '-'
    string get_display_word();

    // How many guesses remain?
    int get_guesses_remaining();

    // What characters have already been guessed (for display)?
    string get_guessed_chars();

    // Has this character already been guessed?
    bool was_char_guessed(char c);

    //how many possible words are left
    int get_words_remaining();

    // Has the game been won/lost?  (Else, it continues.)
    bool is_won();
    bool is_lost();

    // Return the true hidden word.
    string get_hidden_word();

    void print_remaining();

private:
  set<string> words_remaining;
  int guesses;
  int length;
  string display_word;
  string guessed_chars;
  string correct_chars;
};

#endif