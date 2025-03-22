# 🧾 Inventory Management System

## 📋 Overview

This is a simple **Inventory Management System** built with C++. It allows users to **add items**, **sell items**, and **list all items** in the inventory. The system also tracks the **total money earned from sales**.

---

## ✨ Key Features

- Object-Oriented Design with two main classes:
  - `Item` – Represents a single inventory item.
  - `Inventory` – Manages a collection of items and handles all item-related operations.
- Operations include:
  - Add new items to the inventory.
  - Sell items and update quantity.
  - Display all inventory items with details.
  - Track total revenue from item sales.

---

## ⚙️ Technical Details

- Uses `std::vector` to store the list of items.
- Employs `std::unique_ptr` for automatic and safe memory management.
- Implements input validation to:
  - Ensure quantities and prices are always positive.
  - Prevent users from selling more items than are available.
- Uses `std::numeric_limits` to manage and clear invalid input from the input buffer.

---

## 🧩 Challenges and Solutions

- **Duplicate Items Handling**:  
  When a user adds an item that already exists in the inventory, the system **updates the quantity** instead of adding a new entry. This prevents duplication and keeps the inventory clean.
  
- **Memory Management**:  
  The use of `std::unique_ptr` ensures **safe and automatic cleanup** of item data when it’s no longer needed, avoiding memory leaks.

---

## 🚀 Future Improvements

- Ability to **save inventory data to a file** and **load it later**.
- Add **item categories** (e.g., Electronics, Groceries).
- Implement **search and filter** functionality.
- Create a **menu-driven UI** or migrate to a GUI using libraries like Qt or SFML.

---

## 🛠️ Getting Started

### 🧾 Prerequisites
- C++17 or later
- A C++ compiler (like `g++` or `clang++`)

