all: canalyzex

test: testnl testfgn
	./testnl
	./testfgn

canalyzex: canalyze.o namelist.o fgetname.o
	gcc -g -Wall -o $@ $^

testnl: testnl.o namelist.o
	gcc -g -Wall -o $@ $^

testfgn: testfgn.o fgetname.o
	gcc -g -Wall -o $@ $^

canalyze.o: canalyze.c fgetname.h namelist.h
	gcc -g -Wall -c -o  $@ $<

testnl.o: testnl.c namelist.h
	gcc -g -Wall -c -o $@ $<

namelist.o: namelist.c namelist.h
	gcc -g -Wall -c -o $@ $<

testfgn.o: testfgn.c fgetname.h
	gcc -g -Wall -c -o $@ $<

fgetname.o: fgetname.c fgetname.h
	gcc -g -Wall -c -o $@ $<

clean:
	rm -f testnl testfgn *.o
