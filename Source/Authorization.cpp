#include "Authorization.hpp"
#include "Authentication.hpp"

EUserPermission CAuthorizationServer::getPermission(const  std::string name,const std :: string passwd)
{
    auto user = m_Authentication->login(name,passwd);
    if(nullptr == user)
    {
        throw InvalidUser();
    }

    if (E_READER == user->role)
    {
        return E_READ;
    }
    return E_WRITE;
}

