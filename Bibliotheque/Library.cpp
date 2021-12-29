#include "Library.h"
#include "Book.h"
#include "Login.h"
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

Library::Library()
{
}

Library::~Library()
{
}
void Library::AddBook()
{
    const int N = 20;
    int num, total;
    Book items[N];
    ofstream fileOut;
    fileOut.open("Library.txt", ios::app);
    cout << "how many books do you want to add ?" << endl;
    cin >> num;
        int max = sizeB + 1 + num;
        for (int i=sizeB+1 ; i < max; ++i)
        {
            items[i].writeToFile(fileOut);
            sizeB++;
        }
    system("CLS");
    return;
}

//=============================================
void Library::uploadBooks()
{
    const int N = 20;
    int num, total;
    Book items[N];
    ifstream fileIn;
    fileIn.open("Library.txt");
    for (int i = 0; i < N; ++i)
        items[i].readFromFile(fileIn);
    fileIn.close();
    
    cout << "title" << '\t' << '\t' << "author" << '\t' << '\t' << "description" << '\t' << "numOfPages" << endl;
    cout << "------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < N; ++i)
    {
        cout << items[i].title << '\t' << '\t';
        cout << items[i].author << '\t' << '\t' ;
        cout << items[i].description << '\t' << '\t';
        cout << items[i].numOfPages << endl;
    }
}

//===================================================

void Library::DeleteBook(string _title)
{
    const int N = 20;
    Book items[N];
    ifstream fileIn;
    fileIn.open("Library.txt");
    for (int i = 0; i < N; ++i)
        items[i].readFromFile(fileIn);
    fileIn.close();
    for (int i = 0; i < N; i++)
    {
        if (items[i].title == _title)
        {
            for (int j = i; j < N-1; j++)
            {               
                items[j] = items[j + 1];
                
            }
            system("CLS");
            cout << "delete success" << endl;;
            ofstream fileOut;
            fileOut.open("LibraryT.txt", ios::out);
            for (int i = 0; i < N; i++)
            {
                items[i].writeToFile(fileOut, items, i);
            }
            remove("Library.txt");
            fileOut.close();
            int result;
            char oldname[] = "LibraryT.txt";
            char newname[] = "Library.txt";
            result = rename(oldname, newname);
            if (result == 0)
                return;
            else
                perror("Error renaming file");
            return;

        }
    }
    cout << "No Book Found. ";
    return;
}
//===============================================
void Library::ModifyBookName(string _title, string val)
{
    const int N = 20;
    Book items[N];
    ifstream fileIn;
    fileIn.open("Library.txt");
    for (int i = 0; i < N; ++i)
        items[i].readFromFile(fileIn);
    fileIn.close();
    for (int i = 0; i < N; i++)
    {
        if (items[i].title == _title)
        {
            items[i].title = val;
            system("CLS");
            ofstream fileOut;
            fileOut.open("LibraryT.txt", ios::out);
            for (int i = 0; i < N; i++)
            {
                items[i].writeToFile(fileOut, items, i);
            }
            remove("Library.txt");
            fileOut.close();
            int result;
            char oldname[] = "LibraryT.txt";
            char newname[] = "Library.txt";
            result = rename(oldname, newname);
            if (result == 0)
                cout << "modification success" << endl;
                
            else
                perror("Error renaming file");
            return;
        }
        system("pause");

    }

}
//==================
void Library::ModifyBookAuth(string _title, string val)
{
    const int N = 20;
    Book items[N];
    ifstream fileIn;
    fileIn.open("Library.txt");
    for (int i = 0; i < N; ++i)
        items[i].readFromFile(fileIn);
    fileIn.close();
    for (int i = 0; i < N; i++)
    {
        if (items[i].title == _title)
        {
            items[i].author = val;
            system("CLS");
            ofstream fileOut;
            fileOut.open("LibraryT.txt", ios::out);
            for (int i = 0; i < N; i++)
            {
                items[i].writeToFile(fileOut, items, i);
            }
            remove("Library.txt");
            fileOut.close();
            int result;
            char oldname[] = "LibraryT.txt";
            char newname[] = "Library.txt";
            result = rename(oldname, newname);
            if (result == 0)
                cout << "modification success" << endl;

            else
                perror("Error renaming file");
            return;
        }
        system("pause");

    }
}
//==================
void Library::ModifyBookDesc(string _title, string val)
{
    const int N = 20;
    Book items[N];
    ifstream fileIn;
    fileIn.open("Library.txt");
    for (int i = 0; i < N; ++i)
        items[i].readFromFile(fileIn);
    fileIn.close();
    for (int i = 0; i < N; i++)
    {
        if (items[i].title == _title)
        {
            items[i].description = val;
            system("CLS");
            ofstream fileOut;
            fileOut.open("LibraryT.txt", ios::out);
            for (int i = 0; i < N; i++)
            {
                items[i].writeToFile(fileOut, items, i);
            }
            remove("Library.txt");
            fileOut.close();
            int result;
            char oldname[] = "LibraryT.txt";
            char newname[] = "Library.txt";
            result = rename(oldname, newname);
            if (result == 0)
                cout << "modification success" << endl;

            else
                perror("Error renaming file");
            return;
        }
        system("pause");

    }

}

//===================================================
void Library::searchBook(string val)
{
    const int N = 20;
    Book items[N];
    ifstream fileIn;
    fileIn.open("Library.txt");
    for (int i = 0; i < N; ++i)
        items[i].readFromFile(fileIn);
    fileIn.close();
    for (int i = 0; i < N; i++)
    {
        if ((val == items[i].getTitle()) || (val == items[i].getAuthor()) || (val == items[i].getDescription()))   // displays all books that match criteria
        {
            cout << "Book Found. " << endl << endl;
            items[i].displayBook();
            return;
        }
        else
        {
            cout << "Book not Found";
            return;
        }
    }
}
//===================================================
//===================================================

void Library::ClientMenu()     // Client start menu before doing anything
{   
    int opt1;
    cout << "1. Sign up       " << "2. Login    " << " 3. Exit " << endl;
    cin >> opt1;
    int option;
    Login login;
    bool Blog;
    if (opt1 == 1) {
        login.Signup();
    }
    else if (opt1 == 2) {
        while (true) {
            Blog = login.Signin();
            if (Blog == 1) {
                break;
            }
        }
    }
    //===================================  Menu Starts
    system("CLS");

    while (true)
    {

        cout << "\n";
        cout << "1. Examine Library       " << "2. Search for a Book    " << " 3. Exit " << endl;
        cin >> option;

        if (option == 1)
        {
            uploadBooks();
            system("pause");
            system("CLS");
        }
        else if (option == 2)
        {
            system("CLS");
            string val;
            cout << " Enter Anything to search for: " << endl;
            cin >> val;
            searchBook(val);
        }
        else
        {
            login.Logout();
            return;

        }

    }
}




//=============================================   Librarian Options

void Library::LibrarianMenu()
{
    while (true)
    {
        int option;
        cout << "1. Add a Book       " << "2. Delete a Book     " << "3. Modify a Book" << "       4. Show All Books" << "       5. Logout" << endl << endl;
        cin >> option;
        if (option == 1)

        {
            system("CLS");
            AddBook();
        }
        else if (option == 2)
        {
            system("CLS");
            string delbook;
            cout << "\n";
            cout << "  Choose a book to delete" << endl;
            cin >> delbook;

            DeleteBook(delbook);
        }

        else if (option == 3)
        {
            system("CLS");
            string bktitle;
            string newVal;
            int opt4;

            cout << endl;
            cout << "Enter the title of the book to modify: " << endl << endl;
            cin >> bktitle;
            cout << "Enter what property you want to edit:      1. Title       or      2. Author     or       3. Description  " << endl;
            cin >> opt4;

            if (opt4 == 1)
            {
                cout << "Enter New Title: " << endl;
                cin >> newVal;
                ModifyBookName(bktitle, newVal);

            }
            else if (opt4 == 2)
            {
                cout << "Enter New Author: " << endl;
                cin >> newVal;
                ModifyBookAuth(bktitle, newVal);

            }
            else if (opt4 == 3)
            {
                cout << "Enter New Description: " << endl;
                cin >> newVal;
                ModifyBookDesc(bktitle, newVal);
            }

        }
        else if (option == 4)
        {
            uploadBooks();
            system("pause");
            system("CLS");
        }
        else if (option == 5)
        {
            system("CLS");
            return;
        }
    }
}
