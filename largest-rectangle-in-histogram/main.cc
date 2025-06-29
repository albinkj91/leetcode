#include <iostream>
#include <vector>
using namespace std;

int largestRectangleArea(vector<int>& heights) {
    int min{heights.at(0)};
    int largest_area1{heights.at(0)};
    int reserve{0};
    int rect_count{1};

    for(size_t i{1}; i < heights.size(); ++i)
    {
        if(heights.at(i) >= min)
        {
            if((largest_area1 + min) <= heights.at(i))
            {
                largest_area1 = heights.at(i);
                min = heights.at(i);
                rect_count = 1;
            }
            else
            {
                largest_area1 += min;
                ++rect_count;
            }
        }
        else if(largest_area1 <= ((rect_count + 1) * heights.at(i)))
        {
            ++rect_count;
            largest_area1 = (rect_count) * heights.at(i);
            min = heights.at(i);
        }
        else
        {
            min = heights.at(i);
            rect_count = 1;
            if(largest_area1 > reserve)
                reserve = largest_area1;
            largest_area1 = 0;
        }
    }
    if(reserve > largest_area1)
        largest_area1 = reserve;

    if(heights.size() < 2)
        return heights.at(0);
    min = heights.at(heights.size() - 1);
    int largest_area2{heights.at(heights.size() - 1)};
    rect_count = 1;
    reserve = 0;

    for(size_t i{heights.size()-2}; i > 0; --i)
    {
        if(heights.at(i) >= min)
        {
            if((largest_area2 + min) <= heights.at(i))
            {
                largest_area2 = heights.at(i);
                min = heights.at(i);
                rect_count = 1;
            }
            else
            {
                largest_area2 += min;
                ++rect_count;
            }
        }
        else if(largest_area2 <= ((rect_count + 1) * heights.at(i)))
        {
            ++rect_count;
            largest_area2 = (rect_count) * heights.at(i);
            min = heights.at(i);
        }
        else
        {
            min = heights.at(i);
            rect_count = 1;
            if(largest_area2 > reserve)
                reserve = largest_area2;
            largest_area2 = 0;
        }
    }
    if(reserve > largest_area2)
        largest_area2 = reserve;
    return largest_area1 >= largest_area2 ? largest_area1 : largest_area2;
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
