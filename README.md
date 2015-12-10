# GraphicsFinal - Eric Gan, Sam Inman, Tucker Cheyne
########################################
## ︻デ┳═ー SNIPERS PLAYGROUND ︻デ┳═ー ##
########################################


########################################
## ︻デ┳═ー     Building       ︻デ┳═ー ##
########################################
In order to build our project you should
follow these steps:

1) Remove the build directory
2) Create a new build directory
3) cd into the build directory
4) run `cmake ..`
5) run `make install`
6) a file `terrain` will be put in the `inst`
   directory in the root folder running this
   file will start the game

########################################
## ︻デ┳═ー     Controls       ︻デ┳═ー ##
########################################
M - reseed the world
r - reset world targets

left click - fire bullet
right click and drag - camera movement

w - move forward in the x/z plane
s - move backward in the x/z plane
a - strafe left in x/z plane
d - strafe right in x/z plane

arrow up - move forward in the camera look direction
arrow down - move in the negative camera look direction
arrow left - rotate camera around y axis
arrow right - rotate camera around y axis

5 - decrease water level
6 - increase water level

g - increase gravity
f - decrease gravity

minus - increase wind left
plus - increase wind right
0 - zero the wind speed

t - toggle hit markers

c - toggle bullet follow mode
