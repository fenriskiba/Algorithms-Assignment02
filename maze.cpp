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
