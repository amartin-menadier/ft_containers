#include "stack.hpp"
#include "containers.hpp"
#include <stack>
#include <vector>
#include "vector.hpp"

template <class stack>
void display_and_clear(stack &toprint)
{
	while(!toprint.empty())
	{
		std::cout << toprint.top() << '\n';
		toprint.pop();
	}
	std::cout << std::endl;	
}

template <class stack>
void teststack(stack &stack1,stack &stack2)
{
	COUT("default constructor:", "", "");
	display_and_clear(stack1);
	COUT("\"explicit\" constructor:", "", "");
	display_and_clear(stack2);	
	stack1.push(3);
	stack1.push(42);
	stack1.push(5);
	stack1.pop();
	display_and_clear(stack1);
	std::cout << std::endl;
}

int main(int argc, char **argv)
{
	if (argc == 1 || (argc == 2 && static_cast<std::string>(argv[1]) == "std"))
	{
		if (argc == 1)
	std::cout << "STD stack"<<std::endl;
	std::vector<int> myvector (2,200);        // vector with 2 elements
	std::stack<int,std::vector<int> > first;                    // empty stack
	std::stack<int,std::vector<int> > second(myvector);

	std::cout << "size of first: " << first.size() << '\n';
	std::cout << "size of second: " << second.size() << '\n';

	teststack(first, second);
	}

	if (argc == 1 || (argc == 2 && static_cast<std::string>(argv[1]) == "ft"))
	{
		if (argc == 1)
	std::cout << "------------------------------------\n\nFT stack"<<std::endl;
	ft::vector<int> myvector (2,200);        // vector with 2 elements
	ft::stack<int> first;                    // empty stack
	ft::stack<int,ft::vector<int> > second(myvector);

	std::cout << "size of first: " << first.size() << '\n';
	std::cout << "size of second: " << second.size() << '\n';

	teststack(first, second);
	}

	return (0);
}
