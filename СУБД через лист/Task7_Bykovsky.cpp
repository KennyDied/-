#include <iostream>
using namespace std;

struct Subscriber
{
    Subscriber* Next;   
    char Case;
    union
    {
        struct { char Surname[10], Name[10]; long CardNumber; } Person;
    };
};

Subscriber* DataBase = NULL;

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

Subscriber* FoundSubscriberNum(int num)
{
    Subscriber* p = DataBase;
    while (p != NULL && num--)  
        p = p->Next;            
    return p;   
}              
void AddSubscriber(int num)
{
    Subscriber* q = new Subscriber;
    *q = InpSubscriberInfo();    
    if (DataBase == NULL) num = 0;   
    if (num)
    {
        Subscriber* p = DataBase;      
        while (p->Next != NULL && --num) 
            p = p->Next;
        q->Next = p->Next; p->Next = q;
    }
    else { q->Next = DataBase; DataBase = q; } 
}

void DeleteSubscriber(int num)
{
    Subscriber* q;
    if (DataBase == NULL) return;
    if (num)
    {
        Subscriber* p = DataBase;
        while (p->Next != NULL && --num) p = p->Next;
        if ((q = p->Next) != NULL) { p->Next = q->Next; delete q; }
    }                           
    else { q = DataBase; DataBase = q->Next; delete q; }
}

void main()
{
    Subscriber* p;   int i, j;
    while (1)
    {
        cout << "    Меню СУБД:" << endl
            << "1. Ввод данных." << endl
            << "2. Вывод данных." << endl
            << "3. Вывод всей информации." << endl
            << "4. Удалить данные." << endl
            << "5. Закончить работу." << endl
            << ">";
        cin >> i;
        switch (i)
        {
        case 1: cout << "Порядковый номер пациента: "; cin >> i;
           
            AddSubscriber(i); break;
        
        case 2: cout << "Порядковый номер пациента: "; cin >> i;
            if ((p = FoundSubscriberNum(i)) != NULL)
                OutSubscriberInfo(*p);
            else cout << "Человек не найден!" << endl;
            break;
 
        case 3: p = DataBase; i = 0;
            while (p != NULL)
            {
                cout << "Пациент №" << i++ << ':' << endl;
                OutSubscriberInfo(*p); p = p->Next;
            }
            break;
 
        case 4: cout << "Порядковый номер пациента: "; cin >> i;
            DeleteSubscriber(i); break;

        case 5: while (DataBase != NULL)  
        {
            p = DataBase; DataBase = p->Next; delete p;
        }
              return;
        default: cout << "Поторите ввод!" << endl;
        }
    }
}