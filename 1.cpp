#include<iostream>
#include<string.h>
using namespace std;

struct data
{
    char name[30];
    long teleno;
};

class HashTable
{
    int n, sum, x, c, i, j;
    char na[30];
    long no;
    struct data d[10]; // Qualify 'data' with its namespace

public:
    HashTable()
    {
        for (i = 0; i < 10; i++)
        {
            d[i].teleno = 0;
        }
    }

    void insert();
    void search();
    void display();
};

void HashTable::insert()
{
    cout << "\n enter no. of clients ";
    cin >> n;

    for (j = 0; j < n; j++)
    {
        cout << "\n enter name of client ";
        cin >> na;
        cout << "\n enter telephone no. of client ";
        cin >> no;
        sum = 0;
        for (i = 0; i < strlen(na); i++)
        {
            sum += (int)na[i]; // adding up ASCII value of each character in the name
        }
        x = sum % 10; // calculating the hash value

        c = x;
        while (1)
        {
            if (d[x].teleno == 0) // index is empty
            {
                strcpy(d[x].name, na);
                d[x].teleno = no;
                break;
            }
            x = (x + 1) % 10; // linear probing to find the next free slot
            if (c == x)
            {
                cout << "\n hash table is full ";
                break;
            }
        }
    }
}

void HashTable::search()
{
    cout << "\n enter name to be searched ";
    cin >> na;

    sum = 0;
    for (i = 0; i < strlen(na); i++)
    {
        sum += (int)na[i]; // calculate hash value for input name by adding ASCII value of all characters in the name
    }
    x = sum % 10; // find the appropriate index

    c = x;
    while (1)
    {
        if (strcmp(d[x].name, na) == 0)
        {
            cout << "\n data found : TELEPHONE NO:" << d[x].teleno;
            break;
        }
        x = (x + 1) % 10;
        if (c == x)
        {
            cout << "\n data not found";
            break;
        }
    }
}

void HashTable::display()
{
    for (int i = 0; i < 10; i++)
    {
        if (d[i].teleno != 0)
        {
            cout << d[i].name << " " << d[i].teleno << endl;
        }
    }
}

int main()
{
    HashTable h;
    h.insert();
    //h.display();
    h.search();
    return 0;
}
