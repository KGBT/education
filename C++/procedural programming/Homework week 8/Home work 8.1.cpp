#include <iostream>
#include <Windows.h>
#include <time.h>
#include <string>
using namespace std;


void HodIgrokov(bool &hod, string &enter, int &dice1, int& dice2, int &totalScPl, int &totalScComp) { // & - позволяет передовать переменную по ссылке
   
    if (hod) {
        
        cout << "Ход игрока!" << endl;
        cout << "Чтобы совершить бросок нажмите ENTER." << endl;
        getline(cin, enter);
        cout << "Бросаем кубики..." << endl;
        Sleep(1000);
        dice1 = rand() % 6 + 1;
        dice2 = rand() % 6 + 1;
        totalScPl += dice1 + dice2; // подсчет очков
        hod = !hod; // меняемся ходами
        
    }
    else {
        cout << "Ход компьютера!" << endl << endl;
        cout << "Бросаем кубики..." << endl;
        Sleep(1000);
        dice1 = rand() % 6 + 1;
        dice2 = rand() % 6 + 1;
        totalScComp += dice1 + dice2;
        hod = !hod;
    }
}

void Cube(int dice) {
    switch (dice)
    {
    case 1:
    {
        cout << "===========" << "\n";
        cout << "|         |" << "\n";
        cout << "|         |" << "\n";
        cout << "|    *    |" << "\n";
        cout << "|         |" << "\n";
        cout << "|         |" << "\n";
        cout << "===========" << "\n";
        break;
    }
    case 2:
    {
        cout << "===========" << "\n";
        cout << "|         |" << "\n";
        cout << "|  *      |" << "\n";
        cout << "|         |" << "\n";
        cout << "|      *  |" << "\n";
        cout << "|         |" << "\n";
        cout << "===========" << "\n";
        break;
    }
    case 3:
    {
        cout << "===========" << "\n";
        cout << "|         |" << "\n";
        cout << "|  *      |" << "\n";
        cout << "|    *    |" << "\n";
        cout << "|      *  |" << "\n";
        cout << "|         |" << "\n";
        cout << "===========" << "\n";
        break;
    }
    case 4:
    {
        cout << "===========" << "\n";
        cout << "|         |" << "\n";
        cout << "|  *   *  |" << "\n";
        cout << "|         |" << "\n";
        cout << "|  *   *  |" << "\n";
        cout << "|         |" << "\n";
        cout << "===========" << "\n";
        break;
    }
    case 5:
    {
        cout << "===========" << "\n";
        cout << "|         |" << "\n";
        cout << "|  *   *  |" << "\n";
        cout << "|    *    |" << "\n";
        cout << "|  *   *  |" << "\n";
        cout << "|         |" << "\n";
        cout << "===========" << "\n";
        break;
    }
    case 6:
    {
        cout << "===========" << "\n";
        cout << "|         |" << "\n";
        cout << "|  *   *  |" << "\n";
        cout << "|  *   *  |" << "\n";
        cout << "|  *   *  |" << "\n";
        cout << "|         |" << "\n";
        cout << "===========" << "\n";
        break;
    }
    }

}

void Game(int num, int &hp, int &answer, bool flag, int counter) {
    char sym;

    if (flag)
        cout << "Уровень первый. Раунд " << counter << endl;
    else
        cout << "Уровень второй. Раунд " << counter << endl;

    do
    {
        
        cout << "Количество жизней: " << hp << endl;
        cout << "Какое число загадал компьютер?" << endl;
        cout << "Ваше число: ";
        cin >> answer;
        if (answer != num)
        {
            Sleep(1000);
            cout << "Вы не угадали! Вы теряете 1 жизнь!" << endl;
            hp--;

            if (hp == 0)
            {
                break;
            }

            do
            {
                cout << "Хотите воспользоваться подсказкой? Подсказка стоит жизнь!" << endl;
                cout << "Y - Да, N - Нет." << endl;
                cin >> sym;
                if (sym == 'Y' || sym == 'y')
                {
                    hp--;
                    if (answer > num)
                        cout << "Загаданное число меньше вашего!" << endl;
                    else
                        cout << "Загаданное число больше вашего!" << endl;
                    break;
                }
                else if (sym == 'N' || sym == 'n')
                {
                    break;
                }
                else
                    cout << "Ошибка! Повторите ввод!" << endl;
            } while (true);

        }
        
     } while (answer != num);
     
}

void Congratulation(int &scoreUser, int &scoreComp, int &answer, int num, int &hp, bool flag) {

    int intermediateScore = 0;

    if (answer == num)
    {
        cout << "Поздравляю! Вы угадали число! Это число: " << num << "!" << endl;
        if (flag)
        {
            intermediateScore = hp * 5;
            scoreUser += intermediateScore;
            cout << "Количество очков Игрока после раунда составляет: " << intermediateScore << endl;
            cout << "Общее количество очков: " << scoreUser << endl;
        }
        else 
        {
            intermediateScore = hp * 10;
            scoreUser += intermediateScore;
            cout << "Количество очков Игрока после раунда составляет: " << intermediateScore << endl;
            cout << "Общее количество очков: " << scoreUser << endl;
        }
        
    }
    else {

        if (flag)
        {
            intermediateScore = 5 * 5;
            scoreComp += intermediateScore;
            cout << "Количество очков Компьютера после раунда составляет: " << intermediateScore << endl;
            cout << "Общее количество очков: " << scoreComp << endl;
        }
        else 
        {
            intermediateScore = 24 * 10;
            scoreComp += intermediateScore;
            cout << "Количество очков Компьютера после раунда составляет: " << intermediateScore << endl;;
            cout << "Общее количество очков: " << scoreComp << endl;
        }
    
    }

   
    
}


int main()
{

    
    typedef unsigned int uint;
    setlocale(LC_ALL, "Rus");
    /*
    char symbol = ' ';
    int option, optionDelay, delay = 0;
    cout << "Домашнее задание 8.1\n" << endl;
    cout << "Введите символ: ";
    cin >> symbol;
    cout << "Выберите скорость вывода линии: " << endl;
    cout << "1 - быстро." << endl;
    cout << "2 - нормально." << endl;
    cout << "3 - медленно." << endl;
    cin >> optionDelay;

    switch (optionDelay)
    {
    case 1:
        delay = 10;
        break;
    case 2:
        delay = 500;
        break;
    case 3:
        delay = 1000;
        break;
    default:
        cout << "Ошибка! Такого пункта в меню нет!" << endl;
        break;
    }
    cout << "Выберите тип линии: " << endl;
    cout << "1 - вертикальная линия." << endl;
    cout << "2 - горизонтальная линия." << endl;
    cin >> option;
    
    switch (option)
    {
    case 1:
        for (uint i = 0; i < 15; i++)
        {
            Sleep(delay);
            cout << symbol << endl;
        }
        break;
    case 2:
        for (uint i = 0; i < 15; i++)
        {
            Sleep(delay);
            cout << symbol;
        }
        break;

    default:
        cout << "Ошибка! Такого пункта в меню нет!" << endl;
        break;
    }

    

    cout << "Домашнее задание 8.2\n" << endl << endl;
     
    uint totalCount = 0; // общее количество бросков
    bool hod; // переменная, определяющая очередность хода
    int totalScPl = 0, totalScComp = 0; // суммы очков игрока и компа
    int throwPlayer = 0, throwComp = 0; // по ним определяем право первого хода
    int dice1, dice2; // текущие броски 2 кубиков
    string enter; // пустая переменная, отвечающая на ввод ENTER
    srand(time(NULL));
    cout << "\t Добро пожаловать в игру Кубики!" << endl;
    cout << "Право первого хода определяется броском кубика!" << endl;
    cout << "Чтобы совершить бросок нажмите ENTER." << endl << endl;
    do 
    {
        cout << "Ход игрока." << endl; //определяем право первого хода
        getline(cin, enter);
        cout << "Бросаем кубики..." << endl;
        Sleep(1000);
        dice1 = rand() % 6 + 1;
        dice2 = rand() % 6 + 1;
        throwPlayer = dice1 + dice2;
        Cube(dice1);
        Cube(dice2);
        cout << endl;
        cout << "Ход компьютера." << endl << endl;
        cout << "Бросаем кубики..." << endl;
        Sleep(1000);
        dice1 = rand() % 6 + 1;
        dice2 = rand() % 6 + 1;
        throwComp = dice1 + dice2;
        Cube(dice1);
        Cube(dice2);
        cout << endl;
        if (throwPlayer > throwComp) //объевляем победителя на первый ход
        {
            cout << "Поздравляю! Первым ходит игрок!" << endl;
            hod = true;
        }
        else if (throwPlayer < throwComp) {
            cout << "Поздравляю! Первым ходит компьютер!" << endl;
            hod = false;
        }
        else {
            cout << "Ничья! Перебрасываем кубики!" << endl; // если ничья, то перебрасываем
            cout << "Чтобы продолжить нажмите ENTER!" << endl;
            getline(cin, enter);
        }

    } while (throwPlayer == throwComp);
    cout << "Чтобы продолжить нажмите ENTER!" << endl;
    getline(cin, enter);
    cout << endl;
    cout << "Игра началась!" << endl << endl;

    do
    {
        
        HodIgrokov(hod, enter, dice1, dice2, totalScPl, totalScComp); // функция по броскам, подсчету сумм, чередованию ходов
        Cube(dice1); // функция по выводу кубиков
        Cube(dice2);
        cout << endl;
        HodIgrokov(hod, enter, dice1, dice2, totalScPl, totalScComp);
        Cube(dice1);
        Cube(dice2);
        totalCount++;
        if (totalCount == 3)
        {
            cout << "\n\n\n\nИгра закончилась!\n";
        }
        else {
            cout << "Раунд бросков закончился! Чтобы перейти к следующему нажмите ENTER!" << endl; // притормаживаю выполнение программы вводом ENTER
            getline(cin, enter);
        }
        
    } while (totalCount != 3);

    cout << "Количество очков, набранное игроком состаяляет: " << totalScPl << endl;
    cout << "Количество очков, набранное компьютером состаяляет: " << totalScComp << endl;
    if (totalScPl > totalScComp)
    {
        cout << "Поздравляем! Вы выйграли!" << endl;
    }
    else if (totalScPl < totalScComp)
    {
        cout << "Поздравляем! Вы проиграли!" << endl;
    }
    else if(totalScPl == totalScComp)
        cout << "Ничья!" << endl;
    

    cout << "Домашнее задание 8.3\n" << endl << endl;

    int lv = 0, num = 0, hp = 0, score, answer;
    char sym;
    srand(time(NULL));
    cout << "\tДобро пожаловать в игру GUESS MY NUMBER!" << endl;

    do
    {
        cout << "Выберите уровень сложности: " << endl;
        cout << "1 - первый уровень (число от 1 до 10)" << endl;
        cout << "2 - второй уровень (число от 10 до 100)" << endl;
        cout << "3 - выход" << endl;
        cin >> lv;
        switch (lv)
        {
        case 1:
            cout << "Компьютер загадывает число..." << endl;
            Sleep(3000);
            num = rand() % 10 + 1;
            hp = 10 * 0.5;
            break;
        case 2:
            cout << "Компьютер загадывает число..." << endl;
            Sleep(3000);
            num = rand() % 90 + 10;
            hp = (100-10+1)/4;
            break;
        case 3:
            break;
        default:
            cout << "Ошибка! Такого пункта в меню нет! Повторите ввод!" << endl;
            break;
        }
        if (lv == 1 || lv == 2 )
        {
            break;
        }
    } while (lv != 3);

    if (lv != 3)
    {
        cout << "Игра началась!" << endl << endl;
        do
        {
            cout << "Количество жизней: " << hp << endl;
            cout << "Какое число загадал компьютер?" << endl;
            cout << "Ваше число: ";
            cin >> answer;
            if (answer != num)
            {
                Sleep(1000);
                cout << "Вы не угадали! Вы теряете 1 жизнь!" << endl;
                hp--;

                if (hp == 0)
                {
                    break;
                }

                do
                {
                    cout << "Хотите воспользоваться подсказкой? Подсказка стоит жизнь!" << endl;
                    cout << "Y - Да, N - Нет." << endl;
                    cin >> sym;
                    if (sym == 'Y' || sym == 'y')
                    {
                        hp--;
                        if (answer > num)
                            cout << "Загаданное число меньше вашего!" << endl;
                        else
                            cout << "Загаданное число больше вашего!" << endl;
                        break;
                    }
                    else if (sym == 'N' || sym == 'n')
                    {
                        break;
                    }
                    else
                        cout << "Ошибка! Повторите ввод!" << endl;
                } while (true);

            }
            else {
                cout << "Поздравляю! Вы угадали число! Это число: " << num << "!" << endl;
                if (lv == 1)
                {
                    score = hp * 5;
                }
                else
                    score = hp * 10;
                cout << "Количество очков составляет: " << score;
                break;
            }

        } while (hp > 0);

        if (hp < 0)
        {
            cout << "Вы проиграли!" << endl;
        }
    }
    else
        cout << "Увидимся в следующий раз! Goodbae!" << endl;
    
       */



    cout << "Домашнее задание 8.4\n" << endl << endl;

    int hp = 0, answer, counter = 1, pointer1 = 3, pointer2 = 2, scoreUser = 0, scoreComp = 0, score;
    char sym;
    srand(time(NULL));
    cout << "\tДобро пожаловать в игру GUESS MY NUMBER!" << endl;
    cout << "Игра состоит из двух уровней. Первый уровень длится 3 раунда." << endl;
    cout << "Второй  уровень длится 2 раунда. Перейти ко второму уровню можно только " << endl <<
        "после прохождения первого. " << endl;
    cout << "Хотите начать?" << endl;
    do
    {
        cout << "Y - Да, N - Нет." << endl;
        cin >> sym;
        if (sym == 'Y' || sym == 'y')
        {
            cout << "Игра началась!" << endl << endl;
            do
            {
                int num = rand() % 10 + 1;
                hp = 10 * 0.5;
                Game(num, hp, answer, true, counter);
                Congratulation(scoreUser, scoreComp, answer, num, hp, true);
                cout << endl;
                counter++;
            } while (counter < pointer1 + 1);

            score = scoreUser;
            counter = 1;

            if (score == 0)
            {
                cout << "Вы проиграли! Продолжить игру невозможно!" << endl;
                cout << "Увидимся в следующий раз! Goodbae!" << endl;
                break;

            }

            cout << "Количество очков после первого уровня составляет: " << score << endl;

            cout << "Хотите продолжить игру и перейти ко второму уровню?" << endl;

            do
            {
                cout << "Y - Да, N - Нет." << endl;
                cin >> sym;
                if (sym == 'Y' || sym == 'y')
                {
                    break;
                }
                else if (sym == 'N' || sym == 'n')
                {
                    break;
                }
                else
                    cout << "Ошибка! Повторите ввод!" << endl;
            } while (true);


            if (sym == 'Y' || sym == 'y')
            {
                do
                {
                    int num = rand() % 90 + 10;
                    hp = (100 - 10 + 1) / 4;
                    Game(num, hp, answer, false, counter);
                    Congratulation(scoreUser, scoreComp, answer, num, hp, false);
                    cout << endl;
                    counter++;
                } while (counter < pointer2 + 1);
            }
            else
            {
                cout << "Увидимся в следующий раз! Goodbae!" << endl;
            }


        }
        else if (sym == 'N' || sym == 'n')
        {
            cout << "Увидимся в следующий раз! Goodbae!" << endl;
            break;
        }
        else
            cout << "Ошибка! Повторите ввод!" << endl;
    } while (counter != 3);
    
   


   
}
