# Minishell - My Custom Shell


*My shell programming project*
---
## What is this?
**Minishell** is a custom UNIX shell that works like bash that I wrote myself. It's a school project that helps me learn how operating systems work, how processes communicate, and how shells interpret commands. I'll use this system programming knowledge in other projects later.

---

## What I Built

### Built-in Commands
- **Navigation**: `cd` - change directories
- **Output**: `echo` - print text to terminal
- **Environment**: `env`, `export`, `unset` - manage variables

### Shell Features
- **Command Execution**: Run any program on the system
- **Pipes**: Connect commands with `|` operator
- **Redirections**: Use `>`, `<`, `>>` for file input/output

### Process Management
- `Fork/Exec`: Create and run new processes
- `Signal Handling`: Handle Ctrl+C, Ctrl+D, Ctrl+\
- `Exit Status`: Track command success/failure

---

## How to use it

### What you need
To use this shell, you need:
- A C compiler (like `gcc`) to turn code into programs.
- A computer with Linux or macOS.

### How to set it up
1. Download the code:
   ```bash
   git clone git@github.com:mkatfi/minishell.git
   cd minishell


2. Build the shell:
   ```bash
   make
   ```

   This makes a program called `minishell` that runs like bash.

---

## Who made this
Made by **mouadisfree** as a student at **1337 School** (part of the 42 coding schools).

---

## Thanks
Thanks to 1337 School and all my peers who helped me learn!
