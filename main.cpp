#include "maze.h"
#include <iostream>

using namespace std;

void percolationRate(double, double, int);

int main(int argc, char *argv[])
{
    srand(time(0));
    
    if(argc == 2)
    {
        string fileName = argv[1];
        Maze mazeRunner(fileName);
        
        mazeRunner.hasPass();
        
        cout << "The number of clusters is: " << mazeRunner.numberOfClusters() << endl;
    }
    else if(argc == 4)
    {
        double percolationProbability = atof(argv[1]);
        double numberOfRuns = atof(argv[2]);
        int boardSize = atoi(argv[3]);
        
        percolationRate(percolationProbability, numberOfRuns, boardSize);
    }
    else
    {
        cout << "Invalid Input" << endl;
    }
    
    return 0;
}

void percolationRate(double percolationProbability, double numberOfRuns, int boardSize)
{   
    double successes = 0;
    
    for(int i = 0; i < numberOfRuns; i++)
    {
        Maze mazeRunner(boardSize);
        mazeRunner.randomizeMaze(percolationProbability);
        if(mazeRunner.hasPass())
        {
            successes += 1;
        }
    }
    
    double rate = successes / numberOfRuns;
    rate *= 100;
    cout << "The Percolation Rate is: " << rate << "%" << endl;
}

