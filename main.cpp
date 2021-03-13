#include "list.hpp"
#include "containers.hpp"
#include <list>


template <class list>
void display(list &toprint)
{
	for (typename list::iterator it=toprint.begin(); it!=toprint.end(); it++)
		std::cout << *it << ' ';
	std::cout << std::endl;	
}

template <class list>
void testList(list list1, list list2, list list3, list list4)
{
	// LIST
	// STD LIST
	COUT("'default constructor (1)':", "", "");
	display(list1);
	COUT("'fill constructor (2)':", "", "");
	display(list2);
	COUT("'range constructor (2)':", "", "");
	display(list3);
	COUT("'copy constructor (2)':", "", "");
	display(list4);
	COUT("Is list1 empty?", list1.empty(), "");
	std::cout << std::endl;
	list1.push_front(3);
	list1.push_front(4);
	list1.push_front(5);
	list1.push_front(6);
	list1.push_front(7);
	list1.push_back(2);
	list1.push_back(1);
	display(list1);//7654321
	list1.erase(++list1.begin());
	display(list1);//754321
	list1.pop_front();
	list1.pop_back();
	display(list1);//5432
	list1.insert(++(++list1.begin()), 9);
	list1.insert(list1.begin(), 3, 1);		
	display(list1);//11154932
	COUT("Is list1 empty?", list1.empty(), "");
	std::cout << std::endl << "Its size is " << list1.size();
	std::cout << " and it can contain up to "<< list1.max_size()<<" elements";
	std::cout << std::endl << "Its first element is " << list1.front();
	std::cout << " and its last one is " << list1.back() << std::endl;
	list2.assign(3, 8);
	display(list2);//888
	list1.swap(list2);
	display(list2);//11154932
	list2.resize(13);
	display(list2);//1115493200000
	list2.resize(15, 9);
	display(list2);//111549320000099
	list2.resize(10);
	display(list2);//1115493200
	list2.splice(list2.begin(), list1, list1.begin());
	display(list1);//88
	display(list2);//81115493200
	list2.splice(++(++(list2.begin())), list1);
	display(list1);//
	display(list2);//8188115493200
	list1.clear();
	COUT("Is list2 empty after clear?", list1.empty(), "");
	std::cout << std::endl;

}

int main()
{
	std::cout << "LIST\nSTD LIST" << std::endl;
	std::list<int> stdList;	//default constructor (1/4)
	std::list<int> stdList2(5, 4);//fill constructor (2/4)
	std::list<int> stdList3(++stdList2.begin(), --stdList2.end());//range constructor(3/4)
	std::list<int> stdList4(stdList2);//copy constructor (4/4)
	testList(stdList, stdList2, stdList3, stdList4);

	std::cout << "\nFT LIST" << std::endl;
	ft::list<int> ftList;	//default constructor (1/4)
	ft::list<int> ftList2(5, 4);//fill constructor (2/4)
//	ft::list<int> ftList3(++ftList2.begin(), --ftList2.end());//range constructor(3/4)
	ft::list<int> ftList4(ftList2);//copy constructor (4/4)
	testList(ftList, ftList2, ftList, ftList4);
	return (0);
}
