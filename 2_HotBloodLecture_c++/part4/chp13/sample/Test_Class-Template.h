#ifndef _TEST_CLASS_TEMPLATE_H
#define _TEST_CLASS_TEMPLATE_H

class myClass1
{
private:
    int mem;
public:
    myClass1(int _mem);
    int GetMem(void);
};

template <typename T>
class myClass2
{
private:
    T mem;
public:
    myClass2(T _mem);
    T GetMem(void);
};

#endif