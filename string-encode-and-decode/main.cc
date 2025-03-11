#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>
#include <algorithm>

using namespace std;

string encode(vector<string>& strs)
{
	string str{};
	for_each(strs.begin(), strs.end(),
			[&str](string& s)
			{
				str += s + '@';
			});
	return str;
}

vector<string> decode(string s)
{
	vector<string> strs{};
	size_t separator{};
	while(separator != s.npos && s != "")
	{
		separator = s.find("@");
		string temp{s.substr(0, separator)};
		strs.push_back(temp);
		s = s.substr(separator+1);
	}
	return strs;
}

int main()
{
	vector<string> strs{"neet", "code", "love", "you"};
	string str{encode(strs)};
	cout << "Encoded string: " << str << endl;

	vector<string> output{decode(str)};
	copy(output.begin(), output.end(),
			ostream_iterator<string>{cout, " "});
	cout << endl;
}
