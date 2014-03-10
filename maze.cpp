#include "maze.h"

using namespace std;

Maze::Maze(int s)
{
    size = s * s;
    matrix = new int[size];
    
    parentMatrix = new int[size];
    for(int i = 0; i < size; i++)
    {
        parentMatrix[i] = -1;
    }
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
    
    parentMatrix = new int[size];
    for(int i = 0; i < size; i++)
    {
        parentMatrix[i] = -1;
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

bool Maze::hasPass()
{
    int matrixSize = pow(size, 0.5);
    
    combineWithParent();

    int start = size - matrixSize;
    for(int i = start; i < size; i++)
    {
        if(parentMatrix[i] < matrixSize && parentMatrix[i] != -1)
        {
            return true;
        }
    }
    
    return false;
}

void Maze::combineWithParent()
{
    int matrixSize = pow(size, 0.5);
    
    for(int i = 0; i < size; i++)
    {
        //Right
        if(matrix[i] == 1 && matrix[i + 1] == 1)
        {
            if(((i + 1) % matrixSize) != 0)
            {
                unionElements(i, i + 1);
            }
        }
        
        //Left
        if(i != 0 && (i % matrixSize) != 0)
        {
            if(matrix[i] == 1 && matrix[i - 1] == 1)
            {
                unionElements(i - 1, i);
            }
        }
        
        //Up
        if(i > (matrixSize - 1))
        {
            if(matrix[i] == 1 && matrix[i - matrixSize] == 1)
            {
                unionElements(i - matrixSize, i);
            }
        }
        
        //Down
        if(i < size - matrixSize)
        {
            if(matrix[i] == 1 && matrix[i + matrixSize] == 1)
            {
                unionElements(i, i + matrixSize);
            }
        }
    }

}

void Maze::unionElements(int one, int two)
{
    int root1 = findRoot(one);
    int root2 = findRoot(two);

    if (root1 != root2)
    {
        if(root2 > root1)
        {
            parentMatrix[root2] = root1;
        }
        else
        {
            parentMatrix[root1] = root2;
        }
    }
}

int Maze::findRoot(int index)
{
    while(parentMatrix[index] != -1)
    {
        index = parentMatrix[index];
    }

    return index;
}

