#ifndef ASS5_SOCIALDEMOCRAT_CPP
#define ASS5_SOCIALDEMOCRAT_CPP

#include "SocialDemocrat.h"
SocialDemocrat::SocialDemocrat(const std::string& first,const std::string& last,const int& id ,const int& my_power):Politician(first,last,id,my_power) {}
std::ostream& SocialDemocrat::print_politician(std::ostream& cout) const
{
    cout<<"Democratic Person:";
    Politician::print_politician(cout);
    cout<<"Type:S, Chairman: "<<head_of_party;
}
int SocialDemocrat::primaries_power() const
{
    return -1;//social politician doesnt include in primaries.
}
int SocialDemocrat::election_power() const
{
    return power*2;
}

#endif