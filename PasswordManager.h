#ifndef PASSWORDMANAGER_H
#define PASSWORDMANAGER_H
#include <string>

using namespace std;

class PasswordManager 
{
    private: 
        string username;
        string password;
        string encrypt(string);
        bool meetsCriteria(string);
    public: 
        void setUsername(string);
        void setEncryptedPassword(string);
        string getUsername() { return username; }
        string getEncryptedPassword() { return password; }
        bool setNewPassword(string);
        bool authenticate(string);

};
#endif
