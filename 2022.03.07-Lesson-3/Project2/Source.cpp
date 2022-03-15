#include<iostream>

using namespace std;

struct Node
{
	int data;
	Node* next;

	Node(int data = 0, Node* next = nullptr)
	{
		this->data = data;
		this->next = next;
	}
};

void print(Node* head)
{
	Node* temp = head;
	while (temp != nullptr)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

void deleteList(Node* &head)
{
	while (head != nullptr)
	{
		Node* temp = head->next;
		delete head;
		head = temp;
	}
}

int main()
{
	Node* node = nullptr;

	node = new Node(10, nullptr);
	node->data = 5;

	node->next = new Node(10);
	node->next->next = new Node(20);
	node->next->next->next = new Node(30);

	cout << node->data << " ";
	cout << node->next->data << " ";
	cout << node->next->next->data << " ";
	cout << node->next->next->next->data << endl;


	node->next->next = new Node(15, node->next->next);

	cout << node->data << " ";
	cout << node->next->data << " ";
	cout << node->next->next->data << " ";
	cout << node->next->next->next->data << " ";
	cout << node->next->next->next->next->data << endl;

	print(node);
	node = new Node(3, node);
	print(node);

	deleteList(node);
	print(node);

	return 0;
}