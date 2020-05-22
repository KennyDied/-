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
  
    cout << "�������: "; cin >> scb.Person.Surname;
    cout << "���: "; cin >> scb.Person.Name;
    cout << "����� ����� ��������: "; cin >> scb.Person.CardNumber;
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
        cout << "    ���� ����:" << endl
            << "1. ���� ������." << endl
            << "2. ����� ������." << endl
            << "3. ����� ���� ����������." << endl
            << "4. ������� ������." << endl
            << "5. ��������� ������." << endl
            << ">";
        cin >> i;
        switch (i)
        {
        case 1: cout << "���������� ����� ��������: "; cin >> i;
           
            AddSubscriber(i); break;
        
        case 2: cout << "���������� ����� ��������: "; cin >> i;
            if ((p = FoundSubscriberNum(i)) != NULL)
                OutSubscriberInfo(*p);
            else cout << "������� �� ������!" << endl;
            break;
 
        case 3: p = DataBase; i = 0;
            while (p != NULL)
            {
                cout << "������� �" << i++ << ':' << endl;
                OutSubscriberInfo(*p); p = p->Next;
            }
            break;
 
        case 4: cout << "���������� ����� ��������: "; cin >> i;
            DeleteSubscriber(i); break;

        case 5: while (DataBase != NULL)  
        {
            p = DataBase; DataBase = p->Next; delete p;
        }
              return;
        default: cout << "�������� ����!" << endl;
        }
    }
}