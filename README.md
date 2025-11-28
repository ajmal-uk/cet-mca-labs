
# CET MCA Labs — 2025–27 Batch

Welcome to the CET MCA labs repository. This repository collects the lab programs and web assignments for the CET MCA 2025–27 batch. It contains implementations in C (data structures & algorithms), Python (various exercises and small projects), and web files (HTML/CSS/JS and PHP).

---

## Table of Contents

- [Overview](#overview)
- [Repository Structure](#repository-structure)
- [Prerequisites](#prerequisites)
- [How to Run Examples](#how-to-run-examples)
	- [C (GCC)](#c-gcc)
	- [Python](#python)
	- [Web / Static Files](#web--static-files)
	- [PHP (Built-in server)](#php-built-in-server)
- [Contributing](#contributing)
- [Notes & Tips](#notes--tips)
- [Contact](#contact)
- [License](#license)

---

## Overview

This repository is a student collection of laboratory assignments, sample programs, and small web projects for the CET MCA course. The code is intended for learning and demonstration purposes.

## Repository Structure

Top-level folders and a short description of their contents:

- `sem1/ads/` — C programs focused on data structures and algorithms (graphs, trees, queues, stacks, sorting, etc.).
- `sem1/python/` — Python practice programs and mini projects including a small `graphics` package and cycle-specific folders.
- `sem1/web/` — Web pages and a simple PHP backend for small projects; static HTML, CSS, and example PHP apps.

See the repo itself for detailed organization — folders are grouped by semester and subject.

## Prerequisites

Install these tools locally before running code examples:

- GCC (for C programs): brew install gcc or install Xcode command line tools
- Python 3 (for Python scripts): brew install python or use system Python 3
- A web browser (for HTML)
- PHP (to run PHP files): brew install php

---

## How to Run Examples

Choose a category below and follow the examples.

### C (GCC)

To compile and run a C program (example — BFS):

```bash
# Compile
gcc -Wall -Wextra -std=c11 -O2 sem1/ads/bfs.c -o bfs

# Run
./bfs
```

To compile all `.c` files in a directory and run a specific program, adjust the file paths accordingly.

### Python

Run simple Python programs with Python 3. Example:

```bash
python3 sem1/python/program2.py
```

If a Python file imports from a package (e.g., the `graphics` package), run it from the project root or add the package to `PYTHONPATH`:

```bash
python3 -m sem1.python.cycle\ 3.graphics.circle  # if that path is correct and is a Python package
# or run from the directory where package imports resolve:
cd sem1/python && python3 -m cycle\ 3.graphics.circle
```

Tip: avoid spaces in folder names (e.g., `cycle 1`) when using command line tools — use quotes around paths or rename folders to `cycle-1`.

### Web / Static Files

To preview static HTML files locally, start a simple HTTP server from the project root:

```bash
# Serve files under the repository root on port 8000
python3 -m http.server 8000 --directory ./web

# Open in browser: http://localhost:8000/program1.html
```

Alternatively, use the VS Code Live Server extension to serve and live-reload HTML files.

### PHP (Built-in server)

To test PHP files, start the built-in PHP server and point the document root to the `web/php` folder:

```bash
cd web/php
php -S localhost:8000

# Open in browser: http://localhost:8000/data.php
```

If PHP pages rely on `$_SERVER` variables or form handling, the built-in server is a quick way to test functionality.

---

## Contributing

Thanks for contributing! To add or update code, please follow these steps:

1. Fork the repository and create a feature branch off `main`:

```bash
git checkout -b feat/add-topic-name
```

2. Add or update your files; follow the folder structure by semester and topic.
3. Write clear commit messages and add a short description to the PR.
4. Create a pull request against `main` and describe what you changed.

Guidelines:
- Keep code simple and readable; add comments for important logic.
- For C files, compile with `-Wall -Wextra` and make sure there are no warnings if possible.
- Avoid committing large binary files; use text or source code files instead.

---

## Notes & Tips

- Folder paths sometimes contain spaces (e.g., `cycle 1`) — avoid issues by using quotes in commands or renaming them to `cycle-1`.
- If you want the entire repo to compile or run as a course project, consider adding small Makefiles or a simple script to compile relevant C programs and run Python scripts.

---

## Contact

Repository owner: `ajmal-uk` (GitHub). If you need help, you can open an issue in this repository.

---

## License

This repository currently does not include a license. If you'd like, I can add a recommended license such as the MIT license to make it easier for others to reuse the code.

---

If you'd like me to also add an example Makefile, rename folders (e.g., remove spaces), or include a sample script to automate compiling/running common programs, tell me which option to implement next and I'll add it.

