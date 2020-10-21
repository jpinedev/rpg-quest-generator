#include <string>
#include <sstream>
#include <iostream>

#include "quest.hpp"

namespace Quest {

  std::string format_with_item(const std::string & temp, const Item & item) {
    std::stringstream in(temp);
    std::stringstream out;

    bool firstWord = true;
    std::string word;
    while (in >> word) {
      if (!firstWord) {
        out << " ";
      }
      if (word == "{item.name}") {
        out << item.name;
      } else if (word.length() >= 11 && word.substr(0, 11) == "{item.name}") {
        out << item.name << word.substr(11, std::string::npos);
      } else {
        out << word;
      }
      firstWord = false;
    }
    return out.str();
  }
  std::string format_with_item_count(const std::string & temp, const Item & item, int count) {
    std::stringstream in(temp);
    std::stringstream out;

    bool firstWord = true;
    std::string word;
    while (in >> word) {
      if (!firstWord) {
        out << " ";
      }
      if (word == "{item.name}") {
        out << item.name;
      } else if (word.length() >= 11 && word.substr(0, 11) == "{item.name}") {
        out << item.name << word.substr(11, std::string::npos);
      } else if (word == "{item.count}") {
        out << count;
      } else {
        out << word;
      }
      firstWord = false;
    }
    return out.str();
  }

  Collect::Collect(const std::string & temp, const Item & item, const int & count) {
    this->_template = temp;
    this->_item = item;
    this->_count = count;
  }
  std::string Collect::toString() {
    return format_with_item_count(this->_template, this->_item, this->_count);
  }

}