#ifndef ASS5_PARTY_CPP
#define ASS5_PARTY_CPP
#include "Party.h"

Party::Party(const std::string& name):party_name(name), head_of_party("None"){}

void Party::Primaries() {
    std::string old_head=head_of_party;

    int max_power = 0;
    std::vector<Politician *>::iterator it;
    for (it = party_members.begin(); it != party_members.end(); ++it) {
        if (head_of_party == "None" && (*it)->primaries_power() > 0) {
            head_of_party = (*it)->get_name();
            max_power = (*it)->primaries_power();
        }

        if ((*it)->primaries_power() > max_power) {
            head_of_party = (*it)->get_name();
            max_power = (*it)->primaries_power();
        }
    }
    if (old_head==head_of_party) return;//in case of Head stayed None or Didnt Change!
    //NOTIFY :
    // Update all head_of_party field in all party members!
    for (it = party_members.begin(); it != party_members.end(); ++it)
    {
        (*it)->Update(head_of_party,party_name);
    }
}
int Party::get_political_power()const
{
    int sum_power=0;
    std::vector<Politician*>::const_iterator it;
    for ( it=party_members.begin();it!=party_members.end();it++)
    {
        sum_power+=(*it)->election_power();
    }
    return sum_power;
}
std::ostream& Party::print_party(std::ostream &cout)const
{
    std::cout << party_name << ", chairman:" << head_of_party << ", Size:" << party_members.size();
    std::vector<Politician*>::const_iterator it;
    if (!party_members.empty())
    {std::cout<<std::endl;
        for (it = party_members.begin(); it != party_members.end()-1 ; ++it)
        {
            std::cout << "\t";
            (*it)->print_politician(cout);
            std::cout << std::endl;
        }
        std::cout << "\t";
        std::vector<Politician*>::const_iterator last = party_members.end();
        --last;
        (*last)->print_politician(cout);
        return cout;
    }
    return cout;
}

bool Party::add_politician(Politician& pol)
{
    //if we here we sure we want to get inside here
    party_members.push_back(&pol);
    pol.Update(head_of_party,party_name);
    return true;
}

bool Party::remove_politician( Politician& pol)
{
    //notify_all_members_in_party();//notify all party members that head of party *MIGHT* be changed
    std::vector<Politician*>::iterator it;
    it = party_members.begin();
    while (it != party_members.end())
    {
        if (*(*it) == pol) {
            it = party_members.erase(it);
            return true;
        }
        ++it;
    }
    return false;
}
void Party::notify_all_members_in_party()const
{
    std::vector<Politician*>::const_iterator it;
    for (it = party_members.begin(); it != party_members.end(); ++it)
    {
        (*it)->Update(head_of_party,party_name);
    }
}

Party::~Party()
{

    party_members.clear();
}

#endif //ASS5_PARTY_CPP