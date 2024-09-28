# C++ Multithreading Tasks

This document presents five independent tasks focusing on different aspects of multithreading in modern C++. Each task is designed to explore specific concepts and features related to concurrent programming.

## Task 1: Parallel Image Processing

Implement a program that applies a simple image filter (e.g., grayscale conversion or blur) to a large image using parallel processing.

Requirements:
- Use the stb_image library for loading and saving images.
- Implement the filter operation using standard C++ threads.
- Divide the image into chunks and process each chunk in a separate thread.
- Use a thread pool to manage worker threads efficiently.
- Compare the performance with a single-threaded version.

Concepts to explore:
- Basic thread creation and management
- Work distribution among threads
- Thread pooling
- Performance measurement in multithreaded scenarios

## Task 2: Concurrent Data Structure

Implement a thread-safe, lock-free queue data structure.

Requirements:
- The queue should support concurrent enqueue and dequeue operations.
- Use atomic operations to ensure thread safety without locks.
- Implement a simple producer-consumer scenario to test the queue.
- Handle the ABA problem in your implementation.
- Provide a comparison with a mutex-based queue implementation.

Concepts to explore:
- Lock-free programming
- Atomic operations in C++
- The ABA problem and its solutions
- Comparing lock-based and lock-free data structures

## Task 3: Asynchronous Web Scraper

Create a simple web scraper that asynchronously downloads and processes web pages.

Requirements:
- Use libcurl for making HTTP requests.
- Implement asynchronous downloads using std::future and std::async.
- Process multiple web pages concurrently.
- Implement a timeout mechanism for web requests.
- Extract and store specific information from the downloaded pages (e.g., all links or specific text patterns).

Concepts to explore:
- Asynchronous programming with std::future and std::async
- Handling I/O-bound tasks in parallel
- Timeout implementation in asynchronous operations
- Combining asynchronous operations with data processing

## Task 4: Parallel Sorting Algorithm

Implement a parallel version of the Merge Sort algorithm.

Requirements:
- Create a recursive implementation that spawns new threads for sub-arrays.
- Use std::thread for creating threads in the recursive calls.
- Implement a cutoff point where the algorithm switches to sequential sort for small sub-arrays.
- Compare the performance with sequential Merge Sort for various input sizes.
- Experiment with different strategies for thread creation and management.

Concepts to explore:
- Recursive thread creation
- Balancing parallelism and overhead
- Measuring speedup in parallel algorithms
- Strategies for efficient thread utilization in recursive algorithms

## Task 5: Concurrent Logger with Periodic Flush

Implement a thread-safe logging system with asynchronous, periodic flushing to a file.

Requirements:
- Create a Logger class that can be safely used from multiple threads.
- Implement a separate thread for periodically flushing log messages to a file.
- Use condition variables to signal the flush thread when new messages are available or when a flush is requested.
- Implement different log levels (e.g., INFO, WARNING, ERROR) and allow filtering based on log level.
- Provide an option for immediate flush for critical log messages.

Concepts to explore:
- Thread-safe singleton pattern
- Producer-consumer pattern with condition variables
- Periodic tasks in separate threads
- Balancing between responsiveness and efficiency in I/O operations

Each of these tasks focuses on different aspects of multithreading and concurrent programming in C++. They cover a range of concepts from basic thread management to more advanced topics like lock-free programming and asynchronous I/O. You can tackle these tasks in any order, depending on which concepts you want to explore first.