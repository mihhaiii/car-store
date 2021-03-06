#include "Magazin.h"
#include "Masina.h"

#include <ctime>
#include <random>
Magazin::Magazin()
{
    //ctor
    // incarc 10 masini random in listaMasini
    for (int i=0;i<10;i++)
    {
        listaMasini.push_back(new Masina(Masina::getRandBrand(), Masina::getRandModel(), rand() % 1000 + 10000, rand()%60 + 1950));
    }

    _state = uninitialized;

   /* for (auto m:listaMasini)
    {
        cout << Brands2Str[m->getMarca()] << ' ' << Models2Str[m->getModel()] << ' ' << m->getPret() << ' ' << m->getAn() << endl;
    }*/
}

Magazin::~Magazin()
{
    //dtor
}

void  Magazin::startApp()
{
    cout << "----------------Bine ati Venit!!!-----------------"<<endl;
    if (_state != uninitialized)
        return;

    _mainWindow.create(sf::VideoMode(800,600),"Magazin de masini");
    _state=showingSplash;

    while (_mainWindow.isOpen())
    {
        appLoop();
    }
}

void Magazin::appLoop()
{
    switch(_state)
    {
    case exiting:
        _mainWindow.close();
        break;
    case showingSplash:
        showSplash();
        break;
    case showingMenu:
        showMenu();
        break;
    case showingLogInfo:
        showLogInfo();
        break;
    case logging:
        showLogScreen();
        break;
    case registering:
        showRegisterScreen();
        break;
    case displayingCars:
        displayCars();
        break;
    }
}

void Magazin::showMenu()
{
    Menu m;
    Menu::MenuResult res = m.show(_mainWindow);
    switch(res)
    {
    case Menu::AfiseazaMasini:
        _state = displayingCars;
        break;
    case Menu::Iesire:
        _state = exiting;
    }

}
void Magazin::showSplash()
{
    SplashScreen ss;
    ss.show(_mainWindow);
    _state=showingLogInfo;
}

void Magazin::showLogInfo()
{
    LogInfoScreen lis;
    LogInfoScreen::MenuResult res = lis.show(_mainWindow);
    switch(res)
    {
    case LogInfoScreen::Login:
        _state = logging;
        break;
    case LogInfoScreen::Register:
        _state = registering;
    }
}
void Magazin::showLogScreen()
{

    LogScreen ls;
    ls.show(_mainWindow);

    _state = showingMenu;
}
void Magazin::showRegisterScreen()
{
    RegisterScreen rs;
    rs.show(_mainWindow);

    _state = showingMenu;
}

void Magazin::displayCars()
{
    _state = showingSplash;
}
