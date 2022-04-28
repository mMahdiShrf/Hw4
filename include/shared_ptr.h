#ifndef SHARED_PTR
#define SHARED_PTR

#include <vector>

template <typename T>
class SharedPtr
{
public:
SharedPtr(T* ptr);
SharedPtr();
~SharedPtr();
SharedPtr(SharedPtr<T>& obj);
SharedPtr& operator=(SharedPtr& obj);
int use_count();
T* get();
T operator*();
T* operator->();
void reset(T* ptr=nullptr);
operator bool() {return (_p == nullptr) ? false : true;}


private:
T* _p;
T** __p;
int* refrence;

};


#include"shared_ptr.hpp"
#endif //SHARED_PTR