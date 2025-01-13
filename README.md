# code-game
Basic terminal card/matching game for linux that gives codes for the user to break using cards.\
So far, it only does color/number cards (no wildcards/actions/etc).\
Has only been tested on fedora and debian but there's a good chance it will work on most other kinds of linux.\

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
./game
```
to run in the future just use `./game`
# known issues
- no thorough explanation of gameplay exists
- the `system()` function poses a security vulnerability
