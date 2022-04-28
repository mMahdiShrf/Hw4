#ifndef SHARED_PTR
#define SHARED_PTR

#include <vector>

template <typename T>
class SharedPtr
{
public:
SharedPtr(T* ptr);
SharedPtr();
SharedPtr(SharedPtr<T>& obj); // copy constructor 
~SharedPtr();
SharedPtr& operator=(SharedPtr& obj); // copy version of operator=
T operator*();
T* operator->();
operator bool() {return (_p == nullptr) ? false : true;} // challenge part
int use_count();
T* get();
void reset(T* ptr=nullptr);



private:
T* _p; // store pointer
T** __p; //  a pointer to stored pointer
int* refrence; // number of SharedPtr with same pointer

};


#include"shared_ptr.hpp"
#endif //SHARED_PTR