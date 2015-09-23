#!/usr/bin/env python
# coding=utf-8

def insertsort (A, p, q):
    if (p<q):
        i=p
        while (i<=q):
            key=A[i]
            j=i-1
            while (A[j]>key and j>=p):
                A[j+1]=A[j]
                j-=1
            A[j+1]=key
            i+=1
    else:
        print "sorry"
        
coll = [1,345,5462,43,6,65,2,56,6245,8,3,62,4,2,46,8,4,56,5,95,6,85,624,58,67,7,9,4,6,2,562,7,63,5,764,524,756,624,8,356,73,56,7,43]
for i in coll:
    print i,                                    #python不换行输出
print ""
print "coll after insertsort is ------------------------------------------------------------------------"
insertsort(coll, 0, 43)
for i in coll:
    print i,
print ""
