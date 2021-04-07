#ifndef LIST_HPP
# define LIST_HPP

# include <iostream>
# include <string>

namespace ft
{
	template <typename T>
	struct Node
	{
		Node(Node<T> *prev, Node<T> *next, const T &value)
			: _prev(prev), _next(next), _element(value){}
		Node<T>	*_prev;
		Node<T>	*_next;
		T		_element;
	};

	template <typename T, class Alloc = std::allocator<T> >
	class list
	{
		
		public:

			typedef T								value_type;
			typedef Alloc							allocator_type;
			typedef typename Alloc::reference		reference;
			typedef typename Alloc::const_reference	const_reference;
			typedef typename Alloc::pointer			pointer;
			typedef typename Alloc::const_pointer	const_pointer;

			typedef typename Alloc::size_type		size_type;

//ITERATORS
			class iterator
			{
				public:
				iterator():_ptr(NULL){};
				iterator(const iterator & src){_ptr = src._ptr;};
				iterator(Node<T> *ptr){_ptr = ptr;};
				bool operator==(const iterator &other) const {return _ptr == other._ptr;};
				bool operator!=(const iterator &other) const {return _ptr != other._ptr;};
				iterator &operator++() {_ptr=_ptr->_next; return *this;};//++it
				iterator &operator--() {_ptr=_ptr->_prev; return *this;};//--it
				iterator operator++(int) {iterator it(this->_ptr); this->_ptr = this->_ptr->_next; return it;}; // it++
				iterator operator--(int) {iterator it(this->_ptr); this->_ptr = this->_ptr->_prev; return it;}; // it--				
				T	&operator*(){return _ptr->_element;};//dereferencing

				Node<T> * getPtr() const{return _ptr;};
				private:
					Node<T>	*_ptr;
			};
			class reverse_iterator
			{
				public:
				reverse_iterator():_ptr(NULL){};
				reverse_iterator(const reverse_iterator &src){_ptr = src._ptr;};
				reverse_iterator(Node<T> *ptr){_ptr = ptr;};
				bool operator==(const reverse_iterator &other) const {return _ptr == other._ptr;};
				bool operator!=(const reverse_iterator &other) const {return _ptr != other._ptr;};
				reverse_iterator &operator++() {_ptr=_ptr->_prev; return *this;};//++it
				reverse_iterator &operator--() {_ptr=_ptr->_next; return *this;};//--it
				reverse_iterator operator++(int) {reverse_iterator it(this->_ptr); this->_ptr = this->_ptr->_prev; return it;};//it++
				reverse_iterator operator--(int) {reverse_iterator it(this->_ptr); this->_ptr = this->_ptr->_next; return it;};//it--
				T	&operator*(){return _ptr->_element;};//dereferencing

				Node<T> * getPtr() const{return _ptr;};
				private:
					Node<T>	*_ptr;
			};
			class const_reverse_iterator
			{
				public:
				const_reverse_iterator():_ptr(NULL){};
				const_reverse_iterator(const const_reverse_iterator &src){_ptr = src._ptr;};
				const_reverse_iterator(Node<T> *ptr){_ptr = ptr;};
				bool operator==(const const_reverse_iterator &other) const {return _ptr == other._ptr;};
				bool operator!=(const const_reverse_iterator &other) const {return _ptr != other._ptr;};
				const_reverse_iterator &operator++(){_ptr=_ptr->_prev; return *this;};//++it
				const_reverse_iterator &operator--(){_ptr=_ptr->_next; return *this;};//--it
				const_reverse_iterator operator++(int){const_reverse_iterator it(this->_ptr); this->_ptr = this->_ptr->_prev; return it;};//it++
				const_reverse_iterator operator--(int){const_reverse_iterator it(this->_ptr); this->_ptr = this->_ptr->_next; return it;};//it--
				T	&operator*() const{return _ptr->_element;};//dereferencing

				Node<T> * getPtr() const{return _ptr;};
				private:
					Node<T>	*_ptr;
			};
			class const_iterator
			{
				public:
				const_iterator():_ptr(NULL){};
				const_iterator(const const_iterator & src){_ptr = src._ptr;};
				const_iterator(Node<T> *ptr){_ptr = ptr;};
				bool operator==(const const_iterator &other) const {return _ptr == other._ptr;};
				bool operator!=(const const_iterator &other) const {return _ptr != other._ptr;};
				const_iterator &operator++() {_ptr=_ptr->_next; return *this;};//++it
				const_iterator &operator--() {_ptr=_ptr->_prev; return *this;};//--it
				const_iterator operator++(int) {const_iterator it(this->_ptr); this->_ptr = this->_ptr->_next; return it;}; // it++
				const_iterator operator--(int) {const_iterator it(this->_ptr); this->_ptr = this->_ptr->_prev; return it;}; // it--				
				T	&operator*() const{return _ptr->_element;};//dereferencing

				Node<T> * getPtr() const{return _ptr;};
				private:
					Node<T>	*_ptr;
			};


//CONSTRUCTORS
			//default constructor(1)
			explicit list (const allocator_type& alloc = allocator_type())
				: _allocator(alloc), _size(0)
			{
				_list = new Node<T>(NULL, NULL, value_type());
				_list->_next = _list;
				_list->_prev = _list;

			};
			//fill constructor(2)
			explicit list (size_type n, const value_type& val = value_type(),const allocator_type& alloc = allocator_type())
				: _allocator(alloc), _size(0)
			{
				_list = new Node<T>(NULL, NULL, value_type());
				_list->_next = _list;
				_list->_prev = _list;
				for (size_type i = 0; i < n; i++)
					push_front(val);
			};
			//range constructor(3)
			list (iterator first, iterator last, const allocator_type& alloc = allocator_type()) : _allocator(alloc), _size(0)
			{
				_list = new Node<T>(NULL, NULL, value_type());
				_list->_next = _list;
				_list->_prev = _list;
				while (first != last)
				{
					push_back(*first);
					first++;
				}
			};
			//copy constructor(4)
			list (const list& x) : _allocator(x._allocator), _size(0)
			{
				_list = new Node<T>(NULL, NULL, value_type());
				_list->_next = _list;
				_list->_prev = _list;
				*this = x;
			};

			list& operator= (const list& x)
			{
				clear();
				Node<T> *tocopy = x._list->_next;
				while (tocopy != x._list)
				{
					push_back(tocopy->_element);
					tocopy = tocopy->_next;
				}
				return *this;
			};
			//Destructor
			~list(){delete _list;};

//CAPACITY
			bool empty() const{return !_size;};
			size_type size() const{return _size;};
			size_type max_size() const
			{
				//size_type is always positive so -1 is the max
				return static_cast<size_type>(-1/sizeof(Node<T>));
			};
//ITERATORS
			iterator begin(){return iterator(_list->_next);}
			const_iterator begin() const{return const_iterator(_list->_next);};
			iterator end(){return iterator(_list);}
			const_iterator end() const{return const_iterator(_list);};
			reverse_iterator rbegin(){return reverse_iterator(_list->_prev);};
			const_reverse_iterator rbegin() const{return const_reverse_iterator(_list->_prev);};
			reverse_iterator rend(){return reverse_iterator(_list);};
			const_reverse_iterator rend() const{return const_reverse_iterator(_list);};
//ELEMENT ACCESS
			reference front(){return (*begin());};
			const_reference front() const {return (*begin());};
			reference back(){return _list->_prev->_element;};
			const_reference back() const{return _list->_prev->_element;};

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
			void	push_back(const T& val){insert(end(), val);};
			void	pop_back(){erase(--end());};
			//insert: single element (1)	
			iterator insert (iterator position, const value_type& val)
			{
				Node<T> *newNode = new Node<T>(position.getPtr()->_prev, position.getPtr(), val);
				position.getPtr()->_prev->_next = newNode;
				position.getPtr()->_prev = newNode;
				_size++;
				return iterator(--position);
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
					insert(position, *first);
					first++;
				}
			};
			iterator erase (iterator position)
			{
				position.getPtr()->_next->_prev = position.getPtr()->_prev;
				position.getPtr()->_prev->_next = position.getPtr()->_next;
				iterator ret;
				ret = iterator(position.getPtr()->_next);
				delete position.getPtr();
				_size--;
				return ret;
			};
			iterator erase (iterator first, iterator last)
			{
				iterator it = first;
				while (it != last)
					it = erase(it);//returns iterator after the one erased
				return last;
			};
			void swap (list& x)
			{
				std::swap(_size, x._size);
				std::swap(_list, x._list);
			};
			void resize (size_type n, value_type val = value_type())
			{
				while (n > _size)
					push_back(val);
				while (n < _size)
					pop_back();
			};
			void clear(){resize(0);}

//OPERATIONS
			//splice: entire list (1)	
			void splice (iterator position, list& x)
			{
				while(x._size)
					splice(position, x, x.begin());
			};
			//splice: single element (2)	
			void splice (iterator position, list& x, iterator i)
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
			void splice (iterator position, list& x, iterator first, iterator last){
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
				iterator it = _list->_next->_next;
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
			void merge (list& x){splice(begin(), x);};
			//merge (2)	
			template <class Compare>//bool function comparing two elements
			void merge (list& x, Compare comp){//to use with sorted lists
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
				Node<T> *a = _list->_next;
				Node<T> *b = a->_next;
				Node<T> *bef;
				Node<T> *aft;
				while (b != _list)
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
						a = _list->_next;
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
				Node<T> *a = _list->_next;
				Node<T> *b = a->_next;
				Node<T> *bef;
				Node<T> *aft;
				while (b != _list)
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
						a = _list->_next;
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
				Node<T> *cur = _list->_next;
				Node<T> *next;
				Node<T> *tmp;

				while (cur != _list)
				{
					next = cur->_next;
					/*swap a->_next and a->_prev */
					tmp = cur->_next;
					cur->_next = cur->_prev;
					cur->_prev = tmp;
					/*go to next node*/
					cur = next;
				}
				// swap dernier node
				tmp = cur->_next;
				cur->_next = cur->_prev;
				cur->_prev = tmp;
			}


		private:
			allocator_type	_allocator;
			Node<T>			*_list;
			size_type		_size;

	};
};

// RELATIONAL OPERATORS
//==(1)	
template <class T, class Alloc>
bool operator== (const ft::list<T,Alloc>& lhs, const ft::list<T,Alloc>& rhs)
{
	if (lhs.size() != rhs.size())
		return false;
	typename ft::list<T,Alloc>::const_iterator itlhs = lhs.begin();
	typename ft::list<T,Alloc>::const_iterator itrhs = rhs.begin();
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
bool operator!= (const ft::list<T,Alloc>& lhs, const ft::list<T,Alloc>& rhs)
{
	if (lhs == rhs)
		return false;
	else
		return true;
};
//<(3)	
template <class T, class Alloc>
bool operator<(const ft::list<T,Alloc>& lhs, const ft::list<T,Alloc>& rhs)
{
	typename ft::list<T,Alloc>::const_iterator itlhs = lhs.begin();
	typename ft::list<T,Alloc>::const_iterator itrhs = rhs.begin();
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
bool operator<= (const ft::list<T,Alloc>& lhs, const ft::list<T,Alloc>& rhs)
{
	if (lhs < rhs || lhs == rhs)
		return true;
	else
		return false; 
};
//>(5)	
template <class T, class Alloc>
bool operator>(const ft::list<T,Alloc>& lhs, const ft::list<T,Alloc>& rhs)
{
	if (!(lhs == rhs) && !(lhs < rhs))
		return true;
	else
		return false;
};
//>=(6)	
template <class T, class Alloc>
bool operator>= (const ft::list<T,Alloc>& lhs, const ft::list<T,Alloc>& rhs)
{
	if (!(lhs < rhs))
		return true;
	else
		return false;
};

template <class T, class Alloc>
void swap (ft::list<T,Alloc>& x, ft::list<T,Alloc>& y){x.swap(y);};

#endif /* ************************************************************ LIST_H */