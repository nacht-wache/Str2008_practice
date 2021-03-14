#include <iostream>

using namespace std;

//errors list
class div_error {};
class bracket_error {};
class primary_error {};
class putback_full {};
class Bad_token {};
//------------------------------------------------------------------------------

class Token{
public:
    char kind;        // what kind of token
    double value;     // for numbers: a value 
    Token(char ch)    // make a Token from a char
        :kind(ch), value(0) { }
    Token(char ch, double val)     // make a Token from a char and a double
        :kind(ch), value(val) { }
};


class Token_stream {
public:
    Token_stream();   
    Token get();     
    void putback(Token t);    
private:
    bool full;      
    Token buffer;     
};

//------------------------------------------------------------------------------


Token_stream::Token_stream()
    :full(false), buffer(0)    
{
}

//------------------------------------------------------------------------------

void Token_stream::putback(Token t)
{
    if (full) throw putback_full();
    buffer = t;       
    full = true;      
}

//------------------------------------------------------------------------------

Token Token_stream::get()
{
    if (full) {       
        full = false;
        return buffer;
    }

    char ch;
    cin >> ch;   

    switch (ch) {
    case '=':    // for "print"
    case 'x':    // for "quit"
    case '(': case ')': case '+': case '-': case '*': case '/':
        return Token(ch);        
    case '.':
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '9':
    {
        cin.putback(ch);         // put digit back into the input stream
        double val;
        cin >> val;              // read a floating-point number
        return Token('8', val);   // let '8' represent "a number"
    }
    default:
        throw Bad_token();
    }
}

//------------------------------------------------------------------------------

Token_stream ts;       

//------------------------------------------------------------------------------

double expression();    

//------------------------------------------------------------------------------

double primary()
{
    Token t = ts.get();
    switch (t.kind) {
    case '(':    // handle '(' expression ')'
    {
        double d = primary();
        t = ts.get();
        if (t.kind != ')') throw bracket_error();
            return d;
    }
    case '8':            // we use '8' to represent a number
        return t.value;  // return the number's value
    default:
        throw primary_error();
    }
}

//------------------------------------------------------------------------------

// deal with *, /, and %
double term()
{
    double left = primary();
    Token t = ts.get();        // get the next token from token stream

    while (true) {
        switch (t.kind) {
        case '*':
            left *= primary();
            t = ts.get();
            break;
        case '/':
        {
            double d = primary();
            if (d == 0) throw div_error();
            left /= d;
            t = ts.get();
            break;
        }
        default:
            ts.putback(t);     // put t back into the token stream
            return left;
        }
    }
}

//------------------------------------------------------------------------------

// deal with + and -
double expression()
{
    double left = term();      // read and evaluate a Term
    Token t = ts.get();        // get the next token from token stream

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

//------------------------------------------------------------------------------

int main() {
    try
    {
        double val = 0;
        
        cout << "Welcome to our simple calculator.\n"
             << "Please enter expressions using floating point numbers.\n"
             << " '+', '-', '*' and '/' are available. print 'x' to exit and '=' to make a calculation.\n";
        
        while (cin) {
            Token t = ts.get();

            if (t.kind == 'x') return EXIT_SUCCESS;
            if (t.kind == '=')        // '=' for "print now"
                cout << val << '\n';
            else
                ts.putback(t);
            val = expression();
        }
    }
    catch (div_error) {
        cout << "Oops! Division by 0. Kiss <3" << endl;
        return EXIT_FAILURE;
    }

    catch (bracket_error) {
        cout << "Oops! Missing ')'. Kiss <3" << endl;
        return EXIT_FAILURE;
    }

    catch (primary_error) {
        cout << "Oops! No primary has been read. Kiss <3" << endl;
        return EXIT_FAILURE;
    }

    catch (putback_full) {
        cout << "Oops! IDK. Kiss <3" << endl;
        return EXIT_FAILURE;
    }

    catch (Bad_token) {
        cout << "Oops! Bad input. Kiss <3" << endl;
        return EXIT_FAILURE;
    }
}

//------------------------------------------------------------------------------