#include <iostream>
using namespace std;




class Tree
{
private:
	class Node
	{
	public:
		class Offense
		{
		public:
			class Knot
			{
			public:
				string violation;
				Knot* next;
				Knot(string violation = "", Knot* next = nullptr) : violation{ violation }, next{ next } {}

			};
			Knot* head;
			int size;
			Offense() : head{ nullptr }, size{ 0 } {}
			void clear() {
				for (size_t i = 0; i < size; i++)
				{
					pop_first();
				}
				size = 0;
			}
			~Offense() {
				clear();
			}
			void pop_first() {
				Knot* current = head;
				head = head->next;
				delete current;
			}
			void push_back(string violation) {
				if (head == nullptr)
				{
					head = new Knot(violation);
				}
				else
				{
					Knot* current = head;
					while (current->next != nullptr)
					{
						current = current->next;
					}
					Knot* newKnot = new Knot(violation);
					current->next = newKnot;
				}
				size++;

			}
			void showViolation() {
				Knot* current = head;
				do
				{
					cout << current->violation << endl;
					current = current->next;
				} while (current != nullptr);
			}
		};
		string carNumberKey;
		Offense* offense;
		Node* leftChild;
		Node* rigthChild;
		Node(string carNumberKey = "", string violation = "") :carNumberKey{ carNumberKey }, offense{ new Offense() }, leftChild{ nullptr },
			rigthChild{ nullptr } {
			this->offense->push_back(violation);
		}
		void displayNode() {
			cout << "Номер автомашины: " << carNumberKey << endl;
			cout << "Правонарушения: " << endl;
			offense->showViolation();
			cout << endl;
		}
		
	};
	Node* root;


	void inOrder(Node* localRoot) {
		if (localRoot != nullptr)
		{
			inOrder(localRoot->leftChild);
			localRoot->displayNode();
			inOrder(localRoot->rigthChild);
		}
	}
	void inOrderRange(Node* localRoot, string carNumber1, string carNumber2) {
		if (localRoot != nullptr)
		{
			inOrderRange(localRoot->leftChild, carNumber1, carNumber2);
			if (localRoot->carNumberKey >= carNumber1 && localRoot->carNumberKey <= carNumber2)
			{
				localRoot->displayNode();
			}
			inOrderRange(localRoot->rigthChild, carNumber1, carNumber2);
		}
	}

public:
	Tree() : root{ nullptr } {}
	void insertNode(string carNumber, string violation) {
		Node* newNode = new Node(carNumber, violation);
		if (root == nullptr)
		{
			root = newNode;
		}
		else
		{
			Node* current = root;
			Node* parent;
			while (true)
			{
				parent = current;
				if (carNumber == current->carNumberKey)
				{
					current->offense->push_back(violation);
					delete newNode;
					return;
				}else if (carNumber < current->carNumberKey)
				{
					current = current->leftChild;
					if (current == nullptr)
					{
						parent->leftChild = newNode;
						return;
					}
				}
				else
				{
					current = current->rigthChild;
					if (current == nullptr)
					{
						parent->rigthChild = newNode;
						return;
					}
				}
				
			}
		}
	}
	void printAllTree() {
		inOrder(root);
	}
	void printViolationCarNumber(string carNumber) {
		Node* current = root;
		while (current->carNumberKey != carNumber)
		{
			if (current->carNumberKey < carNumber)
			{
				current = current->leftChild;
			}
			else
			{
				current = current->rigthChild;
			}
			if (current == nullptr)
			{
				return;
			}
		}
		current->displayNode();
	}
	void printViolationCarNumber(string carNumber1, string carNumber2) {
		inOrderRange(root, carNumber1, carNumber2);
	}
	~Tree();



};



int main()
{
	setlocale(LC_ALL, "");
	Tree* tree = new Tree();
	tree->insertNode("asd", "asd asd sad ");
	tree->insertNode("asd", "asd asd sad452361 ");
	tree->insertNode("asd456", "789456 ");
	tree->insertNode("fghj", "123fg ");
	tree->insertNode("fghj", "123fg sad sdf fhhgd ");
	tree->insertNode("kfgoh", "715 ");
	cout << "Распечатка данных по заданному номеру: " << endl;
	tree->printViolationCarNumber("asd");
	cout << endl;
	cout << "Распечатка всех данных: " << endl;
	tree->printAllTree();
	cout << endl;
	cout << "Распечатка данных по заданному диапазону: " << endl;
	tree->printViolationCarNumber("asd", "fghj");
}
