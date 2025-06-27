# 📜 get_next_line | 42 School Project

### My journey into the wonderful world of static variables and potential memory leaks. 😀

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

## 💡 Implementation Details


## Code Flow 
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

    style C,J fill:#f8d7da,stroke:#721c24,stroke-width:2px,color:#721c24
    style P fill:#d4edda,stroke:#155724,stroke-width:2px,color:#155724
```


