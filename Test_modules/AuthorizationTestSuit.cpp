#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "Authorization.hpp"
#include "AuthenticationMock.hpp"

using namespace ::testing;

TEST(AuthorizationTestSuit, verifyTheFuctionLogin)
{
    auto u = std::make_shared<User>(User{1,"user","123",EUserRole::E_READER, 1.1});
    auto subObj = std::make_shared<AuthenticationMock>();
    CAuthorizationServer authorization(subObj);
    EXPECT_CALL(*subObj, login(_,_)).WillOnce(Return(u));
    authorization.getPermission("user","password");
}

