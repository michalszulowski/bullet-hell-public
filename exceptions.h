#ifndef PROJ_1_SHIPS_EXCEPTIONS_H
#define PROJ_1_SHIPS_EXCEPTIONS_H

#include "sptr.h"
//#include "CharSeq.h"

struct Exception {
    const char* message;
    Exception* cause;

    Exception() {}
    Exception(const char* message) : message{message} {};
    Exception(Exception* cause) : cause{cause} {};
    Exception(const char* message, Exception* cause) : message{message}, cause{cause} {};
};

struct NoSuchElementException : public Exception {
    NoSuchElementException() {};
};

struct IncorrectIndexException : public Exception {
    IncorrectIndexException() {};
};

struct ObjectNotInitializedException : public Exception {
    ObjectNotInitializedException() {};
};

struct IllegalArgumentException : public Exception {
    IllegalArgumentException() {}
    IllegalArgumentException(const char* message) : Exception{message} {}
};

struct IllegalStateException : public Exception {
    IllegalStateException() {}
};

struct CharNotADigitException : public IllegalArgumentException {
    CharNotADigitException() {}
};

struct ResourceNotLoadedException : public Exception {
    ResourceNotLoadedException() {}
};

struct IllegalOperationException : public Exception {
    IllegalOperationException() {}
};

#endif //PROJ_1_SHIPS_EXCEPTIONS_H