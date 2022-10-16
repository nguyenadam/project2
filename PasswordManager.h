#include <string>

using namespace std;

class PasswordManager {
    public: 
        PasswordManager() : PasswordManager("", "") { } 
        void setUsername(string);
        void setEncryptedPassword(string);
        string getUsername() { return username; }
        string getEncryptedPassword() { return password; }
        void setNewPassword(string);
        bool authenticate(string);


    private: 
        string username;
        string password;

        string encrypt(string);
        bool meetsCritera();
    
};