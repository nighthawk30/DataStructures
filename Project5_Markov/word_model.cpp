/*
   CSCI 262 Data Structures Project 5 - Markov

   Author: Nathan Taylor
*/

#include "word_model.h"

void word_model::initialize(string text, int order)
{
  _order = order;
  //parse the string into a vector.
  //stringstreams are fucking slow, apparently
  string word = "";
  for (int i = 0; i < text.length(); i++)
  {
    if (text[i] != ' ')//make word
    {
      word += text[i];
    }
    else//cutoff word and add to vector
    {
      if (word != "")
      {
        passage.push_back(word);
        word = "";
      }
    }
  }
  vector<string> addOn = subvector(passage, 0, _order);
  for (int i = 0; i < _order; i++)
  {
    passage.push_back(addOn[i]);
  }
  //look at subvectors of the correct size and add the next word to their value
  for (int i = 0; i < passage.size() - _order; i++)
  {
    w_gram[subvector(passage, i, _order)].push_back(passage[i + _order]);
  }
}

string word_model::generate(int size)
{
  vector<string> phrase;
  int start = rand() % w_gram.size();//random start position
  map<vector<string>, vector<string>>::iterator it = w_gram.begin();
  for (int i = 0; i < start; i++, it++)
  {}//get to the starting word section
  phrase = it->first;//start phrase

  for (int i = 0; i < size - _order; i++)//account for start phrase
  {
    vector<string> current = subvector(phrase, i, _order);
    vector<string> word_sequence = w_gram.at(current);
    phrase.push_back(word_sequence[rand() % word_sequence.size()]);
  }

  string sphrase = "";
  for (int i = 0; i < phrase.size(); i++)
  {
    sphrase += phrase[i] + " ";
  }

  return sphrase;
}

vector<string> word_model::subvector(vector<string>& list, int start, int sublen)
{
  vector<string> sublist;
  for (int i = start; i < start + sublen; i++)
  {
    sublist.push_back(list[i]);
  }
  return sublist;
}