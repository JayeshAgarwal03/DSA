# Using a local bits/stdc++.h in this repo

Options to make `#include <bits/stdc++.h>` work for files inside this repository:

- Preferred (no system changes): use the build helper which adds the repo root to the include path:

  ```bash
  ./build.sh basics/p4.cpp        # builds basics/p4 (default output)
  ./build.sh basics/p4.cpp bin/p4 # custom output
  ```

- Alternative: set `CPLUS_INCLUDE_PATH` in your shell so angle-bracket includes search the repo root:

  ```bash
  export CPLUS_INCLUDE_PATH="$PWD"
  g++ -std=gnu++17 -O2 -Wall basics/p4.cpp -o basics/p4
  ```

- Quick code change: replace angle brackets with quotes in includes, which searches local directories first:

  ```cpp
  #include "bits/stdc++.h"
  ```

Notes:
- A system-wide installation of `bits/stdc++.h` is possible (e.g. copying into `/usr/local/include/bits/`) but requires root and is not recommended.
- The repo already contains `bits/stdc++.h` at the project root so the above methods work.
