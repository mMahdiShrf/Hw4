#ifndef UNIQUE_PTR
#define UNIQUE_PTR

template <typename T>
class UniquePtr
{
    public :
    UniquePtr(T* ptr);
    UniquePtr();
    UniquePtr(const UniquePtr<T>& obj)=delete; // delete for compile error
    ~UniquePtr();
    void reset(T* ptr=nullptr); // default value for reset with no input
    T* release();
    T* get();
    T* operator->();
    T operator*();
    UniquePtr& operator=(const UniquePtr& obj)=delete;
    operator bool(){return (_p == nullptr) ? false : true;} // challenge part
    
    private :

    T* _p;
};

#include "unique_ptr.hpp"








#endif //UNIQUE_PTR