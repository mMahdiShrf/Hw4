
template<typename T>
SharedPtr<T>::SharedPtr(T* ptr): 
_p{ptr},
__p{&_p},
refrence{new int{1}}
{}


template<typename T>
SharedPtr<T>::SharedPtr(): SharedPtr(nullptr)
{
    *refrence -= 1;
}

template<typename T>
SharedPtr<T>::~SharedPtr() 
{
    *refrence -= 1;
    if (*refrence == 0 )
        delete _p;
    *__p = nullptr;
}

template<typename T>
SharedPtr<T>::SharedPtr(SharedPtr<T>& obj)
{   
    _p = obj._p;
    __p = obj.__p;
    *obj.refrence = *(obj.refrence) + 1;
    refrence = obj.refrence;
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
