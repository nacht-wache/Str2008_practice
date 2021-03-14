
//
// This is example code from Chapter 6.7 "Trying the second version" of
// "Software - Principles and Practice using C++" by Bjarne Stroustrup
//

/*
    This file is known as calculator02buggy.cpp

    I have inserted 5 errors that should cause this not to compile
    1. line 96: missing Token_stream:: ; 
    2. line 137: missing ' " ' ;
    3. line 160: missing ')' ;
    4. line 214: missing double val = 0;
    5. line 253: missing 'c'
 
    I have inserted 3 logic errors that should cause the program to give wrong results
    1. line 162: missing break;
    2. line 193: - instead of +
    3. line 200: missing {} for int main()

    First try to find an remove the bugs without looking in the book.
    If that gets tedious, compare the code to that in the book (or posted source code)

    Happy hunting!

*/

/*
exc 2 is handled; lines 105, 142-149; error lines 44, 250-255;
exc 3 is hanled; lines 162-192; :) recheck lines
*/

//4 bytes for pointer
// interpretator storage byte of built-in types

#include <iostream>
#include <vector>

using namespace std;

//const list
const char quit = 'q';
const char print = '=';
const string prompt = ">";
const string result = "=";


// run-time checked narrowing cast (type conversion)
template<class R, class A> R narrow_cast(const A& a)
{
    R r = R(a);
    if (A(r) != a) throw runtime_error("Oops! Info loss.\n");
    return r;
}

class Variable
{
public:
    string name;
    double value;
    Variable(string n, double v) : name(n), value(v) {}
};

//------------------------------------------------------------------------------

vector<Variable>var_table;

double get_value(string s)
{
    for (int i = 0; i < var_table.size(); ++i) {
        if (s == var_table[i].name) return var_table[i].value;
    }
    throw runtime_error("get: undefined variable");
}

double set_value(string s, double v)
{
    for (int i = 0; i < var_table.size(); ++i) {
        if (s == var_table[i].name) {
            var_table[i].value = v;
            return;
        }
    }
    throw runtime_error("set: undefined variable");
}

double statement()
{
    Token t = ts.get();
    switch (t.kind) {
    case let:
        return declaration();
    default:
        ts.putback(t);
        return expression();
    }
}

bool is_declared(string var)

{
    for (int i = 0; i < var_table.size(); ++i)
        if (var_table[i].name == var) return true;
    return false;
}

double define_name(string var, double val)
{
    if (is_declared(var)) runtime_error("declared twice");
    var_table.push_back(Variable(var, val));
    return val;
}

struct Token{
public:
    char kind;        // what kind of token
    double value;     // for numbers: a value
    string name;
    Token(char ch)    // make a Token from a char
        :kind(ch), value(0) { }
    Token(char ch, double val)     // make a Token from a char and a double
        :kind(ch), value(val) { }
    Token(char ch, string n) 
        : kind(ch), name(n) {}
};

class Token_stream {
public:
    Token_stream();   // make a Token_stream that reads from cin
    Token get();      // get a Token (get() is defined elsewhere)
    void putback(Token t);    // put a Token back
    void ignore(char c);
private:
    bool full;        // is there a Token in the buffer?
    Token buffer;     // here is where we keep a Token put back using putback()
};

// The constructor just sets full to indicate that the buffer is empty:
Token_stream::Token_stream()
    :full(false), buffer(0)    // no Token in buffer
{
}

// The putback() member function puts its argument back into the Token_stream's buffer:
void Token_stream::putback(Token t)
{
    if (full) throw runtime_error("Oops! IDK. Kiss <3");
    buffer = t;       // copy t to buffer
    full = true;      // buffer is now full
}

void Token_stream::ignore(char c)
{
    if (full && c == buffer.kind) {
        full = false;
        return;
    }

    full = false;

    char ch;
    while (cin >> ch) {
        if (ch == c) return;
    }
}

//------------------------------------------------------------------------------

const char number = '8'; //t.kind == number means that t is a number Token
const char name = 'a';
const char let = 'L';
const string declkey = "let";

Token Token_stream::get()
{
    if (full) {       // do we already have a Token ready?
        // remove token from buffer
        full = false;
        return buffer;
    }

    char ch;
    cin >> ch;    // note that >> skips whitespace (space, newline, tab, etc.)

    switch (ch) {
    case print:    // for "print"
    case quit:    // for "quit"
    case '!':    // for factorial
    case '{': 
    case '}': 
    case '(': 
    case ')': 
    case '+': 
    case '-': 
    case '*': 
    case '/':
    case '%':
        return Token(ch);        // let each character represent itself
    case '.':
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9':
    {   cin.putback(ch);         // put digit back into the input stream
        double val;
        cin >> val;              // read a floating-point number
        return Token(number, val);   // let '8' represent "a number"
    }
    default:
        if (isalpha(ch)) {
            string s;
            s += ch;
            while (cin.get(ch) && (isalpha(ch) || isdigit(ch))) s += ch;
            cin.putback(ch);
            string s;
            cin >> s;
            if (s == declkey) return Token(let);
            return Token(name, s);
        }
        throw runtime_error("Oops! Bad input. Kiss <3");
    }
}

Token_stream ts;        // provides get() and putback() 

//------------------------------------------------------------------------------

double expression();    // declaration so that primary() can call expression()


void clean_up_mess()
{
    ts.ignore(print);
}

double declaration()
{
    Token t = ts.get();
    if (t.kind != name) runtime_error("name expected in declaration");
    string var_name = t.name;

    Token t2 = ts.get();
    if (t2.kind != '=') runtime_error("= missing in declaration");

    double d = expression();
    define_name(var_name, d);
    return d;
}

// factorial 
double fucktorial(double left)
{
    if (left == 0) return 1;
    double fuck = 1;
    while (left > 1) {
        fuck *= left;
        --left;
    }
    return fuck;
}

// deal with numbers and parentheses
double primary()
{
    Token t = ts.get();
    switch (t.kind){
    case '(':    // handle '(' expression ')'
    {
        double d = expression();
        t = ts.get();
        if (t.kind != ')') throw runtime_error("Oops! Missing ')'. Kiss <3");
        return d;
    }
    case '{':
    {
        double d = expression();
        t = ts.get();
        if (t.kind != '}') throw runtime_error("Oops! Missing '}'. Kiss <3");
        return d;
    }
    case number:            // we use '8' to represent a number
        return t.value;  // return the number's value
    case '-':
        return -primary();
    case '+':
        return primary();
    default:
        throw runtime_error("Oops! No primary has been read. Kiss <3");
    }
}

// deal with !factorial
double fuck()
{
    double left = primary();
    Token t = ts.get();        // get the next token from token stream
    
    while (true) {
        switch (t.kind) {
        case '!':
        {
            return fucktorial(left);
            break;
        }
        default:
            ts.putback(t);     // put t back into the token stream
            return left;
        }
    }
}

// deal with *, /, and %
double term()
{
    double left = fuck();
    Token t = ts.get();        // get the next token from token stream

    while (true) {
        switch (t.kind) {
        case '*':
            left *= fuck();
            t = ts.get();
            break;
        case '/':
        {
            double d = fuck();
            if (d == 0) throw runtime_error("Oops! Division by 0. Kiss <3");
            left /= d;
            t = ts.get();
            break;
        }
        case '%':
        {
            int i1 = narrow_cast<int>(left);
            int i2 = narrow_cast<int>(term());
            if (i2 == 0) throw runtime_error("Oops! Division by 0. Kiss <3");
            left = i1 % i2;
            t = ts.get();
            break;
        }
        default:
            ts.putback(t);     // put t back into the token stream
            return left;
        }
    }
}

// deal with + and -
double expression()
{
    double left = term();      // read and evaluate a Term
    Token t = ts.get();       // get the next token from token stream

    while (true) {
        switch (t.kind) {
        case '+':
            left += term();    // evaluate Term and add
            t = ts.get();
            break;
        case '-':
            left -= term();    // evaluate Term and subtract
            t = ts.get();
            break;
        default:
            ts.putback(t);     // put t back into the token stream
            return left;       // finally: no more + or -: return the answer
        }
    }
}

void calculate()
{

    while (cin)
        try {

        cout << prompt;
        Token t = ts.get();
        while (t.kind == print) t = ts.get();
        if (t.kind == quit) return;
        ts.putback(t);
        cout << result << statement() << '\n';
    }

    catch (exception& e) {
        cerr << e.what() << endl;
        clean_up_mess();
    }
}
               

int main()
{  
    try {
        define_name("pi", 3.1415926535);
        define_name("e", 2.7182818284);

        calculate();
        return 0;
    }

    catch (exception& e) {
        cerr << e.what() << endl;
        return 1;
    }

    catch (...) {
        cerr << "exception \n";
        return 2;
    }
}