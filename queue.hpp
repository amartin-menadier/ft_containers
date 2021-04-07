#ifndef QUEUE_HPP
# define QUEUE_HPP

# include <iostream>
# include <string>
# include "list.hpp"

namespace ft
{
	template <class T, class Container = list<T> > //should be deque but deque is a bonus
	class queue
	{
		public:
			typedef T			value_type;
			typedef size_t		size_type;
			typedef Container	container_type;

//CONSTRUCTOR
			explicit queue (const container_type& ctnr = container_type()) : _container(ctnr) {};

//MEMBER FUNCTIONS
			bool empty() const{
				return _container.empty();};
			size_type size() const{
				return _container.size();};
			value_type& back(){
				return _container.back();};
			const value_type& back() const{
				return _container.back();};
			value_type& front(){
				return _container.front();};
			const value_type& front() const{
				return _container.front();};
			void push (const value_type& val){
				_container.push_back(val);};
			void pop(){
				_container.pop_front();};
				
//NON-MEMBER FUNCTION OVERLOADS = RELATIONAL OPERATORS
			friend bool operator== (const ft::queue<T,Container>& lhs, const ft::queue<T,Container>& rhs){
				return	(lhs._container == rhs._container);};
			friend bool operator!= (const ft::queue<T,Container>& lhs, const ft::queue<T,Container>& rhs){
				return	(lhs._container != rhs._container);};
			friend bool operator<  (const ft::queue<T,Container>& lhs, const ft::queue<T,Container>& rhs){
				return	(lhs._container <  rhs._container);};
			friend bool operator<= (const ft::queue<T,Container>& lhs, const ft::queue<T,Container>& rhs){
				return	(lhs._container <= rhs._container);};
			friend bool operator>  (const ft::queue<T,Container>& lhs, const ft::queue<T,Container>& rhs){
				return	(lhs._container >  rhs._container);};
			friend bool operator>= (const ft::queue<T,Container>& lhs, const ft::queue<T,Container>& rhs){
				return	(lhs._container >= rhs._container);};
		protected:
			container_type	_container;
	};
};


#endif /* *********************************************************** QUEUE_H */