

#include <iostream>
using namespace std;
int main()
{   
    //Task 3.1
    cout << "Home Task 3.1" << endl;
    int sec,h1,m1,s1,h2,m2,s2;
    const int secVSut = 24 * 60 * 60;
    cout << "Vvedite vremya v secundah: ";
    cin >> sec;
    h1 = sec / 3600;
    m1 = (sec % 3600) / 60;
    s1 = sec % 60;
    cout << "\tTime now:" << endl;
    cout << "\th: " << h1 << " m: " << m1 << " s: " << s1 << endl;
    sec = secVSut - sec;
    h2 = sec / 3600;
    m2 = (sec % 3600) / 60;
    s2 = sec % 60;
    cout << "\tTime left:" << endl;
    cout << "\th: " << h2 << " m: " << m2 << " s: " << s2 << endl;
    
    //Task 3.2
    cout << "Home Task 3.2" << endl;
    int inputSec, h;
    cout << "Vvedite vremya v secundah s nachala rabochego dnya: ";
    cin >> inputSec;
    h = 8 - inputSec / 3600;
    cout << "Vam ostalos' rabotat': " << h << " chasov" << endl;
    return 0;
}

