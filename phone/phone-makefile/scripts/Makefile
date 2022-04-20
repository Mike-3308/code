CC := gcc
CFLAGS := -Wall -O3
Libs = -lpthread
Target := phone
Source := $(wildcard ./*.c)
Objs := $(patsubst %.c,%.o,$(Source))
Modules += allfree create delete display init login menu  search   main
AllObjs := $(addsuffix /*.o,$(Modules))

