#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif // !#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <iomanip>

using namespace std;

typedef int Info;

struct Node
{
	Node* left;
	Node* right;
	Info info;
};

unsigned GetAndCheckUnsignedValue(string s, unsigned minVal, unsigned maxVal)
{
	unsigned t;
	bool e;
	e = true;

	while (e) {
		cout << s; cin >> t;

		if (cin.fail())
			e = true;
		else if (t < minVal || t > maxVal)
			e = true;
		else
			e = false;

		if (e) {
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "Error: Incorrect value. Please enter again." << endl;
		}
	}

	return t;
}

Node* CreateTree(int nodeCount)
{
	if (nodeCount == 0)
		return NULL;
	else
	{
		Node* newNode = new Node;
		cout << " Enter node value: ";
		cin >> newNode->info;
		int leftCount = nodeCount / 2;
		int rightCount = nodeCount - leftCount - 1;
		newNode->left = CreateTree(leftCount);
		newNode->right = CreateTree(rightCount);
		return newNode;
	}
}

void PrintTree(Node* root, int level)
{
	if (root != NULL)
	{
		PrintTree(root->right, level + 1);
		for (int i = 1; i <= level; i++)
			cout << "_";
		cout << root->info << endl;
		PrintTree(root->left, level + 1);
	}
}

void PrefixOrder(Node* root)
{
	if (root != NULL)
	{
		cout << root->info << " ";
		PrefixOrder(root->left);
		PrefixOrder(root->right);
	}
}

void InfixOrder(Node* root)
{
	if (root != NULL)
	{
		InfixOrder(root->left);
		cout << root->info << " ";
		InfixOrder(root->right);
	}
}

void PostfixOrder(Node* root)
{
	if (root != NULL)
	{
		PostfixOrder(root->left);
		PostfixOrder(root->right);
		cout << root->info << " ";
	}
}

int Count(Node* root)
{
	if (root == NULL)
		return 0;
	else
		return 1 + Count(root->left) + Count(root->right);
}

Info Sum(Node* root)
{
	if (root == NULL)
		return 0;
	else
		return root->info + Sum(root->left) + Sum(root->right);
}

//void SaveToFile(fstream& f, Node* root)
//{
//	if (root != NULL)
//	{
//		f << root->info << endl;
//		SaveToFile(f, root->left);
//		SaveToFile(f, root->right);
//	}
//	else
//		f << "<END>" << endl;
//
//}
//
//struct Elem // елемент стеку,
//{ // в якому зберігаються
//	Elem* link; // батьківські вузли
//	Node* info;
//};
//
//void Push(Elem*& top, Node* node)
//{
//	cout << "Push " << node->info << endl;
//	Elem* tmp = new Elem;
//	tmp->info = node;
//	tmp->link = top;
//	top = tmp;
//}
//
//Node* Pop(Elem*& top)
//{
//	Elem* tmp = top->link;
//	Node* node = top->info;
//	cout << "Pop " << node->info << endl;
//	delete top;
//	top = tmp;
//	return node;
//}

//void LoadFromFile(fstream& f, Node*& root)
//{
//	Node* newNode, * current;
//	Elem* top = NULL;
//	Info c;
//
//	if (!(f >> c)) // 1
//	{
//		root = NULL;
//		return;
//	}
//	current = new Node; // 2
//	current->info = c;
//	current->left = NULL;
//	current->right = NULL;
//	root = current; // 2.1
//	Push(top, current); // 2.2
//	do
//	{
//		while (f >> c && c != "<END>") // 3
//		{
//			newNode = new Node;
//			newNode->info = c;
//			newNode->left = NULL;
//			newNode->right = NULL;
//			current->left = newNode; // 3.1
//			current = current->left; // 3.2
//			Push(top, current); // 3.3
//		}
//		while (f >> c)
//			if (c == "<END>") // 4
//			{
//				if (top != NULL)
//					current = Pop(top); // 4.1
//			}
//			else
//				break;
//		if (f.eof()) break;
//		if (top != NULL) // 5
//		{
//			current = Pop(top); // 5.1
//			newNode = new Node;
//			newNode->info = c;
//			newNode->left = NULL;
//			newNode->right = NULL;
//			current->right = newNode; // 5.2
//			current = current->right; // 5.3
//			Push(top, current); // 5.4
//		}
//	} while (!f.eof()); // 6
//}

Node* BinarySearchInsert(Node*& root, Info value, bool& found)
{
	if (root == NULL)
	{
		root = new Node;
		root->info = value;
		root->left = NULL;
		root->right = NULL;
		found = false;
		return root;
	}
	else
		if (value == root->info)
		{
			found = true;
			return root;
		}
		else
			if (value < root->info)
				return BinarySearchInsert(root->left, value, found);
			else
				return BinarySearchInsert(root->right, value, found);
}

Node* Find(Node* root, Info value)
{
	if (root == NULL || value == root->info)
		return root;
	if (value < root->info)
		return Find(root->left, value);
	else
		return Find(root->right, value);
}

Node* FindMin(Node* root)
{
	if (root->left != NULL)
		return FindMin(root->left);
	else
		return root;
}

Node* FindMax(Node* root)
{
	if (root->right != NULL)
		return FindMax(root->right);
	else
		return root;
}

Node* FindParent(Node* root, Node* current)
{
	if (current == root)
		return NULL;
	else
		if (current->info < root->info)
		{
			if (current->info == root->left->info)
				return root;
			else
				return FindParent(root->left, current);
		}
		else
		{
			if (current->info == root->right->info)
				return root;
			else
				return FindParent(root->right, current);
		}
}

Node* FindPrev(Node* root, Node* current)
{
	if (current->left != NULL)
		return FindMax(current->left);
	Node* parent = FindParent(root, current);
	while (parent != NULL && current == parent->left)
	{
		current = parent;
		parent = FindParent(root, parent);
	}
	return parent;
}

Node* FindNext(Node* root, Node* current)
{
	if (current->right != NULL)
		return FindMin(current->right);
	Node* parent = FindParent(root, current);
	while (parent != NULL && current == parent->right)
	{
		current = parent;
		parent = FindParent(root, parent);
	}
	return parent;
}

void RightRotation(Node*& root)// standard version
{
	Node* tmp1 = root->left;
	Node* tmp2 = tmp1->right;
	tmp1->right = root; //1
	root->left = tmp2; //2
	root = tmp1; //3
}

void LeftRotation(Node*& root)// standard version
{
	Node* tmp1 = root->right;
	Node* tmp2 = tmp1->left;
	tmp1->left = root; //1
	root->right = tmp2; //2
	root = tmp1; //3
}

void BalanceCount(Node*& root)
{
	if (root != NULL)
	{
		while (Count(root->left) > Count(root->right) + 1)
		{
			RightRotation(root);
		}
		while (Count(root->left) + 1 < Count(root->right))
		{
			LeftRotation(root);
		}
		BalanceCount(root->left);
		BalanceCount(root->right);
	}
}

int Height(Node* root)
{
	if (root == NULL)
		return 0;
	int hL = Height(root->left);
	int hR = Height(root->right);
	return (hL > hR ? hL : hR) + 1;
}

int BFactor(Node* root)
{
	return Height(root->right) - Height(root->left);
}

void BalanceHeight(Node*& root)// standard version
{
	if (root != NULL)
	{
		while (BFactor(root) >= 2)
		{
			if (BFactor(root->right) < 0)
				RightRotation(root->right);
			LeftRotation(root);
		}
		while (BFactor(root) <= -2)
		{
			if (BFactor(root->left) > 0)
				LeftRotation(root->left);
			RightRotation(root);
		}
		BalanceHeight(root->left);
		BalanceHeight(root->right);
	}
}


Node* rightRotation(Node* p)// new version
{
	Node* q = p->left;
	p->left = q->right;
	q->right = p;
	return q;
}

Node* leftRotation(Node* q)// new version
{
	Node* p = q->right;
	q->right = p->left;
	p->left = q;
	return p;
}

Node* balanceHeight(Node* p)// new version
{
	if (BFactor(p) == 2)
	{
		if (BFactor(p->right) < 0)
			p->right
			= rightRotation(p->right);
		return leftRotation(p);
	}
	if (BFactor(p) == -2)
	{
		if (BFactor(p->left) > 0)
			p->left
			= leftRotation(p->left);
		return rightRotation(p);
	}
	return p;
}

Node* Insert(Node* p, Info value)
{
	if (!p)
	{
		p = new Node;
		p->info = value;
		p->left = NULL;
		p->right = NULL;
		return p;
	}
	if (value < p->info)
		p->left = Insert(p->left, value);
	else
		if (value > p->info)
			p->right = Insert(p->right, value);
	return balanceHeight(p);
}

Node* BinarySearchDelete(Node* root, Info value)
{
	if (NULL == root) return NULL; // не знайшли вузол
	if (root->info == value) // знайшли вузол
	{
		if (NULL == root->left && NULL == root->right) // листовий вузол
		{
			delete root;
			return NULL;
		}
		if (NULL == root->right && root->left != NULL) // вузол з одним
		{ // (лівим) нащадком
			Node* temp = root->left;
			delete root;
			return temp;
		}
		if (NULL == root->left && root->right != NULL) // вузол з одним
		{ // (правим) нащадком
			Node* temp = root->right;
			delete root;
			return temp;
		}
		// вузол з двома
		root->info = FindMax(root->left)->info; // нащадками
		root->left = BinarySearchDelete(root->left, root->info);
		return root;
	}
	// не знайшли вузол -
	if (value < root->info) // бінарний пошук в
	{ // лівому під-дереві
		root->left = BinarySearchDelete(root->left, value);
		return root;
	}
	if (value > root->info) // бінарний пошук в
	{ // правому під-дереві
		root->right = BinarySearchDelete(root->right, value);
		return root;
	}
	return root;
}

Node* deleteMin(Node* p)
{
	if (p->left == 0)
		return p->right;
	p->left = deleteMin(p->left);
	return balanceHeight(p);
}

Node* Delete(Node* p, Info value)
{
	if (!p)
		return 0;
	if (value < p->info)
		p->left = Delete(p->left, value);
	else if (value > p->info)
		p->right = Delete(p->right, value);
	else // value == p->key
	{
		Node* q = p->left;
		Node* r = p->right;
		delete p;
		if (!r)
			return q;
		Node* min = FindMin(r);
		min->right = deleteMin(r);
		min->left = q;
		return balanceHeight(min);
	}
	return balanceHeight(p);
}

void DeleteTree(Node*& root, Node* node)
{
	if (node != NULL)
	{
		DeleteTree(root, node->left);
		DeleteTree(root, node->right);
		root = BinarySearchDelete(root, node->info);
	}
}

Node* InsertBTree(Node* p, Info value)
{
	if (!p)
	{
		p = new Node;
		p->info = value;
		p->left = NULL;
		p->right = NULL;
		return p;
	}
	if (value < p->info)
		p->left = InsertBTree(p->left, value);
	else
		if (value > p->info)
			p->right = InsertBTree(p->right, value);
	return p;
}

Node* DeleteMinBTree(Node* p)
{
	if (p->left == 0)
		return p->right;
	p->left = DeleteMinBTree(p->left);
	return p;
}

Node* DeleteBTree(Node* p, Info value)
{
	if (!p)
		return 0;
	if (value < p->info)
		p->left = DeleteBTree(p->left, value);
	else if (value > p->info)
		p->right = DeleteBTree(p->right, value);
	else // value == p->key
	{
		Node* q = p->left;
		Node* r = p->right;
		delete p;
		if (!r)
			return q;
		Node* min = FindMin(r);
		min->right = DeleteMinBTree(r);
		min->left = q;
		return min;
	}
	return p;
}

void DeleteTreeBTree(Node*& root, Node* node)
{
	if (node != NULL)
	{
		DeleteTreeBTree(root, node->left);
		DeleteTreeBTree(root, node->right);
		root = Delete(root, node->info);
	}
}

void Menu()
{
	int menuItem;
	int N;
	Info value;
	bool tt = false;
	Node* root = NULL;

	tt = (bool)GetAndCheckUnsignedValue("Select Tree Type (0 - Binary Tree, 1 - Binary Search Tree) : ", 0, 1);
	//cout << "Select Tree Type (0 - Binary Tree, 1 - Binary Search Tree) (Default: 0) : "; cin >> tt;

	do {
		cout << endl;
		cout << "Select an action:" << endl;
		cout << " [1] - Exit" << endl;
		cout << " [2] - Create" << endl;
		cout << " [3] - Print" << endl;
		cout << " [4] - Add node" << endl;
		cout << " [5] - Delete Node" << endl;
		cout << " [6] - Delete Node and subnodes " << endl;
		cout << " [7] - Process (get sum of nodes)" << endl;
		if (tt)
			cout << " [8] - Balance Binary Search Tree" << endl;
		if (!tt)
			menuItem = GetAndCheckUnsignedValue("Enter a number: ", 1, 7);
		else
			menuItem = GetAndCheckUnsignedValue("Enter a number: ", 1, 8);
		//cout << "Enter a number: "; cin >> menuItem;
		cout << endl;

		switch (menuItem)
		{
		case 1:
			break;
			//case 1:
			//	tt = GetAndCheckUnsignedValue("Select Tree Type (0 - Binary Tree, 1 - Binary Search Tree) (Default: 0) : ", 0, 1);
			//	break;
		case 2:
			cout << "Enter nodes count : "; cin >> N;
			if (!tt) {
				cout << "Create Binary Tree... " << endl;
				root = CreateTree(N);
			}
			else {
				bool found = false;
				cout << "Create Binary Search Tree... " << endl;
				for (int i = 0; i < N; i++) {
					cout << "Value : "; cin >> value;
					BinarySearchInsert(root, value, found);
				}
			}
			//cout << endl;
			break;
		case 3:
			if (!tt)
				cout << "Print Binary Tree... " << endl;
			else
				cout << "Print Binary Search Tree... " << endl;
			PrintTree(root, 0);
			//cout << endl;
			break;
		case 4:
			cout << "Add Node : "; cin >> value;
			if (!tt) {
				root = Insert(root, value);
			}
			else {
				root = Insert(root, value);
			}
			//cout << endl;
			break;
		case 5:
			cout << "Delete Node : "; cin >> value;
			if (!tt) {
				root = Delete(root, value);
			}
			else {
				root = BinarySearchDelete(root, value);
			}
			//cout << endl;
			break;
		case 6:
			cout << "Delete Node and subnodes : "; cin >> value;
			if (!tt) {
				DeleteTreeBTree(root, Find(root, value));
			}
			else {
				DeleteTree(root, Find(root, value));
			}
			//cout << endl;
			break;
		case 7:

			if (!tt) {
				cout << "Process Binary Tree... " << endl;
				//cout << " Count Nodes : " << Count(root) << endl;
				cout << " Sum Nodes : " << Sum(root) << endl;
			}
			else {
				cout << "Process Binary Search Tree... " << endl;
				//cout << " Count Nodes : " << Count(root) << endl;
				cout << " Sum Nodes : " << Sum(root) << endl;
			}
			//cout << endl;
			break;
		case 8:
			cout << "Balance Binary Search Tree... " << endl;
			BalanceHeight(root);
			cout << endl;
			break;
			//default:
			//	cout << "You have entered an incorrect value! "
			//		"You must enter the number - the number of the selected menu item" << endl;
		}

	} while (menuItem != 1);
}

int main()
{
	Menu();

	return 0;
}
