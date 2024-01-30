#include "Elektronska_poruka_sa_tekstom.h"

ostream& Elektronska_poruka_sa_tekstom::ispistexta(ostream& os) const
{
    ispis(os);
    os << text << endl;
    return os;
}
