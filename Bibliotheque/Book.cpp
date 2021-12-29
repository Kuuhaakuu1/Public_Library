#include "Book.h"
#include <iostream>
#include <fstream>
#include <string>


using namespace std;

Book::Book()
{
}
//destructor
Book::~Book()
{
}

Book::Book(string _title, string _author, string _description, int _numOfpages)
{
    title = _title;
    author = _author;
    description = _description;
    numOfPages = _numOfpages;
    borrowed = "No";
    returned = "No";
    return;
}
//setters
void Book::setTitle(string _title)
{
    title = _title;
}

void Book::setAuthor(string _author)
{
    author = _author;
}

void Book::setDescription(string _description)
{
    description = _description;
}

void Book::setNumofPages(string _numOfPages)
{
    numOfPages = _numOfPages;
}
//getters
string Book::getTitle()
{
    return title;
}

string Book::getAuthor()
{
    return author;
}

string Book::getDescription()
{
    return description;
}

string Book::getNumofPages()
{
    return numOfPages;
}
//display
void Book::displayBook()
{
    cout << "Title: " << title << endl;
    cout << "Author: " << author << endl;
    cout << "Description: " << description << endl;
    cout << "Number of Pages: " << numOfPages << endl;
}
void Book::writeToFile(ofstream& fileOut)
{
    string temptitle;
    string tempauth;
    string tempdesc;
    string numOfPages;
    cout << " Title : " << endl;
    cin >> temptitle;
    cout << " Author : " << endl;
    cin >> tempauth;
    cout << " Description (keep it short) : " << endl;
    cin >> tempdesc;
    cout << " number of pager : " << endl;
    cin >> numOfPages;
    fileOut << temptitle << " ";
    fileOut << tempauth << " ";
    fileOut << tempdesc << " ";
    fileOut << numOfPages << " ";
}
void Book::readFromFile(ifstream& fileIn)
{
    fileIn >> title;
    fileIn >> author;
    fileIn >> description;
    fileIn >> numOfPages;
}
void Book::writeToFile(ofstream& fileOut,Book *items, int i)
{
    fileOut << items[i].title << " ";
    fileOut << items[i].author << " ";
    fileOut << items[i].description << " ";
    fileOut << items[i].numOfPages << " ";
}