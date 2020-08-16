#ifndef ASS5_POLITICIAN_H
#define ASS5_POLITICIAN_H
#include "Party.h"
#include <iostream>
#include <string>
using namespace std;
class Party;
class Politician
{
public:
    Politician(const std::string& first, const std::string& last,const int& id ,const int& my_power):
    first_name(first),last_name(last),ID(id),power(my_power){head_of_party="None";Party_name="Has_No_Party";};
    Politician(Politician& new_p){ };
    virtual void insert_to_republic_party(Party& p)=0;
    virtual void insert_to_democratic_party(Party& p)=0;
    virtual int primaries_power() const=0;
    virtual int election_power() const=0;
    friend std::ostream& operator <<(std::ostream &out, const Politician &pol){return pol.print_politician(out);}
    virtual std::ostream& print_politician(std::ostream& out)const =0;
    Politician(const Politician &pol){};
    bool operator ==(const Politician& other)const;
    void Update(const std::string& new_head,const std::string& party_name){head_of_party=new_head; Party_name=party_name;};
    std::string& get_name(){return first_name;}
    std::string& get_party_name(){return Party_name;}
    int get_ID() const{return ID;};
    virtual ~Politician(){};
protected:
    std::string first_name;
    std::string last_name;
    int ID;
    int power;
    std::string Party_name;
    std::string head_of_party;
};



#endif //ASS5_POLITICIAN_H
