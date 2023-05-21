all: life seeds brian

life: life.c
	gcc life.c -o life -lraylib
seeds: seeds.c
	gcc seeds.c -o seeds -lraylib
brian: brian.c
	gcc brian.c -o brian -lraylib
