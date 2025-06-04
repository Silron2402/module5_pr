#include <iostream>
using namespace std;

// Объявление класса Car
class Car
{
private:
  // объявляем закрытые переменные класса
  // Торговая марка
  string brand_name;
  // Число цилиндров
  int cylinders;
  // Мощность, л.с.
  int power;

public:
  // конструктор по умолчанию
  Car()
  {
    brand_name = "Volga";
    cylinders = 4;
    power = 90;
  }

  // Конструктор с параметрами
  Car(string brand, int cyl_num = 4, int h_power = 40)
  {
    brand_name = brand;
    cylinders = cyl_num;
    power = h_power;
  }

  // Конструктор копирования
  Car(const Car &p)
  {
    brand_name = p.brand_name;
    cylinders = p.cylinders;
    power = p.power;
  }
  void print()
  {
    std::cout << "Brand:  " << brand_name << "\tCylinders: " << cylinders << "\tPower: " << power << std::endl;
  }
  // Определим деструктор класса
  ~Car()
  {
    std::cout << "Destruction" << std::endl;
  }
  
  string getBrand_name() { return brand_name; }
  int getCylinders() { return cylinders; }
  int getPower() { return power; }
};

int main()
{
  std::cout << "Start program" << std::endl;

  Car gaz{};
  gaz.print();
  Car vaz("vaz", 4, 40);
  vaz.print();
  /*  Fraction drob1;
    std::cout<< drob1.getNumerator() << "/" << drob1.getDenominator() << std::endl;

    Fraction drob2{5, 2};
    std::cout<< drob2.getNumerator() << "/" << drob2.getDenominator() << std::endl;*/

  return 0;
}