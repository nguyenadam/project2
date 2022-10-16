#include <string>

using namespace std;

class PasswordManager {
    private: 
        string username;
        string password;

        string encrypt(string);
        bool meetsCritera();
    
    public: 
        PasswordManager() : PasswordManager() { 
            username = ""; 
            password = "";
        } 
        void setUsername(string);
        void setEncryptedPassword(string);
        string getUsername() { return username; }
        string getEncryptedPassword() { return password; }
        void setNewPassword(string);
        bool authenticate(string);


};