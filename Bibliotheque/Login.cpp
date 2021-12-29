#include "Login.h"
#include <iostream>
#include <fstream>
#include <string>


using namespace std;

Login::Login()
{
}
//destructor
Login::~Login()
{
}
Login::Login(string _username, string _password)
{
    user = _username;
    pswd = _password;
}
void Login::writeToFile(ofstream& fileOut)
{
    string tempuser;
    string temppswd;
    string temppswd2 = "_Null";
    while (temppswd != temppswd2) {
        cout << " Enter a Username : " << endl;
        cin >> tempuser;
        cout << " Enter a Password : " << endl;
        cin >> temppswd;
        cout << "Comfirm Password : " << endl;
        cin >> temppswd2;
        if (temppswd == temppswd2) {
            fileOut << tempuser << " ";
            fileOut << temppswd << " ";
        }
        else {
            cout << "incorrect password, please repeat" << endl;
        }
    }
}
void Login::readFromFile(ifstream& fileIn)
{
    fileIn >> user;
    fileIn >> pswd;
}
void Login::writeToFile(ofstream& fileOut, Login* items, int i)
{
    fileOut << items[i].user << " ";
    fileOut << items[i].pswd << " ";
}
void Login::Signup()
{
    const int N = 20;
    int total;
    Login cred[N];
    ofstream fileOut;
    fileOut.open("Login.txt", ios::app);
    int max = sizeL + 2;
    for (int i = sizeL + 1; i < max; ++i)
    {
        cred[i].writeToFile(fileOut);
        sizeL++;
    }
    fileOut.close();
}
bool Login::Signin()
{
    const int N = 20;
    Login cred[N];
    ifstream fileIn;
    fileIn.open("Login.txt");
    for (int i = 0; i < N; ++i)
        cred[i].readFromFile(fileIn);
    fileIn.close();
    string username;
    string password;
        cout << "                                 Enter Login Information:" << endl << endl;
        cout << "Name: ";
        cin >> username;
        cout << "\n";
        cout << "Password: ";
        cin >> password;
        cout << "\n";
        for (int i = 0; i < N; i++)
        {
            if ((cred[i].user == username) && (cred[i].pswd == password))
            {
                return 1;
            }
        }
        cout << "Password or username is incorrect please try again";
        system("pause");
        return 0;
}
void Login::Logout()
{
    return;
}
