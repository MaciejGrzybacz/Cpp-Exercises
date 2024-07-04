# Multithreaded Traffic Simulation System

Design and implement a traffic simulation system using C++ multithreading concepts.

## Requirements:

1. `Vehicle` class:
  - Represents a vehicle with properties such as speed, position, and type.
  - Implement a `move()` method to update the vehicle's position.

2. `TrafficLight` class:
  - Represents a traffic light with `changeState()` and `getCurrentState()` methods.
  - Use `std::mutex` for synchronizing access.

3. `Road` class:
  - Contains a vector of vehicles and traffic lights.
  - Implement an `updateTraffic()` method to update the road's state.

4. `TrafficSimulation` class:
  - Manages multiple roads.
  - Use `std::thread` to update each road in parallel.
  - Implement `std::condition_variable` to synchronize simulation cycles.

5. Use `std::atomic` to track global statistics, e.g., number of vehicles.

6. Implement a vehicle generator using `std::async`.

7. Use `std::future` and `std::promise` for asynchronous event reporting, e.g., collisions.

8. Apply `std::shared_lock` and `std::unique_lock` to manage access to shared data.

## Additional Challenges:

- Implement an event logging system using a thread-safe queue.
- Add the ability to dynamically add and remove roads during the simulation.
- Implement a simple user interface for controlling the simulation.

## Implementation Guidelines:

- Ensure thread safety for all shared resources.
- Use smart pointers (`std::shared_ptr`, `std::unique_ptr`) for memory management.
- Implement proper exception handling for thread-related operations.
- Use C++17 or C++20 features where appropriate.
