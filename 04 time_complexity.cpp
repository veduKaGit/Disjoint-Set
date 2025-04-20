// Time complexity of both ***FIND*** and ***UNION*** 
// (since union func uses find func in it) operations = O(Log N). 

------------
  
// The two techniques (union by rank + path compression) complement each other. 
// When we use both of them together:

1. The time complexity of both ***FIND*** and ***UNION*** 
  (since union func uses find func in it) operations becomes = O(1) => VVIMP!!!!
// 2. O(1) (amortized) or O(α(n)), where α(n) is the inverse Ackermann function.
// 3. In practical terms, α(n) grows so slowly that it's effectively a constant, 
//    typically less than 5. 
