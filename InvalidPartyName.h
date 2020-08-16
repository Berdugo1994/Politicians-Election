#ifndef ASS5_INVALIDPARTYNAME_H
#define ASS5_INVALIDPARTYNAME_H
#include <exception>

class InvalidPartyName : public std::exception
{
    virtual const char* what() const throw()
    {
        return  "Please enter valid name\n";
    }

};

#endif //ASS5_INVALIDPARTYNAME_H
