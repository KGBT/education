#include <iostream>
using namespace std;
int main()
{
    //Task 5.1
    /*
    char sym;
    cout << "Home Task 5.1" << endl;
    cout << "Vvedite simvol: ";
    cin >> sym;
    if ((sym >= 65 && sym <=90) ||(sym>=97 && sym <=122))
    {
        cout << sym << " - eto bukva!" << endl;
    }else if (sym >=48 && sym <=57)
    {
        cout << sym << " - eto tsifra!" << endl;
    }else if (sym == 33 || sym == 44 || sym == 46 || sym == 34 || sym == 58 || sym == 59 || sym == 63 || sym == 28 || sym == 29)
    {
        cout << sym << " - eto znak prepinaniya!" << endl;
    }else
        cout << sym << " - eto drugoe!" << endl;
    
    
    //Task 5.2
    float leng, stoim = 0;
    int oper1, oper2;
    float MTS = 5, Megafon = 6.5, Beeline = 3.75;
    cout << "Home Task 5.2" << endl;
    cout << "1 - MTS" << endl;
    cout << "2 - Megafon" << endl;
    cout << "3 - Beeline" << endl;
    cout << "Viberite kod vashego operatora: ";
    cin >> oper1;
    cout << endl;
    cout << "1 - MTS" << endl;
    cout << "2 - Megafon" << endl;
    cout << "3 - Beeline" << endl;
    cout << "Viberite kod operatora na kotorii hotite sovershit' zvonok: ";
    cin >> oper2;
    cout << endl;
    cout << "Vvedite dlitel'nost' razgovora: ";
    cin >> leng;
    cout << endl;
    if (oper1 == oper2) {
        cout << "Zvonki vnutri seti besplatni!" << endl;
    }  
    else if (oper1 == 1 && (oper2>=1 && oper2 <=3)) {
        stoim = MTS * leng;
        cout << "Stoimost' razgovora sostavlyaet: " << stoim << endl;
    }
        
    else if (oper1 == 2 && (oper2 >= 1 && oper2 <= 3)) {
        stoim = Megafon * leng;
        cout << "Stoimost' razgovora sostavlyaet: " << stoim << endl;
    }
        
    else if (oper1 == 3 && (oper2 >= 1 && oper2 <= 3)) {
        stoim = Beeline * leng;
        cout << "Stoimost' razgovora sostavlyaet: " << stoim << endl;
    }
        
    else
        cout << "Error! Takogo operatora net!";
        */
    
    //Task 5.3
    const int shtraf = 20;
    float costOneStroki = 0.5;
    int count, opozdaniya, countStroki, dohod, sumDohod, sumStroki;
    cout << "Home Task 5.3" << endl;
    cout << "Vvedite nomer v Menu:" << endl;
    cout << "\tMenu:" << endl;
    cout << "1 - Podschet kolichestva strok." << endl;
    cout << "2 - Podschet kolichestva opozdanii." << endl;
    cout << "3 - Podchet zarabotnoi plati." << endl;
    cin >> count;
    switch (count)
    {
    case 1:
        cout << "Vvedite jelaemii dohod:";
        cin >> dohod;
        cout << "Vvedite kolichestvo opozdanii: ";
        cin >> opozdaniya;
        sumStroki = dohod / costOneStroki;
        if (opozdaniya >= 3)
        {
            opozdaniya = opozdaniya / 3 * shtraf;
            sumStroki = sumStroki + opozdaniya / costOneStroki;
        }
        
        cout << "Kolichestvo strok, neobhodimie dlya zarplati: " << sumStroki << endl;
        break;
    case 2:
        cout << "Vvedite jelaemii dohod:";
        cin >> dohod;
        cout << "Vvedite kolichestvo strok koda: ";
        cin >> countStroki;
        sumDohod = countStroki * costOneStroki;
        if (sumDohod <= dohod) {
            cout << "Vam nel'zya opazdivat'!" << endl;
        }
        else {
            opozdaniya = (sumDohod - dohod) / shtraf * 3;
            cout << "Vi mojete opozdat': " << opozdaniya <<" raz." << endl;
        }
        break;
    case 3:
        cout << "Vvedite kolichestvo strok koda: ";
        cin >> countStroki;
        cout << "Vvedite kolichestvo opozdanii: ";
        cin >> opozdaniya;
        sumDohod = countStroki * costOneStroki;
        if (sumDohod - opozdaniya / 3 * 20 <= 0)
        {
            cout << "Vam ne zaplatyat voobshe!" << endl;
        }
        else {
            sumDohod = sumDohod - opozdaniya / 3 * 20;
            cout << "Vash dohod sostavlyaet: " << sumDohod << endl;
        }
        
        break;
    default:
        cout << "Oshibka vvoda!" << endl;
        break;
    }
    

}
