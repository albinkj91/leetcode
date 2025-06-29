#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int largestRectangleArea(vector<int>& heights) {
    stack<int> s{};
    int max_area{};

    for(size_t i{}; i <= heights.size(); ++i)
    {
        while(!s.empty() && (i == heights.size() || heights.at(s.top()) >= heights.at(i)))
        {
            int height = heights.at(s.top());
            s.pop();
            int width = s.empty() ? i : i - s.top() - 1;
            max_area = max(max_area, height * width);
        }
        s.push(i);
    }
    return max_area;
}

int main()
{
    vector<int> heights{2,1,5,6,2,3};
    int result{largestRectangleArea(heights)};
    cout << result << endl;

    vector<int> heights2{2,4};
    int result2{largestRectangleArea(heights2)};
    cout << result2 << endl;

    vector<int> heights3{2,0,2};
    int result3{largestRectangleArea(heights3)};
    cout << result3 << endl;

    vector<int> heights4{2,1,2};
    int result4{largestRectangleArea(heights4)};
    cout << result4 << endl;

    vector<int> heights5{1,2,2};
    int result5{largestRectangleArea(heights5)};
    cout << result5 << endl;

    vector<int> heights6{1,2,3,4,5};
    int result6{largestRectangleArea(heights6)};
    cout << result6 << endl;

    vector<int> heights7{0};
    int result7{largestRectangleArea(heights7)};
    cout << result7 << endl;

    vector<int> heights8{2,1,4,5,1,3,3};
    int result8{largestRectangleArea(heights8)};
    cout << result8 << endl;

    vector<int> heights9{4,2,0,3,2,5};
    int result9{largestRectangleArea(heights9)};
    cout << result9 << endl;

    vector<int> heights10{2,0,1,0,1,0};
    int result10{largestRectangleArea(heights10)};
    cout << result10 << endl;
}
