#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <limits>
#include <array>

#include "Pathfinder.h"

using namespace std;


string Pathfinder::toString() const {
    
    stringstream ss;
	    for(int width = 0; width < WIDTH_SIZE; width++) {
	        for(int row = 0; row < ROW_SIZE; row++) {
	        	for(int col = 0; col < COL_SIZE; col++) {
	        		if (col == COL_SIZE - 1) {
	        			ss << maze_grid[row][col][width];
	        		}
	        		else {
	        		ss << maze_grid[row][col][width] << " ";
	        		}
	        	}
	        	ss << '\n';
	        }
	        ss << '\n';
	    }
	    return ss.str();
}
void Pathfinder::createRandomMaze() {
    
    for(int row = 0; row < ROW_SIZE; row++) {
    	for(int col = 0; col < COL_SIZE; col++) {
    		for(int width = 0; width < WIDTH_SIZE; width++) {
    			maze_grid[row][col][width] = rand() % 2;
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
	for(int width = 0; width < WIDTH_SIZE; width++) {
		for(int row = 0; row < ROW_SIZE; row++) {
			getline(ifs, line);
			stringstream ss(line);
			for(int col = 0; col < COL_SIZE; col++) {
				int value;
				ss >> value;
				cout << value;
				maze_grid[row][col][width] = value;
			}
			cout << endl;
		}
		cout << endl;
		getline(ifs, line);
		stringstream ss(line);
	}
	ifs.close();
    return(true);
}
vector <string> Pathfinder::solveMaze() {
    
    findPath(0,0,0);
    
    return solution;
}

bool Pathfinder::findPath(int x, int y, int z) {
	maze_grid[x][y][z] = BACKGROUND;
    	
    solution.push_back("("+to_string(x)+","+to_string(y)+","+to_string(z)+")");
    if(x >= ROW_SIZE || y >= COL_SIZE || z >= WIDTH_SIZE || x == 0 || y == 0 || z == 0) {
    	solution.pop_back();
    	return false;
    }
    else if(maze_grid[x][y][z] != BACKGROUND) {
    	solution.pop_back();
    	return false; //Currently on an invalid path or path already visited.
    }
    else if(x == ROW_SIZE && y == COL_SIZE && z == WIDTH_SIZE) {
    	maze_grid[x][y][z] = PATH;
    	solution.push_back("("+to_string(x)+","+to_string(y)+","+to_string(z)+")");
    }
    else {
    	maze_grid[x][y][z] = PATH;
    	if(findPath(x - 1,y,z)|| //Up
    	findPath(x + 1,y,z)|| //Down
    	findPath(x,y - 1,z)|| //Left
    	findPath(x,y + 1,z)|| //Right
    	findPath(x,y,z - 1)|| //In
    	findPath(x,y,z + 1)) { //Out
    	solution.push_back("("+to_string(x)+","+to_string(y)+","+to_string(z)+")");
    	return true;
    	}
    	else {
    		maze_grid[x][y][z] = TEMPORARY; //Dead End
    		return false;
    	}
    }
}