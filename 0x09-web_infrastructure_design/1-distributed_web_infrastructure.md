![Design of distributed web infrastructure](1-distributed_web_infrastrucure.png)

# **Description**
A three-server web infrastructure that hosts the website `www.foobar.com` and attempts to reduce traffic of incoming requests to the main server by distributing the load to the available servers.

# **Infrastructure specifications**
- For every additional element, why you are adding it.
* Load balancer (High Availability Proxy): Distribute network traffic accross multiple servers to ensure that no single server is overwhelmed with requests, improving overall performance and reliability.
* Additional servers: Added to handle increased traffic as the load on the system increases.
- What distribution algorithm your load balancer is configured with.
Round Robin: One of the simplest methods for distributing client requests accross servers by load balancer forwarding the request to the next server in the list. the process continues in circular order, looping back to the first erver when the list end is reached.
- Is my load balancer enabling an `Active-Active` or `Active-Passive` set-up?
My load balancer enables an `Active-Active` setup in which all nodes are active and share the workload preventing any single node from getting overloaded. In an `Active-Passive` setup one node is active while the others are on stanby ready to take over in case the active node fails ensuring service continuity without load distribution.
- How a database primary -Replica (Master-Slave) cluster works.
The master database is the primary database that receives all the write operations. The replica databases (slaves) are copies of the master and can handle read operations which helps distribute the load. In the replication process, the master logs the updates which ripple through to the replicas in either synchronous (simultaneous) or asychronous (queued up) replication. A fallover mechanism promotes one of the copies to be the new master in case the primary database fails.
- The difference between the Primary node and the Replica node in regard to application.
The Primary node handles the write operations as the main node that receives all updates, logs them and prepares them for replication. The Replica node handles the read operations synchronized with the primary node through replication.
- Where are SPOF in this infrastructure?
SPOFs can occur in various areas:
* Hardware lacking redundancy, Software lacking a fallover mechanism, Network failure, Human error in the absence of a single informed operator, External systems failure, having only one Power supply, or Physical or Virtual machine running redundant components on the same machine.
- Issues with lack of security (HTTPS, firewall)
Data interception, Unauthorized access, susceptibility to `denial of service` attacks, software vulnerabilities and lack of trust when the website is flagged as `not secure`.
- No monitoring.
Lack of visibility that helps understand the state of the infrastructure at any given moment, Troubleshooting dificulties when issues arise, Performance issues to help notice performance degradations, capacity planning to understand the systems capacity and planning for growth, Security vulnerabilities that would identify unusual activity indicating a security breach.
