*This project has been created as part of the 42 curriculum by lbordana*

## Description

Codexion is all about working with threads. Every threads initiated is running a routine
until the end. The two main advantages of multithread coding is the sharing of computational
resources but also, the ability to run multiple functions at the same time.

## Instructions

You must first compile the file like this :

```bash
make
```

Then, you can run the program with :

```bash
./codexion <number_of_coders> <time_to_burnout> <time_to_compile>
<time_to_debug> <time_to_refactor> <number_of_compiles_required>
<dongle_cooldown> <scheduler>
```

For each argue, please enter right values :

number_of_coders : 1-250\
time_to_burnout : 1-60000\
time_to_compile : 0-60000\
time_to_debug : 0-60000\
time_to_refactor : 0-60000\
number_of_compiles_required : 1-60000\
dongle_cooldown : 0-60000\
scheduler : 'fifo' (First in - First out) or 'edf' (Earliest deadline first)

## Resources

As I did not use AI, here are some tutorials I used to understand how pthread was working :

	- https://franckh.developpez.com/tutoriels/posix/pthreads/
	- https://tala-informatique.fr/index.php?title=C_pthread
	- https://www.youtube.com/watch?v=o_GbRujGCnM

## Blocking cases handled

For a while, I stuttered with timing, has I didn't know what was really "required" by the subject in terms of performance.
Then, after asking several people, they explained to me the timing composition.

Also valgrind mutex verification was pretty annoying because of pretended possible data race.
Even if those were never appearing, I choose to protect every variable writing and reading during routine.

## Thread synchronization mechanisms

The mechanisms used were basic, I did not went through pthread_cond mechanisms as it was not feeling as
familiar than a sleepy while loop in my cases.

However, the main mechanisms were implemented in order to protect data race or deadlock.

At first, I am initializing all my coders and my monitor threads with pthread_create.
Then, I am using a pthread_join on the monitor that will run until the end of the program.

I am also joining every threads to complete their refactoring session after that.

During routine execution, I have also implemented custom mutexes functions with pthread_lock and pthread_unlock, that ensure that no data race is possible.
