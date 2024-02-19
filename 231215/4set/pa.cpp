#include <iostream>
#include <fstream>
#include "grade.h"
using namespace std;

int main(int argc, char *argv[])
{
    int i = 0;
    int numOfScores = 0, numOfGroups = 0;
    int *scores = NULL;
    ifstream fin;
    grade *_grade = NULL;

    if (argc > 1)
    {
        fin.open(argv[1]);
        if (!fin.is_open())
        {
            cerr << "File " << argv[1] << " does not exist!" << endl;
            exit(0);
        }
        fin >> numOfScores >> numOfGroups;
        scores = new int[numOfScores];
        for (i = 0; i < numOfScores; i++)
            fin >> scores[i];
        fin.close();
    }
    else
    {
        cin >> numOfScores >> numOfGroups;
        scores = new int[numOfScores];
        for (i = 0; i < numOfScores; i++)
            cin >> scores[i];
    }

    _grade = new grade(numOfScores, scores, numOfGroups);
    _grade->printScores();
    cout << "Minimum error = " << _grade->minimumError() << endl;

    delete _grade;
    _grade = NULL;
    if (scores)
        delete[] scores;
    scores = NULL;
    return 0;
}