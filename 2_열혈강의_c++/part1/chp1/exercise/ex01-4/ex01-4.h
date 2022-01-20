#ifndef EX01_4_H_
#define EX01_4_H_

namespace A
{
    void Test(void);
    void Hi(void);

    namespace AA
    {
        extern int sVal;
    }

    namespace BB
    {
        extern int sVal;
    }
}

namespace B
{
    void Test(void);
}

#endif