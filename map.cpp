#include "map.hpp"
#include "containers.hpp"
#include <map>

template <class map>
void display(map &toprint)
{
	std::cout << "<start>\n";
	for (typename map::iterator it=toprint.begin(); it!=toprint.end(); it++)
		std::cout<<'('<<it->first << "; " << it->second << ");\n";
	std::cout << "<end>" << std::endl;
}

//Predicate ≃ bool function
bool biggerThanEight(const int &totest){return (totest > 8);}
//Binary Predicate ≃ bool function with two args
bool isBiggerByTwo(int first, int next){return (first == next + 2);}
//Compare ≃ Binary Predicate but comparing two args
bool isSmaller(int first, int second){return (first < second);}

template <class map, class pair>
void testmap(map &map0, map &map1,map &map2,map &map3, pair pair0)
{
	COUT("empty constructor (1):", "", "\n");
	display(map0);
	display(map1);
	(void)map3;
	COUT("range constructor (2):", "", "\n");
	display(map2);
	COUT("copy constructor (3):", "", "\n");
	display(map3);
	COUT("Is map0 empty?", (map0.empty()? "yes":"no"), "\n");
	COUT("Is map2 empty?", (map2.empty()? "yes":"no"), "");
	COUT("\nIts size is", map2.size(), "and it can contain up to ");
	COUT(map2.max_size(), "elements\n","");
	std::cout << map2["DEF"] << '\n';
	std::cout << map2["ZYX"] << '\n';
	display(map2);
	for(typename map::reverse_iterator Rit = map2.rbegin(); Rit != map2.rend(); Rit++)
		std::cout << Rit->first << " => " << Rit->second << std::endl;
	map3.insert(++(++(map3.begin())), pair0);//insert with hint (bad position(before))
	display(map3);
	map3.insert(--(map3.end()), pair0);//insert with hint (bad position(after))
	display(map3);
	map3.erase(++(map3.begin()));
	display(map3);
	map3.erase(++(map3.begin()), --(map3.end()));
	display(map3);
	map3.erase("PQR");//exists
	display(map3);
	map2.erase("NOPE");//does not exist
	display(map2);
	map3.swap(map2);
	display(map3);
	display(map2);
	//example given in c++ reference for value_compare function
	map0["x"]=1001;
	map0["y"]=2002;
	map0["z"]=3003;
	std::cout << "map0 contains:\n";
	typename map::iterator it = map0.begin();
	do {
		std::cout << it->first << " => " << it->second << '\n';
	} while(map0.value_comp()(*it++, *(--(map0.end()))));
	//end of the given example


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
	std::pair<std::string, int> stdpair("PAIR", 42);
	testmap(stdmap, stdmap1, stdmap2, stdmap3, stdpair);
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
	ft::pair<std::string, int> ftpair("PAIR", 42);
	testmap(ftmap, ftmap1, ftmap2, ftmap3, ftpair);
	}
	return (0);
}
