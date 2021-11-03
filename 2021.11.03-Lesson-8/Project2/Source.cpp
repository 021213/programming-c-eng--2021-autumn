#include<iostream>

using namespace std;

template<typename T>
struct Node {
	T data;
	Node<T>* next;
	Node(int data = 0, Node<T>* next = nullptr) : data(data), next(next) {};
	~Node() {}
};

template<typename T>
class LinkedList {
private:
	Node<T>* head;
	Node<T>* tail;
	int count;

public:
	LinkedList() : head(nullptr), tail(nullptr), count(0) {}
	LinkedList(const LinkedList<T>& list)
	{
		Node<T>* temp = list.head;
		while (temp != nullptr)
		{
			push_back(temp->data);
			temp = temp->next;
		}
	}
	~LinkedList()
	{
		while (head != nullptr)
		{
			Node<T>* temp = head;
			head = head->next;
			delete temp;
		}
	}

	T& operator[](int index)
	{
		if (index < 0)
		{
			push_forward(0);
			return head->data;
		}
		if (index >= count)
		{
			push_back(0);
			return tail->data;
		}
		Node<T>* temp = head;
		for (int i = 0; i < index; ++i)
		{
			temp = temp->next;
		}
		return temp->data;
	}

	bool indexValid(int index)
	{
		return (index >= 0 && index < count);
	}

	void push_forward(int data)
	{
		head = new Node<T>(data, head);
		if (tail == nullptr)
		{
			tail = head;
		}
		++count;
	}

	void push_back(T data)
	{
		if (tail == nullptr)
		{
			return push_forward(data);
		}
		tail->next = new Node<T>(data);
		tail = tail->next;
		++count;
	}

	void insert(T data, int index)
	{
		if (index == count)
		{
			return push_back(data);
		}
		if (index == 0)
		{
			return push_forward(data);
		}
		if (indexValid(index))
		{
			Node<T>* temp = head;
			for (int i = 0; i < index - 1; ++i)
			{
				temp = temp->next;
			}
			temp->next = new Node<T>(data, temp->next);
			++count;
		}
	}

	T extractHead()
	{
		if (count == 0)
		{
			return 0;
		}
		T result = head->data;
		Node<T>* temp = head;
		head = head->next;
		delete temp;
		--count;
		if (count == 0)
		{
			tail = nullptr;
		}
		return result;
	}

	T extractTail()
	{
		if (count == 0)
		{
			return 0;
		}
		if (count == 1)
		{
			return extractHead();
		}
		Node<T>* temp = head;
		while (temp->next->next != nullptr)
		{
			temp = temp->next;
		}
		T result = temp->next->data;
		delete temp->next;
		temp->next = nullptr;
		--count;
		return result;
	}

	T extractElement(int index)
	{
		if (!indexValid(index))
		{
			return 0;
		}
		if (index == 0)
		{
			return extractHead();
		}
		if (index == count - 1)
		{
			return extractTail();
		}

		Node<T>* temp = head;
		for (int i = 0; i < index - 1; ++i)
		{
			temp = temp->next;
		}
		int result = temp->next->data;
		Node<T>* todelete = temp->next;
		temp->next = temp->next->next;
		delete todelete;
		--count;
		return result;
	}

	friend ostream& operator<<(ostream& stream, const LinkedList<T>& list)
	{
		Node<T>* temp = list.head;
		stream << "[" << list.count << "]:{ ";
		while (temp != nullptr)
		{
			stream << temp->data << " ";
			temp = temp->next;
		}
		stream << "}";
		return stream;
	}
};

int main(int argc, char* argv[])
{
	LinkedList<int> list;
	cout << list << endl;
	list.push_back(5);
	list.push_forward(4);
	list.insert(1, 0);
	list.insert(2, 1);
	list.insert(3, 2);
	list.push_forward(0);
	cout << list << endl;

	cout << "EXTRACT" << endl;
	cout << list.extractTail() << endl;
	cout << list.extractElement(3) << endl;
	cout << list.extractHead() << endl;
	cout << list << endl;
	cout << list.extractHead() << endl;
	cout << list.extractHead() << endl;
	cout << list.extractHead() << endl;
	cout << list.extractHead() << endl;
	cout << list << endl;

	list.push_back(0);
	list.push_back(1);
	list.push_back(2);
	list.push_back(3);
	list.push_back(4);
	list.push_back(5);
	cout << list << endl;
	list[4] = 10;
	cout << list << endl;

	list[-5] = 123;
	list[100] = 100;
	cout << list << endl;
	return EXIT_SUCCESS;
}