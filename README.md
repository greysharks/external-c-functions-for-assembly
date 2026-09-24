This project is a preview of importing custom c functions into assembly programs. 

I also created the external function for this example. It takes two 32-bit (unsigned) values as arguments and returns a pointer to address in memory where two 32-bit elements will be stored. They are results of lossless multiplication of these two 32-bit arguments. The first element of the result consist of lower 32-bits of result and the second element consists of higher 32-bits of the result.

After:
A<sub>N</sub> x B<sub>N</sub> = AxB<sub>2xN</sub>

And:
AxB<sub>2xN</sub> = AxB<sub>0</sub> + AxB<sub>1</sub>

Where:
0 < AxB<sub>0</sub> < N,
N < AxB<sub>1</sub> < 2xN
