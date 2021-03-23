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
		Key		first;
		T		second;
	};
	template <class Key, class T>
	struct Node{
		Node(pair<Key, T> pair): _pair(pair), _prev(NULL), _next(NULL){};
		pair<Key, T>	_pair;
		Node<Key, T>	*_prev;
		Node<Key, T>	*_next;		
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
				bool operator==(const iterator &other) const {return _ptr == other._ptr;};
				bool operator!=(const iterator &other) const {return _ptr != other._ptr;};
				iterator &operator++(){
					_ptr = _ptr->_next;
					setValues();
					return *this;};//++it
				iterator &operator--() {
					_ptr=_ptr->_prev;
					setValues();
					return *this;};//--it
				iterator operator++(int) {
					iterator it(this->_ptr);
					this->_ptr = this->_ptr->_next;
					setValues();
					return it;}; // it++
				iterator operator--(int) {
					iterator it(this->_ptr);
					this->_ptr = this->_ptr->_prev;
					setValues();
					return it;}; // it--				

				Node<Key, T> * getPtr() const{return _ptr;};
				void	setValues(){
					first = _ptr->_pair->first;
					second = _ptr->_pair->second;}
				private:
					Node<Key, T>	*_ptr;
					Key first;
					T	second;
			};
	/*		class const_iterator
			{
				public:
				const_iterator():_ptr(NULL){};
				const_iterator(const const_iterator &src){_ptr = src._ptr;};
				const_iterator(T *ptr){_ptr = ptr;};
				bool operator==(const const_iterator &other) const {return _ptr == other._ptr;};
				bool operator!=(const const_iterator &other) const {return _ptr != other._ptr;};
				const_iterator &operator++() {_ptr++; return *this;};//++it
				const_iterator &operator--() {_ptr--; return *this;};//--it
				const_iterator operator++(int) {const_iterator it(this->_ptr); this->_ptr++; return it;}; // it++
				const_iterator operator--(int) {const_iterator it(this->_ptr); this->_ptr--; return it;}; // it--			
				T &operator*() const{return *_ptr;};//dereferencing
				T *getPtr() const{return _ptr;};
				private:
					T	*_ptr;
			};
			class reverse_iterator
			{
				public:
				reverse_iterator():_ptr(NULL){};
				reverse_iterator(const reverse_iterator &src){_ptr = src._ptr;};
				reverse_iterator(T *ptr){_ptr = ptr;};
				bool operator==(const reverse_iterator &other) const {return _ptr == other._ptr;};
				bool operator!=(const reverse_iterator &other) const {return _ptr != other._ptr;};
				reverse_iterator &operator++() {_ptr--; return *this;};//++it
				reverse_iterator &operator--() {_ptr++; return *this;};//--it
				reverse_iterator operator++(int) {reverse_iterator it(this->_ptr); _ptr--; return it;};//it++
				reverse_iterator operator--(int) {reverse_iterator it(this->_ptr); _ptr++; return it;};//it--
				T	&operator*(){return *_ptr;};//dereferencing

				T * getPtr() const{return _ptr;};
				private:
					T	*_ptr;
			};
			class const_reverse_iterator
			{
				public:
				const_reverse_iterator():_ptr(NULL){};
				const_reverse_iterator(const const_reverse_iterator &src){_ptr = src._ptr;};
				const_reverse_iterator(T *ptr){_ptr = ptr;};
				bool operator==(const const_reverse_iterator &other) const {return _ptr == other._ptr;};
				bool operator!=(const const_reverse_iterator &other) const {return _ptr != other._ptr;};
				const_reverse_iterator &operator++(){_ptr--; return *this;};//++it
				const_reverse_iterator &operator--(){_ptr++; return *this;};//--it
				const_reverse_iterator operator++(int){const_reverse_iterator it(this->_ptr); _ptr--; return it;};//it++
				const_reverse_iterator operator--(int){const_reverse_iterator it(this->_ptr); _ptr++; return it;};//it--
				T	&operator*() const{return *_ptr;};//dereferencing

				T * getPtr() const{return _ptr;};
				private:
					T	*_ptr;
			};
*/
//CONSTRUCTORS
			//default constructor(1)
			explicit map (const key_compare& comp = key_compare())
				: _map(NULL), _comp(comp), _size(0){};
/*			//fill constructor(2)
			explicit map(size_type n, const value_type& val = value_type())
				: _size(n), _capacity(n){
				_map = new T[_capacity];
				for (size_type i = 0; i < n; i++){_map[i] = val;}
			};
			//range constructor(3)
			map(iterator first, iterator last)
				: _size(0)
			{
				while (first != last)
				{
					push_back(*first);
					first++;
				}
			};
			//copy constructor(4)
			map(const map& x): _size(x.size()), _capacity(x.capacity())
			{
				_map = new T[x.capacity()];
				for (size_t i = 0; i < x.size(); i++)
					_map[i] = x._map[i];
			};

			map& operator= (const map& x)
			{
				clear();
				_size = x._size;
				_capacity = x._size;
				if (_map)
					delete _map;
				_map = new T[_capacity];
				for (size_t i = 0; i < x.size(); i++)
					_map[i] = x._map[i];				
				return *this;
			};
			//Destructor
			~map(){delete _map;};
//ITERATORS
		*/	iterator begin(){return iterator(_map);}
		/*	const_iterator begin() const{return const_iterator(_map);};
		*/	iterator end(){return iterator(_map + _size);}
		/*	const_iterator end() const{return const_iterator(_map+_size);};
			reverse_iterator rbegin(){return reverse_iterator(_map+_size-1);};
			const_reverse_iterator rbegin() const{return const_reverse_iterator(_map+_size-1);};
			reverse_iterator rend(){return reverse_iterator(_map-1);};
			const_reverse_iterator rend() const{return const_reverse_iterator(_map-1);};
//CAPACITY
			size_type size() const{return _size;};
			size_type max_size() const
			{
				//size_type is always positive so -1 is the max
				return static_cast<size_type>(-1/sizeof(T));
			};
			void resize (size_type n, value_type val = value_type())
			{
				while (n > _size)
					push_back(val);
				while (n < _size)
					pop_back();
			};
			void clear(){resize(0);}
			size_type capacity() const{return _capacity;};
			bool empty() const{return !_size;};
			void reserve(size_type n){
				if (n <= _capacity)
					return;
				else
				{
					_capacity = n;
					map copy(*this);
					delete _map;
					_map = new T[n];
					for (size_type i=0; i < n; i++)
						_map[i] = copy[i];
				}
			};
//ELEMENT ACCESS
		    reference operator[] (size_type n){return *(_map + n);};
			const_reference operator[] (size_type n) const{return *(_map + n);};
			reference at (size_type n){return (*this)[n];};
			const_reference at (size_type n) const{return (*this)[n];};
			reference front(){return (*begin());};
			const_reference front() const {return (*begin());};
			reference back(){return *(_map + _size - 1);};
			const_reference back() const{return *(_map + _size - 1);};

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
*/			//single element (1)	
			pair<iterator,bool> insert (const value_type& val)
			{
				val.first;
				iterator it;
				(void)val;
			};
/*
with hint (2)	
iterator insert (iterator position, const value_type& val);
range (3)	
template <class InputIterator>
  void insert (InputIterator first, InputIterator last);

			//insert: single element (1)	
			iterator insert (iterator position, const value_type& val)
			{
				size_type i = 0;
				map copy(*this);
				for (iterator it = begin(); it != position; it++)
					i++;
				if (_size + 1 > _capacity)
				{
					if (!_capacity)
						_capacity = 1;
					while (_size + 1 > _capacity)
						_capacity *= 2;
					delete [] _map;
					_map = new T[_capacity];
				}
				size_type j = 0;
				for (; j != i; j++)
					_map[j] = copy[j];
				_map[i] = val;
				for (; j != _size; j++)
					_map[j + 1] = copy[j];	
				_size++;			
				return iterator(&_map[i]);
			};
			//insert: fill (2)	
   			void insert (iterator position, size_type n, const value_type& val)
			{
				for (size_type i = 0; i<n; i++) 
					insert(position, val);
			};
			//insert: range (3)	
    		void insert (iterator position, iterator first, iterator last)
			{
				while (first != last)
				{
					insert(position++, *first);
					first++;
				}
			};
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