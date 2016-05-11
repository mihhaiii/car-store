#include "Masina.h"
#include <ctime>
#include <random>
Masina::Masina()
{
    //ctor
}

Masina::~Masina()
{
    //dtor
}
Masina::Masina(Brands s, Models t, int a, int b) :
   marca(s), model(t), pret(a), an(b)  {}


Brands Masina::getRandBrand()
{
    return (Brands)(rand() % 5);
}

Models Masina::getRandModel()
{
    return Models(rand() % 5);
}

Brands Masina::getMarca() {
    return marca;
}
Models Masina::getModel() {
    return model;
}
int Masina::getPret() {
    return pret;
}
int Masina::getAn() {
    return an;
}

