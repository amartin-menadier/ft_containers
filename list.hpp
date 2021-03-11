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
			: _prev(prev), _next(next), _value(value){}
		Node<T>	*_prev;
		Node<T>	*_next;
		T		_value;
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

//CONSTRUCTORS
			//default(1)
			explicit list (const allocator_type& alloc = allocator_type())
				: _allocator(alloc), _size(0)
			{
				_list = new Node<T>(NULL, NULL, value_type());
				_list->_next = _list;
				_list->_prev = _list;
			};
			//fill(2)
			explicit list (size_type n, const value_type& val = value_type(),const allocator_type& alloc = allocator_type())
				: _allocator(alloc), _size(n)
			{
				_list = new Node<T>(NULL, NULL, value_type());
				_list->_next = _list;
				_list->_prev = _list;
				for (size_type i = 0; i < n; i++)
					push_front(val);
			};
			//range (3)	
/*			template <class InputIterator>
			list (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());
			//copy(4)
			list (const list& x){*this = x;};
*/
		//	list& operator= (const list& x);
	
			//Destructor
			~list(){delete _list;};

//ITERATORS
			class iterator
			{
				public:
				iterator():_ptr(NULL){};
				iterator(const iterator & src){_ptr = src._ptr;};
				iterator(Node<T> *ptr){_ptr = ptr;};
			//	bool operator==(const iterator &other) const {return _ptr== other._ptr;};
				bool operator!=(const iterator &other) const {return _ptr!= other._ptr;};
				iterator &operator++() {_ptr = _ptr->_next; return *this;};//++i
				iterator &operator--() {_ptr = _ptr->_prev; return *this;};//--i
				iterator operator++(int) { iterator it(this->_ptr); this->_ptr = this->_ptr->_next; return it; }; // it++
				iterator operator--(int) { iterator it(this->_ptr); this->_ptr = this->_ptr->_prev; return it; }; // it--				
				T	&operator*(){return _ptr->_value;};//dereferencing

				Node<T> * getPtr() const{return _ptr;};
				private:
					Node<T>	*_ptr;
			};
			iterator begin(){return iterator(_list->_next);}
			//const_iterator begin() const;
			iterator end(){return iterator(_list);}
			//const_iterator end() const;
			//reverse_iterator rbegin();
			//const_reverse_iterator rbegin() const;
			//reverse_iterator rend();
			//const_reverse_iterator rend() const;

//CAPACITY
			bool empty() const{return !_size;};
			size_type size() const{return _size;};
			size_type max_size() const
			{
				//size_type is always positive so -1 is the max
				return static_cast<size_type>(-1/sizeof(Node<T>));
			};

//ELEMENT ACCESS
			reference front(){return (*begin());};
			const_reference front() const {return (*begin());};
			reference back(){return _list->_prev->_value;};
			const_reference back() const{return _list->_prev->_value;};

//MODIFIERS
			//assign
			//range (1)	
	/*		template <class InputIterator>
			void assign (InputIterator first, InputIterator last);
			//fill (2)	
			void assign (size_type n, const value_type& val)
			{

			};
*/

			iterator erase (iterator position)
			{
// A MODIFIER
				iterator ret = position;
				ret++;
				position.getPtr()->_next->_prev = position.getPtr()->_prev;
				position.getPtr()->_prev->_next = position.getPtr()->_next;
				delete position.getPtr();
				_size--;
				return ret;
			};
			iterator erase (iterator first, iterator last)
			{
				iterator it;
				for (it = first; it != last; it++)
					erase(it);
				return (it);
			};

			void clear(){erase(begin(), end());}
			//Member functions
			void	push_front(const T& value)
			{
				Node<T> *front = new Node<T>(_list, _list->_next, value);
				_list->_next->_prev = front;
				_list->_next = front;
				_size++;
			}

			void	push_back(const T& value)
			{
				Node<T> *last = new Node<T>(_list->_prev, _list, value);
				_list->_prev->_next = last;
				_list->_prev = last;
				_size++;				
			}

		private:
			allocator_type	_allocator;
			Node<T>			*_list;
			size_type		_size;

/*
--> Member types:

	iterator	a bidirectional iterator to value_type	convertible to const_iterator
	const_iterator	a bidirectional iterator to const value_type	
	reverse_iterator	reverse_iterator<iterator>	
	const_reverse_iterator	reverse_iterator<const_iterator>	
	difference_type	a signed integral type, identical to: iterator_traits<iterator>::difference_type	usually the same as ptrdiff_t
	size_type	an unsigned integral type that can represent any non-negative value of difference_type	usually the same as size_t

--> Member functions
	Iterators:
		begin 
			Return iterator to beginning (public member function )
		end
			Return iterator to end (public member function )
		rbegin
			Return reverse iterator to reverse beginning (public member function )
		rend
			Return reverse iterator to reverse end (public member function )

	Capacity:
		empty
			Test whether container is empty (public member function )
		size
			Return size (public member function )
		max_size
			Return maximum size (public member function )

	Element access:
		front
			Access first element (public member function )
		back
			Access last element (public member function )

	Modifiers:
		assign
			Assign new content to container (public member function )
		push_front
			Insert element at beginning (public member function )
		pop_front
			Delete first element (public member function )
		push_back
			Add element at the end (public member function )
		pop_back
			Delete last element (public member function )
		insert
			Insert elements (public member function )
				single element (1)	
					iterator insert (iterator position, const value_type& val);
				fill (2)	
    				void insert (iterator position, size_type n, const value_type& val);
				range (3)	
					template <class InputIterator>
    				void insert (iterator position, InputIterator first, InputIterator last);
		erase
			Erase elements (public member function )
		swap
			Swap content (public member function )
		resize
			Change size (public member function )
		clear
			Clear content (public member function )

	Operations:
		splice
			Transfer elements from list to list (public member function )
		remove
			Remove elements with specific value (public member function )
		remove_if
			Remove elements fulfilling condition (public member function template )
		unique
			Remove duplicate values (public member function )
		merge
			Merge sorted lists (public member function )
		sort
			Sort elements in container (public member function )
		reverse
			Reverse the order of elements (public member function )

--> Non-member function overloads
	relational operators (list)
		Relational operators for list (function )
	swap (list)
		Exchanges the contents of two lists (function template )
*/


	};
}

template <typename T>
std::ostream &			operator<<( std::ostream & o, ft::list<T> const & i );

#endif /* ************************************************************ LIST_H */