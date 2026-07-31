#include<bits/stdc++.h>
using namespace std;
struct Book
{
    int id;
    string book_name;
    string author_name;
    int total_copies;
    int issued_copies;
    string issue_date;
    string return_date;
    int available_copies;
};
int book_number=0;
Book library[100];
void add_book()
{
    ofstream fout("library.txt",ios::app);
    cout<<"Enter book ID: "<<endl;
    cin>>library[book_number].id;
    cin.ignore();
    cout<<"Enter book name: "<<endl;
    getline(cin,library[book_number].book_name);
    cout<<"Enter author name: "<<endl;
    getline(cin,library[book_number].author_name);
    cout<<"Enter total copies of the book: "<<endl;
    cin>>library[book_number].total_copies;
    library[book_number].issued_copies=0;
    library[book_number].available_copies=library[book_number].total_copies-library[book_number].issued_copies;
    fout<<library[book_number].id<<" | "
        <<library[book_number].book_name<<" | "
        <<library[book_number].author_name<<" | "
        <<library[book_number].total_copies<<" | "
        <<library[book_number].issued_copies<<" | "
        <<library[book_number].available_copies<<endl;
    fout.close();
    book_number++;
    cout<<"Book added successfully!"<<endl;
}
void search_book()
{
    int book_id;
    bool found=false;
    cout<<"Enter book ID to search: "<<endl;
    cin>>book_id;
    for(int i=0; i<book_number; i++)
    {
        if(library[i].id==book_id)

        {
            library[i].available_copies= library[i].total_copies-library[i].issued_copies;

            cout<<"Book ID:" <<library[i].id<<endl;
            cout<<"Book Name: "<<library[i].book_name<<endl;
            cout<<"Author Name: "<<library[i].author_name<<endl;
            cout<<"Available copies: "<<library[i].available_copies<<endl;
            found=true;
            break;
        }
    }
    if(!found)
    {
        cout<<"Book is not found."<<endl;
    }
}
void borrow_book()
{
    int id;
    bool found=false;
    cout<<"Enter book ID to borrow: "<<endl;
    cin>>id;
    for(int i=0; i<book_number; i++)
    {
        if(library[i].id==id)
        {
            found=true;
            if(library[i].issued_copies<library[i].total_copies)
            {
                library[i].issued_copies++;
                library[i].available_copies=library[i].total_copies-library[i].issued_copies;
                cout<<"Book is issued successfully!"<<endl;
            }
            else
            {
                cout<<"Book is not available!"<<endl;
            }
            break;
        }
    }
    if(!found)
    {
        cout<<"Book is not found."<<endl;
    }

}
void return_book()
{
    int id;
    cout<<"Enter book ID to return: "<<endl;
    cin>>id;
    for(int i=0; i<book_number; i++)
    {
        if(library[i].id==id &&library[i].issued_copies>0)
        {
            library[i].issued_copies--;
            library[i].available_copies=library[i].total_copies-library[i].issued_copies;
            cout<<"Book returned successfully!"<<endl;
            break;
        }
    }
}
void update_file()
{
    ofstream fout("library.txt");
    for(int i=0; i<book_number; i++)
    {
        fout<<library[i].id<<" | "

            <<library[i].book_name<<" | "
            <<library[i].author_name<<" | "
            <<library[i].total_copies<<" | "
            <<library[i].issued_copies<<" | "
            <<library[i].available_copies<<endl;

    }
     fout.close();
}
void load_books()
{
    ifstream fin("library.txt");
    if(!fin)
    {
        cout<<"File is empty"<<endl;
    }
    while(true)
    {
        string s;
        if(!getline(fin,s,'|'))
            break;
        library[book_number].id=stoi(s);
        getline(fin,library[book_number].book_name,'|');
        getline(fin,library[book_number].author_name,'|');
        getline(fin,s,'|');
        library[book_number].total_copies=stoi(s);
        getline(fin,s,'|');
        library[book_number].issued_copies=stoi(s);
        getline(fin,s);
        library[book_number].available_copies=stoi(s);
        book_number++;
    }
    fin.close();
}
int main()
{
    load_books();
    int choice;
    string user_pass;
    cout<<"Enter password: "<<endl;
    cin>>user_pass;
    string passward="library71";
    if(user_pass==passward)
    {
        while(true)
        {
            cout<<"Welcome To EWU Library"<<endl;
            cout<<"*******Menu******"<<endl;
            cout<<"1.Add book\n 2.Search Book\n 3.Borrow Book\n 4.Return BOOK\n 5.Update Information"<<endl;
            cout<<"Enter your choice: "<<endl;
            cin>>choice;
            switch(choice)
            {
            case 1:
                add_book();
                break;
            case 2:
                search_book();
                break;
            case 3:
                borrow_book();
                break;
            case 4:
                return_book();
                break;
            case 5:
                update_file();
                break;
            default:
                cout<<"Invalid choice!"<<endl;
            }
        }
    }
    else
    {
        cout<<"Invalid Password! Please try again"<<endl;
    }
}

