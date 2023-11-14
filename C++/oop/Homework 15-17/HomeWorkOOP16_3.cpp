#include <iostream>
using namespace std;

template<class T>
class List
{
private:

	template<class T>
	class Node
	{
	public:

		T data;
		Node<T>* next;
		Node<T>* previous;

		Node(T data = T(), Node<T>* next = nullptr, Node<T>* previous = nullptr) : data{ data }, next{ next }, previous{ previous } {}
	
	};

	Node<T>* first;
	Node<T>* last;
	int size;
public:

	List(const List<T>& list) = delete;
	List(const List<T>&& list) = delete;
	List();
	~List();
	//удаление
	void clear();
	void pop_first();
	void pop_back(int index); //удаление с конца по i-го элемента
	void push_first(T data);
	void insert_at(T data, int index);
	void ins_at(T data, int index);
	void remove_at(int index);
	T retFirstValue();
	bool isEmpty();
	//вставка 
	void push_back(T data);
	T& returnValue(int index);
	T returnVal(int index);
};

template<class T>
class Array
{
private:
	List<T>* list;
	int size;
	int countOfElements;
	int grow;
public:
	Array() = delete;
	Array(const Array& array);
	Array(const Array&& array) = delete;
	explicit Array(int size);
	~Array() {
		list->clear();
	}

	int getSize() {
		return size;
	}
	void setSize(int size, int grow = 1);
	int getUpperBound() {
		return countOfElements - 1;
	}
	void setUpperBound() {
		countOfElements++;
		
	}
	bool isEmpty() {
		return countOfElements == 0;
	}
	void freeExtra();
	void removeAll();
	T& getAt(int index) const;
	void setAt(T data, int index);
	

	const T& operator[](int index) const; //возвращаем значение
	T& operator[](int index);//возвращаем значение по ссылке

	void add(T element);//вставляет в конец массива

	void append(const Array<T>& array);

	Array<T>& operator=(const Array<T>& array);


	
	List<T>* getData() {
		return list;
	}
	void insertAt(int index) {
		if (index < 0 or index > size)
		{
			throw "Array index out of bounds";
		}
		list->ins_at(-2147483648, index);
		size++;
	}
	void removeAt(int index) {
		if (index < 0 or index > size)
		{
			throw "Array index out of bounds";
		}
		list->remove_at(index);
		
		if (countOfElements == size)
		{
			countOfElements--;
		}
		size--;
	}
};







int main()
{
	srand(time(NULL));
    setlocale(LC_ALL, "");
    std::cout << "Домашняя работа ООП16.3\n";
	

	
	
	cout << "Создание массива: " << endl;
	Array<int>* arr = new Array<int>(10);
	cout << "Заполнение 5 случайными числами: " << endl;
	for (size_t i = 0; i < 5; i++)
	{
		(*arr)[i] = rand() % 10 +1;
		arr->setUpperBound();//костыль
	}
	cout << "Вывод массива: " << endl;
	for (size_t i = 0; i < arr->getSize(); i++)
	{
		cout << (*arr)[i] << " ";
	}
	cout << endl;
	cout << "Размер массива getSize(): " << arr->getSize() << endl;
	cout << "Установка размера массива setSize(15, 5): " << endl;
	arr->setSize(15, 5);
	cout << "Вывод массива: " << endl;
	for (size_t i = 0; i < arr->getSize(); i++)
	{
		cout << (*arr)[i] << " ";
	}
	cout << "Размер массива getSize(): " << arr->getSize() << endl;
	cout << "Установка размера массива setSize(9, 5): " << endl;
	arr->setSize(9, 5);
	cout << "Вывод массива: " << endl;
	for (size_t i = 0; i < arr->getSize(); i++)
	{
		cout << (*arr)[i] << " ";
	}
	cout << endl;
	cout << "Размер массива getSize(): " << arr->getSize() << endl;
	cout << "Последний допустимый индекс getUpperBound(): " << arr->getUpperBound() << endl;
	cout << "(*arr)[arr->getUpperBound()]: " << (*arr)[arr->getUpperBound()] << endl;
	cout << "Массив пуст? isEmpty(): " << arr->isEmpty() << endl;
	cout << "Удалить лишнюю память freeExtra(): "  << endl;
	arr->freeExtra();
	cout << "Размер массива getSize(): " << arr->getSize() << endl;
	for (size_t i = 0; i < arr->getSize(); i++)
	{
		cout << (*arr)[i] << " ";
	}
	cout << endl;
	cout << "Удалить все removeAll: " << endl;
	arr->removeAll();
	cout << "Размер массива getSize(): " << arr->getSize() << endl;
	for (size_t i = 0; i < arr->getSize(); i++)
	{
		cout << (*arr)[i] << " ";
	}
	cout << endl << endl;
	Array<int>* arr2 = new Array<int>(10);
	
	cout << "Заполнение 5 случайными числами: " << endl;
	for (size_t i = 0; i < 5; i++)
	{
		(*arr2)[i] = rand() % 10 + 1;
		arr2->setUpperBound();//костыль
	}
	cout << "Вывод массива через getAt(index): " << endl;
	for (size_t i = 0; i < arr2->getSize(); i++)
	{
		cout << arr2->getAt(i) << " ";
	}
	cout << endl;
	cout << "Установка нового значения через setAt():" << endl;
	arr2->setAt(12, 5);
	arr2->setAt(13, 6);
	arr2->setAt(14, 7);
	cout << "Вывод массива через getAt(index): " << endl;
	for (size_t i = 0; i < arr2->getSize(); i++)
	{
		cout << arr2->getAt(i) << " ";
	}
	cout << "Заполнение случайными числами через add(data): " << endl;
	for (size_t i = 0; i < 10; i++)
	{
		arr2->add(rand() % 10);
	}
	cout << "Размер массива getSize(): " << arr2->getSize() << endl;
	cout << "Последний допустимый индекс getUpperBound(): " << arr2->getUpperBound() << endl;
	cout << "Вывод массива через getAt(index): " << endl;
	for (size_t i = 0; i < arr2->getSize(); i++)
	{
		cout << arr2->getAt(i) << " ";
	}
	cout <<"Удаление i-го элемента removeAt(i):" << endl;
	for (size_t i = arr2->getSize()-1; i > arr2->getSize()-8; i--)
	{
		arr2->removeAt(i);
	}
	cout << "Вывод массива через getAt(index): " << endl;
	for (size_t i = 0; i < arr2->getSize(); i++)
	{
		cout << arr2->getAt(i) << " ";
	}
	cout << endl;
	Array<int>* arr3 = new Array<int>(3);
	cout << "Заполнение 3 случайными числами arr3: " << endl;
	for (size_t i = 0; i < 3; i++)
	{
		(*arr3)[i] = rand() % 10 + 1;
		arr3->setUpperBound();//костыль
	}
	cout << "Вывод массива arr3: " << endl;
	for (size_t i = 0; i < arr3->getSize(); i++)
	{
		cout << arr3->getAt(i) << " ";
	}
	cout << endl << "Сложение массивов append():" << endl;
	arr2->append(*arr3);
	cout << "Вывод массива через getAt(index): " << endl;
	for (size_t i = 0; i < arr2->getSize(); i++)
	{
		cout << arr2->getAt(i) << " ";
	}
	cout << endl;
	cout << "Оператор =: arr4 = arr3" << endl;
	Array<int>* arr4 = new Array<int>(2);
	arr4 = arr3;
	cout << "Вывод массива arr4: " << endl;
	for (size_t i = 0; i < arr4->getSize(); i++)
	{
		cout << arr4->getAt(i) << " ";
	}
	cout << endl;
	cout << "Получение адреса массива getData(arr2): " << endl;
	cout << arr2->getData() << endl;
	cout << "Вставка элемента в заданную позицию insertAt(): " << endl;
	arr4->insertAt(2);
	arr4->insertAt(2);
	arr4->insertAt(2);
	cout << "Вывод массива arr4: " << endl;
	for (size_t i = 0; i < arr4->getSize(); i++)
	{
		cout << arr4->getAt(i) << " ";
	}
	cout << endl;
}







template<class T>
List<T>::List() : first{ nullptr }, last{ nullptr }, size{ 0 } {}

template<class T>
List<T>::~List()
{
	clear();
}

template<class T>
void List<T>::clear()
{
	Node<T>* current = first;
	
	do
	{
		current = current->next;
		pop_first();
	} while (current != nullptr);
	size = 0;
}

template<class T>
bool List<T>::isEmpty()
{
	return first == nullptr;
}

template<class T>
void List<T>::push_back(T data)
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
T& List<T>::returnValue(int index)
{
	int counter;
	Node<T>* current;
	if (index < size / 2)
	{
		counter = 0;
		current = first;
		while (counter != index)
		{
			
			current = current->next;
			counter++;
		}
	}
	else
	{
		counter = size - 1;
		current = last;
		while (counter != index)
		{
		
			current = current->previous;
			counter--;
		}
	}
	return current->data;
}

template<class T>
T List<T>::returnVal(int index)
{
	int counter;
	Node<T>* current;
	if (index < size / 2)
	{
		counter = 0;
		current = first;
		while (counter != index)
		{

			current = current->next;
			counter++;
		}
	}
	else
	{
		counter = size - 1;
		current = last;
		while (counter != index)
		{

			current = current->previous;
			counter--;
		}
	}
	return current->data;
}



template<class T>
void List<T>::pop_first()
{
	Node<T>* deleteNode = first;
	if (first->next == nullptr)
	{
		last = nullptr;
	}
	else
	{
		first->next->previous = nullptr;
	}
	
	first = first->next;
	delete deleteNode;
}

template<class T>
void List<T>::pop_back(int index)
{
	Node<T>* current;
	int counter = size;
	while (counter != index)
	{
		current = last;
		if (first->next == nullptr)
		{
			first = nullptr;

		}
		else
		{
			last->previous->next = nullptr;

		}
		last = last->previous;
		delete current;
		size--;
		counter--;
	}
}

template<class T>
void List<T>::push_first(T data)
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
void List<T>::insert_at(T data, int index)
{
	Node<T>* current = first;
	int counter = 0;
	while (counter != index)
	{
		current = current->next;
		counter++;
	}
	current->data = data;
	
}

template<class T>
void List<T>::ins_at(T data, int index)
{
	
	if (index == 0)
	{
		push_first(data);
	}
	else if (index == size)
	{
		push_back(data);
	}
	else
	{
		Node<T>* current = first;
		Node<T>* newNode = new Node<T>(data);
		int counter = 0;
		while (counter != index - 1)
		{
			current = current->next;
			counter++;
		}
		current->next->previous = newNode;
		newNode->next = current->next;
		newNode->previous = current;
		current->next = newNode;
		size++;
	}
	
}

template<class T>
void List<T>::remove_at(int index)
{
	Node<T>* current = first;
	int counter = 0;
	while (counter != index)
	{
		current = current->next;
		counter++;
	}
	if (current == first)
	{
		first = current->next;
	}
	else
	{
		current->previous->next = current->next;
	}
	if (current == last)
	{
		last = current->previous;
	}
	else
	{
		current->next->previous = current->previous;
	}
	delete current;
}

template<class T>
T List<T>::retFirstValue()
{
	T remember;
	if (first->data == nullptr)
	{
		return T();
	}
	else
	{
		remember = first->data;
		pop_first();
	}
	

	return remember;
}







template<class T>
Array<T>::Array(const Array& array)
{
	if (array.list->isEmpty() == nullptr)
	{
		list = new List<T>();
		for (size_t i = 0; i < size - 1; i++)
		{
			list->push_back(-2147483648);
		}
		this->size = 0;
		countOfElements = 0;
		grow = 1;
	}else 
	{
		if (!list->isEmpty())
			list->clear();
		list = new List<T>();
		for (size_t i = 0; i < array.countOfElements; i++)
		{
			list->push_back(array.list->retFirstValue);
		}
		this->size = array.size;
		countOfElements = array.countOfElements;
		grow = array.grow;
	}
	
	
}

template<class T>
Array<T>::Array(int size){
	
	if (size < 0)
	{
		throw "";
		
	}
	list = new List<T>();
	for (size_t i = 0; i < size; i++)
	{
		list->push_back(-858993460);
	}
	this->size = size;
	countOfElements = 0;
	grow = 1;
}

template<class T>
void Array<T>::setSize(int size, int grow)
{
	if (size > this->size)
	{
		for (size_t i = 0; i < size - this->size; i++)
		{
			list->push_back(-2147483648);
		}
				
	}
	else
	{
		int temp = this->size - size;
		for (size_t i = 0; i < temp; i++)
		{
			list->pop_back(this->size - 1);
			this->size--;
		}
		if (countOfElements > size)
		{
			this->countOfElements = size;
		}
		
	}
	this->size = size;
	this->grow = grow;
	
}

template<class T>
void Array<T>::freeExtra()
{
	int temp = size - countOfElements;
	for (size_t i = 0; i < temp; i++)
	{
		list->pop_back(size - 1);
		size--;
	}
	
}

template<class T>
void Array<T>::removeAll()
{

	list->clear();
	size = 0;
	countOfElements = 0;
	grow = 0;
}

template<class T>
T& Array<T>::getAt(int index)const
{

	if (index < 0 or index > size)
	{
		throw "Array index out of bounds";
	}
	return list->returnValue(index);
}

template<class T>
void Array<T>::setAt(T data, int index)
{
	if (index < 0 or index > size)
	{
		throw "Array index out of bounds";
	}
	list->insert_at(data, index);
	countOfElements++;
}

template<class T>
const T& Array<T>::operator[](int index) const
{

	if (index < 0 or index > size)
	{
		throw "Array index out of bounds";
	}
	
	return list->returnValue(index);
}

template<class T>
T& Array<T>::operator[](int index)
{
	if (index < 0 or index > size)
	{
		throw "Array index out of bounds";
	}
	
	return list->returnValue(index);
}

template<class T>
void Array<T>::add(T element)
{
	countOfElements++;
	if (countOfElements > size)
	{
	
		for (size_t i = 0; i < grow; i++)
		{
			list->push_back(-2147483648);
		}
		
		
		size += grow;
	}
	list->insert_at(element, countOfElements-1);
	
}

template<class T>
void Array<T>::append(const Array<T>& array)
{

	for (size_t i = 0; i < array.countOfElements; i++)
	{
		add(array[i]);
	}
	
}

template<class T>
Array<T>& Array<T>::operator=(const Array<T>& array)
{
	if (this == &array)
	{
		return *this;
	}
	list->clear();
	for (size_t i = 0; i < array.size; i++)
	{
		list->push_back(array[i]);
	}
	return *this;
}





