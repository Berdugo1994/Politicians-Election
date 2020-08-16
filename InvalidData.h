#ifndef ASS5_INVALIDDATA_H
#define ASS5_INVALIDDATA_H
#include <exception>

class InvalidData : public std::exception
{
    virtual const char* what() const throw()
    {
        return  "Please enter valid details\n";
    }
};


#endif //ASS5_INVALIDDATA_H
