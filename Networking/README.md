# C++ Networking Tasks

This document presents five independent tasks focusing on different aspects of network programming in C++. Each task is designed to explore specific concepts and features related to sockets, TCP/IP, UDP, HTTP, and other important networking concepts.

## Task 1: Simple TCP Chat Server and Client

Implement a basic chat server and client using TCP sockets.

Requirements:
- Create a server that can handle multiple client connections simultaneously.
- Implement a client that can connect to the server, send messages, and receive messages from other clients.
- Use select() or poll() for handling multiple connections on the server side.
- Implement a simple protocol for message passing (e.g., message length followed by message content).
- Handle graceful disconnection of clients.

Concepts to explore:
- TCP socket programming
- Client-server architecture
- Multiplexing I/O with select() or poll()
- Basic protocol design
- Handling multiple clients concurrently

## Task 2: UDP-based File Transfer Application

Create a file transfer application using UDP with reliable data transfer mechanisms.

Requirements:
- Implement a sender that breaks files into chunks and sends them over UDP.
- Create a receiver that reassembles the file from received chunks.
- Implement a simple reliability mechanism (e.g., stop-and-wait or selective repeat).
- Handle packet loss, duplication, and reordering.
- Implement a checksum mechanism to ensure data integrity.

Concepts to explore:
- UDP socket programming
- Reliable data transfer over unreliable protocols
- Checksum calculation and verification
- Handling network irregularities (loss, duplication, reordering)
- Designing application-layer protocols

## Task 3: HTTP Server with RESTful API

Implement a basic HTTP server that supports a simple RESTful API.

Requirements:
- Create a server that can handle GET, POST, PUT, and DELETE requests.
- Implement a simple in-memory data store (e.g., a key-value store) that the API interacts with.
- Support basic HTTP features like headers, status codes, and content types.
- Implement simple request routing based on URL paths.
- Handle concurrent requests using threads or an event-driven approach.

Concepts to explore:
- HTTP protocol basics
- RESTful API design
- Parsing and constructing HTTP messages
- Concurrency in network servers
- Basic security considerations in web servers

## Task 4: Network Protocol Analyzer

Create a simple network protocol analyzer that can capture and analyze network traffic.

Requirements:
- Use raw sockets to capture network packets (you may use libpcap for this).
- Implement parsing for common protocols like Ethernet, IP, TCP, UDP, and HTTP.
- Display packet information including source/destination addresses, protocol type, and payload.
- Implement basic filtering capabilities (e.g., by protocol type or IP address).
- Create a simple command-line interface for controlling the analyzer.

Concepts to explore:
- Raw socket programming
- Network protocol structures and headers
- Packet capturing and analysis
- Working with binary data in C++
- Basic network security concepts

## Task 5: Asynchronous DNS Resolver

Implement an asynchronous DNS resolver using modern C++ features.

Requirements:
- Create a function that performs asynchronous DNS lookups using std::future and std::async.
- Implement caching of DNS results to improve performance.
- Handle both forward (hostname to IP) and reverse (IP to hostname) lookups.
- Implement timeout mechanism for DNS queries.
- Create a simple CLI that allows multiple concurrent DNS queries.

Concepts to explore:
- Asynchronous programming in C++
- DNS protocol basics
- Caching strategies
- Handling timeouts in network operations
- Concurrent network requests

Each of these tasks focuses on different aspects of network programming in C++. They cover a range of concepts from basic socket programming to more advanced topics like protocol analysis and asynchronous network operations. You can tackle these tasks in any order, depending on which concepts you want to explore first.