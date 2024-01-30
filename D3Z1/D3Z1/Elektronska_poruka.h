#pragma once
#include "Greske.h"
#include "Korisnik.h"
#include <iostream>
using namespace std;

class Elektronska_poruka
{
protected:
	string naslov;
	Korisnik* posiljalac,*primalac;
	enum mogucestanje {U_PRIPREMI,POSLATA,PRIMLJENA };
	mogucestanje stanje = U_PRIPREMI;

public:
	string dohnaslov()const { return naslov; }
	Korisnik& dohpos()const { return *posiljalac; }
	Korisnik& dohprim()const { return *primalac; }
	string dohstanje()const;

	Elektronska_poruka(Korisnik* pos, Korisnik* prim, string nas) : posiljalac(pos), primalac(prim), naslov(nas) {}
	virtual void posalji() = 0;
	virtual Elektronska_poruka* kopiraj() = 0;
	ostream& ispis(ostream& os) const;
	friend ostream& operator << (ostream& os, const Elektronska_poruka& e) { return e.ispis(os); }
};