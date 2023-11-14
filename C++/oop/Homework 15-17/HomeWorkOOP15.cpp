#include <iostream>
#include <time.h>
using namespace std;

template<class T>
class List
{
public:
	List();
	~List();
	void push_front(T data);
	void push_back(T data);
	void insert(T data, int index);
	void removeAt(int index);
	void pop_front();
	T returnData();
	void pop_back();
	void clear();
	int getSize();
	void clone(const List<T>&);

	T& operator[](const int index);
	List<T>& operator=(const List<T>& list) {
		if (this == &list)
		{
			return *this;
		}
		clear();
		clone(list);
		return *this;
	}
	 List<T>& operator+(const List<T>& list) {
		
		 List<T> newList;
		 Node<T>* pHead = head;
		 Node<T>* pList = list.head;
		 do
		 {
			 newList.push_back(pHead->data);
			 pHead = pHead->pNext;
		 } while (pHead != nullptr);

		 do
		 {
			 newList.push_back(pList->data);
			 pList = pList->pNext;
		 } while (pList != nullptr);

		 return newList;
	}
	 List<T>& operator*(const List<T>& list) {
		
		 List<T> newList;
		 Node<T>* pHead = head;
		 Node<T>* pList = list.head;
		
		 do
		 {
			 do
			 {
				 if (pList->data == pHead->data)
				 {
					 newList.push_back(pList->data);
					 break;
				 }

				 pList = pList->pNext;

			 } while (pList != nullptr);

			 pHead = pHead->pNext;
			 pList = list.head;

		 } while (pHead != nullptr);
		 return newList;
	 }
private:
	template<class T>
	class Node {

	public:
		T data;
		Node* pNext;
		
		Node(T data = T(), Node* pNext = nullptr) : data{ data }, pNext{ pNext } {}
	};
	int size;
	Node<T>* head;	
};



template<class T>
class Stack
{
public:
	Stack() = delete;
	Stack(const Stack&) = delete;
	Stack(const Stack&&) = delete;
	Stack<T>&operator=(const Stack&) = delete;
	Stack(int max_number);
	~Stack();

	bool isFull();
	bool isEmpty();
	void push(const T data);
	T pop();
	T getTop();
	int getCount();
	void clear();

private:
	List<T>* data;
	int EMPTY;
	int FULL;
	int top;
};





















int main()
{
	setlocale(LC_ALL, "");
	srand(time(NULL));
	/*
	cout << "Домашняя работа ООП15.1" << endl;
	Stack<int> st(4);

	cout << "Заполнение стека случайными числами: " << endl;
	for (size_t i = 0; i < 10; i++)
	{
		int ran = rand() % 10;
		cout << ran << " ";
		st.push(ran);
	}
	cout << endl;

	cout << "Вывод верхнего элемента: " << st.getTop() << endl;


	cout << "Количество элементов в стеке: " << st.getCount() << endl;

	cout << "Вывод значений со стека: " << endl;
	while (!st.isEmpty())
	{
		cout << st.pop() << " ";
	}
	cout << endl << "Количество элементов в стеке: " << st.getCount();
	*/

	cout << "Домашняя работа ООП15.2" << endl;
	List<int>lst1;
	lst1.push_front(10);
	lst1.push_front(15);
	lst1.push_front(20);
	cout << "Первый список: " << endl;
	for (size_t i = 0; i < lst1.getSize(); i++)
	{
		cout << lst1[i] << " ";
	}
	cout << endl;

	List<int>lst2;
	//lst2.push_front(30);
	lst2 = lst1;

	cout << "Клонированный список(оператор = или метод clone()): " << endl;
	for (size_t i = 0; i < lst2.getSize(); i++)
	{
		cout << lst2[i] << " ";
	}

	cout << endl;

	List<int> lst3;
	lst3 = lst1 + lst2;
	
	cout << "Суммированный список(оператор +): " << endl;
	for (size_t i = 0; i < lst3.getSize(); i++)
	{
		cout << lst3[i] << " ";
	}

	cout << endl;

	//новые значения в lst1

	lst1.push_front(30);
	lst1.push_front(40);
	lst1.push_front(50);
	cout << "Новый список lst1: " << endl;
	for (size_t i = 0; i < lst1.getSize(); i++)
	{
		cout << lst1[i] << " ";
	}

	cout << endl;

	cout << "Список lst2: " << endl;
	for (size_t i = 0; i < lst2.getSize(); i++)
	{
		cout << lst2[i] << " ";
	}

	cout << endl;

	List<int> lst4 = lst1 * lst2;
	cout << "Одинаковые значения с двух списков(оператор *): " << endl;
	for (size_t i = 0; i < lst4.getSize(); i++)
	{
		cout << lst4[i] << " ";
	}

	cout << endl;
}


































template<class T>
List<T>::List() : size{ 0 }, head{ nullptr } {}

template<class T>
List<T>::~List()
{
}

template<class T>
void List<T>::push_front(T data)
{
	head = new Node<T>(data, head);
	size++;
}

template<class T>
void List<T>::push_back(T data)
{
	if (head == nullptr)
	{
		head = new Node<T>(data);
	}
	else
	{
		Node<T>* current = head;
		while (current->pNext != nullptr)
		{
			current = current->pNext;
		}
		current->pNext = new Node<T>(data);
	}
	size++;
}

template<class T>
void List<T>::insert(T data, int index)
{
	//находим предыдущий элемент
	if (index == 0)
	{
		push_front(data);
	}
	else
	{
		Node<T>* previous = head;
		for (size_t i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}
		Node<T>* newNode = new Node<T>(data, previous->pNext);
		previous->pNext = newNode;
		size++;
	}
}

template<class T>
void List<T>::removeAt(int index) {
	//находим предыдущий элемент
	if (index == 0)
	{
		pop_front();
	}
	else
	{
		Node<T>* previous = head;
		for (size_t i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}
		Node<T>* toDelete = previous->pNext;
		previous->pNext = toDelete->pNext;
		delete toDelete;
	}
	size--;
}

template<class T>
void List<T>::pop_front() {
	Node<T>* toDelete = head;
	head = head->pNext;
	delete toDelete;
	size--;
}

template<class T>
T List<T>::returnData()
{
	return head->data;
}

template<class T>
void List<T>::pop_back() {
	removeAt(size - 1);
}

template<class T>
void List<T>::clear() {
	while (size) //приведение данных
	{
		pop_front();
	}
}

template<class T>
int List<T>::getSize() { return size; }

template<class T>
void List<T>::clone(const List<T>& list)
{
	Node<T>* current = list.head;
	do
	{
		push_back(current->data);
		current = current->pNext;
	} while (current != nullptr);
	
	/*
	Node<T>* current = list.head;
	head = new Node<T>(current->data);
	Node<T>* pNewHead = head;
	while (current->pNext != nullptr)
	{
		current = current->pNext;
		pNewHead->pNext = new Node<T>(current->data);
		pNewHead = pNewHead->pNext;
	}
	size = list.size;
	*/
	
}





template<class T>
T& List<T>::operator[](const int index) {
	
	int counter = 0;
	Node<T>* nextEl = head;
	while (nextEl != nullptr)
	{
		if (counter == index)
		{
			return nextEl->data;
		}
		nextEl = nextEl->pNext;
		counter++;
	}

}


template<class T>
Stack<T>::Stack(int max_number) : data{ new List<T>() }, EMPTY{ -1 }, FULL{ max_number }, top{ EMPTY } {}


template<class T>
Stack<T>::~Stack()
{
	data->clear();
}

template<class T>
bool Stack<T>::isFull()
{
	return top == FULL;
}

template<class T>
bool Stack<T>::isEmpty()
{
	return top == EMPTY;
}

template<class T>
void Stack<T>::push(const T data)
{
	if (!isFull())
	{
		this->data->push_front(data);
		top++;
	}
	else
	{
		FULL++;
		this->data->push_front(data);
		top++;
	}
}

template<class T>
T Stack<T>::pop()
{
	if (!isEmpty())
	{
		T buffer = data->returnData();
		data->pop_front();
		top--;
		return buffer;
	}
	return T();
}

template<class T>
T Stack<T>::getTop()
{
	return data->returnData();
}

template<class T>
int Stack<T>::getCount()
{
	return top + 1;
}

template<class T>
void Stack<T>::clear()
{
	data->clear();
	size = 0;
}
