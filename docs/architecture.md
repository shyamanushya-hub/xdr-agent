# Architecture (Draft)

## Pipeline
1. Kernel sensors (Windows minifilter, Linux eBPF)
2. User-mode agent
3. Event bus and buffering
4. Detection engine
5. Transport to backend

## Components
- Sensors: OS-specific collectors
- Normalizer: common event schema
- Rule engine: local detections
- Transport: HTTPS to backend
