#ifndef FILM_H
#define FILM_H
#include <string>
#include <vector>
#include <fstream>
class Film
{
    private:
    int id;
    bool animatie; /// sau live-action
    const char restrictie;
    /*
    Rated G: Suggested for general audiences.
    Rated M: Suggested for mature audiences - Parental discretion advised.
    Rated R: Restricted – persons under 16 not admitted, unless accompanied by parent or adult guardian.
    Rated X: Persons under 16 not admitted.
    */
    char* director;
    char categoria[100];
    float durata;
    double rating;
    std::string nume;
    static int nrFilme;
    std::vector<int> note;

    public:
    Film();
    Film(bool anim, char res, char dir[],
            char categ[], float dur, double rat, std::string nume);
    Film(bool anim, char res, char dir[],
            char categ[], float dur, double rat, std::string nume, int nrNote, int note[]);
    Film(const Film& f);

    void getFilm();
    int getId();
    bool getAnimatie();
    char getRestrictie();
    char* getDirector();
    char* getCategoria();
    float getDurata();
    double getRating();
    std::string getNume();
    int getNrFilme();
    std::vector<int> getNote();

    void setId(int id);
    void setAnimatie(bool animatie);
    void setRestrictie(char restrictie);
    void setDirector(char* director);
    void setCategoria(char categoria[]);
    void setDurata(float durata);
    void setRating(double rating);
    void setNume(std::string nume);
    void setNrFilme(int nrFilme);

    void nota(float nota);



    Film& operator + (Film& f1);
    Film& operator - (Film& f1);
    Film& operator = (Film& f);
    Film& operator -- ();
    Film& operator ++ ();
    int operator[](int index);

     friend std::ostream& operator << (std::ostream& out,const Film& f);
     friend std::istream& operator >>(std::istream& in, Film& f);



     bool operator ==(Film &f);
     bool operator >(Film &f);
     explicit operator int();


    virtual ~Film();

    protected:

};

#endif // FILM_H
