
#include <U8g2lib.h>
#include "ArduinoLowPower.h"

U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);

#define U8LOG_WIDTH 23
#define U8LOG_HEIGHT 6
uint8_t u8log_buffer[U8LOG_WIDTH*U8LOG_HEIGHT];
U8G2LOG u8g2log;

void bootsequence();

void clearOLED();

void curser();

int r;
int p;

const char MeatString[] PROGMEM = {"\"They're made out of \n\meat.\"\n\
\n\
  \"Meat\?\"\n\
\n\
\"Meat. They're made out of meat.\"\n\
\n\
  \"Meat\?\"\n\
\n\
\"There's no doubt about it. We picked several from different parts of the planet, took them aboard our recon \n\ vessels, probed them\n\ all the way through. \n\They're completely\n\ meat.\"\n\
\n\
  \"That's impossible.\n\ What about the radio\n\ signals\? The messages to the stars.\"\n\
\n\
\"They use the radio\n\ waves to talk, but the signals don't come\n\ from them. The signals come from machines.\"\n\
\n\
  \"So who made the\n\ machines\? That's who\n\ we want to contact.\"\n\
\n\
\"They made the\n\ machines. That's what I'm trying to tell you. Meat made the\n\ machines.\"\n\
\n\
  \"That's ridiculous.\n\ How can meat make a\n\ machine\? You're asking me to believe in\n\ sentient meat.\"\n\
\n\
\"I'm not asking you,\n\ I'm telling you. These creatures are the only sentient race in the\n\ sector and they're\n\ made out of meat.\"\n\
\n\
  \"Maybe they're like\n\ the Orfolei. You know, a carbon-based\n\ intelligence that goes through a meat stage.\"\n\
\n\
\"Nope. They're born\n\ meat and they die\n\ meat. We studied them for several of their\n\ life spans, which\n\ didn't take too long. Do you have any idea\n\ the life span of\n\ meat?\"\n\
\n\
  \"Spare me. Okay,\n\ maybe they're only\n\ part meat. You know,\n\ like the Weddilei. A\n\ meat head with an\n\ electron plasma brain inside.\"\n\
\n\
\"Nope. We thought of\n\ that, since they do\n\ have meat heads like\n\ the Weddilei. But I\n\ told you, we probed\n\ them. They're meat all the way through.\"\n\
\n\
  \"No brain\?\"\n\
\n\
\"Oh, there is a brain\n\ all right. It's just\n\ that the brain is made out of meat!\"\n\
\n\
  \"So... what does the thinking\?\"\n\
\n\
\"You're not\n\ understanding, are\n\ you? The brain does\n\ the thinking. The\n\ meat.\"\n\
\n\
  \"Thinking meat!\n\ You're asking me to\n\ believe in thinking\n\ meat!\"\n\
\n\
\"Yes, thinking meat!\n\ Conscious meat! Loving meat. Dreaming meat.\n\ The meat is the whole deal! Are you getting\n\ the picture?\"\n\
\n\
  \"Omigod. You're\n\ serious then. They're made out of meat.\"\n\
\n\
\"Finally, Yes. They are indeed made out of\n\ meat. And they've been trying to get in touch with us for almost a\n\ hundred of their\n\ years.\"\n\
\n\
  \"So what does the\n\ meat have in mind.\"\n\
\n\
\"First it wants to talk to us. Then I imagine it wants to explore the universe, contact\n\ other sentients, swap ideas and information. The usual.\"\n\
\n\
  \"We're supposed to\n\ talk to meat\?\"\n\
\n\
\"That's the idea.\n\ That's the message\n\ they're sending out by radio. 'Hello. Anyone out there? Anyone\n\ home?' That sort of\n\ thing.\"\n\
\n\
  \"They actually do\n\ talk, then. They use\n\ words, ideas,\n\ concepts\?\"\n\
\n\
\"Oh, yes. Except they\n\ do it with meat.\"\n\
\n\
  \"I thought you just\n\ told me they used\n\ radio.\"\n\
\n\
\"They do, but what do\n\ you think is on the\n\ radio\? Meat sounds.\n\ You know how when you slap or flap meat it\n\ makes a noise\? They\n\ talk by flapping their meat at each other.\n\ They can even sing by squirting air through\n\ their meat.\"\n\
\n\
  \"Omigod. Singing\n\ meat. This is\n\ altogether too much.\n\ So what do you\n\ advise\?\"\n\
\n\
\"Officially or\n\ unofficially\?\"\n\
\n\
  \"Both.\"\n\
\n\
\"Officially, we are\n\ required to contact,\n\ welcome, and log in\n\ any and all sentient\n\ races or multibeings\n\ in the quadrant,\n\ without prejudice,\n\ fear, or favor.\n\ Unofficially, I advise that we erase the\n\ records and forget the whole thing.\"\n\
\n\
  \"I was hoping you\n\ would say that.\"\n\
\n\
\"It seems harsh, but\n\ there is a limit. Do\n\ we really want to make contact with meat\?\"\n\
\n\
  \"I agree one hundred percent. What's there\n\ to say\?\" \`Hello, meat. How's it going\?\' But\n\ will this work? How\n\ many planets are we\n\ dealing with here\?\"\n\
\n\
\"Just one. They can\n\ travel to other\n\ planets in special\n\ meat containers, but\n\ they can't live on\n\ them. And being meat, they only travel\n\ through C space. Which limits them to the\n\ speed of light and\n\ makes the possibility of their ever making\n\ contact pretty slim.\n\ Infinitesimal, in\n\ fact.\"\n\
\n\
  \"So we just pretend\n\ there's no one home in the universe.\"\n\
\n\
\"That's it.\"\n\
\n\
  \"Cruel. But you said it yourself, who wants to meet meat\? And the\n\ ones who have been\n\ aboard our vessels,\n\ the ones you have\n\ probed\? You're sure\n\ they won't remember\?\"\n\
\n\
\"They'll be considered crackpots if they do.\n\ We went into their\n\ heads and smoothed out their meat so that\n\ we're just a dream to them.\"\n\
\n\
  \"A dream to meat! How strangely appropriate, that we should be\n\ meat's dream.\"\n\
\n\
\"And we can mark this\n\ sector unoccupied.\"\n\
\n\
  \"Good. Agreed,\n\ officially and\n\ unofficially. Case\n\ closed. Any others\? \n\ Anyone interesting on that side of the\n\ galaxy\?\"\n\
\n\
\"Yes, a rather shy but sweet hydrogen core\n\ cluster intelligence\n\ in a class nine star\n\ in G445 zone. Was in\n\ contact two galactic\n\ rotations ago, wants\n\ to be friendly again.\"\n\
\n\
  \"They always come\n\ around.\"\n\
\n\
\"And why not\? Imagine\n\ how unbearably, how\n\ unutterably cold the\n\ universe would be if\n\ one were all alone...\" \n\ \t \t \t \t \t \t \t \t \t \t \t \n\ \n\ \n\ \n\ \n\ "};
 

void setup(void) {
  pinMode(0, OUTPUT);
  digitalWrite(0,HIGH);
  u8g2.begin();  
  u8g2log.begin(U8LOG_WIDTH, U8LOG_HEIGHT, u8log_buffer);
  u8g2log.setLineHeightOffset(1); // set extra space between lines in pixel, this can be negative
  u8g2log.setRedrawMode(1);   // 0: Update screen with newline, 1: Update screen for every char  

  bootsequence();
  
}

void loop(void) {
  
  for (int text=0;text<4690;text++) {
    int progressbar = (text/78);
    delay(25);
   u8g2log.print(MeatString[text]);
  
  do {
    u8g2.firstPage();
    u8g2.drawFrame(0, 0, 128,64);
    u8g2.drawLine(0, 9, 128,9);
    u8g2.setFont(u8g2_font_u8glib_4_tr);
    u8g2.drawStr(4, 7, "THEY'RE MADE OF MEAT ");
    u8g2.setCursor(28,7);
    u8g2.setCursor(105, 7);  
    u8g2.drawLine(0, 54, 128,54);
    u8g2.drawStr(4, 61, "TERRY BISSON");
    u8g2.drawFrame(64,57,60,4);
    u8g2.drawBox(64,58, progressbar ,2);
    
    u8g2.setFont(u8g2_font_tinytim_tf);
    u8g2.drawLog(3, 15, u8g2log);   // draw the terminal window on the display
    
  } while ( u8g2.nextPage() );
  
}
    delay(4000);
    u8g2.clearBuffer();
    u8g2.sendBuffer();
    clearOLED();
    int randomdelay = random(30,100);  //random number of seconds from 30 - 100 to wait between cases
    int sleepytime = (randomdelay*1000);
    LowPower.sleep(sleepytime);
    
    bootsequence();
}

void clearOLED(){
    u8g2.firstPage();  
    do {
    } while( u8g2.nextPage() );

}
    
void curser(){
  for (int i = 0; i < 3; i++) {
    
    u8g2.setDrawColor(1);
   // u8g2.clearBuffer();
    u8g2.drawBox(r,p,3,5);
    u8g2.sendBuffer();
    delay(300);
    
   // u8g2.clearBuffer();
    u8g2.setDrawColor(0);
    u8g2.drawBox(r,p,3,5);
    u8g2.sendBuffer();
    delay(300);
    }
} 

void bootsequence(){
    
    u8g2.clearBuffer();
    u8g2.setDrawColor(1);
    u8g2.drawBox(0,0,128,64);
    u8g2.sendBuffer();
    delay(100);
    u8g2.setDrawColor(0);
    u8g2.clearBuffer();
    u8g2.drawBox(0,0,128,64);
    u8g2.sendBuffer();
    delay(500);
    //cursor flash
    r = 1;
    p = 1;
    curser();
    
   
    u8g2.setDrawColor(1);
    u8g2.clearBuffer();
    u8g2.setFont(u8g2_font_u8glib_4_tr);
    u8g2.drawStr(1, 6, "BOOT SEQUENCE INITIATED...");
    u8g2.sendBuffer();
    r = 104;
    p = 1;
    curser();
    //delay(2000);
    //u8g2.setDrawColor(0);
   // u8g2.drawBox(0,0,110,15);
   // u8g2.sendBuffer();
    u8g2.setDrawColor(1);

    u8g2.drawStr(1, 14, "RUNNING STARTUP...");
    u8g2.sendBuffer();
    r = 74;
    p = 9;
   curser();
    

   u8g2.setDrawColor(1);
   u8g2.drawStr(1, 21, "LOADING DATA...");
   u8g2.sendBuffer();
   u8g2.nextPage();
   
    r = 59;
    p = 16;
    curser();
    
    
    u8g2.setDrawColor(0);
    u8g2.drawBox(1,1,110,25);
    u8g2.sendBuffer();
    u8g2.setDrawColor(1);
    delay(100);
    clearOLED(); 

   }
