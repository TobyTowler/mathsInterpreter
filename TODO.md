# Maths Interpreter

## Problems
- Brackets
    * new function call
    * return new index or just find )?
    * minor improvement for much harder implementation

### Eval
- brackets need to look behind to see if number of op
    * number = *
    * return new index or just find the )?
        + return
            + more complicated
        - find
            + slightly slower
            this->+ when is this likely to ever be a problem
            + probably a good design choice fuck it we ball
    * new indexes
        + need to find types index of )
        + then find values index of
            + search types and work out how many int/floats are there
- float vs int decisions
    * `*` and /
    * How?
        + Store current type?
            + Another switch statement based on op and other value
                + only 2 options for each since already picking nextVal by type - not that bad
                + can then just cast to the correct type ig
                + could work
                + need to check output to convert back to Int needed if 2 floats


## Road Map
- / + * - 
- brackets
    * x(y) = x * y
- % // etc
- variable stores e.g. x = 4
