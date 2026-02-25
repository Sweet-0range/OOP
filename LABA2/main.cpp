#include <iostream>
#include <windows.h>

class point2d                                                                   //Класс для работы с точкой в 2D
{
private:
    int x=0;
    int y=0;
    
public:
    point2d(int x, int y);
    point2d();                                                                  //конструктор без параметров
    point2d(const point2d &p);                                                  //конструктор копирования
    ~point2d();                                                                 //деструктор
    point2d& operator=(const point2d &p)                                        //перегрузка оператора присваивания
    {
        if (this == &p)
            return *this;
        x = p.x;
        y = p.y;
        std::cout << "Оператор присваивания 2d" << std::endl;
        return *this;
    }
    int GetX()                                                                  //Гетер для изменения значения X
    {
        return x;
    }
    int GetY()                                                                  //Гетер для изменения значения Y
    {  
        return y;
    }
    void SetX(int x)                                                            //Сетер для получения значения X
    {
        this->x = x;
    }
    void SetY(int y)                                                            //Сетер для получения значения Y
    {
        this->y = y;
    }
    void Print()                                                                //Метод для вывода значений
    {
        std::cout << "X: " << x << std::endl << "Y: " << y << std::endl;
    }
};

point2d::point2d(int x, int y) : x(x), y(y)                                     //Реализация конструктора с параметрами
{
    std::cout << "Конструктор с параметрами 2d" << std::endl;
}
point2d::point2d()                                                              //Реализация конструктора без параметров
{
    std::cout << "Конструктор по умолчанию 2d" << std::endl;
}
point2d::point2d(const point2d &p) : x(p.x), y(p.y)                             //Реализация конструктора копирования
{
    std::cout << "Конструктор копирования 2d" << std::endl;
}
point2d::~point2d()                                                             //Реализация деструктора
{
    std::cout << "Деструктор 2d" << std::endl;
}


void func()                                                                     //Функция для проверки работы деструкторов
{
    point2d p1(1, 2);                                                           //Создание объекта p1,p2 с помощью конструктора с параметрами
    point2d p2(3, 4);

    std::cout << "Вывод значений p1" << std::endl;
    p1.Print();
    std::cout << "Вывод значений p2" << std::endl;
    p2.Print();

    p2 = p1;

    std::cout << "Сеттеры p1, p2:" << std::endl;
    std::cout << "p1 X: " << p1.GetX() << " Y: " << p1.GetY() << std::endl;     //Демонстрация работы геттеров
    std::cout << "p2 X: " << p2.GetX() << " Y: " << p2.GetY() << std::endl;

    std::cout << "Используем Сетеры p1" << std::endl;
    p1.SetX(10);                                                                //Демонстрация работы сеттеров
    p1.SetY(20);
    p1.Print();

    std::cout << "Используем Сетеры p2" << std::endl;
    p2.SetX(30);
    p2.SetY(40);
    p2.Print();

    point2d p3(p1);                                                             //Создание объекта p3 с помощью конструктора копирования
    std::cout << "p3" << std::endl;
    p3.Print();
    

    point2d * p4 = new point2d(5, 6);                                        //Создание динамического объекта p4 c помощью конструктора с параметрами
    point2d * p5 = new point2d();                                            //Создание динамического объекта p5 с помощью конструктора без параметров 
    point2d * p6 = new point2d(*p4);                                         //Создание динамического объекта p5 с помощью конструктора копирования
    std::cout << "p4" << std::endl;
    p4->Print();
    std::cout << "p5" << std::endl;
    p5->Print();
    std::cout << "p6" << std::endl;
    p6->Print();
    delete p4;
    delete p5;                                                                  //Удаление динамических объектов
    delete p6;
}

int main() {
    SetConsoleOutputCP(CP_UTF8);                                                //Установка кодовки для Windows
    SetConsoleCP(CP_UTF8);
    
     func();                                                                    //Вызов функции для проверки работы классов и их методов

     std::cin.get();                                                            //Ожидание ввода для предотвращения закрытия консоли
    return 0;
}   