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

int main()
{
	setlocale(LC_ALL, "");
	srand(time(NULL));
	
	std::cout << "Домашнее задание ООП 22.1\n";
	DoublyLink<int> list1;
	cout << "Удаление из пустого списка delete_front():" << endl;
	list1.delete_front();
	cout << "Удаление из пустого списка pop_front():" << endl;
	list1.pop_front();
	cout << "Удаление из пустого списка pop_at(2) по позиции:" << endl;
	list1.pop_at(2);
	
	cout << "Добавление push_at(2,5) по позиции:" << endl;
	list1.push_at(2, 5);

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
	cout << "Размер списка: " << list1.getSize() << endl;
	list1.push_at(999, 2);
	cout << "Список list1: " << endl;
	for (size_t i = 0; i < list1.getSize(); i++)
	{
		cout << list1[i] << " ";
	}
	cout << endl<< "Добавление в список элемента за пределами размера push_at(666, 12): " << endl;
	list1.push_at(666, 5);
	cout << "Список list1: " << endl;
	for (size_t i = 0; i < list1.getSize(); i++)
	{
		cout << list1[i] << " ";
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
	try
	{
		Node<T>* newNode = new Node<T>(data);
		if (!newNode)
		{
			throw "Ошибка выделении памяти!";
		}
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
	catch (const char* error)
	{
		cout << error << endl;
	}

}

template<class T>
void DoublyLink<T>::push_back(T data)
{
	try
	{
		Node<T>* newNode = new Node<T>(data);
		if (!newNode)
		{
			throw "Ошибка выделения памяти!";
		}
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
	catch (const char* error)
	{
		cout << error << endl;
	}
	
}

template<class T>
void DoublyLink<T>::push_at(T data, int position)
{
	try
	{
		if (position < 0 or position >= size)
		{
			throw "Выход за пределы списка!";
		}
		Node<T>* newNode = new Node<T>(data);
		if (!newNode)
		{
			throw "Ошибка выделения памяти!";
		}
		Node<T>* prev = first;
		int counter = 0;

		if (position == size)
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
	catch (const char* error)
	{
		cout << error << endl;
	}
	
}

template<class T>
T DoublyLink<T>::pop_front()
{
	try
	{
		if (first == nullptr)
		{
			throw "Удаление из пустого списка!";
		}
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
	catch (const char* error)
	{
		cout << error << endl;
	}
}

template<class T>
T DoublyLink<T>::pop_back()
{
	try
	{
		if (last == nullptr)
		{
			throw "Удаление из пустого списка!";
		}
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
	catch (const char* error)
	{
		cout << error << endl;
	}
}

template<class T>
T DoublyLink<T>::pop_at(int position)
{
	
	try
	{
		if (position<0 or position>size)
		{
			throw "Выход за пределы списка!";
		}
		if (first == nullptr or last == nullptr)
		{
			throw "Удаление из пустого списка!";
		}
		T temp = T();
		Node<T>* prev = first;
		Node<T>* current;

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
	catch (const char* error)
	{
		cout << error << endl;
	}
	

	
}

template<class T>
void DoublyLink<T>::delete_front()
{
	try
	{
		if (first == nullptr)
		{
			throw "Удаление из пустого списка!";
		}
		
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
	catch (const char* exeption)
	{
		cout << exeption << endl;
	}

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
	try
	{
		
		int counter;
		Node<T>* temp;
		if (index <= size / 2)
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
	catch (const char* exeption)
	{
		cout << exeption << endl;
	}
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
