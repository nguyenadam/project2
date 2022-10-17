#include <cstdlib>
#include "PasswordManager.h"

using namespace std;

void PasswordManager::setUsername(string s) {
    username = s;
}

void PasswordManager::setEncryptedPassword(string s) {
    password = s;
}

string PasswordManager::encrypt(string password) {
    char *encryptedPassword = new char[password.length()];
    for (int i = 0; i < password.length(); i ++) {
        encryptedPassword[i] = (password[i] - 33 + 25) % 94 + 33;
    }
    return encryptedPassword;
}

bool PasswordManager::setNewPassword(string s) {
    if (meetsCriteria(s)) {
        password = encrypt(s);
        return true;
    }
    return false;
}

bool PasswordManager::authenticate(string input) {
    string encryptedInput = encrypt(input);
    if (encryptedInput == getEncryptedPassword()) {
        return true;
    }
    return false;
}

bool PasswordManager::meetsCriteria(string s) {
    bool hasUppercase = false;
    bool hasLowerCase = false;
    bool hasDigit = false;
    if (s.length() < 8) {
        return false;
    }
    for (int i = 0; i < s.length(); i ++) {
        if (isupper(s[i])) {
            hasUppercase = true;
        } else if (islower(s[i])) {
            hasLowerCase = true;
        } else if (isdigit(s[i])) {
            hasDigit = true;
        }
    }
    if (hasUppercase && hasLowerCase && hasDigit) {
        return true;
    }
    return false;
}



