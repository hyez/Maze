#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <queue>
#include <functional>
#include "maze.h"
using namespace std;

// 우선순위 큐
AStarMaze::AStarMaze() : BreadthFirst::BreadthFirst() {
	queue.push({ maze, x, y, 0 }); // 시작점을 큐에 넣음
}

void AStarMaze::drawMaze(int dx, int dy, item maze_tmp) {
	int h = getH(dx, dy);
	int g = maze_tmp.g + 10;

	vector<vector<string>> maze_ineer_tmp = maze_tmp.maze;
	visited[dx][dy] = 1;
	maze_ineer_tmp[dx][dy] = "*";
	queue.push({ maze_ineer_tmp ,dx,dy, g + h, g, h });
}

int AStarMaze::getH(int x, int y) {
	// 목적지 : 11,1이라고 가정
	return abs(11 - x) * 10 + abs(1 - y) * 10;
}

item AStarMaze::top() {
	return queue.top();
}

void AStarMaze::pop() {
	queue.pop();
}

