#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

typedef struct
{
    int pos;
    int speed;
}car;

int carFleet(int target, vector<int>& position, vector<int>& speed) {
    vector<car> cars{};
    for(size_t i{}; i < position.size(); ++i)
    {
        cars.push_back(car{position.at(i), speed.at(i)});
    }
    sort(cars.begin(), cars.end(),
            [](car const& c1, car const& c2)
            {
                return c1.pos > c2.pos;
            });

    int fleets{1};
    double current_fleet_time{(target - cars.at(0).pos) / static_cast<double>(cars.at(0).speed)};
    for(size_t i{1}; i < cars.size(); ++i)
    {
        double time = (target - cars.at(i).pos) / static_cast<double>(cars.at(i).speed);
        if(time > current_fleet_time)
        {
            ++fleets;
            current_fleet_time = time;
        }
    }
	return fleets;
}

int main()
{
	int target{12};
	vector<int> position{10,8,0,5,3}; // sorted descending: 10, 8, 5, 3, 0
	vector<int> speed{2,4,1,1,3};
	int result{carFleet(target, position, speed)};
    cout << result << endl;

	int target2{100};
	vector<int> position2{0,2,4};
	vector<int> speed2{4,2,1};
	int result2{carFleet(target2, position2, speed2)};
    cout << result2 << endl;

	int target3{10};
	vector<int> position3{3};
	vector<int> speed3{3};
	int result3{carFleet(target3, position3, speed3)};
    cout << result3 << endl;

	int target4{10};
	vector<int> position4{6,8};
	vector<int> speed4{3,2};
	int result4{carFleet(target4, position4, speed4)};
    cout << result4 << endl;
}
