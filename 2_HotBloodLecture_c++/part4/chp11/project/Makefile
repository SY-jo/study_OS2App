# Windows10 powershell

CC = g++
# CFLAGS = 
LDFLAGS = 
LDLIBS = 
OBJS = main.o Account.o Menu.o AccountArray.o
TARGET = BankingSystemVer$(VERSION).exe
VERSION = 0.7

all: $(TARGET)

clean:
	powershell Remove-Item *.o 
	powershell Remove-Item $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS)

main.o : main.cpp
Account.o : Account.cpp Account.h
Menu.o : Menu.cpp Menu.h
AccountArray.o : AccountArray.cpp AccountArray.h 
