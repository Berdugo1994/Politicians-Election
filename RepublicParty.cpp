#ifndef ASS5_REPUBLICPARTY_CPP
#define ASS5_REPUBLICPARTY_CPP
#include "RepublicParty.h"
RepublicParty::RepublicParty(std::string& name):Party(name){}
std::ostream& RepublicParty::print_party(std::ostream &cout)const
{
    std::cout<<"Republican Party: ";
    Party::print_party(cout);
    return cout;
}
#endif //ASS5_REPUBLICPARTY_CPP