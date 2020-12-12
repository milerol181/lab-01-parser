//
// Created by michael on 10.12.2020.
//

#include <Student.hpp>
using nlohmann::json;

void Student::from_json(const json& j) {

  name = get_name(j.at("name"));
  group = get_group(j.at("group"));
  avg = get_avg(j.at("avg"));
  debt = get_debt(j.at("debt"));
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
    return j.get<std::string>();
  else
  return j.get<std::size_t>();
}

std::string Student::name_string() const
{
  return name;
}
std::string Student::group_string() const
{
  if (group.type() == typeid(int))
    return std::to_string(std::any_cast<int>(group));
  else if (group.type() == typeid(float))
  {
    std::string tmp = std::to_string(std::any_cast<float>(group));
    while (tmp.at(tmp.size()-1) == '0')
      tmp = tmp.substr(0, tmp.size()-1);
    return tmp;
  } else {
    return std::any_cast<std::string>(group);
  }
}
std::string Student::avg_string() const
{
  if (avg.type() == typeid(int))
    return std::to_string(std::any_cast<int>(avg));
  else if (avg.type() == typeid(float_t))
  {
    std::string tmp = std::to_string(std::any_cast<float>(avg));
    while (tmp.at(tmp.size()-1) == '0')
      tmp = tmp.substr(0, tmp.size()-1);
    return tmp;
  } else {
    return std::any_cast<std::string>(avg);
  }
}
std::string Student::debt_string() const
{
  if (debt.type() == typeid(int))
    return std::to_string(std::any_cast<int>(debt));
  else if (debt.type() == typeid(std::vector<std::string>))
  {
    int size;
    size = std::any_cast<std::vector<std::string>>(debt).size();
    //  return "this debt is vector";
    return std::to_string(size);
  } else {
    if (debt.type() == typeid(std::nullptr_t))
    {
      return "null";
    } else {
      return std::any_cast<std::string>(debt);
    }
  }
}

std::string Student::print_string() const {
  std::string string;
  string = name + avg_string() + debt_string() + group_string();
  return string;
}
Student::Student(const json& j) {
  from_json(j);
}
