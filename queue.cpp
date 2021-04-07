#include "queue.hpp"
#include "containers.hpp"
#include <queue>
#include <list>
#include "list.hpp"

template <class queue>
void display_and_clear(queue &toprint)
{
	std::cout << '\n';
	while(!toprint.empty())
	{
		std::cout << toprint.front() << '\n';
		toprint.pop();
	}
	std::cout << std::endl;	
}

template <class queue>
void testqueue(queue &queue1,queue &queue2, queue &queue3)
{
	COUT("default constructor:", "", "");
	display_and_clear(queue1);
	COUT("\"explicit\" constructor:", "", "");
	display_and_clear(queue2);	
	queue1.push(3);
	queue1.push(42);
	queue1.push(5);
	queue1.pop();
	std::cout << queue1.back() << '\n';
	queue2.push(3);
	queue2.push(45272);
	queue2.push(1235);
	COUT("Is queue1 equal to queue2?",(queue1 == queue2? "yes":"no"),"\n");
	COUT("Is queue1 equal to queue3?",(queue1 == queue3? "yes":"no"),"\n");
	COUT("Then they are different?",(queue1 != queue3? "yes":"no"),"\n");
	COUT("Is queue1 smaller than queue3?",(queue1 < queue3? "yes":"no"),"\n");
	COUT("Is queue1 smaller or equal to queue2?",(queue1<=queue2?"yes":"no"),"\n");
	COUT("Is queue1 bigger than queue3?",(queue1 > queue3? "yes":"no"),"\n");
	COUT("Is queue1 bigger or equal to queue3?",(queue1>=queue3? "yes":"no"),"\n");
	display_and_clear(queue1);
	display_and_clear(queue2);
	display_and_clear(queue3);
	std::cout << std::endl;
}

void	queue_main(std::string nameSpace)
{
	if (nameSpace == "both" || nameSpace == "std")
	{
		if (nameSpace == "both")
			std::cout << "\n\nQUEUE\nSTD QUEUE"<<std::endl;
		std::list<int> mylist (2,200);        // list with 2 elements
		std::queue<int,std::list<int> > stdqueue0;// empty queue
		std::queue<int,std::list<int> > stdqueue1(mylist);
		std::cout << "size of first: " << stdqueue0.size() << '\n';
		std::cout << "size of second: " << stdqueue1.size() << '\n';
		std::queue<int,std::list<int> > stdqueue2(stdqueue0);
		testqueue(stdqueue0, stdqueue1, stdqueue2);
	}
	if (nameSpace == "both" || nameSpace == "ft")
	{
		if (nameSpace == "both")
			std::cout << "---------------------\n\nFT QUEUE"<<std::endl;
		ft::list<int> mylist (2,200);        // list with 2 elements
		ft::queue<int> ftqueue0;                // empty queue
		ft::queue<int,ft::list<int> > ftqueue1(mylist);
		std::cout << "size of first: " << ftqueue0.size() << '\n';
		std::cout << "size of second: " << ftqueue1.size() << '\n';
		ft::queue<int,ft::list<int> > ftqueue2(ftqueue0);
		testqueue(ftqueue0, ftqueue1, ftqueue2);
	}
}
