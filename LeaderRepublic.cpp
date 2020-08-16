#ifndef ASS5_LEADERREPUBLIC_CPP
#define ASS5_LEADERREPUBLIC_CPP

#include "LeaderRepublic.h"
LeaderRepublic::LeaderRepublic(const std::string& first,const std::string& last,const int& id ,const int& my_power):Politician(first,last,id,my_power) {}
std::ostream& LeaderRepublic::print_politician(std::ostream& cout) const
{
    cout<<"Republican Person:";
    Politician::print_politician(cout);
    cout<<"Type:L, Chairman: "<<head_of_party;
}
int LeaderRepublic::primaries_power() const
{
    return power;//social politician doesnt include in primaries.
}
int LeaderRepublic::election_power() const
{
    return power;
}

#endif