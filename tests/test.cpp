// Copyright 2020 Your Name <your_email>

#include <gtest/gtest.h>
#include <Student.hpp>
#include <fstream>
#include <Json.hpp>

TEST(Example, EmptyTest) {
    EXPECT_TRUE(true);
}

TEST(Example, first_test) {
  std::string file_path = "../file_json/first.json";
  Table table;
  table.parsing_file(file_path);
  std::cout << table.print_string_all();

  EXPECT_TRUE(true);

}
