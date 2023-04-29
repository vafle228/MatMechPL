#include <queue>
#include <string>
#include <vector>
#include <iostream>

#define ChessField std::vector<std::vector<int>>


struct Point
{
	int x, y;

	Point(int x, int y) 
	{
		this->x = x;
		this->y = y;
	}

	Point() : Point(0, 0) {}

	Point AddPoint(Point other) 
	{
		return Point(x + other.x, y + other.y);
	}

	std::string ToSting() 
	{
		return "x: " + std::to_string(x) + ", y: " + std::to_string(y);
	}
};

bool IsPossibleMove(Point pos) 
{
	return (pos.x >= 0 && pos.x <= 7) && (pos.y >= 0 && pos.y <= 7);
}

std::vector<Point> GetPossibleMoves(Point pos) 
{
	std::vector<Point> offsets
	{
		{-1, -2}, {1, -2}, {2, -1}, {2, 1},
		{1, 2}, {-1, 2}, {-2, 1}, {-2, -1},
	};

	std::vector<Point> res;
	for (Point offset : offsets) 
	{
		Point next_move = pos.AddPoint(offset);
		if (IsPossibleMove(next_move)) res.push_back(next_move);
	}
	return res;
}

int main() 
{
	int x, y;
	
	std::cin >> x; std::cin >> y;
	Point start = Point(x, y);
	
	std::cin >> x; std::cin >> y;
	Point goal = Point(x, y);
	
	auto field = std::vector<std::vector<int>>(8, std::vector<int>(8, INT_MAX));
	auto ways = std::vector<std::vector<Point>>(8, std::vector<Point>(8, Point()));

	std::queue<Point> to_handle;
	to_handle.push(start); field[start.x][start.y] = 0;

	while (!to_handle.empty()) 
	{
		Point pos = to_handle.front();
		to_handle.pop();
		int cur_dist = field[pos.x][pos.y];

		for (Point move : GetPossibleMoves(pos)) 
		{
			if (field[move.x][move.y] > cur_dist + 1) 
			{
				field[move.x][move.y] = cur_dist + 1;
				to_handle.push(move); ways[move.x][move.y] = pos;
			}
		}
	}

	while (goal.x != start.x || goal.y != start.y) 
	{
		std::cout << goal.ToSting() << std::endl;
		goal = ways[goal.x][goal.y];
	}
	std::cout << goal.ToSting() << std::endl;
}
