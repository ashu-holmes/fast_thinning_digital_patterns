FAST ALGORITHM FOR THINNING
-----------------------------------------

IMAGE TYPE USED :

This code, used for thinning binary image, is a modification of zhang suen algorithm. Binary image by definition, consists of only black and white pixels. Here, in the code bellow, Black is denoted as 1 and white is denoted as 0.

IMPLEMENTATION: in C language

ADVANTAGE : 

1 It is very fast and simple to implement. 

DISADVANTAGE:
 Skeletons obtained are not unit pixel width and there is loss of patterns sometimes. So there is need of an algorithm which overcomes these disadvantages
in some parculiar cases ,while recognising hand written character the two pixel width or even pixel width in a horizontal or vertical direction may be deleted , which would cause the lose of connectivity of object pattern .

REFERENCES:

1.Simulation of Zhang Suen Algorithm using FeedForward
Neural Networks
http://www.caeaccess.org/research/volume2/number5/luthra-2015-cae-651750.pdf
2. https://nayefreza.wordpress.com/2013/05/11/zhang-suen-thinning-algorithm-java-implementation/
3. http://www.engineersgarage.com/articles/image-processing-tutorial-applications

