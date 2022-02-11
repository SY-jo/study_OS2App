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
    ~Book(void)
    {
        delete[] title;
        delete[] isbn;
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
    void ShowEBookInfo(void)
    {
        ShowBookInfo();
        cout << "DRM Key : " << DRMKey << endl;
    }
    
};

int main(void)
{
    EBook myEbook("Little Prince", "123456", 6000, "d83nv91u921");
    myEbook.ShowBookInfo();
    cout << endl;
    myEbook.ShowEBookInfo();

    return 0;

}