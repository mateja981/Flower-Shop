#pragma once
#include "Greske.h"
#include <iostream>
using namespace std;

class Korisnik
{
	string ime;
	string e_adresa;

public:

	Korisnik(string i, string e): ime(i), e_adresa(e) {}

	string dohime() { return ime; }
	string dohea() { return e_adresa; }

	Korisnik(const Korisnik&) = delete;
	void operator=(const Korisnik&) = delete;

	ostream& ispis(ostream& os) const;
	friend ostream& operator << (ostream& os, const Korisnik& k) { return k.ispis(os); }


};

