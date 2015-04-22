all: pdf done

pdf: GuessEver.tex
	xelatex GuessEver.tex
	xelatex GuessEver.tex

done:	
	rm -f *.toc *.log *.out *.aux

clean:
	rm -f *.toc *.log *.out *.aux *.pdf
