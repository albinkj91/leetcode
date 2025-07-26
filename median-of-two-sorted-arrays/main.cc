#include <iostream>
#include <iomanip>
#include <vector>
#include <limits>
#include <algorithm>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    vector<int>& A = nums1;
    vector<int>& B = nums2;
    int total = A.size() + B.size();
    int half = (total + 1) / 2;

    if (B.size() < A.size()) {
        A = B;
    }

    int l = 0;
    int r = A.size();
    while (l <= r) {
        int i = (l + r) / 2;
        int j = half - i;

        int Aleft = i > 0 ? A.at(i - 1) : numeric_limits<int>::min();
        int Aright = i < A.size() ? A.at(i) : numeric_limits<int>::max();
        int Bleft = j > 0 ? B.at(j - 1) : numeric_limits<int>::min();
        int Bright = j < B.size() ? B.at(j) : numeric_limits<int>::max();

        if (Aleft <= Bright && Bleft <= Aright) {
            if (total % 2 != 0) {
                return max(Aleft, Bleft);
            }
            return (max(Aleft, Bleft) + min(Aright, Bright)) / 2.0;
        } else if (Aleft > Bright) {
            r = i - 1;
        } else {
            l = i + 1;
        }
    }
    return -1;
}

int main()
{
    vector<int> nums1{};
    vector<int> nums2{1};
    double res{findMedianSortedArrays(nums1, nums2)};
    cout << "Result: " << res << endl;
}
