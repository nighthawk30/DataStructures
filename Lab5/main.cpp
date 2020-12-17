/* Nathan Taylor
 * 10/3/20
 * Ancient Algorithms
 */

#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>

using namespace std;

void archimedesPi();
void sqrtBabylon();

int main()
{
    string input = "";
    cout << "PI(p) or Sqrt(s): ";
    getline(cin, input);
    cout << endl;
    if (input == "p")
    {
        archimedesPi();
    }
    else
    {
        sqrtBabylon();
    }
    return 0;
}

void sqrtBabylon()
{
    string ip = "";
    cout << "Number:";
    getline(cin, ip);
    int value = stoi(ip);
    cout << "Square Root Guess:";
    getline(cin, ip);
    long double betterGuess = stoi(ip);
    long double alterGuess = 0;
    long double oldGuess = 100;
    int precision = 20;
    //
    while (abs(betterGuess-oldGuess) > pow(10,-precision))
    {
        oldGuess = betterGuess;
        alterGuess = value/betterGuess;
        betterGuess = (alterGuess + betterGuess)/2;
    }
    cout << setprecision(1500) << betterGuess << endl;
}

void archimedesPi()
{
    int precision = 20;
    long double radius = 1;//C=2r*pi -> pi = C/2r
    long double sides = 6;
    long double sideLen = 1;//hypotenuse of new little triangle
    long double apothem = sqrt(pow(radius, 2) - pow((sideLen/2), 2));//find the apothem
    long double pie = 0;
    long double pieOld = 100;
    long double a, b;

    while (abs(pie-pieOld) >= pow(10,-precision))
    {
        pieOld = pie;
        sides *= 2;//double number of sides on polygon
        a = radius - apothem;//find length of new addition
        b = sideLen / 2;//find leg of new addition
        sideLen = sqrt(pow(a,2) + pow(b,2));//find new side length
        apothem = sqrt(pow(radius, 2) - pow((sideLen/2),2));//find new apothem
        pie = sides * sideLen / 2;
        cout << setprecision(1500) << pie << endl;
    }
}