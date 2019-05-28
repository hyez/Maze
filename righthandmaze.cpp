#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <queue>
#include <functional>
#include "maze.h"
using namespace std;


RightHandMaze::RightHandMaze() : Maze::Maze() {
	maze[x][y] = "*";
	direction = 4;
}
int RightHandMaze::find() {
	string top, bottom, left, right;

	cout << x << ", " << y << ": ";
	if (isDone()) {
		maze[x][y] = "*";
		cout << endl;
		return 1;
	}

	if(x - 1 >= 0) top = maze[x - 1][y];
	if(x + 1 < row) bottom = maze[x + 1][y];
	if(y - 1 >= 0) left = maze[x][y - 1];
	if(y + 1 < col) right = maze[x][y + 1];

	if (x - 1 >= 0 && direction == 1) {
		// 위쪽
		if (top == "#" && right == "#") {
			direction = 3;
		}
		else if (x + 1 < row && y + 1 < col && maze[x + 1][y + 1] == "#" && right == ".") {
			direction = 4;
		}
		else if (top == "." || top == "*") {
			x = x - 1;
			maze[x][y] = "*";
		}
		else if (x + 1 < row && y + 1 < col && maze[x + 1][y + 1] == "#" && right == "*") {
			direction = 4;
		}
	}
	else if (x < row && direction == 2) {
		// 아래쪽
		if (left == "#" && bottom == "#") {
			direction = 4;
		}
		else if (x - 1 >= 0 && y - 1 >= 0 && maze[x-1][y-1] == "#" && left == ".") {
			direction = 3;
		}
		else if (bottom == "." || bottom == "*") {
			x = x + 1;
			maze[x][y] = "*";
		}
		else if (x - 1 >= 0 && y - 1 >= 0 && maze[x - 1][y - 1] == "#" && left == "*") {

		}
	}
	else if (y - 1 >= 0 && direction == 3) {
		// 왼쪽
		if (top == "#" && left == "#") {
			direction = 2;
		}
		else if (x - 1 >= 0 && y + 1< col && maze[x-1][y+1] == "#" && (top == "." )) {
			direction = 1;
		}
		else if (left == "." || left == "*") {
			y = y - 1;
			maze[x][y] = "*";
		}
		else if (x - 1 >= 0 && y + 1< col && maze[x - 1][y + 1] == "#" && (top == "*")) {
			direction = 1;
		}
	}
	else if (y + 1 < col && direction == 4) {
		// 오른쪽
		if (right == "#" & bottom == "#") {
			direction = 1;
		}
		else if (x + 1 < row && y - 1 >= 0 && maze[x + 1][y - 1] == "#" && (bottom == ".")) {
			direction = 2;
		}
		else if (right == "." || right == "*") {
			y = y + 1;
			maze[x][y] = "*";
		}
		else if (x + 1 < row && y - 1 >= 0 && maze[x + 1][y - 1] == "#" && (bottom == "*")) {
			direction = 2;
		}
	}
	
	cout << direction << endl;
	
	return 0;
}