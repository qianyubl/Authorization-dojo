#include "Authorization.hpp"
#include "Authentication.hpp"
#include "ReadOnlyResource.hpp"

EUserPermission CAuthorizationServer::getPermission(const  std::string name,const std :: string passwd)
{
    auto user = m_Authentication->login(name,passwd);
    if(nullptr == user)
    {
        throw InvalidUser();
    }

    if (E_READER == user->role)
    {
        return E_READONLY;
    }
    return E_WRITE8READ;
}

std::shared_ptr<IResource> CAuthorizationServer::getResource(const std::string name,
                            const std::string passwd)
{
    EUserPermission l_permission = getPermission(name,passwd);
    if (E_READONLY == l_permission)
    {
        m_Resource = std::make_shared<ReadOnlyResource>(m_Resource);
    }
    else if (E_WRITE8READ== l_permission)
    {
        m_Resource = std::make_shared<FullResource>(m_Resource);
    }
    return m_Resource;
}


