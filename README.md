*This project has been created as part of the 42 curriculum by hikaru.*

# ft_printf

## Description

`ft_printf` is a reimplementation of the C standard library function `printf()`.
The goal of the project is to learn how **variadic functions** work in C
(`va_start`, `va_arg`, `va_end`) and to build a small, reusable formatted
output function that can be added to my `libft` for future projects.

The function is compiled into a static library, `libftprintf.a`, which also
contains the whole `libft`.

```c
int ft_printf(const char *format, ...);
```

Like the original, it writes to the standard output and returns the number of
characters printed.

### Supported conversions

| Conversion | Description                                         | Example                        | Output       |
|------------|-----------------------------------------------------|--------------------------------|--------------|
| `%c`       | A single character                                  | `ft_printf("%c", 'A')`         | `A`          |
| `%s`       | A string (`(null)` if the pointer is `NULL`)        | `ft_printf("%s", "42")`        | `42`         |
| `%p`       | A pointer address in hexadecimal (`(nil)` if `NULL`)| `ft_printf("%p", &x)`          | `0x7ffd...`  |
| `%d`       | A signed decimal integer                            | `ft_printf("%d", -42)`         | `-42`        |
| `%i`       | A signed decimal integer                            | `ft_printf("%i", 42)`          | `42`         |
| `%u`       | An unsigned decimal integer                         | `ft_printf("%u", -1)`          | `4294967295` |
| `%x`       | An unsigned integer in lowercase hexadecimal        | `ft_printf("%x", -15)`         | `fffffff1`   |
| `%X`       | An unsigned integer in uppercase hexadecimal        | `ft_printf("%X", 255)`         | `FF`         |
| `%%`       | A literal percent sign                              | `ft_printf("%%")`              | `%`          |

## Instructions

### Compilation

```bash
make        # builds libft, then libftprintf.a
make clean  # removes object files
make fclean # removes object files and libraries
make re     # fclean + all
```

The project is compiled with `cc -Wall -Wextra -Werror`.

### Usage

Include the header and link the library:

```c
#include "ft_printf.h"

int main(void)
{
    int len;

    len = ft_printf("Hello %s, you are %d years old (%x in hex)\n", "world", 42, 42);
    ft_printf("%d characters printed\n", len);
    return (0);
}
```

```bash
cc main.c -L. -lftprintf -I. -Ilibft -o ft_printf_test
./ft_printf_test
```

## Algorithm and data structure

### Overall flow

1. `ft_printf()` initialises a `va_list` and a character counter `count`,
   then hands both to `parse()`.
2. `parse()` walks through the format string **once**, character by character:
   - a regular character is written immediately and `count` is incremented;
   - when a `%` is found, the next character (the conversion specifier) is
     sent to a dispatcher, and the index jumps by 2.
3. The dispatcher (`arg_detected()`) calls the right handler
   (`handle_char`, `handle_string`, `handle_int`, ...) based on the specifier.
4. Each handler pulls its argument with `va_arg`, converts it to text, writes
   it, and adds the number of written characters to `count`.
5. `ft_printf()` closes the `va_list` and returns `count`.

### Data structures

No complex data structure is needed: the format string is processed as a
stream, so there is nothing to store between conversions.

- The **`va_list` is passed by pointer** (`va_list *`) to every function, so
  that each `va_arg` call advances the same list. Passing it by value would be
  unsafe: the C standard leaves the state of a `va_list` undefined after it was
  used in a called function.
- The **character counter is passed by pointer** (`int *count`), so that every
  handler can update the single shared total that `ft_printf` returns, without
  global variables.

### Number conversions

- **`%d` / `%i`** reuse `ft_itoa` from `libft`, which already handles the sign
  and `INT_MIN`.
- **`%u`** uses its own conversion, because the value is read as an
  `unsigned int` (e.g. `-1` prints `4294967295`).
- **`%x` / `%X`** share one function, `ft_convert_tob16(nb, caps)`. It counts
  the digits first, allocates exactly the needed size, then fills the string
  from right to left with `base[nb % 16]`. The `caps` flag only switches the
  base string between `"0123456789abcdef"` and `"0123456789ABCDEF"`, which
  avoids duplicated code. The argument is read as an `unsigned int`, so
  negative numbers are shown in two's complement (`-15` → `fffffff1`), exactly
  like the real `printf`.
- **`%p`** converts the address to `unsigned long` (64 bits) and prints it in
  base 16 **recursively**: the function first prints `nb / 16`, then the
  digit `nb % 16`. Recursion writes the digits in the right order without
  any allocation, and the depth is at most 16 calls.

### Why this design

- **One file per conversion**: each handler is short, easy to test and easy
  to read, and the code stays within the 42 Norm (25 lines per function).
- **Single pass, direct `write`**: no output buffer is built, which keeps the
  code simple and the return value easy to compute.
- **Reuse of `libft`**: the library is copied into `libftprintf.a`, so
  `ft_strlen`, `ft_itoa`, etc. are available without extra linking.

## Resources

- `man 3 printf` and `man 3 stdarg`
- [cppreference – printf](https://en.cppreference.com/w/c/io/fprintf)
- [cppreference – Variadic functions](https://en.cppreference.com/w/c/variadic)
- [GNU C Library – Variadic Functions](https://www.gnu.org/software/libc/manual/html_node/Variadic-Functions.html)
- [Two's complement (Wikipedia)](https://en.wikipedia.org/wiki/Two%27s_complement)

### Use of AI
