#
#
#

all: project mastermind

project: project.c 
	gcc -Wall -Wextra -Wpedantic _Wwrite-strings -Wstack-usage=1024 -Wfloat-equal -Waggregate-return -Winline -o project project.c 

mastermind: mastermind.c
	gcc -Wall -Wextra -Wpedantic -Wwrite-strings -Wstack-usage=1024 -Wfloat-equal -Waggregate-return -Winline -o mastermind mastermind.c
	
clean:
	rm project mastermind


