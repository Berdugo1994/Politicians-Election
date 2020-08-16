#ifndef ASS5_POLITICIAN_CPP
#define ASS5_POLITICIAN_CPP

#include "Politician.h"
using namespace std;
bool Politician::operator==(const Politician& other)const
{
return (ID==other.ID);
}
std::ostream& Politician::print_politician(std::ostream& out) const
{
    out<<first_name<<" "<<last_name<<", Id:"<<ID<<", Power:"<<power<<", ";
    return out;
}
#endif //ASS5_POLITICIAN_CPP