#include<iostream>

using namespace std;

struct Node
{
	int data;
	Node* next;
};

int main(int argc, char* argv[])
{
	Node* pNode = new Node();
	(*pNode).data = 5;
	(*pNode).next = new Node();
	(*((*pNode).next)).data = 6;
	delete (*pNode).next;
	delete pNode;

	//(*pNode). == pNode->

	pNode = new Node();
	pNode->data = 5;
	pNode->next = new Node();
	pNode->next->data = 6;
	delete pNode->next;
	delete pNode;


	return EXIT_SUCCESS;
}