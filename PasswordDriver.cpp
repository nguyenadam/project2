#include <iostream>
#include <fstream>
#include <PasswordManager.cpp>
#include <string.h>
using namespace std;

string FILE_NAME = "passwords.txt";

bool try_load_passwords(PasswordManager* passwords) {
  ifstream file(FILE_NAME);
  if(file.fail()){
      //File does not exist code here
      return false;
  }
  int i = 0;
  string text;
  while (getline(file, text) && i < 3) {
    // Output the text from the file
    cout << text;
  }


}

int main() {
  PasswordManager *passwords = new PasswordManager[3];
  try_load_passwords(passwords);
  cout << "Hello World!";
  return 0;
}