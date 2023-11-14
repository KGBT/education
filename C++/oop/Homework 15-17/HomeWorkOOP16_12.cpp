#include <iostream>
#include <time.h>
#include <Windows.h>
using namespace std;



template<class T>
class DoublyLink
{
public:
	DoublyLink();
	DoublyLink(const DoublyLink<T>& list);
	~DoublyLink();

	bool isEmpty();
	void push_front(T data);
	void push_back(T data);
	void push_at(T data, int position);
	T pop_front();
	T pop_back();
	T pop_at(int position);
	void delete_front();
	void clear();
	int getSize();

	T& operator[](const int index);
	DoublyLink<T>& operator=(const DoublyLink<T>& list);
	
	DoublyLink<T>& operator+(const DoublyLink& list);
	DoublyLink<T>& operator*(const DoublyLink& list);

private:
	template<class T>
	class Node
	{
	public:
		T data;
		Node* next;
		Node* previous;
		Node(T data = T(), Node* next = nullptr, Node* previous = nullptr) :
			data{ data }, next{ next }, previous{ previous } {}
	
	};

	Node<T>* first;
	Node<T>* last;
	int size;
};


template<class T>
class Queue
{
public:
	Queue() = delete;
	Queue(const Queue&) = delete;
	Queue(const Queue&&) = delete;
	explicit Queue(int maxSize);
	~Queue();

	bool isEmpty();
	bool isFull();
	void add(T data);
	T extract();
	int getQueueLength();
	void clear();
	void showQueue();
private:
	DoublyLink<T> list;
	int queLength;
	int FULL;
	
};










int main()
{
	setlocale(LC_ALL, "");
	srand(time(NULL));
	/*
    std::cout << "Домашнее задание ООП 16.1\n";
	cout << "Очередь на двухсвязном списке: " << endl;
	Queue<int>* que = new Queue<int>(10);

	for (size_t i = 0; i < 10; i++)
	{
		que->add(rand() % 10);
	}
	que->showQueue();
	cout << endl;
	cout << "Уход из очереди:" << endl;
	for (size_t i = 0; i < 9; i++)
	{
		Sleep(1000);
		cout << que->extract() << " ";
	}
	cout << endl;
	cout << "Отсалось в очереди: " << endl;
	que->showQueue();
	cout << endl;
	*/

	std::cout << "Домашнее задание ООП 16.2\n";
	DoublyLink<int> list1;
	cout << "Заполнение списка случайными числами: " << endl;
	for (size_t i = 0; i < 4; i++)
	{
		list1.push_front(rand() % 10 + 1);
	}
	cout << endl;
	cout << "Список list1: " << endl;
	for (size_t i = 0; i < 4; i++)
	{
		cout << list1[i] << " ";
	}
	cout << endl;
		
	DoublyLink<int> list2 = list1;
	cout << "Список list2: " << endl;
	for (size_t i = 0; i < 4; i++)
	{
		cout << list2[i] << " ";
	}
	cout << endl;

	DoublyLink<int> list3;
	list3 = list1 + list2;
	cout << "Список list3 = list1 + list2: " << endl;
	for (size_t i = 0; i < list3.getSize(); i++)
	{
		cout << list3[i] << " ";
	}
	cout << endl;

	DoublyLink<int> list4;
	list4 = list1 * list2;
	cout << "Список list4 = list1 * list2: " << endl;
	for (size_t i = 0; i < list4.getSize(); i++)
	{
		cout << list4[i] << " ";
	}
	cout << endl;

	DoublyLink<int> list5;
	for (size_t i = 0; i < 4; i++)
	{
		list5.push_front(rand() % 10 + 1);
	}
	cout << endl;
	cout << "Список list5: " << endl;
	for (size_t i = 0; i < list5.getSize(); i++)
	{
		cout << list5[i] << " ";
	}
	cout << endl;

	DoublyLink<int> list6;
	list6 = list5 * list3;
	cout << "Список list6 = list5 * list3: " << endl;
	if (list6.isEmpty())
	{
		cout << "Нет общих элементов." << endl;
	}
	else
	{
		for (size_t i = 0; i < list6.getSize(); i++)
		{
			cout << list6[i] << " ";
		}
		cout << endl;
	}
	
}












template<class T>
DoublyLink<T>::DoublyLink() : first{ nullptr }, last{ nullptr }, size{ 0 } {}

template<class T>
DoublyLink<T>::DoublyLink(const DoublyLink<T>& list)
{
	Node<T>* current = list.first;
	do
	{
		push_back(current->data);
		current = current->next;
	} while (current != nullptr);
	
}

template<class T>
DoublyLink<T>::~DoublyLink()
{
	
	clear();
	
}

template<class T>
bool DoublyLink<T>::isEmpty()
{
	return first == nullptr;
}

template<class T>
void DoublyLink<T>::push_front(T data)
{
	Node<T>* newNode = new Node<T>(data);
	if (isEmpty())
	{
		last = newNode;
	}
	else
	{
		
		first->previous = newNode;
			
	}
	newNode->next = first;
	first = newNode;
	size++;
}

template<class T>
void DoublyLink<T>::push_back(T data)
{
	Node<T>* newNode = new Node<T>(data);
	if (isEmpty())
	{
		first = newNode;
	}
	else
	{
		last->next = newNode;
		newNode->previous = last;
	}
	last = newNode;
	size++;
}

template<class T>
void DoublyLink<T>::push_at(T data, int position)
{
	Node<T>* newNode = new Node<T>(data);
	Node<T>* prev = first;
	int counter = 0;
	
	if(position == size)
	{
		newNode->next = nullptr;
		last = newNode;
	}
	else
	{
		while (prev->next != nullptr)
		{
			if (counter == position - 2)
			{
				break;
			}
			counter++;
			prev = prev->next;
		}
		
		newNode->next = prev->next;
		prev->next->previous = newNode;
		
	}
	newNode->previous = prev;
	prev->next = newNode;
	size++;
	
	
}

template<class T>
T DoublyLink<T>::pop_front()
{
	Node<T>* temp = first;
	T tempData = first->data;

	if (first->next == nullptr)
	{
		last = nullptr;
	
	}
	else
	{
		first->next->previous = nullptr;
	}
	first = first->next;
	delete temp;
	size--;
	return tempData;
}

template<class T>
T DoublyLink<T>::pop_back()
{
	Node<T>* temp = last;
	T tempData = last->data;

	if (first->next == nullptr)
	{
		first = nullptr;

	}
	else
	{
		last->previous->next = nullptr;
	}
	last = last->previous;
	delete temp;
	size--;
	return tempData;
}

template<class T>
T DoublyLink<T>::pop_at(int position)
{
	Node<T>* prev = first;
	Node<T>* current;
	T temp = T();
	int counter = 0;

	if (position == size)
	{
		temp = pop_back();
	}
	else if (position == 0)
	{
		temp = pop_front();
	}
	else
	{
		while (prev->next != nullptr)
		{
			if (counter == position - 1)
			{
				break;
			}
			counter++;
			prev = prev->next;
		}
		current = prev;
		temp = current->data;
		prev->previous->next = prev->next;
		prev->next->previous = prev->previous;
		size--;
		delete current;
	}
		
	return temp;
}

template<class T>
void DoublyLink<T>::delete_front()
{
	Node<T>* temp = first;
	if (first->next == nullptr)
	{
		
		last = nullptr;
	}
	else
	{
		first->next->previous = nullptr;
		
	}
	first = first->next;
	size--;
	delete temp;
	
}

template<class T>
void DoublyLink<T>::clear()
{
	while (size)
	{
		delete_front();
	}
	
}

template<class T>
int DoublyLink<T>::getSize()
{
	return size;
}

template<class T>
T& DoublyLink<T>::operator[](const int index)
{
	int counter;
	Node<T>* temp;
	if (index<= size / 2)
	{
		temp = first;
		counter = 0;
		while (temp->next != nullptr)
		{
			if (counter == index)
			{
				return temp->data;
			}
			temp = temp->next;
			counter++;
		}
	}
	else
	{
		
		temp = last;
		counter = size;
		while (temp->previous != nullptr)
		{
			if (counter - 1 == index)
			{
				return temp->data;
			}
			temp = temp->previous;
			counter--;
		}
	}
	return temp->data;
}

template<class T>
DoublyLink<T>& DoublyLink<T>::operator+(const DoublyLink& list)
{
	Node<T>* current = first;
	Node<T>* currentList = list.first;
	DoublyLink<T>* newLink = new DoublyLink<T>();
	do
	{
		newLink->push_back(current->data);
		current = current->next;
	} while (current != nullptr);
	do
	{
		newLink->push_back(currentList->data);
		currentList = currentList->next;
	} while (currentList != nullptr);
	return *newLink;
}

template<class T>
DoublyLink<T>& DoublyLink<T>::operator*(const DoublyLink& list)
{
	Node<T>* current = first;
	Node<T>* currentList = list.first;
	DoublyLink<T>* newList = new DoublyLink<T>();
	do
	{
		do
		{
			if (currentList->data == current->data)
			{
				newList->push_back(currentList->data);
				break;
			}
			currentList = currentList->next;
		} while (currentList != nullptr);

		current = current->next;
		currentList = list.first;

	} while (current != nullptr);
	
	return *newList;
}

template<class T>
DoublyLink<T>& DoublyLink<T>::operator=(const DoublyLink<T>& list)
{
	if (this == &list)
	{
		return *this;
	}
	clear();
	Node<T>* current = list.first;
	if (current != nullptr)
	{
		do
		{
			push_back(current->data);
			current = current->next;
		} while (current != nullptr);
	}
	return *this;
}

template<class T>
Queue<T>::Queue(int maxSize) : queLength{ 0 }, FULL{ maxSize } {}

template<class T>
Queue<T>::~Queue()
{
	clear();
	
}


template<class T>
bool Queue<T>::isEmpty()
{
	return queLength == 0;
}

template<class T>
bool Queue<T>::isFull()
{
	return FULL == queLength;
}

template<class T>
void Queue<T>::add(T data)
{
	if (!isFull())
	{
		list.push_back(data);
		queLength++;
	}
	else
	{
		cout << "Очередь заполнена." << endl;
	}
}

template<class T>
T Queue<T>::extract()
{
	T temp = T();
	if (!isEmpty())
	{
		temp = list.pop_front();
		queLength--;
	}
	
	return temp;
}

template<class T>
int Queue<T>::getQueueLength()
{
	return queLength;
}

template<class T>
void Queue<T>::clear()
{
	list.clear();
	queLength = 0;
}

template<class T>
void Queue<T>::showQueue()
{
	for (size_t i = 0; i < queLength; i++)
	{
		Sleep(1000);
		cout << list[i] << " ";
	}
}
