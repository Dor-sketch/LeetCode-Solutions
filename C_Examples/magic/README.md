# Magic Square Checker 🌟🔍

## Overview 📖

This C program checks if a given square matrix is a "Magic Square". A Magic Square is a square grid filled with distinct integers such that the sum of numbers in each row, column, and both main diagonals is the same.

This program was created as part of the _Systems Programming 20465_ course in the 2022a semester at _The Open University of Israel_ and achieved a perfect score. 🎓🌟

![Alt text](cover.png)

---

## Features ✨

- **Input Validation**: Ensures only valid integers are entered.
- **Matrix Creation**: Dynamically generates a square matrix based on user input.
- **Magic Square Verification**: Checks if the matrix is a magic square.
- **User-Friendly**: Provides clear instructions and feedback.

## How to Use 🛠️

1. **Enter Matrix Size**: You will be prompted to enter the size of the square (1-9).
2. **Fill the Matrix**: Enter the required number of integers to fill the matrix.
3. **Magic Square Check**: The program will then evaluate if the matrix is a magic square and display the result.

## Examples 📝

_3x3 Magic Square:_
![Alt text](./examples/3x3%20magic%20square.png)

_3x3 Non-Magic Square:_
![Alt text](./examples/3x3%20not%20a%20magic%20square.png)

_5*5 Magic Square:_
![Alt text](./examples/5x5%20magic%20square.png)

_invalid input:_
![Alt text](./examples/invalid%20input%20error.png)

_too many inputs:_
![Alt text](./examples/too%20many%20or%20not%20enough%20numbers%20error.png)

## Components 🧩

- `is_valid_char`: Checks if a character is a valid digit or whitespace.
- `get_char_and_skip_spaces`: Reads characters, skipping whitespaces.
- `get_num`: Converts character digits to an integer.
- `is_square`: Verifies if the correct number of inputs is provided.
- `print_mat`: Prints the matrix.
- `check_diagonal`, `check_row_col`, `is_magic`: Functions to check if the matrix is a magic square.
- `print_mat_with_index`: Displays the matrix with indexes.
- `free_mat`: Frees allocated memory.
- `new_square`: Main function to create and test the square.

## Limitations ⚠️

- The matrix size is limited to a 9x9 grid.
- Only integer inputs are accepted.

## Contributing 🤝

Feel free to fork the repo and submit pull requests for improvements!

## License 📜

This project is open source and available under the [MIT License](LICENSE).

---

_Enjoy checking your magic squares! 🎩✨_
