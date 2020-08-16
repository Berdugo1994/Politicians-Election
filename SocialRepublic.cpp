#ifndef ASS5_SOCIALREPUBLIC_CPP
#define ASS5_SOCIALREPUBLIC_CPP
#include "SocialRepublic.h"
SocialRepublic::SocialRepublic(const std::string& first,const std::string& last,const int& id ,const int& my_power):Politician(first,last,id,my_power){}
std::ostream& SocialRepublic::print_politician(std::ostream& cout) const
{
    cout<<"Republican Person:";
    Politician::print_politician(cout);
    cout<<"Type:S, Chairman: "<<head_of_party;
}
int SocialRepublic::primaries_power() const
{
    return -1;//social politician doesnt include in primaries.
}
int SocialRepublic::election_power() const
{
    return power*2;
}

#endif