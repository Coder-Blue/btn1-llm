#include "book.h"

Book::Book()
    : id(0), title(""), author(""), publish_date(""), available(true) {}

Book::Book(int id, const std::string &title, const std::string &author,
           const std::string &publish_date, bool available)
    : id(id), title(title), author(author), publish_date(publish_date),
      available(available) {}