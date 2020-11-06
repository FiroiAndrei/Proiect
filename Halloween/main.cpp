#include <iostream>
#include <string.h>
using namespace std;

class Decoratiune
{
    char decoratiune[100] = "primaDecoratiune";
    char culoare[100];
    float pret;
    bool reciclabil;

public:
    char* getDecoratiune()
    {
        return this->decoratiune;
    }
    float getPret()
    {
        return this->pret;
    }
};

class ListaProduse
{
    char produse[5000][50];
    float pret1[50];
    float total;
    int index = 0;

public:
    char* operator [](int i)
    {
        if (i == 1)
            return strtok(produse[i]," ");
    }

//    float operator [](int i)
//    {
//
//    }
    ListaProduse operator+(Decoratiune& a)
    {
        strcat(this->produse[index++]," ");
        strcat(this->produse[index], a.getDecoratiune());
        this->total += a.getPret();
        return *this;
    }

    void pret()
    {
        cout << this->total;
    }

//    void n()
//    {
//        cout <<"index =" << index << endl;
//        cout << produse[0] <<"&&*"<< produse[1]<<endl;
//    }

    ListaProduse remove(int i)
    {
        for (int j = i; j < index; j++)
        {
//            cout<<"prduse ["<<j<<"]=" << this->produse[j] << endl;
            strcpy(this->produse[j-1],this->produse[j]);
        }
        this->total -= pret1[i];
        return *this;
    }

};


int main()
{
    Decoratiune a;
    ListaProduse b;
//    b.n();
    b = b+a;
//    b.n();
    b[1];
    b.remove(1);
//    b.n();
}
