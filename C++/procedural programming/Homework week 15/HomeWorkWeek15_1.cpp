#include <iostream>
using namespace std;

float Max(int* massive, const int SIZE) {

    int max = *(massive);

    for (int i = 0; i < SIZE; i++)
    {
        if (max < *(massive+i))
        {
            max = *(massive+i);
        }
    }
    return max;
   
}
float Min(int* massive, const int SIZE) {

    int min = *(massive);

    for (int i = 0; i < SIZE; i++)
    {
        if (min > *(massive+i))
        {
            min = *(massive+i);
        }
    }
    return min;

}
float Avg(int* massive, const int SIZE) {

   float avg = 0;

    for (int i = 0; i < SIZE; i++)
    {
        avg += *(massive + i);
    }
    avg = avg / SIZE;
    return avg;

}
void InitArr(int* arr, const int SIZE) {

    for (int i = 0; i < SIZE; i++)
    {
        *(arr + i) = rand() % 10 + 1;
    }
}
void PrintArr(int* arr, const int SIZE) {

    for (int i = 0; i < SIZE; i++)
    {
        cout << *(arr + i) << " ";
    }
    cout << "\n";
}
int main()
{
    setlocale(LC_ALL, "ru");
    srand(time(NULL));
    const int SIZE1 = 12;
    int massive1[SIZE1];
    InitArr(massive1, SIZE1);
    PrintArr(massive1, SIZE1);
    float(*Action())(int*, const int);
    float(*function)(int*, const int);
    float result;
    while (true)
    {
        function = Action();
        result = function(massive1, SIZE1);
        if (result == NULL)
        {
            break;
        }
        cout << "Результат выполнения: " << result << endl;
    }
    
}

float(*Action())(int*, const int){

    int choice;
    float (*functions[])(int*, const int) = {Max, Min, Avg};
    do
    {
        cout << "\tМеню: " << endl;
        cout << "1 - max" << endl;
        cout << "2 - min" << endl;
        cout << "3 - avg" << endl;
        cout << "4 - exit" << endl;
        cout << "Выберите пункт в меню: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
           
            return functions[0];

            break;
        case 2:

            return functions[1];

            break;
        case 3:

            return functions[2];

            break;
        case 4:
            cout << "Пока!" << endl;
            return NULL;
            break;
        default:
            cout << "Ошибка! Повторите ввод!" << endl;
            break;
        }
    } while (choice != 4);


}
