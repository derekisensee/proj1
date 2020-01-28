all: tcat tgrep tzip tunzip
tcat: tcat.c
	gcc -o tcat tcat.c -Wall -Werror

tgrep: tgrep.c
	gcc -o tgrep tgrep.c -Wall -Werror

tzip: tzip.c
	gcc -o tzip tzip.c -Wall -Werror

tunzip: tunzip.c
	gcc -o tunzip tunzip.c -Wall -Werror
