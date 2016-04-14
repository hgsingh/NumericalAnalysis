from __future__ import division
import sys
import numpy.random as r

def rand_list(size):
    integer = [None]*size
    i = 0
    for i in range(0, size-1):
        if(i == 0):
            integer[i] = unique_rand([size])
        elif((i+ 1) % 2 == 0):
            integer[i] = unique_rand_even(integer[:i])
        elif(i == 4):
            integer[i] = 5
        elif(i == 9):
            integer[i] = 0
        else:
            integer[i] = unique_rand(integer[:i])
    integer[size-1] = 0
    print integer
    return integer

def unique_rand(l):
     #some unique integer
    x = r.random_integers(0,9)
    while(x in l or x == 5 or x == 0 or (x % 2) == 0):
        x = r.random_integers(0,9)
    return x

def unique_rand_even(l):
    x = r.random_integers(0,9)
    while((x in l) or x == 5 or x == 0 or  (x % 2) != 0):
        x = r.random_integers(0, 9)
    return x

def test_list(int_list):
    for i in range(1, len(int_list)):
        s = reduce(lambda x,y: x+str(y), int_list[:i], '')
        num = int(s)
        if(num % (i) != 0):
            print "failed" 
            return 0
    return 1

def test():
    l = rand_list(10)
    while(test_list(l) == 0):
        l = rand_list(10)
    return l
print test()
s = reduce(lambda x,y: x+str(y), test(), '')
print int(s) 


