#include <iostream>

enum Food
{
    burger,
    gookbap,
    pasta
};

class Me
{
    private:
    int hungriness;
    double stressness;

    public:
    void Init(void);
    void eat(Food menu);
    void study(int time);
    void status(void);
    void rest(int time);
};


void Me::eat(Food menu)
{
    switch(menu)
    {
        case burger:
        hungriness -= 7;
        if(hungriness < 0) hungriness = 0;
        stressness *= 0.8;
        break;

        case gookbap:
        hungriness -= 5;
        if(hungriness < 0) hungriness = 0;
        stressness -= 0.7;
        break;

        case pasta:
        hungriness -= 3;
        if(hungriness < 0) hungriness = 0;
        stressness -= 0.6;
        break;
    }

    status();
}

void Me::study(int time)
{
    stressness += (1 + hungriness / 10) * time;
    hungriness += time;

    status();
}

void Me::status(void)
{
    using namespace std;
    
    cout << "Current State" << endl;
    cout << "-----------------------" << endl;
    cout << "Hungry : " << hungriness << endl;
    cout << "Stress : " << stressness << endl;
    cout << "-----------------------" << endl << endl;
}

void Me::rest(int time)
{
    for(int i = 0; i < time; i++)
        stressness *= 0.8;
}

void Me::Init(void)
{
    stressness = 30;
    hungriness = 0;
}

int main(void)
{
    Me jo;
    // Me * jo = new Me;
    // delete jo;

    jo.Init();

    jo.study(3);
    jo.eat(burger);
    jo.study(10);
    jo.rest(5);


    return 0;
}