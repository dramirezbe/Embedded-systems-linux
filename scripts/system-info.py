#!/usr/bin/env python3
import subprocess
import os

base_dir = "/proc"
files = ["cpuinfo", "meminfo", "stat", "uptime"]

def main():
    for file in files:
        path = os.path.join(base_dir, file)

        result = subprocess.run(
            ["cat", path],
            capture_output=True,  # Captura stdout y stderr
            text=True             # Decodifica la salida a str
        )
        print(f"------- File /proc/{file} ----------")

        print(result.stdout)

if __name__ == "__main__":
    main()