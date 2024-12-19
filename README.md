<h1>Multithreaded Proxy web server with LRU cache</h1>
If multiple client connected to the same network requesting the same site again and again it take lot of time request to the same server , here proxy web server help to resolve this problem ,
in this project, if any client visit any website then web server will store that response into the cache , for the future requesting client.


![1](https://github.com/user-attachments/assets/56e2474a-d81d-42cd-a4b2-5673f4da14f5)
![2](https://github.com/user-attachments/assets/46b60cc2-f8c1-48a7-9e75-8c2a8e4c7b07)

## Structure of Request coming
![6](https://github.com/user-attachments/assets/34472ef1-b2db-4687-9196-545187fb160e)
we are using a library to parse this request ,so that we can store the url , body , port etc into the cache.
## Structure of LRU cache
![3](https://github.com/user-attachments/assets/fa46fc17-c46c-4a71-b1c5-5ab0092c5a56)

### Locks working 
- Mutex lock
![5](https://github.com/user-attachments/assets/b1311ca0-3c87-49d8-9121-aa77866f3db1)

- Semaphore , it is integer value and also same as locks
if sem = 10 then max_client can access the cache are 10 , other have to wait in queue
In Semaphores their are two function : 
1. sem_wait() -- it check the sem value if it positive then allow the thread to do manipulations of cache and decrease sem value by 1;
else if sem value is negative then thread have to wait until signal function is called.

2. sem_post() -- when thread exit this function invokes and sem value increased by 1;

## Result
![4](https://github.com/user-attachments/assets/6fbb3e22-61de-48e5-9fed-b4f77c2e0c6d)

 - When website is opened for the first time (`url not found`) then cache will be miss.
 - Then if you again open that website again then `Data is retrieved from the cache` will be printed.
## Limitation 
- Only work for HTTP/1.0 AND HTTP/1.1 version
- Fixed size of cache element , so big website may not be stored in cache.
