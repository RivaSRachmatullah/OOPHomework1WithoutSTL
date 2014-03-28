# - Berikut adalah contoh Makefile untuk autograde
# - Harus ada perintah compile-test untuk kompilasi dan grade untuk eksekusi
# - OUTPUT adalah variabel yang diperlukan, tidak perlu diubah.
# - ADT dan MAIN adalah variabel yang berisi nama-nama file,
#   silahkan diubah sesuai kebutuhan.

OUTPUT=bin
ADT1=Time/Time
ADT2=Date/Date
ADT3=DateTime/DateTime
ADT4=Queue/Queue
ADT5=Teller/Teller
ADT6=Event/Event
MAIN=main

compile-test: $(MAIN).cpp $(ADT6).o $(ADT1).o $(ADT2).o $(ADT3).o $(ADT4).o $(ADT5).o
	g++ -o $(MAIN) $(MAIN).cpp $(ADT6).o $(ADT1).o $(ADT2).o $(ADT3).o $(ADT4).o $(ADT5).o

$(ADT1).o: $(ADT6).cpp $(ADT6).h $(ADT1).o $(ADT2).o $(ADT3).o $(ADT4).o $(ADT5).o
	g++ -c $(ADT6).cpp $(ADT1).o $(ADT2).o $(ADT3).o $(ADT4).o $(ADT5).o

$(ADT1).o: $(ADT1).cpp $(ADT1).h
	g++ -c $(ADT1).cpp

$(ADT2).o: $(ADT2).cpp $(ADT2).h
	g++ -c $(ADT2).cpp

$(ADT3).o: $(ADT3).cpp $(ADT3).h $(ADT1).o $(ADT2).o
	g++ -c $(ADT3).cpp $(ADT1).o $(ADT2).o

$(ADT4).o: $(ADT4).cpp $(ADT4).h
	g++ -c $(ADT4).cpp

$(ADT5).o: $(ADT5).cpp $(ADT5).h $(ADT4).o
	g++ -c $(ADT5).cpp $(ADT4).o

grade:
	./$(MAIN)
