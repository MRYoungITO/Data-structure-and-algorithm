#include "Single.h"

Single::Single()
{
    name = "ÎÞÃû";
    age = 0;
}

Single::Single(int age, string name)
{
    this->age = age;
    this->name = name;
}

Single::~Single()
{

}

int Single::getAge() const
{
    return age;;
}

string Single::getName() const
{
    return name;
}
