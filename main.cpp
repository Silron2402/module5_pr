#include <iostream>
using namespace std;

// Объявление класса Car
class Car
{
private:
  //static int n_obj;
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
    cnt();
  }

  // Конструктор с параметрами
  Car(string brand, int cyl_num = 4, int h_power = 40)
  {
    brand_name = brand;
    cylinders = cyl_num;
    power = h_power;
    cnt();
  }

  // Конструктор копирования
  Car(const Car &p)
  {
    brand_name = p.brand_name;
    cylinders = p.cylinders;
    power = p.power;
    cnt();
  }

  // Определим деструктор класса
  ~Car()
  {
    std::cout << "Destruction" << std::endl;
  }

  // Методы - сеттеры
  void setBrand_name(string brand) { brand_name = brand; }
  void setCylinders(int cyl) { cylinders = cyl; }
  void setPower(int pwr) { power = pwr; }

  // Методы - геттеры
  string getBrand_name() const { return brand_name; }
  int getCylinders() const { return cylinders; }
  int getPower() const { return power; }

  // перегрузка операции вывода
  friend std::ostream &operator<<(std::ostream &out, const Car &property);

  // перегрузка операции ввода
  friend std::istream &operator>>(std::istream &in, Car &property);

  // Перегрузка оператора присваивания
  Car &operator=(const Car &parameters)
  {
    // проверка самоприсваивания
    if (this != &parameters)
    {
      // Выполняем пользовательское присваивание
      brand_name = parameters.brand_name;
      cylinders = parameters.cylinders;
      power = parameters.power;
    }
    return *this;
  }

  friend int cnt(); 
  
  void print()
  {
    std::cout << "Brand:  " << getBrand_name() << std::endl;
    std::cout << "Cylinders: " << getCylinders() << std::endl;
    std::cout << "Power: " << getPower() << std::endl;
  }
};

// Функция, реализующая перегрузку операции вывода
std::ostream &operator<<(std::ostream &out, const Car &property)
{
  out << "brand: " << property.brand_name << "\tcylinders: " << property.cylinders << "\tpower: " << property.power << std::endl;
  return out;
}

// Функция, реализующая перегрузку операции ввода
std::istream &operator>>(std::istream &in, Car &property)
{
  std::cout << "Enter brand name" << std::endl;
  in >> property.brand_name;
  std::cout << "number of cylinders" << std::endl;
  in >> property.cylinders;
  std::cout << "Enter power" << std::endl;
  in >> property.power;

  return in;
}
//функция-счетчике вызовов классов 
int cnt() 
  {
    //переменная,хранящая число выводов класса
    static int n_obj = 0;
    //увеличение на 1
    n_obj++;
    //вывод результата
    std::cout << "call #" << n_obj << std::endl;
    return n_obj;  
  }

// Создадим производный класс Lorry
class Lorry : public Car
{
private:
  // Грузоподъемность
  int capacity;

public:
  Lorry(void) : Car()
  {
    capacity = 0;
  }

  Lorry(string br, int cyl, int hp, int G) : Car(br, cyl, hp)
  {
    capacity = G;
  }

  // Метод сеттер
  void Lorry::setCapacity(int cap) { capacity = cap; }

  // Метод - геттер
  int getCapacity() const { return capacity; }

  void print()
  {
    // std::cout << "Brand:  " << getBrand_name() << "\tCylinders: " << getCylinders() <<
    //"\tPower: " << getPower() << "\tCapacity: " << getCapacity() << std::endl;
    std::cout << "Brand:  " << getBrand_name() << std::endl;
    std::cout << "Cylinders: " << getCylinders() << std::endl;
    std::cout << "Power: " << getPower() << std::endl;
    std::cout << "Capacity: " << getCapacity() << std::endl;
  }
  ~Lorry()
  {
    std::cout << "Destruction Lorry" << std::endl;
  }
};

int main()
{
  std::cout << "Start program" << std::endl;

  // протестируем создание класса по умолчанию
  Car gaz{};
  // выведем результаты с помощью метода print
  gaz.print();


  // протестируем перегруженный оператор вывода
  std::cout << gaz << std::endl;

  // протестируем создание класса c параметрами
  Car vaz("vaz", 4, 40);
  vaz.print();

  // проверим работу оператора ввода и создадим новый класс new_car
  Car new_car;
  std::cout << "Enter car parameters" << std::endl;
  // протестируем перегруженный оператор ввода
  std::cin >> new_car;
  // протестируем перегруженный оператор вывода
  std::cout << new_car << std::endl;

  // протестируем оператор присваивания. Для этого присвоим значения класса new_car
  // классу gaz и выведем результаты
  std::cout << "Contents of the gaz class BEFORE the operation of the overloaded assignment operator" << std::endl;
  std::cout << gaz << std::endl;
  gaz = new_car;
  std::cout << "Contents of the gaz class AFTER the operation of the overloaded assignment operator" << std::endl;
  std::cout << gaz << std::endl;

  //Создание дочернего класса Lorry
  Lorry gazel("gazel", 4, 90, 5);
  gazel.print();

  return 0;
}