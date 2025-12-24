#include <iostream>
/*-Задание - 1 (умный массив типа RALL)-*/

class smartArray // класс;
{
public:                // публичные;
  smartArray(int size) // конструктор;
  {
    this->size = size;           // уст. размер;
    this->array = new int[size]; // динамич. массив по кол-ву эл-тов;
  };

  ~smartArray() // деструктор;
  {
    delete[] this->array; // очистка памяти;
  };

  int getElement(int index) // показываем элемент масс-ва;
  {
    if (index < this->size) // если индекс меньше длины, то...;
    {
      return this->array[index]; //...возвращаем элемент по индексу;
    };
    throw std::exception();                              // иначе бросаем исключение;
    std::cout << "net indexsa!: " << index << std::endl; // подстилаем соломку;
    return 0;                                            // это если бы использовалось без throw;
  };

  void addElement(int element) // добавляем элемент;
  {
    if (this->count < this->size) // если переменная счёта меньше размера, то...;
    {
      this->array[this->count] = element; //...заносим элемент;
      this->count++;                      // увеличиваем переменную на 1;
      return;                             // прерываем;
    }
    throw std::exception();                                                           // иначе бросаем исключение;
    std::cout << "Massiv napolnen! Ne pomestilsya element: " << element << std::endl; // подстилаем соломку;
    return;                                                                           // если бы не было исключения;
  };

protected:
  int *array;
  int size;
  int count = 0;
};

int main()
{
  try
  {
    smartArray arr(5);
    arr.addElement(1);
    arr.addElement(4);
    arr.addElement(155);
    arr.addElement(14);
    arr.addElement(15);
    std::cout << arr.getElement(1) << std::endl;
    std::cout << arr.getElement(5) << std::endl; // здесь выводим ошибку, послед. инд. 4, (всего эл-тов 5)
  }
  catch (const std::exception &ex)
  {
    std::cout << ex.what() << std::endl;
  };

  return 0;
}