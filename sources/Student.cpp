//
// Created by michael on 10.12.2020.
//

#include <Student.hpp>
using nlohmann::json;

void Student::from_json(const json& j, Student& s) {

  s.name = get_name(j.at("group"));
  s.group = get_group(j.at("group"));
  s.avg = get_avg(j.at("avg"));
  s.debt = get_group(j.at("debt"));
}

auto Student::get_name(const json& j) -> std::string {
  return j.get<std::string>();
}

auto Student::get_debt(const json& j) -> std::any {
  if (j.is_null())
    return nullptr;
  else if (j.is_string())
    return j.get<std::string>();
  else
    return j.get<std::vector<std::string> >();
}

auto Student::get_avg(const json& j) -> std::any {
  if (j.is_null())
    return nullptr;
  else if (j.is_string())
    return j.get<std::string>();
  else if (j.is_number_float())
    return j.get<double>();
  else
    return j.get<std::size_t>();
}

auto Student::get_group(const json& j) -> std::any {
  if (j.is_string())
    return = j.get<std::string>();
  else
  return j.get<std::size_t>();
}