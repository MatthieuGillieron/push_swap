# Pushswap – 42 Project  

[![English](https://img.shields.io/badge/English-blue.svg)](./READMEen.md)   [![Français](https://img.shields.io/badge/Français-gray.svg)](./README.md)  

Welcome to **Pushswap**, my project at **École 42**. The goal of this project is to **sort a stack of numbers** using efficient algorithms while minimizing the number of operations. This project helped me improve my **algorithmic skills**, optimize sorting techniques, and work with **simple yet powerful data structures**.  

<br>  

## Project Description  

The **Pushswap** project consists of implementing a sorting algorithm to **sort a stack of numbers**. The objective is to find the most **efficient method** in terms of operations. The program must use only **two stacks** (or more precisely, two arrays), and sorting must be performed using a combination of the following operations:  

- **`sa`** : Swap the first two elements of stack A.  
- **`sb`** : Swap the first two elements of stack B.  
- **`ss`** : Perform `sa` and `sb` simultaneously.  
- **`pa`** : Push the first element of stack B onto stack A.  
- **`pb`** : Push the first element of stack A onto stack B.  
- **`ra`** : Rotate all elements of stack A up by one position.  
- **`rb`** : Rotate all elements of stack B up by one position.  
- **`rr`** : Perform `ra` and `rb` simultaneously.  
- **`rra`** : Rotate all elements of stack A down by one position.  
- **`rrb`** : Rotate all elements of stack B down by one position.  
- **`rrr`** : Perform `rra` and `rrb` simultaneously.  

To complete this project successfully, I used various techniques such as **insertion sort, multi-step sorting algorithms,** and **optimization methods** to minimize the number of required operations.  

## How to Run the Project  

### 1. Clone the repository  

```bash
git clone https://github.com/matthieugillieron/pushswap.git
cd pushswap
```

