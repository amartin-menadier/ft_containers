#include "list.hpp"


/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ft::list::list()
{
}

ft::list::list( const ft::list & src )
{
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ft::list::~list()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ft::list &				ft::list::operator=( ft::list const & rhs )
{
	//if ( this != &rhs )
	//{
		//this->_value = rhs.getValue();
	//}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, ft::list const & i )
{
	//o << "Value = " << i.getValue();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */