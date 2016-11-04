#include "array_producer.h"
#include <random>
#include <ctime>

using Array = std::vector<int>;
using Size = Array::size_type;

ArrayProducer::Array ArrayProducer::CreateSequenceArray(const Size & size, int origin, int delta)
{
	Array ret;
	ret.reserve(size * 1.5);
	for (auto i = 0; i != size; ++i)
	{
		ret.push_back(origin);
		origin += delta;
	}
	return ret;
}

Array ArrayProducer::CreateRepeatArray(const Size & size, const std::string & str)
{
	Array ret;
	ret.reserve(size * 1.5);
	for (auto i = 0; i != size; ++i)
	{
		int index = i % str.size();
		int num = static_cast<int>(str[index]) - 48;
		ret.push_back(num);
	}
	return ret;
}

Array ArrayProducer::CreateUniformDistrubutionArray(const Size & size, int min, int max)
{
	Array ret;
	ret.reserve(size * 1.5);
	static std::default_random_engine e(static_cast<int>(time(nullptr)));
	static std::uniform_int<int> u(min, max);
	for (auto i = 0; i != size; ++i)
		ret.push_back(u(e));

	return ret;
}

Array ArrayProducer::CreateNormalDistrubutionArray(const Size & size, int mean, int standard_deviation)
{
	Array ret;
	ret.reserve(size * 1.5);
	static std::default_random_engine e(static_cast<int>(time(nullptr)));
	static std::normal_distribution<double> u(mean, standard_deviation);
	for (auto i = 0; i != size; ++i)
	{
		int num = std::lround(u(e));
		ret.push_back(num);
	}
	return ret;
}
