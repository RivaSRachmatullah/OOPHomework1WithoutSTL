# - Berikut adalah contoh Makefile untuk autograde
# - Harus ada perintah compile-test untuk kompilasi dan grade untuk eksekusi
# - OUTPUT adalah variabel yang diperlukan, tidak perlu diubah.
# - ADT dan MAIN adalah variabel yang berisi nama-nama file,
#   silahkan diubah sesuai kebutuhan.

OUTPUT=bin
ADT1=../Time/Time
ADT2=../Date/Date
ADT=DateTime
MAIN=mDateTime

compile-test: $(MAIN).cpp $(ADT).o $(ADT1).o $(ADT2).o
	g++ -o $(MAIN) $(MAIN).cpp $(ADT).o $(ADT1).o $(ADT2).o

$(ADT1).o: $(ADT1).cpp $(ADT1).h
	g++ -c $(ADT1).cpp

$(ADT2).o: $(ADT2).cpp $(ADT2).h
	g++ -c $(ADT2).cpp

$(ADT3).o: $(ADT).cpp $(ADT).h $(ADT1).o $(ADT2).o
	g++ -c $(ADT).cpp $(ADT1).o $(ADT2).o

grade:
	./$(MAIN)
