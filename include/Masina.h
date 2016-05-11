#ifndef MASINA_H
#define MASINA_H

#include <iostream>
#include <string>
#include <map>
#include "C:\Users\Mihai\Desktop\magazin_masini\utils.h"

using namespace std;

class Masina
{
    public:
        Masina();
        Masina(Brands,Models,int,int);
        virtual ~Masina();

        static Models getRandModel();
        static Brands getRandBrand();

        Brands getMarca();
        Models getModel();
        int getPret();
        int getAn();

    protected:

    private:
        Brands marca;
        Models model;
        int pret;
        int an;
};

#endif // MASINA_H
