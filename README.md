# CSE4110 Database System Projects

This repository contains two projects for the **CSE4110 Database System** course. The projects provide hands-on experience with database design, normalization, and query processing, focusing on a real-estate office database. The implementation includes E-R modeling, schema design, and query execution using MySQL and C.

## Table of Contents
1. [Project 1: E-R Design and Relational Schema](#project-1-e-r-design-and-relational-schema)
2. [Project 2: Normalization and Query Processing](#project-2-normalization-and-query-processing)

---

## Project 1: E-R Design and Relational Schema

### Overview
The goal of this project is to design a relational database for a real-estate office in Seoul. The office handles agents, buyers, sellers, properties on the market, and recently sold properties. The project includes creating an E-R model, converting it to a relational schema, and writing sample SQL queries for data retrieval.

### Application Description
The real-estate office database must track various entities:
- **Agents** who facilitate property transactions.
- **Buyers** and **Sellers** involved in property sales.
- **Properties** currently on the market or recently sold, focusing on residential properties.

Refer to real-estate listings on websites like [Zigbang](https://www.zigbang.com/home/apt/subways/375) to guide sample data creation, including property details and pricing.

### Requirements

1. **E-R Model**
   - Construct an E-R diagram to capture the database’s conceptual design.
   - Identify primary keys, foreign keys, and relationship cardinalities to avoid redundancy.
   - Include all entities and relationships implied by the project description.

2. **Relational Schema Diagram**
   - Convert the E-R model into a relational schema.
   - Design the schema in **ERwin Data Modeler**, specifying data types, domains, and constraints.
   - Each entity should be named and include primary keys, foreign keys, and relationship details.

3. **SQL Queries**
   - Develop SQL queries to demonstrate the system. Example queries include:
     - List properties for sale in specific districts with price ranges.
     - Show properties in school districts with specific features (e.g., bedrooms, bathrooms).
     - Identify the top-selling agent by value in 2022.
     - Calculate average selling prices and market times by agent.
     - Retrieve photos of the most expensive properties by category (e.g., studio, multi-bedroom).
     - Record a property sale and update its status.
     - Add a new agent to the database.

### Submission Requirements
- **E-R Diagram**: Created using an appropriate tool (e.g., Visual Paradigm, MS PowerPoint).
- **Schema Diagram**: An `.erwin` file for the schema, with display options as used in class practice sessions.
- **Report**: A PDF detailing each entity, relationship, and schema design choices.

---

## Project 2: Normalization and Query Processing

### Overview
This project focuses on decomposing the database schema into **BCNF** and implementing a **C/C++ application** that interacts with MySQL through ODBC. The application allows users to perform CRUD operations and query the database based on specified types.

### System Setup

1. **Software Stack**
   - **C/C++ Application**: Develop a DB application.
   - **MySQL ODBC Driver**: Link the application to the database.
   - **MySQL Server**: Set up and manage the database.

2. **Installation Requirements** (Windows only)
   - Install **MySQL Server** and **MySQL Workbench**.
   - Install the **MySQL ODBC Driver** to enable DB interactions via C/C++.

3. **Database Creation**
   - Use MySQL Workbench or the command line to set up the database.
   - Create and populate the dataset with sample data in a format compatible with the application’s schema.

### Requirements

1. **BCNF Decomposition**
   - Decompose the relational schema into **BCNF** to eliminate redundancy.
   - Ensure that the final design preserves dependencies and meets normalization requirements.

2. **Physical Schema Diagram**
   - After decomposition, create a physical schema diagram in **ERwin Data Modeler**.
   - Define data types, domains, constraints, and nullable fields for each attribute.

3. **SQL Queries**
   - Implement a series of predefined queries with different types (total of 13 query types). Examples include:
     - Finding property listings based on district, price, and other attributes.
     - Listing top-performing agents and calculating average metrics.
     - Recording property sales and adding new agents to the database.

4. **C Application Implementation**
   - Implement a C/C++ program using **ODBC** to interact with the MySQL database.
   - Include a user interface that allows users to select and execute query types.
   - The program should keep running until the user types "quit."

   **Application Details**:
   - The program must use text files with CRUD queries for database initialization and interactions.
   - Menu options for each query type should include submenus for specific query criteria.
   - Users can input query values via standard input, and the program displays results to standard output.

### Submission Requirements
- **Logical Schema Diagram**: `.png` file of the BCNF-decomposed schema.
- **Physical Schema Diagram**: An `.erwin` file representing the final physical schema.
- **C Code**: The main C/C++ source file with comments.
- **Report**: A PDF explaining the physical schema, ODBC connection setup, and BCNF decomposition steps.

### Additional Information
- **Deadline**: Submit all files electronically and in hardcopy as per course guidelines.
- **Academic Integrity**: Ensure original work; plagiarism will result in course failure.

--- 

This README provides an overview of each project, setup instructions, submission details, and key requirements. Follow the structure and requirements closely to ensure successful project completion.
