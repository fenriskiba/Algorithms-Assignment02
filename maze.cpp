#include "maze.h"

using namespace std;

Maze::Maze(int s)
{
    size = s * s;
    matrix = new int[size];
}
Maze::Maze(string fileName)
{
    char temp;
    string tempArray = "";
    ifstream infile;
    
    //Open the file
    infile.open(fileName.c_str(), ios_base::in);
    if(!infile)
    {
        cout << "cannot be opened" << endl;
    }
    
    //Collect the file into a string and close it
    while(infile >> temp)
    {
        tempArray += temp;
    }
    infile.close();
    
    //Convert the string to a new array
    size = tempArray.length();
    matrix = new int[size];
    for(int i = 0; i < size; i++)
    {
        matrix[i] = tempArray[i] - '0';
    }
}

void Maze::printMaze()
{
    int matrixSize = pow(size, 0.5);
    for(int i = 0; i < size; i++)
    {
        cout << matrix[i] << " ";
        if((i + 1) % matrixSize == 0)
        {
            cout << endl;
        }
    }
}

void Maze::randomizeMaze(double percolationProbability)
{
    srand(time(0));
    percolationProbability *= 100;
    
    for(int i = 0; i < size; i++)
    {
        int randomNumber = rand() % 100;
        if(randomNumber < percolationProbability)
        {
            matrix[i] = 1;
        }
        else
        {
            matrix[i] = 0;
        }
    }
}


