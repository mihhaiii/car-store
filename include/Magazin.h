#ifndef MAGAZIN_H
#define MAGAZIN_H

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "masina.h"
#include "SFML/Graphics.hpp"
#include "C:\Users\Mihai\Desktop\magazin_masini\utils.h"
#include "SplashScreen.h"
#include "LogInfoScreen.h"
#include "LogScreen.h"
#include "RegisterScreen.h"
#include "Menu.h"
using namespace std;

class Magazin
{
    public:
        Magazin();
        virtual ~Magazin();
        void startApp();

        void showMenu();
        void showSplash();
        void showLogInfo();
        void showLogScreen();
        void showRegisterScreen();
        void displayCars();

    protected:

    private:
        vector<Masina*> listaMasini;
        States _state;
        sf::RenderWindow _mainWindow;

        void appLoop();
};

#endif // MAGAZIN_H
