# code-game
Basic terminal card/matching game for linux that gives codes for the user to break using cards.\
Has only been tested on fedora and debian but there's a good chance it will work on most other kinds of linux.

# requirements
`make, gcc, libsodium`

Fedora:\
`sudo dnf install make gcc libsodium-devel`

Debian: \
`sudo apt install make gcc libsodium-dev`

# installation and running
installation:
```
git clone https://github.com/me05458/code-game&&cd code-game
make
```
to run the tutorial: `./tutorial`\
to run the game without tutorial: `./game`

# Colorless mode
To enter colorless mode:
```
make clean
make colorless
```
To go back to normal mode:
```
make clean
make
```

# known issues
- the `system()` function poses a security vulnerability
- Some redundant/inefficient code and files exist
- tutorial only exists in color
