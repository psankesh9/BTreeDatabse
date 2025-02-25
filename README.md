# B-Tree Persistent Storage & Multithreading Project

## Overview

This project implements a **B-Tree** data structure with **persistent storage** using memory-mapped files (`mmap`) and **multi-threaded queries** for concurrency. The system efficiently organizes, stores, and retrieves data while demonstrating key database principles.

## Features

- **B-Tree Implementation**: Supports efficient insertions, searches, and in-order traversal.
- **Persistent Storage**: Uses memory-mapped files (`mmap`) to store key-value data.
- **Multithreading**: Uses `std::mutex` to safely query the B-Tree concurrently.
- **Efficient Search & Storage**: Designed for database-like performance with O(log n) search complexity.

## Project Structure

```
BTree_Project/
│── BTree.h                 # B-Tree class definition
│── BTree.cpp               # B-Tree implementation
│── BTreeNode.h             # B-Tree Node class definition
│── BTreeNode.cpp           # B-Tree Node implementation
│── main.cpp                # Example usage of B-Tree
│── mmap.cpp                # Simple memory-mapped file example
│── PersistentStorage.cpp   # Persistent storage class implementation
│── MultiThreadedQueries.cpp # Demonstrates multi-threaded queries
```

## File Descriptions

### B-Tree Implementation

#### `BTree.h` & `BTree.cpp`
Defines and implements the **B-Tree**, including methods for insertion, searching, splitting nodes, and traversal.

- `insert(std::string key)`: Inserts a key into the B-Tree.
- `search(std::string key)`: Searches for a key in the tree.
- `traverse()`: Performs an in-order traversal.
- `splitChild()`: Splits full nodes to maintain balance.

#### `BTreeNode.h` & `BTreeNode.cpp`
Defines the **B-Tree Node**, which stores keys and pointers to child nodes.

- Each node can hold multiple keys (defined by `minDegree`).
- Nodes are split when they become full (to maintain balance).

### Example Usage

#### `main.cpp`
Demonstrates how to use the **B-Tree**:

1. Creates a B-Tree.
2. Inserts keys (`transistor M1`, `resistor R1`, etc.).
3. Performs an in-order traversal.
4. Searches for a specific key.

### Persistent Storage

#### `PersistentStorage.cpp`
Implements a persistent storage system using **memory-mapped files** (`mmap`).

- `store(std::string key, std::string value)`: Saves key-value pairs persistently.
- `load()`: Loads and prints stored data from the memory-mapped file.

#### `mmap.cpp`
A simple example demonstrating the basics of **memory-mapped file storage**. It:

1. Opens a file (`ic_data.bin`).
2. Maps it into memory.
3. Stores data (`transistor M1 width=1.2u length=0.18u`).
4. Reads back and prints the data.

### Multithreading & Concurrency

#### `MultiThreadedQueries.cpp`
Demonstrates querying the **B-Tree** in a multi-threaded environment.

- Uses `std::mutex` to prevent race conditions.
- Launches multiple threads that search the tree concurrently.

## Installation & Usage

### Prerequisites

- **C++ Compiler** (`g++` or `clang++`)
- **Linux/macOS** (for `mmap` support)

### Compilation

To compile all files:
```bash
g++ -std=c++11 -o btree_main main.cpp BTree.cpp BTreeNode.cpp
```

To compile the **persistent storage** demo:
```bash
g++ -std=c++11 -o persistent_storage PersistentStorage.cpp
```

To compile the **multi-threaded queries** demo:
```bash
g++ -std=c++11 -pthread -o multithread MultiThreadedQueries.cpp BTree.cpp BTreeNode.cpp
```

### Running the Program

#### Run the **B-Tree Example**:
```bash
./btree_main
```

#### Run the **Persistent Storage Demo**:
```bash
./persistent_storage
```

#### Run the **Multithreaded Queries**:
```bash
./multithread
```

## Future Enhancements

- **Implement deletion**: The header has a `remove()` method, but it's not implemented.
- **Integrate Persistence with B-Tree**: Store B-Tree nodes in memory-mapped storage.
- **More Efficient Concurrency**: Implement finer-grained locking mechanisms.

## Author & Acknowledgments

- **Author**: [Your Name]
- **Inspired by**: Database indexing techniques & system-level storage management.

This project demonstrates fundamental concepts in **data structures, memory management, and concurrency**—key topics in modern database and storage systems.
