# msgpack-c-easy

依賴[msgpack/msgpack-c](https://github.com/msgpack/msgpack-c)庫，不要求C++編譯器，C++98及C++11用法皆可。
```C++
#include <iostream>
#include <vector>
#include <string>
#include <msgpack_easy.hpp>

int main()
{
	std::vector<int> vec{ 1,2,3 };

	auto pack = msgpack::easy::pack(vec);

	auto v = msgpack::easy::unpack<std::vector<int>>(pack);
	
	for (auto&& i : v)
	{
		std::cout << i << std::endl;
	}

	return 0;
}
```