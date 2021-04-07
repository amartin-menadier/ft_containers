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
void testqueue(queue &queue1,queue &queue2)
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
	display_and_clear(queue1);
	std::cout << std::endl;
}

int main(int argc, char **argv)
{
	if (argc == 1 || (argc == 2 && static_cast<std::string>(argv[1]) == "std"))
	{
		if (argc == 1)
	std::cout << "STD queue"<<std::endl;
	std::list<int> mylist (2,200);        // list with 2 elements
	std::queue<int,std::list<int> > first;                    // empty queue
	std::queue<int,std::list<int> > second(mylist);

	std::cout << "size of first: " << first.size() << '\n';
	std::cout << "size of second: " << second.size() << '\n';

	testqueue(first, second);
	}

	if (argc == 1 || (argc == 2 && static_cast<std::string>(argv[1]) == "ft"))
	{
		if (argc == 1)
	std::cout << "------------------------------------\n\nFT queue"<<std::endl;
	ft::list<int> mylist (2,200);        // list with 2 elements
	ft::queue<int> first;                    // empty queue
	ft::queue<int,ft::list<int> > second(mylist);

	std::cout << "size of first: " << first.size() << '\n';
	std::cout << "size of second: " << second.size() << '\n';

	testqueue(first, second);
	}
	return (0);
}
