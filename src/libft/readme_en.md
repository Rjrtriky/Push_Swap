libft
📖 Description

Definition:

Libft is a custom implementation of functions from the C standard library, created as part of the 42 curriculum. This project includes personal versions of common functions from string.h, ctype.h, stdlib.h, and more, as well as additional functions useful for string and memory manipulation.

Implemented Functions:
Character Functions (ctype.h)

-ft_isalpha: Checks if a character is alphabetic
	int ft_isalpha(int nbr);
		Input parameters:
			c: The character to evaluate (passed as int for compatibility)
		Result:
			Correct: 1 if the character is a letter (A-Z or a-z)
			Error: 0 if the character is not a letter
-ft_isdigit: Checks if a character is a decimal digit
	int ft_isdigit(int nbr);
		Input parameters:
			c: The character to evaluate (passed as int for compatibility)
		Result:
			Correct: 1 if the character is a digit (0-9)
			Error: 0 if the character is not a digit
-ft_isalnum: Checks if the character is alphanumeric (letter or digit)
	int ft_isalnum(int nbr);
		Input parameters:
			c: The character to evaluate (passed as int for compatibility)
		Result:
			Correct: 1 if the character is a letter (A-Z or a-z) or a digit (0-9)
			Error: 0 if the character is not alphanumeric
-ft_isascii: Checks if the value corresponds to a valid ASCII character
	int ft_isascii(int nbr);
		Input parameters:
			c: The value to evaluate (passed as int for compatibility)
		Result:
			Correct: 1 if the value is within the ASCII range (0-127)
			Error: 0 if the value is outside the ASCII range
-ft_isprint: Checks if the character is printable (including space)
	int ft_isprint(int nbr);
		Input parameters:
			c: The character to evaluate (passed as int for compatibility)
		Result:
			Correct: 1 if the character is printable (32-126 in ASCII)
			Error: 0 if the character is not printable (0-31 and 127 in ASCII)
-ft_toupper: Converts a lowercase character to uppercase
	int ft_toupper(int c);
		Input parameters:
			c: The character to convert (passed as int for compatibility)
		Result:
			Correct: Character in uppercase if it was lowercase
			Error: The same character unchanged if it was not lowercase
-ft_tolower: Converts an uppercase character to lowercase
	int ft_tolower(int c);
		Input parameters:
			c: The character to convert (passed as int for compatibility)
		Result:
			Correct: Character in lowercase if it was uppercase
			Error: The same character unchanged if it was not uppercase

String Functions (string.h)

-ft_strlen: Calculates the length of a character string
		size_t ft_strlen(const char *str);
		Input parameters:
			s: The string from which to calculate the length
		Result:
			Correct: Number of characters before the null terminator
			Error: Undefined behavior if the string is null
-ft_strchr: Searches for the first occurrence of a character in a string
	char *ft_strchr(const char *s, int c);
		Input parameters:
			s: The string to search in
			c: The character to search for (passed as int, converted to char)
		Result:
			Correct: Pointer to the first occurrence of the character
			Error: NULL if the character is not found in the string
-ft_strrchr: Searches for the last occurrence of a character in a string
	char *ft_strrchr(const char *s, int c);
		Input parameters:
			s: The string to search in
			c: The character to search for (passed as int, converted to char)
		Result:
			Correct: Pointer to the last occurrence of the character
			Error: NULL if the character is not found in the string
-ft_strncmp: Compares two strings up to a maximum number of characters
	int ft_strncmp(const char *s1, const char *s2, size_t size);
		Input parameters:
			s1: First string to compare
			s2: Second string to compare
			n: Maximum number of characters to compare
		Result:
			Equal: 0 if the strings are equal in the first n characters
			Difference: Non-zero integer indicating the difference (positive if s1 > s2, negative if s1 < s2)
-ft_strlcpy: Copies a string to a buffer with size limit, guaranteeing null termination
	size_t ft_strlcpy(char *dest, const char *src, size_t size);
		Input parameters:
			dest: Destination buffer where the string will be copied
			src: Source string to copy
			size: Size of the destination buffer
		Result:
			Length of the source string (excluding the null terminator)
-ft_strlcat: Concatenates two strings safely, limiting the total size
	size_t ft_strlcat(char *dest, const char *src, size_t size);
		Input parameters:
			dst: Pointer to the destination buffer
			src: Pointer to the source string to concatenate
			size: Total size of the destination buffer
		Result:
			Total length the resulting string would have (without the null final)
-ft_strnstr: Searches for the first occurrence of a substring in a string, with length limit
	char *ft_strnstr(const char *big, const char *little, size_t len);
		Input parameters:
			haystack: Main string to search in
			needle: Substring to search for
			len: Maximum number of characters to examine in haystack
		Result:
			Correct: Pointer to the first occurrence of needle in haystack
			Error: NULL if needle is not found within the first len characters
-ft_strdup: Creates a clone of a string variable in memory
	char *ft_strdup(const char *ori);
		Input parameters:
			ori: Pointer to the original string to duplicate
		Result:
			Correct: Pointer with the new memory address where the duplicate string is located
			Error: NULL
-ft_substr: Allocates memory and returns a substring of the string 's'
	char *ft_substr(char const *s, unsigned int start, size_t len);
		Input parameters:
			s: The string from which to create the substring
			start: The index of the character in 's' from which to start the substring
			len: The maximum length of the substring
		Result:
			Correct: Substring created with malloc
			Error: NULL if memory allocation fails
-ft_strjoin: Generates a pointer to a new string that is the union of the 2 passed as parameters
	char *ft_strjoin(char const *s1, char const *s2);
		Input parameters:
			s1: Pointer to the first string
			s2: Pointer to the second string
		Result:
			Correct: Pointer to the new string
			Error: NULL if memory allocation fails
-ft_strtrim: Removes the characters specified in 'set' from the beginning and end of string s1
	char *ft_strtrim(char const *s1, char const *set);
		Input parameters:
			s1: The string to be trimmed
			set: The characters to remove from the string
		Result:
			Correct: Trimmed string
			Error: NULL if memory allocation fails
-ft_split: Divides a string into substrings using a delimiter character
	char **ft_split(char const *s, char c);
		Input parameters:
			s: String to separate
			c: Delimiter character
		Result:
			Correct: The array of new strings resulting from the separation
			Error: NULL if memory allocation fails
-ft_strmapi: Applies a function to each character of a string creating a new string with the results
	char *ft_strmapi(char const *s, char (*f)(unsigned int, char));
		Input parameters:
			s: The string to iterate
			f: The function to apply to each character
		Result:
			Correct: The string created after correctly using 'f' on each character
			Error: NULL if memory allocation fails
-ft_striteri: Applies a function to each character of a string, passing its index
	void ft_striteri(char *s, void (*f)(unsigned int, char*));
		Input parameters:
			s: The string to iterate
			f: The function to apply to each character
		Result: Nothing

Memory Functions (string.h)

-ft_memset: Fills a block of memory with a specific value
	void *ft_memset(void *ptr, int value, size_t len);
		Input parameters:
			s: Pointer to the block of memory to fill
			c: Value to set (passed as int, converted to unsigned char)
			n: Number of bytes to set
		Result:
			Correct: Pointer to the original memory block
-ft_bzero: Writes zeros to a memory area of specified size
	void *ft_bzero(void *ptr, size_t len);
		Input parameters:
			s: Pointer to the memory block to initialize
			n: Number of bytes to set to zero
		Result: No return value (void function)
-ft_memcpy: Copies n bytes from a source memory area to a destination memory area
	void *ft_memcpy(void *dest, const void *org, size_t len);
		Input parameters:
			dest: Pointer to the destination memory block
			src: Pointer to the source memory block
			n: Number of bytes to copy
		Result:
			Correct: Pointer to the destination memory block
			Error: Undefined behavior if the blocks overlap
-ft_memmove: Copies n bytes from one memory area to another, handling overlaps
	void *ft_memmove(void *dest, const void *org, size_t len);
		Input parameters:
			dest: Pointer to the destination memory block
			src: Pointer to the source memory block
			n: Number of bytes to copy
		Result:
			Correct: Pointer to the destination memory block
-ft_memchr: Searches for the first occurrence of a character in a memory block
	void *ft_memchr(const void *str, int c, size_t len);
		Input parameters:
			s: Pointer to the memory block where the search is performed
			c: Character to search for (passed as int, converted to unsigned char)
			n: Number of bytes to examine
		Result:
			Correct: Pointer to the first occurrence of the character
			Error: NULL if the character is not found in the first n bytes
-ft_memcmp: Compares two memory blocks byte by byte
	int ft_memcmp(const void *s1, const void *s2, size_t n);
		Input parameters:
			s1: Pointer to the first memory block
			s2: Pointer to the second memory block
			n: Number of bytes to compare
		Result:
			Correct: 0 if the blocks are equal in the first n bytes
			Difference: Non-zero integer indicating the difference (positive if s1 > s2, negative if s1 < s2)
-ft_calloc: Allocates memory space and sets the entire space to 0
	void *ft_calloc(size_t num, size_t size);
		Input parameters:
			num: number of variables
			size: size of the variables
		Result:
			Correct: pointer to the reserved memory address
			Error: NULL

Conversion Functions (stdlib.h)

-ft_atoi: Converts a string to an integer. Limits the number to int limits, both upper and lower
	int ft_atoi(const char *str);
		Input parameters:
			s: A pointer to a string
		Result:
			Correct: An integer number
			Error: 0
-ft_itoa: Generates a string representing the integer value received as an argument
	char *ft_itoa(int n);
		Input parameters:
			n: the integer to convert
		Result:
			Correct: The string representing the number
			Error: NULL if memory allocation fails

Output Functions

-ft_putchar_fd: Prints a character using write on the specified file descriptor
	void ft_putchar_fd(char c, int fd);
		Input parameters:
			c: character to write
			fd: file to write to (STDIN_FILENO=0, STDOUT_FILENO=1, STDERR_FILENO=2)
		Result: Nothing
-ft_putstr_fd: Sends a string to the specified file
	void ft_putstr_fd(char *s, int fd);
		Input parameters:
			s: string to write
			fd: file to write to (STDIN_FILENO=0, STDOUT_FILENO=1, STDERR_FILENO=2)
		Result: Nothing
-ft_putendl_fd: Prints a string followed by a newline in an output file
	void ft_putendl_fd(char *s, int fd);
		Input parameters:
			s: string to write
			fd: file to write to (STDIN_FILENO=0, STDOUT_FILENO=1, STDERR_FILENO=2)
		Result: Nothing
-ft_putnbr_fd: Prints an integer in an output file that is indicated
	void ft_putnbr_fd(int n, int fd);
		Input parameters:
			n: integer number to write
			fd: file to write to (STDIN_FILENO=0, STDOUT_FILENO=1, STDERR_FILENO=2)
		Result: Nothing
Bonus Linked List Functions

-ft_lstnew: Creates a new node (malloc) with the content 'content' and the pointer to the next node set to NULL
	t_list *ft_lstnew(void *content);
		Input parameters:
			content: the content with which to create the node
		Result:
			Correct: Returns the new node
			Error: Returns NULL if memory allocation fails
-ft_lstadd_front: Adds the node 'new' to the beginning of the list 'lst'
	void ft_lstadd_front(t_list **lst, t_list *new);
		Input parameters:
			lst: the address of a pointer to the first node of a list
			new: a pointer to the node to add to the beginning of the list
		Result: Nothing
-ft_lstadd_back: Adds the new node sent as a parameter to the end of the list
	void ft_lstadd_back(t_list **lst, t_list *new);
		Input parameters:
			lst: the pointer to the first node of a list
			new: the pointer to a node to add to the list
		Result: None
-ft_lstsize: Counts the number of nodes in a list
	int ft_lstsize(t_list *lst);
		Input parameters:
			lst: the beginning of the list
		Result:
			Correct: Number of nodes in the list
-ft_lstlast: Returns the last node of the list
	t_list *ft_lstlast(t_list *lst);
		Input parameters:
			lst: pointer to the first node of the list
		Result:
			Pointer to the last node of the list
-ft_lstdelone: Takes a node 'lst' as a parameter and frees the memory of the content using the function 'del', in addition to freeing the node
	void ft_lstdelone(t_list *lst, void (*del)(void*));
		Input parameters:
			lst: the node to free
			del: a pointer to the function used to free the node's content
		Result: Nothing
-ft_lstclear: Deletes and frees the given node 'lst' and all consecutive nodes of that node, using the function 'del' and free(3)
	void ft_lstclear(t_list **lst, void (*del)(void*));
		Input parameters:
			lst: the address of a pointer to a node
			del: a pointer to a function used to delete the content of a node
		Result: Nothing
-ft_lstiter: Iterates the list 'lst' and applies the function 'f' to the content of each node
	void ft_lstiter(t_list *lst, void (*f)(void *));
		Input parameters:
			lst: a pointer to the first node
			f: a pointer to the function that will be used by each node
		Result: Nothing
-ft_lstmap: Iterates the list 'lst' and applies the function 'f' to the content of each node. Creates a resulting list
	t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
		Input parameters:
			lst: a pointer to a node
			f: the address of a pointer to a function used in the iteration
			del: a pointer to a function used to delete the content of a node
		Result:
			Correct: The new list
			Error: NULL if memory allocation fails

⚙️ Instructions

COMPILATION

make
make bonus

Makefile options

	make clean	# Removes object files (.o)
	make fclean	# Removes object files and the library
	make re		# Recompiles everything from scratch
	make all	# Compiles the basic library (default)

INCLUDE IN PROJECT

In the file header you must include:

#include "libft.h"

FUNCTION DESCRIPTIONS:

📚 Resources

CLASSIC REFERENCES:

-Documentation of read() on Linux with man and at https://man7.org/linux/man-pages/man2/read.2.html
-Tutorials on dynamic memory management in C.
-Examples of previous 42 projects related to libft.
