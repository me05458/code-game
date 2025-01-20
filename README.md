# code-game
Basic terminal card/matching game for linux that gives codes for the user to break using cards.\
So far, it makes color/number cards and wildcards that can be played on anything (no color/number wild cards or action cards).\
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
to run the tutorial: `./tutorial`
to run the game without tutorial: `./game`
# known issues
- tutorial is not elegant at all (should be optimized)
- the `system()` function poses a security vulnerability
