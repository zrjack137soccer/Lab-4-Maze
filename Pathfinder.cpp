#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <array>

#include "Pathfinder.h"

using namespace std;


string Pathfinder::toString() const {
    
    stringstream ss;
	    for(int row = 0; row < ROW_SIZE; row++) {
	        for(int col = 0; col < COL_SIZE; col++) {
	        	for(int width = 0; width < WIDTH_SIZE; width++) {
	        		ss << maze_grid[row][col][width];
	        	}
	        }
	        ss << endl;
	    }
	    return ss.str();
}
void Pathfinder::createRandomMaze() {
    
    for(int row = 0; row < ROW_SIZE; row++) {
    	for(int col = 0; col < COL_SIZE; col++) {
    		for(int width = 0; width < WIDTH_SIZE; width++) {
    			maze_grid[row][col][width] = rand % 2;
    		}
    	}
    }
    maze_grid[4][4][4] = 1;
    maze_grid[0][0][0] = 1;
    
    return;
}
bool Pathfinder::importMaze(string file_name) {
	ifstream ifs;
	ifs.open(file_name.c_str());
    string line;
	int row_count = 0;
	for(int row = 0; row < ROW_SIZE; row++) {
		for(int col = 0; col < COL_SIZE; col++) {
			getline(ifs, line);
			stringstream ss(line);
			for(int width = 0; width < WIDTH_SIZE; width++) {
				int value;
				ss >> value;
				cout << "[" << row << "][" << col << "][" << width << "]=" << value << endl;
				maze_grid[row][col][width] = value;
			}
		}
	}
	ifs.close();
    return true;
}
vector <string> Pathfinder::solveMaze() {
    bool findPath(int x, int y, int z) {
    	solution.push_back()
    }
    
    
    
    return solution;
}