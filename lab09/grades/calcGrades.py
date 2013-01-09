#!/usr/bin/python

import sys
import csv

sum = float(0)
count = 0
grades = {}
studentNum = {}

with open(sys.argv[1], 'rb') as csvfile:
  gradereader = csv.reader(csvfile, delimiter=',')
  for row in gradereader:
    print ','.join(i for i in row)
    if row[2].isdigit():
      if int(row[2]) in grades:
	grades[int(row[2])] += 1
      else:
	grades[int(row[2])] = 1
      if int(row[2]) in studentNum:
        studentNum[int(row[2])]= studentNum[int(row[2])] + ", " + row[1]
      else:
	studentNum[int(row[2])]=row[1]
      sum = sum + float(row[2])
      count =count + 1
print(" , Average, " + str(sum/count))
for grade in sorted(grades.keys()):
  print "The number of students who recieved grade %s is %d and their numbers are %s" %(grade, grades[grade], studentNum[grade])