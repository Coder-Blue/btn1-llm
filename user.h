#pragma once

#include "book.h"
#include <string>

class User {
  std::string studentId;

public:
  User(const std::string &studentId);
  std::string getId() const;
  void recordHistory(const std::string &action, const Book &book) const;
  void showHistory() const;

  static bool registerUser(const std::string &studentId,
                           const std::string &password);
  static bool authenticate(const std::string &studentId,
                           const std::string &password);
  static bool isValidId(const std::string &id);
};