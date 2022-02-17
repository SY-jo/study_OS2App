#include <iostream>
#include <cstring>

//요구사항
//1.문자열을 입력으로 받는 Constructor
//2.동적할당으로 Constructor, Destrcutor, Copy Constructor, Assignment operator
//3.+
//4.+=
//5.==
//6.<<, >>


class myString
{
private:
    char* string;
    int length;
public:
    myString(char* _str) : length(strlen(_str))
    {
        string = new char[length+1];
        strcpy(string, _str);
    }
    myString(void) : string(nullptr), length(0) { }
    myString(const myString& ref) : length(ref.length)
    {
        string = new char[length+1];
        strcpy(string, ref.string);
    }
    ~myString(void)
    {
        delete[] string;
    }

    myString& operator=(const myString& ref)
    {
        delete[] string;
        length = ref.length;
        string = new char[length+1];
        strcpy(string, ref.string);
    }
    myString& operator+(const myString& ref) const
    {
        char* sum = new char[length + ref.GetLength()];
        strcpy(sum, string);
        strcat(sum, ref.string); // 이거 별도로 Getter 필요한거 아닌가?
        myString* result = new myString(sum);
        delete sum;
        return *result;
    }
    myString& operator+=(const myString& ref)
    {
        char* sum = new char[length + ref.GetLength()];
        strcpy(sum, string);
        strcat(sum, ref.string); // 이거 별도로 Getter 필요한거 아닌가?

        delete[] string;
        string = sum;
        length = strlen(string);

        return *this;        
    }
    bool operator==(const myString& ref) const
    {
        int result = strcmp(string, ref.string);
        return (result == 0) ? true : false;
    }

    friend std::ostream& operator<<(std::ostream&, const myString&);
    friend std::istream& operator>>(std::istream&, myString&);

    int GetLength(void) const
    {
        return length;
    }
    void Show(void) const
    {
        std::cout << string << std::endl;
    }
};

std::ostream& operator<<(std::ostream& os, const myString& ref)
{
    os << ref.string;

    return os;

}
std::istream& operator>>(std::istream& is, myString& ref)
{
    char str[100];
    is >> str;
    ref.length = strlen(str);
    delete[] ref.string;
    ref.string = new char[ref.length];
    strcpy(ref.string, str);

    return is;
}

int main(void)
{
    myString str1("Hello ");
    myString str2 = "World";

    str1.Show();
    str2.Show();

    myString str3 = str1 + str2;
    str3.Show();
    str3 += str1;
    str3.Show();

    if(str1 == str1)
        std::cout << "Same String!" << std::endl;
    else
        std::cout << "Different String!" << std::endl;

    myString str4;
    std::cout << "Type string : ";
    std::cin >> str4;
    std::cout << str4 << std::endl;

    myString str5;

    return 0;
}