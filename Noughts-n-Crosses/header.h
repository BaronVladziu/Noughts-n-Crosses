#pragma once
#include "SFML\Graphics.hpp"
#include <memory>
#include <iostream>
#include <fstream>
#include <vector>
#include <list>

class Tab;
class Program;
class Icon;
class IconVoid;
class IconNought;
class IconCross;
enum Mark
{
	V, //Void - puste pole
	O, //O - k�ko
	X, //X - krzy�yk
	N  //Niedozwolone - pole poza plansz�
};
class Algorithm;
class TestAlgorithm;
class CountingAlgorithm;