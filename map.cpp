#include "map.hpp"
#include "containers.hpp"
#include <map>

template <class map>
void display(map &toprint)
{
	std::cout << ">" << std::endl;
	for (typename map::iterator it=toprint.begin(); it!=toprint.end(); it++)
		std::cout << it->first << " => " << it->second << std::endl;
	std::cout << "<" << std::endl;
}

//Predicate ≃ bool function
bool biggerThanEight(const int &totest){return (totest > 8);}
//Binary Predicate ≃ bool function with two args
bool isBiggerByTwo(int first, int next){return (first == next + 2);}
//Compare ≃ Binary Predicate but comparing two args
bool isSmaller(int first, int second){return (first < second);}

template <class map>
void testmap(map &map0, map &map1,map &map2,map &map3)
{
	COUT("empty constructor (1):", "", "\n");
	display(map0);
	display(map1);
	(void)map3;
	COUT("range constructor (2):", "", "\n");
	display(map2);
	COUT("copy constructor (3):", "", "\n");
	display(map3);
	COUT("Is map1 empty?", (map1.empty()? "yes":"no"), "\n");
	display(map1);

/*	for(typename map::reverse_iterator Rit = map2.rbegin(); Rit != map2.rend(); Rit++)
		std::cout << Rit->first << " => " << Rit->second << std::endl;
	map2.erase(++map2.begin());
	display(map2);

*/	
	display(map2);
	COUT("Is map1 empty?", (map2.empty()? "yes":"no"), "");
	COUT("\nIts size is", map2.size(), "and it can contain up to ");
	COUT(map2.max_size(), "","");
	display(map2);
/*	map1.swap(map2);
	display(map2);
	map1.insert(map1.begin(), ++(++(++(map2.begin()))), --map2.end());
	display(map1);
	COUT("map1:", "", "");
	display(map1);
	COUT("map2:", "", "");
	map2 = map1;
	display(map2);
	COUT("map3:", "", "");
	display(map3);
	COUT("map4:", "", "");
	display(map4);
	COUT("Is map1 equal to map2?",(map1 == map2? "yes":"no"),"\n");
	COUT("Is map1 equal to map3?",(map1 == map3? "yes":"no"),"\n");
	COUT("Then they are different?",(map1 != map3? "yes":"no"),"\n");
	COUT("Is map1 smaller than map3?",(map1 < map3? "yes":"no"),"\n");
	COUT("Is map1 smaller or equal to map2?",(map1<=map2?"yes":"no"),"\n");
	COUT("Is map1 bigger than map4?",(map1 > map4? "yes":"no"),"\n");
	COUT("Is map1 bigger or equal to map4?",(map1>=map4? "yes":"no"),"\n");
	swap(map1, map4);
	display(map1);
	display(map4);
*/	map1.clear();
	COUT("Is map1 empty after clear?", (map1.empty()? "yes":"no"), "");
	std::cout << std::endl;
}

int main(int argc, char **argv)
{
	if (argc == 1 || (argc == 2 && static_cast<std::string>(argv[1]) == "std"))
	{
	if (argc == 1)
		std::cout << "MAP\nSTD MAP" << std::endl;
	std::map<std::string, int> stdmap;	//empty constructor (1/3)
	std::map<std::string, int> stdmap1;
	stdmap1.insert(std::pair<std::string, int> ("ABC", 2));
	stdmap1.insert(std::pair<std::string, int> ("DEF", 52));
	stdmap1.insert(std::pair<std::string, int> ("GHI", 43));
	stdmap1.insert(std::pair<std::string, int> ("GHI", 13));
	stdmap1.insert(std::pair<std::string, int> ("JKL", 2856));
	stdmap1.insert(std::pair<std::string, int> ("MNO", 12));
	stdmap1.insert(std::pair<std::string, int> ("PQR", 0));
	stdmap1.insert(std::pair<std::string, int> ("STU", 42));
	std::map<std::string, int> stdmap2(++stdmap1.begin(), --stdmap1.end());//range constructor(2/3)
	std::map<std::string, int> stdmap3(stdmap2);//copy constructor (3/3)
	testmap(stdmap, stdmap1, stdmap2, stdmap3);
	}

	if (argc == 1 || (argc == 2 && static_cast<std::string>(argv[1]) == "ft"))
	{
	if (argc == 1)
		std::cout << "-----------------------------------\n\nFT MAP"<<std::endl;
	ft::map<std::string, int> ftmap;	//empty constructor (1/3)
	ft::map<std::string, int> ftmap1;
	ftmap1.insert(ft::pair<std::string, int> ("ABC", 2));
	ftmap1.insert(ft::pair<std::string, int> ("DEF", 52));
	ftmap1.insert(ft::pair<std::string, int> ("GHI", 43));
	ftmap1.insert(ft::pair<std::string, int> ("MNO", 12));
	ftmap1.insert(ft::pair<std::string, int> ("JKL", 2856));
	ftmap1.insert(ft::pair<std::string, int> ("PQR", 0));
	ftmap1.insert(ft::pair<std::string, int> ("STU", 42));
	ft::map<std::string, int> ftmap2(++ftmap1.begin(), --ftmap1.end());//range constructor(2/3)
	ft::map<std::string, int> ftmap3(ftmap2);//copy constructor (3/3)
	testmap(ftmap, ftmap1, ftmap2, ftmap3);
	}
	return (0);
}
