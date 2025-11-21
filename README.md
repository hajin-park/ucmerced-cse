# Computer Science and Engineering at University of California, Merced

Open pull requests or issues to add contributions. Follow naming and structure conventions.

## Repository Tree

```bash
./
├── cse100/
│   ├── exams/
│   ├── f23_cse100_syllabus.pdf
│   ├── homeworks/
│   ├── lectures/
│   └── misc/
├── cse106/
│   ├── exams/
│   ├── homeworks/
│   └── lectures/
├── cse107/
│   ├── exams/
│   ├── homeworks/
│   └── lectures/
├── cse108/
│   ├── exams/
│   ├── homeworks/
│   └── lectures/
├── cse111/
│   ├── exams/
│   ├── homeworks/
│   └── lectures/
├── cse120/
│   ├── exams/
│   ├── homeworks/
│   └── lectures/
├── cse126/
│   ├── exams/
│   ├── homeworks/
│   └── lectures/
├── cse135/
│   ├── exams/
│   ├── homeworks/
│   └── lectures/
├── cse140/
│   ├── exams/
│   ├── homeworks/
│   └── lectures/
├── cse141/
│   ├── exams/
│   ├── homeworks/
│   └── lectures/
├── cse150/
│   ├── exams/
│   ├── homeworks/
│   └── lectures/
├── cse151/
│   ├── exams/
│   ├── homeworks/
│   └── lectures/
├── cse155/
│   ├── exams/
│   ├── homeworks/
│   └── lectures/
├── cse157/
│   ├── exams/
│   ├── homeworks/
│   └── lectures/
├── cse160/
│   ├── exams/
│   ├── homeworks/
│   └── lectures/
├── cse162/
│   ├── exams/
│   ├── homeworks/
│   └── lectures/
├── cse165/
│   ├── exams/
│   ├── homeworks/
│   └── lectures/
├── cse168/
│   ├── exams/
│   ├── homeworks/
│   └── lectures/
├── cse170/
│   ├── exams/
│   ├── homeworks/
│   └── lectures/
├── cse171/
│   ├── exams/
│   ├── homeworks/
│   └── lectures/
├── cse173/
│   ├── exams/
│   ├── homeworks/
│   └── lectures/
├── cse175/
│   ├── exams/
│   ├── homeworks/
│   └── lectures/
├── cse176/
│   ├── exams/
│   ├── homeworks/
│   └── lectures/
├── cse177/
│   ├── exams/
│   ├── homeworks/
│   └── lectures/
├── cse177h/
│   ├── exams/
│   ├── homeworks/
│   └── lectures/
├── cse178/
│   ├── exams/
│   ├── homeworks/
│   └── lectures/
├── cse179/
│   ├── exams/
│   ├── homeworks/
│   └── lectures/
├── cse180/
│   ├── exams/
│   ├── homeworks/
│   └── lectures/
├── cse185/
│   ├── exams/
│   ├── homeworks/
│   └── lectures/
├── cse188/
│   ├── exams/
│   ├── homeworks/
│   └── lectures/
├── cse22/
│   ├── exams/
│   ├── homeworks/
│   └── lectures/
├── cse24/
│   ├── exams/
│   ├── homeworks/
│   ├── lectures/
│   └── projects/
├── cse30/
│   ├── exams/
│   ├── homeworks/
│   ├── lectures/
│   └── projects/
├── cse31/
│   ├── exams/
│   ├── f23_cse031_syllabus.pdf
│   ├── homeworks/
│   ├── lectures/
│   ├── misc/
│   └── projects/
├── LICENSE
└── README.md
```

## Naming Conventions

### Directories

Root: `ucmerced-cse/`
- Contains: semester directories

Semesters: `<fa/sp><last two digits of year>`
- Contains class directories

Classes: `<course accronym><course number>` i.e. `cse29`
- Contains: `README.md`, `homeworks/`, `projects/`, `lectures/`
- Optionally contains: `discussions/`, `exams/`, `labs/`, `misc/`, `readings/`

Homework/Assignments/PAs: `homework<number>/` or class-specific name

Projects: `project<number>/` or class-specific name

### Files

- Homework files: `homework<number>.<extension>` or class-specific name
- Project files: `project<number>.<extension>` or class-specific name
- Lecture files: `lecture<number>.<extension>` or class-specific name
- Discussion files: `discussion<number>.<extension>` or class-specific name
- Exam files: `<midterm/final><number>.<extension>` or class-specific name
- Lab files: `lab<number>.<extension>` or class-specific name

## Submodules

Avoid submodules if possible.

Includes submodules of Github Classroom generated repositories.

Includes submodules of group assignment repositories.

Useful commands:
```bash
# Add submodule
git submodule add <url> <path>

# Initialize submodule
git submodule update --init --recursive

# Update submodule
git submodule update --remote --recursive

# Remove submodule
git submodule deinit <path>
git rm <path>
```

## [Course Catalog](https://catalog.ucmerced.edu/content.php?filter%5B27%5D=CSE&filter%5B29%5D=&filter%5Bcourse_type%5D=-1&filter%5Bkeyword%5D=&filter%5B32%5D=1&filter%5Bcpage%5D=1&cur_cat_oid=24&expand=&navoid=2732&search_database=Filter#)

*Last updated: 11/21/2025*

---

### CSE 022: Introduction to Programming

Introduces students to programming, computational thinking, and problem solving concepts, teaching students how to use computers as tools rather than appliances. In addition to programming skills, students also learn industry-standard practices, such as version control, unit testing and debugging. Follows a Project-Based Learning Philosophy, with Python as the main programming language, but students also get exposure to HTML, CSS, JavaScript, and SQL.

---

### CSE 024: Advanced Programming
Intended for students with basic to intermediate programming skills, and introduces them to advanced programming techniques such as pointers and memory management, exception handling, multi-threading, object oriented programming, and generic programming. The C++ language is used throughout the course.

---

### CSE 030: Data Structures

Focuses on the design, analysis, and implementation of fundamental data structures, design patterns, and algorithms used throughout computer science, including linked lists, stacks, queues, trees, hash tables, graphs, recursion, and methods for searching and sorting.

---

### CSE 031: Computer Organization and Assembly Language

Exposes students to the underlying structure of machines. Starting from C programming, pointers, data representation, MIPS instruction-set, Compilation process and down to Hardware implementation.

---

### CSE 100: Algorithm Design and Analysis

Introduction to the design and analysis of computer algorithms. Topics will include concepts of algorithm complexity, and various algorithmic design patterns like divide and conquer, dynamic programming and greedy algorithms. Also covers major algorithms and data structures for searching and sorting, graphs and some optimization techniques.

---

### CSE 106: Exploratory Computing

Our ability to manipulate data depends on and is limited by our familiarity with computing technologies. We study tools for exploratory computing, emphasizing programming and scripting languages over point-and-click interfaces. We cover the Unix basics and common utilities, regular expressions, Perl and R languages. Development of a problem solving ability to learn languages independently and cull online documentation.

---

### CSE 107: Introduction to Digital Image Processing

Overview of digital image processing including visual perception, image formation, spatial transformations, image enhancement, color image representations and processing, edge detection, image segmentation, and morphological image processing.

---

### CSE 108: Full Stack Web Development

Explores topics related to both front end and backend web development including web security, scalable architecture, web frameworks, databases, and object relational mappers.

---

### CSE 111: Database Systems

Principles of database design and operation. Relational data model. High-level data modeling representations. SQL database language. Active databases with constraints and triggers. Query optimization with views and indexes. Exploiting database servers within programming languages for web application development. Other topics include transaction processing and recovery, user-defined functions, and data warehousing. 

---

### CSE 120: Software Engineering

Teams work on approved design projects or on software teams. Through these projects, students will practice design methodology and learn modern software engineering techniques to create reliable, efficient, reusable, and maintainable software systems using various design process models. Good standard project practices topics will be covered.

---

### CSE 126: Information Systems and Service Design

Presents an end-to-end view of the design life cycle for information systems and services. Explains how design problems are conceived, researched, analyzed and resolved in different types of organizations and contexts, including start-ups, enterprises with legacy-systems, non-profit and government entities.

---

### CSE 130: Introduction to Cryptography

Introduces the basic theory and practice of cryptographic techniques used in computer security by exploring the inner workings, mathematical assumptions and foundations of cryptographic primitives and how to use them correctly. Topics include pseudorandom functions, one-way functions, cryptographic hashing, encryption (symmetric and public-key), message integrity, message authentication codes, digital signatures, key management, security protocols and more. Covers the necessary mathematical background, formal definitions of security and proofs of security based on precise definitions and assumptions.

---

### CSE 135: Introduction to Theory of Computation

Understanding the inherent capabilities and limitations of computers is a fundamental question in computer science. To answer this question, we will define formal mathematical models of computation, and study their relationships with formal languages. Topics will consist of three central areas of the theory of computation: automata, computability, and complexity. 

---

### CSE 140: Computer Architecture

Fundamental concepts of digital computer design, including instruction sets, memory systems and registers, logic and mathematics units, modern CPUs and their architectural features are discussed along with the motivation for each design choice.

---

### CSE 141: Introduction to Compiler Construction

Explores basic concepts and techniques in compiler construction. Examines topics such as, lexical analysis, finite automata, parsing, context-sensitive analysis, intermediate representation, code shape analysis, code optimizations, code generation, and register allocation. 

---

### CSE 150: Operating Systems

Concepts of computer operating systems including concurrency, memory management, file systems, multitasking, performance analysis, and security.

---

### CSE 151: Advanced Operating Systems

Introduces the concept of advanced Operating Systems, including distributed operating system, real-time operating systems, advanced computer networks and security. Covers both fundamental knowledge and top-flight research topics in Operating Systems.

---

### CSE 155: Introduction to Human-Computer Interaction

Introduces students to the basic concepts in the theory and practice of Human-Computer Interaction (HCI). Teaches how hardware and software design influence the interaction between human and computers to provide insights into the design and development of safe, effective, and accessible interactive systems.

---

### CSE 157: Signal Processing for Internet of Things

Introduces methods for signal processing between digitization and inference algorithms, where time-series signals are pre-processed. Explores the applications of Internet of Things (IoT) systems, smart connected devices in people’s lives, and examples of converting physical world analog signals to digital ones. Includes topics both theoretical and practical.

---

### CSE 160: Computer Networks

Design concepts and implementation features of computer networks. Concepts of network robustness, scalability, addressing, routing, and security. Several contemporary networking protocols are analyzed.

---

### CSE 162: Mobile Computing

Introduces mobile cloud computing’s basic concepts, including different types of mobile computing devices and applications, the communication technologies used in modern smartphones, the context-aware computing technologies, and programming on mobile devices. 

---

### CSE 165: Introduction to Object Orientated Programming

Topics include object-oriented programming concepts, such as classes, objects, methods, interfaces, packages, inheritance, encapsulation, and polymorphism.

---

### CSE 168: Distributed Software Systems

Covers the foundations of distributed software systems and their practical designs. Includes concepts and principles of distributed systems (e.g., consistency, availability, scalability, etc.); programming models for distributed computing (e.g., batch/streaming processing, RPC, Key-Value, etc.); distributed storage systems (e.g., indexing, replication, partition, and erasure coding, etc.); and convergence of HPC, Big Data, AI, and Cloud Computing with modern distributed systems.

---

### CSE 170: Computer Graphics

Basic algorithms in computer graphics enabling students to understand and experience the process of implementing modern computer graphics applications. Topics covered: programmable shaders, rasterization, hidden surface removal, transformations, rendering pipeline, scene graphs, curves and surfaces, boundary representation, spatial partition methods, keyframe animation, texture mapping, illumination and shading.

---

### CSE 171: Game Programming

Covers the main algorithms and techniques used in the implementation of interactive 3D Graphics, such as in Computer Games, Robotics Simulators and Virtual Reality. Topics covered are: keyframe animation, articulated figures, direct and inverse kinematics, physically-based simulation, path planning, behavior-based animation, scripting behaviors, and other advanced topics.

---

### CSE 173: Computational Cognitive Neuroscience

Design and analysis of computational simulations of human behavior and brain function. Techniques for modeling active membranes, individual neurons, the dynamics produced by recurrent excitation and lateral inhibition, synaptic plasticity, and the computational role of neurotransmitters. Formal models of perception, attention, learning, memory, language, categorization, and cognitive control.

---

### CSE 175: Introduction to Artificial Intelligence

Overview of the main concepts and techniques underlying the design and analysis of intelligent computer systems. Topics include: search and games; knowledge representation, reasoning, and planning; reasoning under uncertainty; machine learning; robotics, perception, and language understanding.

---

### CSE 176: Introduction to Machine Learning

Survey of techniques for development and analysis of software that learns from experience. Specific topics: supervised learning (classification, regression); unsupervised learning (density estimation, clustering, dimensionality reduction); reinforcement learning; and others. Specific techniques: linear classifiers, mixture models, nonparametric methods, decision trees, neural networks, kernel machines, ensembles, graphical models, Bayesian methods, etc.

---

### CSE 177: Database Systems Implementation

Studies the internals of a database management system, with emphasis on query execution. The final goal of the class is to build a fully-functional database execution engine consisting of all the standard components: storage manager, buffer manager, query execution engine, query optimizer, and query compiler.

---

### CSE 177H: Database Systems Implementation

Studies the internals of a database management system, with emphasis on query execution. The final goal of the class is to build a fully-functional database execution engine consisting of all the standard components: storage manager, buffer manager, query execution engine, query optimizer, and query compiler.

---

### CSE 178: Computers and Networks Security

Introduces fundamental concepts in the design and development of secure computer networks. Covers security threats, secret-key and public-key cryptography and algorithms, digital signatures, authentication, Electronic mail, Public-key infrastructure, viruses and worms.

---

### CSE 179: Introduction to Parallel Computing

Parallel computing is pervasive. From embedded devices, laptops, to high-end supercomputer, and large-scale data centers, parallel computing is widely employed to achieve performance and efficiency targets. This course introduces the foundations of parallel computing, including parallel architectures, parallel programming methods and techniques, and parallel algorithm designs.

---

### CSE 180: Introduction to Robotics

Covers the basic of robotics focusing on the algorithmic side, rather than technology. Introduces basic computational techniques concerning spatial modeling, planning, and sensor processing. The course has a strong hands-on component. Implementation of different techniques in simulation will complement the theoretical lectures.

---

### CSE 185: Introduction to Computer Vision

Overview of fundamental image processing and pattern recognition techniques including image formation, edge detection, image segmentation, optical flow, recovery of three-dimensional structure from shading or stereo information, shape representations, and issues in object recognition.

---

### CSE 188: Natural Language Processing

Natural Language Processing explores computational approaches to analyzing and generating human language. Covers machine learning techniques for tasks such as sentiment analysis, named entity recognition, machine translation, and question-answering systems. Students implement NLP algorithms and work with popular frameworks like PyTorch to build practical applications processing real-world text data.