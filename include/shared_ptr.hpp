
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
