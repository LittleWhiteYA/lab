BMI: BMI.o main.o
	g++ -o BMI BMI.o main.o

BMI.o: BMI.cpp BMI.h
	g++ -c BMI.cpp

main.o: main.cpp BMI.h
	g++ -c main.cpp

clean:
	rm BMI *.o
