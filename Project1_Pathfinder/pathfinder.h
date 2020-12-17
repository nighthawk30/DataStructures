#ifndef _PATHFINDER_H
#define _PATHFINDER_H

/*
    pathfinder.h
        
    class definition for the pathfinder class.

    assignment: CSCI 262 Project - Project1_Pathfinder

    author: Nathan
*/

#include <string>
#include <vector>

#include "picture.h"

using namespace std;

/******************************************************************************
   class pathfinder

   Given access to a source of topographical data (a file specifying width and
   height and listing elevation data for the resulting grid), a pathfinder
   object can:
     - read in the data
     - create an image showing the data as a grayscale image, with gray level 
       representing relative elevation
     - compute and overlay the optimal path from all western starting points
     - compute and overlay the single best optimal path from west to east
     - save the image data

******************************************************************************/

class pathfinder {
public:
    // constructor - optional, in case you need to initialize anything
    pathfinder();

    // our only public method: do everything and return the best path cost
    int run(string data_file_name, string save_file_name, bool use_recursion);

private:
    int _height, _width;                     // height and width of map
    bool _use_recursion;
    vector<vector<int>> _elevations;         // raw data from file
    Picture _image;                          // image to save at the end

    bool _read_data(string data_file_name);  // read in raw data
    void _draw_map();                        // draw the grayscale elevation map
    int _draw_paths();                       // find optimal paths, returning the most optimal cost
    void _save_image(string save_file_name); // save the image as a .png file
    int optCostToEast(int rpos, int cpos, int cost);//recursion function
    void westwardExpansion(int rpos, int cpos, int *costDirection, vector<vector<int>> elevationCost);
    int elevationChange(int x1, int y1, int x2, int y2);//change in elevation between 2 points
    void recurseBlue(int rpos, int cpos, vector<vector<int>> optDirection, vector<vector<bool>> goneGoneGone);//not in use
    void recurseYellow(int rpos, int cpos, vector<vector<int>> optDirection);
};

#endif
