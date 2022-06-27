#include "_inputs.h"

_inputs::_inputs()
{
    //ctor
}

_inputs::~_inputs()
{
    //dtor
}
//----------------------------------------- MENU FUNCTION INPUTS ---------------------------------------------------------------------------

void _inputs::keypressed(_Landing* lnd, double zloc)                // instruction for landing page/ hides image to zloc value
{
    if((wParam == VK_RETURN || wParam == VK_LBUTTON )&& inlanding)  // if (ENTER) or (LEFT MOUSE CLICK) is pressed while in landing page
    {
        inlanding = false;                                          // set in landing page to false and in menu to true
        inmenu = true;
        lnd->z = zloc;                                              // change landing page's z pos to hide pic
    }
}

void _inputs::keypressed(_menu* mens, double zloc) // instruction for menu page, hides menu when start is selected
{

     if(wParam == 83 && (inmenu == true || inlvlselect == true) )   // IF 'S' pressed and inside menu, bypass and go to lvl select image behind it
    {

         mens->num ++;                                   //increase counter:  EVEN = HELP PAGE CLOSED   ODD = HELP PAGE OPEN
        if(mens->num % 2 == 1)                          // IF ODD = show pic by changing z pos
        {
            progressfile.open("progress.txt");
            progressfile >> lvlunlocked;
            progressfile.close();

            inlvlselect = true;
            inmenu = false;
            mens->z = zloc;
        } else                                          //IF EVEN = hide pick by changing z pos
        {
            inlvlselect = false;
            inmenu = true;
            mens->z = -2.0;
        }


                                     //change z to hide menu
    }else if(wParam == 69 && inmenu == true)  // if 'E' is pressed, exit program
    {
        exit(0);
    }
}
void _inputs::keypressed(_help* help, double frontn, double backn) // help page instructions
{
    if (wParam == 72 && (inmenu == true || inhelp == true) ) //  if 'H' is pressed and inside menu
    {
        help->num ++;                                   //increase counter:  EVEN = HELP PAGE CLOSED   ODD = HELP PAGE OPEN
        if(help->num % 2 == 1)                          // IF ODD = show pic by changing z pos
        {
            inhelp = true;
            inmenu = false;
            help->z = frontn;
        } else                                          //IF EVEN = hide pick by changing z pos
        {
            inhelp = false;
            inmenu = true;
            help->z = backn;
        }
    }
}

void _inputs::keypressed(_highScore* HS, double frontn, double backn) //highscore background page instructions
{

    if (wParam == 84 && (inmenu == true  || inhighscore == true)) //  if 'T' is pressed and inside menu
    {
        HS->num ++;                                   //increase counter:  EVEN = HIGHSCORE PAGE CLOSED   ODD = HIGHSCORE PAGE OPEN
        if(HS->num % 2 == 1)                          // IF ODD = show pic by changing z pos
        {
            inhighscore = true;
            inmenu = false;
            HS->z = frontn;

        } else                                         // IF EVEN = hide pic by changing z pos
        {
            inhighscore = false;
            inmenu = true;
            HS->z = backn;
        }
    }
}
void _inputs::keypressed(_credits* credits, double frontn, double backn) // credits page background instructions
{
    if (wParam == 67 && (inmenu == true  || incredits == true)) //  if 'C' is pressed and inside menu
    {
        credits->num ++;                                   //increase counter:  EVEN = CREDITS PAGE CLOSED   ODD = CREDITS PAGE OPEN
        if(credits->num % 2 == 1)                          // IF ODD = show pic by changing z pos
        {
            incredits = true;
            inmenu = false;
            credits->z = frontn;

        } else                                         // IF EVEN = hide pic by changing z pos
        {
            incredits = false;
            inmenu = true;
            credits->z = backn;
        }
    }
}


// -------------------------------- LEVEL INTRO INSTRUCTIONS / LEVEL SCENE LAUNCH -----------------------------------------------------------------

void _inputs::launchintro(_intro1* intro, double frontn, double backn) // level 1 intro page instructions
{
        if (wParam == 49 && ( (inIntro_1 == true) || (inlvlselect == true && inIntro_2 == false && inIntro_3 == false) ) ) //if '1' is pressed & in level selection & other intros !open
    {

        intro->num ++;                                                                        // increase COUNTER   EVEN = show   ODD = hide
        if(intro->num % 2 == 1)                                                               // if ODD display level 1 intro page, set bool to true
        {
            inlvlselect = false;
            inIntro_1 = true;
            intro->z = frontn;
        } else                                                                                // if EVEN hide level 1 intro page and set bool to false
        {
            inlvlselect = true;
            inIntro_1 = false;
            intro->z = backn;
        }
    }
}


void _inputs::launchintro(_intro2* intro, double frontn, double backn) // level 2 intro page instructions
{
        if(wParam == 50 && ( (inIntro_2 == true) || (inlvlselect == true && inIntro_1 == false && inIntro_3 == false && lvlunlocked >= 2) ) )//if '2' is pressed & in level selection & other intros !open
    {
        intro->num ++;                                                     // increase COUNTER   EVEN = show   ODD = hide
        if(intro->num % 2 == 1)                                            // if ODD display level 2 intro page, set bool to true
        {
            inlvlselect = false;
            inIntro_2 = true;
            intro->z = frontn;

        } else                                                             // if EVEN hide level 2 intro page and set bool to false
        {
            inlvlselect = true;
            inIntro_2 = false;
            intro->z = backn;
        }
    }
}


void _inputs::launchintro(_intro3* intro, double frontn, double backn) // level 3 intro page instructions
{
        if (wParam == 51 && ( ( inIntro_3 == true) || ( inlvlselect == true && inIntro_1 == false && inIntro_2 == false && lvlunlocked >= 3)) ) //if '3' is pressed & in level selection & other intros !open
    {
        intro->num ++;                                                   // increase COUNTER   EVEN = show   ODD = hide
        if(intro->num % 2 == 1)                                          // if ODD display level 3 intro page, set bool to true
        {
            inlvlselect = false;
            inIntro_3 = true;
            intro->z = frontn;

        } else                                                          // if EVEN hide level 3 intro page and set bool to false
        {
            inlvlselect = true;
            inIntro_3 = false;
            intro->z = backn;
        }
    }
}



// -----------------------------  HIGH SCORE DIGIT INSTRUCTIONS -----------------------------------------------------------------------------------------


void _inputs::keypressed(_hsDigit* DS, double frontn, double backn) // instructions for Digit of highscore, same as high score background
{
      if (wParam == 84 && (inmenu == true || inhighscore == true) ) //  WHAT TO DO IF 'T' KEY IS PRESSED
    {
        DS->num ++;                                      //increase counter  EVEN = digits hidden   ODD = digits shown
        if(DS->num % 2 == 1)                             // if ODD show digit
        {
            DS->z = frontn;

        } else                                           //if EVEN hide digit
        {
            DS->z = backn;
        }
    }
}

//----------------------------------------------------------------------------------------------------------------------------------------------


