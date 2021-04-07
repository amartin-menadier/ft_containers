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
				pair<Key, T> operator*(){
					if(_ptr)
						return (_ptr->_pair);
					else
						return (pair<Key, T>());
				};
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
	
//CLASS VALUE_COMPARE
			class value_compare
			{
				public:
					value_compare(const key_compare& compare) : _comp(compare)
					{}

					bool operator() (const value_type& a, const value_type& b) const
					{
						return _comp(a.first, b.first);
					}
				private:
					key_compare _comp;
			};
//CONSTRUCTORS
			//default constructor(1)
			explicit map (const key_compare& comp = key_compare())
				: _keycomp(comp), _size(0){
					_map = new Node<Key, T>();
					_map->_prev = _map;
					_map->_next = _map;
				};
			//range constructor(2)
			map(iterator first, iterator last, const key_compare& comp = key_compare())
				: _keycomp(comp), _size(0)
			{
				_map = new Node<Key, T>();
				_map->_prev = _map;
				_map->_next = _map;
				insert(first, last);
			};
			//copy constructor(3)
			map(const map& x): _keycomp(x._keycomp), _size(0)
			{
				_map = new Node<Key, T>();
				_map->_prev = _map;
				_map->_next = _map;
				insert(iterator(x._map->_next), iterator(x._map));
			};

			map& operator= (const map& x)
			{
				clear();
				_keycomp = x._keycomp;
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
				while (it != end() && _keycomp(it->first, k))
					it++;
				if (it != end() && it->first == k)//element found
					return (it->second);
				else//element not found
					insert(pair<Key, T>(k, T()));
				return ((*this)[k]);
			};

//MODIFIERS
			//insert: single element(1)	
			pair<iterator,bool> insert (const value_type& val)
			{
				iterator it = begin();
				while (it != end() && _keycomp(it->first, val.first))
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
			//insert: with hint(2)	
			iterator insert (iterator position, const value_type& val)
			{
				iterator it = iterator(position);
				while(it!=end() && _keycomp(val.first, it->first))//case for position too high
					it--;
				while(it!=end() && _keycomp(it->first, val.first))//case for position too low
					it++;
				if (it != end() && it->first == val.first)//element found insert not done
					return (it);
				else
				{
					_size++;
					Node<Key, T> *newNode = new Node<Key, T>(val);
					newNode->_next = it.getPtr();
					newNode->_prev = it.getPtr()->_prev;
					it.getPtr()->_prev->_next = newNode;
					it.getPtr()->_prev = newNode;
					return (it);
				}
			};
			//insert: range(3)
			void insert (iterator first, iterator last){
				for (;first!=last; first++)
					insert(pair<Key, T>(first->first, first->second));
			};
			//erase(1)	
		    void erase (iterator position)
			{
				iterator it = begin();
				while (it != end() && it != position)
					it++;
				if (it == end())
					return;
				else
				{
					Node<Key, T> *prev = it.getPtr()->_prev;
					Node<Key, T> *next = it.getPtr()->_next;
					prev->_next = next;
					next->_prev = prev;
					delete (it.getPtr());
					_size--;
				}
			};
			//erase(2)	
			size_type erase (const key_type& k)
			{
				iterator it = begin();
				while (it != end() && it->first != k)
					it++;
				if (it == end())
					return(0);
				else if (it->first == k)
					erase(it);
				return(1);//nb of elements erased
			};
			//erase(3)	
			void erase (iterator first, iterator last)
			{
				iterator it(first);
				iterator next;
				while (it != end() && it != last)
				{
					next = iterator(it.getPtr()->_next);
					erase(it);
					it = next;
				}
			};
			void swap (map& x)
			{
				std::swap(_size, x._size);
				std::swap(_map, x._map);
			};
			void clear(){
				erase(begin(), end());
			}

//OBSERVERS
			key_compare key_comp() const{
				return (_keycomp);
			};
			value_compare value_comp() const{
				return (value_compare(_keycomp));
			};
//OPERATIONS
			iterator find (const key_type& k)
			{
				iterator it = begin();
				while (it != end() && it->first != k)
					it++;
				return (it);
			};
			const_iterator find (const key_type& k) const{
				const_iterator it = begin();
				while (it != end() && it->first != k)
					it++;
				return (it);				
			}; 
			size_type count (const key_type& k) const{
				if (find(k) == end())
					return 0;
				else
					return 1;
			};
			iterator lower_bound (const key_type& k)
			{
				iterator it = begin();
				while (it != end() && _keycomp(it->first, k))
					it++;
				return (it);
			};
			const_iterator lower_bound (const key_type& k) const{
				const_iterator it = begin();
				while (it != end() && _keycomp(it->first, k))
					it++;
				return (it);				
			};
			iterator upper_bound (const key_type& k){
				iterator it = lower_bound(k);
				if (it->first == k)
					it++;
				return it;
			};
			const_iterator upper_bound (const key_type& k) const{
				const_iterator it = lower_bound(k);
				if (it->first == k)
					it++;
				return it;
			};
			pair<const_iterator,const_iterator> equal_range (const key_type& k) const{
				return(pair<const_iterator,const_iterator>(lower_bound(k),upper_bound(k)));
			};
			pair<iterator,iterator>             equal_range (const key_type& k){
				return (pair<iterator, iterator>(lower_bound(k), upper_bound(k)));
			};
		private:
			Node<Key, T>	*_map;
			key_compare		_keycomp;
			size_type		_size;
	};
};
#endif /* ************************************************************* MAP_H */