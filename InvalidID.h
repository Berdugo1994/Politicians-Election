#ifndef ASS5_INVALIDID_H
#define ASS5_INVALIDID_H
#include <exception>

class InvalidID : public std::exception
{
virtual const char* what() const throw()
    {
        return  "Please enter valid id\n";
    }
};


#endif //ASS5_INVALIDID_H
