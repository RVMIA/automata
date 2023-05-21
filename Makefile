all: life seeds brian

life: life.c
	gcc life.c -o life.out -lraylib
seeds: seeds.c
	gcc seeds.c -o seeds.out -lraylib
brian: brian.c
	gcc brian.c -o brian.out -lraylib
