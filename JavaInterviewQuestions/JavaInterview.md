##############STRING ################

1. Why are strings immutable in java?

https://www.scaler.com/topics/why-string-is-immutable-in-java/

2. How intern() works?

https://www.scaler.com/topics/intern-in-java/

3. How many objects are created in Strings using string literals and new operator?

Two objects are created.

When a string literal is encountered in Java, the Java Virtual Machine (JVM) checks the string constant pool to see if the string already exists. If it does, the JVM reuses the existing string object. If the string does not exist in the pool, the JVM creates a new string object and adds it to the pool.
When the new keyword is used to create a string object, the JVM always creates a new string object, even if the string already exists in the string constant pool.


4. How string constant pool works?

https://www.geeksforgeeks.org/string-constant-pool-in-java/

https://www.scaler.com/topics/java/string-pool-in-java/

5. Difference between equals and == operator?

The equals() method and the == operator are used to compare two objects in Java. However, there is a subtle difference between the two.
The equals() method compares the content of two objects, while the == operator compares their memory addresses. This means that if two objects have the same content but are stored in different memory locations, the equals() method will return false, while the == operator will return true.

https://unacademy.com/content/gate-cse-it/difference-between-operator-and-equals-method-in-java

6. Difference between string , string buffer and string builder.

In Java, String, StringBuffer, and StringBuilder are all classes used to handle strings, but they differ in mutability and thread safety:
String: Immutable, meaning the object can't be changed after creation.
StringBuffer: Mutable, meaning the object can be modified without creating a new object. It's thread-safe, so multiple threads can use it simultaneously.
StringBuilder: Mutable, meaning the object can be modified without creating a new object. It's not thread-safe, so it shouldn't be used in multi-threaded environments

https://www.digitalocean.com/community/tutorials/string-vs-stringbuffer-vs-stringbuilder



##################OBJECT #####################

1. Why is wrapper class required?

Wrapper classes are objects that wrap around primitive data types in programming languages. They can be useful in a variety of situations, including:
a. Converting between primitives and objects: Wrapper classes make it easier for developers to use objects instead of primitives when coding.
b. Displaying related data: In Salesforce, wrapper classes can be used to encapsulate related records, such as parent and child records, in a single Visualforce page. This allows developers to easily manage and display the data in a structured format.
c. Working with collections: Wrapper classes are essential for working with collections, which are collections of objects that are dealt with using pre-defined methods.
d. Calling methods on primitive data types: Wrapper classes can be used to call methods on primitive data types.
e. Representing the absence of a value: Wrapper classes can be used to represent the absence of a value.
f. Synchronization in multithreading: Objects are needed to support synchronization in multithreading, and wrapper classes can help in this case

2. Methods of Object class?

The Object class is the root of all classes in Java. It provides several methods that are common to all objects. These methods are:
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

3. Does java gives importance to primitive data types?

Yes, Java gives importance to primitive data types. Java is a statically typed language, which means that the data type of a variable must be known at compile time. This ensures that the code is more reliable and less prone to errors.

Primitive data types are the basic data types that are built into the Java language. They are:
byte, short, int, long, float, double, char, and boolean.

Primitive data types are important because they are the most efficient way to store data in Java. They are also the most widely used data types in Java programs.
In addition to primitive data types, Java also has reference data types. Reference data types are objects that are created by the programmer. They are not as efficient as primitive data types, but they are more flexible.
Here are some of the reasons why Java gives importance to primitive data types:
Efficiency:
Primitive data types are the most efficient way to store data in Java. They are stored directly in memory, which makes them very fast to access.
Simplicity:
Primitive data types are very simple to use. They do not have any methods or properties, which makes them easy to understand and use.
Portability:
Primitive data types are the same on all Java platforms. This makes it easy to write portable Java code that can run on any platform.
Overall, primitive data types are very important in Java. They are the most efficient and simple way to store data in Java. They are also the most widely used data types in Java programs.

4. Is Java pass by value or pass by reference?

Java is always pass by value. This means that when you pass an argument to a method, a copy of that argument is made and passed to the method. The original argument is not changed.
This is true for both primitive types (such as int and boolean) and object types. When you pass an object to a method, a copy of the object reference is passed to the method. The original object reference is not changed.
However, it is important to note that the object itself can be changed. This is because the object reference that is passed to the method points to the original object. If the method changes the state of the object, the original object will also be changed.



##################OOPS################

1. Composition vs Aggregation vs Association?

https://medium.com/@bindubc/association-aggregation-and-composition-in-oops-8d260854a446

2. Function overloading vs overriding

https://www.shiksha.com/online-courses/articles/difference-between-overloading-and-overriding/

3. Difference between Abstract class and Interface?

https://www.geeksforgeeks.org/difference-between-abstract-class-and-interface-in-java/

4. Can private method or static methods be overridden in Java?

No, private methods and static methods cannot be overridden in Java. Here's why:
Private methods
Private methods are accessible only within the class in which they are declared.
Subclasses cannot access private methods of their superclasses.
Therefore, subclasses cannot override private methods.
Static methods
Static methods are associated with the class itself, rather than with an instance of the class.
When a subclass inherits a static method from its superclass, it is not possible to override the behavior of that static method. 


Instead, the static method of the superclass will be called.
Final methods
Final methods cannot be overridden in Java.
If a method is declared as final in a superclass, then it cannot be overridden in any of its subclasses.
This is because final methods are intended to be the final implementation of a method.

https://www.prepbytes.com/blog/java/can-we-override-static-method-in-java/

5. Can main() method be overloaded?

Yes, the main() method can be overloaded in Java, but the JVM (Java Virtual Machine) only calls the original main method with the signature public static void main(String[] args).

https://www.scaler.com/topics/can-we-overload-main-method-in-java/

6. Can Abstract class have main method?

Yes, an abstract class in Java can have a main method and can be run like any other class. Abstract classes can also have other types of methods, including:
Abstract methods: Can't have bodies, but can be declared with the abstract keyword
Non-abstract methods: Can be included in an abstract class
Final methods: Can prevent child classes from changing the method's body
Static methods: Can be defined in an abstract class

https://cs-fundamentals.com/tech-interview/java/can-we-run-abstract-class-in-java-that-has-main-method




#################Serialization###################

1. What is Serialisation and Deserialisation?

https://www.geeksforgeeks.org/serialization-in-java/


2. Use of transient keyword?

The transient keyword in Java is used to tell Java to ignore an attribute when serializing an object. Serialization is the process of converting an object's state into a byte stream that can be saved to a file, database, or transmitted over a network. The transient keyword can be useful in situations where you have sensitive or temporary data that you don't want to serialize.

https://www.upgrad.com/blog/transient-keyword-java/

3. Is it possible to serialise a class if its super class is not serialisable ?Can the class be still serialised and deserialised?

Yes provided that non-serialisable super class has no args constructor which is involved at deserialisation to initialise the super class.

4. Can Uninitialised non serialised , non transient fields still be tolerated?

Yes

During serialization, we need to handle IOException ; during deserialization, we need to handle IOException and ClassNotFoundException . So the deserialized class type must be in the classpath. Uninitialized non-serializable, non-transient instance fields are tolerated

##########Cloning###################

1. What is marker interface?

https://www.geeksforgeeks.org/marker-interface-java/

2. What is shallow copy and Deep copy?

A shallow copy and a deep copy are both ways to copy an object, but they differ in how they handle references to other objects:

Shallow copy: Creates a new object that shares the same references as the original object. This means that if you change either the original or the copy, the other object may also change. For example, if a shallow copy creates a new array, it points to the same elements as the original array instead of creating new copies.

Deep copy: Creates a new object that is completely independent of the original object. This means that changes to the deep copy do not affect the original object. For example, a deep copy creates a completely independent copy of an array and its data, so it doesn't share any data with the original array

https://www.geeksforgeeks.org/difference-between-shallow-and-deep-copy-of-a-class/


##################Exception###################

1. Difference between Error and Exception?

https://www.shiksha.com/online-courses/articles/difference-between-errors-and-exceptions-in-java-blogId-155937

2. Checked vs Unchecked Exception?

https://www.geeksforgeeks.org/checked-vs-unchecked-exceptions-in-java/

3. Create custom Exception?

https://www.geeksforgeeks.org/user-defined-custom-exception-in-java/


4. What is Runtime exception ?

A runtime exception is an exception that can occur during the normal operation of a virtual machine (VM). In Java, RuntimeException is the superclass of all classes that throw exceptions during normal VM operation. Runtime exceptions, also known as unchecked exceptions, can occur anywhere in a program and can be very numerous. The compiler doesn't require that runtime exceptions be caught or specified, but they can be.

https://www.geeksforgeeks.org/java-program-to-handle-runtime-exceptions/

5. How does JVM handle Exception?

https://medium.com/geekculture/how-does-exception-handling-work-in-java-c71c45103e7d

6. Difference between Final, Finalise and Finally?

https://www.geeksforgeeks.org/g-fact-24-finalfinally-and-finalize-in-java/


7. Super class of all exceptions?

In Java, the Throwable class is the superclass of all exceptions and errors. It is a direct subclass of the Object class and has two direct subclasses, Exception and Error.


8. Is throwable an interface?

Yes, Throwable is an interface in Java. It is the root of the Java class hierarchy and is the superclass of all errors and exceptions. Throwable has two direct subclasses: Error and Exception.
Throwable is the base interface for any object that can be thrown via a throw statement, including Error and Exception. 

https://www.geeksforgeeks.org/throwable-class-in-java-with-examples/


9. When Finally block doesn't get executed?

https://www.scientecheasy.com/2020/05/java-finally-block-not-executed.html/

10. Can subclass throw higher checked exception than base class?

No, a subclass cannot throw a higher checked exception than its base class. This is because the subclass is inheriting the contract of the base class, and part of that contract is the set of exceptions that the class can throw. If the subclass were to throw a higher checked exception, then it would be breaking that contract.

https://medium.com/@salvipriya97/java-rules-to-follow-when-using-checked-exceptions-with-inheritance-62cd3a6dfc6c

11. Can we throw an unchecked exception in child class if parent class doesn't throw any exception?


Yes, in Java, you can throw an unchecked exception in a child class even if the parent class does not declare any exceptions. Here's why:

Unchecked Exceptions: Unchecked exceptions in Java are subclasses of RuntimeException or Error. These exceptions do not need to be declared in a method's throws clause.

Inheritance of Exceptions: When you override a method from a parent class in a child class, you can throw any unchecked exception or subclass thereof, regardless of whether the parent method declares any exceptions.

Exception Compatibility: Java allows subclasses to throw a narrower range of exceptions than the superclass. This means you can throw fewer exceptions, more specific exceptions, or unchecked exceptions in the child class method that overrides a parent class method.

There are two important points to remember while handling exceptions using method overriding. If the superclass method does not declare an exception, then the overriding subclass method cannot declare a checked exception, but it can declare an unchecked exception.

12. Difference between throw and throws()

https://www.geeksforgeeks.org/difference-between-throw-and-throws-in-java/



###############Usage of Enum##############

1. Why to use Enum?

Enums are used to give names to constants, which makes the code easier to read and maintain.


#################Garbage collection##################

1. How does Garbage collection in Java works?

Garbage collection in Java is a process of automatic memory management. It automatically reclaims memory that is no longer in use by the program.
The garbage collector works by using a mark-and-sweep algorithm. The mark phase traverses the object graph starting from the roots. The roots are objects that are known to be in use, such as global variables and objects referenced by local variables. The mark phase marks all objects that are reachable from the roots. The sweep phase then reclaims all objects that are not marked.

https://newrelic.com/blog/best-practices/java-garbage-collection


#############Collection################

1. Array vs ArrayList?

https://www.simplilearn.com/difference-between-array-and-arraylist-article

2. ArrayList vs LinkedList? When to use which collection?

https://www.naukri.com/code360/library/difference-between-arraylist--linkedlist-that-everyone-should-know

3. Fail Safe vs Fail Fast Iterators?

https://www.geeksforgeeks.org/fail-fast-fail-safe-iterators-java/


4. What is concurrent modification exception?

In Java, a ConcurrentModificationException is a runtime exception that occurs when an object is modified without permission while another operation is being performed on the same collection. This can happen when a thread is iterating over a collection using an Iterator while another operation is performed on the collection. For example, modifying a list's structure with subList while a thread is traversing it can also cause this exception

https://www.fusion-reactor.com/blog/resolving-concurrentmodificationexception-in-java-a-guide-to-understanding-avoiding-and-fixing/


5. Internal working of HashMap

https://www.geeksforgeeks.org/internal-working-of-hashmap-java/


6. Java8 changes to HashMap

Java 8 made significant changes to the HashMap class, primarily focused on improving performance in the presence of hash collisions. These changes include:

Removal of the alternative String hash function:
Java 7 introduced an alternative hash function for Strings, but it was found to be less effective than the original function in many cases. Java 8 removed this alternative function, restoring the original behavior.
Storing entries in a balanced tree instead of a linked list:
When a bucket in a HashMap contains a large number of colliding entries, Java 8 will automatically store those entries in a balanced tree instead of a linked list. This change improves the performance of get() and put() operations in these cases, from O(n) to O(log n).
Improved performance for key collisions:

Java 8 also made a number of other changes to the internal implementation of HashMap to improve its performance in the presence of hash collisions. These changes include using a more efficient algorithm for finding empty buckets, and using a more compact data structure for storing entries in linked lists.
Overall, the changes to HashMap in Java 8 result in a significant performance improvement for applications that use HashMaps heavily, especially in cases where there are a large number of hash collisions.


7. Why HashMap contains null key?

HashMap allows one null key and multiple null values. This is because HashMap is implemented using a hash table, which is a data structure that maps keys to values. The hash table is designed to be very efficient for storing and retrieving data, but it does not allow for null keys. To allow for null keys, HashMap uses a special value called NULL_KEY to represent the null key.
There are a few reasons why HashMap allows null keys. First, it allows for more flexibility in how HashMaps are used. For example, a 

HashMap could be used to store a list of objects, where the key is the object's ID and the value is the object itself. If an object is deleted, its ID can be set to null to indicate that it is no longer in the list.
Second, allowing null keys can improve the performance of HashMaps in some cases. For example, if a HashMap is used to store a cache of data, and the data is frequently updated, it can be more efficient to simply set the key to null when the data is updated, rather than removing the key from the HashMap.

Finally, allowing null keys makes HashMaps more consistent with other Java collections, such as HashSet and ArrayList. These collections all allow null values, so it makes sense for HashMap to allow null keys as well.
However, there are also some potential drawbacks to using null keys in HashMaps. First, it can be easy to accidentally introduce null keys into a HashMap, which can lead to unexpected behavior. For example, if a HashMap is used to store a list of objects, and a null key is inserted into the HashMap, the list will no longer be ordered correctly.

Second, using null keys can make it more difficult to debug problems with HashMaps. For example, if a HashMap is used to store a cache of data, and the data is not being updated correctly, it can be difficult to track down the problem if the key is null.


8. Is it Mandatory to have key immutable in HashMap?

While it's not mandatory for a HashMap key to be immutable, it's recommended. Immutable keys help ensure that the hash code and equality remain constant, even if the key is changed after it's been used in the HashMap. If a mutable key is changed, the hash code can change, which can lead to incorrect value retrieval. Immutable keys can also improve performance and provide better code control

https://www.thetechnojournals.com/2019/10/why-hashmap-key-should-be-immutable-in.html


9. Why to override equals() and hashcode() method?

https://lazy-programmer.medium.com/why-it-is-important-to-override-equals-and-hashcode-method-for-custom-objects-1d2bc629b5c4


10. HashSet vs LinkedHashSet vs TreeSet

https://www.geeksforgeeks.org/difference-and-similarities-between-hashset-linkedhashset-and-treeset-in-java/


11. What is the Internal Datastructure in TreeMap? How the elements are sorted?

https://medium.com/@basecs101/treemap-in-java-collection-framework-interview-question-a3f81c7aaa84


12. HashMap vs ConcurrentHashMap

https://www.geeksforgeeks.org/difference-hashmap-concurrenthashmap/


13. Comparable vs Comparator

https://www.geeksforgeeks.org/comparable-vs-comparator-in-java/


14. What is blocking Queue?

https://www.digitalocean.com/community/tutorials/java-blockingqueue-example


15. What is Vector? When to use it?

Vectors are utilized in the storage of locations, directions, and velocities in video games. The position vector tells us how far away the object is, the velocity vector tells us how long time it will take or how much force we need to apply, and the direction vector tells us how we should apply that force.

https://www.javatpoint.com/when-to-use-vector-in-java



###############MultiThreading################

1. MultiThreading vs MultiProcessing vs MultiProgramming vs MultiTasking?

https://www.geeksforgeeks.org/difference-between-multitasking-multithreading-and-multiprocessing/


2. Life cycle of a Thread

https://www.geeksforgeeks.org/lifecycle-and-states-of-a-thread-in-java/


3. Extends vs Runnable

https://www.geeksforgeeks.org/implement-runnable-vs-extend-thread-in-java/


4. yield() vs sleep() vs join() ?

https://www.geeksforgeeks.org/java-concurrency-yield-sleep-and-join-methods/


5. wait() vs sleep() ?

https://medium.com/@reetesh043/understanding-the-difference-between-wait-and-sleep-methods-64958feffbb8


6. why is join() method used?

The join() method is used to wait for a thread to finish its execution. When a thread calls join() on another thread, it will block until the other thread finishes executing. This can be useful for ensuring that a thread has completed a task before another thread starts.
For example, you might have a thread that is responsible for reading data from a file. You could use the join() method to wait for the thread to finish reading the file before starting another thread that processes the data. This would ensure that the second thread does not start processing the data before it has all been read.
The join() method can also be used to synchronize threads. For example, you might have two threads that are both writing to the same file. You could use the join() method to ensure that one thread finishes writing to the file before the other thread starts. This would prevent the two threads from overwriting each other's data.

https://www.geeksforgeeks.org/joining-threads-in-java/


7. Can we Override start() method in Thread?

Yes, we can override the start() method in the Thread class. However, it is not recommended to do so. The start() method is responsible for creating a new thread and starting its execution. If we override the start() method, we can change its behavior and prevent it from creating a new thread. This can lead to unexpected results and can make it difficult to debug our code.

https://www.geeksforgeeks.org/overriding-thread-class-start-method/


8. Can we Override run() method?

Yes, we can override the run() method in Java. The run() method is declared in the Thread class and is responsible for executing the code of the thread. When a thread is started, the run() method is called.
To override the run() method, we need to create a subclass of the Thread class and implement the run() method in the subclass. The run() method in the subclass will replace the run() method in the Thread class.

https://www.geeksforgeeks.org/overriding-thread-class-start-method/


9. Can we start the thread twice?

No, a thread cannot be restarted after it has been begun. An IllegalThreadStateException is raised if you do so. In this situation, the thread will execute once, but will throw an exception the second time.

https://www.javatpoint.com/can-we-start-a-thread-twice


10. What is IllegalThreadStateException?

In Java, an IllegalThreadStateException is thrown when an operation is attempted on a thread that is not in the right state for that operation. For example, this can happen when dealing with threads or the Collections framework of the java.util package under certain conditions

11. What happens if run() method is called without start()?

If you call the run() method directly instead of using start() , the code in the run() method will be executed in the current thread of execution rather than in a new thread. This means that the code will be executed sequentially in the current thread, without creating a new thread of execution

https://medium.com/javarevisited/dont-get-stuck-in-neutral-knowing-when-to-use-run-or-start-in-multithreading-dbd85a59e75d


12. Why do we use ThreadPool?

Thread pools are used to improve the performance of an application by separating the creation and management of threads from the execution of tasks. They can also help reduce resource consumption and improve response speed:

Reduce resource consumption: Thread pools reuse created threads, which reduces the overhead of creating and destroying threads for each task.

Improve response speed: Tasks can be executed immediately when they arrive, without waiting for a thread to be created.

Improve manageability of threads: Thread pools can be used to allocate, tune, and monitor threads, which are scarce resources

https://stackify.com/java-thread-pools/

13. What is Race Condition?

https://www.techtarget.com/searchstorage/definition/race-condition


14. What is Synchronisation? Types of Synchronisation

https://www.geeksforgeeks.org/synchronization-in-java/


15. Object Level Locking vs Class Level Locking?

https://www.geeksforgeeks.org/object-level-class-level-lock-java/


16. If there is 2 synchronised methods m1 and m2 in a class, can 2 different threads t1 and t2 call different methods(m1,m2) respectively on same object of class c at same time ?

No. Only 1 Thread can hold the lock on a object of a class.However the other non synchronised methods can be called on same object.

17. If a class has a synchronised method and non synchronised method, can multiple threads execute non synchronised methods?

Yes. If a class has a synchronised method and non synchronised method , multiple threads can access non synchronised methods.

Yes, a Non synchronized method can always be called without any problem. In fact Java does not do any check for a non-synchronized method. The Lock object check is performed only for synchronized methods/block

18. Can 2 threads call 2 different static synchronised methods of same class?

The static synchronised methods of same class always block each other as 1 lock per class exists. So no 2 static synchronised methods can execute at the same time.

19. Does static synchronised methods block a non synchronised methods?

No. The thread executing static synchronised method holds a lock on the class and the executing the non static synchronised method holds lock on the object on which the method has been called, these 2 locks are different and these threads dont block eachother.

20. Can Constructors be synchronised?
21. What is DeadLock?
22. What is Inter thread communication?Explain wait(),notify() and notifyall()?
23. What is IllegalMonitorStateException?
24. Which class does wait(),notify() and notifyall() method belong?
25. Explain few Thread class methods?is Sleep() a method in Thread class or Object class?
26. Producer Consumer Problem in Java?
27. Volatile vs Synchronised?
28. What are Atomic variables?



###########Concurrency########################

1. runnable vs callable ?
2. What is Future Object?
3. What is CompletableFuture?
4. Use of Done() , IsCancelled() and Cancel() method of Future Object?
5. Explain ThreadLocal class
6. What is CountDownLatch?
7. What is CyclicBarrier?
8. What is ReEntrant lock?
9. ExecutorService.submit() vs Executor.execute()?
10. Different types of ThreadExecutor Services?
11. Explain how FixedThreadPool executor works?



############Java 8#####################

1. Interface8 changes
2. What is Functional Interface? why do we need it?
3. Difference between Collection and Stream
4. What is Terminal Operator vs Intermediate operators?
5. What is Optional?
6. Flatmap vs Map?
7. Difference between Parallel sort vs sort
8. Difference between Predicate vs BiPredicate?
9. How Diamond problem is solved in Java8?



#########Other##############

1. Difference between JDK,JRE and JVM
2.What is Immutable class?
3. What are solid principles?
4. Difference between ClassNotFound vs NoClassDefError?
5. What is Singleton Design pattern?Explain ThreadSafe Singleton and Bill Pugh Singleton ?
6. How to break Singleton?
7. Explain few features in each Java versions starting from Java8