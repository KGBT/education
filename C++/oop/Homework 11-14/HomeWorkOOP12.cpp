#include <iostream>
using namespace std;



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
			this->matrix = new data*[rows];
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
	matrix = new data*[rows];
	for (size_t i = 0; i < rows; i++)
	{
		*(matrix + i) = new data[columns];
	}
}
template<class data>
Matrix<data>::Matrix(const Matrix& matrix) : Matrix(matrix.rows, matrix.columns){
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < columns; j++)
		{
			this->matrix[i][j] = matrix(i, j);
		}
	}
}
template<class data>
Matrix<data>::Matrix(Matrix&& matrix) noexcept : rows{matrix.rows}, 
columns{ matrix.columns }, matrix{matrix.matrix}
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






int main()
{
	setlocale(LC_ALL, "");
	srand(time(NULL));
    std::cout << "Домашняя работа ООП12\n";
	cout << "Матрица m1." << endl;
	Matrix<int> m1(3, 3);
	cout << "Заполнение с клавиатуры: " << endl;
	m1.InputKeyMatrix();
	m1.OutputMatrix();

	cout << endl;
	cout << "Матрица m2." << endl;
	Matrix<int> m2(m1);
	cout << "Заполнение случайными числами: " << endl;
	m2.RandomMatrix(10);
	m2.OutputMatrix();

	cout << endl;
	
	Matrix<int> m3(3, 3);
	cout << "Сложение:" << endl;
	m3 = m1 + m2;
	m3.OutputMatrix();
	cout << endl;

	cout << "Вычитание:" << endl;
	m3 = m1 - m2;
	m3.OutputMatrix();
	cout << endl;

	cout << "Умножение:" << endl;
	m3 = m1 * m2;
	m3.OutputMatrix();
	cout << endl;

	cout << "Деление:" << endl;
	m3 = m1 / m2;
	m3.OutputMatrix();
	cout << endl;

	cout << "Max in m1: " << m1.MaxEl() << endl;
	cout << "Min in m2: " << m1.MinEl() << endl;

	cout << endl << endl << endl;

	cout << "Матрица m4." << endl;
	Matrix<double> m4(3, 3);
	cout << "Заполнение случайными числами: " << endl;
	m4.RandomMatrix(10);
	m4.OutputMatrix();

	cout << endl;
	cout << "Матрица m5." << endl;
	Matrix<double> m5(3,3);
	cout << "Заполнение случайными числами: " << endl;
	m5.RandomMatrix(10);
	m5.OutputMatrix();

	cout << endl;

	Matrix<double> m6(3, 3);
	cout << "Сложение:" << endl;
	m6 = m4 + m5;
	m6.OutputMatrix();
	cout << endl;

	cout << "Вычитание:" << endl;
	m6 = m4 - m5;
	m6.OutputMatrix();
	cout << endl;

	cout << "Умножение:" << endl;
	m6 = m4 * m5;
	m6.OutputMatrix();
	cout << endl;

	cout << "Деление:" << endl;
	m6 = m4 / m5;
	m6.OutputMatrix();
	cout << endl;

	cout << "Max in m4: " << m4.MaxEl() << endl;
	cout << "Min in m4: " << m4.MinEl() << endl;

	cout << endl;

}
