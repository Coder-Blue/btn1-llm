#pragma once

#include <string>

struct Book {
  int id;
  std::string title;
  std::string author;
  std::string publish_date;
  bool available;

  Book();
  Book(int id, const std::string &title, const std::string &author,
       const std::string &publish_date, bool available = true);
};