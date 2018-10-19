#pragma once
#include <iostream>
#include <string>
#include <array>
#include <iomanip>
#include <vector>
#include "PathfinderInterface.h"

using namespace std;

const int ROW_SIZE = 5;
const int COL_SIZE = 5;
const int WIDTH_SIZE = 5;
const int BACKGROUND = 1;
const int WALL = 0;
const int TEMPORARY = 2;
const int PATH = 3;

class Pathfinder:public PathfinderInterface {
    
public:
    Pathfinder() {
      srand(time(NULL));
    };
    virtual ~Pathfinder() {};
    
    string toString() const;
    void createRandomMaze();
    bool importMaze(string file_name);
    vector <string> solveMaze();
    bool findPath(int x, int y, int z);
    
protected:
  
  int maze_grid[ROW_SIZE][COL_SIZE][WIDTH_SIZE];
  vector<string> solution;
};
