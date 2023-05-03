parser.out: lex.yy.o y.tab.o ass6_20CS30042_translator.o ass6_20CS30042_target_translator.o
	g++ lex.yy.o y.tab.o ass6_20CS30042_translator.o ass6_20CS30042_target_translator.o -lfl -o parser.out

ass6_20CS30042_target_translator.o: ass6_20CS30042_target_translator.cxx ass6_20CS30042_translator.h
	g++ -c ass6_20CS30042_target_translator.cxx

ass6_20CS30042_translator.o: ass6_20CS30042_translator.cxx ass6_20CS30042_translator.h
	g++ -c ass6_20CS30042_translator.cxx

lex.yy.o: lex.yy.c
	g++ -c lex.yy.c

y.tab.o: y.tab.c
	g++ -c y.tab.c

lex.yy.c: ass6_20CS30042.l y.tab.h ass6_20CS30042_translator.h
	sudo apt install flex
	flex ass6_20CS30042.l

y.tab.c y.tab.h: ass6_20CS30042.y
	sudo apt install bison
	bison -dty --report=all ass6_20CS30042.y

libass2_20CS30042.a: ass2_20CS30042.o
	ar -rcs libass2_20CS30042.a ass2_20CS30042.o

ass2_20CS30042.o: ass2_20CS30042.c myl.h
	gcc -c ass2_20CS30042.c

clean:
	rm libass2_20CS30042.a ass2_20CS30042.o parser.out ass6_20CS30042_translator.o ass6_20CS30042_target_translator.o lex.yy.* y.tab.* y.output *test*.s *quads*.out test*

test: parser.out libass2_20CS30042.a
	@echo "Generating assembly files\n"
	./parser.out ass6_20CS30042_test1 > ass6_20CS30042_quads1.out
	./parser.out ass6_20CS30042_test2 > ass6_20CS30042_quads2.out
	./parser.out ass6_20CS30042_test3 > ass6_20CS30042_quads3.out
	./parser.out ass6_20CS30042_test4 > ass6_20CS30042_quads4.out
	./parser.out ass6_20CS30042_test5 > ass6_20CS30042_quads5.out
	@echo "Compiling assembly files\n"
	gcc ass6_20CS30042_test1.s -L. -lass2_20CS30042 -no-pie -o test1
	gcc ass6_20CS30042_test2.s -L. -lass2_20CS30042 -no-pie -o test2
	gcc ass6_20CS30042_test3.s -L. -lass2_20CS30042 -no-pie -o test3
	gcc ass6_20CS30042_test4.s -L. -lass2_20CS30042 -no-pie -o test4
	gcc ass6_20CS30042_test5.s -L. -lass2_20CS30042 -no-pie -o test5
	@echo "Binaries generated. Run using ./test<num>\n\n"
	@echo "Running test1:\n"
	@./test1
	@echo "Running test2:\n"
	@./test2
	@echo "Running test3:\n"
	@./test3
	@echo "Running test4:\n"
	@./test4
	@echo "Running test5:\n"
	@./test5

