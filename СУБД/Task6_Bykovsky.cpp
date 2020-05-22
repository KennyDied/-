#include <iostream>
using namespace std;

struct Subscriber
{
    char Case;
    union
    {
        struct { char Surname[10], Name[10]; long CardNumber; } Person;
    };
};

Subscriber InpSubscriberInfo()
{
    Subscriber scb;
    
    cout << "ФАМИЛИЯ: "; cin >> scb.Person.Surname;
    cout << "ИМЯ: "; cin >> scb.Person.Name;
    cout << "НОМЕР КАРТЫ ПАЦИЕНТА: "; cin >> scb.Person.CardNumber;
    
    return scb;
}

void OutSubscriberInfo(Subscriber scb)
{
     cout << scb.Person.Surname << ' ' << scb.Person.Name << " | "
        << scb.Person.CardNumber;

     
}

void main()
{
    setlocale(LC_ALL, "RUS");
    int pass;
    int len;
    Subscriber DataBase[10],                  
        scb = { 0, "", "" };
    int i, j;                                 
    for (i = 0; i < sizeof(DataBase) / sizeof(Subscriber); i++)
        DataBase[i] = scb;
    while (1)
    {
        cout << "    Меню СУБД:" << endl
            << "1. Ввод данных." << endl
            << "2. Вывод данных." << endl
            << "3. Удалить данные" << endl
            << "4. Вывод всей информации." << endl
            << "5. Закончить работу." << endl
            << ">";
        cin >> i;
        switch (i)
        {
        case 1: 
            cout << "Порядковый номер пациента: "; cin >> i;
            DataBase[i] = InpSubscriberInfo(); break;

        case 2: cout << "Номер карты пациента: "; cin >> pass;
            for (int i = 0; i < sizeof(DataBase) / sizeof(Subscriber); i++) {
                if (DataBase[i].Person.CardNumber = pass) {
                    OutSubscriberInfo(DataBase[i]); break;
                }
            }
            
        case 3: 
            len = sizeof(DataBase) / sizeof(Subscriber);
            int N;
            cout << "Введите номер записи для удаления: ";
            cin >> N;
            for (int i = N; i <  len - 2; i++)
            {
                DataBase[i] = DataBase[i + 1];
            }
            break;

        case 4:
            for (i = 0; i < sizeof(DataBase) / sizeof(Subscriber); i++)
                cout << "Пациент №" << i << ':' << endl;
                OutSubscriberInfo(DataBase[i]);   
            break;
        
        case 5: return;
        default: cout << "Поторите ввод!" << endl;
        }
    }
}