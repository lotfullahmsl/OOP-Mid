#include <iostream>
#include <string>
#include <list>
#include <sstream>
#include <fstream>

using namespace std;
class Book {
public:
	list<Book> books;
	string title;
	string author;
	int price;
	Book(string title, string author, int price) {
		this->title = title;
		this->author = author;
		this->price = price;
	}
	void Display_Book_Info() {
		cout << "Title: " << title << endl;
		cout << "Author: " << author << endl;
		cout << "Price: " << price << endl;
	}
	void Add_Book(Book book) {
		books.push_back(book);
	}
};
class ShoppingCart {
public:
	//creat attributes for this class
	list<Book> books;
	int total_price;
	//creat constructor for this class
	ShoppingCart() {
		total_price = 0;
	}
	//creat method for this class
	void Add_Book(Book book) {
		books.push_back(book);
		total_price += book.price;
	}

	void Display_ShoppingCart() {
		for (Book book : books) {
			book.Display_Book_Info();
		}
		cout << "Total Price: " << total_price << endl;
	}
	//implement methods to view cart contints
	void View_ShoppingCart() {
		cout << endl;
		ifstream file;
		file.open("Cart.txt");
		string line;
		while (getline(file, line)) {
			cout << line << endl;
		}
		file.close();
		
		for (Book book : books) {
			book.Display_Book_Info();
		}
	}
	//implement method to proceed with chekout
	void Proceed_To_Checkout() {
		//add a logic here to method
		cout << "Total Price: " << total_price << endl;

	}
	//implement method to clear shopping cart
	void Clear_ShoppingCart() {
		books.clear();
		
		ifstream file;
		string line;
		while (getline(file, line)) {
			cout << line << endl;
		}
		file.close();
		cout << "Total Price After Cleaning: " << total_price << endl;
		cout << endl;

	}
};

int main() {
	Book book1("The Alchemist", "Paulo Coelho", 500);
	Book book2("The Da Vinci Code", "Dan Brown", 700);
	Book book3("The Kite Runner", "Khaled Hosseini", 600);
	Book book4("The Great Gatsby", "F. Scott Fitzgerald", 800);
	ShoppingCart cart;
	cout << "1. Add Book" << endl;
	cout << "2. View Cart" << endl;
	cout << "3. Proceed to Checkout" << endl;
	cout << "4. Clear Cart" << endl;
	cout << "5. Exit" << endl;
	cout << "Enter your choice: ";
	char choice;
	cin >> choice;
	switch (choice) {
	case '1':
	{
			int price;
			string title, author;
			cin.ignore();
			cout << "Enter Title: ";
			getline(cin, title);
			cout << "Enter Author: ";
			getline(cin, author);
			cout << "Enter Price: ";
			cin >> price;
			Book book(title, author, price);
			cart.Add_Book(book);
			if (book1.author == author && book1.title == title && book1.price == price) {
				book.Add_Book(book1);

				cout << "Book Added Successfully" << endl;
				book.Display_Book_Info();
				cout << "Total Price: " << book.price << endl;
				ofstream file;
				file.open("Cart.txt");
				file << "Title: " << title << endl;
				file << "Author: " << author << endl;
				file << "Price: " << price << endl;
				file.close();
				break;
			}
			else if (book2.author == author && book2.title == title && book2.price == price) {
				book.Add_Book(book2);
				cout << "Book Added Successfully" << endl;
				book.Display_Book_Info();
				cout << "Total Price: " << book.price << endl;
				ofstream file;
				file.open("Cart.txt");
				file << "Title: " << title << endl;
				file << "Author: " << author << endl;
				file << "Price: " << price << endl;
				file.close();
				break;
			}
			else if (book3.author == author && book3.title == title && book3.price == price) {
				book.Add_Book(book3);
				cout << "Book Added Successfully" << endl;
				book.Display_Book_Info();
				cout << "Total Price: " << book.price << endl;
				ofstream file;
				file.open("Cart.txt");
				file << "Title: " << title << endl;
				file << "Author: " << author << endl;
				file << "Price: " << price << endl;
				file.close();
				break;
			}
			else if (book4.author == author && book4.title == title && book4.price == price) {
				book.Add_Book(book4);
				cout << "Book Added Successfully" << endl;
				book.Display_Book_Info();
				cout << "Total Price: " << book.price << endl;
				ofstream file;
				file.open("Cart.txt");
				file << "Title: " << title << endl;
				file << "Author: " << author << endl;
				file << "Price: " << price << endl;
				file.close();
				break;
			}
			else {
				cout << "Wrong information" << endl;
				break;
			}

			// this part store data into file
			ofstream file;
			file.open("Cart.txt");
			file << "Title: " << title << endl;
			file << "Author: " << author << endl;
			file << "Price: " << price << endl;
			file.close();
			break;			
	}

	break;
	case '2':
		cart.View_ShoppingCart();
		break;
	case '3':
		cart.Proceed_To_Checkout();
		break;
	case '4':
		cart.Clear_ShoppingCart();
		break;
	case '5':
		exit(0);
		break;
	default:
		cout << "Invalid Choice" << endl;
	}
	return 0;

}