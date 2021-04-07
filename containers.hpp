#ifndef CONTAINERS_HPP
# define CONTAINERS_HPP
# define COUT(value1, value2, value3) std::cout << value1 << ' ' << value2 << ' ' << value3;
# include <string>

void    list_main(std::string nameSpace);
void    vector_main(std::string nameSpace);
void    map_main(std::string nameSpace);
void    stack_main(std::string nameSpace);
void	queue_main(std::string nameSpace);

#endif