/*

Look at the headache-inducing last example of §8.4.
Indent it properly and explain the meaning of each construct.
Note that the example doesn't do anything meaningful; it is pure obfuscation.

*/

struct X {             // begin struct X

void f(int x) {        // begin function 'f' of struct 'X' with parameter x
    struct Y {         // begin struct 'Y'
        int f() {      // begin function 'f' of struct 'Y'
            return 1;  // return 'true'
        }              // end function 'f' of struct 'Y'

        int m;         // declare variable 'm' of struct Y
    };                 // end struct Y

    int m;             // declare variable m;
    m=x;               // assigne 'x' (line 11: parameter) to 'm'
    Y m2;              // declare m2 of type 'Y'
    return f(m2.f());  // f(return line 14) regardless of parameter 'x'
}


int m;                 // declare 'm' of struct X
void g(int m) {        // begin function 'g' with parameter 'm'
    if (m){            // if int>bool true
        f(m+2);        // call recursive function 'f' of struct 'X'
                       // return line 23
    }
    else {
        g(m+2);        // call itself only once with parameter 'm' + 2
                       // only if m == 0;
    }
}                      // end function 'g' of struct X

X() {                  // defenition of empty function 'X' of struct X

}                      // end function 'X' of struct 'X'

void m3() {            // defenition of empty function 'm3' of struct X

}                      // end function 'm3' of struct X

void main() {          // defenition of function 'main'
                       // of struct 'X'
    X a;               // declaration of 'a' of type 'X'
    a.f(2);            // call of function 'f' of struct X
                       // with parameter 2
                       // return line 14; return true regardless of parameter
}
};                  // end struct X;
