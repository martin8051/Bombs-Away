#ifndef _MENUSCENE_H
#define _MENUSCENE_H

#include <windows.h>
#include <GL/glut.h>
#include <iostream>
#include <_glLight.h>
#include <_inputs.h>
#include <_Landing.h>
#include <_menu.h>
#include <_help.h>
#include <_lvlSelect.h>
#include <fstream>
#include <_highScore.h>
#include <_hsDigit.h>
#include <_intro1.h>
#include <_intro2.h>
#include <_intro3.h>
#include <_credits.h>
#include <string>
// ================= LEVEL ONE HEADERS ============
#include <_1glLight.h>
#include <_1inputs.h>
#include <_1parallax.h>
#include <_1player.h>
#include <_1enms.h>
#include <_1collisionFlag.h>
#include <_1health.h>
#include <_1lose.h>
#include <_1retry_or_menu.h>
#include <_1gameClock.h>
#include <_1completed.h>
#include <_1continue.h>
#include <_1pause.h>
#include <_1pauseMenu.h>
//=================================================
#include<_digit.h>
#include<_gameOver.h>
#include<_score.h>
#include<_gameTimer.h>
#include<_imageLoader.h>
#include<bits/stdc++.h>
#include<SNDS/irrKlang.h>

using namespace std;

class _menuScene
{
    public:
        _menuScene();                            // constructor
        virtual ~_menuScene();                   // Deconstructor
        GLint initGL();                          // initialize OpenGL
        GLint drawScene();                       // Renderer
        GLvoid reSizeScene(GLsizei, GLsizei);    // screen size changes
// ================== MENU instances =============================================================================
        int menubypass;
        ifstream progressfile;                      // used to grab progress levels unlocked
        ifstream scoref;                             // used to grab high score
        ofstream outfile;
        _inputs *kBMs = new _inputs();              // instance of inputs
        _Landing *lnd = new _Landing();             // LANDING PAGE INSTANCE
        _menu *mens = new _menu();                  // MENU PAGE INSTANCE
        _help *help = new _help();                  // HELP PAGE INSTANCE
        _lvlSelect *lvlsel = new _lvlSelect();      // create level selection page
        _highScore *HS = new _highScore();          // create high score background
        _credits *credits = new _credits();

        _hsDigit *d1 = new _hsDigit();              // digits for high score
        _hsDigit *d2 = new _hsDigit();
        _hsDigit *d3 = new _hsDigit();
        _hsDigit *d4 = new _hsDigit();
        _hsDigit *d5 = new _hsDigit();

        _intro1 *intro_1 = new _intro1 ();         // level 1,2,3 intro pages
        _intro2 *intro_2 = new _intro2 ();
        _intro3 *intro_3 = new _intro3 ();
 // ======================================== LEVEL ONE STUFF ==================================================================


        bool didPlayerLose(int);        //bool function to test if player lost
        bool didPlayerWin(float, float);//bool function to test if player won
        void deathScene(int);           //death scene protocol when player loses
        void winScene(int);              //win scene protocol when player wins
        bool sceneOver;                  //flag for if scene is over
        void deathScene3(int numBombs);
 // ============================================================================================================================
        bool livemenu;
        bool livelevel1;
        bool livelevel2;
        bool livelevel3;

        bool doneloadingm;
        bool doneloading1;
        bool doneloading2;
        bool doneloading3;

        bool gamePauseActive;
        bool retryScreenActive;
        bool continueScreenActive;
        void clearScene();
        int  currentScene;

        int winMsg(HWND, UINT, WPARAM, LPARAM);	 // Callback of inputs

        float screenHeight, screenWidth;         // to map background images
    protected:
    private:
};

#endif // _MENUSCENE_H
