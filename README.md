Authentication Authorization and Accounting

Authentication interface has this method
       login(const string& username, const string& password);
Accounting interface
       account(int userId)
Resource interface:
       read()
       write();
Role
       AUTHOR
       READER

Our purpose is to write an Authorization class to grant permission of read/write to users.
Author role can read/write 
Reader role only can read but need do account first. 

