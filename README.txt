To compile: `make all`.

To run: execute file `dvrp`. Make sure it's in the same directory as
a file named NodeConfigurationFile. There's not too much special going
on here.

I'll save you some time, though -- all the code you're looking for is in
nodeX.h/c. The other four node source files are gutted and basically just
call into functions defined in nodeX.c -- that way, all nodes behave
identically and there's less code to mention.

--Christopher Myers