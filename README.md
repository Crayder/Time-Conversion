# Time-Conversion
stamp to date-time and the inverse.

### `stamp2datetime`
This was actually taken directly from pawn's source code. It's one of those functions that aren't included in SA-MP's version of pawn. I converted it's internal function to actual pawn code. It hasn't been cleaned up or anything, just converted to a working state. I also added a `gmh` (Greenwich Mean Hour) and  `gmh` (Greenwich Mean Minute), both being derivatives of `GMT` (Greenwich Mean Time).
### `datetime2stamp`
Converted from a Python script I found and fitted to `stamp2datetime`'s flavor. This function also has not been cleaned up, I have only converted it to a working state.
