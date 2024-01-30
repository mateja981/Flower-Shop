#include "Elektronska_poruka.h"


string Elektronska_poruka::dohstanje() const
{
	switch (stanje)
	{
	case Elektronska_poruka::U_PRIPREMI:
		return "U_PRIPREMI";
		break;
	case Elektronska_poruka::POSLATA:
		return "POSLATA";
		break;
	case Elektronska_poruka::PRIMLJENA:
		return "POSLATA";
		break;
	}
}

ostream& Elektronska_poruka::ispis(ostream& os) const
{
	os << naslov << endl;
	os << *posiljalac << endl;
	os << *primalac << endl;

	return os;
}

