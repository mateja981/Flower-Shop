#pragma once
#include "Greske.h"
#include <iostream>
using namespace std;

class Vremenska_oznaka
{
	int godina, mesec, dan, sat, minut;

public:
	Vremenska_oznaka(int g, int m, int d, int s, int min) : godina(g), mesec(m), dan(d), sat(s), minut(min) {};
	
	ostream& ispis(ostream& os) const;
	friend ostream& operator << (ostream& os, const Vremenska_oznaka& v) { return v.ispis(os); }
};

