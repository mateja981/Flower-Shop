#include "Korisnik.h"

ostream& Korisnik::ispis(ostream& os) const
{
    os << "(" << ime << ")" << e_adresa;
    return os;
}
