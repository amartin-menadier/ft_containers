#include "list.hpp"
#include <list>

template <typename T>
void display(const std::list<T> list)
{
	for (typename std::list<T>::const_iterator it=list.begin(); it!=list.end(); it++)
		std::cout << *it << ' ';
	std::cout << std::endl;	
}

template <typename T>
void display(ft::list<T> list)
{
	for (typename ft::list<T>::iterator it=list.begin(); it != list.end(); it++)
		std::cout << *it << ' ';
	std::cout << std::endl;
}

void list()
{
	// LIST
	// STD LIST
	std::cout << "LIST\nSTD LIST" << std::endl;
	std::cout << "'default constructor (1)'" << std::endl;
	std::list<int> stdList;	//default constructor (1/4)
	std::cout << "Is stdList empty ? " << stdList.empty() << std::endl;
	stdList.push_front(3);
	stdList.push_front(4);
	stdList.push_front(5);
	stdList.push_front(6);
	stdList.push_front(7);
	stdList.push_back(2);
	stdList.push_back(1);
	display(stdList);
	stdList.erase(++stdList.begin());
	display(stdList);
	stdList.pop_front();
	stdList.pop_back();
	display(stdList);
	stdList.insert(++(++stdList.begin()), 9);
	stdList.insert(stdList.begin(), 3, 1);		
	display(stdList);
	std::cout << std::endl << "Is stdList empty? " << stdList.empty();
	std::cout << std::endl << "Its size is " << stdList.size();
	std::cout << " and it can contain up to "<< stdList.max_size()<<" elements";
	std::cout << std::endl << "Its first element is " << stdList.front();
	std::cout << " and its last one is " << stdList.back();
	std::cout << std::endl << "'fill constructor (2)'" << std::endl;
	std::list<int> stdList2(5, 4);//fill constructor (2/4)
	display(stdList2);
//	stdList2.assign(3, 8);
	display(stdList2);
	stdList.swap(stdList2);
	display(stdList2);
	stdList2.resize(13);
	display(stdList2);
	stdList2.resize(15, 9);
	display(stdList2);
	stdList2.resize(10);
	display(stdList2);
	stdList2.splice(stdList2.begin(), stdList, stdList.begin());
	display(stdList2);
	display(stdList);
	stdList.splice(++(++(stdList.begin())), stdList2);
	display(stdList);	
	std::cout << "'range constructor (3)'" << std::endl;
	std::list<int> stdList3(++stdList.begin(), --stdList.end());//range constructor(3/4)
	display(stdList3);
	std::cout << "'copy constructor (4)'" << std::endl;
	std::list<int> stdList4(stdList);//copy constructor (4/4)
	display(stdList4);
	stdList.clear();
	std::cout << "Is stdList empty after clear? "<<stdList.empty();

//	std::list<int>::reverse_iterator stdListRIt;	
//	for (stdListRIt = stdList.rbegin();stdListRIt!= stdList.rend();stdListRIt++)
//		std::cout << *stdListRIt << std::endl;



	// FT LIST
	std::cout << std::endl << std::endl << "FT LIST" << std::endl;
	std::cout << "'default constructor (1)'" << std::endl;
	ft::list<int> ftList;	//default constructor (1/4)
	std::cout << "Is ftList empty ? " << ftList.empty() << std::endl;
	ftList.push_front(3);
	ftList.push_front(4);
	ftList.push_front(5);
	ftList.push_front(6);
	ftList.push_front(7);
	ftList.push_back(2);
	ftList.push_back(1);
	for (ft::list<int>::iterator ftListIt = ftList.begin(); ftListIt != ftList.end(); ftListIt++)
		std::cout << *ftListIt << ' ';
	std::cout << std::endl;
//	display(ftList);
	ftList.erase(++ftList.begin());
//	display(ftList);
	ftList.pop_front();
//	display(ftList);
	ftList.pop_back();
//	display(ftList);
	ftList.insert(++(++ftList.begin()), 9);
	ftList.insert(ftList.begin(), 3, 1);		
	display(ftList);
	std::cout << std::endl << "Is ftList empty? " << ftList.empty();
	std::cout << std::endl << "Its size is " << ftList.size();
	std::cout << " and it can contain up to "<< ftList.max_size()<<" elements";
	std::cout << std::endl << "Its first element is " << ftList.front();
	std::cout << " and its last one is " << ftList.back();
	std::cout << std::endl << "'fill constructor (2)'" << std::endl;
	ft::list<int> ftList2(5, 4);//fill constructor (2/4)
	display(ftList2);
//	ftList2.assign(3, 8);
	display(ftList2);
	ftList.swap(ftList2);
	display(ftList2);
	ftList2.resize(13);
	display(ftList2);
	ftList2.resize(15, 9);
	display(ftList2);
	ftList2.resize(10);
	display(ftList2);
	ftList2.splice(ftList2.begin(), ftList, ftList.begin());
	display(ftList2);
	display(ftList);
	ftList.splice(++(++(ftList.begin())), ftList2);
	display(ftList);	
	std::cout << "'range constructor (3)'" << std::endl;
//	ft::list<int> ftList3(++ftList.begin(), --ftList.end());//range constructor(3/4)
//	display(ftList3);
	std::cout << "'copy constructor (4)'" << std::endl;
	ft::list<int> ftList4(ftList);//copy constructor (4/4)
	display(ftList4);
	ftList.clear();
	std::cout << "Is ftList empty after clear? "<<ftList.empty();

//	ft::list<int>::reverse_iterator ftListRIt;	
//	for (ftListRIt = ftList.rbegin();ftListRIt!= ftList.rend();ftListRIt++)
//		std::cout << *ftListRIt << std::endl;
}

int main()
{
	list();
	return (0);
}
