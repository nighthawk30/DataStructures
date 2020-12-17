/*
    partc.cpp

    Author: Clayton Kramp and Lucas Henke

    Last modified: 2/6/2020

*/

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <cmath>

using namespace std;

// TODO: Implement your hash function!
int hash_string (string str)
{
    int output = 0;
    for (int i = 0; i < str.length(); i++)
    {
      output += str[i];
    }
    output %= 1000;
    //cout << output << endl;
    return output;
}

int main()
{
    // open dictionary and read in all the words
    int hashKey;
    cout << "What is your hash key?" << endl;
    cin >> hashKey;

    cout << "Reading dictionary...";
    ifstream fin("dictionary.txt");

    if (!fin) {
        cerr << "Could not open 'dictionary.txt' for reading, exiting." << endl;
        return -1;
    }

    // Our hashed map
    map<int, vector<string>> hashedMap;
    string word;

    while (!fin.eof()) {
        getline(fin, word);
        // For each word, hash it!
        int hash_value = hash_string(word);

        // Add the hash word into our map
        hashedMap[hash_value].push_back(word);
    }

    fin.close();
    cout << "done." << endl;

    // Given a hash, find the words that map to it
    cout << "Finding possible words for the hash " << hashKey << endl;
    vector<string> vec = hashedMap[hashKey];
    for (string i : vec) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
