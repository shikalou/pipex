# 42 project - pipex

## How to recreate the shell pipe in C !

The project goal is to reproduce the pipe behaviour in a command line with the pipe() command of the libc.

### How to run the program

```bash
  ./pipex [infile] [cmd1] [cmd2] ... [cmdn] [outfile]
```
should behave like ``< infile cmd1 | cmd2 ... | cmdn > outfile``

OR

```bash
 ./pipex here_doc LIMITER [cmd1] [cmd2] ... [cmdn] [outfile]
```
should behave like ``cmd1 << LIMITER | cmd2 ... | cmdn >> file``
