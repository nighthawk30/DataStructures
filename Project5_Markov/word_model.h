/*
   CSCI 262 Data Structures, Project 5  - Markov

   Author: Nathan Taylor
*/
#ifndef _WORD_MODEL_H
#define _WORD_MODEL_H

#include "model.h"
#include <map>
#include <vector>
#include <string>
#include <cstdlib>
#include <iostream>

using namespace std;

class word_model : public markov_model
{
 public:
  virtual void initialize(string text, int order);
  virtual string generate(int size);
  vector<string> subvector(vector<string> &list, int start, int sublen);


 protected:
  int _order;
  string _text;
  map<vector<string>, vector<string>> w_gram;
  vector<string> passage;
};

#endif
