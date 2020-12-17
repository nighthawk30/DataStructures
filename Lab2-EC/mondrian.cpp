/*
 * mondrian.cpp
 *
 * Author: Nathan Taylor
 *
 * Generate recursive pictures inspired by the art of Piet Mondrian.
 */

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <cmath>

#include "mondrian.h"

using namespace std;

void Mondrian::_paint_recursive(Picture &picture, int left, int top, int right, int bottom) {
    // base case 1 - in case we made a zero width or height rectangle
    if (bottom - top <= 0 || right - left <= 0)
    {
      return;
    }
    else if ((bottom - top) * (right - left) <= 5000)// base case 2 - rectangle is now "small enough"
    {
      // Fill with a color (or not) using _color_fill()
      _color_fill(picture, left, top, right, bottom);
    }
    else
    {
      if ((right - left) < (bottom - top))//horizontal
      {
        //choose a number between bottom and top
        int range = bottom - top;
        int linePosition = rand() % range + top;
        _draw_horizontal_line(picture, linePosition, left, right);
        _paint_recursive(picture, left, top, right, linePosition - 1);
        _paint_recursive(picture, left, linePosition + 1, right, bottom);
      }
      else//vertical
      {
        //choose a number between bottom and top
        int range = right - left;
        int linePosition = rand() % range + left;
        _draw_vertical_line(picture, linePosition, top, bottom);
        _paint_recursive(picture, left, top, linePosition - 1, bottom);
        _paint_recursive(picture, linePosition + 1, top, right, bottom);
      }
    }


    // otherwise, split the rectangle in two at random, and paint the
    // two rectangles recursively; make sure not to paint over the 
    // dividing lines!
}

void Mondrian::_color_fill(Picture &picture, int left, int top, int right, int bottom) {
    int r, g, b;

    // this just paints a random shade of blue
    float height = bottom - top;
    float width = right - left;
    float area = width * height;
    float perfection;
    //perfection = 9 * (1 - area / 5000);//scales area to color number
    perfection = 9.0 * (1.0 - min(width, height) / max(width, height));//scales squareness to color number

    //three phase colors based on sigmoid scaling for warmth to size relation
    //takes the color from 0-11 and uses sigmoid to find the right color
    //Red
    if (perfection > 6)
    {
      r = _sigmoid_scale(-1, -9, perfection);
    }
    else
    {
      r = _sigmoid_scale(1, -3, perfection);
    }
    //Blue
    if (perfection < 3)
    {
      b = _sigmoid_scale(1, 1, perfection);
    }
    else if (perfection < 8)
    {
      b = _sigmoid_scale(-1, -5, perfection);
    }
    else
    {
      b = _sigmoid_scale(1, -11, perfection);
    }
    //Green
    if (perfection < 4)
    {
      g = _sigmoid_scale(-1, -1, perfection);
    }
    else if (perfection < 10)
    {
      g = _sigmoid_scale(1, -7, perfection);
    }
    else
    {
      g = _sigmoid_scale(-1, -12, perfection);
    }

    for (int x = left; x <= right; x++) {
        for (int y = top; y <= bottom; y++) {
            picture.set(x, y, r, g, b);
        }
    }
}

int Mondrian::_sigmoid_scale(int sign, int shift, float sizeRange)
{
  int value = 255 / (1+exp(sign * 4 * (sizeRange + shift)));
  return value;
}

// These are done for you to save time in lab
void Mondrian::_draw_horizontal_line(Picture &picture, int y, int left, int right) {
    for (int x = left; x <= right; x++) {
        picture.set(x, y, 0, 0, 0);
    }
}

void Mondrian::_draw_vertical_line(Picture &picture, int x, int top, int bottom) {
    for (int y = top; y <= bottom; y++) {
        picture.set(x, y, 0, 0, 0);
    }
}

void Mondrian::paint(string output_filename, int width, int height) {
    // get a new random seed each time
    srand(time(nullptr));

    // create a white picture
    Picture picture(width, height, 255, 255, 255);

    // put a frame around it
    _draw_horizontal_line(picture, 0, 0, width - 1);
    _draw_horizontal_line(picture, height - 1, 0, width - 1);
    _draw_vertical_line(picture, 0, 0, height - 1);
    _draw_vertical_line(picture, width - 1, 0, height - 1);

    // invoke our computer artist!
    _paint_recursive(picture, 1, 1, width - 2, height - 2);

    // save result
    picture.save(output_filename);
}
