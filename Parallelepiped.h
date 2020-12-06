#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

class Parallelepiped
{
public:
	Parallelepiped(const double l, const double w, const double h, const double dens); //����������� �����
	
	void printInfo();

	double getLength();

	double getWidth();

	double getHeight();

	double getDensity();

	double getMass();

	double getVolume();

	void setLength(const double l);

	void setWidth(const double w);

	void setHeight(const double h);

	void setDensity(const double d);
	
	void recompute(); // ��������� ���� �� ��'��

	void rotate(); // ������ ����� ��� ���������

	void turn(); // ������� ����� ��� �����

private:
	void computeVolume();

	void computeMass();

	double length;
	double width;
	double height;

	double volume;
	double density;
	double mass;
};

