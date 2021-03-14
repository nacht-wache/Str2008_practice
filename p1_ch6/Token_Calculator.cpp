#include <iostream>

using namespace std;

//errors list
class div_error {};
class bracket_error {};
class primary_error {};
class putback_full {};
class Bad_token {};

class Token {
public:
	char kind;
	double value;
	Token(char ch)
		:kind(ch), value(0) {}
	Token(char ch, double val)
		:kind(ch), value(val) {}
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

Token_stream::Token_stream()
	:full(false), buffer(0)
{

}
void Token_stream::putback(Token t)
{
	if (full == true) throw putback_full();
	buffer = t;
	full = true;
}
Token Token_stream::get()
{
	if (full) {
		full = false;
		return buffer;
	}
	
	char ch;
	cin >> ch;

	switch (ch) {
	case ';':
	case 'q':
	case '(': case ')': case '+': case '-': case '*': case '%': case '/':
		return Token(ch);
	case '.':
	case '0': case '1': case '2': case '3': case '4':
	case '5': case '6': case '7': case '8': case '9':
	{
		cin.putback(ch);
		double val;
		cin >> val;
		return Token('8', val);
	}
	default:
		throw Bad_token();
	}
}

Token_stream ts;
double expression();

double primary() {
	Token t = ts.get();
	switch (t.kind)
	{
	case '(':
	{
		double d = primary();
		t = ts.get();
		if (t.kind != ')') throw bracket_error();
		return d;
	}
	case '8':
		return t.value;
	default:
		throw primary_error();
	}
}
double term() {
	double left = primary();
	Token t = ts.get();
	while (true) {
		switch (t.kind) {
		case '*':
			left *= primary();
			t = ts.get();
			break;
		case '/':
		{	double d = primary();
			if (d == 0) throw div_error();
			left /= d;
			t = ts.get();
			break;
		}
		default:
			ts.putback(t);
			return left;
		}
	}
}
double expression() {
	double left = term();
	Token t = ts.get();
	while (true) {
		switch (t.kind) {
		case '+':
			left += term();
			t = ts.get();
			break;
		case '-':
			left -= term();
			t = ts.get();
			break;
		default:
			ts.putback(t);
			return left;
		}
	}

}


int main(){

	try {
		double val = 0;
		while (cin) {
			Token t = ts.get();

			if (t.kind == 'q') EXIT_SUCCESS;
			if (t.kind == ';')
				cout << "=" << val << endl;
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