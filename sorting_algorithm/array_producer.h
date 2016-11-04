#pragma once

#include <vector>
#include <string>

class ArrayProducer
{
	using Array = std::vector<int>;
	using Size = Array::size_type;
public:
	static Array CreateSequenceArray(const Size& size, int origin, int delta);
	static Array CreateRepeatArray(const Size& size, const std::string& str);
	static Array CreateUniformDistrubutionArray(const Size& size, int min, int max);
	static Array CreateNormalDistrubutionArray(const Size& size, int mean, int standard_deviation);

};