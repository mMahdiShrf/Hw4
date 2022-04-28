#ifndef SHARED_PTR
#define SHARED_PTR

#include <vector>

template <typename T>
class SharedPtr
{
public:
SharedPtr(T* ptr);
SharedPtr();
SharedPtr(SharedPtr<T>& obj);
~SharedPtr();
SharedPtr& operator=(SharedPtr& obj);
T operator*();
T* operator->();
operator bool() {return (_p == nullptr) ? false : true;}
int use_count();
T* get();
void reset(T* ptr=nullptr);



private:
T* _p;
T** __p;
int* refrence;

};


#include"shared_ptr.hpp"
#endif //SHARED_PTR