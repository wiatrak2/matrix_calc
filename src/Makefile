Flags = -Wreturn-type -pedantic -pedantic-errors -Wundef -std=c++11
CPP = g++


main : Makefile   main.o rational.o
	$(CPP) $(Flags) -o main   main.o rational.o

main.o : Makefile   main.cpp   rational.h vector.h imaginary.h matrix.h square_matrix.h identity_matrix.h equation_matrix.h
	$(CPP) -c $(Flags) main.cpp -o  main.o

rational.o : Makefile   rational.cpp   rational.h 
	$(CPP) -c $(Flags) rational.cpp -o  rational.o

clean:
	rm *.o
	rm main