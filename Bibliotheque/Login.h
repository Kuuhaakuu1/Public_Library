#pragma once
#ifndef LOGIN_H
#define LOGIN_H
#include <iostream>
#include <string>

using namespace std;
class Login
{
public:
    string user;
    string pswd;

public:
    //default constructor
    Login();
    //destructor
    virtual ~Login();
    //constructor
    Login(string, string);
    //getters 
    void writeToFile(ofstream& fileOut);
    void readFromFile(ifstream& fileIn);
    void writeToFile(ofstream& fileOut, Login* items, int i);
    void Signup();
    bool Signin();
    void Logout();
    int sizeL = 0;
};


#endif // LOGIN_H
