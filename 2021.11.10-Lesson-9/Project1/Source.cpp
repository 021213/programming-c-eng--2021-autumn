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

		if (node->left != nullptr)
		{
			print(stream, node->left, level + 1);
		}

		for (int i = 0; i < level; ++i)
		{
			stream << "  ";
		}

		stream << node->data << endl;

		if (node->right != nullptr)
		{
			print(stream, node->right, level + 1);
		}
	}

	void insert(BNode* node, int element)
	{
		if (node->data > element)
		{
			if (node->left == nullptr)
			{
				node->left = new BNode(element);
			}
			else
			{
				insert(node->left, element);
			}
		}
		else if (node->data < element)
		{
			if (node->right == nullptr)
			{
				node->right = new BNode(element);
			}
			else
			{
				insert(node->right, element);
			}
		}
	}

public:
	BTree() : root(nullptr) {}

	BTree& operator+=(int element)
	{
		if (root == nullptr)
		{
			root = new BNode(element);
		}
		else
		{
			insert(root, element);
		}
		return *this;
	}

	friend ostream& operator<<(ostream& stream, BTree& tree);
};

ostream& operator<<(ostream& stream, BTree& tree)
{
	stream << "_____START_____" << endl;
	tree.print(stream, tree.root);
	stream << "______END______" << endl;
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
	cout << tree << endl;

	return EXIT_SUCCESS;
}