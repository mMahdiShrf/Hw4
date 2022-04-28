template <typename T>
UniquePtr<T>:: UniquePtr(T* ptr):
_p {ptr}
{}

template <typename T>
UniquePtr<T>:: UniquePtr():
UniquePtr(nullptr)
{}

template <typename T>
UniquePtr<T>::~UniquePtr()
{  
    delete _p;
    _p = nullptr; 
}

template<typename T>
T* UniquePtr<T>:: get()
{
    return _p;
}

template<typename T>
void UniquePtr<T>::reset(T* ptr)
{
    if (!ptr)
    {
        delete _p;
        _p = nullptr;
        _p = ptr;
    }
    else
    {
        delete _p;
        _p = ptr;
    }
}

template<typename T>
T* UniquePtr<T>::release()
{
    T* __p{_p};
    _p = nullptr;
    return __p;
}

template<typename T>
T* UniquePtr<T>::operator->()
{   
    return get();
}

template<typename T>
T UniquePtr<T>::operator*()
{
    return *_p;
}

template <typename T>
UniquePtr<T>  make_unique(T obj)
{
    return UniquePtr<T> {new T{obj}};
}





