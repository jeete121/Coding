# STRING Interview Questions

**1. Why are strings immutable in java?**

https://www.scaler.com/topics/why-string-is-immutable-in-java/

**2. How intern() works?**

https://www.scaler.com/topics/intern-in-java/

**3. How many objects are created in Strings using string literals and new operator?**

Two objects are created.

When a string literal is encountered in Java, the Java Virtual Machine (JVM) checks the string constant pool to see if the string already exists. If it does, the JVM reuses the existing string object. If the string does not exist in the pool, the JVM creates a new string object and adds it to the pool.
When the new keyword is used to create a string object, the JVM always creates a new string object, even if the string already exists in the string constant pool.


**4. How string constant pool works?**

https://www.geeksforgeeks.org/string-constant-pool-in-java/

https://www.scaler.com/topics/java/string-pool-in-java/


**5. Difference between equals and == operator?**

The equals() method and the == operator are used to compare two objects in Java. However, there is a subtle difference between the two.
The equals() method compares the content of two objects, while the == operator compares their memory addresses. This means that if two objects have the same content but are stored in different memory locations, the equals() method will return true, while the == operator will return false.

https://unacademy.com/content/gate-cse-it/difference-between-operator-and-equals-method-in-java


**6. Difference between string , string buffer and string builder.**

In Java, String, StringBuffer, and StringBuilder are all classes used to handle strings, but they differ in mutability and thread safety:

String: Immutable, meaning the object can't be changed after creation.

StringBuffer: Mutable, meaning the object can be modified without creating a new object. It's thread-safe, so multiple threads can use it simultaneously.

StringBuilder: Mutable, meaning the object can be modified without creating a new object. It's not thread-safe, so it shouldn't be used in multi-threaded environments

https://www.digitalocean.com/community/tutorials/string-vs-stringbuffer-vs-stringbuilder



# OBJECT Interview Questions

**1. Why is wrapper class required?**

Wrapper classes are objects that wrap around primitive data types in programming languages. They can be useful in a variety of situations, including:

a. Converting between primitives and objects: Wrapper classes make it easier for developers to use objects instead of primitives when coding.

b. Displaying related data: In Salesforce, wrapper classes can be used to encapsulate related records, such as parent and child records, in a single Visualforce page. This allows developers to easily manage and display the data in a structured format.

c. Working with collections: Wrapper classes are essential for working with collections, which are collections of objects that are dealt with using pre-defined methods.

d. Calling methods on primitive data types: Wrapper classes can be used to call methods on primitive data types.

e. Representing the absence of a value: Wrapper classes can be used to represent the absence of a value.

f. Synchronization in multithreading: Objects are needed to support synchronization in multithreading, and wrapper classes can help in this case

**2. Methods of Object class?**

The Object class is the root of all classes in Java. It provides several methods that are common to all objects.

These methods are:

equals(): - Compares two objects for equality.

toString(): - Returns a string representation of the object.

hashCode(): - Returns a hash code for the object.

getClass(): - Returns the class of the object.

clone(): - Creates a copy of the object.

finalize(): - Called by the garbage collector before destroying the object.

wait(): - Causes the current thread to wait until another thread notifies it.

notify(): - Notifies a waiting thread.

notifyAll(): - Notifies all waiting threads.

https://www.slainstitute.com/object-methods-in-java

**3. Does java gives importance to primitive data types?**

Yes, Java gives importance to primitive data types. Java is a statically typed language, which means that the data type of a variable must be known at compile time. This ensures that the code is more reliable and less prone to errors.

Primitive data types are the basic data types that are built into the Java language. They are:
byte, short, int, long, float, double, char, and boolean.

Primitive data types are important because they are the most efficient way to store data in Java. They are also the most widely used data types in Java programs.

In addition to primitive data types, Java also has reference data types. Reference data types are objects that are created by the programmer. They are not as efficient as primitive data types, but they are more flexible.
Here are some of the reasons why Java gives importance to primitive data types:

Efficiency: Primitive data types are the most efficient way to store data in Java. They are stored directly in memory, which makes them very fast to access.

Simplicity: Primitive data types are very simple to use. They do not have any methods or properties, which makes them easy to understand and use.

Portability: Primitive data types are the same on all Java platforms. This makes it easy to write portable Java code that can run on any platform.

Overall, primitive data types are very important in Java. They are the most efficient and simple way to store data in Java. They are also the most widely used data types in Java programs.


**4. Is Java pass by value or pass by reference?**

Java is always pass by value. This means that when you pass an argument to a method, a copy of that argument is made and passed to the method. The original argument is not changed.

This is true for both primitive types (such as int and boolean) and object types. When you pass an object to a method, a copy of the object reference is passed to the method. The original object reference is not changed.

However, it is important to note that the object itself can be changed. This is because the object reference that is passed to the method points to the original object. If the method changes the state of the object, the original object will also be changed.



# OOPS Interview Questions

**1. Composition vs Aggregation vs Association?**

https://medium.com/@bindubc/association-aggregation-and-composition-in-oops-8d260854a446


**2. Function overloading vs overriding**

https://www.shiksha.com/online-courses/articles/difference-between-overloading-and-overriding/


**3. Difference between Abstract class and Interface?**

https://www.geeksforgeeks.org/difference-between-abstract-class-and-interface-in-java/


**4. Can private method or static methods be overridden in Java?**

No, private methods and static methods cannot be overridden in Java. Here's why:

Private methods: Private methods are accessible only within the class in which they are declared.

Subclasses cannot access private methods of their superclasses.
Therefore, subclasses cannot override private methods.

Static methods: Static methods are associated with the class itself, rather than with an instance of the class.
When a subclass inherits a static method from its superclass, it is not possible to override the behavior of that static method. 


Instead, the static method of the superclass will be called.

Final methods: Final methods cannot be overridden in Java.

If a method is declared as final in a superclass, then it cannot be overridden in any of its subclasses.
This is because final methods are intended to be the final implementation of a method.

https://www.prepbytes.com/blog/java/can-we-override-static-method-in-java/


**5. Can main() method be overloaded?**

Yes, the main() method can be overloaded in Java, but the JVM (Java Virtual Machine) only calls the original main method with the signature public static void main(String[] args).

https://www.scaler.com/topics/can-we-overload-main-method-in-java/


**6. Can Abstract class have main method?**

Yes, an abstract class in Java can have a main method and can be run like any other class. Abstract classes can also have other types of methods, including:

Abstract methods: Can't have bodies, but can be declared with the abstract keyword

Non-abstract methods: Can be included in an abstract class

Final methods: Can prevent child classes from changing the method's body

Static methods: Can be defined in an abstract class

https://cs-fundamentals.com/tech-interview/java/can-we-run-abstract-class-in-java-that-has-main-method



# Serialization Interview Questions

**1. What is Serialisation and Deserialisation?**

https://www.geeksforgeeks.org/serialization-in-java/


**2. Use of transient keyword?**

The transient keyword in Java is used to tell Java to ignore an attribute when serializing an object. Serialization is the process of converting an object's state into a byte stream that can be saved to a file, database, or transmitted over a network. The transient keyword can be useful in situations where you have sensitive or temporary data that you don't want to serialize.

https://www.upgrad.com/blog/transient-keyword-java/


**3. Is it possible to serialise a class if its super class is not serialisable ?Can the class be still serialised and deserialised?**

Yes provided that non-serialisable super class has no args constructor which is involved at deserialisation to initialise the super class.

**4. Can Uninitialised non serialised , non transient fields still be tolerated?**

Yes

During serialization, we need to handle IOException ; during deserialization, we need to handle IOException and ClassNotFoundException . So the deserialized class type must be in the classpath. Uninitialized non-serializable, non-transient instance fields are tolerated


# Cloning Interview Questions

**1. What is marker interface?**

https://www.geeksforgeeks.org/marker-interface-java/


**2. What is shallow copy and Deep copy?**

A shallow copy and a deep copy are both ways to copy an object, but they differ in how they handle references to other objects:

Shallow copy: Creates a new object that shares the same references as the original object. This means that if you change either the original or the copy, the other object may also change. For example, if a shallow copy creates a new array, it points to the same elements as the original array instead of creating new copies.

Deep copy: Creates a new object that is completely independent of the original object. This means that changes to the deep copy do not affect the original object. For example, a deep copy creates a completely independent copy of an array and its data, so it doesn't share any data with the original array

https://www.geeksforgeeks.org/difference-between-shallow-and-deep-copy-of-a-class/


# Exception Interview Questions

**1. Difference between Error and Exception?**

https://www.shiksha.com/online-courses/articles/difference-between-errors-and-exceptions-in-java-blogId-155937

**2. Checked vs Unchecked Exception?**

https://www.geeksforgeeks.org/checked-vs-unchecked-exceptions-in-java/

**3. Create custom Exception?**

https://www.geeksforgeeks.org/user-defined-custom-exception-in-java/


**4. What is Runtime exception ?**

A runtime exception is an exception that can occur during the normal operation of a virtual machine (VM). In Java, RuntimeException is the superclass of all classes that throw exceptions during normal VM operation. Runtime exceptions, also known as unchecked exceptions, can occur anywhere in a program and can be very numerous. The compiler doesn't require that runtime exceptions be caught or specified, but they can be.

https://www.geeksforgeeks.org/java-program-to-handle-runtime-exceptions/

**5. How does JVM handle Exception?**

https://medium.com/geekculture/how-does-exception-handling-work-in-java-c71c45103e7d

**6. Difference between Final, Finalise and Finally?**

https://www.geeksforgeeks.org/g-fact-24-finalfinally-and-finalize-in-java/


**7. Super class of all exceptions?**

In Java, the Throwable class is the superclass of all exceptions and errors. It is a direct subclass of the Object class and has two direct subclasses, Exception and Error.


**8. Is throwable an interface?**

Yes, Throwable is an interface in Java. It is the root of the Java class hierarchy and is the superclass of all errors and exceptions. 

Throwable has two direct subclasses: Error and Exception.

Throwable is the base interface for any object that can be thrown via a throw statement, including Error and Exception. 

https://www.geeksforgeeks.org/throwable-class-in-java-with-examples/


**9. When Finally block doesn't get executed?**

https://www.scientecheasy.com/2020/05/java-finally-block-not-executed.html/

**10. Can subclass throw higher checked exception than base class?**

No, a subclass cannot throw a higher checked exception than its base class. This is because the subclass is inheriting the contract of the base class, and part of that contract is the set of exceptions that the class can throw. If the subclass were to throw a higher checked exception, then it would be breaking that contract.

https://medium.com/@salvipriya97/java-rules-to-follow-when-using-checked-exceptions-with-inheritance-62cd3a6dfc6c

**11. Can we throw an unchecked exception in child class if parent class doesn't throw any exception?**


Yes, in Java, you can throw an unchecked exception in a child class even if the parent class does not declare any exceptions. Here's why:

Unchecked Exceptions: Unchecked exceptions in Java are subclasses of RuntimeException or Error. These exceptions do not need to be declared in a method's throws clause.

Inheritance of Exceptions: When you override a method from a parent class in a child class, you can throw any unchecked exception or subclass thereof, regardless of whether the parent method declares any exceptions.

Exception Compatibility: Java allows subclasses to throw a narrower range of exceptions than the superclass. This means you can throw fewer exceptions, more specific exceptions, or unchecked exceptions in the child class method that overrides a parent class method.

There are two important points to remember while handling exceptions using method overriding. If the superclass method does not declare an exception, then the overriding subclass method cannot declare a checked exception, but it can declare an unchecked exception.

**12. Difference between throw and throws()**

https://www.geeksforgeeks.org/difference-between-throw-and-throws-in-java/



# Usage of Enum

**1. Why to use Enum?**

Enums are used to give names to constants, which makes the code easier to read and maintain.


# Garbage collection Interview Questions

**1. How does Garbage collection in Java works?**

Garbage collection in Java is a process of automatic memory management. It automatically reclaims memory that is no longer in use by the program.

The garbage collector works by using a mark-and-sweep algorithm. The mark phase traverses the object graph starting from the roots. The roots are objects that are known to be in use, such as global variables and objects referenced by local variables. The mark phase marks all objects that are reachable from the roots. The sweep phase then reclaims all objects that are not marked.

https://newrelic.com/blog/best-practices/java-garbage-collection


# Collection Interview Questions

**1. Array vs ArrayList?**

https://www.simplilearn.com/difference-between-array-and-arraylist-article

**2. ArrayList vs LinkedList? When to use which collection?**

https://www.naukri.com/code360/library/difference-between-arraylist--linkedlist-that-everyone-should-know

**3. Fail Safe vs Fail Fast Iterators?**

https://www.geeksforgeeks.org/fail-fast-fail-safe-iterators-java/


**4. What is concurrent modification exception?**

In Java, a ConcurrentModificationException is a runtime exception that occurs when an object is modified without permission while another operation is being performed on the same collection. This can happen when a thread is iterating over a collection using an Iterator while another operation is performed on the collection. For example, modifying a list's structure with subList while a thread is traversing it can also cause this exception

https://www.fusion-reactor.com/blog/resolving-concurrentmodificationexception-in-java-a-guide-to-understanding-avoiding-and-fixing/


**5. Internal working of HashMap**

https://www.geeksforgeeks.org/internal-working-of-hashmap-java/


**6. Java8 changes to HashMap**

Java 8 made significant changes to the HashMap class, primarily focused on improving performance in the presence of hash collisions. These changes include:

Removal of the alternative String hash function:

Java 7 introduced an alternative hash function for Strings, but it was found to be less effective than the original function in many cases.

Java 8 removed this alternative function, restoring the original behavior.

Storing entries in a balanced tree instead of a linked list:

When a bucket in a HashMap contains a large number of colliding entries, Java 8 will automatically store those entries in a balanced tree instead of a linked list. This change improves the performance of get() and put() operations in these cases, from O(n) to O(log n).
Improved performance for key collisions:

Java 8 also made a number of other changes to the internal implementation of HashMap to improve its performance in the presence of hash collisions. These changes include using a more efficient algorithm for finding empty buckets, and using a more compact data structure for storing entries in linked lists.

Overall, the changes to HashMap in Java 8 result in a significant performance improvement for applications that use HashMaps heavily, especially in cases where there are a large number of hash collisions.


**7. Why HashMap contains null key?**

HashMap allows one null key and multiple null values. This is because HashMap is implemented using a hash table, which is a data structure that maps keys to values. The hash table is designed to be very efficient for storing and retrieving data, but it does not allow for null keys. To allow for null keys, HashMap uses a special value called NULL_KEY to represent the null key.
There are a few reasons why HashMap allows null keys. First, it allows for more flexibility in how HashMaps are used. For example, a 

HashMap could be used to store a list of objects, where the key is the object's ID and the value is the object itself. If an object is deleted, its ID can be set to null to indicate that it is no longer in the list.

Second, allowing null keys can improve the performance of HashMaps in some cases. For example, if a HashMap is used to store a cache of data, and the data is frequently updated, it can be more efficient to simply set the key to null when the data is updated, rather than removing the key from the HashMap.

Finally, allowing null keys makes HashMaps more consistent with other Java collections, such as HashSet and ArrayList. These collections all allow null values, so it makes sense for HashMap to allow null keys as well.

However, there are also some potential drawbacks to using null keys in HashMaps. First, it can be easy to accidentally introduce null keys into a HashMap, which can lead to unexpected behavior. For example, if a HashMap is used to store a list of objects, and a null key is inserted into the HashMap, the list will no longer be ordered correctly.

Second, using null keys can make it more difficult to debug problems with HashMaps. For example, if a HashMap is used to store a cache of data, and the data is not being updated correctly, it can be difficult to track down the problem if the key is null.


**8. Is it Mandatory to have key immutable in HashMap?**

While it's not mandatory for a HashMap key to be immutable, it's recommended. Immutable keys help ensure that the hash code and equality remain constant, even if the key is changed after it's been used in the HashMap. If a mutable key is changed, the hash code can change, which can lead to incorrect value retrieval. Immutable keys can also improve performance and provide better code control

https://www.thetechnojournals.com/2019/10/why-hashmap-key-should-be-immutable-in.html


**9. Why to override equals() and hashcode() method?**

https://lazy-programmer.medium.com/why-it-is-important-to-override-equals-and-hashcode-method-for-custom-objects-1d2bc629b5c4


**10. HashSet vs LinkedHashSet vs TreeSet**

https://www.geeksforgeeks.org/difference-and-similarities-between-hashset-linkedhashset-and-treeset-in-java/


**11. What is the Internal Datastructure in TreeMap? How the elements are sorted?**

https://medium.com/@basecs101/treemap-in-java-collection-framework-interview-question-a3f81c7aaa84


**12. HashMap vs ConcurrentHashMap**

https://www.geeksforgeeks.org/difference-hashmap-concurrenthashmap/


**13. Comparable vs Comparator**

https://www.geeksforgeeks.org/comparable-vs-comparator-in-java/


**14. What is blocking Queue?**

https://www.digitalocean.com/community/tutorials/java-blockingqueue-example


**15. What is Vector? When to use it?**

Vectors are utilized in the storage of locations, directions, and velocities in video games. The position vector tells us how far away the object is, the velocity vector tells us how long time it will take or how much force we need to apply, and the direction vector tells us how we should apply that force.

https://www.javatpoint.com/when-to-use-vector-in-java



# MultiThreading Interview Questions

**1. MultiThreading vs MultiProcessing vs MultiProgramming vs MultiTasking?**

https://www.geeksforgeeks.org/difference-between-multitasking-multithreading-and-multiprocessing/


**2. Life cycle of a Thread**

https://www.geeksforgeeks.org/lifecycle-and-states-of-a-thread-in-java/


**3. Extends vs Runnable**

https://www.geeksforgeeks.org/implement-runnable-vs-extend-thread-in-java/


**4. yield() vs sleep() vs join() ?**

https://www.geeksforgeeks.org/java-concurrency-yield-sleep-and-join-methods/


**5. wait() vs sleep() ?**

https://medium.com/@reetesh043/understanding-the-difference-between-wait-and-sleep-methods-64958feffbb8


**6. why is join() method used?**

The join() method is used to wait for a thread to finish its execution. When a thread calls join() on another thread, it will block until the other thread finishes executing. This can be useful for ensuring that a thread has completed a task before another thread starts.
For example, you might have a thread that is responsible for reading data from a file. You could use the join() method to wait for the thread to finish reading the file before starting another thread that processes the data. This would ensure that the second thread does not start processing the data before it has all been read.

The join() method can also be used to synchronize threads. For example, you might have two threads that are both writing to the same file. You could use the join() method to ensure that one thread finishes writing to the file before the other thread starts. This would prevent the two threads from overwriting each other's data.

https://www.geeksforgeeks.org/joining-threads-in-java/


**7. Can we Override start() method in Thread?**

Yes, we can override the start() method in the Thread class. However, it is not recommended to do so. The start() method is responsible for creating a new thread and starting its execution. If we override the start() method, we can change its behavior and prevent it from creating a new thread. This can lead to unexpected results and can make it difficult to debug our code.

https://www.geeksforgeeks.org/overriding-thread-class-start-method/


**8. Can we Override run() method?**

Yes, we can override the run() method in Java. The run() method is declared in the Thread class and is responsible for executing the code of the thread. When a thread is started, the run() method is called.

To override the run() method, we need to create a subclass of the Thread class and implement the run() method in the subclass. The run() method in the subclass will replace the run() method in the Thread class.

https://www.geeksforgeeks.org/overriding-thread-class-start-method/


**9. Can we start the thread twice?**

No, a thread cannot be restarted after it has been begun. An IllegalThreadStateException is raised if you do so. In this situation, the thread will execute once, but will throw an exception the second time.

https://www.javatpoint.com/can-we-start-a-thread-twice


**10. What is IllegalThreadStateException?**

In Java, an IllegalThreadStateException is thrown when an operation is attempted on a thread that is not in the right state for that operation. For example, this can happen when dealing with threads or the Collections framework of the java.util package under certain conditions

**11. What happens if run() method is called without start()?**

If you call the run() method directly instead of using start() , the code in the run() method will be executed in the current thread of execution rather than in a new thread. This means that the code will be executed sequentially in the current thread, without creating a new thread of execution

https://medium.com/javarevisited/dont-get-stuck-in-neutral-knowing-when-to-use-run-or-start-in-multithreading-dbd85a59e75d


**12. Why do we use ThreadPool?**

Thread pools are used to improve the performance of an application by separating the creation and management of threads from the execution of tasks. They can also help reduce resource consumption and improve response speed:

Reduce resource consumption: Thread pools reuse created threads, which reduces the overhead of creating and destroying threads for each task.

Improve response speed: Tasks can be executed immediately when they arrive, without waiting for a thread to be created.

Improve manageability of threads: Thread pools can be used to allocate, tune, and monitor threads, which are scarce resources

https://stackify.com/java-thread-pools/

**13. What is Race Condition?**

https://www.techtarget.com/searchstorage/definition/race-condition


**14. What is Synchronisation? Types of Synchronisation**

https://www.geeksforgeeks.org/synchronization-in-java/


**15. Object Level Locking vs Class Level Locking?**

https://www.geeksforgeeks.org/object-level-class-level-lock-java/


**16. If there is 2 synchronised methods m1 and m2 in a class, can 2 different threads t1 and t2 call different methods(m1,m2) respectively on same object of class c at same time ?**

No. Only 1 Thread can hold the lock on a object of a class.However the other non synchronised methods can be called on same object.

**17. If a class has a synchronised method and non synchronised method, can multiple threads execute non synchronised methods?**

Yes. If a class has a synchronised method and non synchronised method , multiple threads can access non synchronised methods.

Yes, a Non synchronized method can always be called without any problem. In fact Java does not do any check for a non-synchronized method. The Lock object check is performed only for synchronized methods/block

**18. Can 2 threads call 2 different static synchronised methods of same class?**

The static synchronised methods of same class always block each other as 1 lock per class exists. So no 2 static synchronised methods can execute at the same time.

**19. Does static synchronised methods block a non synchronised methods?**

No. The thread executing static synchronised method holds a lock on the class and the executing the non static synchronised method holds lock on the object on which the method has been called, these 2 locks are different and these threads dont block eachother.

**20. Can Constructors be synchronised?**

No, constructors in Java cannot be synchronized. Using the synchronized keyword with a constructor is a syntax error. Constructors also cannot be abstract, final, or static

https://docs.oracle.com/javase/tutorial/essential/concurrency/syncmeth.html

**21. What is DeadLock?**

https://www.geeksforgeeks.org/introduction-of-deadlock-in-operating-system/


**22. What is Inter thread communication?Explain wait(),notify() and notifyall()?**

Inter-thread communication in Java is a fundamental part of building multithreaded applications. The Object class methods wait(), notify(), and notifyAll() provide a way for threads to communicate and coordinate their activities. These methods are used for signaling and communication between threads.

https://www.javatpoint.com/inter-thread-communication-example


**23. What is IllegalMonitorStateException?**

In Java, an IllegalMonitorStateException is a runtime exception that occurs in multithreaded applications when a thread tries to wait on or notify other threads waiting on an object's monitor without owning the monitor. This can happen if a thread calls the wait(), notify(), or notifyAll() methods of the Object class outside of a synchronized block

https://www.baeldung.com/java-illegalmonitorstateexception


**24. Which class does wait(),notify() and notifyall() method belong?**

The wait(), notify(), and notifyAll() methods belong to the Object class in Java. These methods are used for thread synchronization. The wait() method causes the current thread to wait until another thread invokes the notify() method or the notifyAll() method on the same object. The notify() method wakes up a single thread that is waiting on the object. The notifyAll() method wakes up all threads that are waiting on the object.

https://www.digitalocean.com/community/tutorials/java-thread-wait-notify-and-notifyall-example


**25. Explain few Thread class methods?is Sleep() a method in Thread class or Object class?**

The Sleep() method is a method in the Thread class. It is used to pause the execution of the current thread for a specified period of time. The sleep() method takes a single argument, which is the length of time to sleep in milliseconds.

https://www.geeksforgeeks.org/thread-sleep-method-in-java-with-examples/


**26. Producer Consumer Problem in Java?**

https://www.geeksforgeeks.org/producer-consumer-solution-using-threads-java/


**27. Volatile vs Synchronised?**

Volatile and synchronized are two keywords in Java that are used to ensure the visibility and atomicity of shared variables in multithreaded applications. However, there are some key differences between the two keywords.

Volatile

Guarantees visibility: The volatile keyword ensures that the value of a shared variable is always visible to all threads. This means that if one thread changes the value of a volatile variable, other threads will immediately see the updated value.
Does not guarantee atomicity: The volatile keyword does not guarantee the atomicity of shared variables. This means that it is possible for two threads to read or write to a volatile variable at the same time, which can lead to race conditions.

Synchronized

Guarantees visibility: The synchronized keyword ensures that the value of a shared variable is always visible to all threads. This means that if one thread changes the value of a synchronized variable, other threads will immediately see the updated value.
Guarantees atomicity: The synchronized keyword also guarantees the atomicity of shared variables. This means that it is impossible for two threads to read or write to a synchronized variable at the same time, which prevents race conditions.

When to use volatile: The volatile keyword should be used when you need to ensure that the value of a shared variable is always visible to all threads, but you do not need to guarantee atomicity. For example, you might use the volatile keyword to implement a flag that indicates whether a thread is still running.

When to use synchronized: The synchronized keyword should be used when you need to ensure that the value of a shared variable is always visible to all threads and you also need to guarantee atomicity. For example, you might use the synchronized keyword to implement a counter that is shared by multiple threads.

Performance: The synchronized keyword has a higher performance cost than the volatile keyword. This is because the synchronized keyword requires the JVM to acquire a lock on the shared variable before it can be accessed. The volatile keyword, on the other hand, does not require the JVM to acquire a lock.

Conclusion: The volatile and synchronized keywords are two important tools for ensuring the visibility and atomicity of shared variables in multithreaded applications. The volatile keyword should be used when you need to ensure that the value of a shared variable is always visible to all threads, but you do not need to guarantee atomicity. The synchronized keyword should be used when you need to ensure that the value of a shared variable is always visible to all threads and you also need to guarantee atomicity.

https://blog.knoldus.com/difference-between-synchronized-and-volatile-in-java/

**28. What are Atomic variables?**

Atomic variables are a way to perform atomic operations on primitive data types, such as integers, longs, and doubles, in a thread-safe and efficient manner. Atomic operations are operations that are fully executed without the possibility of being interrupted by another thread. This means that atomic operations either happen all at once or not at all, ensuring a consistent state of the variable being operated on

https://medium.com/@erayaraz10/understanding-atomic-volatile-and-synchronized-variables-in-java-differences-and-use-cases-b12f519a4c4b



# Concurrency Interview Questions

**1. runnable vs callable ?**

Runnable and Callable are both interfaces in Java that are used to represent tasks that can be run by multiple threads. However, there are some key differences between the two interfaces.

runnable: Runnable is a simpler interface with a single method, run(), which does not return anything. This means that Runnable tasks cannot return a result. Runnable tasks are typically used for fire-and-forget tasks, such as updating a GUI or logging data.

callable: Callable is a more powerful interface with a single method, call(), which returns a value. This means that Callable tasks can return a result, which can be useful for tasks such as processing data or performing calculations. Callable tasks are typically used when you need to get the result of a task back.

https://www.geeksforgeeks.org/difference-between-callable-and-runnable-in-java/

**2. What is Future Object?**

A Future object represents the result of an asynchronous computation. It provides methods to check if the computation is complete, to wait for its completion, and to retrieve the result of the computation.
In Java, the Future interface is defined in the java.util.concurrent package. It is used to represent the result of an asynchronous computation that is submitted to an ExecutorService.

https://www.digitalocean.com/community/tutorials/java-callable-future-example


**3. What is CompletableFuture?**

CompletableFuture is a class in java. util. concurrent package that implements the Future and CompletionStage Interface. It represents a future result of an asynchronous computation. It can be thought of as a container that holds the result of an asynchronous operation that is being executed in a different thread.

https://www.geeksforgeeks.org/completablefuture-in-java/


**4. Use of Done() , IsCancelled() and Cancel() method of Future Object?**

The Future interface in Java provides methods to check the status of an asynchronous task and to cancel it if necessary. The three methods you mentioned, Done(), IsCancelled(), and Cancel(), are all used for this purpose.

Done(): The Done() method returns true if the task has completed, either normally or by being cancelled. If the task is still running, Done() will return false.

IsCancelled(): The IsCancelled() method returns true if the task was cancelled before it completed normally. If the task is still running or has completed normally, IsCancelled() will return false.

Cancel(): The Cancel() method attempts to cancel the task. If the task is still running, Cancel() will try to interrupt the thread that is running it. If the task has already completed, Cancel() will have no effect.


https://connect2grp.medium.com/understating-java-future-and-callable-features-aec70d2aef6


**5. Explain ThreadLocal class**

ThreadLocal is a class in Java that allows you to create variables that can only be read and written by the same thread. This can be useful in situations where you have multiple threads accessing the same variable, but you want to ensure that each thread has its own isolated copy of the variable

https://www.geeksforgeeks.org/java-lang-threadlocal-class-java/


**6. What is CountDownLatch?**

CountDownLatch is a synchronization aid in Java that allows one or more threads to wait until a set of operations being performed in other threads is complete. It is a class in the java.util.concurrent package.

CountDownLatch is initialized with a count, representing the number of actions that must occur before the latch is released. Each action decrements this count. When the count reaches zero, all waiting threads are released.

CountDownLatch can be used in a variety of situations where you need to wait for multiple threads to complete their tasks before proceeding. For example, you could use CountDownLatch to wait for all of the threads in a thread pool to finish their work before shutting down the pool.

https://www.geeksforgeeks.org/countdownlatch-in-java/

**7. What is CyclicBarrier?**

A CyclicBarrier is a synchronization tool in Java that allows a group of threads to wait for each other to reach a common execution point, called a barrier. The barrier is initialized with a specific number of threads, and the threads wait until all of them reach the barrier using await methods.

https://www.baeldung.com/java-cyclic-barrier


**8. What is ReEntrant lock?**

A reentrant lock is a mutual exclusion mechanism that allows multiple threads to access a shared resource without causing a deadlock. It is implemented as a class in the Java programming language and is part of the java.util.concurrent package.

A reentrant lock can be acquired by a thread multiple times. When a thread acquires a reentrant lock for the first time, the lock's hold count is set to one. Each subsequent acquisition of the lock by the same thread increments the hold count by one. The lock is released when the thread calls the unlock() method the same number of times as it called the lock() method.

Reentrant locks are useful for protecting shared resources from concurrent access. For example, a reentrant lock could be used to protect a shared database connection or a file.

https://www.baeldung.com/java-binary-semaphore-vs-reentrant-lock



**9. ExecutorService.submit() vs Executor.execute()?**

The main difference between ExecutorService.submit() and Executor.execute() is that submit() returns a Future object, while execute() does not. This Future object can be used to check the status of the task, cancel it, or get its result.

https://www.geeksforgeeks.org/difference-between-executorservice-execute-and-submit-method-in-java/


**10. Different types of ThreadExecutor Services?**

CachedThreadPool: This type of thread pool creates new threads as needed and reuses them when they become available. It doesn't have a fixed number of threads and can create new threads as needed. However, if a thread is idle for a certain period of time, it is terminated and removed from the pool.

FixedThreadPool: This type of thread pool creates a fixed number of threads at the time of creation and reuses them for all tasks. It is useful when you want to limit the number of threads that are running simultaneously.

SingleThreadExecutor: This type of thread pool creates only one thread and uses it to execute all tasks. It is useful when you want to ensure that tasks are executed in the order in which they are submitted.

ScheduledThreadPoolExecutor: This type of thread pool creates a fixed number of threads and uses them to execute tasks that are scheduled to run at a specific time or with a specific frequency. It is useful for tasks that need to be executed periodically, such as sending emails or updating databases.

ForkJoinPool: This type of thread pool is designed to work with recursive tasks. It creates a pool of threads and uses them to execute tasks in a work-stealing algorithm. This means that if a thread is idle, it will steal work from other threads that are busy. This can improve performance for recursive tasks.

https://www.linkedin.com/pulse/types-thread-pool-executors-aniket-nandan/

**11. Explain how FixedThreadPool executor works?**

A FixedThreadPool executor is a type of thread pool that maintains a fixed number of threads to execute tasks. It is created using the Executors.newFixedThreadPool() method, which takes the number of threads to create as an argument.

When a task is submitted to a FixedThreadPool executor, it is added to a queue. If there are any available threads, one of them will pick up the task and start executing it. If all of the threads are busy, the task will remain in the queue until a thread becomes available.

FixedThreadPool executors are useful when you want to limit the number of threads that are used to execute tasks. This can be helpful for controlling resource usage or preventing your application from becoming overloaded.

https://medium.com/@himani.prasad016/thread-pools-in-java-b19ea1af7c4c


# Java 8 Interview Questions

**1. Interface8 changes**

Java8 Interfaces also introduced a static method for the interface, this is similar to the static method of the class. We cannot override the static method in the implementation class. Static methods are useful to implement utility functionalities that do not belong to any particular implementation class.

https://medium.com/javarevisited/java-8-interface-changes-functional-interface-interview-questions-67acecda534d


**2. What is Functional Interface? why do we need it?**

A functional interface in Java is an interface that has one abstract method. Introduced in Java 8, they're used to define new functions and manipulate existing ones. Functional interfaces are beneficial because they allow for more concise and expressive code.

Benefits: Functional interfaces allow developers to write more modular and reusable code by defining functions as values and passing them around as arguments or return values. They also help make code more readable, clean, and straightforward.

Implementation: Functional interfaces can be instantiated using lambda expressions, which avoids the need for bulky anonymous class implementation.

Annotation: While not mandatory, it's considered best practice to mark an interface as functional using the @FunctionalInterface annotation. This prevents accidental addition of extra methods and throws a compiler error if more than one abstract method is added.

Methods: While a functional interface can only have one abstract method, it can also have any number of static and default (non-abstract) methods.

Examples: Some examples of functional interfaces include Function, Consumer, Predicate, and Supplier.

https://www.geeksforgeeks.org/functional-interfaces-java/


**3. Difference between Collection and Stream**

Collections store data, while streams process data.

Collections are designed to store and organize data, while streams are designed to process data in a sequential manner.

Collections are eager, while streams are lazy.

Collections eagerly evaluate all of their elements when they are created, while streams lazily evaluate their elements only when they are needed.

Collections are mutable, while streams are immutable.

Collections can be modified after they are created, while streams cannot be modified after they are created.

Collections are finite, while streams can be infinite.

Collections have a fixed size, while streams can have an infinite number of elements.

Collections are thread-safe, while streams are not thread-safe.

Collections can be safely accessed by multiple threads, while streams cannot be safely accessed by multiple threads.

Here are some examples of how collections and streams can be used:

Collections can be used to store a list of names, a set of numbers, or a map of key-value pairs.

Streams can be used to filter a list of names, sort a set of numbers, or reduce a map of key-value pairs.

https://www.geeksforgeeks.org/difference-between-streams-and-collections-in-java/


**4. What is Terminal Operator vs Intermediate operators?**

In Java streams, terminal operations produce the final output, while intermediate operations modify the objects in the pipeline:

Terminal operations: These operations produce a result or side effect, and mark the end of stream processing. Once a terminal operation is executed, the stream can't be used further. Examples of terminal operations include toList(), forEach(), and reduce().

Intermediate operations: These operations transform a stream into another stream, and are only executed once a terminal operation is invoked. Examples of intermediate operations include distinct(), sorted(), and flatMap().


https://stackoverflow.com/questions/47688418/what-is-the-difference-between-intermediate-and-terminal-operations


**5. What is Optional?**

The Optional class in Java is a container object that may or may not contain a non-null value. It is intended to reduce the number of NullPointerExceptions in your code.

There are a few things to keep in mind when using Optional:

You can use the isPresent() method to check if a value is present.

You can use the get() method to get the value of a present value.

You can use the orElse() method to return a default value if the value is not present.

You can use the ifPresent() method to execute a block of code if the value is present.

You can use the map() method to transform values.

https://medium.com/javarevisited/optional-class-in-java-8-making-your-code-more-clear-and-concise-62af0712910d


**6. Flatmap vs Map?**

https://www.geeksforgeeks.org/difference-between-map-and-flatmap-in-java-stream/


**7. Difference between Parallel sort vs sort**

The main difference between parallel sort and sort is that parallel sort uses multiple threads to sort the data, while sort uses a single thread. This can make parallel sort much faster than sort, especially for large datasets.

Another difference is that parallel sort is a stable sorting algorithm, while sort is not. This means that parallel sort will preserve the original order of equal elements in the data, while sort may not.


https://www.baeldung.com/java-arrays-sort-vs-parallelsort


**8. Difference between Predicate vs BiPredicate?**

BiPredicate is a functional interface in Java that accepts two inputs and can return a boolean value. It is similar to the Predicate interface. The only difference is that it takes two inputs instead of one

https://ganeshkumarm1.medium.com/predicate-and-function-in-java-837b46c6dcf7


**9. How Diamond problem is solved in Java8?**

The diamond problem in Java can be solved in Java 8 and later versions by using virtual extension methods or interfaces. The diamond problem can occur when a class extends multiple classes that have the same name function, which can lead to ambiguity and program crashing.

https://www.geeksforgeeks.org/diamond-problem-in-java/


# Other Interview Questions

**1. Difference between JDK,JRE and JVM**

JDK, JRE, and JVM are all part of Java development and execution:

JDK: Java Development Kit is a software development kit used to develop Java applications. It contains tools for debugging, monitoring, and developing Java code. JDKs are platform-dependent, meaning you need a different JDK for each platform.

JRE: Java Runtime Environment is a software package that provides the Java Virtual Machine (JVM), class libraries, and other components to run Java applications. JREs provide programming tools and deployment technologies. They are also platform-dependent, so you need a different JRE for each platform.

JVM: Java Virtual Machine is the foundation of the Java programming language and ensures that a program's Java source code is platform-agnostic. It acts as an abstract layer between the program and the platform it's running on, making Java code portable. JVMs are included in both JDK and JRE, and Java programs won't run without them.

https://www.geeksforgeeks.org/differences-jdk-jre-jvm/

**2. What is Immutable class?**

In Java, an immutable class is a class whose state cannot be changed after it has been created. Immutable classes are useful in situations where the state of an object needs to remain constant, such as in multi-threaded environments. They are also important for safety, as they prevent side effects and are safe from cloning

https://www.digitalocean.com/community/tutorials/how-to-create-immutable-class-in-java


**3. What are solid principles?**

https://www.freecodecamp.org/news/solid-principles-explained-in-plain-english/

https://www.digitalocean.com/community/conceptual-articles/s-o-l-i-d-the-first-five-principles-of-object-oriented-design


**4. Difference between ClassNotFound vs NoClassDefError?**

The main difference between ClassNotFoundException and NoClassDefFoundError is that the ClassNotFoundException is thrown when the Java Virtual Machine (JVM) cannot find the class file, while the NoClassDefFoundError is thrown when the JVM can find the class file but cannot load it.

Here are some specific cases when each exception is thrown:

ClassNotFoundException

When the class file is not in the classpath.

When the class file is corrupted or invalid.

When the class file is for a different version of Java than the one that is running.

NoClassDefFoundError

When the class file is in the classpath but the JVM cannot load it.

When the class file depends on another class that is not in the classpath.

When the class file is for a different version of Java than the one that is running.

To resolve these errors, you can try the following:

ClassNotFoundException

Make sure that the class file is in the classpath.

Make sure that the class file is not corrupted or invalid.

Make sure that the class file is for the same version of Java as the one that is running.

NoClassDefFoundError

Make sure that the class file is in the classpath.

Make sure that the class file does not depend on another class that is not in the classpath.

Make sure that the class file is for the same version of Java as the one that is running.

https://help.liferay.com/hc/en-us/articles/360029316331-Resolving-ClassNotFoundException-and-NoClassDefFoundError-in-OSGi-Bundles



**5. What is Singleton Design pattern? Explain ThreadSafe Singleton and Bill Pugh Singleton ?**

https://www.geeksforgeeks.org/java-singleton-design-pattern-practices-examples/

A thread safe singleton works fine in multi-threaded environments but reduces performance because of the cost associated with the synchronized method. To overcome the issue of synchronization, Bill Pugh came up with his implementation using the static inner helper class.

https://dzone.com/articles/singleton-bill-pugh-solution-or-enum


**6. How to break Singleton?**

https://dzone.com/articles/prevent-breaking-a-singleton-class-pattern


**7. Explain few features in each Java versions starting from Java8**

https://www.geeksforgeeks.org/java-8-features/