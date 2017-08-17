#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "Authorization.hpp"
#include "AuthenticationMock.hpp"

using namespace ::testing;

struct AuthorizationTestSuit : public Test
{
    std::shared_ptr<User> reader = std::make_shared<User>(User{1,"user","123",EUserRole::E_READER, 1.1});
    std::shared_ptr<AuthenticationMock> authMock = std::make_shared<AuthenticationMock>();
    CAuthorizationServer authorization{authMock};
};

TEST_F(AuthorizationTestSuit, verifyTheFuctionLoginIsCalled)
{
    EXPECT_CALL(*authMock, login(reader->name,reader->passwd)).WillOnce(Return(reader));
    authorization.getPermission(reader->name,reader->passwd);
}

TEST_F(AuthorizationTestSuit, shouldThrowExceptionWhenUserNotExist)
{
    EXPECT_CALL(*authMock, login(reader->name,reader->passwd)).WillOnce(Return(nullptr));
    ASSERT_THROW(authorization.getPermission(reader->name,reader->passwd),InvalidUser);
}



