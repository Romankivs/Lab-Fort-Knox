#pragma once
#include "Parallelepiped.h"

class AlienShip
{
public:
	AlienShip(double windowW, double windowH, double startE, double flyE, double bulbaV, double bulbaM, std::vector<Parallelepiped> &AllParallelepipeds);

	bool performAnOperation(); // ��������� �� ��������� ����㳿 ��� ���� ���������� ��������, ���� ��� �� ������ �� ������ �� ��������

	bool checkIfGold(); // ��������� �� � ������������ �������

	void rotate(); // ������ ����� ������������� �� ������ ��� ���������

	void turn(); // ������� ����� ������������� �� ������ ��� �����

	bool putNext(); // ��������� ����� ������������ �� ������

	void drop(); // �������� ������������

	void cut(double neededVolume); // �������� ������

	bool checkIfFitsWindow(); // ��������� �� ������ ������ ���� � ������

	bool rotateAndCheckIfFitsWindow(); // ��������� ������ ������ ���������, �� �� ��������� checkIfFitsWindow() ��������� �� ���� � ������

	bool checkIfEnoughEnergy(); // ���������� �� ��������� ����㳿

	bool checkIfEnoughVolume(); // ���������� �� ��������� ������ ��'��� � �����

	bool checkIfEnoughMass(); // ���������� �� ��������� ������ ������� �������������� � �����
	
	void melt(); // ���������� ������

	bool checkIfCanBeMelted(); // ��������� �� ����� ���������� ( �������� ������  checkIfEnoughEnergy(), checkIfEnoughVolume(), checkIfEnoughMass()

	void startProcess(); // ��������� ������ 

	void flyAway(); // ��������� ������
private:
	bool flag = false; // ���� ������� performAnOperation() ������� false, �� ��� ��������� �������� �� true

	double windowHeight; // ������ ������
	double windowWidth;  // ������ ������

	double currentEnergy; // ������ � ���� �������� ������
	double flyEnergy; // ������, �� ������� ������� ��� ���������� ������

	double bulbaMaxVolume; // ������������ ��'�� ������
	double bulbaCurVolume = 0; // ��'�� ������, ���� ����������� � �����
	double bulbaMaxMass; // ��������������
	double bulbaCurMass = 0; // ���� ������ � �����

	unsigned int counter = 0; // ����� ������

	Parallelepiped current; // ������������ ���� ����������� �� ������

	std::vector<Parallelepiped> *all; // �������� �� ������ � ���� �������������, �� � � �������
	std::vector<Parallelepiped> melted; // ������ ��� �������������, �� ���� ������� �������� �������
	std::vector<Parallelepiped> trash; // ������ ��� �������������, �� ���� ������� �������� �������
};

