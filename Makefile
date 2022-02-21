SOURCES = main.cc url.cc tree.cc

default: build

build: clean ; g++ -std=c++11 -Wall -o main $(SOURCES) -lcurl

clean: ;  rm -rf main

test1: build ; ./main https://www.ulethbridge.ca/ https://www.ulethbridge.ca/ross/admissions/grad/deadlines

test2: build ; ./main https://www.ulethbridge.ca/  https://library.ulethbridge.ca/resources/databases/providers

test3: build ; ./main https://www.ulethbridge.ca/ https://www.ulethbridge.ca/planning-and-reporting/strategic-plan-document
