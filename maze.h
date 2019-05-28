#pragma once
struct item {
	std::vector<std::vector<std::string>> maze;
	int x, y;
	int f, g, h;
};
struct cmp {
	bool operator()(item t, item u) {
		return t.f > u.f;
	}
};


class Maze {
protected:
	std::vector<std::vector<std::string>> maze;
	int row, col;
	int x, y;
	int isDone();
public:
	Maze();
	void load(std::string file);
	void print();
	virtual int find() = 0;
};

class RightHandMaze : public Maze {
private:
	int direction;
public:
	RightHandMaze();
	int find();
};     

class BreadthFirst : public Maze {
private:
	void init();
	std::queue<item> queue;
protected:
	std::vector<std::vector<int>> visited;
	void save(std::vector<std::vector<std::string>> &n);
	virtual void drawMaze(int dx, int dy, item maze_tmp);
	virtual item top();
	virtual void pop();
public:
	BreadthFirst();
	int find();
};

class AStarMaze : public BreadthFirst {
private:
	std::priority_queue<item, std::vector<item>, cmp > queue;
protected:
	void drawMaze(int dx, int dy, item maze_tmp);
	item top();
	void pop();
	int getH(int x, int y);
public:
	AStarMaze();
};