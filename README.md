# msgpack-c-easy

依賴[msgpack/msgpack-c](https://github.com/msgpack/msgpack-c)庫。
在msgpack::easy命名空間內引入：
```
template<typename T>
std::string pack(const T& t)

template<typename T>
T unpack(std::string str)

template<typename T>
T unpack(const char* data, size_t len)

template<typename T>
T unpack(const uint8_t* data, size_t len)
```