#pragma once
template <typename T>
class LinkedList: std::iterator<std::bidirectional_iterator_tag, T>
{
public: 
	class ListNode
	{
	public:
		ListNode(T value, ListNode* prev, ListNode* next) :_value(value), _prev(prev), _next(next) {}
		ListNode() :_value(T()), _prev(this), _next(this) {}
		T _value;
		ListNode* _prev;
		ListNode* _next;
	};

	class iterator : std::iterator<std::bidirectional_iterator_tag, T>
	{
	public:
		iterator(ListNode* ptr, ListNode *head) 
		{
			_ptr = ptr;
			__head = head; 
		}
		iterator operator ++()
		{
			if (_ptr == __head)
				throw std::runtime_error("warnings");
			_ptr = _ptr->_next;
			return *this;
		}
		iterator operator ++(int)
		{
			if (_ptr == __head)
				throw std::runtime_error("warnings");
			iterator old(*this);
			_ptr = _ptr->_next;
			return old;
		}
		iterator operator --()
		{
			if (_ptr->_prev == __head)
				throw std::runtime_error("warnings");
			_ptr = _ptr->_prev;
			return *this;
		}
		iterator operator --(int)
		{
			if (_ptr->_prev == __head)
				throw std::runtime_error("warnings");
			iterator old(*this);
			_ptr = _ptr->_prev;

			return old;
		}
		T& operator*()
		{
			return _ptr->_value;
		}
		T* operator ->()
		{
			return &_ptr->_value;
		}
		friend bool operator==(const iterator& left, const iterator& right)
		{
			return (left._ptr == right._ptr);
		}
		friend bool operator!=(const iterator& left, const iterator& right)
		{
			return !(operator==(left, right));
		}
		ListNode* _ptr;
		ListNode* __head;
	};

	class const_iterator : std::iterator<std::bidirectional_iterator_tag, T>
	{
	public:
		const_iterator(ListNode* ptr) :_ptr(ptr) {}
		const_iterator operator ++()
		{
			_ptr = _ptr->_next;
			return *this;
		}
		const_iterator operator ++(int)
		{
			const_iterator old(*this);
			_ptr = _ptr->_next;
			return old;
		}
		const_iterator operator --()
		{
			_ptr = _ptr->_prev;
			return *this;
		}
		const_iterator operator --(int)
		{
			const_iterator old(*this);
			_ptr = _ptr->_prev;

			return old;
		}
		const T& operator*()
		{
			return _ptr->_value;
		}
		T* operator ->()
		{
			return &_ptr->_value;
		}
		friend bool operator==(const const_iterator& left, const const_iterator& right)
		{
			return (left._ptr == right._ptr);
		}
		friend bool operator!=(const const_iterator& left, const const_iterator& right)
		{
			return !(operator==(left, right));
		}
		ListNode* _ptr;
	};

	class reverse_iterator : std::iterator<std::bidirectional_iterator_tag, T>
	{
	public:
		reverse_iterator(ListNode* ptr) :_ptr(ptr) {}
		reverse_iterator operator ++()
		{
			_ptr = _ptr->_prev;
			return *this;
		}
		reverse_iterator operator ++(int)
		{
			reverse_iterator old(*this);
			_ptr = _ptr->_prev;
			return old;
		}
		reverse_iterator operator --()
		{
			_ptr = _ptr->_next;
			return *this;
		}
		reverse_iterator operator --(int)
		{
			reverse_iterator old(*this);
			_ptr = _ptr->_next;
			return old;
		}
		 T& operator*()
		{
			return _ptr->_value;
		}
		T* operator ->()
		{
			return &_ptr->_value;
		}
		friend bool operator==(const reverse_iterator& left, const reverse_iterator& right)
		{
			return (left._ptr == right._ptr);
		}
		friend bool operator!=(const reverse_iterator& left, const reverse_iterator& right)
		{
			return !(operator==(left, right));
		}
		ListNode* _ptr;
	};
	class const_reverse_iterator : std::iterator<std::bidirectional_iterator_tag, T>
	{
	public:
		const_reverse_iterator(ListNode* ptr) :_ptr(ptr) {}
		const_reverse_iterator operator ++()
		{
			_ptr = _ptr->_prev;
			return *this;
		}
		const_reverse_iterator operator ++(int)
		{
			const_reverse_iterator old(*this);
			_ptr = _ptr->_prev;
			return old;
		}
		const_reverse_iterator operator --()
		{
			_ptr = _ptr->_next;
			return *this;
		}
		const_reverse_iterator operator --(int)
		{
			const_reverse_iterator old(*this);
			_ptr = _ptr->_next;
			return old;
		}
		const T& operator*()
		{
			return _ptr->_value;
		}
		T* operator ->()
		{
			return &_ptr->_value;
		}
		friend bool operator==(const const_reverse_iterator& left, const const_reverse_iterator& right)
		{
			return (left._ptr == right._ptr);
		}
		friend bool operator!=(const const_reverse_iterator& left, const const_reverse_iterator& right)
		{
			return !(operator==(left, right));
		}
		ListNode* _ptr;
	};



	const_iterator begin() const
	{
		return _head._next;
	}
	
	reverse_iterator rbegin()
	{
		return _head._prev;
	}

	const_reverse_iterator rbegin() const
	{
		return _head._prev;
	}
	const_iterator end() const
	{
		return _head._prev->_next;
	}
	reverse_iterator rend()
	{
		return _head._next->_prev;
	}
	const_reverse_iterator rend() const
	{
		return _head._prev->_next;
	}
	
	iterator insert(iterator where, const T& value)
	{
		ListNode* Save = new ListNode(value, where._ptr->_prev, where._ptr);
		where._ptr->_prev->_next = Save;
		where._ptr->_prev = Save;
		return iterator(Save,where.__head);
	}
	void push_back(const T& value)
	{
		insert(end(), value);
	}
	void push_front(const T& value)
	{
		insert(begin(), value);
	}
	iterator erase(iterator where)
	{
		iterator del(where._ptr->_next, where.__head);
		where._ptr->_next->_prev= where._ptr->_prev;
		where._ptr->_prev->_next= where._ptr->_next;
		delete where._ptr;
		return del;
	}

	iterator begin()
	{
		return iterator(_head._next,&_head);
	}
	iterator end()
	{
		return iterator(&_head,&_head);
	}
	bool empty()
	{
		return (begin() == end());
	}
	void remove(const T& value)
	{
		iterator be = begin();
		while ((be != end()) && (value != be._ptr->_value))
			++be;
		if (value == be._ptr->_value)
			erase(be);
	}
	~LinkedList()
	{
		iterator be(begin());
		while (be != end())
			 erase(be++);
	}
	LinkedList() = default;
	LinkedList(const LinkedList& ob)
	{
		iterator i1(ob._head._next, &_head);
		iterator i2(ob._head._next->_prev, &_head);

		while (i1 != i2)
		{
			push_back(*i1);
			++i1;
		}
	}
	LinkedList(LinkedList &&ob)
	{
		_head._next = ob._head._next;
		_head._prev = ob._head._prev;
		ob._head._prev->_next = &_head;
		ob._head._next->_prev = &_head;
		ob._head._next = &ob._head;
		ob._head._prev = &ob._head;
	}
	LinkedList& operator=(const LinkedList& ob)
	{
		if (&_head == &ob._head)
			return *this;
		this->~LinkedList();
		iterator i1(ob._head._next);
		iterator i2(ob._head._next->_prev);
		while (i1 != i2)
		{
			push_back(*i1);
			++i1;
		}
		return *this;
	}
	LinkedList& operator=(LinkedList&& ob)
	{
		if (&_head == &ob._head)
			return *this;
		this->~LinkedList();
		_head._next = ob._head._next;
		_head._prev = ob._head._prev;
		ob._head._prev->_next = &_head;
		ob._head._next->_prev = &_head;
		ob._head._next = &ob._head;
		ob._head._prev = &ob._head;
		return *this;
	}

private:
	ListNode _head;                     
};

