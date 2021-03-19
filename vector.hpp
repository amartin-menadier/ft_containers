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
			typedef T			value_type;
			typedef size_t		size_type;
			typedef value_type	&reference;

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
				T	&operator*(){return *_ptr;};//dereferencing

				T * getPtr() const{return _ptr;};
				private:
					T	*_ptr;
			};
/*			class reverse_iterator
			{
				public:
				reverse_iterator():_ptr(NULL){};
				reverse_iterator(const reverse_iterator &src){_ptr = src._ptr;};
				reverse_iterator(T *ptr){_ptr = ptr;};
				bool operator==(const reverse_iterator &other) const {return _ptr == other._ptr;};
				bool operator!=(const reverse_iterator &other) const {return _ptr != other._ptr;};
				reverse_iterator &operator++() {_ptr=_ptr->_prev; return *this;};//++it
				reverse_iterator &operator--() {_ptr=_ptr->_next; return *this;};//--it
				reverse_iterator operator++(int) {reverse_iterator it(this->_ptr); this->_ptr = this->_ptr->_prev; return it;};//it++
				reverse_iterator operator--(int) {reverse_iterator it(this->_ptr); this->_ptr = this->_ptr->_next; return it;};//it--
				T	&operator*(){return _ptr->_element;};//dereferencing

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
				const_reverse_iterator &operator++(){_ptr=_ptr->_prev; return *this;};//++it
				const_reverse_iterator &operator--(){_ptr=_ptr->_next; return *this;};//--it
				const_reverse_iterator operator++(int){const_reverse_iterator it(this->_ptr); this->_ptr = this->_ptr->_prev; return it;};//it++
				const_reverse_iterator operator--(int){const_reverse_iterator it(this->_ptr); this->_ptr = this->_ptr->_next; return it;};//it--
				T	&operator*() const{return _ptr->_element;};//dereferencing

				T * getPtr() const{return _ptr;};
				private:
					T	*_ptr;
			};
			class const_iterator
			{
				public:
				const_iterator():_ptr(NULL){};
				const_iterator(const const_iterator & src){_ptr = src._ptr;};
				const_iterator(T *ptr){_ptr = ptr;};
				bool operator==(const const_iterator &other) const {return _ptr == other._ptr;};
				bool operator!=(const const_iterator &other) const {return _ptr != other._ptr;};
				const_iterator &operator++() {_ptr=_ptr->_next; return *this;};//++it
				const_iterator &operator--() {_ptr=_ptr->_prev; return *this;};//--it
				const_iterator operator++(int) {const_iterator it(this->_ptr); this->_ptr = this->_ptr->_next; return it;}; // it++
				const_iterator operator--(int) {const_iterator it(this->_ptr); this->_ptr = this->_ptr->_prev; return it;}; // it--				
				T	&operator*() const{return _ptr->_element;};//dereferencing

				T * getPtr() const{return _ptr;};
				private:
					T	*_ptr;
			};
*/

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
/*
			vector& operator= (const vector& x)
			{
				clear();
				T *tocopy = x._vector->_next;
				while (tocopy != x._vector)
				{
					push_back(tocopy->_element);
					tocopy = tocopy->_next;
				}
				return *this;
			};
*/			//Destructor
			~vector(){delete _vector;};

//CAPACITY
			size_type size() const{return _size;};
			size_type max_size() const
			{
				//size_type is always positive so -1 is the max
				return static_cast<size_type>(-1/sizeof(T));
			};
	/*		void resize (size_type n, value_type val = value_type())
			{
				while (n > _size)
					push_back(val);
				while (n < _size)
					pop_back();
			};
			void clear(){resize(0);}
	*/		size_type capacity() const{return _capacity;};
			bool empty() const{return !_size;};

//ITERATORS
			iterator begin(){return iterator(_vector);}
	//		const_iterator begin() const{return const_iterator(_vector->_next);};
			iterator end(){return iterator(_vector + _size);}
	/*		const_iterator end() const{return const_iterator(_vector);};
			reverse_iterator rbegin(){return reverse_iterator(_vector->_prev);};
			const_reverse_iterator rbegin() const;
			reverse_iterator rend(){return reverse_iterator(_vector);};
			const_reverse_iterator rend() const;
//ELEMENT ACCESS
*/		    reference operator[] (size_type n){return *(_vector + n);};
/*			const_reference operator[] (size_type n) const;
			reference front(){return (*begin());};
			const_reference front() const {return (*begin());};
			reference back(){return _vector->_prev->_element;};
			const_reference back() const{return _vector->_prev->_element;};

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

			void	push_front(const T& val){insert(begin(), val);};
			void	pop_front(){erase(begin());};
*/			void	push_back(const T& val){insert(end(), val);};
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
 /*   		void insert (iterator position, size_type n, const value_type& val)
			{
				for (size_type i = 0; i<n; i++) 
					insert(position, val);
			};
			//insert: range (3)	
    		void insert (iterator position, iterator first, iterator last)
			{
				while (first != last)
				{
					insert(position, *first);
					first++;
				}
			};
*/			iterator erase (iterator position)
			{
				while(*position)
					*position = *(++position);
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
/*			void swap (vector& x)
			{
				std::swap(_size, x._size);
				std::swap(_vector, x._vector);
			};


//OPERATIONS
			//splice: entire vector (1)	
			void splice (iterator position, vector& x)
			{
				while(x._size)
					splice(position, x, x.begin());
			};
			//splice: single element (2)	
			void splice (iterator position, vector& x, iterator i)
			{
				i.getPtr()->_prev->_next = i.getPtr()->_next;
				i.getPtr()->_next->_prev = i.getPtr()->_prev;
				x._size--;
				position.getPtr()->_prev->_next = i.getPtr();
				i.getPtr()->_prev = position.getPtr()->_prev;
				position.getPtr()->_prev = i.getPtr();
				i.getPtr()->_next = position.getPtr();
				_size++;
			};
			//splice: element range (3)	
			void splice (iterator position, vector& x, iterator first, iterator last){
				while (first != last)
				{
					iterator next = first.getPtr()->_next;
					splice(position, x, first);
					first = next;
				}
			};
			void remove (const value_type& val)
			{
				iterator it = begin();
				while (it != end())
				{
					iterator next = iterator(it.getPtr()->_next);
					if (*it == val)
						erase(it);
					it = next;
				}
			};
			template <class Predicate>//Predicate ≃ bool function
			void remove_if (Predicate pred){
				iterator it = begin();
				iterator next;
				while(it != end())
				{
					next = it.getPtr()->_next;
					if (pred(*it))
						erase(it);
					it = next;
				}
			};
			//unique (1)	
			void unique()
			{
				iterator it = _vector->_next->_next;
				iterator prev = begin();
				iterator next;
				while (it != end())
				{
					next = iterator (it.getPtr()->_next);
					if (*prev == *it)
						erase(it);
					else
						prev = it;
					it = next;
				}
			};
			//unique (2)	
			template <class BinaryPredicate>//bool function with two args
  			void unique (BinaryPredicate binary_pred)
			{
				iterator it = ++begin();
				iterator prev;
				iterator next;
				while (it != end())
				{
					next = iterator (it.getPtr()->_next);
					prev = iterator (it.getPtr()->_prev);
					if (binary_pred(*prev, *it))
						erase(it);
					else
						prev = it;
					it = next;
				}
			};
			//merge (1)	
			void merge (vector& x){splice(begin(), x);};
			//merge (2)	
			template <class Compare>//bool function comparing two elements
			void merge (vector& x, Compare comp){//to use with sorted vectors
				if (&x == this)
					return;
				iterator it = begin();
				iterator itX = x.begin();
				iterator xNext;
				while (itX != x.end())
				{
					while (it != end())
					{
						if (comp(*itX, *it))
						{
							xNext = iterator (itX.getPtr()->_next);
							splice(it, x, itX);
							itX = xNext;
						}
						else
							it++;
					}
					xNext = iterator (itX.getPtr()->_next);
					splice(it, x, itX);
					itX = xNext;
				}
			};

			//sort (1)
			void sort() {
				T *a = _vector->_next;
				T *b = a->_next;
				T *bef;
				T *aft;
				while (b != _vector)
				{	// bef -> a -> b -> aft
					if (b->_element < a->_element) 
					{
						bef = a->_prev;
						aft = b->_next;
						// link bef -> b
						bef->_next = b;
						b->_prev = bef;
						// link b -> a
						b->_next = a;
						a->_prev = b;
						// link a-> aft
						a->_next = aft;
						aft->_prev = a;
						// retun to begin
						a = _vector->_next;
						b = a->_next;
					} 
					else 
					{
						a = a->_next;
						b = b->_next;
					}
				}
			}
			//sort (2)	
			template <class Compare>
			void sort (Compare comp){
				T *a = _vector->_next;
				T *b = a->_next;
				T *bef;
				T *aft;
				while (b != _vector)
				{	// bef -> a -> b -> aft
					if (comp(b->_element, a->_element)) 
					{
						bef = a->_prev;
						aft = b->_next;
						// link bef -> b
						bef->_next = b;
						b->_prev = bef;
						// link b -> a
						b->_next = a;
						a->_prev = b;
						// link a-> aft
						a->_next = aft;
						aft->_prev = a;
						// retun to begin
						a = _vector->_next;
						b = a->_next;
					} 
					else 
					{
						a = a->_next;
						b = b->_next;
					}
				}				
			};
			void reverse() {
				T *cur = _vector->_next;
				T *next;
				T *tmp;

				while (cur != _vector)
				{
					next = cur->_next;
					//swap a->_next and a->_prev 
					tmp = cur->_next;
					cur->_next = cur->_prev;
					cur->_prev = tmp;
					//go to next node
					cur = next;
				}
				// swap dernier node
				tmp = cur->_next;
				cur->_next = cur->_prev;
				cur->_prev = tmp;
			}

*/
		private:
			T				*_vector;
			size_type		_size;
			size_type		_capacity;

	};
};
/*
// RELATIONAL OPERATORS
//==(1)	
template <class T, class Alloc>
bool operator== (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
{
	if (lhs.size() != rhs.size())
		return false;
	typename ft::vector<T,Alloc>::const_iterator itlhs = lhs.begin();
	typename ft::vector<T,Alloc>::const_iterator itrhs = rhs.begin();
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
template <class T, class Alloc>
bool operator!= (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
{
	if (lhs == rhs)
		return false;
	else
		return true;
};
//<(3)	
template <class T, class Alloc>
bool operator<(const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
{
	typename ft::vector<T,Alloc>::const_iterator itlhs = lhs.begin();
	typename ft::vector<T,Alloc>::const_iterator itrhs = rhs.begin();
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
template <class T, class Alloc>
bool operator<= (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
{
	if (lhs < rhs || lhs == rhs)
		return true;
	else
		return false;
};
//>(5)	
template <class T, class Alloc>
bool operator>(const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
{
	if (!(lhs == rhs) && !(lhs < rhs))
		return true;
	else
		return false;
};
//>=(6)	
template <class T, class Alloc>
bool operator>= (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
{
	if (!(lhs < rhs))
		return true;
	else
		return false;
};

template <class T, class Alloc>
void swap (ft::vector<T,Alloc>& x, ft::vector<T,Alloc>& y){x.swap(y);};*/

#endif /* ********************************************************** VECTOR_H */