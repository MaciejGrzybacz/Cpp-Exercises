# Library Management System Class Hierarchy

## MediaItem (Base Class)
- Properties:
  - Title (string)
  - Author/Creator (string)
  - Unique ID (integer)
  - Borrowing status (boolean)
- Methods:
  - A virtual display function to show item details
  - A virtual function to return the item type as a string
  - Getters and setters for all properties

## Book (Derived from MediaItem)
- Additional Properties:
  - Number of pages (integer)
  - ISBN (string)
- Methods:
  - Override display function to include book-specific details
  - Override get-type function to return "Book"

## Magazine (Derived from MediaItem)
- Additional Properties:
  - Issue number (integer)
  - Publication date (date)
- Methods:
  - Override display function for magazine-specific information
  - Override get-type function to return "Magazine"

## DVD (Derived from MediaItem)
- Additional Properties:
  - Duration in minutes (float)
  - Genre (string)
- Methods:
  - Override display function for DVD-specific details
  - Override get-type function to return "DVD"

## User (Base Class)
- Properties:
  - Name (string)
  - Unique ID (integer)
  - List of borrowed items (vector of MediaItem pointers)
- Methods:
  - A virtual display function to show user information
  - A virtual function to return the user type as a string
  - Functions to add and remove items from the borrowed list
  - Getters and setters for all properties

## Student (Derived from User)
- Additional Properties:
  - Major (string)
  - Year of study (integer)
- Methods:
  - Override display function to include student-specific information
  - Override get-user-type function to return "Student"

## Faculty (Derived from User)
- Additional Properties:
  - Department (string)
  - Position (string)
- Methods:
  - Override display function for faculty-specific details
  - Override get-user-type function to return "Faculty"

## Staff (Derived from User)
- Additional Properties:
  - Department (string)
  - Job title (string)
- Methods:
  - Override display function for staff-specific information
  - Override get-user-type function to return "Staff"

## Library Class
- Properties:
  - Collection of media items (vector of MediaItem pointers)
  - Collection of users (vector of User pointers)
- Methods:
  - Add new media item to the collection
  - Add new user to the system
  - Find media item by ID
  - Find user by ID
  - Display all media items
  - Display all users
  - Handle item borrowing (moving item to user's borrowed list)
  - Handle item return (removing item from user's borrowed list)

## Friend Functions
- Borrow Item Function:
  - Parameters: user ID, item ID, reference to Library
  - Functionality: Locate user and item, check availability, update borrowing status
- Return Item Function:
  - Parameters: user ID, item ID, reference to Library
  - Functionality: Locate user and item, verify borrowing, update return status
