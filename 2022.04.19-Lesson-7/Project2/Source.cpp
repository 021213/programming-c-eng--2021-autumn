#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node* next;
	Node(int data, Node* next = nullptr) : data(data), next(next) {};
	Node(const Node& node) : data(node.data), next(nullptr) {};
	~Node() { data = 0; next = nullptr; };
};

/*
  template<typename _Category, typename _Tp, typename _Distance = ptrdiff_t,
		   typename _Pointer = _Tp*, typename _Reference = _Tp&>
	struct iterator
	{
	  /// One of the @link iterator_tags tag types@endlink.
	  typedef _Category  iterator_category;
	  input_iterator_tag, output_iterator_tag, forward_iterator_tag, bidirectional_iterator_tag, random_access_iterator_tag
	  /// The type "pointed to" by the iterator.
	  typedef _Tp        value_type;
	  /// Distance between iterators is represented as this type.
	  typedef _Distance  difference_type;
	  /// This type represents a pointer-to-value_type.
	  typedef _Pointer   pointer;
	  /// This type represents a reference-to-value_type.
	  typedef _Reference reference;
	};
*/

template<typename ValType>
struct MyIterator : public std::iterator<std::input_iterator_tag, ValType>
{
	friend struct LinkedList;
	ValType* p;
	MyIterator(ValType* p) : p(p) {};
	MyIterator(const MyIterator& it) : p(it.p) {};
	bool operator!=(MyIterator const& other) const
	{
		return p != other.p;
	}
	bool operator==(MyIterator const& other) const
	{
		return p == other.p;
	}
	MyIterator& operator++()
	{
		p = p->next;
		return *this;
	}
	typename MyIterator::reference operator*() const
	{
		return *p;
	}
};

struct LinkedList
{
	typedef MyIterator<Node> iterator;
	typedef MyIterator<const Node> const_iterator;

	iterator begin()
	{
		return iterator(head);
	}

	iterator end()
	{
		return iterator(tail);
	}

	const_iterator cbegin()const
	{
		return const_iterator(head);
	}

	const_iterator cend() const
	{
		return const_iterator(tail);
	}

	Node* head;
	Node* tail;
	int count;
	LinkedList() : head(nullptr), tail(nullptr), count(0) {};
	LinkedList(LinkedList& list)
	{
		head = nullptr;
		tail = nullptr;
		Node* temp = list.head;
		while (temp != nullptr)
		{
			insertEnd(temp->data);
			temp = temp->next;
		}
	}
	~LinkedList()
	{
		while (head != nullptr)
		{
			Node* temp = head;
			head = head->next;
			delete temp;
		}
	}
	int& operator[](int index)
	{
		Node* temp = head;
		while (temp != nullptr && index > 0)
		{
			temp = temp->next;
			--index;
		}
		if (temp == nullptr)
		{
			int data;
			return data;
		}
		return temp->data;
	}
	void insertBeg(int element)
	{
		head = new Node(element, head);
		if (tail == nullptr)
		{
			tail = head;
		}
		count++;
	}
	void insertEnd(int element)
	{
		if (head == nullptr)
		{
			return insertBeg(element);
		}
		tail->next = new Node(element);
		tail = tail->next;
		count++;
	}
};

int main()
{
	LinkedList list1;
	list1.insertBeg(1);
	list1.insertBeg(2);
	list1.insertBeg(3);
	list1.insertBeg(4);
	list1.insertBeg(5);

	for (auto element : list1)
	{
		//cout << element << " "; //TODO: 1. make it work correctly
		cout << element.data << " ";
	}
	cout << endl;

	//TODO: 2. Attempt to make an iterator for your own Binary Search Tree.
	return 0;
}