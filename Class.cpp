//
// Created by trykr on 30.05.2020.
//

#include "Class.h"

void *Class::operator new(std::size_t size)
{
    void* ptr= std::malloc(size);
    if (!ptr)
        throw std::bad_alloc();
    else
        return ptr;
}

void Class::operator delete(void *ptr)
{
    std::free(ptr);
}

void *Class::operator new[](std::size_t size)
{
    void* ptr = std::malloc(size);
    if(!ptr)
        throw std::bad_alloc();
    else
        return ptr;
}

void Class::operator delete[](void *ptr)
{
    std::free(ptr);
}

void *Class::operator new(std::size_t size, void *ptr)
{
    return ptr;
}

void *Class::operator new[](std::size_t size, void *ptr)
{
    return ptr;
}

void *Class::operator new(std::size_t size, const std::nothrow_t &nth)
{
    return std::malloc(size);
}

void *Class::operator new[](std::size_t size, const std::nothrow_t &nth) {
    return std::malloc(size);
}
