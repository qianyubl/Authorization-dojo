#include "Authorization.hpp"
#include "Authentication.hpp"

Permission CAuthorizationServer::getPermission(const  std::string name,const std :: string passwd)
{
    m_Authentication->login(name,passwd);

    return Permission();
}

