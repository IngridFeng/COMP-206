# Assignment3

This is the source code repository that will be used as a starting point for Assignment 3. You should edit this file (README.md) in order to write your responses for Question 2.

## Question 2
### 1)
1. Main takes inputs as command-line arguments. It prints out error message and exits if the number of arguments is smaller than 3.
1. Main first calls function **load_one_preference** from **preferences.c**.
1. **load_one_preference** calls **LOAD_FIELD**, which is defined in the preprocessor of **preferences.c** as **input_fcn_array**: an array of function pointers that points to a number of functions starts with **"input_"**. Also, **LOAD_FIELD** takes the result of function **field_offsets** as one of the inputs.
1. If the flag -DDEBUG is included in the commandline, the line "Target user has preferences:\n" will be printed(this preprocessor is defined in **preferences.h**) and **print_preference** from **preferences.c** will be called. 
1. **print_preference** calls **PRINT_FIELD**, which is defined in the preprocessor of **preferences.c** as **output_fcn_array**: an array of function pointers that points to a number of functions starts with **"output_"**. Also, **PRINT_FIELD** takes the result of function **field_offsets** as one of the inputs.
1. Now, as the for loop loops through the arguments entered, in each iteration, we "printf" is "-DDEBUG" is included and call function **load_one_preference**. Then, we call **print_preference** again if "-DDEBUG" is included. Next, we call **compute_difference_numeric** and **compute_difference_alphabetic**.
1. After the for loop, if "-DDEBUG" is included, we **"printf"** and call **print_preference** again.
1. Also, some other preprocessor macros like **MAX_LINE_LENGTH**, **MAX_FIELD_LENGTH** are defined in **preferences.h** and are used serveral times throughout the program. Type **PREFERENCE_INFO** is defined in **preferences.h** and used in the program.

### 2)
**#define** is a preprocessor macro. From this line(#define LOAD_FIELD( dest, src, field_number )......) until the end, every instance of **LOAD_FIELD** will be replaced by **input_fcn_array**, which is an array of function pointers that points to a number of functions starts with **"input_"**. The array have length **field_number**, which is the input of **LOAD_FIELD**. Two inputs of **input_fcn_array** are calculated from "dest", "src" and the result of function **field_offsets**.

### 3)
The number of bytes distributed to individual field in a struct may not be equal to the usual bytes of the data type of the field. **field_offsets** is using the correct way to compute the offset to each field in the struct because it does not calculate based on bytes but individual field. In this way, each **offsetof** will return the number of bytes from the beginning of a struct to the corresponding field. An example is that **field_offsets[2]** will return **offsetof(struct s_preference_info, favorite_number)**.
