# Volleyball Analytics Tracker

## Overview

This project calculates player and team serve and serve-receive statistics through a C++ console application and an HTML/CSS/JavaScript dashboard.

## Metrics

- Serve-in percentage
- Ace totals
- Serve-receive average
- Player-by-player comparison

## Implementation

The C++ application uses a structured player record, reusable calculation functions, zero-attempt handling, and formatted tabular output. The browser dashboard applies the same calculations to a responsive HTML table.

## Run the Console Version

```bash
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o volleyball_tracker
./volleyball_tracker
```

Open `index.html` in a browser to view the dashboard.

## Validation and Sample Output

```bash
bash tests/test_console.sh
```

The test compiles with strict C++17 warnings enabled and verifies player rows, serve percentages, and receive averages. [View the console output](sample-output/console-output.txt).

## Skills Demonstrated

C++, HTML, CSS, JavaScript, data validation, reusable functions, formatted reporting, and sports-performance analysis.

## Author

Daniel McNamara
