#include "Vremenska_oznaka.h"

ostream& Vremenska_oznaka::ispis(ostream& os) const
{
    os << dan << ".";
    os << mesec << ".";
    os << godina << "-";
    os << sat << ":";
    os << minut << endl;

    return os;
}
