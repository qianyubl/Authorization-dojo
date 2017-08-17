#pragma once
#include <gmock/gmock.h>
#include "IResource.hpp"

class ResourceMock: public IResource
{
public:
    MOCK_METHOD0(read, void());
    MOCK_METHOD0(write, void());
};

