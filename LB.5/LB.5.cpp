#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//КЛАСИ
//клас для книг
class Book
{
    //публічний, щоб компоненти були доступними і поза класом
public:
    int NUMB;
    string NAME;
    string AUTHOR;
    string ANNOTATION;
    string DATE;
};

//клас для відвідувача
class Customer
{
public:
    int NUMB;
    string NAME;
    string BIRHT;
    string PHONENUMB;
};

//клас для дат
class Dates
{
public:
    string DATE;
};

//ФУНКЦІЇ
//загальна функція, якщо щось пішло не так, помилка
void absurd()
{
    cout << "IT SEEMS YOU ARE DOING SMTH WRONG:(";
}


//2 функції помилки 
void error1(ifstream& x)
{
    if (!x.is_open())
        cout << "ERROR NOTICED!" << '\n';
}
void error2(ofstream& y)
{
    if (!y.is_open())
        cout << "ERROR NOTICED!" << '\n';
}

//функція списку книг
void list(ifstream& z)
{
    string lst;

    //функція, яка видає правду
    while (!z.eof())
    {
        lst = "";
        getline(z, lst);

        cout << lst << '\n';
    }
}

//головна функція, що викликає виществоренні функції
int main()
{
    //створення текстових файлів
    string way_cust = "CUSTOMERS.txt";
    string way_book = "BOOKS.txt";
    string way_infor1 = "TOOKEN.txt";
    string way_infor2 = "RETURNED.txt";

    Book i, j, k, l;
    Customer newone, old;
    Dates dmy;

    cout << "FIRST I NEED TO KNOW IF YOU ARE A LIBRARIAN OR A VISITOR?" << endl;
    cout << "just write here 1 or 2:" << endl;
    int a;
    cout << "-> ";
    cin >> a;

    //якщо працівник бібліотеки
    if (a == 1)
    {
        cout << endl;
        cout << endl << "GOT IT. SO WRITE DOWN: " << endl;
        cout << "1 - to add a book" << endl;
        cout << "2 - to try to delete a book:)" << endl;
        int b;
        cout << "-> ";
        cin >> b;

        //якщо додати нову книгу
        if (b == 1)
        {
            //список книг, що є на "базі"
            ifstream showlist;
            showlist.open(way_book);
            //error1(showlist);

            if (showlist.is_open())
            {
                cout << endl;
                cout << "HERE IS ALL BOOKS SEEABLE: " << endl;
                cout << endl << "      *********      " << endl;
                list(showlist);
                cout << "      *********      " << endl;
            }
            showlist.close();
            
            ///вивід цього списку для додавання нової бажаної
            ofstream reveallist;
            reveallist.open(way_book, ofstream::app);
            //error2(reveallist);

            if (reveallist.is_open())
            {
                cout << endl;
                cout << "YOU WANNA ADD BOOK? GOT IT." << endl;
                cout << endl << "SO, THEN HERE IS THE STEPS:" << endl;

                cout << "   WRITE THE NUMBER:" << endl;
                cout << "-> ";
                cin >> i.NUMB;

                cout << "   WRITE THE NAMECOVER OF BOOK:" << endl;
                cout << "-> ";
                cin >> i.NAME;

                cout << "   ALSO WHO IS THE AUTHOR?:" << endl;
                cout << "-> ";
                cin >> i.AUTHOR;

                cout << "   AND THE DATA OF PRINTING (to be included in the database):" << endl;
                cout << "-> ";
                cin >> i.DATE;

                cout << endl;
                cout << endl << "      *********      " << endl;
                cout << "FINALY YOUR BOOK`S INFO:" << " " << endl << i.NUMB << i.NAME << " " << i.AUTHOR << " " << i.DATE << endl;
                cout << "      *********      " << endl;
                reveallist << endl << i.NUMB << i.NAME << " " << i.AUTHOR << " " << i.DATE << endl;

                cout << endl;
                cout << endl << "EVERYTHING TURNED OUT GREAT, THE BOOK IS ADDED!" << endl;
            }
            reveallist.close();
        }
        //якщо видалити 
        else if (b == 2)
        {
            ifstream reveallist;
            reveallist.open(way_book);

            if (reveallist.is_open())
            {
                cout << "HERE IS ALL BOOKS SEEABLE: " << endl;
                cout << endl << "      *********      " << endl;
                list(reveallist);
                cout << "      *********      " << endl;

                cout << endl << "BUT, UNFORTUNATELLY, YOU CANNOT DELETE ANY BOOKS."
                    "YOU ARE JUST A LIBRARIAN AND DO NOT HAVE SUCH PRIVILEGES:( : " << endl;
            }
            reveallist.close();
        }
        else
            absurd();
    }

    //якщо відвідувач
    else if (a == 2)
    {
        cout << endl << "OKEY, MAYBE YOU HAVE YOUR ID NUMBER IN OUR BASE(1) OR ARE YOU HAVING A FIRST TIME BEING HERE(0)?" << endl;
        cout << "just write here 1 or 0:" << endl;
        int c;
        cout << "-> ";
        cin >> c;

        //якщо відвідувач має ID
        if (c == 1)
        {
            cout << endl << "WELCOME BACK THEN!" << endl;
            cout << "1 - to return a book" << endl;
            cout << "2 - to take a book:)" << endl;
            int d;
            cout << "-> ";
            cin >> d;

            if (d == 1)
            {
                cout << "   WHAT IS YOUR NAME SO?:" << endl;
                cout << "-> ";
                cin >> old.NAME;

                cout << "   WHICH NUMBER OF BOOK YOU WANNA RETURN?:" << endl;
                cout << "-> ";
                cin >> j.NUMB;

                ofstream returnbook;
                returnbook.open(way_infor2, ofstream::app);
                error2(returnbook);
                if (returnbook.is_open())
                {
                    returnbook << endl << old.NAME << " " << j.NUMB << " ";
                    returnbook.close();

                    cout << "THIS BOOK RETURNED. THANK YOU, WE ARE WAITING FOR YOU AGAIN!" << endl;

                }
            }

            //якщо забрати книгу
            else if (d == 2)
            {
                cout << "WHAT IS YOUR NAME SO?:";
                cout << "-> ";
                cin >> old.NAME;

                //вивід усього списку 
                ifstream showlist;
                showlist.open(way_book);
                error1(showlist);

                if (showlist.is_open())
                {
                    cout << endl << "      *********      " << endl;
                    list(showlist);
                    cout << "      *********      " << endl;
                    showlist.close();

                    cout << old.NAME << "," << "WHICH ONE YOU WANNA TOOK?:" << endl;
                    cout << "-> ";
                    cin >> k.NUMB;

                    //узята книга
                    ofstream tookenbook;
                    tookenbook.open(way_infor1, ofstream::app);
                    error2(tookenbook);

                    if (tookenbook.is_open())
                    {
                        tookenbook << endl << old.NAME << " " << k.NUMB << " ";
                    }
                    tookenbook.close();

                    cout << endl << "GOOD IMPRESSIONS FROM THE BOOK AND WAITING FOR YOU BACK FOR NEW BOOK`S ADVENTURES!";
                }
            }
            else
                absurd();
        }

        //якщо новенький
        else if (c == 0)
        {

            cout << endl << "OKEY, WELCOME SO! YOU CHOOSE THE BEST PLACE TO DIVE INTO THE AMAZING WORLD OF LITERATURE!" << endl;
            cout << "HERE YOU CAN SEE THE LIST OF OUR CUSTOMERS JUST LIKE YOU." << endl;

            //список користувачів
            ifstream showcust;
            showcust.open(way_cust);
            error1(showcust);

            if (showcust.is_open())
            {
                cout << endl << "      *********      " << endl;
                list(showcust);
                cout << "      *********      " << endl;
            }
            showcust.close();

            //новий відвідувач
            ofstream revealcust;
            revealcust.open(way_cust, ofstream::app);
            error2(revealcust);

            if (revealcust.is_open())
            {
                cout << endl << "HERE IS A QUESTIONNAIRE YOU NEED TO FILL TO BECOME PART OF OUR FAMILY" << endl;
                cout << "   WRITE THE NUMBER FIRST:" << endl;
                cout << "-> ";
                cin >> newone.NUMB;

                cout << endl << "   WRITE YOUR NAME:" << endl;
                cout << "-> ";
                cin >> newone.NAME;

                cout << endl << "   WRITE YOUR BIRTH DATA: " << endl;
                cout << "-> ";
                cin >> newone.BIRHT;

                cout << endl << "   WRITE YOUR PHONE NUMBER:" << endl;
                cout << "-> ";
                cin >> newone.PHONENUMB;

                cout << endl << "      *********      " << endl;
                cout << "FINALY YOUR PERSONALLY INFO: " << " " << newone.NUMB << newone.NAME << " " << newone.BIRHT << " " << newone.PHONENUMB << " " << endl;
                cout << "      *********      " << endl;

                revealcust << endl << newone.NUMB << newone.NAME << " " << newone.BIRHT << " " << newone.PHONENUMB << " ";
                cout << "CONGRADS! YOU ARE NOW THE MEMBER OF OUR BIG-BOOKS-FAMILY. HAPPY TO SEE YOU HERE!" << endl;
                revealcust.close();

                cout << newone.NAME << "," << " OKEY, DO YOU WANT TO TAKE A BOOK NOW?" << endl;
                cout << "just write here 1 or 0:" << endl;
                cout << "-> ";
                int w;
                cin >> w;

                if (w == 1)
                {
                    //вивід списку книг
                    ifstream reveallist;
                    reveallist.open(way_book);
                    //err(book_out, path_book);
                    error1(reveallist);
                    if (reveallist.is_open())
                    {
                        cout << newone.NAME << ", " << "CHOOSE A BOOK BY WRITING ITS NUMBER: " << endl;
                        
                        cout << endl << "      *********      " << endl;
                        list(reveallist);
                        cout << "      *********      " << endl;
                        cout << "-> ";
                        cin >> l.NUMB;

                        reveallist.close();

                        //дані про взяту книгу
                        ofstream tookenbook;
                        tookenbook.open(way_infor1, ofstream::app);
                        error2(tookenbook);

                        if (tookenbook.is_open())
                        {
                            tookenbook << endl << newone.NAME << " " << l.NUMB << " " << dmy.DATE;
                        }
                        tookenbook.close();

                        cout << endl << "GOOD IMPRESSIONS FROM THE BOOK AND WAITING FOR YOU BACK FOR NEW BOOK`S ADVENTURES!";
                    }
                }

                else if (w == 0)
                {
                    cout << "HAVE A NICE DAY SO! WAITING FOR YOU" << endl;
                }
                else
                    absurd();
            }
        }
        else
        absurd();
    }
    else
    absurd();

    return 0;
}
