# DNA Matching using Trie Data Structure

This project implements a trie data structure in the C programming language, along with a static library that encapsulates the trie functionality. Tries are tree-like structures that are particularly efficient for storing and searching associative data, such as strings. The project also includes an application showcasing the use of the trie data structure for DNA sequence matching.

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Usage](#usage)
- [Applications](#applications)
- [Contributing](#contributing)
- [License](#license)

## Introduction

In this project, we implement a trie data structure in C, providing efficient methods for inserting strings and searching for prefixes or complete words. The code is organized into modular files to ensure maintainability and separation of concerns.

## Features

- Trie creation and insertion of strings.
- String search and prefix search operations.
- Memory-efficient storage of similar prefixes.
- Encapsulation of trie functionality in a static library.
- Demonstration of a real-world application using DNA sequence matching.

## Usage

To utilize the trie data structure, follow these steps:

1. Clone the repository: `git clone https://github.com/your-username/trie-data-structure-c.git`
2. Navigate to the project directory: `cd trie-data-structure-c`
3. Build the static library: `gcc -c node.c -o node.o` and `gcc -c trie.c -o trie.o`
4. Create the static library file: `ar rcs libtrie.a node.o trie.o`
5. Include the `trie.h` and `node.h` headers in your source code to use the provided functions.
6. Link the `libtrie.a` static library while compiling your project. For example:
   `gcc your_source_code_file.c -o output_file -L. -lmylib`

## Application

DNA Sequence Matching
One significant application of this trie implementation is in DNA sequence matching. DNA encodes genetic information using four nucleotide bases: Adenine (A), Thymine (T), Cytosine (C), and Guanine (G). This project demonstrates how a trie efficiently stores and searches DNA sequences, allowing you to match sequences, identify common prefixes, and analyze genetic data.

## Contributing

Contributions to this project are welcomed and encouraged. Whether you want to fix a bug, improve the code, or add new features, your contributions can make this project even better. Here's how you can contribute:

### Getting Started

1. Fork this repository to your own GitHub account.
2. Clone the forked repository to your local machine.
3. Create a new branch for your contributions: `git checkout -b feature/your-feature-name`
4. Make your changes and commit them: `git commit -am 'Add some feature'`
5. Push your changes to your forked repository: `git push origin feature/your-feature-name`
6. Create a pull request from your forked repository to this repository's `main` branch.

### Guidelines for Naming Files

When contributing new files, please follow these naming conventions:

- Use descriptive and meaningful names for your files.
- Use lowercase letters for file names.
- Separate words with hyphens (`-`) rather than underscores (`_`).
- If you're adding a new source code file, name it appropriately based on its purpose (e.g., `new-feature.c`).

### Coding Standards

Please adhere to the following coding standards to maintain consistency in the codebase:

- Use meaningful variable and function names.
- Follow the existing code formatting style.
- Use comments to explain complex sections of code.

### Reporting Issues

If you find a bug or have a suggestion for improvement, please open an issue on the GitHub repository. Provide detailed information about the issue and steps to reproduce it if applicable.

Thank you for considering contributing to this project! Your involvement helps to build a vibrant and thriving open-source community.

## License

This project is licensed under the [MIT License](LICENSE).
