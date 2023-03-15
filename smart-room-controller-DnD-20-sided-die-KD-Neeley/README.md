# Smart-Room-Controller
# Project Title
This project was my Midterm assignment for Brian Rashap's course at the FUSE Makerspace, 'The Internet of Things'. It needs a lot more work to be truly complete. The code is very wet and needs a lot of improvement. I will be updating it in the future. We were given four days to build a custom smart room controller. Mine took the form of a D20 to influence the atmosphere during DnD gameplay. The code can be used to tell the smart room controller what to do. You can turn on smart outlets and control smart lights.

# Motivation
I play DnD every other Saturday with friends. I was inspired by my expereinces playing the game to create this interactive D20 that can influence the atmosphere during gameplay. I imagine that it can do so much more too, with an app in the future to track rolls and influence the game for the DM. 

#Build Status
The current build, let's call it Version 1.0, needs much work. A header file can be created to store the bitmaps, and functions can be written to clean up the wet code. It is functional, but even the baseline values for determining die rolls need work. That is something that needs to be done for everyone uniquely as each accelerometer will have slightly different measurements. I want to find the median for each of the side coordinates to get more accurate roll results. As it stands, it sometimes thinks a side is one of its partners or opposite sides. 

# Code Style
The code is written in C++.

# Screenshots
https://www.youtube.com/watch?v=eOC_jv2n0Ek – automatic! [YouTube](http://YouTube.com) 

# Tech/Framework used
## installed Libraries:
    - Adafruit_SSD1306
    - IoTClassroom_CNM
    - MPU6050_CNM
    - colors.h

## Hardware Used
    - Argon Microcontroller
    - MPU 6050 Accelerometer and Gyroscope
    - Neopixel
    - 3.3V rechargeable Lithium Ion Battery

# Features
Features code that can turn a smart light on or off, change their color, and brightness. 
Features code that can turn NeoPixels on or off, change their color, and brightness.
Features code that can turn a smart outlet (WEMO) on or off.
Features Bitmaps and text messages for OLED display, these can be customized.
Features code that can determine the side rolled for a D20 holding the accelermoter MPU6050 and Argon Microcontroller.
Features a design caseing for the die that can fit the components inside, with a lid that snaps shut. 
Features holes in the lid for USB charging port, and OLED display pins.
Die sides can be customized, and the die can be weighted if you desire it.
Features an inlay on the cover that fits the OLED display so it doesn't get smashed when rolling the die.
Features that need work: Code and header files need refactoring. The lid needs work, it has an edge that juts into the body and won't allow for closure without using a dremel on the final print to level it out.
Lid can be screwed shut with small electronics screws and a tiny drill bit. Countersink the holes in the lid to keep the die level.
Needs interior casing to hold the inner components so they don't roll around and throw off the accelerometer. This is just a prototype, but the final die will allow for the inner components to be rolled and banged around without a care.

# Code Examples
coming soon

# Installation
I've written the program and done edits in Visual Studio Code. There is a free version here: 
https://code.visualstudio.com/ – automatic! [Visual Studio Code](https://code.visualstudio.com/) 


# Tests
coming soon

# Contribute
Feel free to contribute to this project and share your own D20 builds.
You can clone the git repository, or branch off of it, or write your own code from scratch.
Credit to Katie Neeley as the original designer of the prototype is appreciated.

# Credits
Thanks to Brian Rashap for:
    The IoTClassroom_CNM library package
    The MPU6050_CNM header file and example code
    The colors.h header file
    The assignment

# License
MIT
