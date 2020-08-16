#ifndef ASS5_LEADERDEMOCRAT_CPP
#define ASS5_LEADERDEMOCRAT_CPP

#include "LeaderDemocrat.h"
LeaderDemocrat::LeaderDemocrat(const std::string& first,const std::string& last,const int& id ,const int& my_power):Politician(first,last,id,my_power) {}
std::ostream& LeaderDemocrat::print_politician(std::ostream& cout) const
{
    cout<<"Democratic Person:";
    Politician::print_politician(cout);
    cout<<"Type:L, Chairman: "<<head_of_party;
}
int LeaderDemocrat::primaries_power() const
{
    return power;//social politician doesnt include in primaries.
}
int LeaderDemocrat::election_power() const
{
    return power;
}

#endif