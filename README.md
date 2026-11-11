# C++ Projects — Zulqarnain Khan Jadoon

A collection of console-based C++ exercises demonstrating menu-driven programs, input handling, calculations, and structured output.

## Projects

### 1. Simple ATM System — `atm_system.cpp`
- Verify a PIN before opening the ATM menu, with a limited number of attempts.
- Check the current simulated balance.
- Deposit and withdraw amounts with basic validation.
- Apply a sample daily withdrawal limit.
- Change the session PIN after confirming the current PIN.

**Scope:** The balance and PIN are held in program memory and are not connected to a bank or saved as a real account. The source contains a demonstration PIN; this is not a secure authentication system.

### 2. Student Grade Calculator — `grade_calculator.cpp`
- Enter student details and subject marks.
- Calculate subject percentages and grades.
- Calculate an overall percentage and average GPA.
- Print a formatted student result card.

## Build & Run

A C++ compiler such as `g++` is required. Compile each source file separately:

```bash
g++ -std=c++11 atm_system.cpp -o atm_system
./atm_system
```

```bash
g++ -std=c++11 grade_calculator.cpp -o grade_calculator
./grade_calculator
```

On Windows, run the generated `.exe` file instead of the `./` command.

## Project Scope

These are educational simulations for programming practice. The ATM program is not connected to a real bank, payment network, or financial account.

## Developer

**Zulqarnain Khan Jadoon**

- GitHub: [@zulqarnainjadoon99](https://github.com/zulqarnainjadoon99)
- Portfolio: [zulqarnainjadoon99.github.io](https://zulqarnainjadoon99.github.io)

---

*Review the source code for the exact implementation and limitations of each exercise.*