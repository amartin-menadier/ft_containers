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
/*			template <class InputIterator>
			list (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());
*/			//copy constructor(4)
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
					push_back(tocopy->_value);
					tocopy = tocopy->_next;
				}
				return *this;
			};
	
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
				iterator &operator++() {_ptr=_ptr->_next; return *this;};//++it
				iterator &operator--() {_ptr=_ptr->_prev; return *this;};//--it
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
*/			void assign (size_type n, const value_type& val)
			{
				clear();
				for (size_type i = 0; i < n; i++)
					push_back(val);
			};

			void	push_front(const T& val){insert(begin(), val);};
			void	pop_front(){erase(begin());};
			void	push_back(const T& val){insert(end(), val);};
			void	pop_back(){erase(--end());};
			//insert
				//single element (1)	
			iterator insert (iterator position, const value_type& val)
			{
				Node<T> *newNode = new Node<T>(position.getPtr()->_prev, position.getPtr(), val);
				position.getPtr()->_prev->_next = newNode;
				position.getPtr()->_prev = newNode;
				_size++;
				return iterator(--position);
			};
				//fill (2)	
    		void insert (iterator position, size_type n, const value_type& val)
			{
				for (size_type i = 0; i<n; i++) 
					insert(position, val);
			};
				//range (3)	
			//template <class InputIterator>
    		//oid insert (iterator position, InputIterator first, InputIterator last);
			iterator erase (iterator position)//fonctionne mal
			{
				position.getPtr()->_next->_prev = position.getPtr()->_prev;
				position.getPtr()->_prev->_next = position.getPtr()->_next;
				iterator ret(position.getPtr()->_next);
				delete position.getPtr();
				_size--;
				return ret;
			};
			iterator erase (iterator first, iterator last)//fonctionne mal
			{
				iterator it = first;
				while (it != last)
				{
					erase(it);
					it++;
				}
				return (last);
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
/*			//splice: element range (3)	
			void splice (iterator position, list& x, iterator first, iterator last);
*/

		private:
			allocator_type	_allocator;
			Node<T>			*_list;
			size_type		_size;

	};
}

template <typename T>
std::ostream &			operator<<( std::ostream & o, ft::list<T> const & i );

#endif /* ************************************************************ LIST_H */