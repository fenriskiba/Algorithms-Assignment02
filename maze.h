#ifndef BIGINT_H
#define	BIGINT_H

#include <iostream>

using namespace std;

class Maze
{
    private:
        bool** matrix;
        int size;
    public:
        Maze(int);
        //Maze(string);
        
        void printMaze();
};

#endif
