/*
   CSCI 262 Data Structures Project 5 - Markov

   Author: Nathan Taylor
*/
#include "map_model.h"

void map_model::initialize(string text, int order)
{
  _order = order;
  _text = text + text.substr(0, _order);
  //look through passage
  for (int i = 0; i < _text.length() - _order; i++)
  {//substr(startposition, number of characters)
    //adds each substring to the list, then adds each character following
    k_gram[_text.substr(i, _order)] += _text[i + _order];
  }
}

string map_model::generate(int size)
{
  string phrase;
  int start = rand() % k_gram.size();//random start position
  map<string, string>::iterator it = k_gram.begin();
  for (int i = 0; i < start; i++, it++) {}//get to the starting word section
  phrase = it->first;//start phrase

  for (int i = 0; i < size - _order; i++)//account for start phrase
  {
    string current = phrase.substr(i, _order);
    string char_sequence = k_gram.at(current);
    phrase += char_sequence[rand() % char_sequence.length()];
  }

  return phrase;
}