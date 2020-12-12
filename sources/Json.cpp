//
// Created by michael on 11.12.2020.
//

#include "Json.hpp"
#include <Student.hpp>
Table::Table() {}
void Table::parsing_file(const std::string& path_file) {
  std::ifstream file(path_file, std::ifstream::in);
  if (!file) {
    throw std::string("Could not find json file by path: " + path_file);
  }
  nlohmann::json data;
  file >> data;

  for (auto i = data.at("items").cbegin();
       i < data.at("items").cend();
       i++)
  {
    students_all.push_back(Student(i.value()));
  }
}
std::string Table::print_string_all() {
  std::string string;
  for (auto i = students_all.cbegin(); i < students_all.cend(); i++) {
    string += i->print_string();
  }
  return string;
}
