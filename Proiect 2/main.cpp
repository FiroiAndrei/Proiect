#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;
class Film
{
    int id;
    bool animatie; /// sau live-action
    char restrictie;
    /*
    Rated G: Suggested for general audiences.
    Rated M: Suggested for mature audiences - Parental discretion advised.
    Rated R: Restricted – persons under 16 not admitted, unless accompanied by parent or adult guardian.
    Rated X: Persons under 16 not admitted.
    */
    char* seria = NULL; /// habar n-am
    char categoria[100]; /// comedy, horror
    float durata; /// in minute
    int* producator; ///
    double rating; /// o nota de la 1 la 10 ... sau 100, sunt comentariu, nu politist
    /// schimbare de plan : rating este acum un numar oarecare, cu cat mai mult cu atat mai bine-
    const string director;
    static int nrFilme;
    char nume[100];
    int* note;

public:


     Film(bool anim, char restr, char* ser,
            char* categ, float dur, int* prod, double rat,string dir, char* nume):director(dir)
     {

         this->id = nrFilme;
         this->animatie = anim;
         this->restrictie = restr;
//         this->seria = new char[strlen(ser) + 1];
//         strcpy(this->seria, ser);
         this->seria = new char[strlen(ser) + 1];
         this->seria = ser;


         strcpy(this->categoria,categ);

         this->durata = dur;
         this->producator = prod;
         this->rating = rat;
         strcpy(this->nume, nume);
         this->nrFilme++;
     }

     Film():id(nrFilme++)
     {
         id = -1;
         animatie = 0;
         restrictie = 'X';
//         char* seria = new char[strlen("1")+1];
//         strcpy (this->seria,seria);
         this->seria=new char[strlen("FaraSerie")+1];
         strcpy(this->seria,"FaraSerie");
         strcpy(categoria,"\0");
         durata = 0;
         this->producator = new int[1];
         this->producator[0] = 5;
         rating = 0;
         strcpy(this->nume , "\0");
     }

    Film(const Film& f):director(f.director)
    {
        this->id = f.id;
        this->animatie = f.animatie;
        this->restrictie = f.restrictie;
        this->seria = new char[strlen(seria) + 1];
        strcpy(this->seria, seria);
        strcpy(this->categoria, f.categoria);
        this->durata = f.durata;
        this->producator = f.producator;
        this->rating = f.rating;
        strcpy(this->nume, f.nume);

    }
     void getFilm()
     {

         cout << "Id :" <<
         this->id << endl << "Animatie (1 = da ; 0 = nu) : " <<
         this->animatie << endl << "Nush cum sa ii zic la asta : " <<
         this->restrictie << endl << "Seria :" <<
         this->seria << endl << "Categoria : " <<
         this->categoria << endl << "Durata (in minute) :" <<
         this->durata << endl << "Producator : " <<
         this->producator << endl << "Rating : " <<
         this->rating << endl << "Director :" <<
         this->director << endl << "Nr Filme : " <<
         this->nrFilme << endl << "********************" << endl;


     }


     // Setters / Getters **********************************

     /// ************* SETTERS ******************************
     void setId(int id)
     {
         this->id = id;
     }


     void setAnimatie(bool animatie)
     {
         this->animatie = animatie;
     }

     void setRestrictie(char restrictie)
     {
         this->restrictie = restrictie;
     }

     void setSeria(char* seria)
     {
       char aux[100];
        if (this->seria != nullptr)
            delete[] this->seria;
        this->seria = new char[strlen(seria) + 1];
//        this->seria = seria;
        strcpy(this->seria, seria);

     }

//void setSeria(char* seria)
//{
//
//    if (seria == nullptr) {
//            seria = new char[1];
//            seria[0] = '\0';
//        }
//        else {
//            seria = new char[strlen(ser) + 1];
//            this->seria = ser;
//        }
//}
     void setCategoria(char categoria[100])
     {
         strcpy(this->categoria, categoria);
     }

     void setDurata(float durata)
     {
         this->durata = durata;
     }

     void setProducator(int* producator)
     {
         this->producator = producator;
     }


     void setRating(double rating)
     {
         this->rating = rating;
     }

//     void setDirector(char* director)
//     {
//         this->director = director;
//     }

    void setNume(char* nume)
    {
        strcpy(this->nume, nume);
    }

     void setNrFilme(int nrFilme)
     {
         this->nrFilme = nrFilme;
     }


     // ********************** GETTERS ******************************


     int getId()
     {
         return this->id;
     }
     int* getIdAdresa()
     {
         return &this->id;
     }

     bool getAnimatie()
     {
         return this->animatie;
     }

     char getRestrictie()
     {
         return this->restrictie;
     }

     char* getSeria()
     {
         return this->seria;
     }

     char* getCategoria()
     {
         return this->categoria;
     }

     float getDurata()
     {
         return this->durata;
     }

     int* getProducator()
     {
         return this->producator;
     }

     double getRating()
     {
         return this->rating;
     }

     string getDirector()
     {
         return this->director;
     }
     char* getNume()
     {
         return this->nume;
     }

     int getNrFilme()
     {
         return this->nrFilme;
     }

     /// **************************************************************

     Film& operator + (Film& f1)
     {
         this->producator = &(f1.id);
         return *this;
     }

     Film& operator - (Film& f1)
     {
         this->producator = NULL;
         return *this;
     }

      Film& operator = (Film& f1)
     {
         strcpy(this->categoria, f1.categoria);
         return *this;
     }

      Film& operator -- ()
     {
         this->rating -= 5;
         return *this;
     }

      Film& operator ++ ()
     {
         this->rating += 5;
         return *this;
     }



     char* operator[](int index)
     {
         int i = 0;
         char *b;
         b = strtok(this->categoria , " ,");
           while (b!= NULL && i < index)
        {
            i++;
            b = strtok(NULL, " ,");
        }

        if (b == NULL)
            {
                cout << "\nERROR\n";
                return b;
            }

        return b;
     }

     friend ostream& operator << (ostream& out,const Film& f)
     {
         out << "Id :" << f.id << endl <<
         "Nume:" << f.nume << endl <<
         "Animatie (1 = da ; 0 = nu) : " << f.animatie << endl <<
         "Nush cum sa ii zic la asta : " << f.restrictie << endl <<
         "Seria :" << f.seria << endl <<
         "Categoria : " << f.categoria << endl <<
         "Durata (in minute) :" << f.durata << endl <<
         "Producator : " << f.producator << endl <<
         "Rating : " << f.rating << endl <<
         "Director :" << f.director << endl <<
         "Nr Filme : " << f.nrFilme << endl <<
         "********************" << endl;

         return out;
     }

     friend istream& operator >>(istream& in, Film& f)
     {
         cout << "Animatie (1 = da, 0 = nu) : ";
         in >> f.animatie;
         cout << "Restrictie(G, M , R sau X) : ";
         in >> f.restrictie;
         cout << "Nu merge inca sa o leg de o serie, scuzati\n";
         cout << "Categoria : ";
         in >> f.categoria;
         cout << "Durata : ";
         in >> f.durata;
//         cout << "Producator :";
//         in >> f.producator;
         cout << "Rating : ";
         in >> f.rating;
//         cout << "Director :";
//         in >> f.director;
        return in;
     }

     ~Film ()
     {
         if (this->seria != NULL)
         delete []this->seria;

         if (this->producator != NULL)
            delete [] this->producator;

     }

     bool operator ==(Film &f)
     {
         if(this->rating == f.rating)
            return 1;
         else
            return 0;

     }

     bool operator >(Film &f)
     {
         if(this->rating > f.rating)
            return 1;
         else
            return 0;

     }
      explicit operator int()
    {

        return (int)this->rating;

    }
};
int Film::nrFilme = 0;

class User
{
    int id;
    bool premium;
    char membru;
    /*
    A = VIP
    B = Normal User
    C = New User
    */
    char* categorieFavorita;
    char descriere[100] = {""};
    float avgRating;
    int* invitatDe;
    double rating;
    const string dataInscrierii;
    static int nrMembri;
    int* note;
    int nrNote = 0;
    public:

    User(bool premium, char membru, char* categorieFavorita, char descriere[100],
          float avgRating, double rating,
          string dataInscrierii):dataInscrierii(dataInscrierii)
          {
              this->id = this->nrMembri;
              this->premium = premium;
              this->membru = membru;
              strcpy(this->categorieFavorita, categorieFavorita);
              strcpy(this->descriere, descriere);
              this-> avgRating = avgRating;
              this-> rating = rating;
              this->nrMembri++;
          }

     User(char* categorieFavorita, char descriere[100],
          string dataInscrierii):dataInscrierii(dataInscrierii)
          {
              this->id = this->nrMembri;
              this->premium = 0;
              this->membru = 'C';
              strcpy(this->categorieFavorita, categorieFavorita);
              strcpy(this->descriere, descriere);
              this-> avgRating = 0;
              this-> rating = 0;
              this->nrMembri++;
          }

      User ():dataInscrierii("00-00-0000")
      {
          this->id = this->nrMembri;
          this->premium = false;
          this->membru = 'C';
          this->categorieFavorita = NULL;
          this->invitatDe = NULL;
          strcpy(this->descriere, "");
          this-> avgRating = -1;
          this-> rating = -1;
          this->nrMembri++;
          this->note = new int[1];
          this->note[0] = 0;
          this->nrNote = 0;
      }

       User(const User& u):dataInscrierii(u.dataInscrierii)
    {
        this->id = u.id;
        this->premium = u.premium;
        this->membru = u.membru;
//        this->categorieFavorita = new char[strlen(categorieFavorita) + 1];
//        strcpy(this->categorieFavorita, categorieFavorita);
        this->categorieFavorita = u.categorieFavorita;

        strcpy(this->descriere, u.descriere);
        this->avgRating = u.avgRating;
        this->rating = u.rating;
    }


     friend ostream& operator << (ostream& out,const User& u)
     {


         out << "Id :" << u.id << endl <<
         "Premium :" << u.premium << endl <<
         "Membru : " << u.membru << endl <<
         "Categoria favorita :" << u.categorieFavorita << endl <<
         "Descriere : " << u.descriere << endl <<
         "Average Rating :" << u.avgRating << endl <<
         "invitat de : " << u.invitatDe << endl <<
         "Rating : " << u.rating << endl <<
         "Data :" << u.dataInscrierii << endl <<
         "Nr membri : " << u.nrMembri << endl <<
         "Nr note :" << u.nrNote << endl <<
         "Note : ";
         for (int i = 0 ; i < u.nrNote; i++)
            out << u.note[i] << " ";
         cout << "\n********************" << endl;

         return out;
     }

     friend istream& operator >>(istream& in, User& u)
     {
         cout << "Premium (1 = da, 0 = nu) : ";
         in >> u.premium;
         cout << "Membru(A, B sau C) : "; /// stiu ca n-are sens, nici asta nici rating dar ca sa vedeti ca pot
         in >> u.membru;
         cout << "Categorie favorita : ";
         char aux[100];
         in>>aux;
         u.categorieFavorita=new char[strlen(aux)+1];
         strcpy(u.categorieFavorita,aux);
         cout << "Descrie-te intr-un cuvant : ";
         in >> aux;
         strcpy(u.descriere, aux);

         cout << "Rating : ";
         in >> u.rating;

        return in;
     }



     /// ************* SETTERS ******************************
     void setId(int id)
     {
         this->id = id;
     }


     void setPremium(bool premium)
     {
         this->premium = premium;
     }

     void setMembru(char membru)
     {
         this->membru = membru;
     }

     void setCategorieFav(char* categ)
     {
       char aux[100];
        if (this->categorieFavorita != nullptr)
            delete[] this->categorieFavorita;
        this->categorieFavorita = new char[strlen(categ) + 1];
        strcpy(this->categorieFavorita, categ);

     }


     void setDescriere(char* descriere)
     {
         strcpy(this->descriere, descriere);
     }

     void setAvgRating(float avgRating)
     {
         this->avgRating = avgRating;
     }

     void setInvitatDe(int* inv)
     {
         this->invitatDe = inv;
     }


     void setRating(double rating)
     {
         this->rating = rating;
     }


/// pare un pic stupid setnrMembri
     void setNrMembri(int nrMembri)
     {
         this->nrMembri = nrMembri;
     }


     // ********************** GETTERS ******************************


     int getId()
     {
         return this->id;
     }
     int* getInvitatDe()
     {
         return this->invitatDe;
     }

     bool getPremium()
     {
         return this->premium;
     }

     char getMembru()
     {
         return this->membru;
     }

     char* getCategorieFavorita()
     {
         return this->categorieFavorita;
     }

     char* getDescriere()
     {
         return this->descriere;
     }

     float getAvgRating()
     {
         return this->avgRating;
     }


     double getRating()
     {
         return this->rating;
     }

     string getDataInscrierii()
     {
         return this->dataInscrierii;
     }

     int* getNote()
     {
         return this->note;
     }
      int getNrNote()
     {
         return this->nrNote;
     }


     int getNrMembri()
     {
         int a = this->nrMembri;
         return a;
     }

     /// **************************************************************

     User& operator + (float nota)
     {


         int v[this->nrNote++];
         int nr = this->nrNote;
         for (int i = 0 ; i < nr-1; i++)
            v[i] = this->note[i];

         if (this->note != NULL)
            delete [] this->note;

         this->note=new int[this->nrNote];
         for (int i = 0 ; i < nr-1; i++)
         {
            this->note[i] = v[i];
         }
         this->note[this->nrNote-1] = nota;
         float suma = 0;
         for (int i = 0 ;i < this->nrNote; i++)
            suma += this->note[i];
         this->avgRating = suma / this->nrNote;

         return *this;
     }

     User& operator - (User& u1)
     {
         this->invitatDe = NULL;
         return *this;
     }

      User& operator = (User& u1)
     {
        this->premium = u1.premium;
        return *this;
     }

      User& operator -- ()
     {
         this->rating -= 1;
         return *this;
     }

      User& operator ++ ()
     {
         this->rating += 1;
         return *this;
     }
    const User operator++(int)
    {

        User aux(*this);

        this->rating +=1;

        return aux;


    }


     char* operator[](int index)
     {
         int i = 0;
         char *b;
         b = strtok(this->descriere , " ,");
           while (b!= NULL && i < index)
            {
                i++;
                b = strtok(NULL, " ,");
            }

        if (b == NULL)
            {
                cout << "\nEROARE LA OPERATORUL DE INDEXARE\n";
                return b;
            }

        return b;
     }

     bool operator ==(User &u)
     {
         if(this->rating == u.rating)
            return 1;
         else
            return 0;

     }

     bool operator >(User &u)
     {
         if(this->rating > u.rating)
            return 1;
         else
            return 0;

     }

    explicit operator int()
    {
        return (int)this->rating;
    }

    ~User()
    {
        if (this->categorieFavorita != NULL)
            delete [] this->categorieFavorita;

        if(this->note != NULL)
            delete [] this->note;
    }

};
int User::nrMembri = 0;

class Merch
{
    char* produs;
    int pret;
    const float euro; // lei


public:
    Merch (char* produs, int pret, float cursValutar):euro(cursValutar)
    {
        strcpy(this->produs, produs);
            this->pret = pret;
    }

    Merch ():euro(4.781)
    {
        this->produs=new char[strlen("cinci")];
         strcpy(this->produs,"cinci");
        this->pret = 0;

    }
      Merch& operator =(Merch &m)
     {
             this->pret = m.pret;

         this->produs = m.produs;
         return *this;
     }

       Merch(const Merch& m):euro(m.euro)
    {
        this->pret = m.pret;
        this->produs=new char[strlen(m.produs)];
         strcpy(this->produs, m.produs);
    }


     friend ostream& operator << (ostream& out,const Merch& m)
     {


         out <<  "Produse : " << m.produs << endl <<
         "PRET : " << m.pret<< endl <<
         "\n********************" << endl;

         return out;
     }

     friend istream& operator >>(istream& in, Merch& m)
     {

        char aux[100];
         cout << "Produs : ";
         in>>aux;
         m.produs=new char[strlen(aux)+1];
         strcpy(m.produs,aux);

         cout <<"Pret : ";
            in >> m.pret;

        return in;
     }



     ~Merch()
     {
         if(this->produs != NULL)
            delete [] this->produs;

     }

};

void DisplayStart()
{
    cout << "****************     CEVA GEN IMDB     **************** \n\n\n";
//    cout << "\n\n\t1.LOGIN" << endl << "\t2.REGISTER\n\n";


}

int Start()
{
    char alegere;

    while (true)
    {

        cout << "\n\n\t1.LOGIN" << endl << "\t2.REGISTER\n\n";
        cin >> alegere;
        switch(alegere)
        {
            case '1': return 1;
            case '2': return 2;
            default : cout<< "\n\nAlege un numar de la 1 la 2\n";
        }

    }
}

void DisplayLogIn()
{
    cout << "Stiu ca nu aveti cont \n";

}
void DisplayRegister(User& A)
{
    cout << "\n";
    cin >> A;
}

int SuccessfulLogIn(User& A)
{
    cout << "Bine ai (re?)venit, ";
    cout << "\n 1. Rate a movie \t 2. Log out\n";

    char alegere;

    while (true)
    {

        cin >> alegere;
        switch(alegere)
        {
            case '1': return 1;
            case '2': return 2;
            default : cout<< "\n\nAlege un numar de la 1 la 2\n";
        }

    }
}
int AlegeFilm(int i)
{
    char alegere1;
        while(true)
        {
            cin >> alegere1;
            switch (alegere1)
            {
                case '1' : return 0;
                case '2' : return 1;
                case '3' : return 2;
                case '4' : return 3;
                case '5' : return 4;
                case '6' : return 5;
                case '7' : return 6;
                case '8' : return 7;
                case '9' : return 8;
                case '10' : return 9;
                default : cout << "Va rugam alegeti un numar de la 1 la " << i << endl;

            }
        }
}
int main()
{


    Film Dummy[10];
    Dummy[0].setNume("yes");
    Dummy[1].setNume("No");
    Dummy[2].setNume("Doi");
    Dummy[3].setNume("Dar de fapt 3");
    Dummy[4].setNume("frozen");
    Dummy[5].setNume("Vegetables");
    Dummy[6].setNume("nush");
    Dummy[7].setNume("alt film");
    Dummy[8].setNume("hdf");
    Dummy[9].setNume("fsa");

     User D[10];
    D[0].setRating(7);
    D[1].setRating(27);
    D[2].setRating(21.2);
    D[3].setRating(5.8);
    D[4].setRating(31.2);
    D[5].setRating(6.2);
    D[6].setRating(1);
    D[7].setRating(3);
    D[8].setRating(2);
    D[9].setRating(5);

    DisplayStart();
    int alegere = Start();
    if (alegere == 1)
        DisplayLogIn();
    User A;


    int index;
    index = A.getNrMembri();
//    cout << A;
    DisplayRegister(A);
    alegere = SuccessfulLogIn(A);
    if (alegere == 1)
    {
        cout << "Va rugam alegeti filmul :\n";
        int i;
        for (i = 0 ;i < Dummy[0].getNrFilme() ;i++)
            cout << i+1 << '.' <<Dummy[i].getNume() << endl;


        alegere = AlegeFilm(i);
        cout << endl << Dummy[alegere].getNume() <<" are o medie de " << Dummy[i].getRating() << endl;

        cout << "Va rugam sa-i acordati o nota de la 1 la 10 : ";
        double nota;
        cin >> nota;
        double rat = Dummy[i].getRating();
        Dummy[i].setRating(rat + nota);
        --Dummy[i];
        A + nota;
    }


    return 0;
}
