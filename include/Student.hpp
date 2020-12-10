//
// Created by michael on 10.12.2020.
//

#ifndef TEMPLATE_STUDENT_HPP
#define TEMPLATE_STUDENT_HPP
#include <iostream>
#include <any>
#include <string>
#include "nlohmann/json.hpp"

class Student {
  void from_json(const json& j, Student& s);
  auto get_name(const json& j) -> std::string;
  auto get_debt(const json& j) -> std::any;
  auto get_avg(const json& j) -> std::any;
  auto get_group(const json& j) -> std::any;


 private:
  std::string name;
  std::any group;
  std::any avg;
  std::any debt;
};

#endif  // TEMPLATE_STUDENT_HPP
