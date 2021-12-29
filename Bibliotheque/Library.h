#pragma once
#ifndef LIBRARY_H
#define LIBRARY_H
#include "Login.h"
#include "Book.h"
#include <vector>
#include <fstream>
class Library : public Book
{
public:
    Library();
    virtual ~Library();
    void AddBook();
    void DeleteBook(string);//works
    void ModifyBookName(string, string);
    void ModifyBookAuth(string, string);
    void ModifyBookDesc(string, string);
    void uploadBooks();
    void ClientMenu();
    void LibrarianMenu();
    void searchBook(string);
    Book books[20];
    int _size = 1;
};

#endif // LIBRARY_H