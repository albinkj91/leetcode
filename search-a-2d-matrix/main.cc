#include <iostream>
#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target)
{
    int m{static_cast<int>(matrix.size())};
    int n{static_cast<int>(matrix.at(0).size())};
    int len{n*m};

    int l{};
    int r{len-1};
    int mid{r/2};

    while(l <= r)
    {
        int col{mid % n};
        int row{mid / n};

        if(matrix.at(row).at(col) < target)
            l = mid + 1;
        else if(matrix.at(row).at(col) > target)
            r = mid - 1;
        else
            return true;

        mid = (l + r) / 2;
    }
    return false;
}

int main()
{
    vector<vector<int>> matrix{{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int target{13};
    bool res{searchMatrix(matrix, target)};
    cout << res << endl;
}
