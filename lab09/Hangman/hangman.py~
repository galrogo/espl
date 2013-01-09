#!/usr/bin/python

# hangman - a rudimentary version of the hangman game. Instead of showing a
#   gradually embodied hanging man, this simply has a bad guess countdown.
#   You can optionally indicate steps from the gallows as the only arg.

import os
import sys
import random

wordlib="long-words.txt"
randomquote="./randomquote.sh"
empty="\."	# we need something for the sed [set] when $guessed=""
games=0

def randomWord(filename):
    all_words = []
    try:
        with open(wordlib, 'r') as f:
            for w in f:
                all_words.append(w.strip())
    except IOError as e:
        sys.stderr.write("%s: Missing word library %s\n" % (sys.argv[0], wordlib))
        sys.stderr.write("(online at http://www.intuitive.com/wicked/examples/long-words.txt\n")
        sys.stderr.write("save the file as $wordlib and you're ready to play!)\n")
        sys.exit(1);
    return random.choice(all_words)

if not os.path.isfile('long-words.txt'):
  print "Missing word library %s" %(wordlib)
  print "(online at http://www.intuitive.com/wicked/examples/long-words.txt"
  print "save the file as $wordlib and you're ready to play!)"
  sys.exit(1)
else:
   file = 'long-words.txt'
  
  
guess = ""

while (guess != "quit"):
  word = randomWord(file)
  if (games == 0):
    print "*** New Game! ***"
   
  games = games + 1
  guessed = []
  partial = ''
  
  while (guess != "quit"):
     
    for c in word:
      if c in guessed:
	partial += c
      else:
	partial += '-'
	
    print "Steps from Gallow %d, word so far %s" %(7-games, partial)
    print "Guess a letter: "
    guess = raw_input()
  
    guessed.append(guess)
  
   
      
    if guess not in word:
       games = games + 1
      
    if '-' not in partial:
      print "SUCCESS"
      break
      
    if (games == 7):
      print "YOU DIED!!!!"
      break
    
      partial =''

