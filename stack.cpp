#include "stack.hpp"
#include "containers.hpp"
#include <stack>
#include <vector>
#include "vector.hpp"

template <class stack>
void display_and_clear(stack &toprint)
{
	std::cout << '\n';
	while(!toprint.empty())
	{
		std::cout << toprint.top() << '\n';
		toprint.pop();
	}
	std::cout << std::endl;	
}

template <class stack>
void teststack(stack &stack1,stack &stack2, stack &stack3)
{
	COUT("default constructor:", "", "");
	display_and_clear(stack1);
	COUT("\"explicit\" constructor:", "", "");
	display_and_clear(stack2);	
	stack1.push(3);
	stack1.push(42);
	stack1.push(5);
	stack1.pop();
	stack2.push(3782);
	stack2.push(422);
	stack2.push(5553);
	stack2.push(171742);
	stack2.push(517);
	COUT("Is stack1 equal to stack2?",(stack1 == stack2? "yes":"no"),"\n");
	COUT("Is stack1 equal tostack3?",(stack1 ==stack3? "yes":"no"),"\n");
	COUT("Then they are different?",(stack1 !=stack3? "yes":"no"),"\n");
	COUT("Is stack1 smaller thanstack3?",(stack1 <stack3? "yes":"no"),"\n");
	COUT("Is stack1 smaller or equal to stack2?",(stack1<=stack2?"yes":"no"),"\n");
	COUT("Is stack1 bigger than stack3?",(stack1 > stack3? "yes":"no"),"\n");
	COUT("Is stack1 bigger or equal to stack3?",(stack1>=stack3? "yes":"no"),"\n");
	display_and_clear(stack1);
	display_and_clear(stack2);
	display_and_clear(stack3);
	std::cout << std::endl;
}

void	stack_main(std::string nameSpace)
{
	if (nameSpace == "both" || nameSpace == "std")
	{
		if (nameSpace == "both")
			std::cout << "\n\nSTACK\nSTD STACK"<<std::endl;
	std::vector<int> myvector (2,200);        // vector with 2 elements
	std::stack<int,std::vector<int> > stdstack0;  // empty stack
	std::stack<int,std::vector<int> > stdstack1(myvector);
	std::cout << "size of first: " << stdstack0.size() << '\n';
	std::cout << "size of second: " << stdstack1.size() << '\n';
	std::stack<int, std::vector<int> > stdstack2(stdstack0);
	teststack(stdstack0, stdstack1, stdstack2);
	}
	if (nameSpace == "both" || nameSpace == "ft")
	{
		if (nameSpace == "both")
			std::cout << "---------------------\n\nFT STACK"<<std::endl;
	ft::vector<int> myvector (2,200);        // vector with 2 elements
	ft::stack<int> ftstack0;                    // empty stack
	ft::stack<int,ft::vector<int> > ftqueue1(myvector);
	std::cout << "size of first: " << ftstack0.size() << '\n';
	std::cout << "size of second: " << ftqueue1.size() << '\n';
	ft::stack<int> ftstack2(ftstack0);
	teststack(ftstack0, ftqueue1, ftstack2);
	}
}
