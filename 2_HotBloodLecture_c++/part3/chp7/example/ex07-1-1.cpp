#include <iostream>

class Car
{
private:
    int gasolineGauge;
public:
    Car(int _gasolin)
        : gasolineGauge(_gasolin)
    {
        
    }
    int GetGasGauge()
    {
        return gasolineGauge;
    }
};

class HybridCar : public Car
{
private:
    int eletricGauge;
public:
    HybridCar(int _electric, int _gasoline)
        : eletricGauge(_electric), Car(_gasoline)
    {

    }
    int GetElecGauge()
    {
        return eletricGauge;
    }
};

class HybridWaterCar : public HybridCar
{
private:
    int waterGauge;
public:
    HybridWaterCar(int _water, int _electric, int _gasoline)
        : waterGauge(_water), HybridCar(_electric, _gasoline)
    {

    }
    void ShowCurrentGauge()
    {
        std::cout << "잔여 가솔린: " << GetGasGauge() << std::endl;
        std::cout << "잔여 전기량: " << GetElecGauge() << std::endl;
        std::cout << "잔여 워터량: " << waterGauge << std::endl;
    }
};

int main(void)
{
    HybridWaterCar myCar(10, 20, 30);
    myCar.ShowCurrentGauge();

    return 0; 
}