#ifndef UNIQUE_PTR
#define UNIQUE_PTR

template <typename T>
class UniquePtr
{
    public :
    UniquePtr(T* ptr);
    UniquePtr();
    UniquePtr(const UniquePtr<T>& obj)=delete;    
    ~UniquePtr();
    void reset(T* ptr=nullptr);
    T* release();
    T* get();
    T* operator->();
    T operator*();
    UniquePtr& operator=(const UniquePtr& obj)=delete;
    operator bool(){return (_p == nullptr) ? false : true;}
    private :
    T* _p;
};

#include "unique_ptr.hpp"








#endif //UNIQUE_PTR