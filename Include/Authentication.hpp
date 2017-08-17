#pragma once

#include <string>
#include "Authorization.hpp"
#include <memory>



class IAuthentication
{
public:
    virtual std::shared_ptr<User> login(const std::string& user, const std::string& name) = 0;
};

