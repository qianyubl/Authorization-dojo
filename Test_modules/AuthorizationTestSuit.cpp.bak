#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "ILoginMock.hpp"
#include "IResourceMock.hpp"
#include "IAcoutingMock.hpp"
#include "Authorization.hpp"
#include "Role.hpp"
#include <iostream>
using namespace ::testing;
using namespace ::std;

class AuthorizationTestSuit: public Test
{
public:
    StrictMock<ILoginMock> m_loginMock;
    StrictMock<IResourceMock> m_resourceMock;	
    StrictMock<IAcountingMock> m_acoutingMock;	
		string username = std::string("liming");
		string password = std::string("123");
		User UserAuthor{1, Role::AUTHOR};
		User UserReader{2, Role::READER};
};

TEST_F(AuthorizationTestSuit, initializeAuthorization)
{ 
	  Authorization(m_loginMock, m_resourceMock, m_acoutingMock);
}

TEST_F(AuthorizationTestSuit, authorLogin)
{ 
	  Authorization auth(m_loginMock, m_resourceMock, m_acoutingMock);
	  EXPECT_CALL(m_loginMock,login(username, password)).WillOnce(Return(UserAuthor));
	  auth.login(username, password);
}

TEST_F(AuthorizationTestSuit, readPermission)
{ 
	  Authorization auth(m_loginMock, m_resourceMock, m_acoutingMock);
	  EXPECT_CALL(m_loginMock,login(username, password)).WillOnce(Return(UserAuthor));
	  auth.login(username, password);
	  
	  EXPECT_CALL(m_acoutingMock, IsVIPMember(UserAuthor.m_userId)).WillOnce(Return(true));
	  EXPECT_CALL(m_resourceMock, read());
	  ASSERT_NO_THROW(auth.read());
}

TEST_F(AuthorizationTestSuit, writePermission)
{ 
	  Authorization auth(m_loginMock, m_resourceMock, m_acoutingMock);
	  EXPECT_CALL(m_loginMock,login(username, password)).WillOnce(Return(UserAuthor));
	  auth.login(username, password);
	  EXPECT_CALL(m_resourceMock, write());
	  ASSERT_NO_THROW(auth.write());
}

TEST_F(AuthorizationTestSuit, writeNotPermission)
{ 
	  Authorization auth(m_loginMock, m_resourceMock, m_acoutingMock);
	  EXPECT_CALL(m_loginMock,login(username, password)).WillOnce(Return(UserReader));
	  auth.login(username, password);
	  ASSERT_THROW(auth.write(), NoPermissionException);
}

TEST_F(AuthorizationTestSuit, noPermissiontoReadWithoutLogin)
{ 
	  Authorization auth(m_loginMock, m_resourceMock, m_acoutingMock);
	  //EXPECT_CALL(m_loginMock,login(username, password)).WillOnce(Return(UserReader));
	  //auth.login(username, password);
	  
	  ASSERT_THROW(auth.read(), NoLoginException);
}

TEST_F(AuthorizationTestSuit, readPermissionForReviewer)
{ 
	  Authorization auth(m_loginMock, m_resourceMock, m_acoutingMock);
	  EXPECT_CALL(m_loginMock,login(username, password)).WillOnce(Return(UserReader));
	  auth.login(username, password);
	  EXPECT_CALL(m_acoutingMock, IsVIPMember(UserReader.m_userId)).WillOnce(Return(true));
	  EXPECT_CALL(m_resourceMock, read());
	  ASSERT_NO_THROW(auth.read());
}
