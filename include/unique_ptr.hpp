template <typename T>
UniquePtr<T>:: UniquePtr(T* ptr):
_p {ptr}
{}

template <typename T>
UniquePtr<T>:: UniquePtr():
UniquePtr(nullptr)
{}



