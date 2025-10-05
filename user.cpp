#include "user.h"
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <regex>
#include <sstream>
#include <string>

User::User(const std::string &studentId) : studentId(studentId) {}

std::string User::getId() const { return studentId; }

void User::recordHistory(const std::string &action, const Book &book) const {
  std::ofstream fout("history_" + studentId + ".txt", std::ios::app);

  auto t = std::time(nullptr);
  auto tm = *std::localtime(&t);

  fout << std::put_time(&tm, "%Y-%m-%d") << " " << action << " " << book.id
       << " " << book.title << "\n";
}

void User::showHistory() const {
  std::ifstream fin("history_" + studentId + ".txt");

  if (!fin) {
    std::cout << "No history found for user " << studentId << ".\n";
    return;
  }

  std::string line;
  std::cout << "Borrow/Return History for " << studentId << ":\n";

  while (std::getline(fin, line)) {
    std::cout << line << "\n";
  }
}

bool User::registerUser(const std::string &studentId,
                        const std::string &password) {
  std::ifstream fin("users.txt");
  std::string line;

  while (std::getline(fin, line)) {
    std::istringstream iss(line);
    std::string id, pass;
    std::getline(iss, id, ',');

    if (id == studentId) {
      std::cout << "Student ID already registered.\n";
      return false;
    }
  }
  fin.close();

  std::ofstream fout("users.txt", std::ios::app);
  fout << studentId << ',' << password << "\n";
  return true;
}

bool User::authenticate(const std::string &studentId,
                        const std::string &password) {
  std::ifstream fin("users.txt");
  std::string line;

  while (std::getline(fin, line)) {
    std::istringstream iss(line);
    std::string id, pass;

    std::getline(iss, id, ',');
    std::getline(iss, pass);

    if (id == studentId && pass == password) {
      return true;
    }
  }
  return false;
}

bool User::isValidId(const std::string &id) {
  return std::regex_match(id, std::regex("\\d{8}"));
}