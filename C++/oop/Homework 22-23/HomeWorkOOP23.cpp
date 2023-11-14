#include <iostream>
#include<time.h>
using namespace std;
namespace myMatrix {
	template<class data>
	class Matrix
	{
		int rows;
		int columns;
		data** matrix;

	public:
		Matrix() = delete;
		Matrix(int rows, int columns);
		Matrix(const Matrix&);
		Matrix(Matrix&&) noexcept;
		~Matrix();

		void DelMatrix();
		void InputKeyMatrix();
		void RandomMatrix(int range);
		void RandomMatrix(int min, int max);
		void OutputMatrix();
		void OutputMatrix() const;
		data MaxEl();
		data MinEl();

		data operator()(int i, int j) const {
			return matrix[i][j];
		}
		Matrix& operator=(const Matrix& matrix) {
			if (this == &matrix)
			{
				return *this;
			}

			if ((rows != matrix.rows) or (columns != matrix.columns))
			{
				DelMatrix();
				this->matrix = new data * [rows];
				for (size_t i = 0; i < rows; i++)
				{
					*(this->matrix + i) = new data[columns];
				}
				rows = matrix.rows;
				columns = matrix.columns;
			}
			for (size_t i = 0; i < rows; i++)
			{
				for (size_t j = 0; j < columns; j++)
				{
					this->matrix[i][j] = matrix(i, j);
				}
			}
		}
		Matrix& operator=(Matrix&& matrix) noexcept {
			if (this == &matrix)
			{
				return*this;
			}
			DelMatrix();
			rows = matrix.rows;
			columns = matrix.columns;
			this->matrix = matrix.matrix;
			matrix.rows = 0;
			matrix.columns = 0;
			matrix.matrix = nullptr;

		}
		Matrix operator+(const Matrix& matrix) {
			if (rows != matrix.rows or columns != matrix.columns)
			{
				cout << "Ошибка! Невозможно сложить матрицы!" << endl;
				_exit(1);

			}
			Matrix buff(rows, columns);
			for (size_t i = 0; i < rows; i++)
			{
				for (size_t j = 0; j < columns; j++)
				{
					buff.matrix[i][j] = this->matrix[i][j] + matrix(i, j);
				}
			}
			return buff;
		}
		Matrix operator-(const Matrix& matrix) {
			if (rows != matrix.rows or columns != matrix.columns)
			{
				cout << "Ошибка! Невозможно сложить матрицы!" << endl;
				_exit(1);

			}
			Matrix buff(rows, columns);
			for (size_t i = 0; i < rows; i++)
			{
				for (size_t j = 0; j < columns; j++)
				{
					buff.matrix[i][j] = this->matrix[i][j] - matrix(i, j);
				}
			}
			return buff;
		}
		Matrix operator*(const Matrix& matrix) {
			if (rows != matrix.rows or columns != matrix.columns)
			{
				cout << "Ошибка! Невозможно сложить матрицы!" << endl;
				_exit(1);

			}
			Matrix buff(rows, columns);
			for (size_t i = 0; i < rows; i++)
			{
				for (size_t j = 0; j < columns; j++)
				{
					buff.matrix[i][j] = this->matrix[i][j] * matrix(i, j);
				}
			}
			return buff;
		}
		Matrix operator/(const Matrix& matrix) {
			if (rows != matrix.rows or columns != matrix.columns)
			{
				cout << "Ошибка! Невозможно сложить матрицы!" << endl;
				_exit(1);

			}
			Matrix buff(rows, columns);
			for (size_t i = 0; i < rows; i++)
			{
				for (size_t j = 0; j < columns; j++)
				{
					if (matrix(i, j) == 0)
					{
						cout << "Деление на 0." << endl;
						buff.matrix[i][j] = 0;
					}
					else
					{
						buff.matrix[i][j] = this->matrix[i][j] / matrix(i, j);
					}

				}
			}
			return buff;
		}
	};
	template<class data>
	Matrix<data>::Matrix(int rows, int columns) : rows{ rows }, columns{ columns }
	{
		matrix = new data * [rows];
		for (size_t i = 0; i < rows; i++)
		{
			*(matrix + i) = new data[columns];
		}
	}
	template<class data>
	Matrix<data>::Matrix(const Matrix& matrix) : Matrix(matrix.rows, matrix.columns) {
		for (size_t i = 0; i < rows; i++)
		{
			for (size_t j = 0; j < columns; j++)
			{
				this->matrix[i][j] = matrix(i, j);
			}
		}
	}
	template<class data>
	Matrix<data>::Matrix(Matrix&& matrix) noexcept : rows{ matrix.rows },
		columns{ matrix.columns }, matrix{ matrix.matrix }
	{
		matrix.rows = 0;
		matrix.columns = 0;
		matrix.matrix = nullptr;
	}
	template<class data>
	Matrix<data>::~Matrix()
	{
		DelMatrix();
	}



	template<class data>
	void Matrix<data>::DelMatrix() {
		if (matrix != nullptr)
		{
			for (size_t i = 0; i < rows; i++)
			{
				delete[] matrix[i];
			}
			delete[] matrix;
			//cout << "Матрица удалена!" << endl;
		}

	}
	template<class data>
	void Matrix<data>::InputKeyMatrix() {

		cout << "Вводите значения с клавиатуры: " << endl;
		for (size_t i = 0; i < rows; i++)
		{
			for (size_t j = 0; j < columns; j++)
			{
				cin >> matrix[i][j];
			}
		}
	}
	template<class data>
	void Matrix<data>::RandomMatrix(int range) {



		double value;

		for (size_t i = 0; i < rows; i++)
		{
			for (size_t j = 0; j < columns; j++)
			{
				value = rand() % (int)pow(10, 2);
				matrix[i][j] = (value / pow(10, 2)) * (range);
			}
		}

	}
	template<class data>
	void Matrix<data>::RandomMatrix(int min, int max) {



		double value;

		for (size_t i = 0; i < rows; i++)
		{
			for (size_t j = 0; j < columns; j++)
			{
				value = rand() % (int)pow(10, 2);
				matrix[i][j] = min + (value / pow(10, 2)) * (max - min);
			}
		}
	}
	template<class data>
	void Matrix<data>::OutputMatrix() {
		for (size_t i = 0; i < rows; i++)
		{
			for (size_t j = 0; j < columns; j++)
			{
				cout << matrix[i][j] << " ";
			}
			cout << endl;
		}
	}
	template<class data>
	void Matrix<data>::OutputMatrix() const {
		for (size_t i = 0; i < rows; i++)
		{
			for (size_t j = 0; j < columns; j++)
			{
				cout << matrix[i][j] << " ";
			}
			cout << endl;
		}
	}
	template<class data>
	data Matrix<data>::MaxEl() {
		data max = matrix[0][0];
		for (size_t i = 0; i < rows; i++)
		{
			for (size_t j = 0; j < columns; j++)
			{
				if (max < matrix[i][j])
				{
					max = matrix[i][j];
				}
			}
		}
		return max;
	}
	template<class data>
	data Matrix<data>::MinEl() {
		data min = matrix[0][0];
		for (size_t i = 0; i < rows; i++)
		{
			for (size_t j = 0; j < columns; j++)
			{
				if (min > matrix[i][j])
				{
					min = matrix[i][j];
				}
			}
		}
		return min;
	}



	class DynArray
	{
	private:
		int* arr;
		int size;
	public:
		DynArray(int sizeP) : arr{ new int[sizeP] {} }, size{ sizeP } {
			cout << "Массив создан для " << this << " размером " << size << endl;

		}
		DynArray() :DynArray(5) {}
		DynArray(const DynArray& object) : arr{ new int[object.size] }, size{ object.size } {
			for (int i = 0; i < object.size; i++)
			{
				*(arr + i) = *(object.arr + i);
			}
			cout << "Массив скопирован с помощью конструктора для " << this << " размером " << size << endl;
		}

		DynArray(DynArray&& object) noexcept : arr{ object.arr }, size{ object.size } {
			object.arr = nullptr;
			object.size = 0;
			cout << "Массив перемещен консруктором для " << this << " размером " << size << endl;
		}

		DynArray& operator=(const DynArray& object) {
			if (this != &object)
			{
				if (size != object.size)
				{
					delete[]arr;
					arr = new int[object.size];

				}
				size = object.size;
				int* dest{ arr }; //указатель на начало массива назначения, то есть куда
				int* src{ object.arr }; //указатель на массив откуда копировать 
				int* const end{ arr + size }; //указатель на конец массива
				while (dest < end)
				{
					*dest++ = *src++; //копирует элементы

				}

			}
			cout << "Массив скопирован с помощью = для " << this << " размером " << size << endl;
			return *this; //проверить на dest
		}
		int getElement(int idx) {
			return *(arr + idx);
		}
		void setElement(int idx, int el) {
			*(arr + idx) = el;
		}
		void print() {
			for (int i = 0; i < size; i++)
			{
				cout << *(arr + i) << " ";
			}
		}
		void random() {
			for (int i = 0; i < size; i++)
			{
				*(arr + i) = rand() % 10;
			}
		}
		~DynArray();

	private:

	};

	DynArray::~DynArray()
	{
		if (arr != nullptr)
		{
			delete[] arr;
		}
	}

	DynArray ArrayFactory(int arrSize) {
		DynArray arr{ arrSize };
		arr.random();
		return arr;
	}














}
namespace myString {

	class String
	{
	private:
		static int countStr;
		char* str;
		int length;
	public:
		String(const char* str1, int length) : str{ str1 ? new char[strlen(str1) + 1] : nullptr }, length{ length } {
			setCountStr();
			setStr(str1);
		}
		String() : String{ nullptr, 80 } {}
		String(int length) : String{ nullptr, length } {}
		String(const char* str) : String{ str, strlen(str) } {}
		String(const String& str) {
			this->str = new char[strlen(str.str) + 1];
			strcpy_s(this->str, strlen(str.str) + 1, str.str);
			this->length = str.length;
		}
		String(String&& str) noexcept : str{ str.str }, length{ str.length } {
			str.str = nullptr;
			str.length = 0;
			cout << "Отработал конструктор перемещения." << endl;
		}
		~String();

		int getLength() {
			return length;
		}
		char* getStr() {
			return str;
		}

		String& setStr(const char* str1) {
			if (str1 != nullptr)
			{
				delete[] str;
				str = new char[strlen(str1) + 1];
				strcpy_s(str, strlen(str1) + 1, str1);
				length = strlen(str1);
			}

			return *this;
		}

		static int getCountStr() {
			return countStr;
		}

		void PrintStr() {
			cout << str;
		}
		void PrintLeng() {
			cout << length;
		}
		void InputStr() {

			cout << "Введите строку: " << endl;
			char st[200];
			gets_s(st, 200);
			if (str != nullptr)
			{
				delete[] str;

			}
			str = new char[strlen(st) + 1];
			strcpy_s(str, strlen(st) + 1, st);
			length = strlen(str);

		}

	private:
		static void setCountStr() {
			countStr++;
		}
	};
	String::~String()
	{
		if (str != NULL)
		{
			delete[]str;
			cout << "Деструктор" << endl;
		}


	}
	int String::countStr{ 0 };
	String StringFactory(int strSize) {
		String str{ strSize };
		str.InputStr();
		return str;
	}
}

int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));
    std::cout << "Домашнее задание ООП23!\n";
	cout << "Класс Matrix в пространстве имен myMatrix: " << endl;
	myMatrix::Matrix<int> matr(3, 3);
	matr.RandomMatrix(1, 10);
	cout << "Вывод матрицы: " << endl;
	matr.OutputMatrix();
	cout << "Класс DynArray в пространстве имен myMatrix: " << endl;
	myMatrix::DynArray array(6);
	array.random();
	cout << "Вывод одномерного массива: " << endl;
	array.print();
	cout << endl << "Класс String в пространстве имен myString: " << endl;
	myString::String str("Это моя самая длинная строка!");
	cout << "Вывод строки: " << endl;
	str.PrintStr();
	cout << endl;
	cout << "Длина строки: ";
	str.PrintLeng();
	cout << endl;
	


}

