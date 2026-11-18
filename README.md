# Library Management System (C)

A small console-based C program demonstrating subject-based access to a library catalog.

- Physics students can see Physics books only.
- Chemistry students can see Chemistry books only.
- Maths students can see Maths books only.
- The admin can see books from all subjects.

## Build and run

```sh
gcc -std=c11 -Wall -Wextra -pedantic library.c -o library
./library
```

## Demo credentials

| Role | Username | Password |
| --- | --- | --- |
| Admin | `admin` | `admin123` |
| Physics student | `physics` | `physics123` |
| Chemistry student | `chemistry` | `chemistry123` |
| Maths student | `maths` | `maths123` |

These credentials are hard-coded for demonstration only. Do not use this authentication approach for a real application.
