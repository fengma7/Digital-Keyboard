/* 
  Digital Keyboard
  GE1501 - Section 17
  Team 6 - Marcus Feng, Braxton Ersoy, Louis Foley, Win Tongtawee
  AN Edited Version of TeachMeSomething Laptop Keyboard Typing model TFT
*/

/*
PsuedoCode
Import libraries for touch screen
Caliberate touchscreen
Set up min and max pressure
Initliaze variables that will be used
void setup()
  Initalize touchscreen
  Initalize intro screen
  Initalize keyboard design
void loop()
  void waitTouch() 
    Set up the screen to choose which side is x-axis and which side is y-axis
    Set up touch screen to detect touch inputs and output it to x and y values
  void DetectButton()
    Create the XY coordinates that correspond to each symbol on the screen
void IntroScreen
  Create an intro screen that displays creators of project as well as where we got the idea and some of the code from
void drawKeyboard()
  Create the GUI for the actual keyboard (each letter and other buttons)
  Create the writing space and cursor locations
*/


#include <Adafruit_GFX.h>
#include <MCUFRIEND_kbv.h>
#include <TouchScreen.h>
MCUFRIEND_kbv tft;

//Calibrates the Screen
const int XP=8,XM=A2,YP=A3,YM=9; //240x320 ID=0x9341
const int TS_LEFT=68,TS_RT=956,TS_TOP=41,TS_BOT=927;

//Sets the Min and Max Pressures
#define MINPRESSURE 10
#define MAXPRESSURE 1200

//Creates Easy Colors to Use
#define BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF

//Intializes the Screen with Calibration
TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);
TSPoint tp;

//Counter Values 
int a = 0;
int b = 0;
int c = 0;

//Intializes Symbols That Will be in the Keyboard
String symbol[3][10] = {
  {"Q", "W", "E", "R", "T", "Y", "U", "I", "O", "P", },
  {"A", "S", "D", "F", "G", "H", "J", "K", "L", ";", },
  {"Z", "X", "C", "V", "B", "N", "M", ",", ".", "<", },
};

//Intializes X,Y Coordinates
int X,Y;

void setup() 
{
  Serial.begin(9600);
  tft.reset();
  tft.begin(0x9341);   //Intializes the Screen
  tft.setRotation(1);
  IntroScreen();
  draw_Keyboard();
  tft.setCursor(0,0);
}

void loop() 
{
  TSPoint p = waitTouch(); //Sets touch point detection with coordiante output
  tft.setCursor (a,b);
  tft.setTextSize (2);     //Sets cursor and text color
  tft.setTextColor(WHITE);
  DetectButton();
  delay(300);
}

TSPoint waitTouch() 
{
  TSPoint p;
  do
  {
    p = ts.getPoint();
    pinMode(XM, OUTPUT); //Detect touch input
    pinMode(YP, OUTPUT);
  }
  while ((p.z < MINPRESSURE) || (p.z > MAXPRESSURE)); //Pressure Circumstances
  p.y = map(p.y, TS_LEFT, TS_RT, 0, 320);
  p.x = map(p.x, TS_TOP, TS_BOT, 0, 240);  //Calibaration/Mapping out the Screen
  X = p.x;  //Sets X and Y to the touch positions
  Y = p.y;
  Serial.print(X); 
  Serial.print(',');  //Prints out Positions
  Serial.println(Y);
  return p;
}

void DetectButton()  //For all of Detect Button, each if statement is a button on the keyboard that represents some letter or button
{
  if (X > 50 && X < 80 && Y < 30)
  {
    tft.print("z");
  }
  else if(X > 50 && X < 80 && Y > 30 && Y < 60)
  {
    tft.print("x");
  }
  else if (X > 50 && X < 80 && Y > 60 && Y < 90)
  {
    tft.print("c");
  }
  else if (X > 50 && X < 80 && Y > 90 && Y < 120)
  {
    tft.print("v");
  }
  else if (X > 50 && X < 80 && Y > 120 && Y < 150)
  {
    tft.print("b");
  }
  else if (X > 50 && X < 80 && Y > 150 && Y < 180)
  {
    tft.print("n");
  }
  else if (X > 50 && X < 80 && Y > 180 && Y < 210)
  {
    tft.print("m");
  }
  else if (X > 50 && X < 80 && Y > 210 && Y < 240)
  {
    tft.print(",");
  }
  else if (X > 50 && X < 80 && Y > 240 && Y < 270)
  {
    tft.print(".");
  }
  else if (X > 50 && X < 80 && Y > 270)
  {
    a = a-12;
    tft.fillRect(a,b,12,20,BLACK);
    a = a-12;
    Serial.print("a=");
    Serial.println(a);
  }
  else if (X > 80 && X < 110 && Y < 30)
  {
    tft.print("a");
  }
  else if (X > 80 && X < 110 && Y > 30 && Y < 60)
  {
    tft.print("s");
  }
  else if (X > 80 && X < 110 && Y > 60 && Y < 90)
  {
    tft.print("d");
  }
  else if (X > 80 && X < 110 && Y > 90 && Y < 120)
  {
    tft.print("f");
  }
  else if (X > 80 && X < 110 && Y > 120 && Y < 150)
  {
    tft.print("g");
  }
  else if (X > 80 && X < 110 && Y > 150 && Y < 180)
  {
    tft.print("h");
  }
  else if (X > 80 && X < 110 && Y > 180 && Y < 210)
  {
    tft.print("j");
  }
  else if (X > 80 && X < 110 && Y > 210 && Y < 240)
  {
    tft.print("k");
  }
  else if (X > 80 && X < 110 && Y > 240 && Y < 270)
  {
    tft.print("l");
  }
  else if (X > 80 && X < 110 && Y > 270)
  {
    a=-12;
    b = b+20;
  }
  else if (X > 110 && X < 150 && Y < 30)
  {
    tft.print("q");
  }
   else if (X > 110 && X < 150 && Y > 30 && Y < 60)
  {
    tft.print("w");
  }
   else if (X > 110 && X < 150 && Y > 60 && Y < 90)
  {
    tft.print("e");
  }
   else if (X > 110 && X < 150 && Y > 90 && Y < 120)
  {
    tft.print("r");
  }
   else if (X > 110 && X < 150 && Y > 120 && Y < 150)
  {
    tft.print("t");
  }
   else if (X > 110 && X < 150 && Y > 150 && Y < 180)
  {
    tft.print("y");
  }
   else if (X > 110 && X < 150 && Y > 180 && Y < 210)
  {
    tft.print("u");
  }
   else if (X > 110 && X < 150 && Y > 210 && Y < 240)
  {
    tft.print("i");
  }
   else if (X > 110 && X < 150 && Y > 240 && Y < 270)
  {
    tft.print("o");
  }
   else if (X > 110 && X < 150 && Y > 270)
  {
    tft.print("p");
  }
   else if (X < 50 && Y > 215 && Y < 300)
  {
    tft.fillRect(0,0,320,100,BLACK);
    a=-12;
    b = 0;
  }
  a = a+12;
  if (a > 310)
  {
    b = b+20;
    a = 0;
  }
}

void IntroScreen()
{
  tft.fillScreen(BLACK);
  tft.setCursor(0,30);
  tft.setTextSize(2);
  tft.setTextColor(WHITE);
  tft.println("Arduino Keyboard");  //Displays an intro screen that has our names as well as the device and the reference used to actually build the code
  tft.println("Created By:"); 
  tft.println(" - Marcus");
  tft.println(" - Braxton");
  tft.println(" - Louis");
  tft.println(" - Win");
  tft.println("An Edited Version of");
  tft.println("TeachMeSomething Laptop");
  tft.println("Keyboard Typing model TFT"); //Provides reference used to build the code
  delay(5000);
}

void draw_Keyboard()
{
  tft.fillScreen(BLACK);
  tft.setTextSize(3);
  tft.setTextColor(BLACK);
  for(int j = 0; j < 3; j++)
  {
    for(int i = 0; i < 10; i++)
    {
      tft.fillRoundRect((i*32)+1, j*35+101, 31, 34, 3, CYAN); //Creates the GUI for the keyboard letters
      tft.setCursor(i*32+9, j*35+107);
      tft.print(symbol[j][i]);
    }
  }
  tft.fillRoundRect(289, 171, 31, 34, 3, 0Xfbef); //Crestes the GUI for the backspace
  tft.setTextColor(BLACK);
  tft.setTextSize(2);
  tft.setCursor(290,182);
  tft.print("<-");
  
  tft.fillRoundRect(289, 136, 31, 34, 3, YELLOW); //Crestes the GUI for the Enter
  tft.setTextColor(BLACK);
  tft.setTextSize(1);
  tft.setCursor(290,150);
  tft.print("Enter");

  tft.fillRoundRect(1, 206, 223, 34, 3, YELLOW); //Crestes the GUI for the Space
  tft.setTextColor(BLACK);
  tft.setTextSize(2);
  tft.setCursor(55, 215);
  tft.print("Space");

  tft.fillRoundRect(225, 206, 95, 34, 3, WHITE); //Crestes the GUI for the Reset
  tft.setTextColor(BLACK);
  tft.setTextSize(2);
  tft.setCursor(247, 217);
  tft.print("Reset");

  while(c < 5)
  {
    tft.setCursor(55,25);
    tft.setTextColor(WHITE);
    tft.setTextSize(2);
    tft.print("Write Something");
    delay(100);
    tft.fillRect(0, 0, 320, 100, BLACK); //Creates the blank space for the written text
    delay(100);
    c++;
  }
}
