#ifndef PASSWORDMANAGER_H
#define PASSWORDMANAGER_H
#include <string>

using namespace std;

class PasswordManager 
{
    private: 
        string username;
        string password;
        string encrypt(string s);
        bool meetsCritera();
    public: 
        void setUsername(string s);
        void setEncryptedPassword(string s);
        string getUsername() { return username; }
        string getEncryptedPassword() { return password; }
        bool setNewPassword(string s);
        bool authenticate(string s);

};
#endif
