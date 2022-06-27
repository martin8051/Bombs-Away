#include "_menuScene.h"

float randomFloat(float a, float b);
bool  playSounds(int soundType);
void showGOScore(bool isHighScore);
void initHighScore();

using namespace irrklang;

        _1inputs *kBMs1 = new _1inputs();                      //keyboard input object
        _1parallax *plxFloor1 = new _1parallax();              //parallax (background) object
        _1player *ply1 = new _1player();                       //player object
        _1enms   *enms = new _1enms[15];                       //this scene will have 15 re-spawning bombs
        _1textureLoader *enmsTex1 = new _1textureLoader();     //load enemy textures
        _1collisionFlag *hit1 = new _1collisionFlag();         //collision flag object
        _1health *health1 = new _1health();                    //health bar object
        _1lose *loseScreen1 = new _1lose();                    //losing screen object
        _1retry_or_menu *retryMenu1 = new _1retry_or_menu();   //retry screen object
        _1gameClock *digitOne1 = new _1gameClock(1);           //first digit for game clock
        _1gameClock *digitTwo1 = new _1gameClock(2);           //second digit for game clock
        _1continue *continueScreen1 = new _1continue();        //continue screen for game
        _1completed *completedScreen1 = new _1completed();     //completed screen for game
        _1pause *pause1 = new _1pause();                       //pause prompt in top left corner of scene
        _1pauseMenu *pauseMenu1 = new _1pauseMenu();           //pause menu that pops up when game is paused
        _1enms   *enms2 = new _1enms[25];                      //this scene will have 25 re-spawning bomb
// =====================================================================================================================
        _1enms    *enms3 = new _1enms[35];                      // bombs for lvl 3
        _gameOver *GOScreen = new _gameOver();              // Game over screen object
        /* Loading images*/
        _imageLoader *newHighScoreImage = new _imageLoader();
        _imageLoader *keepTryingImage = new _imageLoader();
        _imageLoader *highScoreImage = new _imageLoader();
        _imageLoader *trophy = new _imageLoader();
        _gameTimer *gameTimer = new _gameTimer(5,'B',0);
        _score *score = new _score();              // To show high score/ game over score
        ISoundEngine *gameSoundTrackEngine = createIrrKlangDevice(); // For background music
        ISoundEngine *gameSoundEffectsEngine = createIrrKlangDevice();  // For game sound effects
        ISoundEngine *gameOverSoundEngine = createIrrKlangDevice();     // For game over sound
        int highScore;                // Previous high score
        bool highScoreAdded = false; // To check whether New high score is added to text file or not
        bool isGOSoundPlayed = false;   // To stop repetition of game over sound
        int soundTrackNumber = 0;   // Determines the number of sound track which we want to play


void _menuScene::clearScene()        // resets positions and flags of levels 1-3
{
    sceneOver = false;
    ply1->numLives = 5;
    ply1->xPos = -0.3;
    ply1->zRotation = 0.0;
    ply1->xMin = ply1->yMin = 0.0;
    ply1->xMax = 1.0/10.0;
    ply1->yMax = 1.0/8.0;
    continueScreen1->yPos = -2.8;
    completedScreen1->yPos = 1.8;
    loseScreen1->yPos = 1.8;
    retryMenu1->yPos = -2.8;
    pauseMenu1->counter = 0;
    pauseMenu1->yPos = 3.0;

    ply1->runSpeed = 0.08;           //set player run speed back to original

    retryScreenActive = false;
    continueScreenActive = false;
    gamePauseActive = false;

    if (currentScene == 1)
    {

        for (int i = 0; i < 15; i++) {  //set all bombs move speeds back to original
        enms[i].yMove = -0.0009;
        enms[i].timerUnpause();     //unpause animation timer if bomb is exploding
        }
        digitTwo1->stopClock();
        digitTwo1->xMax = 1.0/ digitTwo1->frames;
        digitTwo1->xMin = 0.0;
        digitOne1->xMin = 6.0/digitOne1->frames;
        digitOne1->xMax = 7.0/digitOne1->frames;


    }else if (currentScene == 2)
    {
        for (int i = 0; i < 25; i++) {  //set all bombs move speeds back to original
        enms2[i].timerUnpause();     //unpause animation timer if bomb is exploding
        enms2[i].setSpeed();
        }
        digitTwo1->stopClock();
        digitTwo1->xMax = 1.0/ digitTwo1->frames;
        digitTwo1->xMin = 0.0;
        digitOne1->xMin = 6.0/digitOne1->frames;
        digitOne1->xMax = 7.0/digitOne1->frames;
    }else if (currentScene == 3)
    {
        for (int i = 0; i < 35; i++) {  //set all bombs move speeds back to original
        enms3[i].timerUnpause();     //unpause animation timer if bomb is exploding
        enms3[i].setSpeed();
        }
        gameTimer->score = 0;
        gameTimer->run = true;
        gameTimer->resume();

        highScoreImage->placeImage(-2.85,1.23,-4.05);
        highScoreImage->resizeImage(0.4,0.13);
        score->placeScore(-2.1,1.22,-4.0,0.07);
        score->resizeScore(0.07,0.12);
        newHighScoreImage->placeImage(-5,-5,-4.05);
        newHighScoreImage->resizeImage(2.0,0.8);
        // Initializes trophyImage -> placing it out of sight
        trophy->placeImage(-5,-5,-4.05);
        trophy->resizeImage(0.6,0.6);
        // Initializes keepTryingImage -> placing it out of sight
        keepTryingImage->placeImage(-5,-5,-4.05);
        keepTryingImage->resizeImage(2.0,0.8);

        GOScreen->xRotation, GOScreen->yRotation, GOScreen->zRotation = 0.0;
        GOScreen->xMin = GOScreen->yMin = 0.0;
        GOScreen->xMax = GOScreen->yMax = 1.0;
        GOScreen->xSize = 4.0;
        GOScreen->ySize = 2.0;
        GOScreen->xPos = -2.0;
        GOScreen->yPos = 3.0;
        GOScreen->zPos = -4.05;
        GOScreen->scrollSpeed = 0.001;

        for (int x = 0; x < 5; x++)
        {
        gameTimer->digits[x]->yMin = 0.0;
        gameTimer->digits[x]->yMax = 1.0;
        gameTimer->digits[x]->xSize = 0.22;
        gameTimer->digits[x]->ySize = 0.35;
        gameTimer->digits[x]->yPos = 1.3;
        gameTimer->digits[x]->zPos = -4.5;
        gameTimer->digits[x]->frames = 10;
        gameTimer->digits[x]-> xPos =( (-x*0.25) + 0.55);
        gameTimer->digits[x]-> xMin = 0.0;
        gameTimer->digits[x]-> xMax = 1.0;
        }
    }
}

_menuScene::_menuScene()
{
    //ctor
    screenWidth = GetSystemMetrics(SM_CXSCREEN);
    screenHeight = GetSystemMetrics(SM_CYSCREEN);

    livemenu = true;
    livelevel1 = false;
    livelevel2 = false;
    livelevel3 = false;

    doneloadingm = false;
    doneloading1 = false;
    doneloading2 = false;
    doneloading3 = false;

    gamePauseActive = false;
    retryScreenActive = false;
    continueScreenActive = false;
    currentScene = 0;

    outfile.open("progress.txt", ios::trunc);           // reset unlocked level back to none
    outfile << 1;
    outfile.close();
    menubypass = 0;
}

_menuScene::~_menuScene()
{
    //dtor
}
GLint _menuScene::initGL()
{
   glShadeModel(GL_SMOOTH);                             // to make graphics nicer
   glClearColor(1.0f,0.5f,0.0f,1.0f);                   // background color R,G,B,Alpha
   glClearDepth(1.0f);                                  // Depth Clearance
   glEnable(GL_DEPTH_TEST);
   glDepthFunc(GL_LEQUAL);
   _glLight Light(GL_LIGHT0);

    if(livemenu == true && doneloadingm == false)
    {
        delete kBMs,lnd,mens,help,lvlsel,HS,credits,d1,d2,d3,d4,d5,intro_1,intro_2,intro_3;

        kBMs = new _inputs();              // instance of inputs
        lnd = new _Landing();             // LANDING PAGE INSTANCE
        mens = new _menu();                  // MENU PAGE INSTANCE
        help = new _help();                  // HELP PAGE INSTANCE
        lvlsel = new _lvlSelect();      // create level selection page
        HS = new _highScore();          // create high score background
        credits = new _credits();

        d1 = new _hsDigit();              // digits for high score
        d2 = new _hsDigit();
        d3 = new _hsDigit();
        d4 = new _hsDigit();
        d5 = new _hsDigit();

        intro_1 = new _intro1 ();         // level 1,2,3 intro pages
        intro_2 = new _intro2 ();
        intro_3 = new _intro3 ();

       lnd->landingInit("images/Landing.png");              // initiate landing image
       mens->menuInit("images/mainMenu.png");               // initiate main menu image
       help->helpInit("images/help.png");                   // initiate help image
       HS->highScoreInit("images/highScorem.png");           // initiate high score
       credits->creditsInit("images/Credits.png");

       //check file to load correct level select pic -------
       int progress;

       progressfile.open("progress.txt");                   // open progress file and grab value
       progressfile >> progress;
       progressfile.close();

       switch(progress)                                     // load correct level select page depending on progress value
       {
           case 1: // level one is unlocked
            {
                lvlsel->levelInit("images/Lvl_None_Done.png");
                break;
            }
           case 2: // level 2 is unlocked
            {
                lvlsel->levelInit("images/Lvl_One_Done.png");
                break;
            }
           case 3: // level 3 is unlocked
            {
                lvlsel->levelInit("images/Lvl_All_Done.png");
                break;
            }
       }
       //------------- INITIATING HIGH SCORE DIGITS -------------------------------------
       string grab;                                 // grab value from score text file and save them right justified w/ leading 0's
       char store [5] = {48,48,48,48,48};
       scoref.open("HighScore.txt");
       scoref>>grab;
       scoref.close();

       int back = 4;

       for(int i = grab.length()-1; i >=0; i--)
       {
           store[back] = grab[i];
           back--;
       }
                                                    // initialize digits according to numerical values of score
       d1->hsDigitInit(store[0]);
       d2->hsDigitInit(store[1]);
       d3->hsDigitInit(store[2]);
       d4->hsDigitInit(store[3]);
       d5->hsDigitInit(store[4]);

       //---------------------- initiating intro levels pages ----------------------------------
       intro_1->_intro1Init("images/lvl1Intro.png");
       intro_2->_intro2Init("images/lvl2Intro.png");
       intro_3->_intro3Init("images/lvl3Intro.png");

       menubypass++;

       if(menubypass > 1)       // bypass landing, and menu page and go to lvl select
       {
           kBMs->progressfile.open("progress.txt");
           kBMs->progressfile >> kBMs->lvlunlocked;
           kBMs->progressfile.close();
           kBMs->inlanding = false;
           kBMs->inmenu = false;
           kBMs->inlvlselect = true;
           lnd->z = -15.0;
           mens->z = -15.0;
           mens->num = 1;
       }

       doneloadingm = true;
    }

    if(livelevel1 == true && doneloading1 == false)
    {
       digitTwo1->start();
       pauseMenu1->counter = 0;
       retryScreenActive = false;
       currentScene = 1;
       sceneOver = false;
       continueScreenActive = false;

       enmsTex1->loadTexture("images/bombs.png");    //load bomb image (enemies)
       plxFloor1->parallaxInit("images/city.png");   //load city image (background)
       ply1->initPlayer("images/ply.png");           //load character image
       health1->initHealth("images/health.png");     //load health bar
       loseScreen1->initLost("images/died.png");     //load death scene picture
       retryMenu1->initRetry("images/retry_or_menu.png"); //load retry picture
       digitOne1->initClock("images/digits.png");    //load first digit
       digitTwo1->initClock("images/digits.png");    //load second digit
       completedScreen1->initCompleted("images/completed.png");  //load completed screen
       continueScreen1->initContinueScreen("images/continue.png");//load continue screen
       pause1->initPause("images/pause.png");             //load pause prompt
       pauseMenu1->initPauseMenu("images/pauseMenu.png"); //load pause menu


      //initialize and randomly place all enemies (bombs)
      for (int i = 0; i < 15; i++) {
        enms[i].initEnemy(enmsTex1->tex);
        enms[i].placeEnemy(randomFloat(-2.95, 2.65), randomFloat(3.0, 6.0), -4.0);  //place enemy in random x/y positions
      }
        doneloading1 = true;
    }

    if(livelevel2 == true && doneloading2 == false)
    {
       digitTwo1->start();
       pauseMenu1->counter = 0;
       retryScreenActive = false;
       currentScene = 2;
       sceneOver = false;
       continueScreenActive = false;

       enmsTex1->loadTexture("images/bluebombs.png"); //load bomb image (enemies)
       plxFloor1->parallaxInit("images/night.png");  //load city image (background)
       ply1->initPlayer("images/ply.png");           //load character image
       health1->initHealth("images/health.png");     //load health bar
       loseScreen1->initLost("images/died.png");     //load death scene picture
       retryMenu1->initRetry("images/retry_or_menu.png"); //load retry picture
       digitOne1->initClock("images/digits.png");    //load first digit
       digitTwo1->initClock("images/digits.png");    //load second digit
       completedScreen1->initCompleted("images/completed.png");  //load completed screen
       continueScreen1->initContinueScreen("images/continue.png");//load continue screen
       pause1->initPause("images/pause.png");             //load pause prompt
       pauseMenu1->initPauseMenu("images/pauseMenu.png"); //load pause menu

      //initialize and randomly place all enemies (bombs)
      for (int i = 0; i < 25; i++) {
        enms2[i].initEnemy(enmsTex1->tex);
        enms2[i].placeEnemy(randomFloat(-2.95, 2.65), randomFloat(3.5, 8.0), -4.0);  //place enemy in random x/y positions
        enms2[i].setSpeed();                     //set randomized speed
        enms2[i].storeYmove = enms2[i].yMove;     //store value (needed for pauses)
      }
        doneloading2 = true;
    }

    if(livelevel3 == true && doneloading3 == false)
    {
    pauseMenu1->counter = 0;
    retryScreenActive = false;
    currentScene = 3;
    continueScreenActive = false;
    sceneOver = false;
    initHighScore();

    enmsTex1->loadTexture("images/redbombs.png"); //load bomb image (enemies)
    plxFloor1->parallaxInit("images/forrest.png");  //load city image (background)
    ply1->initPlayer("images/ply.png");           //load character image
    health1->initHealth("images/health.png");     //load health bar
    pause1->initPause("images/pause.png");             //load pause prompt
    pauseMenu1->initPauseMenu("images/pauseMenu.png"); //load pause menu
    gameTimer->initGameTimer("images/digits.png");        // load game Timer

    GOScreen->initGameOver("images/gameOver.png");         // load game overScreen
    // Initializes highScoreImage  -> placing it top-left below number of lives
    highScoreImage->initImage("images/highScore.png");
    highScoreImage->placeImage(-2.85,1.23,-4.05);
    highScoreImage->resizeImage(0.4,0.13);
    // Initializes score ( previous high score)
    score->initScore("images/digits.png",highScore);
    score->placeScore(-2.1,1.22,-4.0,0.07);
    score->resizeScore(0.07,0.12);
    // Initializes newHighScoreImage -> placing it out of sight
    newHighScoreImage->initImage("images/newHighScore.png");
    newHighScoreImage->placeImage(-5,-5,-4.05);
    newHighScoreImage->resizeImage(2.0,0.8);
    // Initializes trophyImage -> placing it out of sight
    trophy->initImage("images/trophy.png");
    trophy->placeImage(-5,-5,-4.05);
    trophy->resizeImage(0.6,0.6);
    // Initializes keepTryingImage -> placing it out of sight
    keepTryingImage->initImage("images/keepTrying.png");
    keepTryingImage->placeImage(-5,-5,-4.05);
    keepTryingImage->resizeImage(2.0,0.8);

    // Playing soundTrack one as default
    //glEnable(GL_COLOR_MATERIAL);


    //initialize and randomly place all enemies (bombs)
    for (int i = 0; i < 35; i++)
    {
        enms3[i].initEnemy(enmsTex1->tex);
        enms3[i].placeEnemy(randomFloat(-2.95, 2.65), enms3->RandFloat(3.5, 35.0), -4.0);  //place enemy in random x/y positions
        enms3[i].setSpeed();                     //set randomized speed
        enms3[i].storeYmove = enms3[i].yMove;     //store value (needed for pauses)
    }
        doneloading3 = true;
    }

   return true;
}

GLint _menuScene::drawScene()
{
    if(livemenu == true)
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Clear Screen And Depth Buffer
        glLoadIdentity();
    //drawing high score digit numbers ---------------------------------------------------------------
         glPushMatrix();
         glScaled(-1,1,1);
         glScalef(0.055,0.055,1.0);
         glTranslatef(7, 0, 0);
         d1->drawSquare(screenWidth,screenHeight);
         glPopMatrix();

         glPushMatrix();
         glScaled(-1,1,1);
          glScalef(0.055,0.055,1.0);
         glTranslatef(3.4, 0, 0);
         d2->drawSquare(screenWidth,screenHeight);
         glPopMatrix();

         glPushMatrix();
         glScaled(-1,1,1);
         glScalef(0.055,0.055,1.0);
         glTranslatef(-0.2, 0, 0);
         d3->drawSquare(screenWidth,screenHeight);
         glPopMatrix();

         glPushMatrix();
         glScaled(-1,1,1);
         glScalef(0.055,0.055,1.0);
         glTranslatef(-3.8, 0, 0);
         d4->drawSquare(screenWidth,screenHeight);
         glPopMatrix();

         glPushMatrix();
         glScaled(-1,1,1);
         glScalef(0.055,0.055,1.0);
         glTranslatef(-7.4, 0, 0);;
         d5->drawSquare(screenWidth,screenHeight);
         glPopMatrix();
    // drawing level 1,2,3 intro pages ---------------------------------------------------------------------
         glPushMatrix();
         glScaled(-1,1,1);
         glScalef(0.42,0.42,1.0);
         intro_1->drawSquare(screenWidth,screenHeight);
         glPopMatrix();

          glPushMatrix();
         glScaled(-1,1,1);
         glScalef(0.42,0.42,1.0);
         intro_2->drawSquare(screenWidth,screenHeight);
         glPopMatrix();

          glPushMatrix();
         glScaled(-1,1,1);
         glScalef(0.42,0.42,1.0);
         intro_3->drawSquare(screenWidth,screenHeight);
         glPopMatrix();

    // drawing high score page -----------------------------------------------------------------
         glPushMatrix();
         glScaled(-1,1,1);
         glScalef(0.42,0.42,1.0);
         HS->drawSquare(screenWidth,screenHeight);
         glPopMatrix();
    // drawing credits page --------------------------------------------------------------------
         glPushMatrix();
         glScaled(-1,1,1);
         glScalef(0.42,0.42,1.0);
         credits->drawSquare(screenWidth,screenHeight);
         glPopMatrix();
    // drawing help page -----------------------------------------------------------------------
         glPushMatrix();
         glScaled(-1,1,1);
         glScalef(.2,.4,1.0);
         help->drawSquare(screenWidth,screenHeight);
         glPopMatrix();
    //  drawing menu page ----------------------------------------------------------------------
         glPushMatrix();
         glScaled(-1,1,1);
         glScalef(.85,.85,1.0);
         mens->drawSquare(screenWidth,screenHeight);
         glPopMatrix();

    //  drawing landing page -------------------------------------------------------------------
         glPushMatrix();
         glScaled(-1,1,1);
         glScalef(0.83,0.83,1);
         lnd->drawSquare(screenWidth,screenHeight);
         glPopMatrix();
    // drawing level select page -----------------------------------------------------------------
     glPushMatrix();
         glScaled(-1,1,1);
         glScalef(1.25,1.25,1);
         lvlsel->drawSquare(screenWidth,screenHeight);
         glPopMatrix();
    }
    if(livelevel1 == true)
    {

        glPushMatrix();
        glPopMatrix();
     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Clear Screen And Depth Buffer
        glLoadIdentity();

        glPushMatrix();
         glTranslated(0,0,-5.2);              //placing objects
         glScalef(6.3,6.3,1);
         plxFloor1->drawSquare(screenWidth,screenHeight);    // draw background
        glPopMatrix();

        glPushMatrix();
         loseScreen1->drawLoseScreen();  //draw losing screen (placed out of sight initially
        glPopMatrix();

        glPushMatrix();
         ply1->actions();                //refresh actions
         ply1->drawPlayer();             //draw player
        glPopMatrix();

        glPushMatrix();
         health1->healthStatus(ply1->numLives);   //get player's health status
         health1->drawHealth();                  //draw health bar
        glPopMatrix();

        glPushMatrix();
         retryMenu1->drawRetyScreen();           //draw retry screen that slides into scene if player loses
        glPopMatrix();

        glPushMatrix();
         digitOne1->drawClock();                 //draw digit one
        glPopMatrix();

        glPushMatrix();
         digitTwo1->drawClock();                 //draw digit two
        glPopMatrix();

        glPushMatrix();
         completedScreen1->drawCompleted();      //draw completed screen that slides into scene if player wins
        glPopMatrix();

        glPushMatrix();
         continueScreen1->drawContinueScreen();  //draw continue screen that slides into scene if player wins
        glPopMatrix();

        glPushMatrix();
         pause1->drawPause();                    //draw pause instruction (top right of screen)
        glPopMatrix();

        glPushMatrix();
         pauseMenu1->drawPauseMenu();            //draw pause menu that comes into scene if game is paused
        glPopMatrix();

        digitTwo1->tickClock();                  //digit two is the digit on timer, so call its ticking function
        digitOne1->dependClock(digitTwo1->xMax, digitTwo1->clockFlip); //digit one depends on digit two's status, so call its depend function

        if(pauseMenu1->counter % 2 == 0)
        {
            gamePauseActive = false;
        } else{
            gamePauseActive = true;
        }

        //draw enemies
        for (int i = 0; i < 15; i++) {
            if (hit1->linearCollision((ply1->xPos + 0.215), ply1->yPos, enms[i].xPos, enms[i].yPos)) {   //if player collides w/ bomb, initiate explosion
                if (enms[i].bombStatus == 1) {  //bomb status ensures same bomb doesn't take away multiple lives
                    ply1->numLives--;            //decrease number of lives
                }
                enms[i].action = 2;             //action 2 = explosion
            }
            else if (hit1->floorCollision(enms[i].yPos)) {    //else if bomb collides with floor, just initiate explosion.
                enms[i].action = 2;             //action 2 = explosion
            }

            //test if player lost all lives
            if (didPlayerLose(ply1->numLives)) {
                deathScene(15); //call death scene. Parameter is the number of bombs in a scene
            }

            //test if scene timer is over
            if (didPlayerWin(digitOne1->xMin, digitTwo1->xMin)) {
                winScene(15);   //call win scene. Parameter is the number of bombs in a scene
            }

            glPushMatrix();
            enms[i].actions();     //call actions of current enemy
            enms[i].drawEnemy();   //draw current enemy
            glPopMatrix();
        }   //end for loop
    }

    if(livelevel2 == true)
    {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Clear Screen And Depth Buffer
	glLoadIdentity();

    glPushMatrix();
     glTranslated(0,0,-5.2);              //placing objects
     glScalef(6.3,6.3,1);
     plxFloor1->drawSquare(screenWidth,screenHeight);    // draw background
    glPopMatrix();

    glPushMatrix();
     loseScreen1->drawLoseScreen();  //draw losing screen (placed out of sight initially
    glPopMatrix();

    glPushMatrix();
     ply1->actions();                //refresh actions
     ply1->drawPlayer();             //draw player
    glPopMatrix();

    glPushMatrix();
     health1->healthStatus(ply1->numLives);   //get player's health status
     health1->drawHealth();                  //draw health bar
    glPopMatrix();

    glPushMatrix();
     retryMenu1->drawRetyScreen();           //draw retry screen that slides into scene if player loses
    glPopMatrix();

    glPushMatrix();
     digitOne1->drawClock();                 //draw digit one
    glPopMatrix();

    glPushMatrix();
     digitTwo1->drawClock();                 //draw digit two
    glPopMatrix();

    glPushMatrix();
     completedScreen1->drawCompleted();      //draw completed screen that slides into scene if player wins
    glPopMatrix();

    glPushMatrix();
     continueScreen1->drawContinueScreen();  //draw continue screen that slides into scene if player wins
    glPopMatrix();

    glPushMatrix();
     pause1->drawPause();                    //draw pause instruction (top right of screen)
    glPopMatrix();

    glPushMatrix();
     pauseMenu1->drawPauseMenu();            //draw pause menu that comes into scene if game is paused
    glPopMatrix();

    digitTwo1->tickClock();                  //digit two is the digit on timer, so call its ticking function
    digitOne1->dependClock(digitTwo1->xMax, digitTwo1->clockFlip); //digit one depends on digit two's status, so call its depend function

        if(pauseMenu1->counter % 2 == 0)
        {
            gamePauseActive = false;
        } else{
            gamePauseActive = true;
        }

    //draw enemies
    for (int i = 0; i < 25; i++) {
        if (hit1->linearCollision((ply1->xPos + 0.215), ply1->yPos, enms2[i].xPos, enms2[i].yPos)) {   //if player collides w/ bomb, initiate explosion
            if (enms2[i].bombStatus == 1) {  //bomb status ensures same bomb doesn't take away multiple lives
                ply1->numLives--;            //decrease number of lives
            }
            enms2[i].action = 2;             //action 2 = explosion
        }
        else if (hit1->floorCollision(enms2[i].yPos)) {    //else if bomb collides with floor, just initiate explosion.
            enms2[i].action = 2;             //action 2 = explosion
        }

        //test if player lost all lives
        if (didPlayerLose(ply1->numLives)) {
            deathScene(25); //call death scene. Parameter is the number of bombs in a scene
        }

        //test if scene timer is over
        if (didPlayerWin(digitOne1->xMin, digitTwo1->xMin)) {
            winScene(25);   //call win scene. Parameter is the number of bombs in a scene
        }

        glPushMatrix();
        enms2[i].actions2();     //call actions of current enemy
        enms2[i].drawEnemy();   //draw current enemy
        glPopMatrix();
    }   //end for loop
    }

    if(livelevel3 == true)
    {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Clear Screen And Depth Buffer
    glLoadIdentity();

    glPushMatrix();
    glTranslated(0,0,-5.2);              //placing objects
    glScalef(6.3,6.3,1);
    plxFloor1->drawSquare(screenWidth,screenHeight);    // draw background
    glPopMatrix();

    glPushMatrix();
    GOScreen->drawGameOver();  //draw game over screen (placed out of sight initially)
    glPopMatrix();


    glPushMatrix();
    ply1->actions();                //refresh actions
    ply1->drawPlayer();             //draw player
    glPopMatrix();

    glPushMatrix();
    health1->healthStatus(ply1->numLives);   //get player's health status
    health1->drawHealth();                  //draw health bar
    glPopMatrix();

    glPushMatrix();
    gameTimer->drawGameTimer();                 //draw game timer
    glPopMatrix();

    glPushMatrix();
    score->drawScore();                 //draw score(previous high score)
    glPopMatrix();

    glPushMatrix();
    newHighScoreImage->drawImage();                 //draw new high score image
    glPopMatrix();

    glPushMatrix();
    trophy->drawImage();                 //draw trophy image
    glPopMatrix();

    glPushMatrix();
    keepTryingImage->drawImage();                 //draw keep trying image
    glPopMatrix();

    glPushMatrix();
    highScoreImage->drawImage();                 //draw high score image
    glPopMatrix();

    glPushMatrix();
    pause1->drawPause();                    //draw pause instruction (top right of screen)
    glPopMatrix();

    glPushMatrix();
    pauseMenu1->drawPauseMenu();            //draw pause menu that comes into scene if game is paused
    glPopMatrix();

    // Runs in a loop
    gameTimer->changeScore();

    if(pauseMenu1->counter % 2 == 0)
        {
            gamePauseActive = false;
        } else{
            gamePauseActive = true;
        }

    //draw enemies
    for (int i = 0; i < 35; i++)
    {
        if (hit1->linearCollision((ply1->xPos + 0.215), ply1->yPos, enms3[i].xPos, enms3[i].yPos))     //if player collides w/ bomb, initiate explosion
        {
            if (enms3[i].bombStatus == 1)    //bomb status ensures same bomb doesn't take away multiple lives
            {
                ply1->numLives--;            //decrease number of lives
                playSounds(4);              // playing bomb collision sound
            }
            enms3[i].action = 2;             //action 2 = explosion
        }
        else if (hit1->floorCollision(enms3[i].yPos))      //else if bomb collides with floor, just initiate explosion.
        {
            enms3[i].action = 2;             //action 2 = explosion
        }

        //test if player lost all lives
        if (didPlayerLose(ply1->numLives))
        {
            deathScene3(35); //call death scene. Parameter is the number of bombs in a scene
        }

        glPushMatrix();
        enms3[i].actions();     //call actions of current enemy
        enms3[i].drawEnemy();   //draw current enemy
        glPopMatrix();
    }   //end for loop
    }
}

GLvoid _menuScene::reSizeScene(GLsizei width, GLsizei height)
{
    GLfloat aspectRatio = (GLfloat)width/(GLfloat) height; // ratio for window mode
    glViewport(0,0,width,height);                          // setting view port
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0,aspectRatio,0.1,100);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
int _menuScene::winMsg(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    if(livemenu == true)
    {
        switch (uMsg)
        {
            case WM_KEYDOWN: // WHAT TO DO WHEN A KEY IS PRESSED DOWN

                 kBMs->wParam = wParam;

                kBMs->keypressed(lnd, -15.0);                   // LANDING PAGE INPUTS AND HIDDEN Z VALUE
                kBMs->keypressed(mens, -15.0);                  // MENU PAGE INPUTS AND  HIDDEN Z VALUE
                kBMs->keypressed (help, -1.0, -15.0);           // HELP PAGE INPUTS AND OPEN/CLOSED Z VALUES
                kBMs->keypressed(HS, -1.0, -15.0);              // High score page background inputs
                kBMs->keypressed(credits, -1.0, -15.0);

                kBMs->keypressed(d1, -0.9, -15.0);              // High score digit's inputs
                kBMs->keypressed(d2, -0.9, -15.0);
                kBMs->keypressed(d3, -0.9, -15.0);
                kBMs->keypressed(d4, -0.9, -15.0);
                kBMs->keypressed(d5, -0.9, -15.0);

                kBMs->launchintro(intro_1, -1.0, -15.0);        // level 1 intro page inputs

                kBMs->launchintro(intro_2, -1.0, -15.0);        // level 2 intro page inputs

                kBMs->launchintro(intro_3, -1.0, -15.0);        // level 3 intro page inputs
                 break;

            case WM_KEYUP:
                 break;

            case WM_LBUTTONDOWN:
                kBMs->wParam = wParam;
                kBMs->keypressed(lnd, -15.0);           // LANDING PAGE INPUTS AND HIDDEN Z VALUE
                break;
            case WM_RBUTTONDOWN:
                kBMs->wParam = wParam;
                break;
            case WM_MBUTTONDOWN:
                kBMs->wParam = wParam;
                break;
        }
    }
    if(livelevel1 == true || livelevel2 == true )
    {
        switch (uMsg)
        {
            case WM_KEYDOWN:
                 kBMs1->wParam = wParam;
                 if (!sceneOver) {  //if scene is not over, allow for movement

                 if(currentScene == 1)
                 kBMs1->pause(pauseMenu1, ply1, enms, digitTwo1, gameTimer, 3.0, 0.0, currentScene);

                 if(currentScene == 2)
                 kBMs1->pause(pauseMenu1, ply1, enms2, digitTwo1, gameTimer, 3.0, 0.0, currentScene);


                 if (ply1->runSpeed != 0.0) {     //if scene is not over and game is not paused, allow parallax movement
                 kBMs1->keyEnv(plxFloor1,0.001);   //handling Env
                 }
                 kBMs1->keyPressed(ply1, currentScene);     // handling player movement
                 }
                 break;

            case WM_KEYUP:
                 kBMs1->keyUp(ply1);
                 break;
        }
    }else if (livelevel3 == true )
    {
         switch (uMsg)
        {
        case WM_KEYDOWN:
            kBMs1->wParam = wParam;
            if (!sceneOver)    //if scene is not over, allow for movement
            {
                if(wParam == VK_ESCAPE)
                {
                    playSounds(3);         // To play pause or resume sound
                }
                else if(wParam == VK_LEFT || wParam == VK_RIGHT)
                {
                   // playSounds(2);         // To play player move sound
                }
                kBMs1->pause(pauseMenu1, ply1, enms3, digitTwo1 ,gameTimer, 3.0, 0.0, currentScene);
                if (ply1->runSpeed != 0.0)       //if scene is not over and game is not paused, allow parallax movement
                {
                    kBMs1->keyEnv(plxFloor1,0.001);   //handling Env
                }
                kBMs1->keyPressed(ply1, currentScene);     // handling player movement
                if(wParam == VK_CONTROL)
                {
                    playSounds(1);    // to change the sound track
                }
            }
            break;

        case WM_KEYUP:
            kBMs1->wParam = wParam;
            kBMs1->keyUp(ply1);      //function to call what inputs are being let off
            break;
        }
    }
}
// ======================= LEVEL ONE DEFINITIONS OF OTHER STUFF ====================================
//returns random float between a and b.
//used for randomly placing bombs in scene.
float randomFloat(float a, float b) {
    float low, high;
    if (a < b) {
        low = a;
        high = b;
    }
    else {
        low = b;
        high = a;
    }
    float random = ((float) rand()) / (float) RAND_MAX;
    float difference = high - low;
    float rand = random * difference;
    return low + rand;
}

//scene for when player loses level
void _menuScene::deathScene(int numBombs) {
    if(currentScene == 1)
    {
        for (int i = 0; i < numBombs; i++) {    //loop moves all bombs out of sight and stops their movement
            enms[i].yMove = 0.0;
            enms[i].yPos = 8.0;
        }
    }

    if(currentScene == 2)
    {
        for (int i = 0; i < numBombs; i++) {    //loop moves all bombs out of sight and stops their movement
            enms2[i].yMove = 0.0;
            enms2[i].yPos = 8.0;
        }
    }
    digitTwo1->stopClock();                  //stop timer
    ply1->layDown();                         //lay down dead player
    loseScreen1->scrollDown();               //scroll down the "you died" screen
    retryMenu1->scrollUp();                  //scroll up the retry menu screen
    retryScreenActive = true;
}


//scene for when player wins level
void _menuScene::winScene(int numBombs)
{
    if(currentScene == 1)
    {
        for (int i = 0; i < numBombs; i++) {    //loop moves all bombs out of sight and stops their movement
            enms[i].yMove = 0.0;
            enms[i].yPos = 8.0;
        }
    }

    if(currentScene == 2)
    {
        for (int i = 0; i < numBombs; i++) {    //loop moves all bombs out of sight and stops their movement
            enms2[i].yMove = 0.0;
            enms2[i].yPos = 8.0;
        }
    }
    digitTwo1->stopClock();                  //stop timer
    ply1->runSpeed = 0.0;                    //run speed = 0 stops player and parallax movement
    completedScreen1->scrollDown();          //scroll completed screen down
    continueScreen1->scrollUp();             //scroll continue screen up
    continueScreenActive = true;
}

//function to test if player has lost all their lives
bool _menuScene::didPlayerLose(int lives) {
    if (lives <= 0) {
        sceneOver = true;
        return true;
    }
    else {
        return false;
    }
}

//function to test if player has beat the level
bool _menuScene::didPlayerWin(float one, float two) {
    if ((one < 0.05) && (two < 0.05)) { //if both digit sprites are at zero, then return true
        sceneOver = true;

      int grab;
      if ( currentScene == 2 || currentScene == 1)
       {
        progressfile.open("progress.txt");
        progressfile >> grab;
        progressfile.close();

        if(grab <= currentScene)
        {
            outfile.open("progress.txt", ios::trunc);
            outfile << (currentScene + 1);
            outfile.close();
        }
       }

       return true;
    }
    return false;
}

/* Play sounds according to sound type*/
bool playSounds(int soundType)
{
    if(soundType == 1) // For game background sound
    {
        gameSoundTrackEngine->removeAllSoundSources();
        switch(soundTrackNumber%4)
        {
        case 0:
            gameSoundTrackEngine->play2D("sounds/gameSound1.wav",true);
            break;
        case 1:
            gameSoundTrackEngine->play2D("sounds/gameSound2.wav",true);
            break;
        case 2:
            gameSoundTrackEngine->play2D("sounds/gameSound3.wav",true);
            break;
        case 3:
            gameSoundTrackEngine->play2D("sounds/gameSound4.wav",true);
            break;
        default :
            break;
        }
        soundTrackNumber++;
    }
    else if(soundType == 2)  // For walk sound
    {
        gameSoundEffectsEngine->play2D("sounds/walkSound.ogg",false);
    }
    else if(soundType == 3)  //For pause and resume sound
    {
        gameSoundEffectsEngine->play2D("sounds/pauseSound.wav",false);
    }
    else if(soundType == 4)  // For Bomb collision sound
    {
        gameSoundEffectsEngine->play2D("sounds/bombCollisionSound.wav",false);
    }
    else if(soundType == 5) // For game over sound
    {
        gameOverSoundEngine->play2D("sounds/gameOverSound.wav",false);
    }
    return true;
}

// Shows the game over score
void showGOScore(bool isHighScore)
{
    if(isHighScore) // If there is new high score achieved
    {
        score->placeScore(0.3,0.05,-4.0,0.25);
        score->resizeScore(0.25,0.40);
        score->changeScore(gameTimer->score); // Changes the score to current score
        newHighScoreImage->placeImage(-0.95,0.95,-4.05);
        trophy->placeImage(-0.35,0.50,-4.05);
        highScoreImage->placeImage(-5.0,-5.0,-4.05); // Move high score image out of sight
        gameTimer->rePosGameTimer(5.0,5.0);      // Move game timer image out of sight
    }
    else if(!isHighScore)
    {
        score->placeScore(0.3,0.10,-4.0,0.25);
        score->resizeScore(0.25,0.40);
        score->changeScore(gameTimer->score);    // Changes the score to current score
        keepTryingImage->placeImage(-0.95,0.55,-4.05);
        highScoreImage->placeImage(-5.0,-5.0,-4.05);   // Move high score image out of sight
        gameTimer->rePosGameTimer(5.0,5.0);   // Move game timer image out of sight
    }
}

// Reads the data from HighScore.txt as current high score and sets it to the highScore variable
// Which can be seen at top-left below number of lives
void initHighScore()
{
    highScoreAdded = false;
    fstream fin;
    int value;
    fin.open("HighScore.txt");
    while(fin >> value)
    {
        highScore = value;
    }
}

//scene for when player loses level
void _menuScene::deathScene3(int numBombs)
{
    retryScreenActive = true;

    for (int i = 0; i < numBombs; i++)      //loop moves all bombs out of sight and stops their movement
    {
        enms3[i].yMove = 0.0;
        enms3[i].yPos = 8.0;
    }
    gameTimer->stopGameTimer();                  //stop timer
    ply1->layDown();                         //lay down dead player

    // if game over sound is already played
    if(!isGOSoundPlayed)
    {
        gameSoundTrackEngine->drop();
        isGOSoundPlayed = playSounds(5);
    }

    // Checks if current score is greater than previous high score or not
    if(gameTimer->score > highScore)
    {
        showGOScore(true);

        // Checks if high score is already added or not in the text file
        if(!highScoreAdded)
        {
            fstream fout;
            fout.open("HighScore.txt");
            fout << gameTimer->score;
            highScoreAdded = true;
        }
    }
    else
    {
        showGOScore(false);
    }
    GOScreen->scrollDown();
}
