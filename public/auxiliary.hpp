#pragma once

#include <string_view>
#include <string>
#include <stdexcept>
#include <optional>
#include <sstream>
#include <charconv>

namespace aux
{
std::string_view& TrimFront(std::string_view& str, char delimiter = ' ');

std::string_view& TrimBack(std::string_view& str, char delimiter = ' ');

std::string_view& Trim(std::string_view& str, char delimiter = ' ');


std::pair<std::string_view, std::optional<std::string_view>> SplitTwoStrict(std::string_view s, std::string_view delimiter = " ");

std::pair<std::string_view, std::string_view> SplitTwo(std::string_view s, std::string_view delimiter = " ");

std::string_view ReadToken(std::string_view& s, std::string_view delimiter = " ");

template <typename Number>
Number ReadNumberOnLine(std::istream& stream) {
	Number number;
	stream >> number;
	std::string dummy;
	std::getline(stream, dummy);
	return number;
}

template<typename T>
T ConvertToNumber(std::string_view str) {
	const char* last = str.data() + str.size();
	T result{};
	auto [pos, ec] {from_chars(str.data(), last, result)};

	if (ec == std::errc() && pos != last)
	{
		std::stringstream error;
		error << "string \"" << str << "\" contains " << (last - pos) << " trailing chars";
		throw std::invalid_argument(error.str());
	}
	else if (ec == std::errc::invalid_argument)
	{
		std::stringstream error;
		error << "string \"" << str << "\" isn't a number";
		throw std::invalid_argument(error.str());
	}
	else if (ec == std::errc::result_out_of_range)
	{
		std::stringstream error;
		error << "string \"" << std::string_view(str.data(), pos - str.data()) << "\" is larger than an " << typeid(T).name();
		throw std::invalid_argument(error.str());
	}

	return result;
}

template <typename Number>
void ValidateBounds(Number number_to_check, Number min_value, Number max_value) {
	if (min_value > max_value) std::swap(min_value, max_value);
	if (number_to_check < min_value || number_to_check > max_value) {
		std::stringstream error;
		error << number_to_check << " is out of [" << min_value << ", " << max_value << "]";
		throw std::out_of_range(error.str());
	}
}
}