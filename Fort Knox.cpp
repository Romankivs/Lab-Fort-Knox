#include <iostream>
#include <AlienShip.h>
#include <fibRan.h>
#include "define.h"


int main()
{
    fRan::newValues(1, 1, 30);
    std::vector<Parallelepiped> parallelepipeds;
    for (int i = 0; i < 300; i++)    // Заповнюємо сховище випадковими паралелепіпедами
    {
        double randomDensity = 19.23 + (pow(-1, fRan::f()) * double(fRan::f()) / 200);         
        Parallelepiped temp(fRan::f()+1, fRan::f()+1, fRan::f()+1, randomDensity);
        parallelepipeds.push_back(temp);
    }
    std::cerr << parallelepipeds.size() << std::endl;
    AlienShip ship(winW, winH , startE, flyE, MaxV, MaxM, parallelepipeds); // Створюєм наш корабель
    ship.startProcess(); // Почати процес завантаження злитків із сховища
}
