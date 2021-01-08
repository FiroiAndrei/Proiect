#include <iostream>
#include <string.h>
#include "Film.h"

Film::Film():restrictie('A')
{
    this->id = -1;
    this->animatie = false;
    this->director = new char[strlen("Anonim") + 1];
    strcpy(this->director, "Anonim");
    strcpy(this->categoria,"N/A");
    this->durata = 0;
    this->rating = 0;
    this->nume = "N/A";
    this->nrFilme++;
    this->note.clear();

}
Film::Film(bool anim, char restr, char* dir,
            char categ[], float dur, double rat, std::string nume):restrictie(restr)
     {
         this->id = this->nrFilme;
         this->animatie = anim;
         this->director = new char[strlen(dir) + 1];
         strcpy(this->director, dir);
         strcpy(this->categoria,categ);
         this->durata = dur;
         this->rating = rat;
         this->nume = nume;
         this->nrFilme++;
         this->note.clear();
     }

Film::Film(bool anim, char restr, char* dir,
            char categ[], float dur, double rat, std::string nume, int nrNote, int note[]):restrictie(restr)
     {
         this->id = this->nrFilme;
         this->animatie = anim;
         this->director = new char[strlen(dir) + 1];
         strcpy(this->director, dir);
         strcpy(this->categoria,categ);
         this->durata = dur;
         this->rating = rat;
         this->nume = nume;
         this->nrFilme++;
         this->note.clear();
         for (int i = 0;i < nrNote; i++)
            this->note.push_back(note[i]);
     }

Film::Film(const Film& f):restrictie(f.restrictie)
{
    this->id = f.id;
    this->animatie = f.animatie;
    this->director = new char[strlen(f.director)+1];
    strcpy(this->director, f.director);
    strcpy(this-> categoria, f.categoria);
    this-> durata = f.durata;
    this-> rating = f.rating;
    this->nrFilme = f.nrFilme;
    this-> nume = f.nume;
    this->note = f.note;

}
///##### GETTERS ###########
void Film::getFilm()
{
      std::cout << "Id :" << this->id << std::endl <<
         "Nume:" << this->nume << std::endl <<
         "Animatie (1 = da ; 0 = nu) : " << this->animatie << std::endl <<
         "Restrictie/Rating : " << this->restrictie << std::endl <<
         "Director : " << this->director << std::endl <<
         "Categoria : " << this->categoria << std::endl <<
         "Durata (in minute) : " << this->durata << std::endl <<
         "Rating : " << this->rating << std::endl <<
         "Nr Filme : " << this->nrFilme << std::endl <<
         "Note :" << std::endl;
         for (int i = 0 ; i < this->note.size(); i++)
            std::cout << note[i] << ' ';

         std::cout << "\n********************" << std::endl;

}
Film::getId()
{
    return this->id;
}

bool Film::getAnimatie()
{
    return this->animatie;
}

char Film::getRestrictie()
{
    return this->restrictie;
}
char* Film::getDirector()
{
    return this->director;
}
char* Film::getCategoria()
{
    return this->categoria;
}
float Film::getDurata()
{
    return this->durata;
}
double Film::getRating()
{
    return this->rating;
}
std::string Film::getNume()
{
    return this->nume;
}
int Film::getNrFilme()
{
    return this->nrFilme;
}
std::vector<int> Film::getNote()
{
    return this->note;
}
int Film::nrFilme = 0;
/// ###############  SETTERS  ####################

void Film::setId(int id)
{
    this->id = id;
}
void Film::setAnimatie(bool animatie)
{
    this->animatie = animatie;
}


void Film::setDirector(char* director)
{
    if (this->director != NULL)
        delete[] this->director;

    this->director = new char[strlen(director) + 1];
    strcpy(this->director, director);

}
void Film::setCategoria(char categoria[])
{
    strcpy(this->categoria, categoria);
}

void Film::setDurata(float durata)
{
    this->durata = durata;
}
void Film::setRating(double rating)
{
    this->rating = rating;
}
void Film::setNume(std::string nume)
{
    this->nume = nume;
}
void Film::setNrFilme(int nrFilme)
{
    this->nrFilme = nrFilme;
}
Film& Film::operator + (Film& f1)
{
    this->rating = (this->rating + f1.rating)/2;
    return *this;
}

Film& Film::operator - (Film& f1)
{
    this->rating = (this->rating - f1.rating)/2;
    return *this;
}
Film& Film::operator = (Film& f)
{
    if (this != &f)
    {
        this-> id = f.id;
        this-> animatie = f.animatie;
        if (this->director != NULL)
            delete[] this->director;
        this->director = new char[strlen(f.director)+1];
        strcpy(this->director, f.director);
        strcpy(this-> categoria, f.categoria);
        this-> durata = f.durata;
        this-> rating = f.rating;
        this->nrFilme = f.nrFilme;
        this-> nume = f.nume;
        return *this;
     }
}
Film& Film::operator -- ()
{
    this->rating -= 0.5;
    return *this;
}

Film& Film::operator ++ ()
{
    this->rating += 0.5;
    return *this;
}

 std::ostream& operator << (std::ostream& out,const Film& f)
{
         out << "Id :" << f.id << std::endl <<
         "Nume:" << f.nume << std::endl <<
         "Animatie (1 = da ; 0 = nu) : " << f.animatie << std::endl <<
         "Restrictie/Rating : " << f.restrictie << std::endl <<
         "Director : " << f.director << std::endl <<
         "Categoria : " << f.categoria << std::endl <<
         "Durata (in minute) : " << f.durata << std::endl <<
         "Rating : " << f.rating << std::endl <<
         "Nr Filme : " << f.nrFilme << std::endl <<
         "********************" << std::endl;

         return out;
}

 std::istream& operator >>(std::istream& in, Film& f)
     {
         std::cout << "Nume : ";
         in >> f.nume;
         std::cout << "Animatie (1 = da, 0 = nu) : ";
         in >> f.animatie;
         std::cout << "Director : ";
         in >> f.director;
         std::cout << "Categoria : ";
         in >> f.categoria;
         std::cout << "Durata : ";
         in >> f.durata;
         std::cout << "Rating : ";
         in >> f.rating;

        return in;
     }

bool Film::operator ==(Film &f)
{
    if(this->rating == f.rating)
        return 1;
    else
        return 0;

}
bool Film::operator >(Film &f)
{
    if(this->rating > f.rating)
        return 1;
     else
        return 0;
}

Film::operator int()
{
    return (int)this->rating;
}

int Film::operator[](int index)
 {
     if (index > this->note.size()-1)
     {
        std::cout << "Eroare\n";
        return 0;
     }
     else
        return this->note[index];

 }

void Film:: nota(float nota)
{
    if (this->note.size() == 0)
    {
        this->rating = nota;
        this->note.push_back(nota);
    }
    else
    {
        this->note.push_back(nota);
        float media = 0;
        for (int i = 0; i < this->note.size();i++)
        {
            media += this->note[i];
        }
        this->rating = media / this->note.size();
    }
}


Film::~Film()
{
    if (this->director != nullptr)
        delete[] this->director;

}













/*
                                     )
                            )      ((     (
                           (        ))     )
                    )       )      //     (
               _   (        __    (     ~->>
        ,-----' |__,_~~___<'__`)-~__--__-~->> <
        | //  : | -__   ~__ o)____)),__ - '> >-  >
        | //  : |- \_ \ -\_\ -\ \ \ ~\_  \ ->> - ,  >>
        | //  : |_~_\ -\__\ \~'\ \ \, \__ . -<-  >>
        `-----._| `  -__`-- - ~~ -- ` --~> >
         _/___\_    //)_`//  | ||]
   _____[_______]_[~~-_ (.L_/  ||
  [____________________]' `\_,/'/
    ||| /          |||  ,___,'./
    ||| \          |||,'______|
    ||| /          /|| I==||
    ||| \       __/_||  __||__
-----||-/------`-._/||-o--o---o---
  ~~~~~'
*/
