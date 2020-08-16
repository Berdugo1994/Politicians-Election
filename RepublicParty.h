#ifndef ASS5_REPUBLICPARTY_H
#define ASS5_REPUBLICPARTY_H

#include "Party.h"
class RepublicParty : public Party{
public:
    RepublicParty(std::string& name);
    void InsertDemocratic (Politician& p) {};
    void InsertRepublican (Politician& p) {add_politician(p) ;};
    virtual std::ostream& print_party(std::ostream& out)const ;
    virtual  ~RepublicParty(){};
};


#endif //ASS5_REPUBLICPARTY_H
