#include <iostream>
#include <string>
#include "ArrayList.h"

int main()
{
    ArrayList<std::string> strAr;
    std::cout << strAr.isEmpty() << std::endl;
    strAr.add("hello");
    strAr.add("world");
    strAr.add("!");
    strAr.add("everyone");
    std::cout << strAr.toString() << std::endl;
    std::cout << strAr.size() << " " << strAr.capacity() << std::endl;
    std::cout << strAr.isEmpty() << std::endl;
    std::cout << strAr.contains("hi") << std::endl;
    try
    {
        std::cout << strAr.get(3) << std::endl;
    }catch(char const* error)
    {
        std::cout << error << std::endl;
    }

    try
    {
        strAr.set(1, "everyone");
        std::cout << strAr.toString() << std::endl;
    }catch(char const* error)
    {
        std::cout << error << std::endl;
    }
    std::cout << strAr.lastIndexOf("everyone") << std::endl;
    strAr.add(1, "hello");
    std::cout << strAr.toString() << std::endl;
    ArrayList<std::string> strAr2(strAr);
    std::cout << strAr2.toString() << std::endl;
    std::cout << strAr.equals(strAr2) << std::endl;
}
