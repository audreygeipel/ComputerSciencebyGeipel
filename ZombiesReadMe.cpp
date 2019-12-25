/* 
CSCI 103 Zombies Programming Assignment 

Name: Audrey Geipel

Email Address: ageipel@usc.edu

NOTE: You can delete the questions, we only need your responses.

NOTE: It is helpful if you write at most 80 characters per line,
and avoid including special characters, so we can read your responses.

Please summarize the help you found useful for this assignment, which
may include office hours, discussion with peers, tutors, et cetera.
Saying "a CP on Tuesday" is ok if you don't remember their name.
If none, say "none".

:I went to CP office hours on Tuesday, and discussing with peers

================================ Questions ==================================

1. Which kind of a loop did you use to iterate through the nights of a
   single simulation?  Why?
   
: I used a while loop, because you don't know how long it will take 
or how many nights it will take until you reach the end of the simulation.

2. Which kind of a loop did you use to perform the M simulations? Why?

   
:I used a for loop to do M simulations, because M was a set and known
amount of simulations, and it didn't need to satisfy a condition in
order to be over.


3. How did you ensure that if a human was turned into a zombie on a
   particular night that he/she didn't bite anyone until the following
   night?

: I counted the number of zombies in the population only after they had
done the bites for the night, so the count of zombies for the next night
only used the number of zombies from the night before.


4. Experiment briefly running your program with fewer simulations 
   (smaller M value). One thing computer scientists do often is evaluate 
   trade-offs. Running with a smaller M results in some interesting 
   trade-offs: your program output three values, Average Nights, Max Nights 
   and Min Nights. How will these values be impacted by running fewer 
   simulations? On the other hand, what other property of your program is 
   affected by using a smaller M?

: The average is less precise when using a smaller M, and it goes
to fewer decimal points. The Max and Min night values also get closer together
and show less variation. 

5. (Optional Challenge -- Ungraded)
    You do not need to submit an answer if you prefer not to.) 
   Given a population of N and k initial zombies, can you find an expression
   for the theoretical minimum number of nights it would take for everyone
   to become a zombie?

:


================================ Remarks ====================================

Filling in anything here is OPTIONAL.

Approximately how long did you spend on this assignment?

: ~10 hours

Were there any specific problems you encountered? This is especially useful to
know if you turned it in incomplete.

: I initially assigned all the zombies to the beginning slots of the array,
but that ended up changing the probability of bites and threw off the answers.

Do you have any other remarks?

