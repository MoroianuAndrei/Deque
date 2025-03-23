# 🔄 Deque Implementation in C++

## 📌 Overview  
This **C++ Deque Implementation** provides a **dynamic double-ended queue** using a memory block model. The structure efficiently supports **push and pop operations at both ends** while maintaining **constant time complexity (O(1))** for these operations. The implementation dynamically expands and contracts based on usage, optimizing memory allocation.  

## 🛠️ Features  
### **🔹 Core Functionalities**  
- **Efficient memory allocation**: Starts with 2 blocks of 8 elements each, expanding dynamically.  
- **Push operations**: `push_front()` and `push_back()` add elements efficiently.  
- **Pop operations**: `pop_front()` and `pop_back()` remove elements efficiently.  
- **Memory deallocation**: When two consecutive blocks become empty, the farthest one is freed.  

### **🔹 Additional Operations**  
- **Element Access**: `front()`, `back()`, and operator `[]` for random access.  
- **Insert/Delete**: Allows insertion (`insert(el, pos)`) and deletion (`del(pos)`) at any position.  
- **Utility Functions**: `empty()`, `clear()`, `size()`.  
- **Interactive Menu**: A `main()` function enables user testing through a command-line interface.  

## 🚀 How It Works  
1. **Deque starts from the middle of the memory block.**  
2. **Elements are added towards both ends** (front and back).  
3. **New memory blocks are allocated** when space runs out.  
4. **Blocks are freed** when two consecutive blocks become empty.  
5. **Users interact through a menu** to test all functionalities.  

## 🔧 Technologies Used  
- **C++** for implementation.
