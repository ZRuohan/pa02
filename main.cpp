// Winter'24
// Instructor: Diba Mirza
// Student name:
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <vector>
#include <cstring>
#include <algorithm>
#include <limits.h>
#include <iomanip>
#include <set>
#include <queue>
#include <sstream>
using namespace std;

#include "utilities.h"
#include "movies.h"

bool parseLine(string &line, string &movieName, double &movieRating);
bool cmsort(const Movie& m1, const Movie& m2);

int main(int argc, char** argv){
    if (argc < 2){
        cerr << "Not enough arguments provided (need at least 1 argument)." << endl;
        cerr << "Usage: " << argv[ 0 ] << " moviesFilename prefixFilename " << endl;
        exit(1);
    }

    ifstream movieFile (argv[1]);

    if (movieFile.fail()){
        cerr << "Could not open file " << argv[1];
        exit(1);
    }

    // Create an object of a STL data-structure to store all the movies\

    set<Movie> ms;
    string line, movieName;
    double movieRating;

    // Read each file and store the name and rating
    while (getline (movieFile, line) && parseLine(line, movieName, movieRating)){
            // Use std::string movieName and double movieRating
            // to construct your Movie objects
            // cout << movieName << " has rating " << movieRating << endl;
            // insert elements into your data structure
            Movie m(movieName, movieRating);
            ms.insert(m);
    }

    movieFile.close();

    if (argc == 2){
            //print all the movies in ascending alphabetical order of movie names
            for (auto it=ms.begin(); it!=ms.end(); it++) {
              cout << it->name() << " "<< it->rating() << endl;
            }
            return 0;
    }

    ifstream prefixFile (argv[2]);

    if (prefixFile.fail()) {
        cerr << "Could not open file " << argv[2];
        exit(1);
    }

    vector<string> pfx;
    while (getline (prefixFile, line)) {
        if (!line.empty()) {
            pfx.push_back(line);
        }
    }

    //  For each prefix,
    //  Find all movies that have that prefix and store them in an appropriate data structure
    //  If no movie with that prefix exists print the following message
    vector<string> bp;
    vector<Movie> bm;

    for (int i = 0; i < pfx.size(); i++) {
    string pre = pfx[i];
    vector<Movie> eq;

    Movie j(pre, 0.0);


        auto it = ms.lower_bound(j);//

    //  for (auto it=ms.begin(); it !=ms.end(); it++) {
    while(it !=ms.end() && it->getstart(pre)){
        eq.push_back(*it);
        it++;
    }
    //auto it = ms.lower_bound(i)
        //  if () {


    if (eq.empty()) {
        cout << "No movies found with prefix " <<pre << endl;
    }

    else {
        sort(eq.begin(), eq.end(), cmsort);

        for (int j= 0; j < eq.size(); j++) {
            cout << eq[j].name() << " " << eq[j].rating() << endl;

        }
          bp.push_back(pre);
          bm.push_back(eq[0]);
      }

    }

    //  For each prefix,
    //  Print the highest rated movie with that prefix if it exists.
    for (int i = 0; i < bm.size(); i++) {
    cout << "Best movie with prefix " << bp[i] << " is: " << bm[i].name() << " with rating " << std::fixed << std::setprecision(1) << bm[i].rating() << endl;
  }

    return 0;
}

/* Add your run time analysis for part 3 of the assignment here as commented block*/

//Analysis, proof:
  //Time
    //Analysis: For Worst Patr2,we:
      //1.check each, and do cmp, Oln.
      //2.Sort for match, so in max k elements, and do this is Okllogk(Since we need assume all same rating to cmp the name, thus l multiplied)
      //3.iterate m
      //Concl: So it should be O(m(n+kl*logk))
  //Space
      //1. need O(kl) for eq to store names
      //2. we got bp,bm sowe have O(2ml) since we assumed that each p is as long as m here, so 2ml, and constant non-reserve, so
      //Concl: O(ml+kl), or((m+k)l)

  //Tradeoff
    // I think f

bool parseLine(string &line, string &movieName, double &movieRating) {
    int commaIndex = line.find_last_of(",");
    movieName = line.substr(0, commaIndex);
    movieRating = stod(line.substr(commaIndex+1));
    if (movieName[0] == '\"') {
        movieName = movieName.substr(1, movieName.length() - 2);
    }
    return true;
}




bool cmsort(const Movie& m1, const Movie& m2) {
    if ((m1.rating()!=m2.rating())) {
        return m1.rating() >
        m2.rating();
    }
    //return m1.name() > m2.name();
      //return m1.name() > m2.name();
    return (m1.name() < m2.name());
}
