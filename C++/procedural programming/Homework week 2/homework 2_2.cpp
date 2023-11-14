

#include <iostream>
using namespace std;

int main()
{   
    //Task 2.1
    cout << "Home Task 2.1" << endl;
    int hour, min, sec;
    cout << "Vvedite vremya v secundah: " << endl;
    cin >> sec;
    hour = sec / 3600;
    min = (sec % 3600) / 60;
    sec = sec % 60;
    cout << "h: " << hour << " m: " << min << " s: " << sec << endl;
    
    
    //Task 2.2
    cout << "Home Task 2.2" << endl;
    float money;
    int cents, dollars;
    cout << "Vvedite summu dlya perevoda: ";
    cin >> money;
    dollars = money;
    cents = (money - dollars) * 100;
    cout << dollars << " dollarov i " << cents << " centov." << endl;
    
    //Task 2.3
    cout << "Home Task 2.3" << endl;
    int weeks, days;
    cout << "Vvedite kolichestvo dney: ";
    cin >> days;
    weeks = days / 7;
    days = days % 7;
    cout << weeks << " nedeli i " << days << " dnya" << endl;
    

    //Task 2.4
    cout << "Home Task 2.4" << endl;
    int timeMin, timeSec;
    float time, speed, lengthOfDis;
    cout << "Calculating running speed." << endl;
    cout << "Enter the length of distance (meters) = ";
    cin >> lengthOfDis;
    cout << "Enter time (min.sec) = ";
    cin >> time;
    timeMin = time;
    timeSec = (time - timeMin) * 100;
    time = timeMin * 60 + timeSec;
    cout << "Distance: " << lengthOfDis << " m." << endl;
    cout << "Time: " << timeMin << " min " << timeSec << " sec = " << time << " seconds" << endl;
    speed = 3.6 * (lengthOfDis / time);
    cout << "You were running at speed " << speed << " km/h" << endl;
    

    //Task 2.5
    cout << "Home Task 2.5" << endl;
    float money, percent, sumEveryMounth;
    int mouth = 0;
    
    cout << "Vvedite summu denejnogo vklada: ";
    cin >> money;
    cout << "Vvedite procent godovih: ";
    cin >> percent;

    while (mouth < 12)
    {   
        mouth++;
        sumEveryMounth = (money * percent * 31 / 365) / 100;
        money = money + sumEveryMounth;
        cout << "Kolichestvo deneg za " << mouth <<" mesyac: " << sumEveryMounth << endl;
    }
    
    return 0;
}

