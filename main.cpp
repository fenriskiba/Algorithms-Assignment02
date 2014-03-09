#include "maze.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    
    if(argc == 2)
    {
        cout << "Part 2" << endl;
    }
    else if(argc == 4)
    {
        double percolationProbability = atof(argv[1]);
        int numberOfRuns = atoi(argv[2]);
        int boardSize = atoi(argv[3]);
        
        Maze mazeRunner(boardSize);
        mazeRunner.randomizeMaze(percolationProbability);
        mazeRunner.printMaze();
    }
    else
    {
        cout << "Invalid Input" << endl;
    }
    
    return 0;
}


