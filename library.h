#pragma once

#include "book.h"
#include <string>
#include <vector>

class Library {
  std::vector<Book> books;
  std::string filename;

public:
  Library(const std::string &filename);

  void load();
  void save() const;
  void addBook(const Book &book);
  int getNextBookId() const;
  void listBooks() const;
  bool borrowBook(int id, Book &outBook);
  bool returnBook(int id, Book &outBook);
  Book *getBookById(int id);
  void searchBooks(const std::string &keyword) const;
};