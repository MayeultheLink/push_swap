Usage : ./push_swap [numbers to be sorted]

This program will give you commands to be applied to a list of integers so they can be sorted. We have two stacks available to manipulate our integers : stack A, where all the numbers are initially stored, and stack B.
The available commands are the following :

pb : Take the first element of stack A and put it in stack B as the first element

pa : Take the first element of stack B and put it in stack A as the first element

sa : swap the first two elements of stack A

sb : swap the first two elements of stack B

ss : swap the first two elements of stack A and of stack B

ra : rotate stack A, so that the first element becomes the last

rb : rotate stack B, so that the first element becomes the last

rr : rotate stack A and stack B, so that the first element becomes the last

rra : rotate stack A, so that the last element becomes the first

rrb : rotate stack B, so that the last element becomes the first

rrr : rotate stack A and stack B, so that the last element becomes the first

I implemented different algorithms to find out which one could be more efficient, since the goal of this project is to sort the numbers passed as parameters with the fewest operation possible. These are the results :


For 100 numbers :

worst case -> merge (822) > radix (1084) > quick (1613) > selection (1623) > bubble (5457) > insertion (8921)

average -> merge (756) > quick (1061) > radix (1084) > selection (1468) > bubble (4660) > insertion (7630)

best case -> merge (699) > quick (748) > radix (1084) > selection(1266) > bubble (4044) > insertion (6056)

standard deviation -> radix (0) > merge (27.2) > selection(75.6) > quick (170.6) > bubble (320.3) > insertion (529.4)


For 500 numbers : 

worst case -> radix (6784) > merge (10 433) > quick (29 509) > selection(35 181) > bubble (121 375) > insertion (203 128)

average -> radix (6784) > merge (9 503) > quick (17 618) > selection(32 253) > bubble (111 319) > insertion (188 029)

best case -> radix (6784) > merge (8 801) > quick (8 973) > selection(30 530) > bubble (102 662) > insertion (176 005)

standard deviation -> radix (0) > merge (334.9) > selection(829.3) > bubble (3659.5) > quick (4961.7) > insertion (5427.5)


To get the highest grade possible on this project, the program must sort 100 numbers with less than 700 commands, and sort 500 numbers with less than 5500 commands. As you can see, none of these algorithms are sufficiently efficient for this goal.

Therefore I implemented an algorithm that is optimized for this project. I worked with chunks : different sizes of chunks are passed to the other stack, depending on the number of integers to be sorted.
I end up with a roughly sorted stack in B, which I can pass in A with a selection sort. With this, I have a worst case scenario still above 700 commands for 100 numbers and above 5500 commands for 500 numbers, but in approximately 95% of cases, the program will answer the demands of the subject.

We can see in the results above that, the larger the number of integers to sort is, the more efficient radix sort becomes. I empirically determined that, around 2500 numbers, radix becomes more efficient than my algorithm, so it will be the one I use for any larger number of integers to sort.

You can use the checker executable to verify that the commands written in the standard output will in fact sort the integers passed as parameters. Usage : ./push_swap [integers to sort] | ./checker [same integers]

Final grade : 125/125
