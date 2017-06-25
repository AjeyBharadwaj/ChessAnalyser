#ifndef PGNREPO_H
#define PGNREPO_H

#include <iostream>
#include <string>

#include "../inc/Repo.h"

using namespace std;

class PGNRepo : public Repo {
public:
    PGNRepo(string repoName);

private:
    string *moves;
    int count;
};


#endif
