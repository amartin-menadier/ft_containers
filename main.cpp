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
	COUT("default constructor (1):", "", "");
	display(list1);
	COUT("fill constructor (2):", "", "");
	display(list2);
	COUT("range constructor (3):", "", "");
	display(list3);
	COUT("copy constructor (4):", "", "");
	display(list4);
	COUT("Is list1 empty?", (list1.empty()? "yes":"no"), "");
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
	list1.insert(list1.begin(), 3, 7);		
	display(list1);//7754932
	COUT("Is list1 empty?", (list1.empty()? "yes":"no"), "");
	COUT("\nIts size is", list1.size(), "and it can contain up to ");
	COUT(list1.max_size(), "elements\nIts first element is", list1.front());
	COUT(" and its last one is", list1.back(), "\n");
	list2.assign(3, 8);
	display(list2);//888
	list2.assign(++(++(list1.begin())), list1.end());
	display(list2);//754932
	list1.swap(list2);
	display(list2);//77754932
	list2.resize(13);
	display(list2);//7775493200000
	list2.resize(15, 9);
	display(list2);//777549320000099
	list2.resize(10);
	display(list2);//7775493200
	list2.splice(list2.begin(), list1, list1.begin());
	display(list1);//549932
	display(list2);//77775493200
	list2.splice(++(++(list2.begin())), list1);
	display(list1);//
	display(list2);//7754932775493200
	list1.push_front(5);
	list1.insert(list1.begin(), ++(++(++(list2.begin()))), --list2.end());
	display(list1);//49327754493205
	list1.splice(++list1.begin(), list2,++(++(++(list2.begin()))), list2.end());
	display(list1);//44932775493200932775493205
	list1.merge(list2);
	list1.sort();
	display(list1);//00022223333444455557777779999
	list1.remove(7);
	display(list1);//00022223333444455559999
	list1.unique();
	display(list1);//023459
	list1.reverse();
	list2 = list1;
	COUT("list1:", "", "");
	display(list1);//954320
	COUT("list2:", "", "");
	display(list2);//954320
	COUT("list3:", "", "");
	display(list3);//444
	COUT("list4:", "", "");
	list4.push_back(8);
	display(list4);//444448
	COUT("Is list1 equal to list2?",(list1 == list2? "yes":"no"),"\n");
	COUT("Is list1 equal to list3?",(list1 == list3? "yes":"no"),"\n");
	COUT("Then they are different?",(list1 != list3? "yes":"no"),"\n");
	COUT("Is list1 smaller than list3?",(list1 < list3? "yes":"no"),"\n");
	COUT("Is list1 smaller or equal to list2?",(list1<=list2?"yes":"no"),"\n");
	COUT("Is list1 bigger than list4?",(list1 > list4? "yes":"no"),"\n");
	COUT("Is list1 bigger or equal to list2?",(list1>=list4? "yes":"no"),"\n");
	list1.clear();
	COUT("Is list1 empty after clear?", (list1.empty()? "yes":"no"), "");

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
	ft::list<int> ftList3(++ftList2.begin(), --ftList2.end());//range constructor(3/4)
	ft::list<int> ftList4(ftList2);//copy constructor (4/4)
	testList(ftList, ftList2, ftList3, ftList4);
	return (0);
}
