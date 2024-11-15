# DNA Graph Search Project

This project is a system designed to read and process a list of people from a text file, create a graph based on DNA similarity using the Hamming distance, and implement search functionalities using Breadth-First Search (BFS) and Depth-First Search (DFS) algorithms to locate a person by their DNA sequence.

## Project Summary

- **Data Input**: Loads information about individuals, including their name, surname, address, DNA sequence, city, and phone number, from a text file. The data is organized using a `Persona` structure.
- **Graph Representation**: Constructs an adjacency matrix to define graph connections based on the similarity of DNA sequences, calculated through the Hamming distance.
- **Search Methods**: Implements BFS and DFS for graph traversal and finding a target DNA sequence, while measuring the time taken for the search operations.

## Requirements
- An input file named `people.txt` containing data lines formatted as:


FirstName,LastName,Address,DNA,City,Phone

Example:
Tom,Wilson,56 Main St,RQCOHQWQJK,Chicago,555-1024-1473

## How It Works


## Implementation Details

### Data Organization

- **Persona Structure**: A structure holding details for each individual, including name, surname, address, DNA sequence, city, and phone number.
- **vector<Persona>**: Used to store the loaded data of all individuals.
- **Adjacency Matrix**: A 2D vector that represents the graph, with connections based on DNA similarity computed using the Hamming distance.

### Graph Construction Process

The graph is modeled using an adjacency matrix. Each person is a node in the graph, and edges are formed between nodes when their DNA sequences have a Hamming distance that falls within a defined threshold.

- **Hamming Distance**: The number of differences between two strings of the same length.
- **Creating the Adjacency Matrix**:
  - For every pair of individuals, the Hamming distance between their DNA sequences is computed.
  - An edge is established (marked as 1 in the matrix) if the distance is below or equal to the threshold; otherwise, the value is 0.

### Search Algorithms

#### Breadth-First Search (BFS)
- Explores the graph in layers, visiting all neighbors of a node before moving to the next level.
- Stops when the target DNA sequence is located.
- Utilizes a queue to manage nodes and their neighbors during traversal.

#### Depth-First Search (DFS)
- Searches by following one path as far as it goes, then backtracks to explore other paths.
- Terminates once the target DNA sequence is found.
- Uses a stack to guide the traversal process.

### Code Overview

The project includes detailed explanations of how each part of the system works and a console demonstration video showing the output and performance of the implemented algorithms.


## Operation Video

https://drive.google.com/file/d/1gWik_To1tRqe1dGu6ZC6E5NSACv4Ecq1/view?usp=sharing
