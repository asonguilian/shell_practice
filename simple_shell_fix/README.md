
# Simple Shell project

This is a simple UNIX command interpreter
This simple shell was built during the ALX SWE program


### Invocation

Usage: **shell**

```
gcc -Wall -Werror -Wextra -pedantic *.c -o shell
./shell
```
**shell** is allowed to be invoked interactively and non-interactively. If **shell** is invoked with standard input not connected to a terminal, it reads and executes received commands in order.

Example:
```
$ echo "echo 'ALX is not for the soft hearted'" | ./sodash
'ALX is not for the soft hearted'
$
```

When **shell** is invoked with standard input connected to a terminal (determined by isatty(3), the interactive mode is opened.
**shell** Will be using the following prompt `#cisfun$`.

Example:
```
$./shell
#cisfun$
```


## Authors & Copyrights

* Guilian Asongtia
* Victory Amadi
