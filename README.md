# 📜 get_next_line | 42 School Project

### My journey into the wonderful world of static variables and potential memory leaks 😀

![42 School Badge](https://img.shields.io/badge/42-School-blue)
![Memory Leaks](https://img.shields.io/badge/Memory-No%20Leaks-success)
![Score](https://img.shields.io/badge/Score-125%2F100-brightgreen)

> *"A foundational project focused on mastering static variables and buffer management to read from a file descriptor."*

---

## 🎯 Project Overview

Welcome to my implementation of `get_next_line`, a key project in the 42 curriculum. The primary objective is to create a C function that reads content from a file descriptor, one line at a time. This project is a practical exercise in managing memory and handling low-level file input/output.

##  🚀 Getting Started

#### 1. Clone the repository:

```bash
get clone https://github.com/MEHDIJAD/42cursus-get_next_line.git
```

#### 2. Navigate to the project directory:

```bash
cd 42Cursus-get_next_line
```
#### 3. Compile with your project:

```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 your_program.c get_next_line.c get_next_line_utils.c
```

----

## 🪾 Project Structure

```bash
.
├── README.md
├── get_next_line.c
├── get_next_line.h
├── get_next_line_bonus.c
├── get_next_line_bonus.h
├── get_next_line_utils.c
└── get_next_line_utils_bonus.c

1 directory, 7 files
```

## 🤖 Code Flow 

```mermaid
%%{init: {'theme': 'base', 'themeVariables': { 'primaryColor': '#e3f2fd', 'secondaryColor': '#e8f5e9'}}}%%
flowchart TD
    A[Start: get_next_line] --> B{fd & BUFFER_SIZE valid ?};
    B -- No --> C[Return NULL];
    B -- Yes --> D[Call read_and_add];

    subgraph Read[Reading & Buffering]
        D --> E{Buffer already contains new line ?};
        E -- No --> F[Loop: read];
        F -- "bytes_read < 0 (Error)" --> ErrorPath;
        F -- "bytes_read == 0 (EOF)" --> G[Break Loop];
        F -- "bytes_read > 0" --> H[ft_strjoined: Append to static buffer];
        H --> E;
        E -- Yes --> G;
    end
    style Read fill:#e3f2fd,stroke:#1565c0

    G --> I{Is static buffer NULL or empty?};
    I -- Yes --> J[free buffer, Return NULL];
    I -- No --> K[Call ft_get_line];

    subgraph Extract[Line Extraction & State Update]
        K --> L[ft_get_line: Malloc and copy line];
        L -- "malloc fails" --> ErrorPath;
        L -- Success --> M[ft_strdup: Create 'temp' with leftover string];
        M -- "malloc fails" --> ErrorPath;
        M -- Success --> N[free old static_buffer];
        N --> O[Update static_buffer];
    end
    style Extract fill:#e8f5e9,stroke:#2e7d32

    O --> P[Return];

    subgraph Errors[Error Handling]
        ErrorPath --> Z[free all relevant memory & Return NULL];
    end
    style Errors fill:#ffcdd2,stroke:#c62828

    style C fill:#ffebee,stroke:#c62828
    style J fill:#ffebee,stroke:#c62828
    style P fill:#e8f5e9,stroke:#2e7d32
```

## 📋 Usage Examples

### Mandatory Part: Reading a Single File


**`main.c`**
```c
#include "get_next_line.h"

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;

	if (argc != 2)
	{
		printf("Usage: %s <filename>\n", argv[0]);
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}
```

### Bonus Part: Reading Multiple Files Simultaneously

**`main_bonus.c`**
```c
#include "get_next_line_bonus.h"

int	main(int argc, char **argv)
{
	int		fd1;
	int		fd2;
	char	*line1;
	char	*line2;

	if (argc != 3)
	{
		printf("Usage: %s <file1> <file2>\n", argv[0]);
		return (1);
	}
	fd1 = open(argv[1], O_RDONLY);
	fd2 = open(argv[2], O_RDONLY);
	while (1)
	{
		line1 = get_next_line(fd1);
		line2 = get_next_line(fd2);
		if (line1 == NULL && line2 == NULL)
			break ;
		if (line1)
		{
			printf("[File 1]: %s", line1);
			free(line1);
		}
		if (line2)
		{
			printf("[File 2]: %s", line2);
			free(line2);
		}
	}
	close(fd1);
	close(fd2);
	return (0);
}
```


## ⚙️ Under the Hood: How get_next_line Works with the OS

### Who Does What

1. **🐧 The Operating System**

- Tracks the file offset (a cursor) for each file descriptor. It knows 	where the next physical read from the disk should happen. This is updated automatically every time you call read().

2. **🧑‍💻 My get_next_line**

- Tracks the leftover buffer (static char *str_buf). It stores data that has been read from the OS but not yet returned to the user as a complete line.

### Why the Bonus Works

- Mandatory: One static buffer can't track leftovers for multiple files. Reading from fd=4 overwrites the leftovers from fd=3.
- Bonus: An array, static char *str_buf[OPEN_MAX], creates a separate leftover buffer for each file descriptor (str_buf[3], str_buf[4], etc.).

## 👨‍💻 Author

- 42 Intra: [eel-garo](https://profile.intra.42.fr/users/eel-garo)
- GitHub: [MEHDIJAD](https://github.com/MAHDIJAD)

