all: EulerQuestions

LIBS = $(wildcard out/*.so)
EulerShared:
	$(MAKE) -C SharedFunctions

runner:
	$(MAKE) -C EulerRunner

EulerQuestions: EulerShared runner
	$(MAKE) -C EulerQuestions

install: all
	mkdir -p ~/lib

	cp $(LIBS) ~/lib

run: install
	out/EulerQuestions
clean:
	rm -rf out
	rm -rf obj
	rm -rf include
