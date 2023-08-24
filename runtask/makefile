CC=g++
CFLAGS= -ggdb3 -std=c++17 -O0 -Wall -Wextra -Weffc++ -Wc++14-compat -Wmissing-declarations -Wcast-align -Wcast-qual -Wchar-subscripts -Wconversion -Wctor-dtor-privacy -Wempty-body -Wfloat-equal -Wformat-nonliteral -Wformat-security -Wformat=2 -Winline -Wnon-virtual-dtor -Woverloaded-virtual -Wpacked -Wpointer-arith -Winit-self -Wredundant-decls -Wshadow -Wsign-conversion -Wsign-promo -Wstrict-overflow=2 -Wsuggest-override -Wswitch-default -Wswitch-enum -Wundef -Wunreachable-code -Wunused -Wvariadic-macros -Wno-missing-field-initializers -Wno-narrowing -Wno-old-style-cast -Wno-varargs -Wstack-protector -fcheck-new -fsized-deallocation -fstack-protector -fstrict-overflow -fno-omit-frame-pointer -Wlarger-than=8192 -fPIE -Werror=vla
OFLAGS= -ggdb3 -std=c++17 -O0 -Wall -Wextra -Weffc++ -Wc++14-compat -Wmissing-declarations -Wcast-align -Wcast-qual -Wchar-subscripts -Wconversion -Wctor-dtor-privacy -Wempty-body -Wfloat-equal -Wformat-nonliteral -Wformat-security -Wformat=2 -Winline -Wnon-virtual-dtor -Woverloaded-virtual -Wpacked -Wpointer-arith -Winit-self -Wredundant-decls -Wshadow -Wsign-conversion -Wsign-promo -Wstrict-overflow=2 -Wsuggest-override -Wswitch-default -Wswitch-enum -Wundef -Wunreachable-code -Wunused -Wvariadic-macros -Wno-missing-field-initializers -Wno-narrowing -Wno-old-style-cast -Wno-varargs -Wstack-protector -fcheck-new -fsized-deallocation -fstack-protector -fstrict-overflow -fno-omit-frame-pointer -Wlarger-than=8192 -fPIE -Werror=vla
all: run

run: ../object/main.o ../object/output.o ../object/simple.o ../object/solve.o ../object/test.o
	$(CC) $(CFLAGS) -o run ../object/main.o ../object/output.o ../object/simple.o ../object/solve.o ../object/test.o

../object/main.o: ../cpp/main.cpp ../headers/header.h ../headers/solve.h ../headers/output.h ../headers/test.h
	$(CC) $(CFLAGS) ../cpp/main.cpp -c -o ../object/main.o

../object/output.o: ../cpp/output.cpp ../headers/header.h
	$(CC) $(CFLAGS) ../cpp/output.cpp -c -o ../object/output.o

../object/simple.o: ../cpp/simple.cpp ../headers/header.h
	$(CC) $(CFLAGS) ../cpp/simple.cpp -c -o ../object/simple.o

../object/solve.o: ../cpp/solve.cpp ../headers/header.h ../headers/simple.h
	$(CC) $(CFLAGS) ../cpp/solve.cpp -c -o ../object/solve.o

../object/test.o: ../cpp/test.cpp ../headers/header.h ../headers/solve.h ../headers/output.h ../headers/simple.h
	$(CC) $(CFLAGS) ../cpp/test.cpp -c -o ../object/test.o
