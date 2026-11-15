#include "movies.h"

Movie::Movie() {
    n = "";
    rt = 0;
}

Movie::Movie(string a, double b) {
    n = a;
    rt =b;
}

string Movie::name() const {
    return this->n;
}

double Movie::rating() const {
    return rt;
}

bool Movie::getstart(string pre) const {
    return (!n.compare(0, pre.size(), pre));
}

bool Movie::operator<(const Movie& b) const {
    return n < b.n;
}
