#include "Client.h"
#include <iostream>
#include <windows.h>
#include <string>


//#include "Book.h"
using namespace std;
Client::Client()
{
}

Client::~Client()
{
}

Client::Client(string _name, string _password)
{
    name = _name;
    password = _password;
}

string Client::getName()
{
    return name;
}

string Client::getPassword()
{
    return password;
}

void Client::setName(string _name)
{
    name = _name;
}

void Client::setPassword(string _password)
{
    password = _password;
}

bool Client::Login(string _name, string _password)
{
    if ((_name == name) && (_password == password))
    {
        cout << "Correct Login" << endl << endl;
        return 1;
    }
    else
    {
        system("CLS");
        cout << "Wrong Name or Password entered." << endl;
        return 0;
    }
}


void Client::Logout()
{
    return;
}