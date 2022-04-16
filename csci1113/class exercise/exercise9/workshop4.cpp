#include <iostream>
using namespace std;

class Book
{
    private:
    string title;
    string author[4];
    string isbn;
    double price;
    int copies;
    public:
    Book();
    Book(string, string*, int, string, double, int);
    void setTitle(string);
    void setAuthor(string[], int);
    void setISBN(string);
    void setPrice(double);
    void setCopies(int);
    string getTitle();
    string* getAuthor();
    string getISBN();
    double getPrice();
    int getCopies();
    void display(ostream &out) const;
    void read(istream &in);
};

Book::Book(){
    title = "";
    for (size_t i = 0; i < 4; i++)
    {
        author[i] = "";
    }
    isbn = "";
    price = 0;
    copies = 0;
}
Book::Book(string titleval, string* auth, int numauth, string isbnval, double priceval, int copiesval){
    title = titleval;
    for (size_t i = 0; i < 4; i++)
    {
        if (i< numauth)
        {
            author[i] = auth[i];
        }
        else{
            author[i] = "";
        }
    }
    isbn = isbnval;
    price = priceval;
    copies = copiesval;
}
    void Book::setTitle(string titleval){
        Book::title = titleval;
    }
    void Book::setAuthor(string* auth, int num){
        for (size_t i = 0; i < num; i++)
        {
            author[i] = auth[i];
        }
    }
    void Book::setISBN(string val){
        isbn = val;
    }
    void Book::setPrice(double val){
        price = val;
    }
    void Book::setCopies(int val){
        copies = val;
    }
    string Book::getTitle(){
        return title;
    }
    string* Book::getAuthor(){
        return author;
    }
    string Book::getISBN(){
        return isbn;
    }
    double Book::getPrice(){
        return price;
    }
    int Book::getCopies(){
        return copies;
    }

    void Book::display(ostream &out) const {
        out << "the title is: " << title << endl;
        out << "the authors are: " << author[0] << ", " << author[0] << ", " << author[0] << ", " << author[0] << endl;
        out << "the isbn is: " << isbn << endl;
        out << "the price is: " << price << endl;
        out << "the number of copies is: " << copies << endl;
    }

    void Book::read(istream &in){
        cout << " title: ";
        in >> title;
        cout << "number of authors";
        int num;
        in >> num;
        for (size_t i = 0; i < num; i++)
        {
            cout << "author " << i+1 << endl ;
            in >> author[i];
        }
        cout << "isbn: ";
        in >> isbn;
        cout << "price: ";
        in >> price;
        cout << "copies: ";
        in >> copies;
        
    }

    istream &operator>>(istream &in, Book &b) {
        b.read(in);
        return in;
    }

    ostream &operator<<(ostream &out, Book &b) {
        b.display(out);
        return out;
    }


    int main(){
        Book fiction;
        cout << "enter book's information";
        cin >> fiction;
        cout << fiction << endl;
    }