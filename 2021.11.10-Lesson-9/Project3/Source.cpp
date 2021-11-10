#include<iostream>

using namespace std;

struct BNode
{
	int data;
	BNode* left;
	BNode* right;
	BNode(int data = 0,
		BNode* left = nullptr,
		BNode* right = nullptr) : data(data), left(left), right(right) {};
	~BNode() {}
};

class BTree
{
private:
	BNode* root;

	void print(ostream& stream, BNode* node, int level = 0)
	{
		if (node == nullptr)
		{
			return;
		}

		print(stream, node->left, level + 1);

		for (int i = 0; i < level; ++i)
		{
			stream << "  ";
		}

		stream << node->data << endl;

		print(stream, node->right, level + 1);
	}

	void printLinear(ostream& stream, BNode* node)
	{
		if (node == nullptr)
		{
			return;
		}

		printLinear(stream, node->left);
		stream << node->data << " ";
		printLinear(stream, node->right);
	}

	void insert(BNode*& node, int element)
	{
		if (node == nullptr)
		{
			node = new BNode(element);
		}
		else
		{
			if (node->data > element)
			{
				insert(node->left, element);
			}
			else if(node->data < element)
			{
				insert(node->right, element);
			}
		}
	}

	BNode*& find(BNode*& root, int element)
	{

	}

	BNode* extract(BNode*& node)
	{

	}

public:
	BTree() : root(nullptr) {}

	BTree& operator+=(int element)
	{
		insert(root, element);
		return *this;
	}
	
	BTree& operator-=(int element)
	{
		BNode*& node = find(root, element);
		node = extract(node);
		delete node;
		return *this;
	}

	friend ostream& operator<<(ostream& stream, BTree& tree);
};

ostream& operator<<(ostream& stream, BTree& tree)
{
	stream << "_____START_____" << endl;
	tree.printLinear(stream, tree.root);
	stream << endl << "______END______" << endl;
	return stream;
}

int main(int argc, char* argv[])
{
	BTree tree;
	cout << tree << endl;
	tree += 5;
	tree += 3;
	tree += 2;
	cout << tree << endl;
	tree += 4;
	tree += 10;
	tree += 7;
	tree += 15;
	cout << tree << endl;

	return EXIT_SUCCESS;
}