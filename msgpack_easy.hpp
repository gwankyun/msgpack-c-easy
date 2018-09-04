#pragma once
#ifndef MSGPACK_EASY
#define MSGPACK_EASY
#include <string>
#include <sstream>
#include <msgpack.hpp>

namespace msgpack
{
	namespace easy
	{
		template<typename T>
		std::string pack(const T& t)
		{
			using namespace std;
			stringstream buffer;
			msgpack::pack(buffer, t);
			buffer.seekg(0);
			return string(buffer.str());
		}

		template<typename T>
		T unpack(std::string str)
		{
			return msgpack::unpack(str.data(), str.size()).get().as<T>();
		}

		template<typename T>
		T unpack(const char* data, size_t len)
		{
			return msgpack::unpack(data, len).get().as<T>();
		}
	}
}
#endif // !MSGPACK_EASY
