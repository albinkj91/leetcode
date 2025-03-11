#include <iostream>
#include <vector>
using namespace std;

typedef struct
{
	int val;
	int min;
}Node;

class MinStack {
public:
	MinStack()
	{ }

	void push(int val)
	{
		if(stack.empty())
			stack.push_back(Node{val, val});
		else if(val < stack.back().min)
			stack.push_back(Node{val, val});
		else
			stack.push_back(Node{val, stack.back().min});
	}

	void pop()
	{
		stack.pop_back();
	}

	int top()
	{
		return stack.back().val;
	}

	int getMin()
	{
		return stack.back().min;
	}

private:
	vector<Node> stack{};
};

int main()
{
	MinStack* obj = new MinStack();
	obj->push(3);
	obj->push(5);
	obj->pop();
	int param_3 = obj->top();
	int param_4 = obj->getMin();
	cout << "top: " << param_3 << '\n';
	cout << "min: " << param_4 << endl;
}
