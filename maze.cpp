#include "maze.h"

using namespace std;

Maze::Maze(int s)
{
    size = s;
    matrix = new bool*[size];
    
    for(int i = 0; i < size; i++)
    {
        matrix[i] = new bool[size];
    }
}

void Maze::printMaze()
{
    for(int i = 0; i < size; i++)
    {
        for(int x = 0; x < size; x++)
        {
            cout << matrix[i][x] << " ";
        }
        cout << endl;
    }
}

void Maze::randomizeMaze(double percolationProbability)
{
    srand(time(0));
    percolationProbability *= 100;
    
    for(int i = 0; i < size; i++)
    {
        for(int x = 0; x < size; x++)
        {
            int randomNumber = rand() % 100;
            if(randomNumber < percolationProbability)
            {
                matrix[i][x] = true;
            }
            else
            {
                matrix[i][x] = false;
            }
        }
    }
}

