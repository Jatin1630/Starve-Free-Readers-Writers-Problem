                                            Starve-Free-Readers-Writers-Problem 
It is one of the most common problem in process synchronization. There are two type of users -> the Readers, who wants to read the shared resource and the Writers, who wants to modify the shared resource. There are three variations to this problem.

## First Readers–Writers problem
It allows that when at least one reader is accessing the resource, new readers can also enter the critical section to read that resource. However, in this case, the writer may lead to starvation as it may not get a chance to modify the resources as new readers may continuously enter to read the resource.

## Second Readers–Writers problem
In this problem, the readers may starve. Writers are given preference in this problem. The reader must wait until the last writer exits the critical section by modifying the resource and release the lock to allow readers to access the resource.

## Third Readers–Writers problem
This overcomes the drawbacks of the previous two starvation problems and, therefore, is also known as the Starve-Free-Readers-Writers-Problem. It will give priority to the resources in the order of their arrival. For example, if a writer wants to write to the resource, it will wait untill the current readers execute their tasks. Meanwhile, other readers accessing the resources would not be allowed to do so.

## Explanation of the Code
We will make use of three semaphores:

rd_mutex --> used while updating the readers count. Therefore it would only be available to readers method.
get_access --> This would be either in control of readers or the writer. If the readers are reading, then if writer would try to access the critical section would get blocked and vice versa. However if one reader is reading and another reader try to access then there won't be any problem. This semaphore get updated at 3 instances. First, when 1st reader arrives. Secondly when the last reader left the critical section. Lastly, when any writer will would write to the resource.
order --> This semaphore is used at the start of entry section of readers/writers code. This only checks that if there is any process already waiting for its turn. If so, it gets blocked. If not, then it access the semaphore and no new reader/writer could now execute before this process. Therefore, it helps in preserving the order of process.
We would also make use of a variable rd_count to update the number of readers at a particular time.

For the read method we would first call wait for order and rd_mutex. If any process is already in queue order would be 1 and thus calling process would be blocked. Otherwise it would make order "1". rd_mutex would check that no other process is updating the readers count. If reader count was 0 then don't allow writer to access the critical section. After reader count is updated both the semaphore are released. After reading of resource read_count is decremented by getting hold of rd_mutex. If reader count is 0, writers can now access critical section.

We would first check the order semaphore for the write method, and then the writer would get access with the get_access semaphore. Since, the order would be preserved we could release the order semaphore. Then writers modify the resource and finally release get_access.

Hence , our purpose is achieved in this way.                   
