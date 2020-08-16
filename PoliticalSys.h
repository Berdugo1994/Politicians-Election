#ifndef ASS5_POLITICALSYS_H
#define ASS5_POLITICALSYS_H
#include "DemocraticParty.h"
#include "RepublicParty.h"
#include "SocialDemocrat.h"
#include "LeaderDemocrat.h"
#include "LeaderRepublic.h"
#include "SocialRepublic.h"
#include "InvalidData.h"
#include "InvalidID.h"
#include "InvalidPartyName.h"

class PoliticalSys {
public:
    PoliticalSys();
    explicit PoliticalSys(const std::string&);
    void addPolitician();
    void removePolitician();
    void addParty();
    void removeParty();
    void elections();
    virtual ~PoliticalSys();
    void printPoliticians () const;
    void printParties() const;
    void BiggestParty() const;
private:
    std::vector<Party*> sort_by_size_vec;
    std::vector<Party*> parties_vec;
    std::vector<Politician*> politicians_vec;
    void Insert_Helper(Politician& pol, int cur_size);
    void insert_politician_with_arguments(const std::string& ,const std::string&,const int& ,const int&,const char&,const char&);
    void insert_party_with_arguments(std::string,char);
    static bool Comp_Functor(Party* a,Party* b);
    void file_handling(const std::string&);
    bool no_parties() const {return parties_vec.empty();}
    bool no_politicians() const {return politicians_vec.empty();}
    std::vector<Politician*>::iterator get_pol_by_id(const int& id);
    std::vector<Party*>::iterator get_party_by_name(const std::string& name);
};


#endif //ASS5_POLITICALSYS_H

