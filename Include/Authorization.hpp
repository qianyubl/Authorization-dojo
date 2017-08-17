#pragma once

#include <stdexcept>
#include <string>
#include <vector>
#include <memory>

//#include "Authentication.hpp"

class IAuthentication;

class InvalidUser : std::logic_error
{
public:
    InvalidUser() : std::logic_error("InvalidUser")
        {}
};


enum EUserRole
{
    E_READER,
    E_AUTHOR
};

enum EUserPermission
{
    E_READ = 1,
    E_WRITE = 2
};

struct User
{
   int id;
   std::string name;
   std::string passwd;
   EUserRole role;
   double account;
};

class CAuthorizationServer
{
public:
    CAuthorizationServer(std::shared_ptr<IAuthentication> p_Authentication)
    {
        m_Authentication = p_Authentication;
    }
    ~CAuthorizationServer() = default;

     EUserPermission getPermission(const std::string name,
                                 const std::string passwd);

private:
    std::vector<User> m_userTable;
    std::shared_ptr<IAuthentication> m_Authentication;
};













