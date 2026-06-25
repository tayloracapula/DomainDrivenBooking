#pragma once
#include <algorithm>
#include <cctype>
#include <string>

//start trim in place
inline void ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
	return !std::isspace(ch);
    }));
}

//end trim in place
inline void rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch){
	return !std::isspace(ch);
    }).base(), s.end());
}

//both ends trim in place
inline void trim(std::string &s){
    rtrim(s);
    ltrim(s);
}

// start trim (copying)
inline std::string ltrim_copy(std::string s){
    ltrim(s);
    return s;
}

//end trim (copying)
inline std::string rtrim_copy(std::string s){
    rtrim(s);
    return s;
}

//both ends trim (copying)
inline std::string trim_copy (std::string s) {
    trim(s);
    return s;
}


