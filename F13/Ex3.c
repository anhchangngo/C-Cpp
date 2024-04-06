/*
Visit the root 10, which having 2 child nodes 4 and 8,  we will enqueue node 4 and 8 to the queue
Then visit the node 4 having child node 13, enqueue 13 to queue, dequeue 4 
Traverse to next node in the queue (8 having 2 child nodes 20 and 90, enqueue 20 and 90 to the queue, dequeue 8
Traverse to next node 13, no child, no enqueue, dequeue 13 
Next... 
traverse result is: 10 4 8 13 20 90
*/