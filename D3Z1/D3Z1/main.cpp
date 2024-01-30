#include <iostream>
#include "Greske.h"
#include "Lista.h"
#include "Korisnik.h"
#include "Elektronska_poruka.h"
#include "Elektronska_poruka_sa_tekstom.h"
using namespace std;

int main() {

	try
	{
		Korisnik k1("Korisnik1", "korisnik1@gmail.com"), k2("Korisnik2", "korisnik2@gmail.com");


		Elektronska_poruka_sa_tekstom et1(&k1, &k2, "Naslov et1");
		et1.posaljitext("Text poruke et1");
		et1.posalji();
		cout << et1;
		//et1.posaljitext("da li mogu sad da posaljem");
	}
	catch (exception e) {
		cout << e.what() << endl;
	}
}