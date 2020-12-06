#pragma once
#include "Parallelepiped.h"

class AlienShip
{
public:
	AlienShip(double windowW, double windowH, double startE, double flyE, double bulbaV, double bulbaM, std::vector<Parallelepiped> &AllParallelepipeds);

	bool performAnOperation(); // Перевірити чи достатньо енергії для однієї стандартної операції, якщо так то відняти цю енергію від доступної

	bool checkIfGold(); // Перевірити чи є паралелепіпед золотом

	void rotate(); // верхня грань паралелепіпеда на конвеєрі стає передньою

	void turn(); // передня грань паралелепіпеда на конвеєрі стає бічною

	bool putNext(); // Поставити новий паралелепіпед на конвеєр

	void drop(); // Викинути паралелепіпед

	void cut(double neededVolume); // Зменшити злиток

	bool checkIfFitsWindow(); // Перевірити чи злиток золота влізає у віконце

	bool rotateAndCheckIfFitsWindow(); // Повернути злиток різними варіантами, та за допомогою checkIfFitsWindow() перевірити чи влізає у віконце

	bool checkIfEnoughEnergy(); // Перервірити чи достатньо енергії

	bool checkIfEnoughVolume(); // Перервірити чи достатньо запасу об'єму у бульбі

	bool checkIfEnoughMass(); // Перервірити чи достатньо запасу можливої грузопідйомності у бульбі
	
	void melt(); // Розплавити золото

	bool checkIfCanBeMelted(); // Перевірити чи можна розплавити ( Виконати почерзі  checkIfEnoughEnergy(), checkIfEnoughVolume(), checkIfEnoughMass()

	void startProcess(); // Запустити процес 

	void flyAway(); // Вернутися додому
private:
	bool flag = false; // Якщо функція performAnOperation() видасть false, то цей прапорець зміниться на true

	double windowHeight; // Висота віконця
	double windowWidth;  // Ширина віконця

	double currentEnergy; // Енергія з якою корабель прилітає
	double flyEnergy; // Енергія, що потрібна кораблю для повернення додому

	double bulbaMaxVolume; // Максимальний об'єм бульби
	double bulbaCurVolume = 0; // Об'єм золота, який знаходиться в бульбі
	double bulbaMaxMass; // Грузопідйомність
	double bulbaCurMass = 0; // Маса золота в бульбі

	unsigned int counter = 0; // Номер злитку

	Parallelepiped current; // Паралелепіпед який знаходиться на конвеєрі

	std::vector<Parallelepiped> *all; // Вказівник на вектор з усіма паралелепіпада, що є у сховищі
	std::vector<Parallelepiped> melted; // Список усіх паралелепіпедів, що були прийняті конвеєром корабля
	std::vector<Parallelepiped> trash; // Список усіх паралелепіпедів, що були викинуті конвеєром корабля
};

