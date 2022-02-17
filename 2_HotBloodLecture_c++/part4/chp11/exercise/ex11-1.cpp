#include <iostream>
#include <cstring>

using namespace std;

class Book
{
private:
    char* title;
    char* isbn;
    int price;
public:
    Book(char* _title, char* _isbn, int _price)
        :price(_price)
    {
        title = new char[strlen(_title) + 1];
        strcpy(title, _title);
        
        isbn = new char[strlen(_isbn) + 1];
        strcpy(isbn, _isbn);
    }
    ~Book()
    {
        delete[] title;
        delete[] isbn;
    }
    Book& operator=(const Book& ref)
    {
        delete[] title;
        title = new char[strlen(ref.title)];
        strcpy(title, ref.title);

        delete[] isbn;
        isbn = new char[strlen(ref.isbn)];
        strcpy(isbn, ref.isbn);

        price = ref.price;
        
        return *this;
    }
    void ShowBookInfo(void)
    {
        cout << "Title : " << title << endl;
        cout << "ISBN : " << isbn << endl;
        cout << "Price : " << price << endl;

    }
};

class EBook : public Book
{
private:
    char* DRMKey;
public:
    EBook(char* _title, char* _isbn, int _price, char* _DRMKey)
        :Book(_title, _isbn, _price)
    {
        DRMKey = new char[strlen(_DRMKey) + 1];
        strcpy(DRMKey, _DRMKey);
    }
    ~EBook(void)
    {
        delete[] DRMKey;
    }
    EBook& operator=(const EBook& ref)
    {
        Book::operator=(ref);
        delete[] DRMKey;
        DRMKey = new char[strlen(ref.DRMKey) + 1];
        strcpy(DRMKey, ref.DRMKey);
    }
    void ShowEBookInfo(void)
    {
        ShowBookInfo();
        cout << "DRM Key : " << DRMKey << endl;
    }
    
};

int main(void)
{
    EBook book1("Little Prince", "123456", 6000, "d83nv91u921");
    EBook book2("Test", "0000", 7777, "sample");

    book1.ShowEBookInfo();
    book2.ShowEBookInfo();
    cout << endl;

    book2 = book1;
    book1.ShowEBookInfo();
    book2.ShowEBookInfo();

    return 0;

}