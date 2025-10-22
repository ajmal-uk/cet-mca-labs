print("<=== Publisher, Book, Python (base class constructor invocation, Method Overriding) ===>\n")

class Publisher:
    def __init__(self, name, age):
        self.name = name
        self.age = age

class Book(Publisher):
    def __init__(self, no_of_books, name, age, book_name):
        super().__init__(name, age)
        self.no_of_books = no_of_books
        self.book_name = book_name
    
    def display_books(self):
        print(f"Number of Books by {self.name} is {self.no_of_books}")

    def author_name(self):
        print(f"From Book Class:\nThe author name is {self.name}")

class Python(Book):
    def __init__(self, no_of_books, name, age, book_name):
        super().__init__(no_of_books, name, age, book_name)

    def author_name(self):
        print(f"From Python Class:\nThe author name is {self.name}")

    def print_book_name(self):
        print(f"Book Name is {self.book_name}")

p = Python(5, "John Doe", 45, "Learning Python")
p.display_books()
p.author_name()
p.print_book_name()

print(p.name)