#include <iostream>
using namespace std;

class Stack
{
public:
	Stack() = delete;
	explicit Stack(int);
	~Stack();
	bool isEmpty() {
		return top == EMPTY;
	}
	bool isFull() {
		return top == CAPACITOR;
	}
	void Push(char);
	char Top() {
		return elements[top];
	}
	char Pop();
		
	

private:
	char* elements;
	const int CAPACITOR;
	const int EMPTY;
	int top;
};


Stack::Stack(int capacitor) : elements{ new char[capacitor] {} }, CAPACITOR{ capacitor }, EMPTY{ -1 }, top{ EMPTY } {}
Stack::~Stack()
{
	delete[] elements;
}

void Stack::Push(char element) {
	
	if (!isFull())
	{
		elements[++top] = element;
	}
	else
	{
		cout << "Переполнение Stack." << endl;
	}
	
}
char Stack::Pop() {
	if (!isEmpty())
	{
		return elements[top--];
	}
	else
	{
		cout << "Stack пуст." << endl;
		
	}
	return 0;
}

int main()
{
	setlocale(LC_ALL, "");
    std::cout << "Домашнее задание ООП13\n";
	Stack stack(20);
	char* str = new char[128] {};
	char* remember = new char[128] {};
	char bracket = ' ';
	bool isFalse = false;
	cout << "Введите выражение для проверки: "<< endl;
	cin.getline(str, 128, ';');
	//cout << "Введеное выражение: " << endl;
	//cout << str << endl;
	for (size_t i = 0; i < strlen(str); i++)
	{
		bracket = ' ';
		remember[i] = str[i];
		switch (str[i])
		{
		case '(':
		case '[':
		case'{':
			stack.Push(str[i]);
			break;
		case')':
		case']':
		case'}':
			bracket = stack.Pop();
			break;
		}
		if (bracket == '(' && str[i] != ')')
		{
			isFalse = true;
			break;
		}
		if (bracket == '[' && str[i] != ']')
		{
			isFalse = true;
			break;
		}
		if (bracket == '{' && str[i] != '}')
		{
			isFalse = true;
			break;
		}
	}
	if (isFalse)
	{
		cout << "Скобки в выражении заданы не верно!" << endl;
		cout << remember << endl;

	}
	else
	{
		cout << "Скобки в выражении заданы верно!" << endl;
		cout << str << endl;
	}
}
