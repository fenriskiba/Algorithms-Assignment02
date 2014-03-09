#ifndef BIGINT_H
#define	BIGINT_H

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cmath>

using namespace std;

class Maze
{
    private:
        int** matrix;
        int size;
    public:
        Maze(int);
        Maze(string);
        
        void printMaze();
        void randomizeMaze(double);
        //bool unionFind();
};

#endif
