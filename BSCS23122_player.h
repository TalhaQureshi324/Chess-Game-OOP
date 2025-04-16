#pragma once
#include<string.h>
#include<iostream>
#include"BSCS23122_allOtherFunctions.h"

using namespace std;
class Player
{
public:

	string name;
	long long Duration;
	int col;
	Position pos;
	Player();
	void p1(string na, int cl);
	string getname();
	Position SelectPortion();

};