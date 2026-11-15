#include <string>
using namespace std;

class Movie {
private:
    string n;
    double rt;

public:
    Movie();
    Movie(string a, double b);

    string name() const;
    double rating() const;
    bool getstart(string pre) const;
    bool operator<(const Movie& b) const;
};
