#include "containers.hpp"

int main(int argc, char** argv)
{
	if (argc == 1 || (argc >= 2 && static_cast<std::string>(argv[1]) == "list"))
	{
		if (argc <= 2)//make et make list
			list_main("both");
		else if (static_cast<std::string>(argv[2]) == "ft")
			list_main("ft");
		else if (static_cast<std::string>(argv[2]) == "std")
			list_main("std");
	}
	if (argc == 1 || (argc >= 2 && static_cast<std::string>(argv[1]) == "vector"))
	{
		if (argc <= 2)//make et make vector
			vector_main("both");
		else if (static_cast<std::string>(argv[2]) == "ft")
			vector_main("ft");
		else if (static_cast<std::string>(argv[2]) == "std")
			vector_main("std");
	}
	if (argc == 1 || (argc >= 2 && static_cast<std::string>(argv[1]) == "map"))
	{
		if (argc <= 2)//make et make map
			map_main("both");
		else if (static_cast<std::string>(argv[2]) == "ft")
			map_main("ft");
		else if (static_cast<std::string>(argv[2]) == "std")
			map_main("std");
	}
	if (argc == 1 || (argc >= 2 && static_cast<std::string>(argv[1]) == "stack"))
	{
		if (argc <= 2)//make et make stack
			stack_main("both");
		else if (static_cast<std::string>(argv[2]) == "ft")
			stack_main("ft");
		else if (static_cast<std::string>(argv[2]) == "std")
			stack_main("std");
	}
	if (argc == 1 || (argc >= 2 && static_cast<std::string>(argv[1]) == "queue"))
	{
		if (argc <= 2)//make et make queue
			queue_main("both");
		else if (static_cast<std::string>(argv[2]) == "ft")
			queue_main("ft");
		else if (static_cast<std::string>(argv[2]) == "std")
			queue_main("std");
	}
	return (0);
}
