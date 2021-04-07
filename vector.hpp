#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <string>

namespace ft
{
	template <typename T>
	class vector
	{
		public:
			typedef T					value_type;
			typedef size_t				size_type;
			typedef value_type			&reference;
			typedef const value_type	const_reference;

//ITERATORS
			class iterator
			{
				public:
				iterator():_ptr(NULL){};
				iterator(const iterator & src){_ptr = src._ptr;};
				iterator(T *ptr){_ptr = ptr;};
				bool operator==(const iterator &other) const {return _ptr == other._ptr;};
				bool operator!=(const iterator &other) const {return _ptr != other._ptr;};
				iterator &operator++(){_ptr++; return *this;};//++it
				iterator &operator--(){_ptr--; return *this;};//--it
				iterator operator++(int){iterator it(this->_ptr); this->_ptr++; return it;}; // it++
				iterator operator--(int){iterator it(this->_ptr);this->_ptr--; return it;}; // it--				
				T &operator*(){return *_ptr;};//dereferencing
				T *getPtr() const{return _ptr;};
				private:
					T	*_ptr;
			};
			class const_iterator
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

//CONSTRUCTORS
			//default constructor(1)
			explicit vector()
				:_vector(NULL), _size(0), _capacity(0){};
			//fill constructor(2)
			explicit vector(size_type n, const value_type& val = value_type())
				: _size(n), _capacity(n){
				_vector = new T[_capacity];
				for (size_type i = 0; i < n; i++){_vector[i] = val;}
			}; 
			//range constructor(3)
			vector(iterator first, iterator last)
				: _size(0)
			{
				while (first != last)
				{
					push_back(*first);
					first++;
				}
			};
			//copy constructor(4)
			vector(const vector& x): _size(x.size()), _capacity(x.capacity())
			{
				_vector = new T[x.capacity()];
				for (size_t i = 0; i < x.size(); i++)
					_vector[i] = x._vector[i];
			};

			vector& operator= (const vector& x)
			{
				clear();
				_size = x._size;
				_capacity = x._size;
				if (_vector)
					delete _vector;
				_vector = new T[_capacity];
				for (size_t i = 0; i < x.size(); i++)
					_vector[i] = x._vector[i];				
				return *this;
			};
			//Destructor
			~vector(){delete _vector;};
//ITERATORS
			iterator begin(){return iterator(_vector);}
			const_iterator begin() const{return const_iterator(_vector);};
			iterator end(){return iterator(_vector + _size);}
			const_iterator end() const{return const_iterator(_vector+_size);};
			reverse_iterator rbegin(){return reverse_iterator(_vector+_size-1);};
			const_reverse_iterator rbegin() const{return const_reverse_iterator(_vector+_size-1);};
			reverse_iterator rend(){return reverse_iterator(_vector-1);};
			const_reverse_iterator rend() const{return const_reverse_iterator(_vector-1);};
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
					vector copy(*this);
					delete _vector;
					_vector = new T[n];
					for (size_type i=0; i < n; i++)
						_vector[i] = copy[i];
				}
			};
//ELEMENT ACCESS
		    reference operator[] (size_type n){return *(_vector + n);};
			const_reference operator[] (size_type n) const{return *(_vector + n);};
			reference at (size_type n){return (*this)[n];};
			const_reference at (size_type n) const{return (*this)[n];};
			reference front(){return (*begin());};
			const_reference front() const {return (*begin());};
			reference back(){return *(_vector + _size - 1);};
			const_reference back() const{return *(_vector + _size - 1);};

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
			//insert: single element (1)	
			iterator insert (iterator position, const value_type& val)
			{
				size_type i = 0;
				vector copy(*this);
				for (iterator it = begin(); it != position; it++)
					i++;
				if (_size + 1 > _capacity)
				{
					if (!_capacity)
						_capacity = 1;
					while (_size + 1 > _capacity)
						_capacity *= 2;
					delete [] _vector;
					_vector = new T[_capacity];
				}
				size_type j = 0;
				for (; j != i; j++)
					_vector[j] = copy[j];
				_vector[i] = val;
				for (; j != _size; j++)
					_vector[j + 1] = copy[j];	
				_size++;			
				return iterator(&_vector[i]);
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
			void swap (vector& x)
			{
				std::swap(_size, x._size);
				std::swap(_vector, x._vector);
			};

		private:
			T				*_vector;
			size_type		_size;
			size_type		_capacity;

	};
};

// RELATIONAL OPERATORS
//==(1)	
template <class T>
bool operator== (const ft::vector<T>& lhs, const ft::vector<T>& rhs)
{
	if (lhs.size() != rhs.size())
		return false;
	typename ft::vector<T>::const_iterator itlhs = lhs.begin();
	typename ft::vector<T>::const_iterator itrhs = rhs.begin();
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
bool operator!= (const ft::vector<T>& lhs, const ft::vector<T>& rhs)
{
	if (lhs == rhs)
		return false;
	else
		return true;
};
//<(3)	
template <class T>
bool operator<(const ft::vector<T>& lhs, const ft::vector<T>& rhs)
{
	typename ft::vector<T>::const_iterator itlhs = lhs.begin();
	typename ft::vector<T>::const_iterator itrhs = rhs.begin();
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
bool operator<= (const ft::vector<T>& lhs, const ft::vector<T>& rhs)
{
	if (lhs < rhs || lhs == rhs)
		return true;
	else
		return false;
};
//>(5)	
template <class T>
bool operator>(const ft::vector<T>& lhs, const ft::vector<T>& rhs)
{
	if (!(lhs == rhs) && !(lhs < rhs))
		return true;
	else
		return false;
};
//>=(6)	
template <class T>
bool operator>= (const ft::vector<T>& lhs, const ft::vector<T>& rhs)
{
	if (!(lhs < rhs))
		return true;
	else
		return false;
};

template <class T>
void swap (ft::vector<T>& x, ft::vector<T>& y){x.swap(y);};

#endif /* ********************************************************** VECTOR_H */