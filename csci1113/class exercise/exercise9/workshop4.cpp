#include <iostream>
using namespace std;

struct bookData
{
    private:
    string title;
    string author[4];
    string isbn;
    double price;
    int copies;
    public:
    bookData();
    bookData(string, string*, int, string, double, int);
    void setTitle(string);
    void setAuthor(string[], int);
    void setISBN(string);
    void setPrice(double);
    void setCopies(int);
    string getTitle(string);
    string* getAuthor(string[], int);
    string getISBN(string);
    double getPrice(double);
    int getCopies(int);
};

bookData::bookData(){
    title = "";
    for (size_t i = 0; i < 4; i++)
    {
        author[i] = "";
    }
    isbn = "";
    price = 0;
    copies = 0;
}
bookData::bookData(string titleval, string* auth, int numauth, string isbnval, double priceval, int copiesval){
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
    void setTitle(string titleval){
        bookData::title = titleval;
    }
    void setAuthor(string* auth, int num){
        for (size_t i = 0; i < num; i++)
        {
            bookData::author[i] = auth[i];
        }
    }
    void setISBN(string){

    }
    void setPrice(double){

    }
    void setCopies(int){

    }
    string getTitle(string){

    }
    string* getAuthor(string[], int){

    }
    string getISBN(string){

    }
    double getPrice(double){

    }
    int getCopies(int){

    }