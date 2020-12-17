/*
	animal.cpp

	author: Nathan Taylor
	date:

	Animal/20 questions program for CSCI 262, starter code.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <queue>

using namespace std;

class node
{
public:
    string data;
    node* left;
    node* right;
};

void play_game(node* top, node* root, queue<char> &inputs);
node* read_game_tree();
void write_game_tree(node*);
void delete_game_tree(node*);
node* read_preorder(ifstream &inFile, node* top);
void extend_tree(node* top, queue<char> inputs);
void writeTree(node* root, ofstream &outFile);

/**
 * Handles showing the main menu/basic UI
 */
int main()
{
	node* root = read_game_tree();
	if (root == NULL) return -1;

	while (true)
        {
		string tmp;
		int choice;
                cout << endl;
		cout << "Welcome to 20 questions!" << endl;
		cout << "  1) Play the game" << endl;
		cout << "  2) Save the game file" << endl;
		cout << "  3) Quit" << endl;
		cout << "Please make your selection: ";
		getline(cin, tmp);
		choice = atoi(tmp.c_str());
                queue<char> inputs;
		switch (choice)
                {
                case 1:
                  play_game(root, root, inputs);
                  break;
    		case 2:
                  write_game_tree(root);
                  break;
    		case 3:
                  break;
    		default:
                  cout << "Sorry, I don't understand." << endl << endl;
		}
		if (choice == 3) break;
	}

	delete_game_tree(root);
	return 0;
}

/**
 * Sets up the recursive call to the read_preorder
 * @return root of the tree
 */
node* read_game_tree()
{
  ifstream inFile("animal_game_tree.txt");
  string line = "";
  node* top = nullptr;
  top = read_preorder(inFile, top);
  inFile.close();
  return top;
}

node* read_preorder(ifstream &inFile, node* top)
{
  //not eof
  if (inFile.eof()) return nullptr;
  string line;
  getline(inFile, line);//getline
  top = new node();
  top->data = line;
  if (line[1] == 'A')//check if a A, then set leaves to nullptr
  {
    top->left = nullptr;
    top->right = nullptr;
  }
  else//check if Q, then recursively repeat
  {
    top->left = read_preorder(inFile, top->left);
    top->right = read_preorder(inFile, top->right);
  }
  return top;
}

/**
 * Plays the game
 * @param root Root of the game tree
 */
void play_game(node* top, node* root, queue<char> &inputs)
{
  if (root != nullptr)
  {
    cout << root->data.substr(3) << " (y/n): ";
    string input;
    getline(cin, input);
    inputs.emplace(input[0]);
    if (root->left == nullptr && root->right == nullptr)//leaf
    {
      if (input[0] == 'y')
      {
        cout << endl << "I win" << endl;
      }
      else
      {
        cout << "I am out of questions. I lose." << endl;
        cout << "Do you want to expand the game tree? (y/n): ";
        getline(cin, input);
        if (input[0] == 'y')
        {
          extend_tree(top, inputs);
        }
      }
    }
    else//Question
    {
      if (input[0] == 'y')//left
      {
        play_game(top, root->left, inputs);
      }
      else//right
      {
        play_game(top, root->right, inputs);
      }
    }
  }
}

void extend_tree(node* top, queue<char> inputs)
{
  cout << endl << "I asked:" << endl;
  while(top->left != nullptr && top->right != nullptr)
  {
    if (inputs.front() == 'y')
    {
      cout << top->data << " YES" << endl;
      top = top->left;
    }
    else
    {
      cout << top->data << " NO" << endl;
      top = top->right;
    }
    inputs.pop();
  }
  string animal;
  cout << "Enter a new animal: ";
  getline(cin, animal);
  string query;
  cout << "Enter a new question: ";
  getline(cin, query);
  string ans = top->data;
  top->data = "#Q " + query;

  node* ans1 = new node();
  node* ans2 = new node();
  ans1->data = "#A " + animal;
  ans1->left = nullptr;
  ans1->right = nullptr;
  ans2->data = ans;
  ans2->right = nullptr;
  ans2->left = nullptr;

  top->left = ans1;
  top->right = ans2;
}

/**
 * Writes the game tree, sets up a recursive call to write_preorder();
 * @param root The root of the tree
 */
void write_game_tree(node* root)
{
  ofstream outFile("animal_game_tree.txt");
  writeTree(root, outFile);
  outFile.close();
}

void writeTree(node* root, ofstream &outFile)
{
  //do preorder stuff
  if (root != nullptr)
  {
    outFile << root->data << endl;
    writeTree(root->left, outFile);
    writeTree(root->right, outFile);
  }
}

/**
 * Deletes the game tree
 * @param root Root of the game tree
 */
void delete_game_tree(node* root)//its good practice - post order ofc
{
  if (root != nullptr)
  {
    delete_game_tree(root->left);
    delete_game_tree(root->right);
    delete root;
  }
}
