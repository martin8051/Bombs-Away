#ifndef _SCORE_H
#define _SCORE_H
#include<vector>
#include<_digit.h>


class _score
{
    public:
        _score();
        virtual ~_score();
        int score;
        vector<_digit*> digits;
        void initScore(char*,int);
        void placeScore(float,float,float,float);
        void changeScore(int);
        void drawScore();

        void resizeScore(float,float);

    protected:

    private:
};

#endif // _SCORE_H
