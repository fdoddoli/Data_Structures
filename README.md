# Introduction

The following are the programs I built while coursing Data Structures in University. 

# Act 1.3

**Introduction**

In this problem situation, we were given a file with different information representing access to computer IP addresses, with the objective of obtaining the corresponding records for a range of dates. The information provided for each access included the month, day, hour, IP address, and reason for failure.

**Description**

The first step to obtain the corresponding records for a range of dates was to sort the information by date for the search operations. To do this, we created a class called "Registro" (Record) and stored the file information in a vector of type "Registro". Additionally, for each "Registro" element, we created its key using the "crearClave" method, which is called within the constructor of the "Registro" class. Finally, to sort the data based on their keys, we used the merge sorting algorithm with a time complexity of O(n*logn). Then, to merge this data, we used a method called "unir" (merge) in our program with a complexity of O(n). To perform comparisons in the merge function, we used operator overloading in our "Registro" class to compare the keys directly. We chose this algorithm because when working with a large amount of data, it is more efficient than the exchange sort and bubble sort algorithms.

Finally, to search for corresponding records within a date range, we asked the user for the initial and final dates and then called the search function. This function retrieves the keys for the initial and final dates by calling the key order method. Then, it calls the binary search method using the initial date as a parameter to obtain the starting position and the final date to obtain the ending position, respectively. Finally, the search method checks if the starting and ending positions exist (they are not -1), and if they do, it iterates through the records from the starting position to the ending position, displaying them. We used these two methods because they are efficient, with a time complexity of O(n) and O(logn) for the search and binary search algorithms, respectively.

**Conclusion**

I really enjoyed being able to apply sorting and searching methods to a real-world problem situation. I believe that mastering these algorithms and understanding how they work is extremely important in order to have the intuition to solve this type of problem in the most efficient way possible.

# Act 2.3

**Introduction**

For this integrative activity, we were asked to read a file and store the data in a doubly linked list with the objective of allowing the user to search for a range of IP addresses and display them in ascending order, as well as store the sorted result in a new document.

**Development**

However, it is important to analyze if using a doubly linked list is the most suitable approach for this problem. There are people who argue that a doubly linked list is better than a singly linked list for the purpose of searching information. They are right because the time complexity for searching is O(n). However, in this problem, having to sort a file with a large amount of data makes the program very inefficient due to the complexity of the sortIP method, which is O(n^3). This is important because it means that a doubly linked list is not the best solution for solving this situation.

**Conclusion**

A crucial factor in determining the effectiveness of using a doubly linked list to solve this problem was the functionality of sorting information in ascending order. Analyzing this method, one can observe its complexity and inefficiency - O(n^3). Thus, after weighing the pros and cons of using a doubly linked list to solve this problem, it can be concluded that it is not a suitable solution.

# Act 3.4

**Introduction**
In this activity, I analyze the importance and efficiency of using a binary search tree (BST), a type of data structure, to solve a problem similar to the one in Activity 2.3.

**Development**

Implementing a BST to solve a problem of this nature is not efficient. This is because the most accessed IPs will have larger key values, which means they will be the last nodes in the binary search tree. This is important because it implies that the time complexity to search for the node with the most accessed IP will be O(n), which is not very efficient. However, this problem can be addressed by using a splay tree instead of a BST to solve a problem of this nature. A splay tree is another type of data structure, but unlike a BST, it is ideal for problems where we need to quickly access the most used or searched data. This is because after searching for a piece of data, the searched data is stored in the root, allowing the program to retrieve that data with a time complexity of O(logn) if it is searched again. This is important because it means that for a problem of this nature, the use of a splay tree is more efficient than a BST, which would allow us to determine if a network is infected or not.

**Conclusion**

One way to detect if a network is infected is by storing important information through a data structure, such as a splay tree, which enables efficient searches to detect malicious accesses. For example, a DDoS cyber-attack, where many bots from various devices connected to the internet overwhelm the servers of a product or service, causing them to malfunction due to an avalanche of accesses, can be easily detected through a splay tree because the devices causing the attack can be quickly identified. This is because if there is a cyber-attack by bots, the malicious accesses will be the ones accessing the network most frequently and will be located at higher levels of the tree. This is important because it means that if we want to detect if a network is infected, we can do it quickly and efficiently.

# Act 4.3 

**Introduction**

In this activity, I analyze the benefits of using a graph to solve a problem similar to the one in activity 4.3.

**Development**

Implementing a directed graph to solve a problem of this nature is efficient because we can store the data in an adjacency list organized by the source IP address using an unordered_map. This way, we can store the source IP as the key value, its corresponding index in the adjacency list, and its outdegree as a pair in the unordered_map's map value. This is important because it makes our program very efficient, as the complexity of storing the data in an adjacency list is O(|V|+|E|), and the use of an unordered_map is O(1). In addition to the fact that using a graph as a data structure is an efficient strategy for solving problems of this nature, utilizing an unordered_map, where a pair is the map value and the second value is the number of outdegrees, allows us to easily determine which IPs are infecting the network.

**Conclusion**

One way to detect which IPs are infecting the network is by analyzing which IPs have the highest number of outdegrees, i.e., which IPs are pointing to the most IPs. For example, a DDoS cyber attack, where many bots from various devices connected to the internet overload servers of a product or service with a flood of requests, can be easily detected through a directed graph stored in an adjacency list because the nodes causing the attack can be quickly identified. This is possible because if there is a cyber attack from bots, the malicious accesses will be the nodes with the highest number of outdegrees, i.e., those pointing to the highest number of nodes. This is important because it means that if we want to detect which IPs are attacking the network, we can do so quickly and efficiently with a complexity of O(n).

# Act 5.2

**Introduction**

In this reflection, I analyze the importance and efficiency of using hash tables, a type of data structure, to solve a problem like the one in activity 5.2.

**Development and Conclusion**

For this activity, we were asked to use a hash table to store data and, given an IP, retrieve the associated value and display the information in a suitable way. We were able to accomplish this by using an unordered_map to represent our hash table, where we used the IP as the key value and the value as a vector of a struct type called "Registro" that stored the summary of the IP. Additionally, we used the C++ function "push_back()" when reading the file to properly insert the data into the unordered_map. This is important because it allowed us to solve the problem very efficiently. For example, our methods for loading the data into the unordered_map, retrieving and displaying the number of accesses for a given IP are all of linear complexity. Furthermore, our method for displaying the summary of the value associated with the IP is constant. All of this is crucial because it demonstrates that using an unordered_map as a hash table is an excellent solution for solving this type of problem where we need to store and search information quickly.
