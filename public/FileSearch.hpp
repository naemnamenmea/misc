#pragma once

#include <sstream>
#include <string>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <iterator>
#include <memory>
#include <fstream>
#include <map>
#include <functional>
#include <set>
#include <iostream>
#include <iomanip>
#include <unordered_map>
#include <codecvt>
#include <locale>
#include <regex>
#include <dirent.h>
#include <experimental/filesystem>



typedef std::vector<std::string> vString;

namespace fs = std::experimental::filesystem;

typedef unsigned int ui;


class SearchEngine {
public:
	static std::string getPathFromInput(std::string input);
};




std::string dirnameOf(const std::string& file)
{
	size_t pos = file.find_last_of("\\/");
	return (std::string::npos == pos) ? "" : file.substr(0, pos);
}

std::string SearchEngine::getPathFromInput(std::string input)
{
	std::string pathKey = "--path";
	std::string path = "";
	size_t pos = input.find(pathKey);
	if (pos != std::string::npos) {
		std::string cuted = input.substr(pos + pathKey.length() + 1);

		std::smatch matches;
		//std::regex regex(R"("(\w:\\)?([\w\s0-9_]\\)*[\w]+\.txt")");
		std::regex regex(R"(^"c:\\file.txt"$)");
		if (std::regex_search(cuted, matches, regex)) {
			size_t non_space_pos = cuted.find_first_not_of(' ');
			cuted = cuted.substr(non_space_pos);
			std::cout << non_space_pos << std::endl;
			std::cout << cuted << std::endl;
			std::cout << matches[0] << std::endl;
			std::cout << cuted.find(matches[0]) << std::endl;
			if (cuted.find(matches[0]) == 0) {
				path = matches[0];
			}
		}
	}
	/*
	должно работать с кавычками и без них
	проверить на работу с пробелами
	проверить если впереди будет мусор

	add_file --path ""
	add_file --path "c:\file.txt"
	add_file --path "Test_data\\doc_quick_search\\docs 1251\\2.txt"

	/^(([a-zA-Z]:)|(\{2}w+)$?)(\(w[w ]*))+.(txt|TXT)$/si

	Регулярное выражение совпадет
	c:file.txt | c:foldersub folderfile.txt | networkfolderfile.txt
	Регулярное выражение не совпадет
	C: | C:file.xls | folder.txt
	*/

	return path;
}

vString getDirectoryFiles(const std::string& path) {
	vString files;

	DIR *dir;
	struct dirent *ent;
	if ((dir = opendir(path.c_str())) != NULL) {
		while ((ent = readdir(dir)) != NULL) {
			const std::string str = ent->d_name;
			if (str.length() >= 4 && str.substr(str.length() - 4) == ".txt")
			{
				files.push_back(str);
			}
		}
		closedir(dir);
	}

	return files;
}

vString split(const std::string& s)
{
	vString ret;
	typedef std::string::size_type string_size;
	string_size i = 0;

	while (i != s.size()) {
		while (i != s.size() && isspace(s[i]))
			++i;

		string_size j = i;

		if (s[j] != s.size() && (s[j] == '\'' || s[j] == '\"')) {
			char quote = s[j];

			while (true) {
				++j;
				if (j == s.size() || s[j] == quote) break;
			}

			if (i + 1 != j - 1) {
				ret.push_back(s.substr(i + 1, j - i - 1));
				if (j == s.size()) break;
				else i = j + 1;
			}
		}
		else {
			while (j != s.size() && !isspace(s[j]))
				j++;

			if (i != j) {
				ret.push_back(s.substr(i, j - i));
				i = j;
			}
		}
	}
	return ret;
}