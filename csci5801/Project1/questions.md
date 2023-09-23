# standardize logging format
### Q
    
    
### A
    titles and values seems best, new titles can be added with changing values and searching by titles would be easier.

# Adding new types of items
## no restrictions
### Q
    is it still text or are we storing graphs/videos/images
### A
    we could take uploaded files save them to a location and then store a link to the file?
## new types of data can be added
### Q
### A
# search and filter data 
    sql??

# interactive and batch processessing
    what does this mean, 


can we get examples of previous logged data so we can understand what kind of data is expected.



# Questions

1. what kind of data is being stored is it just text or is it images, videos, audio?
(this will give us an idea of what our standard will need to cover)

2. what data is always required to be tracked
(what data will we need to require/can auto track what do we need to ask)

3. can we get examples of data that was previously tracked
(this can give us an idea as to what has "worked" previously and what to change)

4. will there be people who can keep track of the system, can we use aministrators to modify what data is required as data evolves
(this will tell us if the system needs security structure and if its possible to keep someone in charge of controlling data)
 4a. how many levels of security are needed, who needs to see, change, and add any kind of data.

5. are we expecting to do calculations daily and then also when data is accessed? what do we mean by interactive and batch

6. when new data is required to be logged how do we update old data, leave it the same or give it a placeholder.
    6a. what should the placeholder be.


(the software so far seems like it would work best as a webserver that stores data that can be accessed and changed but stored in one place, requiring all data to go through this system)

from assumptions 
webserver accessed through a website most likely
uses sql to store, sort and filter data on backend
required formatting controlled by admins

need to know, what data to store,
this will help us to decide how to store, and what to put on a gui.

how to access data, how are we searching or filtering or displaying data?
