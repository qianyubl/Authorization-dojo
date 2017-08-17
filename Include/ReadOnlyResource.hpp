#include "IResource.hpp"
#include <memory>

class ReadOnlyResource : public IResource
{
public:
    ReadOnlyResource(std::shared_ptr<IResource> p_resource)
        {m_resource = p_resource;}
    void read(){m_resource->read();}
    void write(){throw WriteForbidden();}
private:
    std::shared_ptr<IResource> m_resource;
};


class FullResource : public IResource
{
public:
    FullResource(std::shared_ptr<IResource> p_resource)
        {m_resource = p_resource;}
    void read(){m_resource->read();}
    void write(){m_resource->write();}
private:
    std::shared_ptr<IResource> m_resource;
};
