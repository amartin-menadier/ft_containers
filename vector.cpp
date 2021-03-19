#include "vector.hpp"
#include "containers.hpp"
#include <vector>

template <class vector>
void display(vector &toprint)
{
	for (typename vector::iterator it=toprint.begin(); it!=toprint.end(); it++)
		std::cout << *it << ' ';
	std::cout << std::endl;	
}

//Predicate ≃ bool function
bool biggerThanEight(const int &totest){return (totest > 8);}
//Binary Predicate ≃ bool function with two args
bool isBiggerByTwo(int first, int next){return (first == next + 2);}
//Compare ≃ Binary Predicate but comparing two args
bool isSmaller(int first, int second){return (first < second);}

template <class vector>
void testvector(vector &vector1,vector &vector2,vector &vector3,vector &vector4)
{
	COUT("default constructor (1):", "", "");
	display(vector1);
	COUT("fill constructor (2):", "", "");
	display(vector2);
	COUT("range constructor (3):", "", "");
	display(vector3);
	COUT("copy constructor (4):", "", "");
	display(vector4);
	COUT("Is vector1 empty?", (vector1.empty()? "yes":"no"), "\n");
	COUT("Its capacity is", vector1.capacity(), "\n");
	COUT("What is vector 2's capacity?", vector2.capacity(), "\n");
	vector2.push_back(5);
	COUT("What is vector 2's capacity?", vector2.capacity(), "\n");
	vector2.push_back(5);
	COUT("What is vector 2's capacity?", vector2.capacity(), "\n");
	vector2.push_back(5);
	COUT("What is vector 2's capacity?", vector2.capacity(), "\n");
	vector2.push_back(5);
	COUT("What is vector 2's capacity?", vector2.capacity(), "\n");
	vector2.push_back(5);
	COUT("What is vector 2's capacity?", vector2.capacity(), "\n");
	vector2.push_back(5);
	COUT("What is vector 2's capacity?", vector2.capacity(), "\n");
	vector2.push_back(5);
	COUT("What is vector 2's capacity?", vector2.capacity(), "\n");
	vector2.push_back(5);
	COUT("What is vector 2's capacity?", vector2.capacity(), "\n");
	vector2.push_back(5);
	COUT("What is vector 2's capacity?", vector2.capacity(), "\n");
	vector2.push_back(5);
	COUT("What is vector 2's capacity?", vector2.capacity(), "\n");
	vector2.push_back(5);
	COUT("What is vector 2's capacity?", vector2.capacity(), "\n");
	vector2.push_back(5);
	COUT("What is vector 2's capacity?", vector2.capacity(), "\n");
	vector2.push_back(5);
	COUT("What is vector 2's capacity?", vector2.capacity(), "\n");
	display(vector1);
	vector1.push_back(1);
	display(vector1);
	vector1.push_back(2);
	vector1.push_back(3);
	vector1.push_back(4);
	vector1.push_back(5);
	vector1.push_back(6);
	vector1.push_back(7);
	display(vector1);
	vector1.pop_back();
	vector1.pop_back();
	vector1.pop_back();
	vector1.pop_back();
	vector1.pop_back();
	vector1.pop_back();
	display(vector1);
	std::cout << vector1.capacity();
/*

	for(typename vector::reverse_iterator Rit = vector1.rbegin(); Rit != vector1.rend(); Rit++)
		std::cout << *Rit;
	std::cout << std::endl;	
	display(vector1);//7654321
	vector1.erase(++vector1.begin());
	display(vector1);//754321
	vector1.pop_front();
	vector1.pop_back();
	display(vector1);//5432
	vector1.insert(++(++vector1.begin()), 9);
	vector1.insert(vector1.begin(), 3, 7);		
	display(vector1);//7754932
	COUT("Is vector1 empty?", (vector1.empty()? "yes":"no"), "");
	COUT("\nIts size is", vector1.size(), "and it can contain up to ");
	COUT(vector1.max_size(), "elements\nIts first element is", vector1.front());
	COUT(" and its last one is", vector1.back(), "\n");
	vector2.assign(3, 8);
	display(vector2);//888
	vector2.assign(++(++(vector1.begin())), vector1.end());
	display(vector2);//754932
	vector1.swap(vector2);
	display(vector2);//77754932
	vector2.resize(13);
	display(vector2);//7775493200000
	vector2.resize(15, 9);
	display(vector2);//777549320000099
	vector2.resize(10);
	display(vector2);//7775493200
	vector2.splice(vector2.begin(), vector1, vector1.begin());
	display(vector1);//54932
	display(vector2);//77775493200
	vector3 = vector1;
	vector2.splice(++(++(vector2.begin())), vector1);
	display(vector1);//
	display(vector2);//7754932775493200
	vector1.push_front(5);
	vector1.insert(vector1.begin(), ++(++(++(vector2.begin()))), --vector2.end());
	display(vector1);//49327754493205
	vector1.splice(++vector1.begin(), vector2,++(++(++(vector2.begin()))), vector2.end());
	display(vector1);//44932775493200932775493205
	vector1.merge(vector2);
	vector1.sort();
	display(vector1);//00022223333444455557777779999
	vector1.merge(vector3, isSmaller);//(vector3 = 54932)
	display(vector1);//0002222333344445555547777779999932 
	vector1.remove(7);
	display(vector1);//000222233334444555554999932
	vector1.unique();
	display(vector1);//023454932
	vector1.reverse();
	display(vector1);//239454320
	vector1.sort(isSmaller);
	display(vector1);//022334459
	vector1.remove_if(biggerThanEight);
	display(vector1);//02233445
	vector1.unique(isBiggerByTwo);
	display(vector1);//02233445
	COUT("vector1:", "", "");
	display(vector1);//02233445
	COUT("vector2:", "", "");
	vector2 = vector1;
	display(vector2);//02233445
	COUT("vector3:", "", "");
	display(vector3);//
	COUT("vector4:", "", "");
	vector4.pop_back();
	display(vector4);//4444
	COUT("Is vector1 equal to vector2?",(vector1 == vector2? "yes":"no"),"\n");
	COUT("Is vector1 equal to vector3?",(vector1 == vector3? "yes":"no"),"\n");
	COUT("Then they are different?",(vector1 != vector3? "yes":"no"),"\n");
	COUT("Is vector1 smaller than vector3?",(vector1 < vector3? "yes":"no"),"\n");
	COUT("Is vector1 smaller or equal to vector2?",(vector1<=vector2?"yes":"no"),"\n");
	COUT("Is vector1 bigger than vector4?",(vector1 > vector4? "yes":"no"),"\n");
	COUT("Is vector1 bigger or equal to vector4?",(vector1>=vector4? "yes":"no"),"\n");
	swap(vector1, vector4);
	display(vector1);
	display(vector4);
	vector1.clear();
	COUT("Is vector1 empty after clear?", (vector1.empty()? "yes":"no"), "");
*/
	std::cout << std::endl;
}

int main(int argc, char **argv)
{
	if (argc == 1 || (argc == 2 && static_cast<std::string>(argv[1]) == "std"))
	{
		if (argc == 1)
	std::cout << "vector\nSTD VECTOR" << std::endl;
	std::vector<int> stdvector;	//default constructor (1/4)
	std::vector<int> stdvector2(5, 4);//fill constructor (2/4)
	std::vector<int> stdvector3(++stdvector2.begin(), --stdvector2.end());//range constructor(3/4)
	std::vector<int> stdvector4(stdvector2);//copy constructor (4/4)
	testvector(stdvector, stdvector2, stdvector3, stdvector4);
	}

	if (argc == 1 || (argc == 2 && static_cast<std::string>(argv[1]) == "ft"))
	{
		if (argc == 1)
	std::cout << "------------------------------------\n\nFT VECTOR"<<std::endl;
	ft::vector<int> ftvector;	//default constructor (1/4)
	ft::vector<int> ftvector2(5, 4);//fill constructor (2/4)
//	ft::vector<int> ftvector3(++ftvector2.begin(), --ftvector2.end());//range constructor(3/4)
//	ft::vector<int> ftvector4(ftvector2);//copy constructor (4/4)
	testvector(ftvector, ftvector2, ftvector, ftvector);
//	testvector(ftvector, ftvector2, ftvector3, ftvector4);
	}

	return (0);
}
