# Make a Digital Timer!
 
## Overview
For this assignment, you are going to 

A) [Solder your LCD panel](#part-a-solder-your-lcd-panel)

B) [Write text to an LCD Panel](#part-b-writing-to-the-lcd) 

c) [Using a time-based digital sensor!](#part-c-using-a-time-based-digital-sensor)

D) [Make your Arduino sing!](#part-d-make-your-arduino-sing)

E) [Make your own timer](#part-e-make-your-own-timer) 
 
## In The Report
Include your responses to the bold questions on your own fork of [this lab report template](https://github.com/FAR-Lab/IDD-Fa18-Lab2). Include snippets of code that explain what you did. Deliverables are due next Tuesday. Post your lab reports as README.md pages on your GitHub, and post a link to that on your main class hub page.

## Part A. Solder your LCD panel

![Soldered LCD](https://github.com/MattD18/IDD-Fa18-Lab2/blob/master/IMG_2349.JPG)

## Part B. Writing to the LCD
 
**a. What voltage level do you need to power your display?**

We need 5V to power the display, with power through the VDD node and ground through the VSS node.

**b. What voltage level do you need to power the display backlight?**

We need 3V to power the display backlight, with power through the A node and ground through the K node.
   
**c. What was one mistake you made when wiring up the display? How did you fix it?**

Fortunately, I didn't have any major mistakes in wiring up the display. I found that color coding my wires was helpful (orange for power, blue for ground, white for others). Also, I didn't realize my display was working until I adjusted by 10K pot.

**d. What line of code do you need to change to make it flash your name instead of "Hello World"?**

Within setup(), I needed to change the lcd.print() command.

```
void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("hello, Matt!");
}
```

 
**e. Include a copy of your Lowly Multimeter code in your lab write-up.**

https://github.com/MattD18/IDD-Fa18-Lab2/blob/master/lowly_multimeter.ino

## Part C. Using a time-based digital sensor

![Working Rotary Encoder](https://github.com/MattD18/IDD-Fa18-Lab2/blob/master/IMG_2350.MOV)


## Part D. Make your Arduino sing!

**a. How would you change the code to make the song play twice as fast?**

In setup(), I added the line:

```
noteDurations[thisNote] = noteDurations[thisNote] * 2;
```
 
**b. What song is playing?**

Star Wars!!

## Part E. Make your own timer

**a. Make a short video showing how your timer works, and what happens when time is up!**

Chess Clock:

https://www.youtube.com/watch?v=7o0EPOPa0BM

Code:

https://github.com/MattD18/IDD-Fa18-Lab2/blob/master/chess_clock.ino


**b. Post a link to the completed lab report in your class hub GitHub repo.**

Please see class repo
