#pragma once

#include <iostream>

using namespace std;

#define DEBUG(...) debug(std::cout, #__VA_ARGS__, __VA_ARGS__)

#ifdef SOME_VALUE
template<typename H1>
std::ostream& debug(std::ostream& out, const char* label, H1&& value) {
	return out << label << " = " << std::forward<H1>(value) << '\n';
}

template<typename H1, typename ...T>
std::ostream& debug(std::ostream& out, const char* label, H1&& value, T&& ... rest) {
	const char* pcomma = strchr(label, ',');
	return debug(out.write(label, pcomma - label) << " = "
		<< std::forward<H1>(value)
		<< ',',
		pcomma + 1,
		std::forward<T>(rest)...);
}
#else
void debug() {}

template <typename T, typename... Args>
void debug(T a, Args... args) {
	cerr << a << endl;
	debug(args...);
}
#endif
