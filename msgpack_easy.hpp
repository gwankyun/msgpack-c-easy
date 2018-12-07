#pragma once
#ifndef MSGPACK_EASY
#define MSGPACK_EASY
#include <string>
#include <sstream>
#include <utility>
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
			return std::move(msgpack::unpack(str.data(), str.size()).get().as<T>());
		}

		template<typename T>
		T unpack(const char* data, std::size_t len)
		{
			return std::move(msgpack::unpack(data, len).get().as<T>());
		}
		
		template<typename T>
		T unpack(const uint8_t* data, std::size_t len)
		{
			return std::move(msgpack::unpack(reinterpret_cast<const char*>(data), len).get().as<T>());
		}
	}
}
#endif // !MSGPACK_EASY
