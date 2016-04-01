all: EulerShared EulerQuestions

EulerShared:
	$(MAKE) -C SharedFunctions
	
EulerQuestions: EulerShared
	$(MAKE) -C EulerQuestions

clean:
	rm -rf out
	rm -rf obj
	rm -rf include
