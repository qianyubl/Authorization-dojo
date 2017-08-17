#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "Authorization.hpp"
#include "AuthenticationMock.hpp"

using namespace ::testing;

TEST(AuthorizationTestSuit, verifyTheFuctionLogin)
{
    User u = {1,"user","123",EUserRole::E_READER, 1.1};
    auto subObj = std::make_shared<AuthenticationMock>();
    CAuthorizationServer authorization(subObj);
    EXPECT_CALL(*subObj, login(_,_)).WillOnce(Return(u));
    //ASSERT_THROW(authorization.getPermission("user","password"), InvalidUser);
    authorization.getPermission("user","password");
}


