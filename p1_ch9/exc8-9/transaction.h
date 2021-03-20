#ifndef TRANSACTION_H
#define TRANSACTION_H
#include "book.h"
#include "patron.h"
#include "date.h"

#include <iostream>
#include <vector>

struct Transaction {
    Book book;
    Patron patron;
    Date date;
};

#endif // TRANSACTION_H
