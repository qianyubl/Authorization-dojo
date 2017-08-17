#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "Authorization.hpp"
#include "AuthenticationMock.hpp"
#include "ResourceMock.hpp"

using namespace ::testing;

struct AuthorizationTestSuit : public Test
{
    std::shared_ptr<User> reader = std::make_shared<User>(User{1,"user","123",EUserRole::E_READER, 1.1});
    std::shared_ptr<StrictMock<AuthenticationMock>> authMock = std::make_shared<StrictMock<AuthenticationMock>>();
    std::shared_ptr<ResourceMock> ResouMock = std::make_shared<ResourceMock>();
    CAuthorizationServer authorization{authMock, ResouMock};
};

TEST_F(AuthorizationTestSuit, shouldThrowExceptionWhenUserNotExist)
{
    EXPECT_CALL(*authMock, login(reader->name,reader->passwd)).WillOnce(Return(nullptr));
    ASSERT_THROW(authorization.getPermission(reader->name,reader->passwd),InvalidUser);
}

TEST_F(AuthorizationTestSuit, shouldHaveReadPermissionForAReaderUser)
{
    EXPECT_CALL(*authMock, login(reader->name,reader->passwd)).WillOnce(Return(reader));
    EXPECT_CALL(*ResouMock, read());
    ASSERT_EQ(E_READ, authorization.getPermission(reader->name,reader->passwd));
}


