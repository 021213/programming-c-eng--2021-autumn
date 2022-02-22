#include<iostream>

using namespace std;

struct Node {
	int data;
	Node* left;
	Node* right;
	
	Node(int data, Node* left = nullptr, Node* right = nullptr) :
		data(data), left(left), right(right) {};
	
	friend ostream& operator<<(ostream& stream, Node* node)
	{
		if (node == nullptr)
		{
			stream << "_";
		}
		else
		{
			stream << node->data;
		}
		return stream;
	}
};

struct BTree
{
private:
	Node* root;

	void addRec(Node*& node, int data)
	{
		if (node == nullptr)
		{
			node = new Node(data);
		}
		else
		{
			if (node->data == data)
			{
				return;
			}
			if (node->data > data)
			{
				addRec(node->left, data);
			}
			else
			{
				addRec(node->right, data);
			}
		}
	}

	void printRec(Node*& node, int depth = 0)
	{
		if (node)
		{
			printRec(node->left, depth + 1);
		}
		for (int i = 0; i < depth; ++i)
		{
			cout << "  ";
		}
		cout << node << endl;
		if (node)
		{
			printRec(node->right, depth + 1);
		}
	}

	Node*& find(Node*& node, int data)
	{
		if (node == nullptr || node->data == data)
		{
			return node;
		}
		if (node->data > data)
		{
			return find(node->left, data);
		}
		else
		{
			return find(node->right, data);
		}
	}

	void extractRec(Node*& result)
	{
		if (result->left == nullptr)
		{
			result = result->right;
			return;
		}
		if (result->right == nullptr)
		{
			result = result->left;
			return;
		}

 		if (result->left->right == nullptr)
		{
			result->left->right = result->right;
			result = result->left;
			return;
		}

		Node* rightmost = result->left;
		while (rightmost->right->right != nullptr)
		{
			rightmost = rightmost->right;
		}
		Node* copy = rightmost->right;
		extractRec(rightmost->right);

		copy->left = result->left;
		copy->right = result->right;
		result = copy;
	}

	Node* extract(int data)
	{
		Node*& result = find(root, data);
		if (result == nullptr)
		{
			return nullptr;
		}

		Node* copy = result;

		extractRec(result);

		return copy;
	}

public:
	BTree(Node* root = nullptr) : root(root) {};

	void add(int data)
	{
		addRec(root, data);
	}

	void print()
	{
		cout << "TREE START" << endl;
		printRec(root);
		cout << "TREE END" << endl;
	}

	void deleteElement(int data)
	{
		Node* node = extract(data);
		if (node != nullptr)
		{
			delete node;
		}
	}
};


int main()
{
	BTree tree;
	tree.print();
	tree.add(8);
	tree.add(4);
	tree.add(12);
	tree.add(5);
	tree.add(2);
	tree.add(1);
	tree.add(10);
	tree.print();

	tree.deleteElement(5);
	tree.print();

	tree.deleteElement(4);
	tree.print();

	tree.add(5);
	tree.add(4);
	tree.add(15);
	tree.print();

	tree.deleteElement(2);
	tree.print();
	tree.add(9);
	tree.add(11);
	tree.add(14);
	tree.add(16);
	tree.print();

	tree.deleteElement(12);
	tree.print();

	tree.deleteElement(8);
	tree.print();

	return 0;
}