#ifndef ASS5_PARTY_H
#define ASS5_PARTY_H
#include <string>
#include <iostream>
#include "Politician.h"
#include <vector>
class Politician;
class Party{
public:
    Party(const std::string& name);
    bool add_politician(Politician& pol);
    bool remove_politician(Politician& pol);
    virtual void Primaries();
    virtual int get_political_power()const;
    friend std::ostream& operator<<(std::ostream& out,Party &p){return p.print_party(out);};
    virtual std::ostream& print_party(std::ostream& out)const=0;
    virtual void InsertDemocratic(Politician& pol1)=0;
    virtual void InsertRepublican(Politician& pol2)=0;
    std::string get_party_name()const {return party_name;}
    int get_size() const{return party_members.size();}
    std::string get_head_of_party_name()const {return head_of_party;}
    void notify_all_members_in_party()const;
    std::vector<Politician*> get_members_vec()const {return party_members;}
    void set_head_of_party_name(const std::string& new_name){head_of_party=new_name;}
    void set_party_name(const std::string& new_name){party_name=new_name;}
    virtual ~Party();
protected:
    std::string party_name;
    std::string head_of_party;
    std::vector<Politician*> party_members;
};


#endif //ASS5_PARTY_H
