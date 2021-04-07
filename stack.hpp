#ifndef STACK_HPP
# define STACK_HPP

# include <iostream>
# include <string>
# include "vector.hpp"

namespace ft
{
	template <class T, class Container = vector<T> > //should be deque but deque is a bonus
	class stack
	{
		public:
			typedef T			value_type;
			typedef size_t		size_type;
			typedef Container	container_type;

//CONSTRUCTOR
			explicit stack (const container_type& ctnr = container_type())
				: _container(ctnr) {};

//MEMBER FUNCTIONS
			bool empty() const{
				return _container.empty();};
			size_type size() const{
				return _container.size();};
			value_type& top(){
				return _container.back();};
			const value_type& top() const{
				return _container.back();};
			void push (const value_type& val){
				_container.push_back(val);};
			void pop(){
				_container.pop_back();};
		private:
			container_type	_container;
	};
};

//NON-MEMBER FUNCTION OVERLOADS = RELATIONAL OPERATORS
template <class T, class Container>
	bool operator== (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs){
		return	lhs._stack == rhs._stack;};
template <class T, class Container>
	bool operator!= (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs){
		return	lhs._stack != rhs._stack;};
template <class T, class Container>
	bool operator<  (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs){
		return	lhs._stack < rhs._stack;};
template <class T, class Container>
	bool operator<= (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs){
		return	lhs._stack <= rhs._stack;};
template <class T, class Container>
	bool operator>  (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs){
		return	lhs._stack > rhs._stack;};
template <class T, class Container>
	bool operator>= (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs){
		return	lhs._stack >= rhs._stack;};

#endif /* *********************************************************** STACK_H */