#include <iostream>
#include <vector>
#include <string>
#include <msgpack_easy.hpp>

int main()
{
#ifdef __cpp_rvalue_references
    std::vector<int> vec{ 1,2,3 };

    // 打包
    auto pack = msgpack::easy::pack(vec);

    // 解包
    auto v = msgpack::easy::unpack<std::vector<int>>(pack);

    for (auto&& i : v)
    {
        std::cout << i << std::endl;
    }
#else
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);

    // 打包
    std::string pack;
    msgpack::easy::pack(vec, pack);

    // 解包
    std::vector<int> v;
    msgpack::easy::unpack<std::vector<int>>(pack, v);

    for (size_t i = 0; i != v.size(); ++i)
    {
        std::cout << v[i] << std::endl;
    }
#endif // __cpp_rvalue_references
    return 0;
}
