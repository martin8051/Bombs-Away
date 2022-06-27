#ifndef _INPUTS_H
#define _INPUTS_H

#include<windows.h>
#include<_Landing.h>
#include <_menu.h>
#include <_help.h>
#include <_lvlSelect.h>
#include <_highScore.h>
#include <fstream>
#include <_hsDigit.h>
#include <GL/glut.h>
#include <_intro1.h>
#include <_intro2.h>
#include <_intro3.h>
#include <_credits.h>

class _inputs
{
    public:
        _inputs();
        virtual ~_inputs();

        //------------------------------------------ FLAG VALUES ---------------------------------------------------------
        bool inmenu = false;             // boolean values used to keep track of where you are: used restrict key inputs
        bool inpause = false;
        bool inlanding = true;
        bool inlvlselect = false;
        bool inhelp = false;
        bool inhighscore = false;
        bool incredits = false;
        ifstream progressfile;          // used to store value into lvlunlocked int variable below
        int  lvlunlocked = 1;  //  1 = 1 unlocked , 2 = 1/2 unlocked , 3 = all unlocked, read this from progress.txt
        bool inIntro_1 = false;
        bool inIntro_2 = false;
        bool inIntro_3 = false;
        int  menupos;
        //--------------------------------------------------------------------------------------------------------------
        void keyUp();
        //--------------------------------------------- GENERAL MENU PAGES ----------------------------------------------------------
        void keypressed(_Landing *, double);                   // LANDING INPUTS, DOUBLE TO STORE Z LOCATION TO HIDE LANDING
        void keypressed(_menu *, double);                      // MENU INPUTS     DOUBLE USED FOR Z LOCATION TO HIDE MENU
        void keypressed(_help *, double, double);              // HELP INPUTS  DOUBLE,DOUBLE = Z POSITIONS VISABLE/HIDDEN HELP PAGE
        void keypressed(_highScore *, double, double);         // used to present high score page background
        void keypressed(_hsDigit *, double, double);           // used to present high score digits one by one
        void keypressed(_credits*, double, double);            // used to present the credits page

        //--------------------------------- CODE FOR INTRO LVLS / SELECTING LEVEL -----------------------------------------

        void launchintro(_intro1 *, double, double); // use this bring up intro 1

        void launchintro(_intro2 *, double, double);// use to bring up intro 2

        void launchintro(_intro3 *, double, double);// used to bring up intro 3

        //-------------------------------------------------------------------------------------------------------------------
        WPARAM wParam;

    protected:

    private:
};

#endif // _INPUTS_H
