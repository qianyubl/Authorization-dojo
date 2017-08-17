#pragma once

#include <stdexcept>
#include <string>
#include <vector>
#include <memory>
#include "IResource.hpp"

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
    CAuthorizationServer(std::shared_ptr<IAuthentication> p_Authentication,
                             std::shared_ptr<IResource> p_Resource )
    {
        m_Authentication = p_Authentication;
        m_Resource = p_Resource;
    }
    ~CAuthorizationServer() = default;

     EUserPermission getPermission(const std::string name,
                                 const std::string passwd);
     void startUserTask(const std::shared_ptr<User> p_User);

private:
    std::vector<User> m_userTable;
    std::shared_ptr<IAuthentication> m_Authentication;
    std::shared_ptr<IResource> m_Resource;
};













