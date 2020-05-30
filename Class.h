//
// Created by trykr on 30.05.2020.
//

#ifndef ALLOCATOR_CLASS_H
#define ALLOCATOR_CLASS_H
#include <memory>
class Class
{
public:
    void* operator new(std::size_t size);
    void operator delete(void* ptr);
    void* operator new[](std::size_t size);
    void operator delete[](void* ptr);
    void* operator new(std::size_t size, void* ptr);
    void* operator new[](std::size_t size, void* ptr);
    void* operator new(std::size_t size, const std::nothrow_t& nth);
    void* operator new[](std::size_t size, const std::nothrow_t& nth);

};
#endif //ALLOCATOR_CLASS_H
