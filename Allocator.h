#pragma once

#include <stdexcept>
template <typename ValueType>
class Allocator {
private:

    std::size_t _size;
public:
    ValueType size() const;

    Allocator(std::size_t size);

    ValueType* allocate(std::size_t size) const;

    void deallocate(ValueType* ptr, std::size_t size) const;

    template< typename... Args >
    void construct(ValueType* ptr, const Args&... args) const;

    void destroy(ValueType* ptr) const;

};

template<typename ValueType>
ValueType Allocator<ValueType>::size() const {
        return sizeof(ValueType);
}

template<typename ValueType>
Allocator<ValueType>::Allocator(std::size_t size)
{
    this->_size = size;
}

template<typename ValueType>
ValueType *Allocator<ValueType>::allocate(std::size_t size) const {
    if (size > this->_size)
    {
        throw std::bad_alloc();
    }
    else{
        return new ValueType[size];
    }
}

template<typename ValueType>
void Allocator<ValueType>::deallocate(ValueType *ptr, std::size_t size) const
{
    delete[] ptr;
}

template<typename ValueType>
template<typename... Args>
void Allocator<ValueType>::construct(ValueType *ptr, const Args &... args) const
{
    new(ptr) ValueType(args...);
}

template<typename ValueType>
void Allocator<ValueType>::destroy(ValueType *ptr) const
{
    ptr->~ValueType();
}

