#pragma once
#include <gmock/gmock.h>
#include "Authentication.hpp"

class AuthenticationMock: public IAuthentication
{
public:
    MOCK_METHOD2(login, std::shared_ptr<User>(const std::string& user, const std::string& name));
};

