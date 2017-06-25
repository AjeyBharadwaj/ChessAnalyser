#ifndef REPO_H
#define REPO_H

#include <iostream>
#include <string>

using namespace std;

class Repo {
public:
    Repo(string repoName);
    ~Repo();

    virtual string getNextMove() = 0;
    virtual string getPrevMove() = 0;
    virtual string getFirstMove() = 0;
    virtual string getLastMove() = 0;
    virtual int getMoveCount() = 0;

private:
    string repoFile;
};

#endif
