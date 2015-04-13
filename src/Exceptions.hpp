#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP

#include <exception>

using namespace std;

struct NoEnoughSpaceInInt : public exception {
    NoEnoughSpaceInInt(int base_pairs) : base_pairs(base_pairs) { }
    const char *what() const throw() {
        return string("Tried to pack " + to_string(base_pairs) + " base pairs in " +
                to_string(sizeof(int)*8) + " bits integer").c_str();
    }

    protected:
        int base_pairs;
};

struct CannotOpenInstanceFileError : public exception {
    CannotOpenInstanceFileError(string filename) : filename(filename) { }
    const char *what() const throw() {
        return string("Cannot open instance file: " + filename + ":\nIt's a valid path?").c_str();
    }

    protected:
        string filename;
};

#endif  /* EXCEPTIONS_HPP */
