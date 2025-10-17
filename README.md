# ESL-workflow-test

## Project Structure 
```text
.
├── README.md
└── src
    ├── main.c  # Tests for vector3D library
    ├── Makefile # Build targets
    └── vector
        ├── vector3D.c # Implementation of library functions
        └── vector3D.h # API definitions
```
- - -

## Building library

```bash
make libvector3D.a 
```
- - -

## Run tests

```bash
make
```
This will create the executable tests. You can run it.

Or use another target:

```bash
make test
```
- - -

## Requirements:

To run tests, you need to have the check library installed.
On ubuntu:
```bash
sudo apt install check
```