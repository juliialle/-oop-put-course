#include <iostream>
#include <optional>
#include <utility>
#include <vector>
using namespace std;

class Book {
private:
    string title;
public:
    Book Name(string newTitle) {
        this -> title = move(newTitle);
        return *this;
    }
    string CurrentTitle() {
        return this -> title;
    }
};

class Human {
private:
    string state;
    std::optional<vector<Book>> ownShelf;
public:
    void Activate(string NewState) {
        this -> state = move(NewState);
    }
    void PutBook(const Book &book) {
        this -> ownShelf -> push_back(book);
    }
    Book TakeBook() {
        Book takenFromShelf = this->ownShelf->back();
        this->ownShelf->pop_back();
        return takenFromShelf;
    }
};

int main() {
    Human StudentIgor;
    StudentIgor.Activate("Studying");
    Book book;
    Book actualBook = book.Name("Mathematics");
    StudentIgor.PutBook(actualBook);
    Book newBook = StudentIgor.TakeBook();
    newBook.Name("Wesele");
    cout << newBook.CurrentTitle();
    return 0;
}