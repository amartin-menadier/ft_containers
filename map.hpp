#ifndef MAP_HPP
# define MAP_HPP

# include <iostream>
# include <string>

namespace ft
{
	template <typename T>
	struct less{bool operator()(const T &a,const T &b) const{return (a < b);};};

	template <class Key, class T>
	struct pair{
		pair(Key first, T second): first(first), second(second){};
		pair():first(), second(){};
		const Key	first;
		T			second;
	};

	template <class Key, class T>
	struct Node{
		Node(pair<Key, T> pair): _pair(pair), _prev(NULL), _next(NULL){};
		Node(): _pair(), _prev(NULL), _next(NULL){};
		pair<Key, T>	_pair;
		Node<Key, T>	*_prev;
		Node<Key, T>	*_next;	
		char			_padding[9];//just there to get the same maxsize output
	};

	template <class Key, class T, class Compare = less<Key> >
	class map
	{
		public:
			typedef Key key_type;
			typedef T mapped_type;
			typedef ft::pair<key_type, mapped_type> value_type;
			typedef Compare key_compare;
			typedef size_t size_type;

//ITERATORS
			class iterator
			{
				public:
				iterator():_ptr(NULL){};
				iterator(const iterator & src){_ptr = src._ptr;};
				iterator(Node<Key, T> *ptr){_ptr = ptr;};
				bool operator==(const iterator &other) const{return _ptr==other._ptr;};
				bool operator!=(const iterator &other) const{return _ptr!=other._ptr;};
				iterator &operator++(){
					_ptr = _ptr->_next;
					return *this;};//++it
				iterator &operator--() {
					_ptr=_ptr->_prev;
					return *this;};//--it
				iterator operator++(int) {
					iterator it(this->_ptr);
					this->_ptr = this->_ptr->_next;
					return it;}; // it++
				iterator operator--(int) {
					iterator it(this->_ptr);
					this->_ptr = this->_ptr->_prev;
					return it;}; // it--
				pair<Key, T> *operator->(){
					if(_ptr)
						return &(_ptr->_pair);
					else
						return (NULL);};
				Node<Key, T> *getPtr() const{return _ptr;};
				private:
				Node<Key, T>	*_ptr;
			};
			class const_iterator
			{
				public:
				const_iterator():_ptr(NULL){};
				const_iterator(const const_iterator & src){_ptr = src._ptr;};
				const_iterator(Node<Key, T> *ptr){_ptr = ptr;};
				bool operator==(const const_iterator&other)const{return _ptr==other._ptr;};
				bool operator!=(const const_iterator&other)const{return _ptr!=other._ptr;};
				const_iterator &operator++(){
					_ptr = _ptr->_next;
					return *this;};//++it
				const_iterator &operator--() {
					_ptr=_ptr->_prev;
					return *this;};//--it
				const_iterator operator++(int) {
					const_iterator it(this->_ptr);
					this->_ptr = this->_ptr->_next;
					return it;}; // it++
				const_iterator operator--(int) {
					const_iterator it(this->_ptr);
					this->_ptr = this->_ptr->_prev;
					return it;}; // it--
				pair<Key, T> *operator->(){
					if(_ptr)
						return &(_ptr->_pair);
					else
						return (NULL);};
				Node<Key, T> *getPtr() const{return _ptr;};
				private:
				Node<Key, T>	*_ptr;
			};
			class reverse_iterator
			{
				public:
				reverse_iterator():_ptr(NULL){};
				reverse_iterator(const reverse_iterator & src){_ptr = src._ptr;};
				reverse_iterator(Node<Key, T> *ptr){_ptr = ptr;};
				bool operator==(const reverse_iterator &other) const{return _ptr==other._ptr;};
				bool operator!=(const reverse_iterator &other) const{return _ptr!=other._ptr;};
				reverse_iterator &operator++(){
					_ptr = _ptr->_prev;
					return *this;};//++it
				reverse_iterator &operator--() {
					_ptr=_ptr->_next;
					return *this;};//--it
				reverse_iterator operator++(int) {
					reverse_iterator it(this->_ptr);
					this->_ptr = this->_ptr->_prev;
					return it;}; // it++
				reverse_iterator operator--(int) {
					reverse_iterator it(this->_ptr);
					this->_ptr = this->_ptr->_next;
					return it;}; // it--
				pair<Key, T> *operator->(){
					if(_ptr)
						return &(_ptr->_pair);
					else
						return (NULL);};
				Node<Key, T> *getPtr() const{return _ptr;};
				private:
				Node<Key, T>	*_ptr;
			};
			class const_reverse_iterator
			{
				public:
				const_reverse_iterator():_ptr(NULL){};
				const_reverse_iterator(const const_reverse_iterator & src){_ptr = src._ptr;};
				const_reverse_iterator(Node<Key, T> *ptr){_ptr = ptr;};
				bool operator==(const const_reverse_iterator &other) const{return _ptr==other._ptr;};
				bool operator!=(const const_reverse_iterator &other) const{return _ptr!=other._ptr;};
				const_reverse_iterator &operator++(){
					_ptr = _ptr->_prev;
					return *this;};//++it
				const_reverse_iterator &operator--() {
					_ptr=_ptr->_next;
					return *this;};//--it
				const_reverse_iterator operator++(int) {
					const_reverse_iterator it(this->_ptr);
					this->_ptr = this->_ptr->_prev;
					return it;}; // it++
				const_reverse_iterator operator--(int) {
					const_reverse_iterator it(this->_ptr);
					this->_ptr = this->_ptr->_next;
					return it;}; // it--
				pair<Key, T> *operator->(){
					if(_ptr)
						return &(_ptr->_pair);
					else
						return (NULL);};
				Node<Key, T> *getPtr() const{return _ptr;};
				private:
				Node<Key, T>	*_ptr;
			};		
	
//CONSTRUCTORS
			//default constructor(1)
			explicit map (const key_compare& comp = key_compare())
				: _comp(comp), _size(0){
					_map = new Node<Key, T>();
					_map->_prev = _map;
					_map->_next = _map;
				};
			//range constructor(2)
			map(iterator first, iterator last, const key_compare& comp = key_compare())
				: _comp(comp), _size(0)
			{
				_map = new Node<Key, T>();
				_map->_prev = _map;
				_map->_next = _map;
				insert(first, last);
			};
			//copy constructor(3)
			map(const map& x): _comp(x._comp), _size(0)
			{
				_map = new Node<Key, T>();
				_map->_prev = _map;
				_map->_next = _map;
				insert(iterator(x._map->_next), iterator(x._map));
			};

			map& operator= (const map& x)
			{
				clear();
				_comp = x._comp;
				insert(iterator(x._map->_next), iterator(x._map));
			};

			//Destructor
			~map(){delete _map;};

//ITERATORS
			iterator begin(){return iterator(_map->_next);};
			const_iterator begin() const{return const_iterator(_map->_next);};
			iterator end(){return iterator(_map);};
			const_iterator end() const{return const_iterator(_map);};
			reverse_iterator rbegin(){return reverse_iterator(_map->_prev);};
			const_reverse_iterator rbegin() const{return const_reverse_iterator(_map->_prev);};
			reverse_iterator rend(){return reverse_iterator(_map);};
			const_reverse_iterator rend() const{return const_reverse_iterator(_map);};

//CAPACITY
			bool empty() const{return !_size;};
			size_type size() const{return _size;};
			size_type max_size() const{
				//size_type is always positive so -1 is the max
				return static_cast<size_type>(-1/sizeof(Node<Key, T>));
			};

//ELEMENT ACCESS
			mapped_type& operator[] (const key_type& k){
				iterator it = begin();
				while (it != end() && _comp(it->first, k))
					it++;
				if (it != end() && it->first == k)//element found
					return (it->second);
				else//element not found
					insert(pair<Key, T>(k, T()));
				return ((*this)[k]);
			};
/*
//MODIFIERS
			//assign: range (1)	
			void assign (iterator first, iterator last)
			{
				clear();
				while (first != last)
				{
					push_back(*first);
					first++;
				}
			};
			//assign: fill (2)	
			void assign (size_type n, const value_type& val)
			{
				clear();
				for (size_type i = 0; i < n; i++)
					push_back(val);
			};
			void	push_back(const T& val){insert(end(), val);};
			void	pop_back(){erase(--end());};
*/			
			//insert: single element (1)	
			pair<iterator,bool> insert (const value_type& val)
			{
				iterator it = begin();
				while (it != end() && _comp(it->first, val.first))
					it++;
				if (it != end() && it->first == val.first)//element found insert not done
					return (pair<iterator, bool>(it, false));
				else
				{
					_size++;
					Node<Key, T> *newNode = new Node<Key, T>(val);
					newNode->_next = it.getPtr();
					newNode->_prev = it.getPtr()->_prev;
					it.getPtr()->_prev->_next = newNode;
					it.getPtr()->_prev = newNode;
					return (pair<iterator, bool>(iterator(newNode), true));
				}
			};
/*
with hint (2)	
iterator insert (iterator position, const value_type& val);
*/			//insert: range (3)
			void insert (iterator first, iterator last){
				for (;first!=last; first++)
					insert(pair<Key, T>(first->first, first->second));
			};
			//erase(1)	
/*     void erase (iterator position);
(2)	
size_type erase (const key_type& k);
(3)	
     void erase (iterator first, iterator last);
*/
/*			


			iterator erase (iterator position)
			{
				iterator next;
				while(position != end())
				{
					next = iterator(position.getPtr() + 1);
					*position = *next;
					position = next;
				}
				_size--;
				return position;
			};
			iterator erase (iterator first, iterator last)
			{
				iterator it = first;
				while (it != last)
					it = erase(it);//returns iterator after the one erased
				return last;
			};
			void swap (map& x)
			{
				std::swap(_size, x._size);
				std::swap(_map, x._map);
			};
*/
			void clear(){
				Node<Key, T> *toErase = _map->_next;
				Node<Key, T> *next;
				while (toErase != _map)
				{
					next = toErase->_next;
					delete toErase;
					_size--;
					toErase = next;
				}
				_map->_next = _map;
				_map->_prev = _map;
			}
		private:
			Node<Key, T>	*_map;
			key_compare		_comp;
			size_type		_size;

	};
};
/*
// RELATIONAL OPERATORS
//==(1)	
template <class T>
bool operator== (const ft::map<T>& lhs, const ft::map<T>& rhs)
{
	if (lhs.size() != rhs.size())
		return false;
	typename ft::map<T>::const_iterator itlhs = lhs.begin();
	typename ft::map<T>::const_iterator itrhs = rhs.begin();
	while (itlhs != lhs.end() && itrhs != rhs.end())
	{
		if (*itrhs != *itlhs)
			return false;
		itrhs++;
		itlhs++;
	}
	if (itlhs == lhs.end() && itrhs == rhs.end())
		return true;
	else
		return false;
};
//!=(2)	
template <class T>
bool operator!= (const ft::map<T>& lhs, const ft::map<T>& rhs)
{
	if (lhs == rhs)
		return false;
	else
		return true;
};
//<(3)	
template <class T>
bool operator<(const ft::map<T>& lhs, const ft::map<T>& rhs)
{
	typename ft::map<T>::const_iterator itlhs = lhs.begin();
	typename ft::map<T>::const_iterator itrhs = rhs.begin();
	while (itlhs != lhs.end() && itrhs != rhs.end())
	{
		if (*itlhs < *itrhs)
			return true;
		if (*itlhs > *itrhs)
			return false;
		itrhs++;
		itlhs++;
	}
	if (itlhs == lhs.end() && itrhs != rhs.end())
		return true;
	else
		return false;
};
//<=(4)	
template <class T>
bool operator<= (const ft::map<T>& lhs, const ft::map<T>& rhs)
{
	if (lhs < rhs || lhs == rhs)
		return true;
	else
		return false;
};
//>(5)	
template <class T>
bool operator>(const ft::map<T>& lhs, const ft::map<T>& rhs)
{
	if (!(lhs == rhs) && !(lhs < rhs))
		return true;
	else
		return false;
};
//>=(6)	
template <class T>
bool operator>= (const ft::map<T>& lhs, const ft::map<T>& rhs)
{
	if (!(lhs < rhs))
		return true;
	else
		return false;
};

template <class T>
void swap (ft::map<T>& x, ft::map<T>& y){x.swap(y);};
*/
#endif /* ************************************************************* MAP_H */