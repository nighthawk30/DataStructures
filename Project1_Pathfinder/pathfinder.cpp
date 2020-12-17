/*
    pathfinder.cpp
        
    Method implementations for the pathfinder class.
    
    assignment: CSCI 262 Project - Project1_Pathfinder

    author: Nathan Taylor
    //I SEE THE 1 LINE FILE...
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include "pathfinder.h"

using namespace std;

// constructor - optional, in case you need to initialize anything
pathfinder::pathfinder()
{

}

// public run() method - invokes private methods to do everything;
// returns the total elevation change cost of the best optimal path.
int pathfinder::run(string data_file_name, string save_file_name, bool use_recursion)
{
    // suggested implementation - modify as desired!
    _use_recursion = use_recursion;
    if (!_read_data(data_file_name))
    {
        cout << "Error reading map data from \"" << data_file_name << "\"!" << endl;
        return -1;
    }

    _draw_map();

    int best_cost = _draw_paths();

    _save_image(save_file_name);

    return best_cost;
}

/*******************/
/* PRIVATE METHODS */
/*******************/

// _read_data - read and store width, height, and elevation data from the
// provided data file; return false if something goes wrong
bool pathfinder::_read_data(string data_file_name)
{
    // Open Input file
    ifstream inFile(data_file_name);
    // Read in Data
    string line = "";
    string test = "";
    int rows;
    int columns;
    int lineCounter = -2;//first 2 lines are text
    while (!inFile.eof())
    {
        getline(inFile, line);//get line
        istringstream inStream(line);//get line as a string
        if (lineCounter == -2)//first line has columns
        {
            inStream >> test;
            inStream >> columns;
        }
        else if (lineCounter == -1)//second line has rows
        {
            inStream >> test;
            inStream >> rows;
            _elevations = vector<vector<int>>(rows, vector<int>(columns));//initialize _elevations 2d vector
        }
        else
        {
            //if the line never stops, it will fill in the array
            for (int i = lineCounter; i < rows; i++)//start at the row you are on
            {
                for (int j = 0; j < columns; j++)//fill in the row
                {
                    inStream >> _elevations[i][j];
                    if (inStream.eof())//if the line ends, stop and use the main loop to get to the next row
                    {
                        break;
                    }
                }
                if (inStream.eof())
                {
                    break;
                }
            }
        }
        lineCounter++;
    }
    inFile.close();
    return true;
}

// _draw_map - draw the elevation data as grayscale values on our Picture
// object.
void pathfinder::_draw_map()
{
    // Min max elevations
    int rows = _elevations.size() - 1;
    int cols = _elevations[0].size();
    float min = -1;
    float max = -1;
    //search the 2d vector for the min and max values
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (max == -1 || _elevations[i][j] > max)
            {
                max = _elevations[i][j];
            }
            if (min == -1 || _elevations[i][j] < min)
            {
                min = _elevations[i][j];
            }
        }
    }

    //Scaling Factor to 0-255
    float shift = min;//shift all values down
    float scale = 255 / (max - min);//scale them to range
    _image.set(rows - 1, cols - 1, 0, 0, 0);//preallocate memory to image for faster writing
    //scale each value and put it into the image
    for (int i = 0; i < _elevations.size() - 1; i++)
    {
        //string scaled = "";
        for (int j = 0; j < _elevations[0].size(); j++)
        {
            int r, g, b;
            r = g = b = (_elevations[i][j] - shift) * scale;//set grayscale value
            //scaled += " " + to_string(r);
            _image.set(i, j, r, g, b);//set image point
        }
    }
}

// _draw_paths() - find and draw optimal paths from west to east using either recursion or dynamic programming
// return the best optimal path cost
int pathfinder::_draw_paths()
{
    int rows = _elevations.size();
    int columns = _elevations[0].size();
    if (_use_recursion)//recursion is selected
    {
        vector<vector<int>> elevationCost;
        elevationCost = vector<vector<int>>(rows, vector<int>(2));
        for (int i = 0; i < rows; i++)//send recursion starting at points on western(left) edge
        {
            elevationCost[i][0] = _elevations[i][0];//fill elevation and cost table
            elevationCost[i][1] = optCostToEast(i, 0, 0);
        }
        cout << endl;

        //find cheapest path
        int cheap = -1;
        for (int i = 0; i < rows; i++)
        {
            if (cheap == -1 || elevationCost[i][1] < cheap)
            {
                cheap = elevationCost[i][1];
            }
        }
        return cheap;
    }
    else//part 2:dynamic
    {
        //make cost table
        vector<vector<int>> elevationCost;
        elevationCost = vector<vector<int>>(rows, vector<int>(columns));
        vector<vector<int>> optDirection;
        optDirection = vector<vector<int>>(rows, vector<int>(columns));//1 - northe, 0 - east, -1 - southe
        //set east - 1 to the lower cost to move to east in each of the 4
        for (int j = columns - 1; j >= 0; j--)
        {
            cout << "Cost computation: " <<  100 * (columns - j - 1)/columns << "% Complete" << endl;
            for (int i = 0; i < rows; i++)
            {
                int costPath[2];
                westwardExpansion(i, j, costPath, elevationCost);
                elevationCost[i][j] = costPath[0];
                optDirection[i][j] = costPath[1];
            }
        }
        //draw the optimal paths
        int bestIndex = 0;
        vector<vector<bool>> goneGoneGone = vector<vector<bool>>(rows, vector<bool>(columns));
        for (int i = 0; i < rows; i++)
        {
            cout << "Path Drawing: " << 100 * i/rows << "% Complete" << endl;
            int rpos = i;//start at the start point
            //recurseBlue(i, 0, optDirection, goneGoneGone);//draw optimal paths in blue
            for (int j = 0; j < columns - 1; j++)
            {
                _image.set(rpos, j, 0, 0, 255);
                rpos -= optDirection[rpos][j];//adding vertical direction change to vertical position  - subtracting bc its weird
            }
            if (elevationCost[i][0] < elevationCost[bestIndex][0])//find cheapest path
            {
                bestIndex = i;
            }
        }
        //draw the best path in yellow
        recurseYellow(bestIndex, 0, optDirection);//it could be faster with loops but I dont care, it was easy to code
        return elevationCost[bestIndex][0];
    }
}

//keeping the original code bc I want to
void pathfinder::recurseBlue(int rpos, int cpos, vector<vector<int>> optDirection, vector<vector<bool>> goneGoneGone)
{
    if (!goneGoneGone[rpos][cpos])//dont overwrite paths that have previously been followed
    {
        goneGoneGone[rpos][cpos] = true;
        _image.set(rpos, cpos, 0, 0, 255);//set image point to blue
        if (cpos != _elevations[0].size() - 1)
        {
            recurseBlue(rpos - optDirection[rpos][cpos], cpos + 1, optDirection, goneGoneGone);
        }
    }
}

void pathfinder::recurseYellow(int rpos, int cpos, vector<vector<int>> optDirection)
{
    _image.set(rpos, cpos, 255, 255, 0);//set image point to yellow
    if (cpos != _elevations[0].size() - 1)
    {
        recurseYellow(rpos - optDirection[rpos][cpos], cpos + 1, optDirection);
    }
}

//find the lowest cost of travel to the east at each point in each column starting east and moving west
void pathfinder::westwardExpansion(int rpos, int cpos, int *costDirection, vector<vector<int>> elevationCost)
{
    costDirection[0] = -2;
    costDirection[1] = -2;
    if (cpos == _elevations[0].size() - 1)//you are at the eastern edge
    {
        costDirection[0] = 0;//path is 0
        costDirection[1] = 0;//direction is irrelevant
    }
    else
    {
        int path[3] = {-1, -1, -1};//east, northeast, southeast path distances
        //find the total cost of the path at the current point - elevation change for current step and lowest cost of prior paths
        path[1] = elevationChange(rpos, cpos, rpos, cpos + 1) + elevationCost[rpos][cpos + 1];//straight east
        if (rpos != 0)//not in top row - north
        {
            path[2] = elevationChange(rpos, cpos, rpos - 1, cpos + 1) + elevationCost[rpos - 1][cpos + 1];//check a row higher
        }
        if (rpos != _elevations.size() - 1)//not at bottom - south
        {
            path[0] = elevationChange(rpos, cpos, rpos + 1, cpos + 1) + elevationCost[rpos + 1][cpos + 1];//check row lower
        }
        for (int i = 0; i < 3; i++)//finds the lowest cost path
        {
            if (path[i] != -1)//the path exists
            {
                if (costDirection[0] == -2 || path[i] < costDirection[0])//the cheapest path
                {
                    costDirection[0] = path[i];
                    costDirection[1] = i - 1;//the cheapest direction
                }
            }
        }
    }
}

int pathfinder::optCostToEast(int rpos, int cpos, int cost)//recursion start
{
    int a, b, c;//three path cost possibilities
    if (cpos == _elevations[0].size() - 1)//end of image (right edge)
    {
        return cost;
    }
    else if (rpos == _elevations.size() - 1 && rpos == 0)//just in case - you can only move right
    {
        a = optCostToEast(rpos, cpos + 1, cost + elevationChange(rpos, cpos, rpos, cpos + 1));
        return a;
    }
    else if (rpos == 0)//southern edge (top of table)
    {
        //right & up
        a = optCostToEast(rpos, cpos + 1, cost + elevationChange(rpos, cpos, rpos, cpos + 1));
        b = optCostToEast(rpos + 1, cpos + 1, cost + elevationChange(rpos, cpos, rpos + 1, cpos + 1));
        return min(a, b);
    }
    else if (rpos == _elevations.size() - 1)//northern edge (bottom of table)
    {
        a = optCostToEast(rpos, cpos + 1, cost + elevationChange(rpos, cpos, rpos, cpos + 1));
        b = optCostToEast(rpos - 1, cpos + 1, cost + elevationChange(rpos, cpos, rpos - 1, cpos + 1));
        return min(a, b);
    }
    else//middle
    {
        a = optCostToEast(rpos, cpos + 1, cost + elevationChange(rpos, cpos, rpos, cpos + 1));
        b = optCostToEast(rpos + 1, cpos + 1, cost + elevationChange(rpos, cpos, rpos + 1, cpos + 1));
        c = optCostToEast(rpos - 1, cpos + 1, cost + elevationChange(rpos, cpos, rpos - 1, cpos + 1));
        return min(a, min(b, c));
    }
}

//elevation difference between 2 points
int pathfinder::elevationChange(int x1, int y1, int x2, int y2)
{
    return abs(_elevations[x1][y1] - _elevations[x2][y2]);
}

// _save_image - we'll do this one for you :)
void pathfinder::_save_image(string save_file_name) {
_image.save(save_file_name);
}

