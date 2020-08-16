#ifndef ASS5_DEMOCRATICPARTY_CPP
#define ASS5_DEMOCRATICPARTY_CPP
#include "DemocraticParty.h"
DemocraticParty::DemocraticParty(std::string& name):Party(name){};
std::ostream& DemocraticParty::print_party(std::ostream &cout)const
{
    std::cout<<"Democrat Party: ";
    Party::print_party(cout);
    return cout;
}

#endif //ASS5_DEMOCRATICPARTY_CPP