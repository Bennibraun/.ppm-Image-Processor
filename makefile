# Benjamin Braun
# 10-16-18

transform: mainDriver.c
	gcc -Wall -o transform mainDriver.c parse.c menu.c mirror.c print.c flipHoriz.c purple.c

run: transform
	./transform input.ppm > img.ppm

clean:
	rm transform
	rm output.ppm
