#pragma once
#include "Greske.h"
#include <iostream>
using namespace std;

template <typename T>
class Lista
{
	int br_ele = 0;
	struct Elem {
		T podatak;
		Elem* sled;
		Elem(T& podatak, Elem* s = nullptr) : podatak(podatak), sled(s) {}
	};
	Elem* prvi;
	Elem* poslednji;
	Elem* tek;

	void kopiraj(const Lista& l);
	void premesti(Lista& l);
	void izbrisi();
	void zameni(Lista& l1, Lista& l2);

public:
	Lista() { prvi = nullptr; poslednji = nullptr; tek = nullptr; }
	Lista(const Lista* l) { kopiraj(l); }
	Lista(Lista&& l) { premesti(l); }
	~Lista() { izbrisi(); }
	Lista operator=(Lista l) { zameni(*this, l); return *this; }


	void dodaj(T& podatak);
	int brojelemenata() { return br_ele; }
	void postaviprvi() const { tek = prvi; }
	void postavisled() const { tek = tek -> sled; }
	bool postavitek() { if (tek) return 1; return 0; }
	T& dohvati_tek() { if (tek) return tek->podatak; throw GNepostojeciTekuci(); }

};

template <typename T>
void Lista<T>::kopiraj(const Lista& l) {
	br_ele = l.br_ele;

	Elem* tek = l.prvi;
	Elem* poslednji = nullptr;

	while (tek)
	{
		Elem* novi = new Elem(tek->podatak);
		if (!prvi) prvi = novi;
		else poslednji->sled = novi;
		poslednji = novi;
		tek = tek->sled;
	}
}

template <typename T>
void Lista<T>::premesti(Lista& l) {
	br_ele = l.br_ele;
	prvi = l.prvi;
	l.prvi = nullptr;
}

template <typename T>
void Lista<T>::izbrisi() {
	Elem* tek = prvi, * stari;
	while (tek) {
		stari = tek;
		tek = tek->sled;
		delete stari;
	}
}

template <typename T>
void Lista<T>::zameni(Lista& l1, Lista& l2) {
	swap(l1.br_ele, l2.br_ele);
	swap(l1.prvi, l2.prvi);
	swap(l1.poslednji, l2.poslednji);
}

template <typename T>
void Lista<T>::dodaj(T& p) {
	if (prvi) {
		poslednji->sled = new Elem(p);
		poslednji = poslednji->sled;
		br_ele++;
	}
	if (!prvi) {
		prvi = new Elem(p);
		poslednji = prvi;
		br_ele = 1;
	}
}
