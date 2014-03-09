#include "maze.h"

using namespace std;

Maze::Maze(int s)
{
    size = s;
    matrix = new int*[size];
    
    for(int i = 0; i < size; i++)
    {
        matrix[i] = new int[size];
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
        cout << "cannot be opened"<<endl;
    }
    
    //Collect the file into a string and close it
    while(infile >> temp)
    {
        tempArray += temp;
    }
    infile.close();
    
    //Convert the string to a new array
    size = pow(tempArray.length(),0.5);
    
    //Generate the new array
    matrix = new int*[size];
    
    for(int i = 0; i < size; i++)
    {
        matrix[i] = new int[size];
    }
    
    //Move the string value over to the array
    int stringCount = 0;
    for(int i = 0; i < size; i++)
    {
        for(int x = 0; x < size; x++)
        {
            matrix[i][x] = tempArray[stringCount] - '0';
            stringCount++;
        }
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
                matrix[i][x] = 1;
            }
            else
            {
                matrix[i][x] = 0;
            }
        }
    }
}


