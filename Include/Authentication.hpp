#pragma once

#include <string>
#include "Authorization.hpp"



class IAuthentication
{
public:
    virtual User login(const std::string& user, const std::string& name) = 0;
};

