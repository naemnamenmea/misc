#include "auxiliary.hpp"

using namespace std;

namespace aux 
{
string_view& TrimFront(string_view& str, char delimiter)
{
	while (!str.empty() && str.front() == delimiter)
	{
		str.remove_prefix(1);
	}

	return str;
}

string_view& TrimBack(string_view& str, char delimiter)
{
	while (!str.empty() && str.back() == delimiter)
	{
		str.remove_suffix(1);
	}

	return str;
}

string_view& Trim(string_view& str, char delimiter)
{
	TrimFront(str, delimiter);
	TrimBack(str, delimiter);

	return str;
}

pair<string_view, optional<string_view>> SplitTwoStrict(string_view s, string_view delimiter) {
	const size_t pos = s.find(delimiter);
	if (pos == s.npos) {
		return { s, nullopt };
	}
	else {
		return { s.substr(0, pos), s.substr(pos + delimiter.length()) };
	}
}

pair<string_view, string_view> SplitTwo(string_view s, string_view delimiter) {
	const auto [lhs, rhs_opt] = SplitTwoStrict(s, delimiter);
	return { lhs, rhs_opt.value_or("") };
}

string_view ReadToken(string_view& s, string_view delimiter) {
	const auto [lhs, rhs] = SplitTwo(s, delimiter);
	s = rhs;
	return lhs;
}
}