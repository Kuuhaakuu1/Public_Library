#pragma once
#ifndef BOOK_H
#define BOOK_H
#include <iostream>
#include <string>

using namespace std;
class Book
{
public:
    string title;
    string author;
    string description;
    string numOfPages;

public:
    //default constructor
    Book(); 
    //destructor
    virtual ~Book();
    //constructor
    Book(string, string, string, int);
    //getters 
    string getTitle();
    string getAuthor();
    string getDescription();
    string getNumofPages();
    //setters
    void setTitle(string _title);
    void setAuthor(string _author);
    void setDescription(string _description);
    void setNumofPages(string _numOfPages);
    //display function
    void displayBook();
    void writeToFile(ofstream& fileOut);
    void readFromFile(ifstream& fileIn);
    void writeToFile(ofstream& fileOut, Book* items, int i);
    string borrowed;
    string returned;
    int sizeB = 0;
    
};


#endif // BOOK_H
