#ifndef __GRADE_H__
#define __GRADE_H__

class grade
{
private:
    int num;
    int *scores;
    int numOfGroups;

    // Declare member variables or functions here if you need...
public:
    grade(int n, int *s, int g);
    ~grade();
    void printScores();

    int minimumError(void);
};

#endif
