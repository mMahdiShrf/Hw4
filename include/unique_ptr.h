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

    private :
    T* _p;
};









#endif //UNIQUE_PTR