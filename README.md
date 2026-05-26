# cpp-projects
C++ Projects by  Zulqarnain Khan Jadoon
# Secure Console-Based ATM Banking Application

A high-integrity, interactive Command-Line Interface (CLI) application built using **C++**. This system simulates a real-world Automated Teller Machine (ATM) ecosystem, focusing on runtime state security, precise arithmetic balance execution, and strict conditional multi-user access logic.

Designed to showcase solid Object-Oriented Programming (OOP) syntax handling, input stream validation, and defensive coding techniques in C++.

---

## 🚀 Key Features

*   **Secure Access Layer:** Implements encrypted-style multi-attempt PIN verification logic to prevent unauthorized brute-force balance queries.
*   **Transactional Integrity:** Handles real-time Cash Withdrawal, Fast Cash options, and Fund Deposits with robust boundary checks (e.g., overdraft blocking and negative deposit filtering).
*   **Dynamic Session Management:** Maintains individual account states actively during execution loops, providing clean system clearing and update cycles.
*   **Robust Input Stream Validation:** Built-in safeguards against common terminal crashes (such as `std::cin` type-mismatch vulnerabilities when alphabetical characters are entered instead of digits).

---

## 🛠️ Core Concepts Demonstrated

*   **Language Syntax:** Modern C++ (Standard ISO library constructs)
*   **Control Flow Mastery:** Complex conditional branching, state machines, and switch-case routing structures.
*   **Defensive Programming:** Active parameter boundaries verification to guarantee financial computation accuracy without data leakage.

---

## ⚙️ Compilation & Execution

1. **Clone the repository:**
```bash
   git clone [https://github.com/zulqarnainjadoon99/your-atm-repo-name.git](https://github.com/zulqarnainjadoon99/your-atm-repo-name.git)
   cd your-atm-repo-name
