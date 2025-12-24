/*-Задание №2 (копирование одного экземпляра в другой)-*/
#include <iostream>

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

  /*-явно перегружаем присваивание: -*/
  smartArray &operator=(const smartArray &other)
  {
    if (this != &other) // если этот массив не другой, то тогда...;
    {
      this->size = other.size;   // копируем размер из другого массива в этот;
      this->count = other.count; // копируем состояние счёта из другого массива в этот;

      delete[] this->array; // чистим память этого массива;

      this->array = new int[this->size];   // выделяем этому массиву новую память по новому размеру;
      for (int i = 0; i < this->size; ++i) // пробегаемся по массивам этому и другому;
      {
        this->array[i] = other.array[i]; // копируем каждый элемент из другого массива в этот;
      };
    };
    return *this; // возвращаем этот в любом случае;
  };

  int getElement(int index) // показываем элемент масс-ва;
  {
    if (index < this->size) // если индекс меньше длины, то...;
    {
      return this->array[index]; //...возвращаем элемент по индексу;
    };
    // throw std::exception();                              // иначе бросаем исключение;
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
    // throw std::exception();                                                           // иначе бросаем исключение;
    std::cout << "Massiv napolnen! Ne pomestilsya element: " << element << std::endl; // подстилаем соломку;
    return;                                                                           // если бы не было исключения;
  };

  void show() // показ массива
  {
    std::cout << "Massiv: ";
    for (int i = 0; i < this->size; ++i)
    {
      std::cout << this->array[i] << " ";
    };
    std::cout << std::endl;
  };

protected:
  int *array;
  int size;
  int count = 0;
};

int main()
{
  smartArray arr(5);
  arr.addElement(1);
  arr.addElement(4);
  arr.addElement(155);
  /*-немного отсебятинки: -*/
  arr.show(); // посмотрим массивчик

  smartArray new_array(2);
  new_array.addElement(44);
  new_array.addElement(34);
  /*-опять: -*/
  new_array.show(); // посмотрим массивчик;

  arr = new_array; // копируем один в другой;

  arr.show();       // смотрим один;
  new_array.show(); // смотрим другой;

  return 0;
}