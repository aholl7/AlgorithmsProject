# Algorithms Final Project

## Problem
There is a family member who is a professor that teaches a Chemistry course at his university. The professor has been told that he must submit a report to his department head that displays a student’s first name, last name, and grade in descending order, along with displaying their GPA. This is because the department head wants if see if there is any correlation to a student’s GPA and their grade in their course. The report must also display the average grade in this professor’s course along with the lowest grade and highest grade. This is because the department head wants to compare between other Chemistry professors and assess if there is any need to change how they go about teaching the course along with assessing the professor’s performance. Lastly, the professor has also been invited to a Chemistry Trivia Competition, along with the other Chemistry professors at this university. A part of the requirements is to bring a group of students whose GPA does not exceed 12.0 combined. Two students would be selected to play a part in the trivia competition for each team and the rest would be reserves for their respective teams. This professor wants to enter the competition also really wants to win but wants to choose the best students in his class, however, he has to meet this very strict GPA requirement and he is stuck on which students he should choose that have been doing great in this class along with generating a group to meet this requirement.

## Solution
In order, to generate this report that this Chemistry professor needed, we decided that the best course of action would be to use some sort of sorting algorithm to generate this information. It also would create an easy way for all other information to be shown, such as the lowest grade and highest grade. This is because of the fact that since the algorithm had to be generated in descending order, the highest grade could be found at the first element and the lowest grade at the last element. The average could also be found through a simple function that added up each grade and divided by the total number of students. We decided that Quicksort would be the best sorting algorithm to use, due to the fact it would not take up unnecessary memory space. Allocating and deallocating this extra memory can increase its running time. Another thing about this algorithm that it is quick to implement. For the next course of action, there was a need to find which students the professor could use to participate in the trivia competition. The best approach for this problem was to implement the Knapsack Algorithm and another Brute Force Algorithm to find the most valuable set of students based on their grades who combined to meet the GPA requirement that the professor needed. 
