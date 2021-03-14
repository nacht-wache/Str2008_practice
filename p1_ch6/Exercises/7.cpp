/*
Write a grammar for logical expressions. A logical expression is much
like an arithmetic expression except that the operators are ! (not) , ~
(complement), & (and), I (or) , and ^ (exclusive or). ! and ~ are prefix
unary operators. A ^ binds tighter than a | (just as * binds tighter than +)
so that x|y^z means x|(y^z) rather than (x|y)^z. The & operator binds
tighter than ^ so that x^y&z means x^(y&z).
*/

/*

primary
1. !A = not A;
2. ~A = A is complement to B;
3. variable

term
1. case &:
2. case ^:
3. case |:

*/