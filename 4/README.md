# Notes regarding Ch 4

There is one big change I made, and that was the choice to use `std::map` instead of an array for storing the variable names and their values. The advantage here is the fact that we can easily store strings now, allowing for multi-character variable names. I also chose to keep the white space ignoring function.

There was one small change I also made, which was related to new lines. Unix systems do not place carriage returns before new lines, but other operating systems do. But because of this, we need an additional if statement for checking new lines without the carriage return.

Finally, there's a small change to the Input function. It made more sense to format reading input into the Table like so:
```sh
?<variable_name>(expression)
```
