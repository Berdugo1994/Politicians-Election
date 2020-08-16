#ifndef ASS5_POLITICALSYS_CPP
#define ASS5_POLITICALSYS_CPP

#include <algorithm>
#include "PoliticalSys.h"
#include <iostream>
#include <fstream>
#include <sstream>

PoliticalSys::PoliticalSys(){}
PoliticalSys::PoliticalSys(const std::string& tfile)
{
    file_handling(tfile);
}

void  PoliticalSys::addPolitician()
{
    cout<<"---Create Politician---"<<endl;
    std::string f_name;
    std::string l_name;
    char side;
    char type;
    int id;
    int power;
    while(true)
    {
        try
        {
            std::cout << "First name:" << std::endl;
            std::cin >> f_name;
            std::cout << "Last name:" << std::endl;
            std::cin >> l_name;
            std::cout << "ID:" << std::endl;
            std::cin >> id;
            std::cout << "Power:" << std::endl;
            std::cin >> power;
            std::cout << "Republican or Democratic person" << std::endl;
            std::cin >> side;
            std::cout << "Leader or Social" << std::endl;
            std::cin >> type;
            if(get_pol_by_id(id)!=politicians_vec.end()||power<0||(side!='D'&& side!='R')||(type!='S'&& type!='L')||id<=0)
            {
                throw InvalidData();
            }
            insert_politician_with_arguments(f_name,l_name,id,power,side,type);
            break;
        }
        catch(exception& e)
        {
            cout<<e.what();
        }
    }
}

void PoliticalSys::insert_politician_with_arguments(const std::string& f_name,const std::string& l_name,const int& id ,
        const int& power,const char& side,const char& type){
    int cur_party_size = -1;
    Politician* tmp;
    if(side=='R')
    {
        if(type=='L')
        {
             tmp =new LeaderRepublic(f_name,l_name,id,power);
        }
        else
        {
            tmp =new SocialRepublic(f_name,l_name,id,power);
        }
    }
    else
    {
        if (type == 'L')
        {
            tmp = new LeaderDemocrat(f_name, l_name, id, power);
        }
        else
        {
            tmp = new SocialDemocrat(f_name, l_name, id, power);
        }
    }
    if(tmp== NULL){delete this;std::terminate();} //old compailer , can't run nullptr
    politicians_vec.push_back(tmp);//Add To Politicians System
    std::vector<Party *>::iterator it;
    Insert_Helper(*tmp,cur_party_size);
    try {
        //comp functor is static and cant deallocate memory in case of args are  null
        std::sort(sort_by_size_vec.begin(), sort_by_size_vec.end(), Comp_Functor);
    }
    catch(...)
    {
        delete(this);
        terminate();
    }
}


//first part insert of party
void PoliticalSys::addParty() {
    std::string new_name;
    char side;
    cout<<"---Create Party---"<<endl;
    while(true)
    {
        try
        {
            std::cout << "Name:" << std::endl;
            std::cin >> new_name;
            std::cout << "Republican or Democratic party" << std::endl;
            std::cin >> side;
            if(get_party_by_name(new_name)!=parties_vec.end())
            {
                throw InvalidData();
            }
            insert_party_with_arguments(new_name,side);
            break;
        }
        catch(exception& e)
        {
            cout<<e.what();
        }
    }
}


//second part insert of party
void PoliticalSys::insert_party_with_arguments(std::string new_name, char side)
{
    Party* new_party;


    if(side=='R')
    {
        new_party=new RepublicParty(new_name);
    }
    else
    {
        new_party=new DemocraticParty(new_name);
    }
    if(new_party== NULL)
    {
        delete this;
        std::terminate();
    }
    //nullptr doesn't work
    sort_by_size_vec.push_back(new_party);
    parties_vec.push_back(new_party);
    Party* old_party;
    std::string cur_party_name;
    std::vector<Politician*>::iterator it;
    for (it = politicians_vec.begin(); it != politicians_vec.end(); ++it)
    {//go over each politician

        // when politician has_no_party, we try to add him to the party;
        if((*it)->get_party_name()=="Has_No_Party" )
        {
                (*it)->insert_to_republic_party(*new_party);
                (*it)->insert_to_democratic_party(*new_party);
        }
        else
        {
            //when he have party already we try to add only if
            // his old party have more memmbers than the new party
            old_party = *get_party_by_name((*it)->get_party_name());
            if (old_party->get_size() > new_party->get_size())
            {
                (*it)->insert_to_republic_party(*new_party);
                (*it)->insert_to_democratic_party(*new_party);
                if(old_party->get_party_name()!=(*it)->get_party_name())
                    {
                        // if the removed politician was the head of his party,
                        // we update the Head_Of_Party to None
                        if (old_party->get_head_of_party_name()==(*it)->get_name())
                        {
                            old_party->set_head_of_party_name("None");
                            old_party->notify_all_members_in_party();
                        }
                        old_party->remove_politician( *(*it) );
                    }
            }
        }
    }
    try {
        std::sort(sort_by_size_vec.begin(), sort_by_size_vec.end(), Comp_Functor);
    }
    catch(...)
    {
        delete(this);
        terminate();
    }
}

void PoliticalSys::removePolitician()
{//calls to remove politician
    int cur_id;
    Party* cur_party;
    Politician* cur_pol;
    if(no_politicians())return;
    cout<<"---Remove Politician---"<<endl;
    while(true)
    {
        try
        {
            std::cout<<"Enter the ID:"<<std::endl;
            std::cin>>cur_id;
            if(get_pol_by_id(cur_id)==politicians_vec.end()||cur_id<=0)
            {
                throw InvalidID();
            }
            cur_pol=*get_pol_by_id(cur_id);
            if(get_party_by_name(cur_pol->get_party_name())!=parties_vec.end())
            {
                cur_party=*get_party_by_name(cur_pol->get_party_name());
                //case we want to delete head of party
                if (cur_pol->get_name() == cur_party->get_head_of_party_name())
                {
                    cur_party->set_head_of_party_name("None");
                    cur_party->notify_all_members_in_party();
                }
                //DISCONNECT POLITICIAN FROM 'PARTY MEMBERS' VECTOR
                cur_party->remove_politician(*cur_pol);
            }
            std::vector<Politician*>::iterator it;
            for(it = politicians_vec.begin();it!=politicians_vec.end();++it)
            {
                //Disconnect politician from politician-vec in political system
                if (cur_pol->get_ID()==(*it)->get_ID())
                {
                    politicians_vec.erase(it);
                    delete(cur_pol);
                    break;
                }

            }
            try {
                std::sort(sort_by_size_vec.begin(), sort_by_size_vec.end(), Comp_Functor);
            }
            catch(...)
            {
                delete(this);
                terminate();
            }
            break;
        }
        catch(exception& e)
        {
            cout<<e.what();
        }
    }
}
void PoliticalSys::removeParty()
{
    Party *cur_party;
    std::string party_name;
    if(no_parties())return;
    cout<<"---Remove Party---"<<endl;
    while(true)
    {
        try
        {
            std::cout<< "Enter party name:" << std::endl;
            std::cin >> party_name;
            if(get_party_by_name(party_name)==parties_vec.end())
            {
                throw InvalidPartyName();
            }
            //here to put exception
            cur_party = *get_party_by_name(party_name);
            cur_party->set_head_of_party_name("None");
            cur_party->set_party_name("Has_No_Party");
            party_name="Has_No_Party";
            cur_party->notify_all_members_in_party();
            //notifies all deleted-party members as none and
            // if there's another party from same side it will update later in add-politician called by loop down
            std::vector<Party*>::iterator it;
            it = find(sort_by_size_vec.begin(), sort_by_size_vec.end(), cur_party);
            //disconnect party from sorted vector
            sort_by_size_vec.erase(it);
            //disconnected from original vector
            parties_vec.erase(get_party_by_name(party_name));
            //go over the memmbers vector of the deleted party
            //and find a party for every one.
            std::vector<Politician *> deleted_party_members = cur_party->get_members_vec();
            std::vector<Politician*>::iterator old_party_pols;
            for (old_party_pols = deleted_party_members.begin();old_party_pols!=deleted_party_members.end();++old_party_pols)
            {
                cur_party->remove_politician(*(*old_party_pols));
                Insert_Helper(*(*old_party_pols),-1);
            }
            delete(cur_party);
            break;
        }
        catch(exception& e)
        {
            cout<<e.what();
        }
    }

}

void PoliticalSys::elections()
{//primaries print
    if (no_parties()||no_politicians())return;
    int index=0;
    int max_power=-1;
    Party* max_party;

    std::cout<<"----Primaries----"<<std::endl;
    std::vector<Party*>::iterator it;
    for(it = parties_vec.begin();it!=parties_vec.end();++it)
    {
        (*it)->Primaries();
        std::cout<<(*it)->get_head_of_party_name()<<" is the chairman of "<<(*it)->get_party_name()<<std::endl;
    }
    std::cout<<"----Elections----"<<std::endl;
    for(it = parties_vec.begin();it!=parties_vec.end();++it)
    {
        std::cout<<"Party: "<<(*it)->get_party_name()<<",Power: "<<(*it)->get_political_power()<<std::endl;
        if(max_power<(*it)->get_political_power())
        {
            max_power=(*it)->get_political_power();
            max_party=(*it);
        }
    }
    if(max_power>-1)
    {
        std::cout<<"----Elections Results----"<<std::endl;
        std::cout<<max_party->get_party_name()<<" party won the elections and "<<max_party->get_head_of_party_name();
        std::cout<<" is the prime minister\n";
    }
}


//3 print functions:
//print all politicians
//print all parties
//print biggest party
void PoliticalSys::printPoliticians () const
{
    if (no_politicians())return;
    std::cout<<"----Politicians----"<<std::endl;
    std::vector<Politician*>::const_iterator it;
    for(it = politicians_vec.begin(); it!= politicians_vec.end();++it)
    {
        std::cout<<*(*it)<<std::endl;
    }
}
void PoliticalSys::printParties () const
{
    if (no_parties())return;
    std::cout<<"----Parties----"<<std::endl;
    std::vector<Party*>::const_iterator it;
    for(it = parties_vec.begin(); it!=parties_vec.end();++it)
    {
        std::cout<<*(*it)<<std::endl;
    }
}
void PoliticalSys::BiggestParty()const
{
    std::cout<<"----Biggest Party----"<<std::endl;
    if(sort_by_size_vec.empty())
    {//no parties handling
        std::cout<<"["<<"None"<<","<<"0"<<"]"<<std::endl;
    }
    else
        {
        std::cout << "[" << (*(sort_by_size_vec.end() - 1))->get_party_name() << ","
                  << (*(sort_by_size_vec.end() - 1))->get_size() << "]" << std::endl;
        }
}


//helper functions**

std::vector<Party*>::iterator PoliticalSys::get_party_by_name(const std::string& name)// helper for add party->erase from old party
{
    std::vector<Party *>::iterator it;
    for (it = parties_vec.begin(); it != parties_vec.end(); ++it)
    {
        if((*it)->get_party_name()==name)
            return it;
    }
return it;
}


std::vector<Politician*>::iterator PoliticalSys::get_pol_by_id(const int& id)//helper for Erase Politician from PolSys
{
    std::vector<Politician*>::iterator it;
    for (it = politicians_vec.begin(); it != politicians_vec.end(); ++it)
    {
        if((*it)->get_ID()==id)
            return it;
    }
    return it;
}


bool PoliticalSys::Comp_Functor(Party *a, Party *b)
{
    if(a== NULL || b== NULL){throw exception();}
    if(a->get_size()==b->get_size())
    {
        return (a->get_party_name()<b->get_party_name());
    }
return a->get_size()<b->get_size();
}


void PoliticalSys::Insert_Helper(Politician& pol, int cur_size)
{//helps find the current party for our politician
    bool first_in = true;
    Party* old_party;
    std::vector<Party*>::iterator it;
    // go over parties vector
    //the iteration will go over *all* the parties
    //at first it try to add the politicaian to every party
    //when the politician has a party , he will enter only if
    //the party have less memmbers.
    for(it = parties_vec.begin() ; it !=parties_vec.end();++it)
    {
        // go in if politican has_no_party
        if (first_in)
        {
            pol.insert_to_democratic_party(*(*it));
            pol.insert_to_republic_party(*(*it));
            if (pol.get_party_name()==(*it)->get_party_name())
            {
                cur_size=(*it)->get_size();
                old_party = *it;
                first_in = false;
            }
        }
        else
        {
            if (cur_size>(*it)->get_size())
            {
                pol.insert_to_democratic_party(*(*it));
                pol.insert_to_republic_party(*(*it));
                if (pol.get_party_name()==(*it)->get_party_name())
                {
                    cur_size=(*it)->get_size();
                    old_party->remove_politician(pol);
                    old_party = *it;
                }
            }
        }
    }
    try {
        std::sort(sort_by_size_vec.begin(), sort_by_size_vec.end(), Comp_Functor);
    }
    catch(...)
    {
        delete(this);
        terminate();
    }
}


void PoliticalSys::file_handling(const std::string& file_path)
{

    std::string line,word,f_name,l_name;
    int id,power;
    char type,side;
    std::string delimeter=" ";
    std::ifstream myfile (file_path.c_str());

    int pos=0;
    if(myfile.is_open())//check that path is exist
    {
        getline(myfile,line);//"Politicians" skip
        while (getline(myfile,line) && line!="Parties:\r")
        {//parties reading
            std::stringstream ss(line);
            getline(ss, f_name, ' ');
            getline(ss, l_name,' ');
            ss>>id;
            ss>>power;
            ss>>side;
            ss>>type;
            insert_politician_with_arguments(f_name,l_name,id,power,side,type);
        }
        while (getline(myfile,line))
        {//parties reading
            std::stringstream ss(line);
            getline(ss, f_name, ' ');//f_name here is party_name
            ss>>side;//party type
            insert_party_with_arguments(f_name,side);
        }
    }
    myfile.close();
}


PoliticalSys::~PoliticalSys() {
    std::vector<Party*>::iterator p;
    for (p = parties_vec.begin(); p!= parties_vec.end() ; ++p)
    {
        delete (*p);
    }
    std::vector<Politician*>::iterator pol;
    for (pol = politicians_vec.begin(); pol!= politicians_vec.end() ; ++pol)
    {
        delete *pol;
    }
    politicians_vec.clear();
    parties_vec.clear();
    sort_by_size_vec.clear();


}
#endif //ASS5_POLITICALSYS_H