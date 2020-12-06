
#include "Parallelepiped.h"

Parallelepiped::Parallelepiped(const double l, const double w, const double h, const double dens) : length(l), width(w), height(h), density(dens) 
{
	recompute();
}

void Parallelepiped::printInfo()
{
	std::cerr << "Length: " << length << " Width: " << width << " Height: " << height << " Density: "<< density << " Volume: " << volume << " Mass: " << mass << std::endl;
}

double Parallelepiped::getLength()
{
	return length;
}

double Parallelepiped::getWidth()
{
	return width;
}

double Parallelepiped::getHeight()
{
	return height;
}

double Parallelepiped::getDensity()
{
	return density;
}

double Parallelepiped::getMass()
{
	return mass;
}

double Parallelepiped::getVolume()
{
	return volume;
}

void Parallelepiped::setLength(const double l)
{
	length = l;
	recompute();
}

void Parallelepiped::setWidth(const double w)
{
	width = w;
	recompute();
}

void Parallelepiped::setHeight(const double h)
{
	height = h;
	recompute();
}

void Parallelepiped::setDensity(const double d)
{
	density = d;
	recompute();
}

void Parallelepiped::computeVolume()
{
	volume = length * width * height;
}

void Parallelepiped::computeMass()
{
	mass = volume * density;
}

void Parallelepiped::recompute()
{
	computeVolume();
	computeMass();
}

void Parallelepiped::rotate()
{
	std::swap(length, height);
}

void Parallelepiped::turn()
{
	std::swap(length, width);
}
