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
        cout << "    ���� ����:" << endl
            << "1. ���� ������." << endl
            << "2. ����� ������." << endl
            << "3. ������� ������" << endl
            << "4. ����� ���� ����������." << endl
            << "5. ��������� ������." << endl
            << ">";
        cin >> i;
        switch (i)
        {
        case 1: 
            cout << "���������� ����� ��������: "; cin >> i;
            DataBase[i] = InpSubscriberInfo(); break;

        case 2: cout << "����� ����� ��������: "; cin >> pass;
            for (int i = 0; i < sizeof(DataBase) / sizeof(Subscriber); i++) {
                if (DataBase[i].Person.CardNumber = pass) {
                    OutSubscriberInfo(DataBase[i]); break;
                }
            }
            
        case 3: 
            len = sizeof(DataBase) / sizeof(Subscriber);
            int N;
            cout << "������� ����� ������ ��� ��������: ";
            cin >> N;
            for (int i = N; i <  len - 2; i++)
            {
                DataBase[i] = DataBase[i + 1];
            }
            break;

        case 4:
            for (i = 0; i < sizeof(DataBase) / sizeof(Subscriber); i++)
                cout << "������� �" << i << ':' << endl;
                OutSubscriberInfo(DataBase[i]);   
            break;
        
        case 5: return;
        default: cout << "�������� ����!" << endl;
        }
    }
}