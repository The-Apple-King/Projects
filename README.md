# CSCI 3081 Project - Drone Simulation System

010-47
Owen Swearingen, SWEAR041

#### What is in this directory?
<ul>
  <li>  <code>README.md</code>
  <li>  <code>.gitignore</code>
  <li>  <code>app</code> folder, which contains:
    <ul>
      <li>  <code>graph_viewer</code> : producing graph visualization
      <li>  <code>transit_service</code> : visualization
    </ul>
  <li>  <code>libs</code> folder, which contains:
    <ul>
      <li>  <code>routing</code> : finding the paths
      <li>  <code>trainsit</code> : entities properties
    </ul>
  <li>  <code>dependencies</code>
</ul>

## Getting Started

Here is a quick overview of how to run the visualization (If you are using ssh, navigate to ssh category below):

    ```bash
    # Go to the project directory
    cd /path/to/repo/project
    
    # Build the project
    make -j
    
    # Run the project (./build/web-app <port> <web folder>)
    ./build/bin/transit_service 8081 apps/transit_service/web/
    ```
    
Navigate to http://127.0.0.1:8081 and you should see a visualization.

Navigate to http://127.0.0.1:8081/schedule.html and you should see a page to schedule the trips.

*Note: 8081 will depends on what port you used. If you use port 8082, then it will be http://127.0.0.1:8082 instead.*

# Simulation

## Schedule
You will be able to schedule the robots for a ride or order food from a restaurant in this page http://127.0.0.1:8081/schedule.html. 

### Ride
To schedule a ride, type passenger name, select start and end destination, and then press `Schedule Trip` button to schedule a trip for your passenger. 

### Food
To order food delivery, type client name, select your restaurant from the drop down menu, and then press `Order Food` button to send the drone to pick up the food and drop it off at the robot. 

### People
In order to add people to the simulation click the `add person` button to spawn another person to run around the map.

Now go to 3D Visualization page and select the view of the entities on top right corner.

## 3D Visualization
You will be able to watch the simulation of the drone and the passenger here http://127.0.0.1:8081.

On top right corner, you can change your camera view into locking the entities.

There are a few entities that exist to make the map more lively, a helicopter, a jogger, and a dragon. These move to a random point and then pick another point to move to.

Drones are given jobs to do by the robots and the drones will pick up and drop off the robots or food at the destination specified.


# New Features

## Restaurants
In order to make the simulation more interesting we added food orders to the mix, this gives a completely new type of movement to the simulation and another type of order for drones to fulfil. 

This new feature didn't use a design pattern we added it on top of the existing javascript used to schedule rides.

 ## Data Collection
 Every time a trip is completed a drone sends data to a singleton class in order to store and later output the data to a csv and txt file. Using singleton allows the entire simulation access to the same data making it easier to output and implement. output.csv collects all the data while output.txt saves sorted data in an easy to read through file. The stored data includes the name of the drone that completed the order, the name of the client, the start and ending positions of the drone, the distance flown, and the name of the restaurant if it was a food order.

 The output.txt file contains which drone went furthest, the number of trips for each drone, the orders and what they were for, and the movement strategies used in order to deliver the clients or their food to the destination.

 ## Specialized Drones
 This new feature implements chain of command in order to determine which drone should take an order. Using chain of command allows us to implement more rules easily in the future by adding another link to the chain. The rules set up are Drone1 will prefer giving robots rides and Drone2 will prefer food orders. If there are none of the prefered orders available, but there are not prefered orders available the drone will take a less prefered order in order to finish tasks faster.

# Sprint Retrospective
Sprints are a good way to keep organized when writing code, but it becomes quite difficult to stay on top of things when you miss a meeting. They are also difficult to write requirements for when the specifics of your project aren't fully understood which forces you to think about requirements before working. It also allows for more vague requirements at the beginning that become more specific near the end, as people meet and talk about their implementation.


# Build and run in different environments

## Getting Started using SSH onto CSE Lab machines

**Important: You have to start the ssh clean if you would like to use the commands below. This means, if you are currently using vscode and already login via ssh, then you cannot run the commands below.**

1. SSH into a CSE Lab Machine using **port forwarding** for the UI

   **Note:** If port `8081` is not available, choose a different port (e.g. 8082, 8083, etc...)

    ```bash
    ssh -L 8081:127.0.0.1:8081 x500@csel-xxxx.cselabs.umn.edu
    ```
    
    Example:
    ```bash
    ssh -L 8081:127.0.0.1:8081 kaung006@csel-kh1250-05.cselabs.umn.edu
    ```

2. Compile the project (within ssh session)

    ```bash
    cd /path/to/repo/project
    make -j
    ```
    
 3. Run project (within ssh session)

    ```bash
    ./build/bin/transit_service 8081 apps/transit_service/web/
    ```

5. Navigate to http://127.0.0.1:8081 and you should see a visualization.

6. Navigate to http://127.0.0.1:8081/schedule.html and you should see a page to schedule the trips.

## Using VOLE

1. See [here](https://github.umn.edu/umn-csci-3081-S23/FAQs/tree/main/VOLE) on how to start using VOLE.

2. Compile the project (within ssh session)

    ```bash
    cd /path/to/repo/project
    make -j
    ```
    
  3. Run project (within ssh session)

      ```bash
      ./build/bin/transit_service 8081 apps/transit_service/web/
      ```

  4. Navigate to http://127.0.0.1:8081 and you should see a visualization.

  5. Navigate to http://127.0.0.1:8081/schedule.html and you should see a page to schedule the trips.
