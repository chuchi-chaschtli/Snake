# Snake
Simple Snake Game implmentation in C++. Uses a standard Wiimote for key interaction, transmitted via a Bluetooth connection through an FPGA Controller.

- [Wiimote](https://en.wikipedia.org/wiki/Wii_Remote)
- [Zedboard](https://www.digikey.com/catalog/en/partgroup/zedboard-zynq-7000-development-board/49272?utm_adgroup=Programmers%20Dev&gclid=CjwKCAiAjanRBRByEiwAKGyjZRwrR2mIRXxX-yXDImv_d5vKcZAsT3Ar8xjpORzv_SbxS4Mam198PBoCfLMQAvD_BwE)

#### Usage
Note that steps 1 and 2 only need to be completed once.

1. Connect and power on the Zedboard and Wiimote to a UNIX environment.
2. Run the WiimoteConnect.sh to connect the Wiimote via Bluetooth signal. Note that you will have to modify this file to use your [Wiimote's MAC address](https://android.ccpcreations.com/wiicontroller/wc-findmac).
3. Run the make-snake.sh file to launch the Snake game.

#### Instructions
This is a very basic implementation of Snake. Snake is a classic arcade game in which the user, the snake, is trying to grow by eating food, or the fruit. Everytime the snake consumes a piece of fruit, it grows. The game ends when the snake collides with itself or the edges of the game board.

Use the keypad on the Wiimote to control your Snake's direction. Press B to play a new game.
