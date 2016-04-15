all: EulerQuestions

EulerShared:
	$(MAKE) -C SharedFunctions
	
runner:
	$(MAKE) -C EulerRunner

EulerQuestions: EulerShared runner
	$(MAKE) -C EulerQuestions

clean:
	rm -rf out
	rm -rf obj
	rm -rf include

