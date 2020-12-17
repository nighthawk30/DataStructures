/*Nathan Taylor
 * main.cpp
 *
 * starter code for the Binary Tree lab, CSCI 262
 *
 * last modified: 3/10/2020
 */

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class node
{
public:
    string data;
    node* left;
    node* right;
};

void cursedTree(node* root, ifstream &fin);
void cursedLeaves(node* top);

// This program is simple enough to do the user interface in main()
int main()
{
    //file stream by reference
    string input_filename;

    cout << "What is the file you wish to read?" << endl;
    cin >> input_filename;

    ifstream fin(input_filename);
    if (!fin)
    {
	cout << "Error opening \"" << input_filename << "\" for reading." << endl;
	return -1;
    }

    // TODO: call your recursive function to read in the tree
    node* root = new node;
    cursedTree(root, fin);
    fin.close();

    // TODO: call your recursive function to print out the tree
    cursedLeaves(root);
    return 0;
}

void cursedLeaves(node* top)
{
  if (top->left != nullptr)
  {
    cursedLeaves(top->left);
  }
  cout << top->data << " ";
  if (top->right != nullptr)
  {
    cursedLeaves(top->right);
  }
}

void cursedTree(node* top, ifstream &fin)
{
  string word;
  string leaves;
  fin >> word;
  fin >> leaves;
  top->data = word;
  top->left = nullptr;
  top->right = nullptr;
  if (leaves == "L")
  {
    top->left = new node;
    cursedTree(top->left, fin);
  }
  if (leaves == "R")
  {
    top->right = new node;
    cursedTree(top->right, fin);
  }
  if (leaves == "LR")
  {
    top->left = new node;
    cursedTree(top->left, fin);
    top->right = new node;
    cursedTree(top->right, fin);
  }
}