
template<typename T>
SharedPtr<T>::SharedPtr(T* ptr): // assign initializer values
_p{ptr},
__p{&_p},
refrence{new int{1}}
{}


template<typename T>
SharedPtr<T>::SharedPtr(): SharedPtr(nullptr) {*refrence -= 1;}

template<typename T>
SharedPtr<T>::~SharedPtr() 
{
    *refrence -= 1; // decrease refrence
    if (*refrence == 0 )
        delete _p; // make Shared pointer safe to use
    *__p = nullptr; // assign nullptr to _p by it's pointer
}

template<typename T>
SharedPtr<T>::SharedPtr(SharedPtr<T>& obj) // copy constructor 
{   
    _p = obj._p;
    __p = obj.__p;
    *obj.refrence = *(obj.refrence) + 1; // because of this statment input can't be const
    refrence = obj.refrence;  // new Shared Pointer has to have same refrence with obj
}   

template<typename T>
SharedPtr<T>& SharedPtr<T>::operator=(SharedPtr<T>& obj)
{   
    if(obj._p == _p ) 
        return *this;
    _p = obj._p;
    refrence = obj.refrence;
    *refrence += 1; 
    return *this;

}

template<typename T>
int SharedPtr<T>:: use_count()
{
    return *refrence;
}

template<typename T>
T* SharedPtr<T>:: get()
{
    return _p;
}

template<typename T>
T SharedPtr<T>::operator*()
{
    return *_p;
}

template<typename T>
T* SharedPtr<T>::operator->()
{   
    return get();
}

template<typename T>
void SharedPtr<T>::reset(T* ptr)
{
    if(*refrence == 1)
        delete _p; // safe delete of Shared Pointer
    *refrence -= 1;
    refrence = new int {}; // new refrence for changed pointer
    if (ptr)
        *refrence += 1; 
    _p = ptr;
    
}

template <typename T>
SharedPtr<T>  make_shared(T obj)
{
    return SharedPtr<T> {new T{obj}};
}