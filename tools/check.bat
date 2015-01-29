:loop
	mk > A.in
	A < A.in > A.out
	p < A.in > p.out
	fc A.out p.out
	if errorlevel 1 goto end
	goto loop
:end
	pause
