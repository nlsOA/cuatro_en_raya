# 🎮 Cuatro en Raya

<p align="center">
  <img src="https://raw.githubusercontent.com/isocpp/logos/master/cpp_logo.png" width="110">
</p>

<p align="center">
  <strong>Classic Four in a Row game developed from scratch in C++</strong>
</p>

<p align="center">
  <img src="https://img.shields.io/badge/C%2B%2B-17-00599C?style=for-the-badge&logo=cplusplus&logoColor=white">
  <img src="https://img.shields.io/badge/Console-Game-222222?style=for-the-badge">
</p>

---

## 🎮 About

**Cuatro en Raya** is a two-player console game developed entirely in
**C++**.

Players take turns selecting a column on a **6 × 7 board**, attempting
to connect four pieces horizontally, vertically or diagonally.

The project was built from scratch without external libraries or game
engines.

---

## ⚙️ How It Works

The game follows a simple loop:

```text
┌───────────────┐
│ Initialize    │
│    Board      │
└───────┬───────┘
        ↓
┌───────────────┐
│ Select Column │
└───────┬───────┘
        ↓
┌───────────────┐
│ Place Piece   │
└───────┬───────┘
        ↓
┌───────────────┐
│ Check Victory │
└───────┬───────┘
        ↓
   ┌────┴────┐
   │         │
  YES        NO
   │         │
   ↓         ↓
  END    Next Turn
