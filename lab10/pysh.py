#!/usr/bin/env python

import os, os.path, sys, getpass, shlex, subprocess

#os.path.expandvars

home=os.getenv('HOME')

standardin = sys.stdin
standardout = sys.stdout

def getcwd():
    "like os.getcwd(), but collapses the home directory prefix into ~"
    cwd = os.getcwd()
    if cwd.startswith(home):
        cwd = '~'+cwd[len(home):]
    return cwd

def runProgram (argv):
  stout = None
  stin = None
  background = False
  argvv = []
  for arg in argv:
    argg = os.path.expandvars(arg)
    argvv.append(argg)
  if '>' in argvv:
    stout = open(argvv[argvv.index('>') + 1], 'wb')
    argvv = argvv[0:argvv.index(">")]
  elif '<' in argvv:
    stin = open(argvv[argvv.index('<') + 1], 'rb')
    argvv = argvv[0:argvv.index("<")]
  if '&' in argvv:
    background = True
    argvv.remove('&')
  if '|' in argvv:
    p1 = subprocess.Popen(argvv[:argvv.index('|')], stdout = subprocess.PIPE)
    p2 = subprocess.Popen(argvv[argvv.index('|')+1:], stdin=p1.stdout, stdout=None)
    p1.stdout.close()
    p2.communicate()
    return
  
  if (background):
    subprocess.Popen(argvv, stdin =stin, stdout =stout)
  else:
    subprocess.call(argvv, stdin =stin, stdout = stout)
    
    
 
  
    
while True:
    print "%s@%s>" % (getpass.getuser(), getcwd()),

    argv = None
    try:
        argv = shlex.split(raw_input())
    except EOFError:
        print
        break                             # end of file from user, e.g. Ctrl-D

    if not argv:
        continue # empty command
        
    if argv[0] in ['exit', 'quit', 'bye']:
        break
    elif argv[0]=='cd':
        try:
            os.chdir(os.path.expanduser(argv[1])) # expand ~ to home directory
        except IndexError:                   # no arguments, chdir to home dir
            os.chdir(home)
        except OSError, s:
            print >>sys.stderr, "chdir: %s" % s
    else:
      runProgram (argv)

    #else:
        #print "TODO: execute %s" % ' '.join(argv)

# goodbye message
goodbye = "have a good sunny day, see you back soon"
print "*"+"-"*(len(goodbye)+2)+"*"
print "| %s |" % goodbye
print "*"+"-"*(len(goodbye)+2)+"*"
