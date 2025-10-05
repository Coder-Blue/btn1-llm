#include "library.h"
#include <algorithm>
#include <fstream>
#include <iostream>

Library::Library(const std::string &filename) : filename(filename) {}

void Library::load() {
  books.clear();

  std::ifstream fin(filename);

  if (!fin)
    return;

  int id, available;
  std::string title, author, publish_date, line;
  while (std::getline(fin, line)) {
    if (line.empty())
      continue;
    id = std::stoi(line);

    std::getline(fin, title);
    std::getline(fin, author);
    std::getline(fin, publish_date);
    std::getline(fin, line);

    available = std::stoi(line);
    std::getline(fin, line);
    books.emplace_back(id, title, author, publish_date, available);
  }
}

void Library::save() const {
  std::ofstream fout(filename);
  for (const auto &book : books) {
    fout << book.id << "\n"
         << book.title << "\n"
         << book.author << "\n"
         << book.publish_date << "\n"
         << book.available << "\n"
         << "---\n";
  }
}

void Library::addBook(const Book &book) { books.push_back(book); }

int Library::getNextBookId() const {
  int maxId = 0;
  for (const auto &book : books) {
    if (book.id > maxId)
      maxId = book.id;
  }
  return maxId + 1;
}

void Library::listBooks() const {
  std::cout << "\n===== Book List =====\n";
  for (const auto &book : books) {
    std::cout << "ID: " << book.id << "\n"
              << "Title: " << book.title << "\n"
              << "Author: " << book.author << "\n"
              << "Published: " << book.publish_date << "\n"
              << "Status: " << (book.available ? "Available" : "Borrowed")
              << "\n"
              << "---------------------------\n";
  }
}

Book *Library::getBookById(int id) {
  for (auto &book : books) {
    if (book.id == id)
      return &book;
  }
  return nullptr;
}

bool Library::borrowBook(int id, Book &outBook) {
  for (auto &book : books) {
    if (book.id == id && book.available) {
      book.available = false;
      outBook = book;
      return true;
    }
  }
  return false;
}

bool Library::returnBook(int id, Book &outBook) {
  for (auto &book : books) {
    if (book.id == id && !book.available) {
      book.available = true;
      outBook = book;
      return true;
    }
  }
  return false;
}

void Library::searchBooks(const std::string &keyword) const {
  std::string lower_keyboard = keyword;
  std::transform(lower_keyboard.begin(), lower_keyboard.end(),
                 lower_keyboard.begin(), ::tolower);
  bool found = false;

  std::cout << "\n===== Search Results =====\n";

  for (const auto &book : books) {
    std::string title = book.title;
    std::string author = book.author;

    std::transform(title.begin(), title.end(), title.begin(), ::tolower);
    std::transform(author.begin(), author.end(), author.begin(), ::tolower);

    if (title.find(lower_keyboard) != std::string::npos ||
        author.find(lower_keyboard) != std::string::npos) {
      std::cout << "ID: " << book.id << "\n"
                << "Title: " << book.title << "\n"
                << "Author: " << book.author << "\n"
                << "Published: " << book.publish_date << "\n"
                << "Status: " << (book.available ? "Available" : "Borrowed")
                << "\n"
                << "---------------------------\n";
      found = true;
    }
  }

  if (!found) {
    std::cout << "No books found for keyword: " << keyword << "\n";
  }
}