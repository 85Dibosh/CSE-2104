#include <bits/stdc++.h>
using namespace std;
struct Book{
    string title;
    string author;
    int year;
};

void selectionSort(vector<Book>& books){
    int n = books.size();
    for(int i = 0; i < n - 1; i++){
        int min = i;
        for(int j = i + 1; j < n; j++){
            if(books[j].year != books[min].year){
                if(books[j].year > books[min].year)
                    min = j;
            }else if(books[j].author != books[min].author){
                if(books[j].author < books[min].author)
                    min = j;
            }else if(books[j].title != books[min].title){
                if(books[j].title < books[min].title)
                    min = j;
            }
        }
        swap(books[i],books[min]);
    }
}

int main(){
    int n;
    cin >> n;

    vector<Book> books(n);
    for(int i = 0; i < n; i++){
        getline(cin >> ws, books[i].title, ',');
        getline(cin >> ws, books[i].author, ',');
        cin >> books[i].year;

        if (!books[i].author.empty() && books[i].author[0] == ' ') {
            books[i].author = books[i].author.substr(1);
        }

    }

    selectionSort(books);

    cout << endl;

    for (const auto& b : books) {
        cout << b.title << ", " << b.author << ", " << b.year << "\n";
    }
    return 0;
}
