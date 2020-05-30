#include <iostream>
#include "Class.h"
#include "Allocator.h"

int main()
{
    Allocator<char> allocator(10);
    char* array = new char[10];
    allocator.construct(array, 10);
    allocator.destroy(array);
    allocator.deallocate(array, 10);

    char* array2 = allocator.allocate(10);
    std::cout << allocator.size();
    allocator.deallocate(array2, 10);

    auto* a = new Class;
    delete a;

    auto* b = new Class[1000];
    delete[] b;

    auto *ptr = new char[sizeof(Class)];
    auto* c = new(ptr) Class;
    c->~Class();
    delete[] ptr;

    auto *ptr2 = new char[sizeof(Class)*1000];
    auto * d = new (ptr2) Class[1000];
    delete[] d;

    auto* e = new(std::nothrow) Class;
    delete e;

    auto* f = new(std::nothrow) Class[1000];
    delete[] f;
}