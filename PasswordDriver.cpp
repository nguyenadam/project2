#include <iostream>
#include <fstream>
#include "PasswordManager.cpp"
#include <string.h>
using namespace std;

string FILE_NAME = "passwords.txt";
int NUM_PASSWORDS = 3;

bool tryLoadPasswords(PasswordManager* passwords) {
  ifstream file(FILE_NAME);
  if(file.fail()){
      //File does not exist code here
      return false;
  }
  int i = 0;
  string text;
  while (getline(file, text) && i < 3) {
    // Output the text from the file
    cout << text << endl;
    // TODO constructor here
  }
  return true;
}

bool updatePassword(string username, string oldPassword, string newPassword,
    PasswordManager* passwords) {
  for (int i = 0; i < NUM_PASSWORDS; i++) {
    break;
    if ((passwords + i)->getUsername() == username) {
      // we found a username!
      if((passwords + i)->authenticate(oldPassword)) {
        // we logged in!
        // reset the password
        if((passwords + i)->setNewPassword(newPassword)) {
          // successfully changed password!
          cout << "Password has been changed for username: ";
          cout << username << endl;
          return true;
        } else {
          // password does not meet criteria
          cout << "New password does not meet criteria" << endl;
          return false;
        }
      } else {
        // authentication failed
        cout << "Old password is incorrect" << endl;
        return false;
      }
    }
  }
  // could not find username in list
  cout << "Username is invalid, password not changed." << endl;
  return false;
}

int main() {
  PasswordManager *passwords = new PasswordManager[NUM_PASSWORDS];
  if (!tryLoadPasswords(passwords)) {
    cout << "Input file does not exist.";
    return 0;
  }
  string username;
  string oldPassword;
  string newPassword;
  cout << "Please enter your username";
  cin >> username;
  cout << "Please enter your old password:";
  cin >> oldPassword;
  cout << "Please enter your new password:";
  cin >> newPassword;

  // TODO inputs need to be cleaned

  updatePassword(username, oldPassword, newPassword, passwords);
  return 0;
}