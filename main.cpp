#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <queue>
#include <functional>
#include "maze.h"
using namespace std;
int main() {
	int n;
	cout << "RightHandMaze 1, BreadthFirst 2, AStarMaze 3 : ";
	cin >> n;
	Maze *m;

	if (n == 1)
		m = new RightHandMaze();
	else if (n == 2)
		m = new BreadthFirst();
	else if (n == 3)
		m = new AStarMaze();
	else
		return 0;
	
	//Maze *m = new RightHandMaze();
	//Maze *m = new BreadthFirst();
	//Maze *m = new AStarMaze();
	

	m->print();
	while(true) {
		if (m->find()) {
			break;
		}
	}
	m->print();
	delete m;
	return 0;
}