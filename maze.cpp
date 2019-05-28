#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <queue>
#include <functional>
#include "maze.h"
using namespace std;

Maze::Maze() {
	load("maze2.txt");
}
void Maze::load(string file) {
	string line;
	vector<string> tmp;
	ifstream myfile(file);
	if (myfile.is_open()) {
		string s;
		while (myfile >> s) {
			tmp.push_back(s);
		}
		myfile.close();
	}
	row = stof(tmp[0]);
	col = stof(tmp[1]); 
	x = stof(tmp[2]);
	y = stof(tmp[3]);

	for (int i = 0; i < 12; i++) {
		vector<string> tmp2;
		for (int j = 0; j < 12; j++) {
			int txtIndex = 4 + (i * col + j);
			tmp2.push_back(tmp[txtIndex]);
		}
		maze.push_back(tmp2);
	}

}


void Maze::print() {
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 12; j++) {
			cout << maze[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

int Maze::isDone() {
	return x >= row - 1 || y >= col - 1;
}