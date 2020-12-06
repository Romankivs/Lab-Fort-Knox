
#include "AlienShip.h"

AlienShip::AlienShip(double windowW, double windowH, double startE, double flyE, double bulbaV, double bulbaM, std::vector<Parallelepiped> &AllParallelepipeds) :
	windowWidth(windowW), windowHeight(windowH), currentEnergy(startE), flyEnergy(flyE), bulbaMaxVolume(bulbaV), bulbaMaxMass(bulbaM),
	current(*(AllParallelepipeds.begin())), all(&AllParallelepipeds) {}

bool AlienShip::performAnOperation()
{
	if (currentEnergy - flyEnergy < 50 + 1e-5)
	{
		if (!flag)
		{
			std::cerr << "Not enough energy to perform a single operation" << std::endl;
			drop();
		}
		flag = true;
	}
	else
	{
		currentEnergy -= 50;
	}
	return flag;
}

bool AlienShip::checkIfGold()
{
	performAnOperation();
	if (flag)
		return false;
	bool test = (current.getDensity() > 19.10 && current.getDensity() < 19.35);
	if (!test)
		std::cerr << "It isn`t gold" << std::endl;
	return test;
}

void AlienShip::rotate()
{
	performAnOperation();
	if (!flag)
	{
		current.rotate();
	}
}

void AlienShip::turn()
{
	performAnOperation();
	if (!flag)
	{
		current.turn();
	}
}

 bool AlienShip::putNext()
{
	 performAnOperation();
	 if (all->size() == 1)
		 return false;;
	 current = *all->erase(all->begin());
	 return true;
}

void AlienShip::drop()
{
	trash.push_back(current);
}

void AlienShip::cut(double neededVolume)
{
	performAnOperation();
	if (!flag)
	{
		double neededLength = neededVolume / (current.getWidth() * current.getHeight());
		Parallelepiped cutOff = current;

		cutOff.setLength(current.getLength() - neededLength);
		trash.push_back(cutOff);
		std::cerr << "Part thrown away: " << std::endl;
		cutOff.printInfo();

		current.setLength(neededLength);
		current.recompute();
		std::cerr << "Part melted: " << std::endl;
		current.printInfo();
	}
}

bool AlienShip::checkIfFitsWindow()
{
	performAnOperation();
	if (flag)
		return false;
	if (current.getWidth() <= windowWidth && current.getHeight() <= windowHeight) // �������� �� �����������, ������ �� �����������
	{
		return true;
	}
	return false;
}

bool AlienShip::rotateAndCheckIfFitsWindow()
{
	if (!flag)
	{
		if (checkIfFitsWindow()) // ������������ ������� ��� ��������
		{
			std::cerr << "Fits the window without any movements" << std::endl;
			return true;
		}
		turn();
		if (checkIfFitsWindow()) // ������������ ������� � ����� turn
		{
			std::cerr << "Fits the window after being turned" << std::endl;
			return true;
		}
		turn();

		rotate();
		if (checkIfFitsWindow()) // ������������ ������� � ����� rotate
		{
			std::cerr << "Fits the window after being rotated" << std::endl;
			return true;
		}
		rotate();

		turn();
		rotate();
		if (checkIfFitsWindow()) // ������������ ������� � turn ���� rotate
		{
			std::cerr << "Fits the window after being turned and after that rotated" << std::endl;
			return true;
		}
		rotate();
		turn();

		rotate();
		turn();
		if (checkIfFitsWindow()) // ������������ ������� � rotate ���� turn
		{
			std::cerr << "Fits the window after being rotated and after that turned" << std::endl;
			return true;
		}
		turn();
		rotate();

		rotate();
		turn();
		rotate();
		if (checkIfFitsWindow()) // ������������ ������� � rotate ���� turn ���� rotate
		{
			std::cerr << "Fits the window after being rotated and after that turned and rotated" << std::endl;
			return true;
		}
		rotate();
		turn();
		rotate();

		std::cerr << "Doesn`t fit the window after all possible movements" << std::endl;
		return false;
	}
	return false;
}

bool AlienShip::checkIfEnoughEnergy()
{
	if (currentEnergy - current.getMass() * 66.2 >= flyEnergy + 1e-5)
		return true;
	if (currentEnergy - flyEnergy >= 50 + 1e-5)
	{
		std::cerr << "Not enough Energy need to cut off something" << std::endl;
		double neededEnergy = currentEnergy - flyEnergy - 50;
		std::cerr  << "Needed energy:" << neededEnergy << " Current Energy: " << currentEnergy << std::endl;
		double neededVolume = neededEnergy / (66.2 * current.getDensity());
		cut(neededVolume);
		return true;
	}
	std::cerr << "Not Enough Energy" << std::endl;
	return false;
}

bool AlienShip::checkIfEnoughVolume()
{
	if (current.getVolume() + bulbaCurVolume <= bulbaMaxVolume)
		return true;
	if (bulbaCurVolume < bulbaMaxVolume - 1e-5)
	{
		std::cerr << "Not enough Volume Capacity need to cut off something" << std::endl;
		double neededVolume = bulbaMaxVolume - bulbaCurVolume;
		cut(neededVolume);
		return true;
	}
	std::cerr << "Not Enough Volume Capacity Available" << std::endl;
	return false;
}

bool AlienShip::checkIfEnoughMass()
{
	if (current.getMass() + bulbaCurMass <= bulbaMaxMass)
		return true;
	if (bulbaCurMass < bulbaMaxMass - 1e-5)
	{
		std::cerr << "Not enough Carrying Capacity need to cut off something" << std::endl;
		double neededMass = bulbaMaxMass - bulbaCurMass;
		double neededVolume = neededMass / current.getDensity();
		cut(neededVolume);
		return true;
	}
	std::cerr << "Not Enough Carrying Capacity Available" << std::endl;
	return false;
}

void AlienShip::melt()
{
	bulbaCurVolume += current.getVolume() - 14.2e-6 * current.getVolume() * 296; // ��������� ������� �������� ��� ����������
	bulbaCurMass += current.getMass();

	currentEnergy -= current.getMass() * 66.2; // ������� ����㳿
	std::cerr << "Energy spent: " << current.getMass() * 66.2 << std::endl; 
	currentEnergy += 0.7 * (0.130 * current.getMass() * (296)); // �����������
	std::cerr << "Energy received: " << 0.7 * (0.130 * current.getMass() * (296)) << std::endl;

	melted.push_back(current);
}

bool AlienShip::checkIfCanBeMelted()
{
	performAnOperation();
	if (flag)
		return false;
	return (checkIfEnoughEnergy() && checkIfEnoughVolume() && checkIfEnoughMass());
}

void AlienShip::startProcess()
{
	do
	{
		flag = false;
		counter++;
		std::cerr << "Parallelepiped's Number: " << counter << std::endl;
		current.printInfo();
		if (flag)
		{
			std::cerr << "Not enough energy to perform a single operation"  << std::endl;
			drop();
		}
		else
		{
			if (!(checkIfGold()) || !(rotateAndCheckIfFitsWindow()) || !(checkIfCanBeMelted()))
			{
				if (!flag)
					drop();
			}
			else
				melt();
			std::cerr << "Energy left: " << currentEnergy << " Mass of Gold: " << bulbaCurMass << " Volume of Gold: " << bulbaCurVolume << std::endl;
			std::cerr << "____________________________________________________________________________________________________________________" << std::endl;
		}
	} while (putNext());
	flyAway();
}

void AlienShip::flyAway()
{
	std::cerr << "Psssssh... Flew Away... " << std::endl;
	currentEnergy -= flyEnergy;
	std::cerr << "Trash:" << std::endl; // ���� ���������� ��� �� ������� �������������
	for (auto e : trash) {
		e.printInfo();
	}
	std::cerr << "Melted:" << std::endl; // ���� ���������� ��� �� ������������ �������������
	for (auto e : melted) {
		e.printInfo();
	}
	std::cerr << "Energy left: " << currentEnergy << " Mass of Gold: " << bulbaCurMass << " Volume of Gold: " << bulbaCurVolume;
}