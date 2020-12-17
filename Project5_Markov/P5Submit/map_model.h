/*
   CSCI 262 Data Structures, Fall 2019, Project 4 - Markov

   Author: Lucas Henke

   Modified: 10/24/2019
*/
#ifndef _MAP_MODEL_H
#define _MAP_MODEL_H

#include <map>
#include <string>
#include "model.h"

using namespace std;

class map_model : public markov_model
{
 public:
  virtual void initialize(string text, int order);

  virtual string generate(int size);

 protected:
  map<string, string> k_gram;//first: k_gram, second: string of letters that follow
  int _order;
  string _text;
  // Add any variables you may need here
};

#endif
