Milestone #2 - Reflection

Milestone two was very simple to complete, but I was having trouble producing the result that was supposed 
to be high contrast and random noise. It took me twenty minutes before I realized that I forgot to add
new breaks to the switch case and it was only producing a high contrast result and not a random noise one. 
I figured this out because when I chose an option that had been successful in milestone 1, it came out as a
high contrast instead of negate red. Once I realized they were all becoming high contrast, I looked at the swich
case and noticed there were no breaks at the end of case 8 or 9. It was a simple mistake and easy fix, but it
wasted so much time and made me think there was something wrong with my code that I ended up changing it a bunch
before I realized it was the lack of breaks and not the effect itself. 

Another problem I ran into was the while loop. I originally had it as " while(choice == "y") ... " and it ran 
perfectly until I tried to get out of the loop, it just continued to loop through and I had to terminate it. 
I looked up the different types of controlled while loops and realized that I needed to put it as 
" while(choice != "n") ... " so that when it does equal "n" the while loop knows it has to terminate the loop. 
Once I realized this and implemented it into my code, everything ran smoothly and I was able to add multiple 
to the bunny2.ppm. Overall, I enjoy the image manpulator project because it challenges in my code writing
capabilits, plus it is a fun exercise to do when I am bored. 