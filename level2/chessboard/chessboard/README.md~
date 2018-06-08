#Chessboard this is a platform for people-to-people, AI-to-AI, people-to-AI gobang playing(Windows system,Chinese Language)

#How to use it?

##run chessboard.exe

Then you can see the timer setter and mode setter, which are for you to set the time limits for each step and set a person player or a AI player as the first player or the second player. The left setting is for the first player and the other is for the second one.
##setting

If you set the timer setter and mode setter well, you can click to ensure it. If the mode is for person, then do nothing. If the mode is for AI, you need to add the location of the AI's executable (.exe) file in the bar and ensure it.

##start playing

when you ensure all the setting, you will see a button for ensuring. Click it and the game will start.

#Some functions

##All the steps will be limited by timers, and you can see the timers counting down through the game. Once one part exceed the time, that one will lose and the game will be stopped.

##If all the space filled with the chessmans,but not existing a winner, it will show it's a draw.

##If one player does a step, it will throw corresponding messages in the message box lied at the bottom. For example, if he put a chessman where there have been another one, the message box will warn him. This function is made to make the AI programmer be convenient to know what's wrong with the AI and fix it accordingly.

#The player mode

##Person player:

For each step, you only need to click on the chessboard. Then your step will show on the chessboard.

##AI player:

For each step, the platform will send a 15x15 matrix,which is presenting the chessboard status, to the AI through standard input. And the matrix message will be sent in one line. You can read it as follow:

for(int i=0;i<15;i++)
    for (int j=0;j<15;j++)
        cin>>chessman[i][j];

chessman[i][j] means the status of chessman in Column i, Row j. The status has three kinds:

key[i][j]=0 : no chessman
key[i][j]=1 : black chessman
key[i][j]=2 : white chessman

For each step, AI only need to output "x y" through standard output, which means AI will put a chessman in Column x, Row y.

#Good luck and have pleasure!
