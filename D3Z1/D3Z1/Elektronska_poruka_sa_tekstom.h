#pragma once
#include "Elektronska_poruka.h"
class Elektronska_poruka_sa_tekstom: public Elektronska_poruka
{
	string text;
public:
	Elektronska_poruka_sa_tekstom(Korisnik* pos, Korisnik* prim, string nas) : Elektronska_poruka(pos,prim,nas){}
	void posaljitext(string s) { if (stanje == POSLATA) throw GPorukaVecPoslata(); text = s; }
	void posalji() override { stanje = POSLATA; }
	Elektronska_poruka* kopiraj() override { return new Elektronska_poruka_sa_tekstom(*this); }
	ostream& ispistexta(ostream& os) const;
	friend ostream& operator << (ostream& os, const Elektronska_poruka_sa_tekstom& e) { return e.ispistexta(os); }
};

