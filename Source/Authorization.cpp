#include "Authorization.hpp"
#include "Authentication.hpp"

Permission CAuthorizationServer::getPermission(const  std::string name,const std :: string passwd)
{
    auto user = m_Authentication->login(name,passwd);
    if(nullptr == user)
    {
        throw InvalidUser();
    }

    return Permission();
}

