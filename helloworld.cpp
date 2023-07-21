#include <iostream>
#include <vector>
#include <limits>
#include <cmath>
#include <map>
#include <memory>
#include "coordinate.h"

using std::string;

/**
 * 0 helloworld
 * 1 cin
 * 2 gougu
 * 3 string
 * 4 object
 * 5 template function
 * 6 map
 * 7 pointer
 * 8 cout overload
 * 9 lambda
 * 10 smart pointer
*/

#define EXECING 5

namespace Moon {
    const double GRAVITY = 1.6;
    string name = "moon";
}

class Student {
public:
    std::string name;
    int age;
    Student() {}
    Student(std::string name, int age) {
        this->name = name;
        this->age = age;
    }

    void sayHello() {
        std::cout << "Hello, my name is " << name << ", I'm " << age << " years old." << std::endl;
    }
};

#if EXECING == 5
template <typename T, typename U>
inline constexpr auto t_max(T t, U u) {
    return t > u ? t : u;
}

template <typename T>
std::enable_if_t<std::is_same_v<T, int> || std::is_same_v<T, double>, std::string> t_toString(T t) {
    return std::to_string(t);
}

template <typename T>
std::string t_toString2(T t) {
    if constexpr (std::is_same_v<T, int> || std::is_same_v<T, double>) {
        return std::to_string(t);
    } else {
        return "not int or double";
    }
}
#endif

typedef std::vector<std::pair<std::string, int>> pairlist_t;
typedef std::string text_t;

using number_t = int;

number_t main() {
#if EXECING == 0
    std::cout << "I like pizza." << std::endl;
    std::cout << "It's really good!" << std::endl;

    bool isPizzaDelicious = true;
    std::cout << "Is pizza delicious? " << isPizzaDelicious << std::endl;

    text_t name = "tianyi";
    std::cout << "My name is " << name << std::endl;

    const double PI = 3.1415926535;
    double radius = 5.0;
    std::cout << "Circumference is " << radius * 2 * PI << std::endl;
    std::cout << "Area is " << radius * radius * PI << std::endl;

    const double GRAVITY = 9.8;

    std::cout << "Gravity on the earth is " << GRAVITY << std::endl;
    std::cout << "Gravity on the moon is " << Moon::GRAVITY << std::endl;

    pairlist_t pairlist;
    pairlist.push_back(std::make_pair("tianyi", 1));
    pairlist.push_back(std::make_pair("tianyi", 2));
    std::cout << pairlist.size() << std::endl;
#endif

#if EXECING == 1
    string yourName;
    string yourFullName;
    std::cout << "What's your first name? " << std::endl;
    std::cin >> yourName;
    // std::cin.ignore(32767, '\n'); // 加上这个就不会出问题，否则会直接跳过下面的getline, 下面一句也一样解决问题
    // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "What's your full name? " << std::endl;
    // std::getline(std::cin, yourFullName); // 这句会出问题，因为上面的cin留下了一个换行符，所以这里直接读取了一个空行
    // std::ws是跳过空白符，否则会直接跳过下面的getline, 和上面注释的两句一样解决问题
    std::getline(std::cin >> std::ws, yourFullName);
    std::cout << "Hello, " << yourName << "! Now I know your full name is " << yourFullName << "." << std::endl;
#endif

    /*
    math
    double x = 3;
    double y = 4;
    double z;

    z = std::max(x, y);
    z = std::min(x, y);
    z = pow(x, y);
    z = sqrt(x);
    z = abs(x);
    z = round(x);
    z = ceil(x);
    z = floor(x);
    */

#if EXECING == 2
    double a, b, c;
    for (int i = 0; i < 2; i ++) {
        std::cout << "Please input a: " << std::endl;
        std::cin >> a;
        std::cout << "Please input b: " << std::endl;
        std::cin >> b;
        std::cout << "c is " << sqrt(pow(a, 2) + pow(b, 2)) << std::endl;
    }
#endif

#if EXECING == 3
    std::string str = "hello";
    std::cout << str << std::endl;
    str.append(" world");
    std::cout << str << std::endl;
    str.insert(0, "hi ");
    std::cout << str << std::endl;
    str.erase(0, 3);
    std::cout << str << std::endl;
    str.replace(0, 2, "hello");
    std::cout << str << std::endl;
    str.pop_back();
    std::cout << str << std::endl;
    str.find("hello");
    std::cout << str << std::endl;

    std::string str2 = "Hello, World!";
    std::string searchStr = "World";
    std::string charset = "aeiou";

    size_t pos1 = str2.find(searchStr);
    if (pos1 != std::string::npos) {
        std::cout << "Found at position: " << pos1 << std::endl;
    } else {
        std::cout << "Not found." << std::endl;
    }

    size_t pos2 = str2.find_first_of(charset);
    if (pos2 != std::string::npos) {
        std::cout << "Found at position: " << pos2 << std::endl;
    } else {
        std::cout << "Not found." << std::endl;
    }

    size_t pos3 = str2.find_first_not_of(charset);
    if (pos3 != std::string::npos) {
        std::cout << "Found at position: " << pos3 << std::endl;
    } else {
        std::cout << "Not found." << std::endl;
    }
#endif

#if EXECING == 4
    Student student1("tianyi", 18);
    student1.sayHello();

    Student* student2 = new Student("yin", 18);
    student2->sayHello();

    Student student3 = student1;
    student3.name = "yoon";
    student3.sayHello();

    std::cout << &student1 << std::endl;
    std::cout << &student3 << std::endl;

    Student* student4 = student2;
    student4->name = "yaa";
    student4->sayHello();
    student2->sayHello();

    std::cout << student2 << std::endl;
    std::cout << student4 << std::endl;
    delete student2;
    delete student4;
#endif

#if EXECING == 5
    std::cout << t_max(1, 2) << std::endl;
    std::cout << t_max(1.5, 2) << std::endl;
    std::cout << t_max(1, 2.3) << std::endl;
    std::cout << t_max("abc", "dev") << std::endl;

    std::cout << t_toString(3.1415926535) << std::endl;
    std::cout << t_toString2("abc") << std::endl;
#endif

#if EXECING == 6
    std::map<std::string, int> users;
    users["tianyi"] = 21;
    users.insert(std::make_pair("yin", 18));
    users.insert({"yoon", 18});
    users.insert({"yoon", 18});

    std::cout << users["yin"] << std::endl;
    std::cout << users.size() << std::endl;
    std::cout << users.count("yoon") << std::endl;
#endif

#if EXECING == 7
    int nums[] = {1, 2, 3, 4, 5};
    int* p = nums;
    for (int i = 0; i < 5; i ++) {
        std::cout << *p << std::endl;
        p ++; // 指针加一，指向下一个元素, 指针加一的时候，指针的类型决定了加一的大小, 比如int*加一就是加四
    }

    std::string names[] = {"tianyi", "yin", "yoon"};
    std::string* p2 = names;
    for (int i = 0; i < 3; i ++) {
        std::cout << *p2 << std::endl;
        p2 ++;
    }

    struct point {
        int x;
        int y;
    };
    point poi;
    poi.x = 1;
    point* poiptr = &poi;
    poiptr->y = 2;
    std::cout << poi.x << " " << poi.y << std::endl;
    delete poiptr;
#endif

#if EXECING == 8
    Coordinate coord(1, 2, 3);
    std::cout << coord << std::endl;
#endif

#if EXECING == 9
    auto sum_numbers = [](auto a, auto b) -> auto {
        return a + b;
    };

    std::cout << sum_numbers(1, 2.3) << std::endl;

#endif

#if EXECING == 10
    int iage = 20;
    std::string strName = "tianyi";
    std::unique_ptr<std::string> strptr = std::make_unique<std::string>(strName);
    std::cout << typeid(iage).name() << std::endl;
    std::cout << typeid(strName).name() << std::endl;
    decltype(iage) ageType;
    decltype(strName) nameType;
    decltype(strptr) ptrType;
    std::cout << typeid(ageType).name() << std::endl;
    std::cout << typeid(nameType).name() << std::endl;
    std::cout << typeid(ptrType).name()  << std::endl;

#endif
    return 0;
}
