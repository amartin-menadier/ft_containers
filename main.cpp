#include "list.hpp"
#include <list>

int main()
{
	// LIST
	// STD LIST
	std::cout << "LIST\nSTD LIST" << std::endl;
	std::cout << "'default constructor (1)'" << std::endl;
	std::list<int> stdList;	//default constructor (1/4)
	std::cout << "Is stdList empty ? " << stdList.empty() << std::endl;
	std::list<int>::iterator stdListIt;
//	stdList.push_back(5);
	stdList.push_front(3);
	stdList.push_front(4);
	stdList.push_front(5);
	stdList.push_front(6);
	stdList.push_front(7);
	stdList.push_back(2);
	stdList.push_back(1);
	for (stdListIt = stdList.begin(); stdListIt != stdList.end();stdListIt++)
		std::cout << *stdListIt << ' ';
	stdList.erase(stdList.begin());
	std::cout << std::endl;
	for (stdListIt = stdList.begin(); stdListIt != stdList.end(); stdListIt++)
		std::cout << *stdListIt << ' ';

	std::cout << std::endl << "Is stdList empty ? " << stdList.empty();
	std::cout << std::endl << "Its size is " << stdList.size();
	std::cout << " and it can contain up to "<< stdList.max_size()<<" elements";
	std::cout << std::endl << "Its first element is " << stdList.front();
	std::cout << " and its last one is " << stdList.back();
	stdList.clear();
	std::cout << std::endl << "Is stdList empty ? " << stdList.empty();
	for (stdListIt = stdList.begin(); stdListIt != stdList.end(); stdListIt++)
		std::cout << *stdListIt << ' ';	
	std::cout << std::endl << "'fill constructor (2)'" << std::endl;
	std::list<int> stdList2(5, 4);//fill constructor (2/4)
	for (stdListIt = stdList2.begin(); stdListIt != stdList2.end();stdListIt++)
		std::cout << *stdListIt << ' ';
	stdList2.assign(3, 8);
	std::cout << std::endl;
	for (stdListIt = stdList2.begin(); stdListIt != stdList2.end();stdListIt++)
		std::cout << *stdListIt << ' ';
	std::cout << std::endl << "'range constructor (3)'" << std::endl;
	stdListIt = stdList.begin();
	stdListIt++;
	std::list<int> stdList3(stdListIt, stdList.end());//range constructor (3/4)
	for (stdListIt = stdList3.begin(); stdListIt != stdList3.end();stdListIt++)
		std::cout << *stdListIt << ' ';	
	std::cout << std::endl << "'copy constructor (4)'" << std::endl;
	std::list<int> stdList4(stdList);//copy constructor (4/4)
	for (stdListIt = stdList4.begin(); stdListIt != stdList4.end();stdListIt++)
		std::cout << *stdListIt << ' ';		
//	std::list<int>::reverse_iterator stdListRIt;	
//	for (stdListRIt = stdList.rbegin();stdListRIt!= stdList.rend();stdListRIt++)
//		std::cout << *stdListRIt << std::endl;

	// FT LIST
	std::cout << std::endl << std::endl << "FT LIST" << std::endl;
	std::cout << "'default constructor (1)'" << std::endl;
	ft::list<int> ftList;	//default constructor (1/4)
	std::cout << "Is ftList empty ? " << ftList.empty() << std::endl;
	ft::list<int>::iterator ftListIt;
	ftList.push_front(3);
	ftList.push_front(4);
	ftList.push_front(5);
	ftList.push_front(6);
	ftList.push_front(7);
	ftList.push_back(2);
	ftList.push_back(1);
	for (ftListIt = ftList.begin(); ftListIt != ftList.end(); ftListIt++)
		std::cout << *ftListIt << ' ';
	ftList.erase(ftList.begin());
	std::cout << std::endl;
	for (ftListIt = ftList.begin(); ftListIt != ftList.end(); ftListIt++)
		std::cout << *ftListIt << ' ';
//	ftList.erase(++ftList.begin(), --ftList.end());
	std::cout << std::endl;
	for (ftListIt = ftList.begin(); ftListIt != ftList.end(); ftListIt++)
		std::cout << *ftListIt << ' ';
	std::cout << std::endl << "Is ftList empty ? " << ftList.empty();
	std::cout << std::endl << "Its size is " << ftList.size();
	std::cout << " and it can contain up to " << ftList.max_size()<<" elements";
	std::cout << std::endl << "Its first element is " << ftList.front();
	std::cout << " and its last one is " << ftList.back();
//	ftList.clear();
	std::cout << std::endl << "Is ftList empty ? " << ftList.empty();
	std::cout << std::endl << "'fill constructor (2)'" << std::endl;
	ft::list<int> ftList2(5, 4);//fill constructor (2/4)	
	for (ftListIt = ftList2.begin(); ftListIt != ftList2.end();ftListIt++)
		std::cout << *ftListIt << ' ';
//	ftList2.assign(3, 8);
	std::cout << std::endl;
	for (ftListIt = ftList2.begin(); ftListIt != ftList2.end();ftListIt++)
		std::cout << *ftListIt << ' ';
	std::cout << std::endl << "'range constructor (3)'" << std::endl;
/*	
	ftListIt = ftList.begin();
	ftListIt++;
	std::list<int> ftList3(ftListIt, ftList.end());//range constructor (3/4)
	for (ftListIt = ftList3.begin(); ftListIt != ftList3.end();ftListIt++)
	std::cout << *ftListIt << ' ';
*/		
	std::cout << std::endl << "'copy constructor (4)'" << std::endl;
/*	ft::list<int> ftList4(ftList);//copy constructor (4/4)
	for (ftListIt = ftList4.begin(); ftListIt != ftList4.end();ftListIt++)
		std::cout << *ftListIt << ' ';


*/
			std::cout << std::endl;
	return (0);
}
