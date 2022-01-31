# Function, array, matrix
In this part we will manipulate Array and matrix :

1. Transpose a matrix
2. Transpose a matrix in a mono dimensional array.
    * Get size of a matrix as an input from the user.
    * Size should be less than 8 in each direction (rows, columns).
    * Get values to fill the matrix from the user.
    * Transpose matrix.
    * Print original matrix.
    * Print transpose matrix.
    * Transform the original matrix in a mono dimensional array.

******************

# Function, array, matrix

## Problem 1
Write the following functions :
* Caesar cipher https://en.wikipedia.org/wiki/Caesar_cipher
* Vigenere cipher https://en.wikipedia.org/wiki/Vigen%C3%A8re_cipher
In the main file add the necessary code to test and validate your encryption

## Problem 2
Create functions to inverse the encryption

***
# Object, functions, statistics

## Problem 1
Create an object named passager which contains the data of the file "titanic.csv". Create a function to read the full file as a vector of passager. To do this, you probably need the follow tools that you can find in the std library.
 * ifstream https://www.cplusplus.com/reference/fstream/ifstream/?kw=ifstream
 * getline https://www.cplusplus.com/reference/string/string/getline/?kw=getline
 * vector https://www.cplusplus.com/reference/vector/vector/?kw=vector

## Problem 2
The "titanic.csv" file contains data for 887 of the real Titanic passengers. Each row represents one person. The columns describe different attributes about the person including whether they survived (S),their age (A), their passenger-class (C), their sex (G) and the fare they paid (X).
Write a program which finds the answers to the following questions. Calculate the conditional probability that a person survives given their sex and passenger-class:
* P(S= true | G=female,C=1)
* P(S= true | G=female,C=2)
* P(S= true | G=female,C=3)
* P(S= true | G=male,C=1)
* P(S= true | G=male,C=2)
* P(S= true | G=male,C=3)

## Problem 3
What is the probability that a child who is in third class and is 10 years old or younger survives? Sincethe number of data points that satisfy the condition is small use the "bayesian" approach and represent your probability as a beta distribution.
Calculate a belief distribution for:
* S= true | A<=10,C=3

## Problem 4
You can express your answer as a parameterized distribution. How much did people pay to be on the ship? Calculate the expectation of fare conditioned on passenger-class:
* E[X | C=1]
* E[X | C=2]
* E[X | C=3]
