#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

typedef struct
{
	size_t x;
	size_t y;
	size_t box_x;
	size_t box_y;
} digit;

bool isValidSudoku(vector<vector<char>>& board) {
	unordered_map<char, vector<digit>> digits{};
	for(size_t i{}; i < board.size()/3; ++i)
	{
		for(size_t j{}; j < board.at(i).size()/3; ++j)
		{
			for(size_t k{}; k < 3; ++k)
			{
				for(size_t l{}; l < 3; ++l)
				{
					size_t x{3 * j + l};
					size_t y{3 * i + k};
					if(board.at(y).at(x) == '.')
						continue;
					auto d{digits.find(board.at(y).at(x))};
					if(d != digits.end())
					{
						for(auto num : d->second)
						{
							if((num.x == x || num.y == y) || (num.box_x == j && num.box_y == i))
								return false;
						}
						digits.at(board.at(y).at(x)).push_back(digit{x, y, j, i});
					}
					else
					{
						digits.emplace(board.at(y).at(x), vector<digit>{digit{x, y, j, i}});
					}
				}
			}
		}
	}
	return true;
}

int main()
{
	//vector<vector<char>> board{
	//	{'.','.','4','.','.','.','6','3','.'},
	//	{'.','.','.','.','.','.','.','.','.'},
	//	{'5','.','.','.','.','.','.','9','.'},
	//	{'.','.','.','5','6','.','.','.','.'},
	//	{'4','.','3','.','.','.','.','.','1'},
	//	{'.','.','.','7','.','.','.','.','.'},
	//	{'.','.','.','5','.','.','.','.','.'},
	//	{'.','.','.','.','.','.','.','.','.'},
	//	{'.','.','.','.','.','.','.','.','.'}
	//};
	vector<vector<char>> board{
		{'.','.','.','.','5','.','.','1','.'},
		{'.','4','.','3','.','.','.','.','.'},
		{'.','.','.','.','.','3','.','.','1'},
		{'8','.','.','.','.','.','.','2','.'},
		{'.','.','2','.','7','.','.','.','.'},
		{'.','1','5','.','.','.','.','.','.'},
		{'.','.','.','.','.','2','.','.','.'},
		{'.','2','.','9','.','.','.','.','.'},
		{'.','.','4','.','.','.','.','.','.'}
	};
	bool result{isValidSudoku(board)};
	cout << "Result: " << result << endl;
}
