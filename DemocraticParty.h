#ifndef ASS5_DEMOCRATICPARTY_H
#define ASS5_DEMOCRATICPARTY_H
#include "Party.h"
class DemocraticParty : public Party
{
public:
    void InsertDemocratic (Politician& p) {add_politician(p) ;};
    void InsertRepublican (Politician& p) {};
    virtual std::ostream& print_party(std::ostream& out) const;
    DemocraticParty(std::string& name);
    virtual  ~DemocraticParty(){};
};


#endif //ASS5_DEMOCRATICPARTY_H
