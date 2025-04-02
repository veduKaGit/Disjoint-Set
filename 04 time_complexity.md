The two techniques (union by rank + path compression) complement each other. 

When we use both of them together:
1. The time complexity of both ***FIND*** and ***UNION*** (since union func uses find func in it) operations becomes even SMALLER than O(Log N). 
2. In fact, AMORTIZED time complexity effectively becomes small CONSTANT. 
