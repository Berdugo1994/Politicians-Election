//
// Created by berdu on 1/14/2020.
//

#ifndef ASS5_SOCIALREPUBLIC_H
#define ASS5_SOCIALREPUBLIC_H
#include "Politician.h"

class SocialRepublic : public Politician{
public:
    SocialRepublic(const std::string& first,const std::string& last,const int& id ,const int& my_power);
    virtual void insert_to_republic_party(Party& p ){
        p.InsertRepublican(*this);};
    virtual void insert_to_democratic_party(Party& p ){};
    virtual int primaries_power() const;
    virtual int election_power() const;
    virtual std::ostream& print_politician(std::ostream& cout)const;
    virtual ~SocialRepublic(){};
};

#endif //ASS5_SOCIALREPUBLIC_H
