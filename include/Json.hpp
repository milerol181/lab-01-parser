//
// Created by michael on 11.12.2020.
//

#ifndef TEMPLATE_JSON_HPP
#define TEMPLATE_JSON_HPP
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <Student.hpp>
class Table {
 public:
  Table();
  void parsing_file(const std::string &path_file);
  std::string print_string_all();
 private:
  std::vector<Student> students_all;

};

#endif  // TEMPLATE_JSON_HPP
