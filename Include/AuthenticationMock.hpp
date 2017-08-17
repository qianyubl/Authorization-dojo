#pragma once
#include <gmock/gmock.h>
#include "Authentication.hpp"

class AuthenticationMock: public IAuthentication
{
public:
    MOCK_METHOD2(login, User(const std::string& user, const std::string& name));
};

