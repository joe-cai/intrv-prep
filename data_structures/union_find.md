#Union-Find
##Basic Interface
API | Union | Find
--- | ----- | ----
Time | log*n (~O(1)) | log*n (~O(1))

##Under the hook
The meat of the union-find data structure is in the implementation of the private method `root`. This is the most basic and critical method that determines the time complexity of the operations that union-find supports.
Two tricks are used to drastically speed up `root`:
- Weighted Union
- Path Compression

##Implementation
```C++

```
