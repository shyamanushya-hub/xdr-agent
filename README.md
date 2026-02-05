# XDR Agent

Cross-platform XDR agent skeleton with Windows minifilter and Linux eBPF placeholders, a modern C++ user-mode agent, and a FastAPI backend.

## Layout
- agent/ - C++ user-mode agent
- common/ - shared C++ headers and utilities
- drivers/windows/ - minifilter driver (stub)
- ebpf/linux/ - eBPF programs + loader (stub)
- backend/ - FastAPI server
- docs/ - design notes

## Build (Windows)
cmake -S . -B build
cmake --build build --config Release
.\build\Release\xdr_agent.exe

## Backend
python -m venv .venv
.\.venv\Scripts\activate
pip install -r backend\requirements.txt
uvicorn app.main:app --reload --app-dir backend

## Linux
Build Linux targets inside the Linux VM with CMake and clang.
